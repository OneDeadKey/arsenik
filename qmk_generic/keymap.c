#include QMK_KEYBOARD_H
#include "arsenik.h"
// Dummy sed marker (used by arsenik, keep includes above this line)

enum arsenik_layers {
    _base,
    _lafayette,
    _num_row,
    _vim_nav,
    _num_nav,
    _num_pad,
    _fun_pad,
};

enum custom_keycodes {
    ODK_1 = SAFE_RANGE,  // „
    ODK_2,  // “
    ODK_3,  // ”
    ODK_4,  // ¢
    ODK_5,  // ‰
};

// Syntaxic sugar
#ifndef TEST
#    define AG(keycode) RALT(keycode)
#    define XX KC_NO
#    define __ KC_TRNS
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_base] = ARSENIK_LAYOUT(
        KC_CAPS, KC_1, KC_2,  KC_3,  KC_4,  KC_5,      KC_6, KC_7,  KC_8,   KC_9,    KC_0,    KC_DEL,
        KC_TAB,  KC_Q, KC_W,  KC_E,  KC_R,  KC_T,      KC_Y, KC_U,  KC_I,   KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A, KC_SS, KC_DD, KC_FF, KC_G,      KC_H, KC_JJ, KC_KK,  KC_LL,   KC_SCLN, KC_ENTER,
        KC_LSFT, KC_Z, KC_X,  KC_C,  KC_V,  KC_B,      KC_N, KC_M,  KC_DOT, KC_COMM, KC_SLSH, KC_RSFT,
             AS_TL_TUCK, AS_TL_HOME, AS_TL_REACH,      AS_TR_REACH, AS_TR_HOME, AS_TR_TUCK
    ),

    [_lafayette] = ARSENIK_LAYOUT(
        __, AG(KC_1), AG(KC_2), AG(KC_3), AG(KC_4), AG(KC_5),      AG(KC_6), AG(KC_7), AG(KC_8), AG(KC_9), AG(KC_0), __,
        __, AS(CIRC), AS(LT),   AS(GT),   AS(DLR),  AS(PERC),      AS(AT),   AS(AMPR), AS(ASTR), AS(QUOT), AS(GRV),  __,
        __, AS(LCBR), AS(LPRN), AS(LPRN), AS(RCBR), AS(EQL),       AS(BSLS), AS(PLUS), AS(MINS), AS(SLSH), AS(DQUO), __,
        __, AS(TILD), AS(LBRC), AS(RBRC), AS(UNDS), AS(HASH),      AS(PIPE), AS(EXLM), AS(SCLN), AS(COLN), AS(QUES), __,
                                    MO(_num_row), KC_SPC, XX,      XX, KC_SPC, MO(_num_row)
    ),

    // Not fully implemented yet
    [_num_row] = ARSENIK_LAYOUT(
        __, __,    __,    __,    __,    __,         __,    __,       __,       __,      __,       __,
        __, AS_S1, AS_S2, AS_S3, AS_S4, AS_S5,      AS_S6, AS_S7,    AS_S8,    AS_S9,   AS_S0,    __,
        __, AS(1), AS(2), AS(3), AS(4), AS(5),      AS(6), AS(7),    AS(8),    AS(9),   AS(0),    __,
        __, ODK_1, ODK_2, ODK_3, ODK_4, ODK_5,      XX,    AS(MINS), AS(COMM), AS(DOT), AS(SLSH), __,
        LAFAYETTE_LAYER_TOGGLE, KC_SPC, XX,         XX, KC_SPC, LAFAYETTE_LAYER_TOGGLE
    ),

    [_vim_nav] = ARSENIK_LAYOUT(
        __, G(KC_1),      G(KC_2),  G(KC_3),   G(KC_4),  G(KC_5), G(KC_6),  G(KC_7),  G(KC_8), G(KC_9), G(KC_0),      __,
        __, MO(_num_nav), C(AS(T)), KC_WBAK,   KC_WFWD,  XX,      KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,  G(AS(P)),     __,
        __, C(AS(A)),     C(AS(S)), S(KC_TAB), KC_TAB,   XX,      KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, MO(_fun_pad), __,
        __, C(AS(Z)),     C(AS(X)), C(AS(C)),  C(AS(V)), XX,      KC_WH_L,  KC_WH_D,  KC_WH_U, KC_WH_R, XX,           __,
                                             KC_DEL, __, XX,      XX, __, KC_ESC
    ),

    [_num_nav] = ARSENIK_LAYOUT(
        __, G(KC_1),  G(KC_2),  G(KC_3),  G(KC_4),  G(KC_5),        G(KC_6),  G(KC_7),  G(KC_8), G(KC_9), G(KC_0),  __,
        __, KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,        AS(SLSH), AS(7),    AS(8),   AS(9),   G(AS(P)), __,
        __, C(AS(A)), KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,        AS(MINS), AS(4),    AS(5),   AS(6),   AS(0),    __,
        __, C(AS(Z)), C(AS(X)), C(AS(C)), C(AS(V)), S(KC_TAB),      AS(COMM), AS(1),    AS(2),   AS(3),   AS(DOT),  __,
                                               KC_DEL, __, XX,      XX, __, KC_ESC
    ),

    [_fun_pad] = ARSENIK_LAYOUT(
        __, __,    __,     __,     __,     __,      __, __,      __,      __,      __, __,
        __, KC_F1, KC_F2,  KC_F3,  KC_F4,  XX,      XX, XX,      XX,      XX,      XX, __,
        __, KC_F5, KC_F6,  KC_F7,  KC_F8,  XX,      XX, KC_LCTL, KC_LALT, KC_LGUI, __, __,
        __, KC_F9, KC_F10, KC_F11, KC_F12, XX,      XX, XX,      XX,      XX,      XX, __,
        LAFAYETTE_LAYER_TOGGLE, KC_SPC, XX,         XX, KC_SPC, LAFAYETTE_LAYER_TOGGLE
    ),

};

