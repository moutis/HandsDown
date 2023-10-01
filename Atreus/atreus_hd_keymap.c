#include QMK_KEYBOARD_H


#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[L_QWERTY] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUM,KC_G), LT(L_FUN,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
        KC_Z, KC_X, KC_C, KC_V, KC_B, TT(L_NUM), LT(L_FUN,KC_MPLY), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_LEFT, KC_RGHT, KC_APP, LT(L_CFG,KC_MUTE), LT(L_FUN,KC_BSPC), LT(L_NAV,KC_DEL), LT(L_CFG,KC_MUTE), LT(L_SYM,KC_SPC), LT(L_NAV,KC_ENT), LT(L_CFG,KC_MPLY), KC_UP, KC_DOWN),

    [L_HD] = LAYOUT(
        HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,                 HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
        HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,                 HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
        HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, HD_LBA, HD_RBA, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
      KC_LEFT, KC_RGHT, HD_LH3, HD_LH2, HD_LH1, HD_LH0, HD_RH0, HD_RH1, HD_RH2, HD_RH3, KC_UP,  KC_DOWN),

/*
    [L_SYM] = LAYOUT(
        KC_Z, KC_Q, RALT(KC_5), LALT(KC_7), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y),
        KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, RSA(KC_5), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_PSLS),
        KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), ______, ______, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC,
        ______, ______, ______, SK_DELWDL, SK_DELWDR, ______, LSA(KC_8), ______, ______, ______, ______, ______),
*/
    [L_SYM] = LAYOUT(
        LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0,                 LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4,
        LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0,                 LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4,
        LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0, LS_LBA, LS_RBA, LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4,
        ______, ______, LS_LH3, LS_LH2, LS_LH1, LS_LH0, LS_RH0, LS_RH1, LS_RH2, LS_RH3, ______, ______),

/*	[L_FUN] = LAYOUT(
        KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_BSLS,
        LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_SCLN, RSFT_T(KC_1), RGUI_T(KC_2), RALT_T(KC_3), RCTL_T(KC_SLSH), KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_PAUS, KC_TAB, KC_MINS, KC_4, KC_5, KC_6, KC_EQL, KC_PSCR, KC_LSCR, ______, KC_BSPC, KC_ENT, ______, KC_DEL, KC_0, KC_DOT, KC_COMM, ______, ______),
*/
    [L_FUN] = LAYOUT(
        LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0,                 LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4,
        LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0,                 LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4,
        LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0, LF_LBA, LF_RBA, LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4,
        ______, ______, LF_LH3, LF_LH2, LF_LH1, LF_LH0, LF_RH0, LF_RH1, LF_RH2, LF_RH3, ______, ______),

/*
 [L_NUM] = LAYOUT(
    KC_NUM,     KC_PGDN, KC_UP,   KC_PGUP, KC_TAB,              KC_PSLS,    KC_P7,         KC_P8,         KC_P9,         KC_PMNS,
    SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT,          KC_PAST,    RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), RCTL_T(KC_PPLS),
    SK_UNDO,    SK_CUT,  SK_COPY, SK_PSTE, KC_SPC, KC_ESC,  KC_ESC, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL,
        ______, ______, ______, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), KC_DEL, KC_C, KC_P0, KC_PDOT, ______, ______, ______),
*/
    [L_NUM] = LAYOUT(
        LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0,                 LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4,
        LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0,                 LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4,
        LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0, LN_LBA, LN_RBA, LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4,
        ______, ______, LN_LH3, LN_LH2, LN_LH1, LN_LH0, LN_RH0, LN_RH1, LN_RH2, LN_RH3, ______, ______),
/*
    [L_NAV] = LAYOUT(
        SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV,
        KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT,
        SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_ESC, KC_TAB, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT,
        SK_HISTPRV, SK_HISTNXT, ______, ______, ______, ______, ______, SK_HISTPRV, SK_HISTNXT, SK_ZOOMRST, SK_ZOOMOUT, SK_ZOOMIN),
*/
    [L_NAV] = LAYOUT(
        LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,                 LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,
        LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,                 LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,
        LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0, LV_LBA, LV_RBA, LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,
SK_HISTPRV, SK_HISTNXT, LV_LH3, LV_LH2, LV_LH1, LV_LH0, LV_RH0, LV_RH1, LV_RH2, LV_RH3, SK_ZOOMOUT, SK_ZOOMIN),

/*
	[L_CFG] = LAYOUT(
        QK_RBT, CG_SWAP, CG_NORM, EE_CLR, SK_KILL, LCA(KC_DEL), KC_NUM, KC_EJCT, __no__, SK_ZOOMRST,
        HD_AdaptKeyToggle, HD_L_QWERTY, HD_L_ALPHA, KC_VOLU, KC_BRIU, __no__, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT,
        QK_BOOT, AG_SWAP, AG_NORM, KC_VOLD, KC_BRID, __no__, __no__, __no__, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN,
        __no__, __no__, TG(L_NUM), __no__, __no__, __no__, __no__, __no__, __no__, __no__, __no__, __no__)
*/
    [L_CFG] = LAYOUT(
        LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,                 LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,
        LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,                 LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,
        LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0, LC_LBA, LC_RBA, LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,
        ______, ______, LC_LH3, LC_LH2, LC_LH1, LC_LH0, LC_RH0, LC_RH1, LC_RH2, LC_RH3, ______, ______),
};

