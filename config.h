#pragma once


// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate

// The Leader key allows to flexibly assign macros to key sequences.
#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 750
    #define LEADER_NO_TIMEOUT
#endif

#ifdef RGBLIGHT_ENABLE

#ifdef RGBLIGHT_ANIMATIONS
    #undef RGBLIGHT_ANIMATIONS
#endif
#define RGBLIGHT_ANIMATIONS

#ifdef RGBLIGHT_HUE_STEP
    #undef RGBLIGHT_HUE_STEP
#endif
#define RGBLIGHT_HUE_STEP 8

#ifdef RGBLIGHT_SAT_STEP
    #undef RGBLIGHT_SAT_STEP
#endif
#define RGBLIGHT_SAT_STEP 8

#ifdef RGBLIGHT_VAL_STEP
    #undef RGBLIGHT_VAL_STEP
#endif
#define RGBLIGHT_VAL_STEP 8

#ifdef RGBLIGHT_SLEEP
    #undef RGBLIGHT_SLEEP
#endif
#define RGBLIGHT_SLEEP

#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 9000
#endif
 
// I dont' know why these must be here, not in user space...
// but it won't compile otherwise
//
#define TAPPING_TOGGLE 2

#define TAPPING_TERM 170 // TAP VS HOLD timing in milliseconds

// Pick good defaults for enabling homerow modifiers
// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 5
#define TAP_HOLD_CAPS_DELAY 0
#define PERMISSIVE_HOLD
#define BILATERAL_COMBINATIONS
#define IGNORE_MOD_TAP_INTERRUPT

#define ADAPTIVE_TERM TAPPING_TERM/2 // default time between keystrokes allowed for adaptives
#ifdef COMBO_ENABLE
    #ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif

    #define COMBO_ALLOW_ACTION_KEYS
    #define COMBO_STRICT_TIMER

    #ifdef COMBO_TERM
        #undef COMBO_TERM
    #endif
    #define COMBO_TERM (TAPPING_TERM/5) // time to get all combo keys down
    #define COMBO_HOLD (COMBO_TERM*4) // time to hold to trigger delayed combo
#endif

#ifdef COMBO_HOLD
    #undef ADAPTIVE_TERM
    #define ADAPTIVE_TERM COMBO_HOLD  // use COMBO_HOLD time as a standard threshold (same recation time)
#endif

#define LINGER_TIME TAPPING_TERM * 1.3 // how long to hold before a time-depentant behavior begins
#define STATE_RESET_TIME LINGER_TIME * 4 // how long to leave a state active before resetting

