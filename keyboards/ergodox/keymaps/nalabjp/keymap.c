#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols & media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ` ~  |  1 ! |  2 @ |  3 # |  4 $ |  5 % |      |           |      |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  _   |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|  {   |           |  -   |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|  ]   |           |  +   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  }   |           |  =   |   N  |   M  |  , < |  . > |  / ? | Alfred |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Hyper |  Meh | LAlt | ~L1  |Eis/LG|                                       |Kan/RG| Home | End  | PgUp | PgDn |
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,--------------.       ,--------------.
 *                                      |  ~L1  |  L1  |       | Left | Right |
 *                               ,------|-------|------|       |------+-------+------.
 *                               |      |       |      |       |  Up  |       |      |
 *                               |Esc/  | Back  |------|       |------| Space |Enter/|
 *                               |Shift | Space |      |       | Down |       |Shift |
 *                               `---------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,       KC_1,         KC_2,    KC_3,    KC_4,    KC_5,  KC_TRNS,
        KC_TAB,       KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,  KC_LBRC,
        KC_LCTL,      KC_A,         KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT,      KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,  KC_RBRC,
        ALL_T(KC_NO), MEH_T(KC_NO), KC_LALT, MO(SYMB), GUI_T(KC_LANG2),
                                                           MO(SYMB), TG(SYMB),
                                                                      KC_TRNS,
                                             SFT_T(KC_ESC), KC_BSPC,  KC_TRNS,
        // right hand
        KC_TRNS, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_MINS, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLS,
                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_EQL,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LALT(KC_SPC),
            GUI_T(KC_LANG1), KC_HOME, KC_END, KC_PGUP, KC_PGDN,
        KC_LEFT, KC_RGHT,
        KC_UP,
        KC_DOWN, KC_SPC, SFT_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |MsLeft|MsDown|MsRght| Lclk | Rclk |------|           |------| Left | Down |  Up  |Right |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Reset  | Brt- | Brt+ |Animat|      |      |      |           |      |      | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  | Hue- | Hue+ |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS,   KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2,
       RESET, RGB_VAD, RGB_VAI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS,
          EPRM, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
