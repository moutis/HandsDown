#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(SK_COPY, KC_J, KC_G, KC_M, KC_P, KC_V, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, KC_MHEN, SK_PSTE, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_B, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_HENK, SK_SCLP, KC_X, KC_F, KC_L, KC_D, KC_K, LT(5,KC_MHEN), SH_TT, TG(5), LT(5,KC_HENK), KC_MINS, KC_U, KC_O, KC_W, KC_Y, KC_EQL, LT(7,KC_MUTE), KC_APP, LT(4,KC_BSPC), LT(6,KC_H), LT(5,KC_MHEN), LT(5,KC_HENK), LT(3,KC_SPC), LT(6,KC_ENT), LT(5,KC_TAB), LT(7,KC_MPLY)),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, KC_TRNS, KC_TRNS, LCTL_T(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_R), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(LT(7,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(7,KC_LBRC), MO(6), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(6,KC_RBRC), KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_ESC, KC_TRNS, KC_TRNS, KC_ESC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RCTL_T(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_LALT, KC_LCTL, RSFT_T(KC_SPC), KC_TRNS, KC_QUOT, KC_TRNS),
	[3] = LAYOUT(KC_TRNS, KC_Z, KC_Q, LALT(KC_8), LSA(KC_5), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), KC_TRNS, KC_TRNS, LALT(KC_7), KC_LT, KC_LPRN, KC_LCBR, KC_LBRC, RALT(KC_1), LSFT_T(KC_PAST), LGUI_T(KC_PEQL), LALT_T(KC_PPLS), LCTL_T(KC_PSLS), KC_TRNS, KC_TRNS, RALT(KC_5), KC_GT, KC_RPRN, KC_RCBR, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_VOLD, KC_VOLU, SK_DELWDL, SK_DELWDR, KC_TRNS, A(S(KC_9)), KC_TRNS, LALT(KC_9), A(S(KC_8)), TG(5)),
	[4] = LAYOUT(RGB_TOG, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), LSA(KC_LBRC), LSA(KC_8), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, RGB_MOD, RGB_VAI, LSA(KC_3), KC_LT, KC_LPRN, KC_LCBR, KC_LBRC, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, RGB_HUI, RGB_VAD, LSA(KC_4), KC_GT, KC_RPRN, KC_RCBR, KC_RBRC, LALT(KC_MINS), KC_TRNS, KC_TRNS, KC_NLCK, KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, RGB_HUD, KC_TRNS, TG(4), KC_BSPC, KC_PENT, KC_TRNS, KC_BSPC, KC_P0, KC_PDOT, KC_C, SK_ZOOMRST),
	[5] = LAYOUT(RGB_TOG, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_BSLS, RGB_MOD, RGB_VAI, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_SCLN, RSFT_T(KC_4), RGUI_T(KC_5), RALT_T(KC_6), RCTL_T(KC_SLSH), RGB_HUI, RGB_VAD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, LCA(KC_DEL), KC_TRNS, KC_TRNS, KC_NLCK, KC_MINS, KC_1, KC_2, KC_3, KC_EQL, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RESET, KC_0, KC_DOT, KC_COMM, SK_ZOOMRST),
	[6] = LAYOUT(KC_TRNS, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_NLCK, KC_VOLU, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_TRNS, KC_VOLD, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_HANJ, KC_TRNS, KC_TRNS, KC_HANJ, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, SK_ZOOMOUT, SK_HISTPRV, SK_HISTNXT, SK_ZOOMIN, SK_ZOOMRST),
	[7] = LAYOUT(RGB_TOG, KC_NO, KC_NO, KC_EJCT, KC_NO, LCA(KC_DEL), SK_KILL, KC_NO, CG_SWAP, AG_SWAP, KC_NO, RGB_MOD, RGB_VAI, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLU, KC_BRIU, KC_NO, HD_L_Bronze, HD_L_Gold, HD_L_QWERTY, RGB_SAI, RGB_HUI, RGB_VAD, KC_MRWD, KC_MFFD, KC_MSTP, KC_VOLD, KC_BRID, KC_NO, KC_NO, KC_NO, KC_NO, HD_AdaptKeyToggle, KC_NO, KC_NO, KC_NO, RGB_SAD, RGB_HUD, RESET, KC_NO, KC_PAUS, KC_MPLY, KC_NO, KC_NO, CG_NORM, AG_NORM, KC_NO, RESET)
};
