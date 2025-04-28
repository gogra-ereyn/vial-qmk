/* Copyright 2024 ai03 Design Studio */
/* SPDX-License-Identifier: GPL-2.0-or-later */

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
    VM_ESC,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count)
{
    switch (keycode) {
        // HRM
        // L
        SMTD_MT(CKC_S, KC_S, KC_LALT)
        SMTD_MTE(CKC_D, KC_D, KC_LCTL)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)
        // R
        SMTD_MT(CKC_J, KC_J, KC_RSFT)
        SMTD_MTE(CKC_K, KC_K, KC_RCTL)
        SMTD_MT(CKC_L, KC_L, KC_RALT)

        // Layers
        SMTD_LT(CKC_V, KC_V, 2)
    }
}

enum combos {
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
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_SLSH, XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    CKC_S,   CKC_D    CKC_F,   KC_G,    XXXXXXX, XXXXXXX, KC_H,    CKC_J,   CKC_K,   CKC_L,   KC_ENTER, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    CKC_V,   KC_T,    XXXXXXX, XXXXXXX, KC_B,    KC_N,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,  MO(2),   KC_TAB,  KC_DEL
    ),
    [1] = LAYOUT(
        _______, LSFT(KC_EQUAL), LSFT(KC_7),     KC_LBRC,          KC_RBRC,          KC_SLSH,       _______, _______, KC_BSLS,         KC_SCLN,        LSFT(KC_SCLN),   LSFT(KC_4),     KC_BSPC,              _______,
        _______, KC_MINUS,       LSFT(KC_MINUS), LSFT(KC_LBRC),    LSFT(KC_RBRC),    KC_EQUAL,      _______, _______, LSFT(KC_GRAVE),  KC_COMM,        KC_DOT,          LSFT(KC_5),     LSFT(KC_6),           _______,
        _______, LSFT(KC_3),     LSFT(KC_2),     LSFT(KC_9),       LSFT(KC_0),       LSFT(KC_1),    _______, _______, FT(KC_BSLS),     KC_QUOTE,       LSFT(KC_QUOTE),  KC_GRAVE,       KC_TRNS,              _______,
                                 _______,        _______,      _______,      _______,    _______, _______, _______, _______
    ),

    [2] = LAYOUT(
        _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
        _______, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    )

};
