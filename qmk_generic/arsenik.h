#pragma once

// ╭─────────────────────────────────────────────────────────╮
// │         Generic modifiers / Keycodes / Helpers          │
// ╰─────────────────────────────────────────────────────────╯

// TODO: find better names for those macros ?
#ifdef ARSENIK_MAC_MODIFIERS
#    define _GUI_T LALT_T
#    define _CTL_T LGUI_T
#    define _ALT_T LCTL_T
#    define _GUI KC_LALT
#    define _CTL KC_LGUI
#    define _ALT KC_LCTL
#else
#    define _GUI_T LGUI_T
#    define _CTL_T LCTL_T
#    define _ALT_T LALT_T
#    define _GUI KC_LGUI
#    define _CTL KC_LCTL
#    define _ALT KC_LALT
#endif

#ifdef ARSENIK_ENABLE_HRM
#    define KC_SS _GUI_T(KC_S)
#    define KC_DD _CTL_T(KC_D)
#    define KC_FF _ALT_T(KC_F)
#    define KC_JJ _ALT_T(KC_J)
#    define KC_KK _CTL_T(KC_K)
#    define KC_LL _GUI_T(KC_L)
#else
#    define KC_SS KC_S
#    define KC_DD KC_D
#    define KC_FF KC_F
#    define KC_JJ KC_J
#    define KC_KK KC_K
#    define KC_LL KC_L
#endif

// Unused in this file, helper for `process_arsenik` in `arsenik.c`
#ifdef SELENIUM_LEFT_HAND_SPACE
#    ifdef SELENIUM_SWAP_SAME_THUMB_HOLD_ACTION
#        define THUMB_MOD_SAME_HAND_AS_SPACE AS_TL_HOME
#    else
#        define THUMB_MOD_SAME_HAND_AS_SPACE AS_TL_TUCK
#    endif
#    define ALT_THUMB_KEY_SPACE AS_TR_HOME
#else
#    ifdef SELENIUM_SWAP_SAME_THUMB_HOLD_ACTION
#        define THUMB_MOD_SAME_HAND_AS_SPACE AS_TR_HOME
#    else
#        define THUMB_MOD_SAME_HAND_AS_SPACE AS_TR_TUCK
#    endif
#    define ALT_THUMB_KEY_SPACE AS_TL_HOME
#endif

#if defined ARSENIK_HOST_LAYOUT_QWERTY
#    define AS(stripped_keycode) KC_##stripped_keycode
#elif defined ARSENIK_HOST_LAYOUT_AZERTY
#    define AS(stripped_keycode) FR_##stripped_keycode
#    define SHIFTED_NUMBERS
#    include "keymap_french.h"
#    include "sendstring_french.h"
#elif defined ARSENIK_HOST_LAYOUT_ERGOL
#    define AS(stripped_keycode) EL_##stripped_keycode
#    include "keymap_ergol.h"
#    define ODK1_SEQUENCE tap_code(EL_ODK); tap_code(KC_1)
#    define ODK2_SEQUENCE tap_code(EL_ODK); tap_code(KC_2)
#    define ODK3_SEQUENCE tap_code(EL_ODK); tap_code(KC_3)
#    define ODK4_SEQUENCE tap_code(EL_ODK); tap_code(KC_4)
#    define ODK5_SEQUENCE tap_code(EL_ODK); tap_code(KC_5)
#elif defined ARSENIK_HOST_LAYOUT_BEPO
#    define AS(stripped_keycode) BE_##stripped_keycode
#    define SHIFTED_NUMBERS
#    include "keymap_bepo.h"
#    include "sendstring_bepo.h"
#elif defined ARSENIK_HOST_LAYOUT_DVORAK
#    define AS(stripped_keycode) DV_##stripped_keycode
#    include "keymap_dvorak.h"
#    include "sendstring_dvorak.h"
#elif defined ARSENIK_HOST_LAYOUT_COLEMAK
#    define AS(stripped_keycode) CM_##stripped_keycode
#    include "keymap_colemak.h"
#    include "sendstring_colemak.h"
#elif defined ARSENIK_HOST_LAYOUT_WORKMAN
#    define AS(stripped_keycode) WK_##stripped_keycode
#    include "keymap_workman.h"
#    include "sendstring_workman.h"
#else
#    warning "No `ARSENIK_HOST_LAYOUT_*` option was found or recognised. Using `QWERTY` as default"
#    define AS(stripped_keycode) KC_##stripped_keycode
#endif

