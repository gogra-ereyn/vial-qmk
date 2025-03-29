// Copyright 2023 jlw
// SPDX-License-Identifier: GPL-2.0-or-later

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

//const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
//const uint16_t PROGMEM nm_combo[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
//  COMBO(cv_combo, OSM(KC_LCTL)), // CV_LCTL
//  COMBO(nm_combo, OSM(KC_RCTL)), // NM_RCTL
  COMBO(zx_combo, OSM(KC_LGUI))  // ZX_LGUI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_3thumb(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_SLSH,         TO(0),           KC_Y,    KC_U,    KC_I,     KC_O,          KC_P,
        KC_A,   CKC_S,   CKC_D,   CKC_F,    KC_G,                            KC_H,    CKC_J,   CKC_K,    CKC_L,         KC_ENTER,
        KC_Z,    KC_X,    KC_C,    CKC_V,   KC_T,                          KC_B,    KC_N,    KC_M,     MO(2),  OSL(3),
                OSM(MOD_LSFT), OSM(MOD_LSFT), MO(1),                            KC_SPC,   MO(2), MO(2)
    ),
    [1] = LAYOUT_3thumb(
        LSFT(KC_EQUAL), LSFT(KC_7),     KC_LBRC,      KC_RBRC,      KC_SLSH,       KC_TRNS,            KC_BSLS,       KC_SCLN,       LSFT(KC_SCLN), LSFT(KC_4),             KC_BSPC,
        KC_MINUS,       LSFT(KC_MINUS), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_EQUAL,                         LSFT(KC_GRAVE),  KC_COMM,        KC_DOT,          LSFT(KC_5),     LSFT(KC_6),
        LSFT(KC_3),     LSFT(KC_2),     LSFT(KC_9),       LSFT(KC_0),       LSFT(KC_1),                         LSFT(KC_BSLS), KC_QUOTE, LSFT(KC_QUOTE),  KC_GRAVE,       KC_TRNS,
                                                      KC_TRNS,KC_TRNS,          KC_TRNS,                          KC_TRNS,         KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_3thumb(
        KC_ESC,         LCTL(LALT(KC_DEL)),           RGB_TOG,             LSFT(KC_8), KC_F11,             KC_TRNS,                     KC_SCLN,       KC_0,            KC_1,            KC_2,           KC_BSPC,
        KC_TAB,         KC_LEFT,        KC_DOWN,             KC_UP,             KC_RGHT,                         KC_DOT,          KC_3,            KC_4,            KC_5,           KC_6,
        OSM(KC_LGUI),        KC_TRNS,           KC_ESC,             KC_TAB,             LSFT(KC_8),                        KC_COMM,        KC_7,            KC_8,            KC_9,           KC_TRNS,
                                                          KC_TRNS,KC_TRNS,          KC_TRNS,                          KC_TRNS,         KC_TRNS,KC_TRNS
    ),
    [3] = LAYOUT_3thumb(
        LGUI(LSFT(KC_Q)),      LGUI(KC_S),           LGUI(KC_E),                LGUI(KC_R),     LGUI(KC_T),        KC_TRNS,             LGUI(KC_Y),          LGUI(KC_0),            LGUI(KC_1),            LGUI(KC_2),            KC_BSPC,
        LGUI(KC_D),            LGUI(KC_LEFT),        LGUI(KC_DOWN),             LGUI(KC_UP),    LGUI(KC_RGHT),                      LGUI(KC_H),          LGUI(KC_3),            LGUI(KC_4),            LGUI(KC_5),           LGUI(KC_6),
        QK_BOOT,               LGUI(KC_F),           LSFT(LGUI(KC_C)),          LGUI(KC_V),        KC_TRNS,                            LGUI(LSFT(KC_S)),       LGUI(KC_7),            LGUI(KC_8),            LGUI(KC_9),           KC_TRNS,
                                                                                KC_TRNS,KC_TRNS,        KC_TRNS,                            LGUI(KC_SPC),        KC_TRNS,KC_TRNS
    ),
    [4] = LAYOUT_3thumb(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         TO(0),           KC_Y,    KC_U,    KC_I,     KC_O,          KC_P,
        KC_A,   KC_S,   KC_D,   KC_F,    KC_G,                            KC_H,    KC_J,   KC_K,    KC_L,         KC_ENTER,
        KC_Z,    KC_X,    KC_C,    CKC_V,   TO(0),                          KC_B,    KC_N,    KC_M,     MO(2),  OSL(3),
                OSM(MOD_LSFT), OSM(MOD_LSFT), MO(1),                            KC_SPC,   MO(2), MO(2)
    ),
};


// Encoder Map
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [1] =   { ENCODER_CCW_CW(RGB_TOG, RGB_TOG) },
    [2] =   { ENCODER_CCW_CW(RGB_TOG, RGB_TOG) },
    [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [4] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};

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
    if (!process_smtd(keycode, record))
        return false;

    if (keycode == VM_ESC) {
        if (record->event.pressed) {
            register_code(KC_LCTL);
            register_code(KC_LALT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }
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
