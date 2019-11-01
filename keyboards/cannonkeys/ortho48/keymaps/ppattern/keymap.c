/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _VIMQ,
  _VIMD,
  /*_VIMV,
  _FN1,
  _FN2,*/
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  VIMQ,
  VIMD,
//  VIMV,
  I_VIMD,
  A_VIMD,
  O_VIMD,
  S_VIMD,
  X_VIMD
};

#define FN1 LT(_RAISE, KC_ENT)
#define LOWER LT(_LOWER, KC_DEL)
#define RAISE LT(_RAISE, KC_LEFT)
#define RGUIT RGUI_T(KC_DOWN)
#define RALTT RALT_T(KC_UP)
#define RCTLT RCTL_T(KC_RIGHT)
#define FN2 LT(_LOWER, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |          Qwerty
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |Raise | GUI  |  Opt | Ctrl |
   * `-----------------------------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
       KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
LSFT_T(KC_CAPS), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,LSFT_T(KC_SPC),  FN1, FN2,   RSFT_T(KC_SPC),RAISE,    RGUIT,    RALTT,    RCTLT ),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |          Colemak
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |Raise | GUI  |  Opt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
       KC_ESC,   KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,
LSFT_T(KC_CAPS), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,LSFT_T(KC_SPC),  FN1, FN2,   RSFT_T(KC_SPC),RAISE,    RGUIT,    RALTT,    RCTLT
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |          Dvorak
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |Raise | GUI  |  Opt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_BSPC,
       KC_ESC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
LSFT_T(KC_CAPS), KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     RSFT_T(KC_ENT),
       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,LSFT_T(KC_SPC),  FN1, FN2,   RSFT_T(KC_SPC),RAISE,    RGUIT,    RALTT,    RCTLT
),

/* VimQ
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |          VimQ
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |Raise | GUI  |  Opt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_VIMQ] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     I_VIMD,   O_VIMD,   KC_P,     KC_BSPC,
       KC_ESC,   A_VIMD,   S_VIMD,   KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
LSFT_T(KC_CAPS), KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT),
       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,LSFT_T(KC_SPC),  FN1, FN2,   RSFT_T(KC_SPC),RAISE,    RGUIT,    RALTT,    RCTLT
),
/* VimD
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |          VimD
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |Raise | GUI  |  Opt | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_VIMD] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_BSPC,
       X_VIMD,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,
LSFT_T(KC_CAPS), KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     RSFT_T(KC_ENT),
       KC_LCTL,  KC_LALT,  KC_LGUI,  LOWER,LSFT_T(KC_SPC),  FN1, FN2,   RSFT_T(KC_SPC),RAISE,    RGUIT,    RALTT,    RCTLT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  `~  |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  \ | |          Lower
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |      | [ {  |  ] } |  - _ |  = + |  / ? |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |   (  |   )  |   <  |   >  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |      |Space | FN1  | FN2  |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSLS,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LBRC,  KC_RBRC,  KC_MINS,  KC_EQL,   KC_SLSH,
       KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_LPRN,  KC_RPRN,  KC_LT,    KC_GT,    KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  `~  |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  \ | |          Raise
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      |  UP  |      |      |      |  Ins | HOME | PgUp |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Left | Down |Right |      |      |  Del |  End | PgDn |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Opt | GUI  |Lower |Space | FN1  | FN2  |Enter |      | Mute | Vol- | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,      KC_9,     KC_0,     KC_BSLS,
       KC_TAB,   KC_NO,    KC_UP,    KC_NO,    KC_NO,    KC_NO,    KC_INS,   KC_HOME,  KC_PGUP,   KC_NO,    KC_NO,    KC_NO,
       KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_NO,    KC_DEL,   KC_END,   KC_PGDN,   KC_NO,    KC_NO,    KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC__MUTE, KC_VOLD,  KC_VOLU
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      | Ms WU|      |   *  |   /  |   7  |   8  |   9  | MS B1| MS U | MS B2|          Plover
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  | Ms WL| Ms WD| Ms WR|   +  |   -  |   4  |   5  |   6  | MS L | MS D | MS R |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Exit |Ms Ac0|Ms Ac1|Ms Ac2|   .  |   =  |   1  |   2  |   3  | MS B3| MS B4| MS B5|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |Numlck|  Del | Bksp |Space |Enter |   0  |Enter | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_ortho_4x12(
       KC_TAB,   KC_NO,    KC_WH_U,  KC_NO,    KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_BTN1,  KC_MS_U,  KC_BTN2,
       KC_ESC,   KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_PPLS,  KC_PMNS,  KC_P4,    KC_P5,    KC_P6,    KC_MS_L,  KC_MS_D,  KC_MS_R,
       EXT_PLV,  KC_ACL0,  KC_ACL1,  KC_ACL2,  KC_PDOT,  KC_PEQL,  KC_P1,    KC_P2,    KC_P3,    KC_BTN3,  KC_BTN4,  KC_BTN5,
       EXT_PLV, KC_NUMLOCK,KC_DEL,   KC_BSPC,  KC_SPC,   KC_ENT,   KC_P0,    KC_ENT,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |EEPROM| Reset| Debug|      |      |      |      | VimQ | VimD |      |      |      |          Adjust
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PrtScr|      |      |      |      |      |      |Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
EEPROM_RESET,   RESET,   DEBUG,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    VIMQ,     VIMD,     KC_NO,    KC_NO,    KC_NO,
       KC_PSCR, KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    QWERTY,   COLEMAK,  DVORAK,   PLOVER,   KC_NO,
       KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
       KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case I_VIMD:
      if (record->event.pressed) {
        SEND_STRING("i");
      } else {
        set_single_persistent_default_layer(_VIMD);
      }
      return false;
      break;
    case A_VIMD:
      if (record->event.pressed) {
        SEND_STRING("a");
      } else {
        set_single_persistent_default_layer(_VIMD);
      }
      return false;
      break;
    case O_VIMD:
      if (record->event.pressed) {
        SEND_STRING("o");
      } else {
        set_single_persistent_default_layer(_VIMD);
      }
      return false;
      break;
    case S_VIMD:
      if (record->event.pressed) {
        SEND_STRING("s");
      } else {
        set_single_persistent_default_layer(_VIMD);
      }
      return false;
      break;
    case X_VIMD:
      if (record->event.pressed) {
        tap_code(KC_ESC);
      } else {
        set_single_persistent_default_layer(_VIMQ);
      }
      return false;
      break;

    case QWERTY:
      if (record->event.pressed) {
        /*print("mode just switched to qwerty and this is a huge string\n");*/
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

    case VIMQ:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_VIMQ);
      }
      return false;
      break;
    case VIMD:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_VIMD);
      }
      return false;
      break;

    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;

    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
