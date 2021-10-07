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
#endif

#include "moutis_casemods.h"

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd.h"
#endif



void matrix_scan_user_process_combo(void);
// this borrowed from Thomas Bart
typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows; // index of platforms
    };
} user_config_t;




enum my_layers {
  L_HANDSDOWN,
  L_QWERTY,
  L_PUNCT,
  L_FN,
  L_MEDIA_NAV,
  L_LANG_NUM,
  L_DIACR
};

 enum my_keycodes {
     SK_KILL = SAFE_RANGE, // SK_KILL must be the first of contiguous block of SKs
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
     SemKeys_COUNT, // end of non-glyph SemKeys

/* Eventually…these should be handled as SemKeys
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
