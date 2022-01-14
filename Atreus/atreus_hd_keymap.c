#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_J, KC_G, KC_M, KC_P, KC_V, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_B, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_X, KC_F, KC_L, KC_D, KC_K, LT(7,KC_ESC), LT(7,KC_DEL), KC_MINS, KC_U, KC_O, KC_W, KC_Y, KC_DOWN, KC_UP, LT(5,KC_MHEN), LT(4,KC_BSPC), LT(6,KC_H), KC_APP, LT(5,KC_TAB), LT(3,KC_SPC), LT(6,KC_ENT), LT(5,KC_HENK), KC_LEFT, KC_RGHT),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, LCTL_T(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_R), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_Z, KC_X, KC_C, KC_V, KC_B, LT(7,KC_TAB), LT(5,KC_QUOT), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_BSPC), KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_Z, KC_Q, LALT(KC_8), LSA(KC_5), LSA(KC_7), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), LALT(KC_7), KC_LT, KC_LPRN, KC_LCBR, KC_LBRC, RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_RO), RALT(KC_5), KC_GT, KC_RPRN, KC_RCBR, KC_RBRC, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(LALT(KC_RBRC), LSA(KC_RBRC), LALT(KC_LBRC), LSA(KC_LBRC), LSA(KC_8), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, LSA(KC_3), KC_LT, KC_LPRN, KC_LCBR, KC_LBRC, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, LSA(KC_4), KC_GT, KC_RPRN, KC_RCBR, KC_RBRC, KC_NLCK, KC_TAB, KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_ENT, KC_TRNS, KC_DEL, KC_P0, KC_PDOT, KC_C, KC_TRNS, KC_TRNS),
	[5] = LAYOUT(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_GRV, KC_7, KC_8, KC_9, KC_BSLS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_SCLN, RSFT_T(KC_4), RGUI_T(KC_5), RALT_T(KC_6), RCTL_T(KC_SLSH), KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_PAUS, KC_TAB, KC_MINS, KC_1, KC_2, KC_3, KC_EQL, KC_PSCR, KC_LSCR, KC_TRNS, KC_BSPC, KC_ENT, KC_TRNS, KC_DEL, KC_0, KC_DOT, KC_COMM, KC_TRNS, KC_TRNS),
	[6] = LAYOUT(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_TRNS, KC_NLCK, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, SK_ZOOMIN, SK_ZOOMOUT, SK_ZOOMRST, KC_TRNS, KC_TRNS, KC_ESC, KC_TRNS, SK_HISTPRV, SK_HISTNXT, KC_TRNS, SK_HISTPRV, SK_HISTNXT),
	[7] = LAYOUT(KC_NO, KC_NO, KC_EJCT, KC_NO, LCA(KC_DEL), SK_KILL, KC_NO, CG_SWAP, AG_SWAP, KC_NO, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLU, KC_BRIU, KC_NO, HD_L_Bronze, HD_L_Gold, HD_L_QWERTY, KC_NO, KC_MRWD, KC_MFFD, KC_MSTP, KC_VOLD, KC_BRID, RESET, RESET, HD_AdaptKeyToggle, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO, KC_MUTE, KC_MPLY, KC_MUTE, KC_NO, CG_NORM, AG_NORM, KC_NO, KC_MPRV, KC_MNXT)
};
