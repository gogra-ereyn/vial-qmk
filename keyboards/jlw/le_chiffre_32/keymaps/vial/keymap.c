// Copyright 2023 jlw
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HM_A	LGUI_T(KC_A)
#define HM_R	LALT_T(KC_R)
#define HM_S	LCTL_T(KC_S)

#define HM_E	RCTL_T(KC_E)
#define HM_I	LALT_T(KC_I)
#define HM_O	LGUI_T(KC_O)


enum custom_keycodes
{
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_EN,
    SMTD_KEYCODES_END,
};

#include "sm_td.h"

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count)
{
    switch (keycode) {
        // L
        SMTD_MT(CKC_A, KC_A, KC_LEFT_GUI)
        SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_D, KC_D, KC_LEFT_CTRL)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)
        // R
        SMTD_MT(CKC_J, KC_A, KC_LEFT_GUI)
        SMTD_MT(CKC_K, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_L, KC_D, KC_LEFT_CTRL)
    }
}


const int _BASE = 0;
const int _SYM = 1;
const int _NUM = 2;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         QK_BOOT,           KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,
        CKC_A,   CKC_S,   CKC_D,   CKC_F,   KC_G,                            KC_H,    CKC_J,   CKC_K,    CKC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_LALT,                            KC_B,    KC_N,    KC_M,  KC_RALT,  KC_RGUI,
                                   KC_LSFT,MO(1),                           KC_SPC,  MO(2)
    ),
    [1] = LAYOUT(
        LSFT(KC_EQUAL), LSFT(KC_7),     KC_LBRC,      KC_RBRC,      KC_SLSH,       KC_NO,            KC_BSLS,       KC_SCLN,       LSFT(KC_SCLN), LSFT(KC_4),     KC_BSPC,
        KC_MINUS,       LSFT(KC_MINUS), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_EQUAL,                         LSFT(KC_GRAVE),  KC_COMM,        KC_DOT,          LSFT(KC_5),     LSFT(KC_6),
        LSFT(KC_3),     LSFT(KC_2),     LSFT(KC_9),       LSFT(KC_0),       LSFT(KC_1),                         LSFT(KC_BSLS), KC_QUOTE,        LSFT(KC_QUOTE),  KC_GRAVE,       KC_TRNS,
                                                      KC_TRNS,          KC_TRNS,                          KC_TRNS,         KC_TRNS
    ),
    [2] = LAYOUT(
        KC_ESCAPE,      KC_7,           KC_8,             KC_9,             KC_0,           KC_NO,            KC_SCLN,       KC_0,            KC_1,            KC_2,           KC_BSPC,
        KC_TAB,         KC_4,           KC_5,             KC_6,             KC_EQUAL,                         KC_DOT,          KC_3,            KC_4,            KC_5,           KC_6,
        KC_LCTL,        KC_1,           KC_2,             KC_3,             KC_BSLS,                        KC_COMM,        KC_7,            KC_8,            KC_9,           KC_ENTER,
                                                          KC_TRNS,          KC_TRNS,                          KC_TRNS,         KC_TRNS
    ),
    [3] = LAYOUT(
        KC_ESCAPE,      KC_7,           KC_8,             KC_9,             KC_0,           KC_NO,            KC_SCLN,       KC_0,            KC_1,            KC_2,           KC_BSPC,
        KC_TAB,         KC_4,           KC_5,             KC_6,             KC_EQUAL,                         KC_DOT,          KC_3,            KC_4,            KC_5,           KC_6,
        KC_LCTL,        KC_1,           KC_2,             KC_3,             KC_BSLS,                        KC_COMM,        KC_7,            KC_8,            KC_9,           KC_ENTER,
                                                          KC_TRNS,          KC_TRNS,                          KC_TRNS,         KC_TRNS
    ),
};


// Encoder Map
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(S(KC_F2), KC_F2) },
    [1] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [2] =   { ENCODER_CCW_CW(_______, _______) },
    [3] =   { ENCODER_CCW_CW(_______, _______) }
};

// Combos disabled for Vial
#ifndef VIAL_ENABLE
    const uint16_t PROGMEM combo_esc[] = {KC_Q, KC_W,    COMBO_END};
    const uint16_t PROGMEM combo_del[] = {KC_Y, KC_QUOT, COMBO_END};
    combo_t key_combos[] = {
        COMBO(combo_esc, KC_ESC),
        COMBO(combo_del, KC_DEL),
    };
#endif

// RGB settings for indicator lights
// Layer and Mods indicator
#define LED_CENTER_TOP 1
#define LED_CENTER_BOTTOM 0

#define LAYER_R layer_colors[layer][0] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_G layer_colors[layer][1] *  RGB_INDICATOR_BRIGHTNESS / 255
#define LAYER_B layer_colors[layer][2] *  RGB_INDICATOR_BRIGHTNESS / 255

#define MODS_ACTIVE(mods) \
    ((get_mods()|get_oneshot_mods()) & MOD_MASK_##mods ? RGB_INDICATOR_BRIGHTNESS:0)
#define SHIFT_ACTIVE (get_mods() & MOD_MASK_SHIFT ? RGB_INDICATOR_BRIGHTNESS/4:0)
#define MODS_R MODS_ACTIVE(CTRL) + SHIFT_ACTIVE
#define MODS_G MODS_ACTIVE(GUI) + SHIFT_ACTIVE
#define MODS_B MODS_ACTIVE(ALT) + SHIFT_ACTIVE


const uint8_t PROGMEM layer_colors[][3] = {
    {RGB_OFF},
    {RGB_RED},
    {RGB_GREEN},
    {RGB_BLUE},
    {RGB_YELLOW},
    {RGB_PURPLE},
    {RGB_PINK},
    {RGB_TEAL}
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_smtd(keycode, record)){
        return false;
    }
    return true;
}



void set_rgb_matrix_indicators(uint8_t led_min, uint8_t led_max) {
    #if defined(RGB_LAYER_INDICATOR_ENABLE)
    int layer = get_highest_layer(layer_state|default_layer_state);
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, LAYER_R, LAYER_G, LAYER_B);
    /* uprintf("layer RGB: (%u, %u, %u)\n", LAYER_R, LAYER_G, LAYER_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_TOP, 0, 0, 0);
    #endif

    #if defined(RGB_MODS_INDICATOR_ENABLE)
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, MODS_R, MODS_G, MODS_B);
    /* uprintf("mod RGB: (%u, %u, %u)\n", MODS_R, MODS_G, MODS_B); */
    #else
    RGB_MATRIX_INDICATOR_SET_COLOR(LED_CENTER_BOTTOM, 0, 0, 0);
    #endif
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    set_rgb_matrix_indicators(led_min, led_max);
    return false;
}
