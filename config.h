#pragma once

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// This enables Link Time Optimization, saving a significant amount of space. Because the Macro and Function features are incompatible with Link Time Optimization, disable those features in config.h:

// disable a bunch of things to save space
#ifndef NO_ACTION_MACRO
#define NO_ACTION_MACRO
#endif
#ifndef NO_ACTION_FUNCTION
#define NO_ACTION_FUNCTION
#endif
#ifndef NO_ACTION_ONESHOT
#define NO_ACTION_ONESHOT
#endif
#ifndef NO_MUSIC_MODE
#define NO_MUSIC_MODE
#endif
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define TAPPING_TOGGLE 2
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 170 // Mod TAP VS HOLD timing in milliseconds
#endif

// Pick good defaults for enabling homerow modifiers
//#define HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT

#ifdef TAP_CODE_DELAY
#undef TAP_CODE_DELAY
#endif
#define TAP_CODE_DELAY 20 // time between register/unregister (some keycodes go missing/out of sequence)
#define TAP_HOLD_CAPS_DELAY 180 // for Mac

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
// these COMBO_TERM have dilicate interactions with ADAPTIVE_TERM below.
    #define COMBO_TERM (TAPPING_TERM/4) // time to get all combo keys down
    #define COMBO_HOLD (TAPPING_TERM) // time to hold to trigger delayed combo
#endif

#define EN_HDIGRAPH_COMBOS // English H-Digraph combos (Th,Ch,Wh,Sh,Gh,Ph,Sch)
#define EN_PRONOUN_COMBOS // English First Person pronoun combos (I, I'm, I've I'd I'll etc) (184 bytes on AVR)
#define EN_PRONOUN_COMBOS_ALL  // combos for you('ve), We('ve), They('ve) etc. (616 bytes on AVR)
#define EN_W_PRONOUNS
#define JP_MODE_ENABLE  // Japanese mode features switch output for Japanese input (552 bytes on AVR)
#define JP_YOUON_COMBOS  // must have JP_MODE_ENABLE. min contracted sounds as combos (746 bytes on AVR)
#define JP_YOUON_COMBOS_ALL  // must have JP_YOUON_COMBOS. all contracted sounds as combos (862 bytes on AVR)

