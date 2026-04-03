// QMK keymap ported from KMK

// Layers: 0 = QWERTY, 1 = LOWER, 2 = RAISE
//
// Mod-tap / Layer-tap equivalents:
//   MT_RSEN  -> MT(MOD_RSFT, KC_ENT)
//   KC_LRGR  -> LT(LOWER, KC_GRV)
//   KC_RSSP  -> LT(RAISE, KC_SPC)


#include QMK_KEYBOARD_H
#include "hardware/gpio.h"

// void keyboard_post_init_user(void) {
//     gpio_init(28);
//     gpio_set_dir(28, GPIO_IN);
//     gpio_pull_up(28);
// }


// Layer indices
enum layers {
    _QWERTY = 0,
    _LOWER  = 1,
    _RAISE  = 2,
    _ADJUST = 3,
};

// Convenience aliases
#define MT_RSEN MT(MOD_RSFT, KC_ENT)
#define KC_LRGR LT(_LOWER,  KC_GRV)
#define KC_RSSP LT(_RAISE,  KC_SPC)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define ADJUST  LT(_ADJUST, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT_RSEN,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, KC_LRGR, KC_SPC, KC_LALT,   KC_A, KC_ESC,  KC_RSSP, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [_LOWER] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, XXXXXXX, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MT_RSEN,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, KC_LRGR, KC_SPC, KC_LALT,   KC_A, KC_ESC,  KC_RSSP, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    [_RAISE] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   KC_LGUI, KC_LRGR, KC_SPC, KC_LALT,   KC_A, KC_ESC,  KC_RSSP, KC_RALT
                                        //`--------------------------'  `--------------------------'
    ),

    // _ADJUST layer is defined but not populated in the original keymap.
    // ADJUST = LT(_ADJUST, KC_SPC) is declared but the thumb cluster uses
    // KC_SPC directly, so this layer is a placeholder — fill it as needed.
    [_ADJUST] = LAYOUT(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                                        //`--------------------------'  `--------------------------'
    ),
};