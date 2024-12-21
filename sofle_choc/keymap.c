/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _WIN  0
#define _MAC  1
#define _SPCL  2

enum custom_keycodes {
  VIM_CMD = SAFE_RANGE,
  VIM_QUIT,
  VIM_SAVE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MODE |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | LGUI | CTRL | Space| / LALT  /       \ CTRL \  | Bspc | SPCL |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_WIN] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    DF(_MAC),
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    _______,       _______,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      _______, KC_LGUI, KC_LCTL, KC_SPC,  KC_LALT,       MO(_SPCL), KC_BSPC,  KC_RCTL,  KC_DEL,  _______
),

/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MODE |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | LGUI | CMD  | Space| / LALT  /       \ CTRL \  | Bspc | SPCL |  DEL |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MAC] = LAYOUT(
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    DF(_WIN),
    KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    _______,       _______,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      _______, KC_LGUI, KC_LCMD, KC_SPC,  KC_LALT,       MO(_SPCL), KC_BSPC,  KC_RCTL,  KC_DEL,  _______
),

/*
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | MUTE |      |  (   |      |   )  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | VOL+ |   -  |  {   |   +  |   }  |  "   |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | VOL- |   _  |  [   |   =  |   ]  |  '   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SPCL] = LAYOUT(
    KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,    KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_MUTE,  _______, KC_LPRN, _______, KC_RPRN, _______,                       _______,  _______,  _______, _______, _______, _______,
    KC_VOLU,  KC_MINS, KC_LCBR, KC_PLUS, KC_RCBR, KC_DQT,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,VIM_SAVE,VIM_QUIT,
    KC_VOLD,  KC_UNDS, KC_LBRC, KC_EQUAL,KC_RBRC, KC_QUOT, _______,     _______, _______,  _______,  _______, _______, _______, _______,
                       _______, _______, _______, _______, _______,     _______, _______,  _______,  _______, _______
),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIM_SAVE:
        if (record->event.pressed) {
          send_string(SS_LCTL("c"));
          _delay_ms(50);
          send_string(":w" SS_TAP(X_ENTER));
          return false;
        } 
        break;
    case VIM_QUIT:
        if (record->event.pressed) {
          send_string(SS_LCTL("c"));
          _delay_ms(50);
          send_string(":wqa!" SS_TAP(X_ENTER));
          return false;
        } 
        break;
    }
    return true;
}
