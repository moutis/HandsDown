#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

/*      Candybar Ortho is 17x4 68 key layout (outside frame are unused)
 *     ,------------------------------------------------------------------------------------------------------------------------.
 * LT5 |  LT4  |  LT3  |  LT2  |  LT1  |  LT0  |  LTA  |  RTA  | P/ | P7 | P8 | P9 | P- |  RT0  |  RT1  |  RT2  |  RT3  |  RT4  | RT5
 *     |-------+-------+-------+-------+-------+-------+-------+----+----+----+----+----+-------+-------+-------+-------+-------|
 * LM5 |  LM4  |  LM3  |  LM2  |  LM1  |  LM0  | m-up  | m-dn  | P* | P4 | P5 | P6 | P+ |  RM0  |  RM1  |  RM2  |  RM3  |  RM4  | RM5
 *     |-------+-------+-------+-------+-------+-------+-------+----+----+----+----+----+-------+-------+-------+-------+-------|
 * LB5 |  LB4  |  LB3  |  LB2  |  LB1  |  LB0  | m-prv | m-nxt | P, | P1 | P2 | P3 | P= |  RB0  |  RB1  |  RB2  |  RB3  |  RB4  | RB5
 *     |-------+-------+-------+-------+-------+-------+-------+----+----+----+----+----+-------+-------+-------+-------+-------|
 *     |  LH5  |  LH4  |  LH3  |  LH2  |  LH1  | sk-pv | sk-nx |  c | P0 | P. | P0 |esc |  RH1  |  RH2  |  RH3  |  RH4  |  RH5  |
 *     `------------------------------------------------------------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef L_QWERTY
[L_QWERTY] = LAYOUT_grid(
    KC_Q, KC_W, KC_E, KC_R, KC_T, LT(L_CFG,KC_MUTE), LT(L_CFG,KC_MPLY), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_Y, KC_U, KC_I, KC_O, KC_P,
    RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUM,KC_G),  KC_VOLD, KC_VOLU, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, LT(L_FUN,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN),
    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MRWD, KC_MFFD, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    KC_LEFT, KC_RGHT, KC_APP, LT(L_FUN,KC_BSPC), LT(L_NAV,KC_DEL), SK_HISTPRV, SK_HISTNXT, KC_C, KC_P0, KC_PDOT, KC_P0, KC_ESC, LT(L_SYM,KC_SPC), LT(L_NAV,KC_ENT), LT(L_FUN,KC_TAB),  KC_UP, KC_DOWN),
#endif
[L_HD] = LAYOUT_grid(
    HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0, HD_LTA,   HD_RTA,  KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,
    HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0, KC_VOLD,  KC_VOLU, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,
    HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, KC_MRWD,  KC_MFFD, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,
    HD_LH5, HD_LH4, HD_LH3, HD_LH2, HD_LH1, SK_HISTPRV, SK_HISTNXT, KC_C, KC_P0, KC_PDOT, KC_P0, KC_ESC, HD_RH1, HD_RH2, HD_RH3, HD_RH4, HD_RH5),
    
[L_SYM] = LAYOUT_grid(
    LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0, ______, ______, ______, ______, ______, ______, ______, LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4,
    LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0, ______, ______, ______, ______, ______, ______, ______, LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4,
    LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0, ______, ______, ______, ______, ______, ______, ______, LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4,
    ______, ______, LS_LH3, LS_LH2, LS_LH1, ______, ______, ______, ______, ______, ______, ______, LS_RH1, LS_RH2, LS_RH3, ______, ______),

[L_FUN] = LAYOUT_grid(
    LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0, ______, ______, ______, ______, ______, ______, ______, LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4,
    LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0, ______, ______, ______, ______, ______, ______, ______, LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4,
    LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0, ______, ______, ______, ______, ______, ______, ______, LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4,
    ______, ______, LF_LH3, LF_LH2, LF_LH1, ______, ______, ______, ______, ______, ______, ______, LF_RH1, LF_RH2, LF_RH3, ______, ______),

[L_NUM] = LAYOUT_grid(
    LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0, ______, ______, ______, ______, ______, ______, ______, LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4,
    LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0, ______, ______, ______, ______, ______, ______, ______, LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4,
    LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0, ______, ______, ______, ______, ______, ______, ______, LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4,
    ______, ______, LN_LH3, LN_LH2, LN_LH1, ______, ______, ______, ______, ______, ______, ______, LN_RH1, LN_RH2, LN_RH3, ______, ______),

[L_NAV] = LAYOUT_grid(
    LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0, ______, ______, ______, KC_F7,  KC_F8,  KC_F9, ______, LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,
    LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0, ______, ______, ______, KC_F4,  KC_F5,  KC_F6, ______, LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,
    LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0, ______, ______, ______, KC_F1,  KC_F2,  KC_F3, ______, LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,
    ______, ______, LV_LH3, LV_LH2, LV_LH1, ______, ______, ______, KC_F10, KC_F11, KC_F12, ______, LV_RH1, LV_RH2, LV_RH3, ______, ______),

[L_CFG] = LAYOUT_grid(
    LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0, ______, KC_NUM, RGB_TOG, __no__, __no__, __no__, RGB_TOG, LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,
    LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0, KC_VOLD, KC_VOLU, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, __no__, LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,
    LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0, ______, ______, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, __no__, LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,
    ______, ______, LC_LH3, LC_LH2, LC_LH1, KC_MPRV, KC_MNXT, KC_MPLY, __no__, __no__, __no__, __no__, LC_RH1, LC_RH2, LC_RH3, ______, ______)
};

