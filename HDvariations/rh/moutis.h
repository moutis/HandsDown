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


#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#include "moutis_casemods.h"

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd_rh.h"
#endif


void matrix_scan_user_process_combo(void);

#define DQUO_S  KC_RBRC // ]
#define DQUO_A  A(S(KC_BSLS)) // »
#define DQUO_SA A(S(KC_4)) // ›
#define SQUO_S  KC_LBRC // [
#define SQUO_A  A(KC_BSLS) // «
#define SQUO_SA A(S(KC_3)) // ‹

typedef union {
    uint32_t raw;
    struct {
        uint8_t LBRC_key;  // keycode for "["
        uint8_t RBRC_key;  // keycode for "]"
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)?
        bool AdaptiveKeys; // Adaptive Keys On?
    };
} user_config_t;


enum my_layers {  // must be difined before semantickeys.h
// enum my_layers for layout layers for HD Neu family
//    L_HDNUE,     // N             RSNT AEIH (same home row as Rhodium)
      L_HDBRONZE,  // B BR (Neu-hx) RSNT AECI (same home row as Platinum)
//    L_HDSILVER,  // S Ag (Neu-nx) RSHT AECI
//    L_HDPLATINUM,// P Pl (Neu-lx) RSNT AECI (same home row as Bronze)
//    L_HDGOLD,    // G Au (Neu-tx) RSND AEIH
      L_HDTITANIUM,// T Ti (Neu-rx) CSNT AEIH
//    L_HDRHODIUM, // R Rh (Neu-cx) RSNT AEIH (same home row as Neu)
//    L_QWERTY,    //
      L_PUNCT,     // 2
      L_FN_NUM,    // 3
      L_NUMPAD,    // 4
      L_NAV,       // 5
//    L_SYMBOLS,   //  diacritics…maybe to be handled by semantickeys?
      L_MEDIA_KBD  // 6
};

enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,     // uses ANSI_US_EXTENDED layout
    OS_Win,
    OS_count
};

#include "moutis_semantickeys.h"

#define register_linger_key(kc) {register_code16(kc);linger_key = kc;linger_timer = state_reset_timer = timer_read();}
#define unregister_linger_key() {unregister_code16(linger_key);linger_key = 0;}
/*
#define register_linger_key(kc) register_code16(kc);
#define unregister_linger_key(kc) unregister_code16(kc);
*/

#ifdef JP_MODE_ENABLE
bool IS_ENGLISH_MODE;
//#define IS_ENGLISH_MODE (myKC_C == KC_C)
#define TOGGLE_ENGLISH_MODE {IS_ENGLISH_MODE ^= true;}
#endif
