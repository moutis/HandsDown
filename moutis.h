#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

#include "moutis_semantics.h"

#include "moutis_casemods.h"

#ifdef COMBO_ENABLE
#include "moutis_COMBO_hd.h"
#endif


#define ADAPTIVE_TERM TAPPING_TERM/3 // default time between keystrokes allowed for adaptives
#ifdef COMBO_HOLD
    #undef ADAPTIVE_TERM
    #define ADAPTIVE_TERM COMBO_HOLD  // use COMBO_HOLD time as a standard threshold (same recation time)
#endif

#define LINGER_TIME TAPPING_TERM * 2 // how long to hold before a time-depentant behavior begins
#define STATE_RESET_TIME LINGER_TIME * 2 // how long to leave a state active before resetting

void matrix_scan_user_process_combo(void);
// this borrowed from Thomas Bart
typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows; // index of platforms
    };
} user_config_t;

uint8_t  OSIndex = (uint8_t) 0;  // kludge, 'cause I'm stupid




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
