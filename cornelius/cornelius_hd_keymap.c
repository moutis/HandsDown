#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(7,KC_MUTE), KC_J, KC_G, KC_M, KC_P, KC_V, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LT(7,KC_MPLY), KC_UP, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_B, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), LT(6,KC_BSPC), KC_DOWN, KC_X, KC_F, KC_L, KC_D, KC_K, KC_MINS, KC_U, KC_O, KC_W, KC_Y, LT(5,KC_EQL), KC_LEFT, KC_RGHT, KC_APP, LT(5,KC_LANG2), LT(4,KC_BSPC), LT(6,KC_H), LT(3,KC_SPC), LT(6,KC_ENT), LT(4,KC_LANG1), TG(6), KC_LBRC, KC_RBRC),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_D), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_L, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_T), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(LT(7,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(7,KC_ESC), MO(4), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, LT(5,KC_QUOT), KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RGUI_T(KC_EQL), KC_LCTL, MO(6), KC_TRNS, KC_DEL, LT(6,KC_BSPC), KC_LSFT, RSFT_T(KC_SPC), KC_TRNS, RALT_T(KC_LANG1), KC_TRNS, KC_LBRC, RCTL_T(KC_RBRC)),
	[3] = LAYOUT(KC_ESC, KC_Z, KC_Q, LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_9)), LALT(KC_4), KC_DLR, A(S(KC_2)), RALT(KC_3), LALT(KC_Y), KC_TRNS, KC_TRNS, KC_LT, KC_GT, KC_LPRN, KC_LCBR, LALT(KC_8), RALT(KC_1), RSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_RO), KC_TRNS, KC_TRNS, A(S(KC_5)), A(S(KC_7)), KC_RPRN, KC_RCBR, RALT(KC_5), KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_ESC, LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_8)), KC_GRV, KC_7, KC_8, KC_9, KC_BSLS, KC_TRNS, KC_TRNS, KC_LT, KC_GT, KC_LPRN, KC_LCBR, LALT(KC_7), KC_SCLN, RSFT_T(KC_4), RGUI_T(KC_5), RALT_T(KC_6), RCTL_T(KC_SLSH), KC_TRNS, KC_TRNS, A(S(KC_5)), A(S(KC_7)), KC_RPRN, KC_RCBR, RALT(KC_5), KC_MINS, KC_1, KC_2, KC_3, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_BSPC, LT(5,KC_DEL), KC_0, KC_DOT, KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS),
	[5] = LAYOUT(KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NLCK, KC_TRNS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_PAST, RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), RCTL_T(KC_PPLS), KC_TRNS, KC_F16, KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_F17, KC_F18, KC_PSCR, KC_LSCR, KC_PAUS, KC_INS, KC_P0, KC_PDOT, KC_C, KC_TRNS, KC_TRNS, KC_TRNS),
	[6] = LAYOUT(KC_TRNS, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_NLCK, KC_BRIU, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_TRNS, KC_BRID, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_ZOOMRST, SK_HISTPRV, SK_HISTNXT, KC_TRNS, SK_ZOOMIN, SK_ZOOMRST),
	[7] = LAYOUT(KC_MPLY, KC_NO, KC_NO, KC_EJCT, KC_NO, LCA(KC_DEL), SK_KILL, KC_NO, CG_SWAP, AG_SWAP, KC_NO, RESET, KC_VOLU, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLU, KC_BRIU, KC_NO, HD_L_Bronze, HD_L_Gold, HD_L_QWERTY, KC_NO, TG(6), KC_VOLD, KC_MRWD, KC_MFFD, KC_MSTP, KC_VOLD, KC_BRID, HD_AdaptKeyToggle, KC_NO, KC_NO, KC_NO, KC_NO, TG(5), KC_MPRV, KC_MNXT, SK_KILL, KC_VOLU, KC_VOLD, KC_MPLY, CG_NORM, AG_NORM, KC_NO, SK_KILL, KC_NO, KC_NO)
};
