#pragma once
// =============================================================================
// LBLEDescriptor.h — HID Report Descriptor
// Part of LBLE (LDS Bluetooth Low Energy) Library
// LDS Softworks / LDS Electronics
// =============================================================================

#include <cstdint>

namespace LDS {
namespace BLE {
namespace Keyboard {

#define LBLE_KB_REPORT_ID    0x01
#define LBLE_MEDIA_REPORT_ID 0x02

// HID short item encoding
// Format: tag(4) | type(2) | size(2)
// Input/Output/Feature = type 0b10 = 0x80/0x90/0xB0
// Global               = type 0b01 = 0x04 series
// Local                = type 0b00 = 0x00 series
// Main                 = type 0b00 at tag level

static const uint8_t LBLE_HID_DESCRIPTOR[] = {

  // -----------------------------------------------------------------------
  // Keyboard (Report ID 1)
  // -----------------------------------------------------------------------
  0x05, 0x01,        // Usage Page (Generic Desktop)
  0x09, 0x06,        // Usage (Keyboard)
  0xA1, 0x01,        // Collection (Application)
  0x85, 0x01,        //   Report ID (1)

  // Modifier byte: 8 x 1-bit (Left/Right Ctrl/Shift/Alt/GUI)
  0x05, 0x07,        //   Usage Page (Keyboard/Keypad)
  0x19, 0xE0,        //   Usage Minimum (Left Ctrl = 0xE0)
  0x29, 0xE7,        //   Usage Maximum (Right GUI = 0xE7)
  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x08,        //   Report Count (8)
  0x81, 0x02,        //   Input (Data, Variable, Absolute)

  // Reserved byte
  0x95, 0x01,        //   Report Count (1)
  0x75, 0x08,        //   Report Size (8)
  0x81, 0x01,        //   Input (Constant)

  // LED output (5 bits: Num/Caps/Scroll/Compose/Kana)
  0x95, 0x05,        //   Report Count (5)
  0x75, 0x01,        //   Report Size (1)
  0x05, 0x08,        //   Usage Page (LEDs)
  0x19, 0x01,        //   Usage Minimum (Num Lock)
  0x29, 0x05,        //   Usage Maximum (Kana)
  0x91, 0x02,        //   Output (Data, Variable, Absolute)
  0x95, 0x01,        //   Report Count (1)
  0x75, 0x03,        //   Report Size (3) padding
  0x91, 0x01,        //   Output (Constant)

  // Key array: 6 slots, full usage range 0x00-0xE7
  // 2-byte logical/usage max to avoid signed-byte ambiguity above 0x7F
  0x95, 0x06,        //   Report Count (6)
  0x75, 0x08,        //   Report Size (8)
  0x15, 0x00,        //   Logical Minimum (0)
  0x26, 0xE7, 0x00,  //   Logical Maximum (0x00E7 = 231, 2-byte)
  0x05, 0x07,        //   Usage Page (Keyboard/Keypad)
  0x19, 0x00,        //   Usage Minimum (0)
  0x2A, 0xE7, 0x00,  //   Usage Maximum (0x00E7 = 231, 2-byte)
  0x81, 0x00,        //   Input (Data, Array, Absolute)

  0xC0,              // End Collection

  // -----------------------------------------------------------------------
  // Media / Consumer Keys (Report ID 2) — 16-bit bitmask
  // -----------------------------------------------------------------------
  0x05, 0x0C,        // Usage Page (Consumer)
  0x09, 0x01,        // Usage (Consumer Control)
  0xA1, 0x01,        // Collection (Application)
  0x85, 0x02,        //   Report ID (2)

  0x15, 0x00,        //   Logical Minimum (0)
  0x25, 0x01,        //   Logical Maximum (1)
  0x75, 0x01,        //   Report Size (1)
  0x95, 0x10,        //   Report Count (16)

  0x09, 0xB5,        //   Usage (Next Track)
  0x09, 0xB6,        //   Usage (Previous Track)
  0x09, 0xB7,        //   Usage (Stop)
  0x09, 0xCD,        //   Usage (Play/Pause)
  0x09, 0xE2,        //   Usage (Mute)
  0x09, 0xE9,        //   Usage (Volume Up)
  0x09, 0xEA,        //   Usage (Volume Down)
  0x09, 0xB8,        //   Usage (Eject)       -- replaces 2-byte WWW Home
  0x09, 0x6F,        //   Usage (Brightness+)
  0x09, 0x70,        //   Usage (Brightness-)
  0x09, 0x72,        //   Usage (Print Screen)
  0x09, 0x73,        //   Usage (Scroll Lock)
  0x09, 0x74,        //   Usage (Pause)
  0x09, 0x75,        //   Usage (Insert)
  0x09, 0x76,        //   Usage (Home)
  0x09, 0x77,        //   Usage (Page Up)

  0x81, 0x02,        //   Input (Data, Variable, Absolute)

  0xC0               // End Collection

};

static const size_t LBLE_HID_DESCRIPTOR_SIZE = sizeof(LBLE_HID_DESCRIPTOR);

} // namespace Keyboard
} // namespace BLE
} // namespace LDS
