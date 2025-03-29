 /* This program is free software: you can redistribute it and/or modify
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
#include "process_combo.h"

enum custom_keycodes
{
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_V,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count)
{
    switch (keycode) {
        SMTD_MT(CKC_S, KC_S, KC_LALT)
        SMTD_MTE(CKC_D, KC_D, KC_LCTL)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)
        SMTD_MT(CKC_J, KC_J, KC_RSFT)
        SMTD_MTE(CKC_K, KC_K, KC_RCTL)
        SMTD_MT(CKC_L, KC_L, KC_RALT)
        SMTD_LT(CKC_V, KC_V, 2)
    }
}


const int _BASE = 0;
const int _SYM = 1;
const int _NUM = 2;

enum combos {
//  CV_LCTL,
//  NM_RCTL,
  ZX_LGUI,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;


const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
  COMBO(zx_combo, OSM(KC_LGUI))  // ZX_LGUI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_SLSH,   KC_Y,  KC_U,   KC_I,   KC_O,     KC_P,
    KC_A,  CKC_S,  CKC_D,  CKC_F,  KC_G,   KC_H,  CKC_J,  CKC_K,  CKC_L,    KC_ENT,
    KC_Z,   KC_X,   KC_C,   CKC_V,   KC_T,   KC_B,  KC_N,   KC_M,   MO(2),  OSL(3),
    KC_LCTL, OSM(MOD_LSFT), MO(1),                          KC_SPC, MO(2),   KC_LGUI
),
[1] = LAYOUT(
    LSFT(KC_EQUAL),   LSFT(KC_7),       KC_LBRC,         KC_RBRC,        KC_SLSH,            KC_BSLS,         KC_SCLN,        LSFT(KC_SCLN),   LSFT(KC_4),     KC_BSPC,
    KC_MINUS,         LSFT(KC_MINUS),   LSFT(KC_LBRC),   LSFT(KC_RBRC),  KC_EQUAL,           LSFT(KC_GRAVE),  KC_COMM,        KC_DOT,          LSFT(KC_5),     LSFT(KC_6),
    LSFT(KC_3),       LSFT(KC_2),       LSFT(KC_9),      LSFT(KC_0),     LSFT(KC_1),         LSFT(KC_BSLS),   KC_QUOTE,       LSFT(KC_QUOTE),  KC_GRAVE,       KC_TRNS,
    KC_TRNS,          KC_TRNS,          KC_TRNS,                                                                              KC_TRNS,         KC_TRNS,        KC_TRNS
),
[2] = LAYOUT(
    KC_ESC,           LCTL(LALT(KC_DEL)),    KC_TRNS,               LSFT(KC_8),     KC_F11,               KC_SCLN,            KC_0,            KC_1,              KC_2,           KC_BSPC,
    KC_TAB,           KC_LEFT,               KC_DOWN,               KC_UP,          KC_RGHT,              KC_DOT,             KC_3,            KC_4,              KC_5,           KC_6,
    OSM(KC_LGUI),     KC_TRNS,               KC_ESC,                KC_TAB,         LSFT(KC_8),           KC_COMM,            KC_7,            KC_8,              KC_9,           KC_TRNS,
    KC_TRNS,          KC_TRNS,               KC_TRNS,                                                                                          KC_TRNS,           KC_TRNS,        KC_TRNS
),

[3] = LAYOUT(
   LGUI(LSFT(KC_Q)),       LGUI(KC_S),         LGUI(KC_E),                LGUI(KC_R),       LGUI(KC_T),                         LGUI(KC_Y),          LGUI(KC_0),            LGUI(KC_1),            LGUI(KC_2),           KC_BSPC,
    LGUI(KC_D),            LGUI(KC_LEFT),      LGUI(KC_DOWN),             LGUI(KC_UP),      LGUI(KC_RGHT),                      LGUI(KC_H),          LGUI(KC_3),            LGUI(KC_4),            LGUI(KC_5),           LGUI(KC_6),
    QK_BOOT,               LGUI(KC_F),         LSFT(LGUI(KC_C)),          LGUI(KC_V),       KC_TRNS,                            LGUI(LSFT(KC_S)),    LGUI(KC_7),            LGUI(KC_8),            LGUI(KC_9),           KC_TRNS,
    KC_TRNS,               KC_TRNS,            KC_TRNS,                                                                                                                     LGUI(KC_SPC),          KC_TRNS,              KC_TRNS
),
[4] = LAYOUT(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,  KC_U,   KC_I,   KC_O,     KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,  KC_J,   KC_K,   KC_L,    KC_ENT,
    KC_Z,   KC_X,   KC_C,   KC_V,   TO(0),   KC_B,  KC_N,   KC_M,   MO(2),  OSL(3),
    KC_LCTL, OSM(MOD_LSFT), MO(1),                          KC_SPC, MO(2),   KC_LGUI
),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    return true;
}

