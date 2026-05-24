// =============================================================================
// LBLE.cpp — LDS Bluetooth Low Energy Keyboard Library Implementation
// LDS Softworks / LDS Electronics
// Built on NimBLE-Arduino 2.5.0 // Needs testing on older 2.X versions.
// =============================================================================

#include "LBLE.h"
#include <Arduino.h>

#if defined(CONFIG_BT_ENABLED)

namespace LDS {
namespace BLE {
namespace Keyboard {

// ---------------------------------------------------------------------------
// Constructors
// ---------------------------------------------------------------------------

Keyboard::Keyboard(const DeviceConfig& config)
  : _config(config)
{}

Keyboard::Keyboard(
  const std::string& name,
  const std::string& manufacturer,
  uint8_t            batteryLevel,
  uint16_t           vendorID,
  uint16_t           productID,
  uint16_t           productVersion
)
  : _config(DeviceConfig(name, manufacturer, batteryLevel,
                         VendorIDSource::USB_IF,
                         vendorID, productID, productVersion))
{}

// ---------------------------------------------------------------------------
// Lifecycle
// ---------------------------------------------------------------------------

void Keyboard::begin() {
  NimBLEDevice::init(_config.name);
  NimBLEDevice::setSecurityAuth(BLE_SM_PAIR_AUTHREQ_BOND);

  NimBLEServer* pServer = NimBLEDevice::createServer();
  pServer->setCallbacks(this);

  _hid = new NimBLEHIDDevice(pServer);

  _inputKB    = _hid->getInputReport(LBLE_KB_REPORT_ID);
  _outputKB   = _hid->getOutputReport(LBLE_KB_REPORT_ID);
  _inputMedia = _hid->getInputReport(LBLE_MEDIA_REPORT_ID);

  _outputKB->setCallbacks(this);

  _hid->setManufacturer(_config.manufacturer);
  _hid->setPnp(
    static_cast<uint8_t>(_config.vendorIDSource),
    _config.vendorID,
    _config.productID,
    _config.productVersion
  );
  _hid->setHidInfo(0x00, 0x01);
  _hid->setReportMap(
    const_cast<uint8_t*>(LBLE_HID_DESCRIPTOR),
    LBLE_HID_DESCRIPTOR_SIZE
  );
  _hid->startServices();
  _hid->setBatteryLevel(_config.batteryLevel);

  NimBLEAdvertising* pAdv = NimBLEDevice::getAdvertising();
  pAdv->setAppearance(HID_KEYBOARD);
  pAdv->addServiceUUID(_hid->getHidService()->getUUID());
  pAdv->start();
}

void Keyboard::end() {}

// ---------------------------------------------------------------------------
// State
// ---------------------------------------------------------------------------

bool Keyboard::isConnected() const {
  return _connected;
}

void Keyboard::setBatteryLevel(uint8_t level) {
  _config.batteryLevel = level;
  if (_hid) _hid->setBatteryLevel(level);
}

void Keyboard::setDelay(uint32_t ms) {
  _delayMs = ms;
}

// ---------------------------------------------------------------------------
// Internal
// ---------------------------------------------------------------------------

bool Keyboard::isModifier(uint8_t keycode) const {
  return keycode >= 0x80 && keycode <= 0x87;
}

void Keyboard::sendKeyReport() {
  if (!_connected) return;
  _inputKB->setValue(reinterpret_cast<uint8_t*>(&_keyReport), sizeof(KeyReport));
  _inputKB->notify();
  if (_delayMs) delay(_delayMs);
}

void Keyboard::sendMediaReport() {
  if (!_connected) return;
  _inputMedia->setValue(_mediaReport, sizeof(_mediaReport));
  _inputMedia->notify();
  if (_delayMs) delay(_delayMs);
}

// ---------------------------------------------------------------------------
// press() / release()
// ---------------------------------------------------------------------------

size_t Keyboard::press(uint8_t keycode) {
  if (isModifier(keycode)) {
    _keyReport.modifiers |= (1 << (keycode - 0x80));
    sendKeyReport();
    return 1;
  }
  for (uint8_t i = 0; i < 6; i++) {
    if (_keyReport.keys[i] == keycode) return 1;
    if (_keyReport.keys[i] == 0x00) {
      _keyReport.keys[i] = keycode;
      sendKeyReport();
      return 1;
    }
  }
  return 0;
}

size_t Keyboard::release(uint8_t keycode) {
  if (isModifier(keycode)) {
    _keyReport.modifiers &= ~(1 << (keycode - 0x80));
    sendKeyReport();
    return 1;
  }
  for (uint8_t i = 0; i < 6; i++) {
    if (_keyReport.keys[i] == keycode) _keyReport.keys[i] = 0x00;
  }
  sendKeyReport();
  return 1;
}

// ---------------------------------------------------------------------------
// pressRawKC() / releaseRawKC()
// ___________________________________________________________________________
// Press and release of raw keycodes / 0x<hexint>
// ---------------------------------------------------------------------------

size_t Keyboard::pressRawKC(uint8_t usageID) {
  // Raw HID modifier range 0xE0–0xE7
  if (usageID >= 0xE0 && usageID <= 0xE7) {
    _keyReport.modifiers |= (1 << (usageID - 0xE0));
    sendKeyReport();
    return 1;
  }
  for (uint8_t i = 0; i < 6; i++) {
    if (_keyReport.keys[i] == usageID) return 1;
    if (_keyReport.keys[i] == 0x00) {
      _keyReport.keys[i] = usageID;
      sendKeyReport();
      return 1;
    }
  }
  return 0;
}

size_t Keyboard::releaseRawKC(uint8_t usageID) {
  if (usageID >= 0xE0 && usageID <= 0xE7) {
    _keyReport.modifiers &= ~(1 << (usageID - 0xE0));
    sendKeyReport();
    return 1;
  }
  for (uint8_t i = 0; i < 6; i++) {
    if (_keyReport.keys[i] == usageID) _keyReport.keys[i] = 0x00;
  }
  sendKeyReport();
  return 1;
}

// ---------------------------------------------------------------------------
// releaseAll() / write()
// ---------------------------------------------------------------------------

void Keyboard::releaseAll() {
  memset(&_keyReport, 0, sizeof(KeyReport));
  memset(_mediaReport, 0, sizeof(_mediaReport));
  sendKeyReport();
  sendMediaReport();
}

size_t Keyboard::write(uint8_t keycode) {
  size_t r = press(keycode);
  release(keycode);
  return r;
}

// ---------------------------------------------------------------------------
// Media keys
// ---------------------------------------------------------------------------

size_t Keyboard::press(const MediaKeyReport& k) {
  _mediaReport[0] |= k[0];
  _mediaReport[1] |= k[1];
  sendMediaReport();
  return 1;
}

size_t Keyboard::release(const MediaKeyReport& k) {
  _mediaReport[0] &= ~k[0];
  _mediaReport[1] &= ~k[1];
  sendMediaReport();
  return 1;
}

size_t Keyboard::write(const MediaKeyReport& k) {
  size_t r = press(k);
  release(k);
  return r;
}

// ---------------------------------------------------------------------------
// NimBLE 2.x callbacks
// ___________________________________________________________________________
// Only tested on NimBLE's latest version as of 23-May-2026
// ---------------------------------------------------------------------------

void Keyboard::onConnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo) {
  _connected = true;
}

void Keyboard::onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason) {
  _connected = false;
  // NimBLE 2.x restarts advertising automatically
}

void Keyboard::onWrite(NimBLECharacteristic* pChar, NimBLEConnInfo& connInfo) {
  // LED state from host (Num/Caps/Scroll lock) — extend here if needed
}

} // namespace Keyboard
} // namespace BLE
} // namespace LDS

#endif // CONFIG_BT_ENABLED
