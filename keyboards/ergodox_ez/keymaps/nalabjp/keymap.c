// Porting from default_osx/keymap.c
//
// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols & media keys

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
 *   |      |  L1  | ~L1  | LAlt |Eis/LG|                                       |Kan/RG|  Up  | Down | Left | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                      ,--------------.       ,--------------.
 *                                      | Home  | End  |       | Home |  End  |
 *                               ,------|-------|------|       |------+-------+------.
 *                               |      |       | PgUp |       | PgUp |       |      |
 *                               |Esc/  | Back  |------|       |------| Space |Enter/|
 *                               |Shift | Space | PgDn |       | PgDn |       |Shift |
 *                               `---------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
         KC_GRV,     KC_1,     KC_2,    KC_3,            KC_4,    KC_5, KC_TRNS,
         KC_TAB,     KC_Q,     KC_W,    KC_E,            KC_R,    KC_T, KC_LBRC,
        KC_LCTL,     KC_A,     KC_S,    KC_D,            KC_F,    KC_G,
        KC_LSFT,     KC_Z,     KC_X,    KC_C,            KC_V,    KC_B, KC_RBRC,
        KC_TRNS, TG(SYMB), MO(SYMB), KC_LALT, GUI_T(KC_LANG2),
                                                               KC_HOME,  KC_END,
                                                                        KC_PGUP,
                                                SFT_T(KC_ESC), KC_BSPC, KC_PGDN,
        // right hand
        KC_TRNS, KC_6,   KC_7,            KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_MINS, KC_Y,   KC_U,            KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_H,   KC_J,            KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_EQL,  KC_N,   KC_M,            KC_COMM, KC_DOT,  KC_SLSH, LALT(KC_SPC),
                         GUI_T(KC_LANG1), KC_UP,   KC_DOWN, KC_LEFT, KC_RGHT,
        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, KC_SPC, SFT_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  Reset  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |MsLeft|MsDown|MsRght| Lclk | Rclk |------|           |------| Left | Down |  Up  |Right |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | Play | Prev | Next |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
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
[SYMB] = LAYOUT_ergodox(
       // left hand
         RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN2,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
        case SYMB:
            ergodox_right_led_1_on();
            break;
        default:
            // none
            break;
    }

};
