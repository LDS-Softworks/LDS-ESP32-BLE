#pragma once
// =============================================================================
// LBLEKeycodes.h — HID Keyboard Usage ID Definitions
// Part of LBLE (LDS Bluetooth Low Energy) Library
// LDS Softworks / LDS Electronics
// Covers full HID Keyboard/Keypad Usage Page (0x07), 0x00–0xFF
// Organized by category under LDS::BLE::Keyboard::Keys
// =============================================================================

#include <cstdint>

namespace LDS {
namespace BLE {
namespace Keyboard {
namespace Keys {

  // ---------------------------------------------------------------------------
  // Modifiers (sent via modifier byte, not key slots)
  // ---------------------------------------------------------------------------
  constexpr uint8_t LEFT_CTRL    = 0x80;
  constexpr uint8_t LEFT_SHIFT   = 0x81;
  constexpr uint8_t LEFT_ALT     = 0x82;
  constexpr uint8_t LEFT_GUI     = 0x83;
  constexpr uint8_t RIGHT_CTRL   = 0x84;
  constexpr uint8_t RIGHT_SHIFT  = 0x85;
  constexpr uint8_t RIGHT_ALT    = 0x86;
  constexpr uint8_t RIGHT_GUI    = 0x87;

  // ---------------------------------------------------------------------------
  // Standard Printable / Control (HID Usage IDs, direct)
  // ---------------------------------------------------------------------------
  constexpr uint8_t NONE         = 0x00;
  constexpr uint8_t ERR_ROLLOVER = 0x01;
  constexpr uint8_t POST_FAIL    = 0x02;
  constexpr uint8_t ERR_UNDEF    = 0x03;
  constexpr uint8_t A            = 0x04;
  constexpr uint8_t B            = 0x05;
  constexpr uint8_t C            = 0x06;
  constexpr uint8_t D            = 0x07;
  constexpr uint8_t E            = 0x08;
  constexpr uint8_t F            = 0x09;
  constexpr uint8_t G            = 0x0A;
  constexpr uint8_t H            = 0x0B;
  constexpr uint8_t I            = 0x0C;
  constexpr uint8_t J            = 0x0D;
  constexpr uint8_t K            = 0x0E;
  constexpr uint8_t L            = 0x0F;
  constexpr uint8_t M            = 0x10;
  constexpr uint8_t N            = 0x11;
  constexpr uint8_t O            = 0x12;
  constexpr uint8_t P            = 0x13;
  constexpr uint8_t Q            = 0x14;
  constexpr uint8_t R            = 0x15;
  constexpr uint8_t S            = 0x16;
  constexpr uint8_t T            = 0x17;
  constexpr uint8_t U            = 0x18;
  constexpr uint8_t V            = 0x19;
  constexpr uint8_t W            = 0x1A;
  constexpr uint8_t X            = 0x1B;
  constexpr uint8_t Y            = 0x1C;
  constexpr uint8_t Z            = 0x1D;
  constexpr uint8_t N1           = 0x1E; // 1 / !
  constexpr uint8_t N2           = 0x1F; // 2 / @
  constexpr uint8_t N3           = 0x20; // 3 / #
  constexpr uint8_t N4           = 0x21; // 4 / $
  constexpr uint8_t N5           = 0x22; // 5 / %
  constexpr uint8_t N6           = 0x23; // 6 / ^
  constexpr uint8_t N7           = 0x24; // 7 / &
  constexpr uint8_t N8           = 0x25; // 8 / *
  constexpr uint8_t N9           = 0x26; // 9 / (
  constexpr uint8_t N0           = 0x27; // 0 / )
  constexpr uint8_t ENTER        = 0x28;
  constexpr uint8_t ESCAPE       = 0x29;
  constexpr uint8_t BACKSPACE    = 0x2A;
  constexpr uint8_t TAB          = 0x2B;
  constexpr uint8_t SPACE        = 0x2C;
  constexpr uint8_t MINUS        = 0x2D; // - / _
  constexpr uint8_t EQUAL        = 0x2E; // = / +
  constexpr uint8_t LEFT_BRACKET = 0x2F; // [ / {
  constexpr uint8_t RIGHT_BRACKET= 0x30; // ] / }
  constexpr uint8_t BACKSLASH    = 0x31; // \ / |
  constexpr uint8_t NONUS_HASH   = 0x32; // Non-US # and ~
  constexpr uint8_t SEMICOLON    = 0x33; // ; / :
  constexpr uint8_t APOSTROPHE   = 0x34; // ' / "
  constexpr uint8_t GRAVE        = 0x35; // ` / ~
  constexpr uint8_t COMMA        = 0x36; // , / <
  constexpr uint8_t PERIOD       = 0x37; // . / >
  constexpr uint8_t SLASH        = 0x38; // / / ?
  constexpr uint8_t CAPS_LOCK    = 0x39;

