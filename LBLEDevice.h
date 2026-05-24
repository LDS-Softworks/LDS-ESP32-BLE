#pragma once
// =============================================================================
// LBLEDevice.h — Device Identity / PnP Configuration
// Part of LBLE (LDS Bluetooth Low Energy) Library
// LDS Softworks / LDS Electronics
// =============================================================================

#include <cstdint>
#include <string>

namespace LDS {
namespace BLE {
namespace Keyboard {

  // PnP ID source identifiers (HID spec)
  enum class VendorIDSource : uint8_t {
    BLUETOOTH_SIG = 0x01, // Vendor ID assigned by Bluetooth SIG
    USB_IF        = 0x02  // Vendor ID assigned by USB IF
  };

  struct DeviceConfig {
    std::string      name;
    std::string      manufacturer;
    uint8_t          batteryLevel;

    // PnP / HID identity
    VendorIDSource   vendorIDSource;
    uint16_t         vendorID;
    uint16_t         productID;
    uint16_t         productVersion;

    // Defaults: LDS Electronics identity
    DeviceConfig(
      std::string name            = "LDSE Wireless KB",
      std::string manufacturer    = "LDS Electronics",
      uint8_t     batteryLevel    = 100,
      VendorIDSource vidSrc       = VendorIDSource::USB_IF,
      uint16_t    vendorID        = 0x05AC, // LDS default VID
      uint16_t    productID       = 0x0001, // LBLE Keyboard product ID
      uint16_t    productVersion  = 0x0100  // v1.0
    )
      : name(name.substr(0, 15))
      , manufacturer(manufacturer.substr(0, 15))
      , batteryLevel(batteryLevel)
      , vendorIDSource(vidSrc)
      , vendorID(vendorID)
      , productID(productID)
      , productVersion(productVersion)
    {}
  };

} // namespace Keyboard
} // namespace BLE
} // namespace LDS
