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

//
// which HD alpha variation are we using?
//
//
// nu = neu (no thumb alpha)    * does not use thumb
// au = gold (T on thumb)       * most inward rolling
// bz = bronze (H on thumb)     * lightest thumb use w/H-digraph combos
// cr = chromium (C on thumb)   * RSNT typically doesn't use H-digraph combos
// cs = cesium (C on thumb)     * lowest scissors, – lowest thumb w/o H-digraph combos
// pm = promethium (R on thumb) * typically doesn't use H-digraph combos
// rh = rhodium (R on thumb)    * typically doesn't use H-digraph combos
// vf = vibranium (R on thumb, f in lower left, b on right) - "canonical"
// vv = vibranium (R on thumb, v in lower left, f on right) - lowest SFBs
// vx = vibranium (R on thumb, x in lower left, f on right) - better pinky balancing
// vb = vibranium (R on thumb, b in lower left, f on right) - more rolling w/adaptives
// mi = mithril (R on thumb)
// xr = weird test-bed (R on thumb)

#define HD_CONFIG "handsdown/vf-config.h"

//
// HD_CONFIG defines all variation dependent constants/files/keycodes, etc.
// that will be used in the respective keymap for each keyboard
//
//
#include HD_CONFIG // definitions for the Alpha layer and mnemonic combos
//
// definitions for all the other layers not dependent on the alpha layout.
#include "moutis_layers.h"

#define LINGER_TIME TAPPING_TERM * 1.2 // how long to hold before a time-depentant behavior begins
// how long to leave a state active before resetting like APPMENU or CAPSWORD
#define STATE_RESET_TIME LINGER_TIME * 3


// Adaptive (or MAGIC) keys are like a QMK Leader Key, but after (Adaptive Trailer)
#define ADAPTIVE_ENABLE
#define ADAPT_SHIFT KC_COMM // keycode to precede alpha for one-shot shift (leader)
#define ADAPT_H // eliminate SFBs AU/UA;EO/OE;LN;MN;NN using H (instead of ')
#define ADAPT_AE_AU // Use AE->AU (instead of AH->AU, AH is somewhat common)
//#define FR_ADAPTIVES // eliminate 'h SFB for French
//#define DE_ADAPTIVES // alternate AU SFB treatment for German (same as ADAPT_AE_AU)
#define HD_MAGIC HD_HASH // generic MAGIC_KEY (I use for text macros)
//#define HD_MAGIC_A KC_ENT // MAGIC_KEY dependent on alpha (vowel hand?)
#define HD_MAGIC_B KC_BSPC // MAGIC_KEY dependent on alpha (consonant hand?)

#ifdef COMBO_HOLD
    #undef ADAPTIVE_TERM
    #define ADAPTIVE_TERM COMBO_HOLD * 1.35  // use COMBO_HOLD time as a standard threshold (same recation time)
#else
    #define ADAPTIVE_TERM (TAPPING_TERM/4) // rolling threshold
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
    OS_Lux,     // Linux (Gnome?/KDE?/Boox?)
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