  // ---------------------------------------------------------------------------
  // Function Keys
  // ---------------------------------------------------------------------------
  constexpr uint8_t F1           = 0x3A;
  constexpr uint8_t F2           = 0x3B;
  constexpr uint8_t F3           = 0x3C;
  constexpr uint8_t F4           = 0x3D;
  constexpr uint8_t F5           = 0x3E;
  constexpr uint8_t F6           = 0x3F;
  constexpr uint8_t F7           = 0x40;
  constexpr uint8_t F8           = 0x41;
  constexpr uint8_t F9           = 0x42;
  constexpr uint8_t F10          = 0x43;
  constexpr uint8_t F11          = 0x44;
  constexpr uint8_t F12          = 0x45;
  constexpr uint8_t F13          = 0x68;
  constexpr uint8_t F14          = 0x69;
  constexpr uint8_t F15          = 0x6A;
  constexpr uint8_t F16          = 0x6B;
  constexpr uint8_t F17          = 0x6C;
  constexpr uint8_t F18          = 0x6D;
  constexpr uint8_t F19          = 0x6E;
  constexpr uint8_t F20          = 0x6F;
  constexpr uint8_t F21          = 0x70;
  constexpr uint8_t F22          = 0x71;
  constexpr uint8_t F23          = 0x72;
  constexpr uint8_t F24          = 0x73;

  // ---------------------------------------------------------------------------
  // Navigation / Control Cluster
  // ---------------------------------------------------------------------------
  constexpr uint8_t PRINT_SCREEN = 0x46;
  constexpr uint8_t SCROLL_LOCK  = 0x47;
  constexpr uint8_t PAUSE        = 0x48;
  constexpr uint8_t INSERT       = 0x49;
  constexpr uint8_t HOME         = 0x4A;
  constexpr uint8_t PAGE_UP      = 0x4B;
  constexpr uint8_t DELETE       = 0x4C;
  constexpr uint8_t END          = 0x4D;
  constexpr uint8_t PAGE_DOWN    = 0x4E;
  constexpr uint8_t RIGHT_ARROW  = 0x4F;
  constexpr uint8_t LEFT_ARROW   = 0x50;
  constexpr uint8_t DOWN_ARROW   = 0x51;
  constexpr uint8_t UP_ARROW     = 0x52;

  // ---------------------------------------------------------------------------
  // Numpad
  // ---------------------------------------------------------------------------
  constexpr uint8_t NUM_LOCK     = 0x53;
  constexpr uint8_t KP_SLASH     = 0x54;
  constexpr uint8_t KP_ASTERISK  = 0x55;
  constexpr uint8_t KP_MINUS     = 0x56;
  constexpr uint8_t KP_PLUS      = 0x57;
  constexpr uint8_t KP_ENTER     = 0x58;
  constexpr uint8_t KP_1         = 0x59;
  constexpr uint8_t KP_2         = 0x5A;
  constexpr uint8_t KP_3         = 0x5B;
  constexpr uint8_t KP_4         = 0x5C;
  constexpr uint8_t KP_5         = 0x5D;
  constexpr uint8_t KP_6         = 0x5E;
  constexpr uint8_t KP_7         = 0x5F;
  constexpr uint8_t KP_8         = 0x60;
  constexpr uint8_t KP_9         = 0x61;
  constexpr uint8_t KP_0         = 0x62;
  constexpr uint8_t KP_DOT       = 0x63;
  constexpr uint8_t KP_EQUAL     = 0x67;
  constexpr uint8_t KP_COMMA     = 0x85;
  constexpr uint8_t KP_EQUAL_AS400 = 0x86;

