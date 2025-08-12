#include QMK_KEYBOARD_H

#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions (needed here for the QMK keymap introspection)
#endif

#define ______ KC_TRNS
#define __no__ KC_NO

/* The Kyria Keymap Key position names
 * ,-----------------------------------------------.                                  ,-----------------------------------------------.
 * |  LT5  |  LT4  |  LT3  |  LT2  |  LT1  |  LT0  |  LTA                        RTA  |  RT0  |  RT1  |  RT2  |  RT3  |  RT4  |  RT5  |
 * |-------+-------+-------+-------+-------+-------+                                  +-------+-------+-------+-------+-------+-------|
 * |  LM5  |  LM4  |  LM3  |  LM2  |  LM1  |  LM0  |  LMA                        RMA  |  RM0  |  RM1  |  RM2  |  RM3  |  RM4  |  RM5  |
 * |-------+-------+-------+-------+-------+-------+-------+-------.  ,-------+-------+-------+-------+-------+-------+-------+-------|
 * |  LB5  |  LB4  |  LB3  |  LB2  |  LB1  |  LB0  |  LBA  |  LBB  |  |  RBB  |  RBA  |  RB0  |  RB1  |  RB2  |  RB3  |  RB4  |  RB5  |
 * `-------+-------+-------+-------+-------+-------+-------+-------'  '-------+-------+-------+-------+-------+-------+-------+-------'
 *            LH5  |  LH4  |  LH3  |  LH2  |  LH1  |  LH0  |  LHA        RHA  |  RH0  |  RH1  |  RH2  |  RH3  |  RH4  |  RH5
 *                 `---------------------------------------'                  '---------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#ifdef L_QWERTY
    [L_QWERTY] = LAYOUT(
    SK_COPY, KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,                                   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LNG2,
    SK_PSTE, RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUM,KC_G), LT(L_FUN,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_LNG1,
    KC_AMPR, KC_Z, KC_X,    KC_C,   KC_V,   KC_B,   HD_LBA, HD_LBB, HD_RBB, HD_RBA, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_EQL,
        LT(L_FUN,KC_MUTE), KC_APP, LT(L_FUN,KC_BSPC), LT(L_NAV,KC_DEL), HD_LHA, HD_RHA, LT(L_SYM,KC_SPC), LT(L_NAV,KC_ENT), LT(L_FUN,KC_TAB), LT(L_FUN,KC_MPLY)),
#endif
    [L_HD] = LAYOUT(
    HD_LT5, HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,                                 HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4, HD_RT5,
    HD_LM5, HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,                                 HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4, HD_RM5,
    HD_LB5, HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0, HD_LBA, HD_LBB, HD_RBB, HD_RBA, HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4, HD_RB5,
                    HD_LH0, HD_LH3, HD_LH2, HD_LH1, HD_LHA,                 HD_RHA, HD_RH1, HD_RH2, HD_RH3, HD_RH0),

    [L_SYM] = LAYOUT(
    LS_LT5, LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0,                                 LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4, LS_RT5,
    LS_LM5, LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0,                                 LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4, LS_RM5,
    LS_LB5, LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0, LS_LBA, LS_LBB, LS_RBB, LS_RBA, LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4, LS_RB5,
                    LS_LH0, LS_LH3, LS_LH2, LS_LH1, LS_LHA,                 LS_RHA, LS_RH1, LS_RH2, LS_RH3, LS_RH0),

    [L_FUN] = LAYOUT(
    LF_LT5, LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0,                                 LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4, LF_RT5,
    LF_LM5, LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0,                                 LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4, LF_RM5,
    LF_LB5, LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0, LF_LBA, LF_LBB, LF_RBB, LF_RBA, LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4, LF_RB5,
                    LF_LH0, LF_LH3, LF_LH2, LF_LH1, LF_LHA,                 LF_RHA, LF_RH1, LF_RH2, LF_RH3, LF_RH0),

    [L_NUM] = LAYOUT(
    LN_LT5, LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0,                                 LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4, LN_RT5,
    LN_LM5, LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0,                                 LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4, LN_RM5,
    LN_LB5, LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0, LN_LBA, LN_LBB, LN_RBB, LN_RBA, LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4, LN_RB5,
                    LN_LH0, LN_LH3, LN_LH2, LN_LH1, LN_LHA,                 LN_RHA, LN_RH1, LN_RH2, LN_RH3, LN_RH0),
    
    [L_NAV] = LAYOUT(
    LV_LT5, LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,                                 LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4, LV_RT5,
    LV_LM5, LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,                                 LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4, LV_RM5,
    LV_LB5, LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0, LV_LBA, LV_LBB, LV_RBB, LV_RBA, LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4, LV_RB5,
                    LV_LH0, LV_LH3, LV_LH2, LV_LH1, LV_LHA,                 LV_RHA, LV_RH1, LV_RH2, LV_RH3, LV_RH0),

    [L_CFG] = LAYOUT(
    LC_LT5, LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,                                 LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4, LC_RT5,
    LC_LM5, LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,                                 LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4, LC_RM5,
    LC_LB5, LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0, LC_LBA, LC_LBB, LC_RBB, LC_RBA, LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4, LC_RB5,
                    LC_LH0, LC_LH3, LC_LH2, LC_LH1, LC_LHA,                 LC_RHA, LC_RH1, LC_RH2, LC_RH3, LC_RH0),

};

