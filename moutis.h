#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#define tap_SemKeys(sk) tap_code16(SemKeys_t[sk][OSIndex])

#define register_SemKey(sk) register_code16(SemKeys_t[sk][OSIndex])

#define unregister_SemKey(sk) unregister_code16(SemKeys_t[sk][OSIndex])

// this borrowed from Thomas Bart
typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows; // index of platforms
    };
} user_config_t;
uint8_t  OSIndex = (uint8_t) 0;  // kludge, 'cause I'm stupid

enum SemKeys {
    SK_KILL,
    SK_UNDO,
    SK_CUT,
    SK_COPY,
    SK_PSTE,
    SK_PSTM,
    SK_SALL,
    SK_CLOZ,
    SK_QUIT,
    SK_FIND,
    SK_FAGN,
    SK_SCAP,
    SK_SCLP,
    SemKeys_COUNT
};

enum SemKeys_OS {
    SKP_Mac,
    SKP_Min,
    SemKeys_OS_COUNT
};

enum my_combos {
    FC_ESC, // ESCape SIMPLE COMBO must be first-used as FALSE for combo_on

    HC_EQL, // = equal
    HC_QUES, // ?
    HC_EXLM, // !
    HC_AT, // @
    HC_UNDS, // _ underscore
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_TIC, // ` tic (not a dead key)
    HC_GRV, // ` grave (dead key)
    HC_TAB,
    QC_TAB,

    HC_Q, // Q is not on the map
    HC_Q2, // Q is not on the map
    HC_Z, // Z is not on the map

    //
    // ACTION COMBOS (ie, not simple combos as above)
    //
    // This group all have actions on press (no hold-delay),
    // may be repeated if held (register_code) or not (tap_code)
    // to be handled in process_combo_event and/or matrix_scan_user_process_combo
    //
    PC_PENT, // <enter> on num
    PC_BSPC, // <bksp> on num
    PC_DEL, // <del> on num
    PC_TAB, // <tab> on num
    HC_TYPE_TION,
    HC_TYPE_JAPAN,

    //
    // DELAYED ACTION COMBOS -- this block must be contiguous
    //
    // no action on press, action (in matrix_scan_user),
    // underlying keys if the hold threshold is not met.
    // may repeat if appropriate. (tap_code vs register_code)
    //
    PC_STAB,  // Shift-<tab>
    PC_TGNM, // TOGGLE NUM LAYER
    PC_DASH, // – on number layer (keypad)
    PC_TILD, // ˜
    PC_ELIP, // …
    HC_ELIP, // …
    PC_COLN, // :
    PC_DEG, //
    PC_NEQL, // ≠
    PC_ENTR, // <enter> on num layer
    PC_SENT,  // Shift-<enter>
    PC_DIV, // ÷
    PC_PLMN, // ±
    PC_PERC, // %
    PC_EURO, // €
    PC_DOLR, // $
    PC_CENT, // ¢
    PC_JYEN, // ¥
    PC_BPND, // £
    PC_LPRN,
    PC_RPRN,
    PC_CLR,
    PC_AC,
    
    MYMACRO,
    HC_TYPE_LM,

    HC_2DQUO, // "|" insertion point between double quotes
    HC_2DBRC, // [|] insertion point between double BRACKETS (japanese quote)

    HC_ENYE, // ~ enye
    HC_ACUT, // ´ acute
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_RING, // ˚ ring

    HC_UM, // Ü
    HC_OM, // Ö
    HC_UK, // Ů
    HC_OK, // O̊
    HC_UV, // Û
    HC_OV, // Ô
    HC_UF, // Ú
    HC_OF, // Ó
    
    // THESE ALL USE SemKeys for platform independence
    FC_KILL, // Force quit
    FC_SCAP, // Screen Capture Selection
    FC_SCLP, // Screen Capture Selection to clipboard
    FC_CAPS, // CAPS LOCK
    HC_CAPS, // CAPS LOCK

    HC_ENT,
    HC_CLOZ,
    HC_QUIT,
    HC_FIND, // Find the selection
    HC_SALL,
    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
    HC_PSTM  // END OF DELAY BLOCK

};

enum my_layers {
  L_HANDSDOWN,
  L_QWERTY,
  L_PUNCT,
  L_FN,
  L_MEDIA_NAV,
  L_LANG_NUM,
  L_DIACR
};

/* enum my_keycodes {
    HD_aumlt = SAFE_RANGE,
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

};

*/

// static uint32_t appmenu_timer = 0;
// static bool appmenu_on = false;

uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions
void matrix_scan_user_process_combo(void);
char OLEDline[32];
