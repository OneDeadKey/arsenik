// https://docs.qmk.fm/#/feature_combo
// https://docs.qmk.fm/#/feature_macros
// https://docs.qmk.fm/#/feature_mouse_keys

#include QMK_KEYBOARD_H

// homerow mod-taps (aliases for readability + re-use in combo definitions)
#define HM_A    LSFT_T(KC_A)
#define HM_S    LGUI_T(KC_S)
#define HM_D    LALT_T(KC_D)
#define HM_F    LCTL_T(KC_F)
#define HM_J    LCTL_T(KC_J)
#define HM_K    LALT_T(KC_K)
#define HM_L    LGUI_T(KC_L)
#define HM_SCLN LSFT_T(KC_SCLN)

// 1dk-specific key codes
#define CC_1DK       KC_SCLN   // Lafayette: main dead key on [;]
#define CC_SCLN LSFT(KC_COMM)  // ";" on Shift+[,]
#define CC_COLN LSFT(KC_DOT)   // ":" on Shift+[.]
#define CC_LT        KC_NUBS   // "<" on [Non-US-Backslash]
#define CC_GT   LSFT(KC_NUBS)  // ">" on Shift+[Non-US-Backslash]

// 1dk-specific macros
enum macro_keycodes {
    // dead key, number/sign
    ODK_1 = SAFE_RANGE,
    ODK_2,
    ODK_3,
    ODK_4,
    ODK_5,
    ODK_6,
    ODK_7,
    ODK_8,
    ODK_9,
    ODK_0,
    ODK_MN,
    ODK_EQ,
    // dead key, shift + number/sign
    ODK_S1,
    ODK_S2,
    ODK_S3,
    ODK_S4,
    ODK_S5,
    ODK_S6,
    ODK_S7,
    ODK_S8,
    ODK_S9,
    ODK_S0,
    ODK_SMN,
    ODK_SEQ,
};

// keyboard layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Base layer: QWERTY with home row mods and thumb mod-taps
    [0] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,      KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    LT(2,KC_BSPC), LSFT_T(KC_ENT),     LT(3,KC_TAB), LT(1,KC_SPC)
    ),

    // Code layer: Lafayette/ErgoL AltGr symbols
    [1] = LAYOUT_split_3x5_2(
        KC_1,    KC_LBRC, KC_RBRC, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_QUOT, KC_0,
        KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_EQL,    KC_PLUS, KC_MINS, CC_LT,   CC_GT,   KC_DQUO,
        KC_TILD, KC_GRV,  KC_PIPE, KC_UNDS, KC_PSLS,   KC_BSLS, KC_AT,   KC_HASH, KC_EXLM, KC_QUES,
                                   KC_SPC,  KC_ENT,    KC_TRNS, KC_TRNS
    ),

    // Num layer: number row with 1dk+num macros and punctuation signs
    [2] = LAYOUT_split_3x5_2(
        KC_EXLM, ODK_2,   ODK_3,   ODK_5,   KC_PERC,   ODK_6,   ODK_7,   ODK_8,   ODK_9,   ODK_0,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        ODK_S1,  ODK_S2,  ODK_S3,  ODK_S4,  ODK_S5,    ODK_SMN, ODK_MN,  CC_SCLN, CC_COLN, KC_QUES,
                                   KC_TRNS, KC_TRNS,   KC_ESC,  LSFT(KC_SPC)
    ),

    // Navigation layer: arrow keys and mouse emulation (constant mode)
    // (note: KC_BTN4/BTN5 should be the mouse prev/next buttons)
    [3] = LAYOUT_split_3x5_2(
#if defined(MK_3_SPEED) || defined(MK_COMBINED)
        KC_BRIU, KC_BTN4, KC_MS_U, KC_BTN5, KC_VOLU,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LSFT(KC_ENT),
        KC_SLEP, KC_BTN3, KC_WH_U, KC_WH_D, KC_MUTE,   KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
                                   KC_BTN1, KC_BTN2,   KC_TRNS, KC_TRNS
#else
        KC_BRIU, KC_BTN4, KC_MS_U, KC_BTN5, KC_VOLU,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DEL,
        KC_BRID, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LSFT(KC_ENT),
        KC_SLEP, KC_NO,   KC_NO,   KC_BTN3, KC_MUTE,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,
                                   KC_BTN1, KC_BTN2,   KC_TRNS, KC_TRNS
#endif
    )

};

// https://getreuer.info/posts/keyboards/macros/#simple-macros
#define RETURN_1DK(key) tap_code(CC_1DK); tap_code(key); return false;
#define RETURN_S1DK(key) tap_code(CC_1DK); \
    register_code(KC_LSFT); tap_code(key); unregister_code(KC_LSFT); \
    return false;
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) switch (keycode) {
        // send dead key + number/sign
        case ODK_1 ... ODK_0: RETURN_1DK(KC_1 + keycode - ODK_1);
        case ODK_MN:          RETURN_1DK(KC_MINS);
        case ODK_EQ:          RETURN_1DK(KC_EQL);
        // send dead key + shift + number/sign
        case ODK_S1 ... ODK_S0: RETURN_S1DK(KC_1 + keycode - ODK_S1);
        case ODK_SMN:           RETURN_S1DK(KC_MINS);
        case ODK_SEQ:           RETURN_S1DK(KC_EQL);
    }
    return true;
}

/**
 * Combos
 */

#ifdef COMBO_ENABLE

enum combos {
    COMBO_DF,
    COMBO_JK,
    COMBO_DOT_COMM,
    COMBO_COUNT
};
uint16_t COMBO_LEN = COMBO_COUNT; // required by the COMBO macro
const uint16_t PROGMEM df_combo[]       = {HM_D,    HM_F,    COMBO_END};
const uint16_t PROGMEM jk_combo[]       = {HM_J,    HM_K,    COMBO_END};
const uint16_t PROGMEM dot_comm_combo[] = {KC_DOT,  KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_DF] = COMBO(df_combo, KC_ENT),
    [COMBO_JK] = COMBO(jk_combo, KC_ESC),
    [COMBO_DOT_COMM] = COMBO_ACTION(dot_comm_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) switch(combo_index) {
        case COMBO_DOT_COMM:
            tap_code16(LCTL(KC_BSPC));
            break;
    }
}

#endif

/**
 * Rotary encoders
 */

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
