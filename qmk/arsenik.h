#pragma once

// ╭─────────────────────────────────────────────────────────╮
// │         Syntaxic sugar and generic definitions          │
// ╰─────────────────────────────────────────────────────────╯

// Generic shorthand definitions
#define AG(keycode) RALT(keycode)
#define XX KC_NO
#define __ KC_TRNS

// Lafayette-layer-specific shorthand definitions
#ifdef ARSENIK_ENABLE_LAFAYETTE_LAYER
#    define LAFAYETTE MO(_lafayette)
#    define LAFAYETTE_T(keycode) LT(_lafayette, keycode)
#else
#    define LAFAYETTE KC_RALT
#    define LAFAYETTE_T(keycode) RALT_T(keycode)
#endif

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

// Extra simple config for beginners with bigger keyboards
#if defined ARSENIK_ENABLE_SIMPLE_THUMBS
#    define AS_TL_TUCK  _ALT
#    define AS_TL_HOME  _CTL
#    define AS_TL_REACH _GUI
#    define AS_TR_REACH MO(_num_nav)
#    define AS_TR_HOME  KC_SPC
#    define AS_TR_TUCK  LAFAYETTE
#elif defined ARSENIK_ENABLE_SELENIUM_VARIANT
#    define AS_TL_REACH XX
#    define AS_TR_REACH XX
#    define AS_TL_TUCK  LSFT_T(KC_ESC)
#    define AS_TR_TUCK  LAFAYETTE_T(KC_ENT)
#    if defined SELENIUM_LEFT_HAND_SPACE
#        define AS_TL_HOME  LT(_vim_nav, KC_SPC)
#        define AS_TR_HOME  LT(_num_row, KC_BSPC)
#    else
#        define AS_TL_HOME  LT(_vim_nav, KC_BSPC)
#        define AS_TR_HOME  LT(_num_row, KC_SPC)
#    endif
#else
#    define AS_TL_TUCK LSFT_T(KC_BSPC)
#    define AS_TL_HOME LT(_num_nav, KC_BSPC)
#    define AS_TL_REACH XX
#    define AS_TR_REACH XX
#    define AS_TR_HOME AS_TL_HOME
#    define AS_TR_TUCK LAFAYETTE_T(KC_ENT)
#endif

// ╭─────────────────────────────────────────────────────────╮
// │          Keyboard layout specific declarations          │
// ╰─────────────────────────────────────────────────────────╯

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
#    error "No `ARSENIK_HOST_LAYOUT_*` option was found or recognised"
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
// │                 QMK layouts definitions                 │
// ╰─────────────────────────────────────────────────────────╯

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

//  ─────────────────< Custom keyboard-specific layouts >──────────────

#elif defined ARSENIK_LAYOUT_planck_grid
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,      k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,      k54, k55, k56\
    LAYOUT_planck_grid(\
        k11, k12, k13, k14, k15, k16,     k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,     k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,     k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,     k47, k48, k49, k4a, k4b, k4c,\
        XX,  XX,  XX,  k53, k51,      k55,     k56, k54, XX,  XX,  XX,\
    )

#elif defined ARSENIK_LAYOUT_keebio_iris
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

#elif defined ARSENIK_LAYOUT_ansi_89
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,      k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,      k54, k55, k56\
    ) LAYOUT_ansi_90(\
        KC_MUTE, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,\
        __, k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c, KC_EQL,  KC_BSPC, KC_PGUP,\
        __, k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c, KC_RBRC, KC_BSLS, KC_PGDN,\
        __, k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,          KC_ENT,  KC_HOME,\
        __, k41, k42, k43, k44, k45, k46, k46, k47, k48, k49, k4a, k4b, k4c,    KC_UP,\
        __, KC_LCTL, _GUI,      k51, k52, k53,      k55, k56, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT\
    )

#elif defined ARSENIK_LAYOUT_iso_90
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,      k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,      k54, k55, k56\
    ) LAYOUT_iso_91(\
        KC_MUTE, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,\
        __,          k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c, KC_EQL,  KC_BSPC, KC_PGUP,\
        __,          k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c, KC_RBRC,          KC_PGDN,\
        __,          k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c, KC_NUHS, KC_ENT,  KC_HOME,\
        __, KC_NUBS, k41, k42, k43, k44, k45, k46, k46, k47, k48, k49, k4a, k4b, k4c, KC_UP,\
        __, KC_LCTL, _GUI,          k51, k52, k53,      k55, k56, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT\
    )

#elif defined ARSENIK_LAYOUT_iso_90_angle_mod
#define ARSENIK_LAYOUT(\
        k11, k12, k13, k14, k15, k16,      k17, k18, k19, k1a, k1b, k1c,\
        k21, k22, k23, k24, k25, k26,      k27, k28, k29, k2a, k2b, k2c,\
        k31, k32, k33, k34, k35, k36,      k37, k38, k39, k3a, k3b, k3c,\
        k41, k42, k43, k44, k45, k46,      k47, k48, k49, k4a, k4b, k4c,\
                       k51, k52, k53,      k54, k55, k56\
    ) LAYOUT_iso_91(\
        KC_MUTE, KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, KC_DEL,\
        __, k11, k12, k13, k14, k15, k16,               k17, k18, k19, k1a, k1b, k1c, KC_EQL,  KC_BSPC, KC_PGUP,\
        __, k21, k22, k23, k24, k25, k26,               k27, k28, k29, k2a, k2b, k2c, KC_RBRC,          KC_PGDN,\
        __, k31, k32, k33, k34, k35, k36,               k37, k38, k39, k3a, k3b, k3c, KC_NUHS, KC_ENT,  KC_HOME,\
        __, k41, k42, k43, k44, k45, k46, KC_NUBS, k46, k47, k48, k49, k4a, k4b, k4c, KC_UP,\
        __, KC_LCTL, _GUI,      k51, k52, k53,          k55, k56, KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT\
    )

#else
#    error "Arsenik: Unknown layout"
#endif
