/* Copyright 2021 alittlepeace
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

// pandur keymap

#include QMK_KEYBOARD_H
     
void keyboard_post_init_user(void)
{
  rgblight_disable_noeeprom(); 
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    switch (get_highest_layer(state)) {
        case 1:
            rgblight_enable_noeeprom(); 
            rgblight_setrgb(RGB_BLUE);
            break;
        case 2:
            rgblight_enable_noeeprom(); 
            rgblight_setrgb(RGB_RED);
            break;
        default: // for any other layers, or the default layer
            rgblight_disable_noeeprom(); 
            break;
    }

    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ansi_split_bs(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,      KC_BSPC,    KC_KB_VOLUME_UP,  
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BACKSLASH,             KC_KB_VOLUME_DOWN,
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                            KC_DELETE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                    KC_UP,
    KC_LCTL,          KC_LGUI,          KC_SPC,  TG(2),          KC_SPC,           MO(1),                           KC_LEFT, KC_DOWN, KC_RGHT 
  ),

  // mouse layer
  [1] = LAYOUT_ansi_split_bs(
    _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______, _______, BL_TOGG,
    _______, _______,   MS_UP, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL,           _______,
    _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          MS_WHLU, 
    _______, _______,          MS_BTN1, _______,          MS_BTN2,          _______,                            MS_WHLL, MS_WHLD, MS_WHLR 
  ),

  // ansi drawing, f keys instead of numbers...
  [2] = LAYOUT_ansi_split_bs( 
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_MINS,  KC_EQL,   KC_BSLS,      KC_BSPC,    KC_KB_VOLUME_UP,  
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BACKSLASH,             KC_KB_VOLUME_DOWN,
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_ENT,                             KC_DELETE,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                    KC_UP,
    KC_LCTL,          KC_LGUI,          KC_SPC,  TG(2),          KC_SPC,           TG(2),                                 KC_LEFT, KC_DOWN, KC_RGHT 
  ),
};
