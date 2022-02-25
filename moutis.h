#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#ifdef EE_HANDS
    #include "split_util.h"
#endif

#ifdef COMBO_ENABLE
    #include "process_combo.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;

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

#include "moutis_casemods.h"

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd.h"
#endif


enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,
    OS_Win,
    OS_count
};

void matrix_scan_user_process_combo(void);

typedef union {
    uint32_t raw;
    struct {
        uint8_t LBRC_key;  // keycode for "["
        uint8_t RBRC_key;  // keycode for "]"
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)?
        bool AdaptiveKeys; // Adaptive Keys On?
    };
} user_config_t;




enum my_layers {
    L_HDBRONZE,
//    L_HDSILVER,
//    L_HDPLATINUM,
    L_HDGOLD,
    L_QWERTY, //
    L_PUNCT,
    L_FN_NUM,
    L_NUMPAD,
    L_NAV,
//    L_SYMBOLS,
    L_MEDIA_KBD
};

 enum my_keycodes {
     SK_KILL = SAFE_RANGE, // SK_KILL must be the first of contiguous block of SKs
     SK_HENK,
     SK_MHEN,
     SK_UNDO, // undo
     SK_CUT, // cut
     SK_COPY, // copy
     SK_PSTE, // paste
     SK_PSTM, // paste_match
     SK_SALL, // select all
     SK_CLOZ, // close
     SK_QUIT, // quit
     SK_FIND, // find
     SK_FAGN, // find again
     SK_SCAP, // screen capture to clipboard
     SK_SCLP, // selection capture to clipboard
     SK_DELWDL, // Delete word left of cursor
     SK_DELWDR, // Delete word right of cursor
     
     SK_WORDPRV, // WORD LEFT
     SK_WORDNXT, // WORD RIGHT
     SK_DOCBEG, // Go to start of document
     SK_DOCEND, // Go to end of document
     SK_LINEBEG, // Go to beg of line
     SK_LINEEND, // Go to end of line
     SK_PARAPRV, // Go to previous paragraph
     SK_PARANXT, // Go to next paragraph
     SK_HISTPRV, // BROWSER BACK
     SK_HISTNXT, // BROWSER FWD
     SK_ZOOMIN, // ZOOM IN
     SK_ZOOMOUT, // ZOOM OUT
     SK_ZOOMRST, // ZOOM RESET
     SK_SECT, // §
     SK_ENYE, // ñ/Ñ ENYE
     SK_SQUL, // ’ ** Left single quote UNICODE?
     SK_SQUR, // ’ ** Right single quote UNICODE?
     SK_SDQL, // ’ ** Left double quote UNICODE?
     SK_SDQR, // ’ ** Right double quote UNICODE?
     SemKeys_COUNT, // end of non-glyph SemKeys
     HD_AdaptKeyToggle,
     HD_L_Bronze,  // KC to switch default layout
//     HD_L_Silver,
//     HD_L_Platinum,
     HD_L_Gold,
//     HD_L_Neu,
     HD_L_QWERTY,



/* Eventually…these should be handled as SemKeys?
    HD_aumlt,
    HD_amacr,
    HD_aacut,
    HD_acrcm,
    HD_agrav,

    HD_eumlt,
    HD_emacr,
    HD_eacut,
    HD_ecrcm,
    HD_egrav,

    HD_iumlt,
    HD_imacr,
    HD_iacut,
    HD_icrcm,
    HD_igrav,

    HD_oumlt,
    HD_omacr,
    HD_oacut,
    HD_ocrcm,
    HD_ograv,

    HD_uumlt,
    HD_umacr,
    HD_uacut,
    HD_ucrcm,
    HD_ugrav
*/
};

#include "moutis_semantickeys.h"

#define register_linger_key(kc) {register_code16(kc);linger_key = kc;linger_timer = state_reset_timer = timer_read();}
#define unregister_linger_key() {unregister_code16(linger_key);linger_key = 0;}
/*
#define register_linger_key(kc) register_code16(kc);
#define unregister_linger_key(kc) unregister_code16(kc);
*/