// This is where you’ll write most of your custom code for your keyborad.
// This callback is called before the keycode is sent to the OS.
// returning false cancels any furnther treatment.
// for instance, calling `tap_code(KC_B)` if KC_A is pressed but true is
// returned, "ba" is sent, but if `false` is returned, it’s just "b"
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#   ifdef SELENIUM_RESTORE_SPACE
    static bool thumb_mod_same_hand_as_space_held = false;
    if (keycode == THUMB_MOD_SAME_HAND_AS_SPACE && record->event.tap == 0)
        thumb_mod_same_hand_as_space_held = record->event.pressed;
#   endif

    // Let QMK do its thing on key releases.
    if (!record->event.pressed) return true;

    switch (keycode) {
        // Code for your custom keycodes goes here.

        // Below are definitoins for features provided by Arsenik, depending on
        // your config.
#       ifdef SELENIUM_RESTORE_SPACE
        case ALT_THUMB_KEY_SPACE:
            if (!thumb_mod_same_hand_as_space_held) return true;
            if (record->event.tap == 0) return true;
            tap_code(KC_SPC);
            return false;
#       endif

        case ODK_1: ODK1_SEQUENCE; return false;
        case ODK_2: ODK2_SEQUENCE; return false;
        case ODK_3: ODK3_SEQUENCE; return false;
        case ODK_4: ODK4_SEQUENCE; return false;
        case ODK_5: ODK5_SEQUENCE; return false;
    }

    return true;
}

static inline bool tap_keycode_used_in_text(uint16_t keycode) {
    // We can’t make assumptions on curstom keycodes
    if (keycode >= SAFE_RANGE) return false;

    // Remove "quantum" part of the keycode to get the action on tap.
    const uint16_t tap_keycode = keycode & 0xff;
    // `tap_keycode <= KC_0` includes all letters and numbers, but also
    // `KC_NO` which is safer to include, since it is commonly used in the
    // keymap as a placeholder for complex actions on tap.
    return (tap_keycode <= KC_0) || (tap_keycode == KC_SPACE);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return tap_keycode_used_in_text(keycode) ? ARSENIK_HRM_TAPPING_TERM : TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !tap_keycode_used_in_text(keycode);
}