#ifndef ODK1_SEQUENCE
#    define ODK1_SEQUENCE tap_code(KC_NO)
#endif
#ifndef ODK2_SEQUENCE
#    define ODK2_SEQUENCE tap_code(KC_NO)
#endif
#ifndef ODK3_SEQUENCE
#    define ODK3_SEQUENCE tap_code(KC_NO)
#endif
#ifndef ODK4_SEQUENCE
#    define ODK4_SEQUENCE tap_code(KC_NO)
#endif
#ifndef ODK5_SEQUENCE
#    define ODK5_SEQUENCE tap_code(KC_NO)
#endif


#ifdef SHIFTED_NUMBERS
#    define AS_S0  KC_0
#    define AS_S1  KC_1
#    define AS_S2  KC_2
#    define AS_S3  KC_3
#    define AS_S4  KC_4
#    define AS_S5  KC_5
#    define AS_S6  KC_6
#    define AS_S7  KC_7
#    define AS_S8  KC_8
#    define AS_S9  KC_9
#else
#    define AS_S0  S(KC_0)
#    define AS_S1  S(KC_1)
#    define AS_S2  S(KC_2)
#    define AS_S3  S(KC_3)
#    define AS_S4  S(KC_4)
#    define AS_S5  S(KC_5)
#    define AS_S6  S(KC_6)
#    define AS_S7  S(KC_7)
#    define AS_S8  S(KC_8)
#    define AS_S9  S(KC_9)
#endif


// ╭─────────────────────────────────────────────────────────╮
// │                 Thumb keys definitions                  │
// ╰─────────────────────────────────────────────────────────╯

#ifdef ARSENIK_ENABLE_LAFAYETTE_LAYER
#    define LAFAYETTE_LAYER_TOGGLE MO(_lafayette)
#    define LAFAYETTE_LAYER_QUANTUM(keycode) LT(_lafayette, keycode)
#else
#    define LAFAYETTE_LAYER_TOGGLE KC_RALT
#    define LAFAYETTE_LAYER_QUANTUM(keycode) RALT_T(keycode)
#endif

// Extra simple config for beginners with bigger keyboards
#if defined ARSENIK_DISABLE_THUMB_TAP_HOLDS
#    define AS_TL_TUCK  _ALT
#    define AS_TL_HOME  _CTL
#    define AS_TL_REACH _GUI
#    define AS_TR_REACH MO(_num_nav)
#    define AS_TR_HOME  KC_SPC
#    define AS_TR_TUCK  LAFAYETTE_LAYER_TOGGLE

// Selenium mod with a few customsation options
#elif defined ARSENIK_ENABLE_SELENIUM_VARIANT
#    ifdef SELENIUM_LEFT_HAND_SPACE
#        define LEFT_THUMB_HOME_TAP  KC_SPC
#        define RIGHT_THUMB_HOME_TAP KC_BSPC
#    else
#        define LEFT_THUMB_HOME_TAP  KC_BSPC
#        define RIGHT_THUMB_HOME_TAP KC_SPC
#    endif

#    ifdef SELENIUM_LEFT_HAND_NAV
#        define LEFT_THUMB_HOME_QUANTUM(tap_keycode)  LT(_vim_nav, tap_keycode)
#        define RIGHT_THUMB_HOME_QUANTUM(tap_keycode) LT(_num_row, tap_keycode)
#    else
#        define LEFT_THUMB_HOME_QUANTUM(tap_keycode)  LT(_num_row, tap_keycode)
#        define RIGHT_THUMB_HOME_QUANTUM(tap_keycode) LT(_vim_nav, tap_keycode)
#    endif

