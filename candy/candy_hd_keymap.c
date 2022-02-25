#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_grid(KC_J, KC_G, KC_M, KC_P, KC_V, LT(7,KC_MUTE), LT(7,KC_MPLY), KC_SLSH, KC_7, KC_8, KC_9, KC_MINS, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_B, LT(5,KC_TAB), KC_PERC, KC_ASTR, KC_4, KC_5, KC_6, KC_PLUS, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_X, KC_F, KC_L, KC_D, KC_K, KC_LBRC, KC_RBRC, KC_COMM, KC_1, KC_2, KC_3, KC_EQL, KC_MINS, KC_U, KC_O, KC_W, KC_Y, KC_DOWN, KC_UP, LT(5,KC_LANG2), LT(4,KC_BSPC), LT(6,KC_H), KC_APP, LT(3,KC_ESC), KC_C, KC_0, KC_0, KC_DOT, LT(4,KC_TAB), LT(3,KC_SPC), LT(6,KC_ENT), LT(5,KC_LANG1), KC_LEFT, KC_RGHT),
	[1] = LAYOUT_grid(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_D), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_L, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_T), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_grid(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_DOT, KC_COMM, KC_SLSH, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSFT_T(KC_SPC), KC_TRNS, KC_TRNS, KC_RALT, KC_RCTL),
	[3] = LAYOUT_grid(KC_Q, KC_Z, LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_9)), S(G(KC_4)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_4), KC_DLR, A(S(KC_2)), LALT_T(KC_Y), RALT(KC_3), KC_LT, KC_GT, KC_LPRN, KC_LCBR, LALT(KC_8), C(S(G(KC_4))), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_1), LSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_RO), A(S(KC_5)), A(S(KC_7)), KC_RPRN, KC_RCBR, RALT(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_grid(LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_LBRC)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_7, KC_8, KC_9, KC_RO, KC_LT, KC_GT, KC_LPRN, KC_LCBR, LALT(KC_8), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL, RSFT_T(KC_4), RGUI_T(KC_5), RALT_T(KC_6), RCTL_T(KC_MINS), A(S(KC_5)), A(S(KC_7)), KC_RPRN, KC_RCBR, RALT(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_1, KC_2, KC_3, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_COMM, KC_DOT, KC_TRNS, KC_TRNS),
	[5] = LAYOUT_grid(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F7), LSFT_T(KC_F8), KC_F14, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_F16, KC_F17, KC_F18, KC_F19, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_P0, KC_PDOT, KC_C, KC_PENT, KC_PEQL),
	[6] = LAYOUT_grid(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_DOCEND, KC_END, KC_DOWN, KC_LALT, SK_PARANXT, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SK_ZOOMRST, SK_HISTPRV, SK_HISTNXT, SK_ZOOMOUT, SK_ZOOMIN),
	[7] = LAYOUT_grid(KC_PSCR, KC_SLCK, KC_EJCT, KC_NO, LCA(KC_DEL), KC_TRNS, KC_NO, KC_NO, RGB_TOG, RGB_MOD, RGB_RMOD, KC_NO, SK_KILL, KC_NO, CG_SWAP, AG_SWAP, KC_NO, KC_MPRV, KC_MNXT, KC_MSTP, KC_VOLU, KC_BRIU, KC_NO, KC_NO, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, KC_NO, KC_NO, HD_L_Bronze, HD_L_Gold, HD_L_QWERTY, KC_NO, KC_MRWD, KC_MFFD, KC_MUTE, KC_VOLD, KC_BRID, KC_NO, KC_NO, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, KC_NO, HD_AdaptKeyToggle, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_PAUS, KC_MPLY, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, CG_NORM, AG_NORM, KC_NO, KC_MRWD, KC_MFFD)
};