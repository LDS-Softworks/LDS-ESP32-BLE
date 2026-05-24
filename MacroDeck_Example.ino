// =============================================================================
// MacroDeck_Example.ino
// LBLE — LDS Bluetooth Low Energy Keyboard Library
// LDS Softworks / LDS Electronics
//
// Example: JP-IME macro deck with Henkan/Muhenkan/Hiragana/Katakana keys
// Hardware: ESP32 DOIT DevKit V1
// =============================================================================

#include <LBLE.h>

using namespace LDS::BLE;

// --- Pin definitions (GPIO numbers) -----------------------------------------
enum KeyPin {
  HENKAN    = 4,
  HIRAGANA  = 15,
  KATAKANA  = 5,
  LANGSWITCH = 16
};

const int ALL_PINS[]  = { HENKAN, HIRAGANA, KATAKANA, LANGSWITCH };
const int PIN_COUNT   = sizeof(ALL_PINS) / sizeof(ALL_PINS[0]);

// --- LBLE instance -----------------------------------------------------------
// Full constructor: name, manufacturer, battery, VID, PID, version
Keyboard::Keyboard kb(
  "MacroDeck V1",
  "LDS Electronics",
  100,
  0x05AC,   // Vendor ID
  0x0001,   // Product ID
  0x0100    // v1.0
);

// --- Debounce ----------------------------------------------------------------
unsigned long lastPress[4] = {0, 0, 0, 0};
const unsigned long DEBOUNCE_MS = 200;

// --- Setup -------------------------------------------------------------------
void setup() {
  Serial.begin(115200);
  Serial.println("LBLE MacroDeck Example");

  for (int i = 0; i < PIN_COUNT; i++) {
    pinMode(ALL_PINS[i], INPUT_PULLUP);
  }

  kb.begin();
  Serial.println("BLE advertising — pair MacroDeck V1 from your host.");
}

// --- Loop --------------------------------------------------------------------
void loop() {
  if (!kb.isConnected()) {
    delay(10);
    return;
  }

  unsigned long now = millis();

  // Henkan (Convert)
  if (digitalRead(HENKAN) == LOW && now - lastPress[0] >= DEBOUNCE_MS) {
    lastPress[0] = now;
    Serial.println("Pressed: JP_HENKAN");
    kb.press(Keyboard::Keys::JP_HENKAN);
    kb.release(Keyboard::Keys::JP_HENKAN);
  }

  // Hiragana toggle
  if (digitalRead(HIRAGANA) == LOW && now - lastPress[1] >= DEBOUNCE_MS) {
    lastPress[1] = now;
    Serial.println("Pressed: JP_KANA_HIRA");
    kb.press(Keyboard::Keys::JP_KANA_HIRA);
    kb.release(Keyboard::Keys::JP_KANA_HIRA);
  }

  // Katakana
  if (digitalRead(KATAKANA) == LOW && now - lastPress[2] >= DEBOUNCE_MS) {
    lastPress[2] = now;
    Serial.println("Pressed: JP_KATAKANA");
    kb.press(Keyboard::Keys::JP_KATAKANA);
    kb.release(Keyboard::Keys::JP_KATAKANA);
  }

  // IME On/Off toggle (Lang1)
  if (digitalRead(LANGSWITCH) == LOW && now - lastPress[3] >= DEBOUNCE_MS) {
    lastPress[3] = now;
    Serial.println("Pressed: JP_IME_ON");
    kb.press(Keyboard::Keys::JP_IME_ON);
    kb.release(Keyboard::Keys::JP_IME_ON);
  }

  delay(10); // let BLE stack breathe
}
