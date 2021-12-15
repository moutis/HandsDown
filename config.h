#pragma once

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// This enables Link Time Optimization, saving a significant amount of space. Because the Macro and Function features are incompatible with Link Time Optimization, disable those features in config.h:

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define EXTRA_SHORT_COMBOS

// The Leader key allows to flexibly assign macros to key sequences.
#ifdef LEADER_ENABLE
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 750
    #define LEADER_NO_TIMEOUT
#endif


// I dont' know why these must be here, not in user space...
// but it won't compile otherwise
//
#define TAPPING_TOGGLE 2

#define TAPPING_TERM 170 // TAP VS HOLD timing in milliseconds

// Pick good defaults for enabling homerow modifiers
#define TAP_CODE_DELAY 5
#define TAP_HOLD_CAPS_DELAY 0
#define PERMISSIVE_HOLD
//#define BILATERAL_COMBINATIONS
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef COMBO_ENABLE
    #ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif

    #define COMBO_ALLOW_ACTION_KEYS
    #define COMBO_STRICT_TIMER
    #define EXTRA_SHORT_COMBOS
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

#define LINGER_TIME TAPPING_TERM * 1.2 // how long to hold before a time-depentant behavior begins
// how long to leave a state active before resetting like APPMENU or SHIFTWORD
#define STATE_RESET_TIME LINGER_TIME * 4