  // ---------------------------------------------------------------------------
  // International / Non-US Keys
  // ---------------------------------------------------------------------------
  constexpr uint8_t NONUS_BACKSLASH = 0x64; // Non-US \ and |
  constexpr uint8_t APPLICATION  = 0x65;    // Menu / App key
  constexpr uint8_t POWER        = 0x66;
  constexpr uint8_t EXECUTE      = 0x74;
  constexpr uint8_t HELP         = 0x75;
  constexpr uint8_t MENU         = 0x76;
  constexpr uint8_t SELECT       = 0x77;
  constexpr uint8_t STOP         = 0x78;
  constexpr uint8_t AGAIN        = 0x79;
  constexpr uint8_t UNDO         = 0x7A;
  constexpr uint8_t CUT          = 0x7B;
  constexpr uint8_t COPY         = 0x7C;
  constexpr uint8_t PASTE        = 0x7D;
  constexpr uint8_t FIND         = 0x7E;
  constexpr uint8_t MUTE         = 0x7F;
  constexpr uint8_t VOLUME_UP    = 0x80;
  constexpr uint8_t VOLUME_DOWN  = 0x81;
  constexpr uint8_t LOCKING_CAPS = 0x82;
  constexpr uint8_t LOCKING_NUM  = 0x83;
  constexpr uint8_t LOCKING_SCR  = 0x84;
  constexpr uint8_t INTL_1       = 0x87; // Ro (JP) / extra key
  constexpr uint8_t INTL_2       = 0x88; // Katakana/Hiragana (JP)
  constexpr uint8_t INTL_3       = 0x89; // Yen (JP)
  constexpr uint8_t INTL_4       = 0x8A; // Henkan (JP) — Convert
  constexpr uint8_t INTL_5       = 0x8B; // Muhenkan (JP) — Non-Convert
  constexpr uint8_t INTL_6       = 0x8C; // PC9800 Numpad comma
  constexpr uint8_t INTL_7       = 0x8D;
  constexpr uint8_t INTL_8       = 0x8E;
  constexpr uint8_t INTL_9       = 0x8F;

  // ---------------------------------------------------------------------------
  // Language / IME Keys
  // Named aliases for readability — same as INTL_x above where relevant
  // ---------------------------------------------------------------------------
  constexpr uint8_t LANG_1       = 0x90; // Hangul/English toggle (KR) / IME On (JP)
  constexpr uint8_t LANG_2       = 0x91; // Hanja (KR) / IME Off (JP)
  constexpr uint8_t LANG_3       = 0x92; // Katakana (JP)
  constexpr uint8_t LANG_4       = 0x93; // Hiragana (JP)
  constexpr uint8_t LANG_5       = 0x94; // Zenkaku/Hankaku (JP)
  constexpr uint8_t LANG_6       = 0x95;
  constexpr uint8_t LANG_7       = 0x96;
  constexpr uint8_t LANG_8       = 0x97;
  constexpr uint8_t LANG_9       = 0x98;

  // Named JP aliases (use these in your sketches for clarity)
  constexpr uint8_t JP_HENKAN    = INTL_4; // 0x8A — Convert
  constexpr uint8_t JP_MUHENKAN  = INTL_5; // 0x8B — Non-Convert
  constexpr uint8_t JP_YEN       = INTL_3; // 0x89
  constexpr uint8_t JP_RO        = INTL_1; // 0x87
  constexpr uint8_t JP_KANA_HIRA = INTL_2; // 0x88 — Katakana/Hiragana toggle
  constexpr uint8_t JP_KATAKANA  = LANG_3; // 0x92
  constexpr uint8_t JP_HIRAGANA  = LANG_4; // 0x93
  constexpr uint8_t JP_IME_ON    = LANG_1; // 0x90
  constexpr uint8_t JP_IME_OFF   = LANG_2; // 0x91
  constexpr uint8_t JP_ZENKAKU   = LANG_5; // 0x94 — Fullwidth/Halfwidth toggle

  // ---------------------------------------------------------------------------
  // Alternate erase / special
  // ---------------------------------------------------------------------------
  constexpr uint8_t ALT_ERASE    = 0x99;
  constexpr uint8_t SYSREQ       = 0x9A;
  constexpr uint8_t CANCEL       = 0x9B;
  constexpr uint8_t CLEAR        = 0x9C;
  constexpr uint8_t PRIOR        = 0x9D;
  constexpr uint8_t RETURN       = 0x9E;
  constexpr uint8_t SEPARATOR    = 0x9F;
  constexpr uint8_t OUT          = 0xA0;
  constexpr uint8_t OPER         = 0xA1;
  constexpr uint8_t CLEAR_AGAIN  = 0xA2;
  constexpr uint8_t CRSEL        = 0xA3;
  constexpr uint8_t EXSEL        = 0xA4;

