#pragma once

/**
 * Sane defaults for homerow modifiers
 */
#define TAPPING_TERM 200
#define TAPPING_FORCE_HOLD
#undef  PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

/**
 * Sane defaults for combos
 */
#define COMBO_TERM 30

/**
 * Underglow configuration
 */
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_TWINKLE
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#endif

/**
 * Mouse Keys Modes
 *  - Accelerated: linear acceleration until the max speed is reached (default)
 *  - Kinetic:  quadradic acceleration until the max speed is reached
 *  - Inertia:  quadradic acceleration, and deceleration after key release
 *  - Constant: constant speeds
 *  - Combined: accelerated by default, constant speed when KC_ACLx is held
 * https://docs.qmk.fm/#/feature_mouse_keys
 */

/**
 * Accelerated Mode, default QMK settings
// mouse cursor
#define MOUSEKEY_DELAY              10
#define MOUSEKEY_INTERVAL           20
#define MOUSEKEY_MOVE_DELTA         8
#define MOUSEKEY_MAX_SPEED          10
#define MOUSEKEY_TIME_TO_MAX        30
// mouse wheel
#define MOUSEKEY_WHEEL_DELAY        10
#define MOUSEKEY_WHEEL_INTERVAL     80
#define MOUSEKEY_WHEEL_MAX_SPEED    8
#define MOUSEKEY_WHEEL_TIME_TO_MAX  30
 */

/**
 * Accelerated Mode, default Oryx settings
 * https://github.com/manna-harbour/miryoku_qmk/blob/bdb9fd81e8aa2afb3882f7c0f6ae2d3ba448ac93/users/manna-harbour_miryoku/config.h#L23-L33
 */
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_INTERVAL     16 // matches 60 FPS
#define MOUSEKEY_MAX_SPEED    6
#define MOUSEKEY_TIME_TO_MAX  64
#define MOUSEKEY_WHEEL_DELAY  0

/**
 * Kinetic Mode, default QMK settings
#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY                        5
#define MOUSEKEY_INTERVAL                     10
#define MOUSEKEY_MOVE_DELTA                   16
#define MOUSEKEY_INITIAL_SPEED                100
#define MOUSEKEY_BASE_SPEED                   5000
#define MOUSEKEY_DECELERATED_SPEED            400
#define MOUSEKEY_ACCELERATED_SPEED            3000
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS      16
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS         32
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS  48
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS  8
 */

/**
 * Inertia Mode, default QMK settings
#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY        150
#define MOUSEKEY_INTERVAL     16 // matches 60 FPS
#define MOUSEKEY_MAX_SPEED    32
#define MOUSEKEY_TIME_TO_MAX  32
#define MOUSEKEY_FRICTION     24
#define MOUSEKEY_MOVE_DELTA   1
 */

/**
 * Inertia Mode, custom settings
#define MOUSEKEY_INERTIA
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_INTERVAL     16 // matches 60 FPS
#define MOUSEKEY_MAX_SPEED    24
#define MOUSEKEY_TIME_TO_MAX  24
#define MOUSEKEY_FRICTION     24
#define MOUSEKEY_MOVE_DELTA   1
 */

/**
 * Constant Mode
 * The settings below enable constant speed mode, which can be:
 *  - momentary:     (hold) KC_ACL0 < KC_ACL1 < unmodified < KC_ACL2
 *  - tap-to-select: (tap)  KC_ACL0 < KC_ACL1 < KC_ACL2
#define MK_3_SPEED         // enables constant speed modes
#define MK_MOMENTARY_ACCEL // enables momentary speed mode
 */

/**
 * Combined Mode
 * Adjusts the Accelerated mode top speed when KC_ACLx is held:
 *  - KC_ACL0: minimal speed
 *  - KC_ACL1: half the maximal (user defined) speed
 *  - KC_ACL2: maximal (computer defined) speed
#define MK_COMBINED
 */
