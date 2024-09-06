#undef PERMISSIVE_HOLD
// QMK’s `PERMISSIVE_HOLD` can be some extra comfort for experienced people,
// but can also be an absolute pain for beginners, especially if you are trying
// to learn home-row-mods, which is why we chose to deactivate this option by
// default.

// QMK considers tap-hold actions as "tap by default" when another key is
// pressed during the "quantic period", but some tap-holds should ideally be
// "hold by default" to avoid this delay.
//
// This option allows us to have a fine-grain controll over this behaviour.
//
// Arsenik provides a good default implementation of the required function,
// though you may override it in your `keymap.c` file
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


// Tap-hold actions (like home-row-mods) may be hard to use as a beginner, as
// it is common to hold those keys for too long and accidentally use the
// `hold-action`.
//
// This option allows us to have a fine-grain controll over the `TAPPING_TERM`
// for each quantum key, allowing a longer delay on those sensitive keys
// without slowing down the safer ones.
//
// Arsenik provides a good default implementation of the required function,
// though you may override it in your `keymap.c` file
#define TAPPING_TERM_PER_KEY

// This line gets automatically filled in by the install script, but the
// underlying layout may not exist, and keyboard specific layout may have other
// variants you might want to check out.
#define ARSENIK_PLACEHOLDER_LAYOUT


// This is the delay used by Arsenik for sensitive tap-holds, which include
// home-row-mods and mod-taps using the spacebar
#define ARSENIK_HRM_TAPPING_TERM 300

// Below are a bunch of options to quickly customize the Arsenik keymap. You
// can pick and choose them by (un)commenting the different `#define`
// declarations.

#define ARSENIK_ENABLE_LAFAYETTE_LAYER
// When active, gives access to the programming symbols layer used by layouts
// like Ergo‑L and all of the "Lafayette" familly of layouts (it’s their AltGr
// layer). The definition of this layer depends on the keyboard layout you are
// using, so make sure to select the correct one in the list bellow.
//
// When inactive, this layer is discarded and replaced by AltGr.

// #define ARSENIK_ENABLE_HRM
// When active, adds a Meta, Ctrl and Alt home-row-mod on respectively s/l,
// d/k or f/j on a Qwerty keyboard. Those home-row-mods stay on those exact
// keys regardless of the layout being used, meaning they would be on r/i, s/e
// and t/n on a Colemak keyboard.

// #define ARSENIK_MAC_MODIFIERS
// Swaps around home-row-mods from Meta, Ctrl, Alt to Alt, Meta, Ctrl, as it
// may make more sense on a Mac, like to keep common shortcuts accessible with
// the Ergo‑L layout, for instance
//
// (Requires `ARSENIK_ENABLE_HRM`)

// #define ARSENIK_DISABLE_THUMB_TAP_HOLDS
// When active, uses an extra simple config without any tap-holds on the thumb
// keys. It may be a *lot* simpler to use, but requieres a keyboard with at
// least 6 thumb keys (so 3 per thumb) instead of 3 thumb keys total and is
// overall a lot less efficient (especially when combining modifiers).
//
// Base thumb config: LSFT_T(KC_ËSC)  LT(_num_nav, KC_SPC)  RALT_T(KC_ENT)
// When it’s active: KC_ALT  KC_CTL  KC_GUI     MO(_num_nav)  KC_SPC  KC_RALT
// (RALT becomes the `_lafayette` layer if `ARSENIK_ENABLE_LAFAYETTE_LAYER` is active)
//
// (Prevents using `ARSENIK_ENABLE_SELENIUM_VARIANT`)

// #define ARSENIK_ENABLE_SELENIUM_VARIANT
// Most ergonomic keyboards have at least 4 comfortable thumb keys keys (so 2
// per thumb). Selenium is a variant of Arsenik made to fit on 34 keys keyboard
// to take advantage of the extra thumb key. It does it by splitting the numbers
// and navigation layers to 2 distict layers, and adds an escape key.
//
// Base thumb config: LSFT_T(KC_ËSC)  LT(_num_nav, KC_SPC)  RALT_T(KC_ENT)
// Selenium: LSFT_T(KC_ESC) LT(_num_row, KC_BSPC) LT(_vim_nav, KC_SPC) RALT_T(KC_ENT)

// #define SELENIUM_LEFT_HAND_SPACE
// Swaps around the backspace and space keycodes with Selenium, but not the
// layers when those keys are held.
//
// (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)

// #define SELENIUM_LEFT_HAND_NAV
// Swaps around the navigation and numbers layers with Selenium, but not space
// and backspace when those keys are tapped.
//
// (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)

// #define SELENIUM_SWAP_SAME_THUMB_HOLD_ACTION
// Swaps around the hold actions of the keys from the same thumb as to place
// Shift and Lafayette / AltGr on the home position, which may be more
// comfortable but less intuitive (espactially for Lafayette / AltGr).
//
// (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)

// #define SELENIUM_RESTORE_SPACE
// Having Space accessible to one thumb may create some problems, especially
// when trying to type Shift + Space or Lafayette / AltGr + Space (depending if
// your space key is on your left or right hand). When active, it temporarely
// replaces the homming thumb key with Space on tap if the modifier from the
// same hand as the "real" Space key is held
//
// (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)


// Lists of layouts supported by Arsenik. Some parts of the config is dependent
// on keyboard layout used on your computer. If they don’t match up some
// characters may not be correctly placed or missing entirely. If multiple
// options are toggled at the same time, the first one is chosen.
#define ARSENIK_HOST_LAYOUT_QWERTY
// #define ARSENIK_HOST_LAYOUT_AZERTY
// #define ARSENIK_HOST_LAYOUT_ERGOL
// #define ARSENIK_HOST_LAYOUT_BEPO
// #define ARSENIK_HOST_LAYOUT_DVORAK
// #define ARSENIK_HOST_LAYOUT_COLEMAK
// #define ARSENIK_HOST_LAYOUT_WORKMAN