  // 0xA5–0xAF reserved by HID spec

  // ---------------------------------------------------------------------------
  // Numpad extended
  // ---------------------------------------------------------------------------
  constexpr uint8_t KP_00        = 0xB0;
  constexpr uint8_t KP_000       = 0xB1;
  constexpr uint8_t THOUSANDS_SEP= 0xB2;
  constexpr uint8_t DECIMAL_SEP  = 0xB3;
  constexpr uint8_t CURRENCY_UNIT= 0xB4;
  constexpr uint8_t CURRENCY_SUB = 0xB5;
  constexpr uint8_t KP_LEFT_PAREN= 0xB6;
  constexpr uint8_t KP_RIGHT_PAREN=0xB7;
  constexpr uint8_t KP_LEFT_BRACE= 0xB8;
  constexpr uint8_t KP_RIGHT_BRACE=0xB9;
  constexpr uint8_t KP_TAB       = 0xBA;
  constexpr uint8_t KP_BACKSPACE = 0xBB;
  constexpr uint8_t KP_A         = 0xBC;
  constexpr uint8_t KP_B         = 0xBD;
  constexpr uint8_t KP_C         = 0xBE;
  constexpr uint8_t KP_D         = 0xBF;
  constexpr uint8_t KP_E         = 0xC0;
  constexpr uint8_t KP_F         = 0xC1;
  constexpr uint8_t KP_XOR       = 0xC2;
  constexpr uint8_t KP_CARET     = 0xC3;
  constexpr uint8_t KP_PERCENT   = 0xC4;
  constexpr uint8_t KP_LESS      = 0xC5;
  constexpr uint8_t KP_GREATER   = 0xC6;
  constexpr uint8_t KP_AMP       = 0xC7;
  constexpr uint8_t KP_DBL_AMP   = 0xC8;
  constexpr uint8_t KP_PIPE      = 0xC9;
  constexpr uint8_t KP_DBL_PIPE  = 0xCA;
  constexpr uint8_t KP_COLON     = 0xCB;
  constexpr uint8_t KP_HASH      = 0xCC;
  constexpr uint8_t KP_SPACE     = 0xCD;
  constexpr uint8_t KP_AT        = 0xCE;
  constexpr uint8_t KP_EXCLAIM   = 0xCF;
  constexpr uint8_t KP_MEM_STORE = 0xD0;
  constexpr uint8_t KP_MEM_RECALL= 0xD1;
  constexpr uint8_t KP_MEM_CLEAR = 0xD2;
  constexpr uint8_t KP_MEM_ADD   = 0xD3;
  constexpr uint8_t KP_MEM_SUB   = 0xD4;
  constexpr uint8_t KP_MEM_MUL   = 0xD5;
  constexpr uint8_t KP_MEM_DIV   = 0xD6;
  constexpr uint8_t KP_PLUS_MINUS= 0xD7;
  constexpr uint8_t KP_CLEAR     = 0xD8;
  constexpr uint8_t KP_CLEAR_ENT = 0xD9;
  constexpr uint8_t KP_BINARY    = 0xDA;
  constexpr uint8_t KP_OCTAL     = 0xDB;
  constexpr uint8_t KP_DECIMAL   = 0xDC;
  constexpr uint8_t KP_HEX       = 0xDD;

  // 0xDE–0xDF reserved

  // ---------------------------------------------------------------------------
  // Modifier raw HID IDs (for pressRawKC reference)
  // ---------------------------------------------------------------------------
  constexpr uint8_t MOD_LEFT_CTRL  = 0xE0;
  constexpr uint8_t MOD_LEFT_SHIFT = 0xE1;
  constexpr uint8_t MOD_LEFT_ALT   = 0xE2;
  constexpr uint8_t MOD_LEFT_GUI   = 0xE3;
  constexpr uint8_t MOD_RIGHT_CTRL = 0xE4;
  constexpr uint8_t MOD_RIGHT_SHIFT= 0xE5;
  constexpr uint8_t MOD_RIGHT_ALT  = 0xE6;
  constexpr uint8_t MOD_RIGHT_GUI  = 0xE7;

} // namespace Keys
} // namespace Keyboard
} // namespace BLE
} // namespace LDS