#    ifdef SELENIUM_SWAP_SAME_THUMB_HOLD_ACTION
#        define AS_TL_TUCK  LEFT_THUMB_HOME_QUANTUM(KC_ESC)
#        define AS_TL_HOME  LSFT_T(LEFT_THUMB_HOME_TAP)
#        define AS_TL_REACH KC_NO
#        define AS_TR_REACH KC_NO
#        define AS_TR_HOME  LAFAYETTE_LAYER_QUANTUM(RIGHT_THUMB_HOME_TAP)
#        define AS_TR_TUCK  RIGHT_THUMB_HOME_QUANTUM(KC_ENT)
#    else
#        define AS_TL_TUCK  LSFT_T(KC_ESC)
#        define AS_TL_HOME  LEFT_THUMB_HOME_QUANTUM(LEFT_THUMB_HOME_TAP)
#        define AS_TL_REACH KC_NO
#        define AS_TR_REACH KC_NO
#        define AS_TR_HOME  RIGHT_THUMB_HOME_QUANTUM(RIGHT_THUMB_HOME_TAP)
#        define AS_TR_TUCK  LAFAYETTE_LAYER_QUANTUM(KC_ENT)
#    endif

// Default Arsenik configuration
#else
#    define AS_TL_TUCK  LSFT_T(KC_BSPC)
#    define AS_TL_HOME  LT(_num_nav, KC_SPC)
#    define AS_TL_REACH KC_NO
#    define AS_TR_REACH KC_NO
#    define AS_TR_HOME  LT(_num_nav, KC_SPC)
#    define AS_TR_TUCK  LAFAYETTE_LAYER_QUANTUM(KC_ENT)
#endif


// ╭─────────────────────────────────────────────────────────╮
// │                 QMK layouts definitions                 │
// ╰─────────────────────────────────────────────────────────╯

#define XX KO_NO
//  ──────────────────────────< Generic layouts >──────────────────────────

#if defined ARSENIK_LAYOUT_split_3x5_2
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_split_3x5_2(\
             k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b,\
             k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b,\
             k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b,\
                       k51, k52,               k55, k56\
    )

#elif defined ARSENIK_LAYOUT_split_3x5_3
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_split_3x5_3(\
             k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b,\
             k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b,\
             k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b,\
                       k51, k52, k53,     k54, k55, k56\
    )

#elif defined ARSENIK_LAYOUT_split_3x6_3
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_split_3x6_3(\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )

#elif defined ARSENIK_LAYOUT_ortho_4x10
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_4x10(\
             k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b,\
             k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b,\
             k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b,\
             XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,\
    )

#elif defined ARSENIK_LAYOUT_ortho_4x12
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_4x12(\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
        XX,  XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,  XX,\
    )

#elif defined ARSENIK_LAYOUT_ortho_4x16
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_4x16(\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c, XX, XX, XX, XX,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c, XX, XX, XX, XX,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c, XX, XX, XX, XX,\
        XX,  XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,  XX,  XX, XX, XX, XX\
    )

#elif defined ARSENIK_LAYOUT_ortho_5x10
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_4x10(\
             k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b,\
             k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b,\
             k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b,\
             k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b,\
             XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,\
    )

#elif defined ARSENIK_LAYOUT_ortho_5x12
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_5x12(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
        XX,  XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,  XX,\
    )

#elif defined ARSENIK_LAYOUT_ortho_5x14
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,     k54, k55, k56\
    )\
    LAYOUT_ortho_5x14(\
    XX, k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c, XX,\
    XX, k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c, XX,\
    XX, k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c, XX,\
    XX, k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c, XX,\
    XX, XX,  XX,  XX,  k51, k52, k53,     k54, k55, k56, XX,  XX,  XX,  XX,\
    )


//  ─────────────────< Custom keyboard-specific layouts >──────────────

#elif defined ARSENIK_LAYOUT_keebio_iris_default
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,      k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,      k54, k55, k56\
    ) LAYOUT(\
        k11, k12, k13, k14, k15, k16,         k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,         k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,         k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46, XX, XX, k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,         k54, k55, k56\
    )

#else
#    error "Unknown layout"
#endif

#undef XX
