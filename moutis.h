#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#ifdef EE_HANDS
    #include "split_util.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP

    #ifdef RGBLIGHT_ANIMATIONS
        #undef RGBLIGHT_ANIMATIONS
    #endif
    //#define RGBLIGHT_EFFECT_BREATHING
    //#define RGBLIGHT_EFFECT_TWINKLE
    //#define RGBLIGHT_SLEEP
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_MODE_ALTERNATING

    #ifdef RGBLIGHT_HUE_STEP
        #undef RGBLIGHT_HUE_STEP
    #endif
    #define RGBLIGHT_HUE_STEP 4

    #ifdef RGBLIGHT_SAT_STEP
        #undef RGBLIGHT_SAT_STEP
    #endif
    #define RGBLIGHT_SAT_STEP 4

    #ifdef RGBLIGHT_VAL_STEP
        #undef RGBLIGHT_VAL_STEP
    #endif
    #define RGBLIGHT_VAL_STEP 4
#endif

//
// which HD alpha variation are we using?
//
// defines all variation dependent constants/files/keycodes, etc.
// they will be used in the respective keymap for each keyboard

#include "personalizedmacros.h"


#ifdef THUMB_SHIFT
#include "handsdown/vx-config.ts.h" // definitions for the Alpha layer and mnemonic combos
#include "moutis_layers.ts.h" // definitions for all the other layers
#else
#include "handsdown/pm-config.h" // definitions for the Alpha layer and mnemonic combos
#include "moutis_layers.h" // definitions for all the other layers
#endif



#define LINGER_TIME TAPPING_TERM * 1.2 // how long to hold before a time-depentant behavior begins
// how long to leave a state active before resetting like APPMENU or CAPSWORD
#define STATE_RESET_TIME LINGER_TIME * 3

//#define THUMB_SHIFT // use the thumb shift variant instead of index shift


#define ADAPTIVE_ENABLE

#define ADAPT_VOWEL_H // eliminate vowel SFBs (AU/UA;EO/OE) using vH instead of v'
#define ADAPT_AE_AU // Use AE->AU (instead of AH->AU)
//#define FR_ADAPTIVES // eliminate 'h SFB for French
//#define DE_ADAPTIVES // alternate AU SFB treatment for German (forces ADAPT_AE_AU)
#define ADAPTIVE_TRAILER KC_HASH // Like QMK Leader Key, but trails, and adaptive
#define ADAPT_SHIFT KC_COMM // keycode to precede alpha for one-shot shift (leader)

#ifdef COMBO_HOLD
    #undef ADAPTIVE_TERM
    #define ADAPTIVE_TERM COMBO_HOLD * 1.35  // use COMBO_HOLD time as a standard threshold (same recation time)
#else
    #define ADAPTIVE_TERM (TAPPING_TERM/4) // rolling threshold
#endif


//#define THUMB_REPEATER
#ifdef THUMB_REPEATER
#define HD_REPEATER_A HD_BSPC
#define HD_REPEATER_B KC_ENT
#endif


#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#include "moutis_casemods.h"

#include "moutis_combo.h"  //

//
// These COULD be made variation/platform dependent, to allow
// them to adapt to geometry differences. Ex.
// most NEU variations have " ' on ring/pinky
// but Bronze/Silver heve ' " (inverted)
// since [ ] and « » are SHIFT/ALT of " '
// the paired brackets would be inverted.
// Perhaps simply redefining these in the xx-config.h
// to override these defs would be the right approach?
//
#define DQUO_S  KC_RBRC // ] (via Double quote shifted)
#define SQUO_S  KC_LBRC // [ (via Single quote shifted)
#define JRQU KC_RBRC //  「 (via " in Japanese mode)
#define JLQU KC_LBRC //  」 (via ' in Japanese mode)


typedef union {
    uint32_t raw;
    struct {
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
        bool AdaptiveKeys; // Adaptive Keys On? (and advanced combos)
    };
} user_config_t;


// enum my_layers for layout layers
enum my_layers {// must be difined before semantickeys.h
    L_QWERTY,   // 0 - QWERTY compatibility layer
    L_HD,       // 1 - Hands Down Alpha layer
    L_SYM,      // 2 - symbols, punctuation, off-map alphas
    L_FUN,      // 3 - function & number rows
    L_NUM,      // 4 - numpad (right); navpad (left)
    L_NAV,      // 5 - nav pad (right); meta keys (left)
    L_CFG,      // 6 - Media/Consumer controls; Keyboard settings
    L_count
};

enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,     // Mac with ANSI_US_EXTENDED layout
//    OS_iOS,     // iOS?
    OS_Win,     // Win with default English/ANSI layout?
    OS_Lux,     // Linux (Gnome?/KDE?)
//    OS_And,     // Android (flavors?)
    OS_count
};

#include "moutis_semantickeys.h"

#define tap_HDkey(kc) {is_SemKey(kc) ? tap_SemKey(kc) : tap_code16(kc);}
#define register_HDkey(kc) {is_SemKey(kc) ? register_SemKey(kc) : register_code16(kc);}
#define unregister_HDkey(kc) {is_SemKey(kc) ? unregister_SemKey(kc) : unregister_code16(kc);}

#define register_linger_key(kc) {register_HDkey(kc);linger_key = kc;linger_timer = timer_read();}
#define unregister_linger_key() {unregister_HDkey(linger_key) ;linger_key = 0;}


void matrix_scan_user_process_combo(void);
