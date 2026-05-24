#pragma once
// =============================================================================
// LBLE.h — LDS Bluetooth Low Energy Keyboard Library
// LDS Softworks / LDS Electronics
// Built on NimBLE-Arduino 2.x
// =============================================================================

#include "sdkconfig.h"
#if defined(CONFIG_BT_ENABLED)

#include <NimBLEDevice.h>
#include <NimBLEServer.h>
#include <NimBLEHIDDevice.h>
#include <NimBLECharacteristic.h>
#include <NimBLEAdvertising.h>

#include <string>
#include <cstdint>

#include "LBLEKeycodes.h"
#include "LBLEDevice.h"
#include "LBLEDescriptor.h"

namespace LDS {
namespace BLE {
namespace Keyboard {

// ---------------------------------------------------------------------------
// HID Key Report structs
// ---------------------------------------------------------------------------
struct KeyReport {
  uint8_t modifiers;
  uint8_t reserved;
  uint8_t keys[6];
};

using MediaKeyReport = uint8_t[2];

// ---------------------------------------------------------------------------
// Keyboard class
// ---------------------------------------------------------------------------
class Keyboard : public NimBLEServerCallbacks,
                 public NimBLECharacteristicCallbacks {
public:
  explicit Keyboard(const DeviceConfig& config = DeviceConfig());

  Keyboard(
    const std::string& name,
    const std::string& manufacturer  = "LDS Electronics",
    uint8_t            batteryLevel  = 100,
    uint16_t           vendorID      = 0x05AC,
    uint16_t           productID     = 0x0001,
    uint16_t           productVersion= 0x0100
  );

  void   begin();
  void   end();
  bool   isConnected() const;
  void   setBatteryLevel(uint8_t level);
  void   setDelay(uint32_t ms);

  size_t press(uint8_t keycode);
  size_t release(uint8_t keycode);
  void   releaseAll();
  size_t write(uint8_t keycode);

  size_t pressRawKC(uint8_t usageID);
  size_t releaseRawKC(uint8_t usageID);

  size_t press(const MediaKeyReport& k);
  size_t release(const MediaKeyReport& k);
  size_t write(const MediaKeyReport& k);

private:
  DeviceConfig          _config;
  NimBLEHIDDevice*      _hid         = nullptr;
  NimBLECharacteristic* _inputKB     = nullptr;
  NimBLECharacteristic* _outputKB    = nullptr;
  NimBLECharacteristic* _inputMedia  = nullptr;
  KeyReport             _keyReport   = {};
  uint8_t               _mediaReport[2] = {};
  bool                  _connected   = false;
  uint32_t              _delayMs     = 7;

  void sendKeyReport();
  void sendMediaReport();
  bool isModifier(uint8_t keycode) const;

  // NimBLE 2.x server callbacks
  void onConnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo) override;
  void onDisconnect(NimBLEServer* pServer, NimBLEConnInfo& connInfo, int reason) override;

  // NimBLE 2.x characteristic callback (LED output from host)
  void onWrite(NimBLECharacteristic* pChar, NimBLEConnInfo& connInfo) override;
};

} // namespace Keyboard
} // namespace BLE
} // namespace LDS

#endif // CONFIG_BT_ENABLED
