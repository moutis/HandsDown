#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_grid(KC_J, KC_G, KC_M, KC_P, KC_V, LT(7,KC_MUTE), LT(7,KC_MPLY), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), LT(5,KC_K), KC_VOLD, KC_VOLU, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, LT(4,KC_COMM), RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), KC_X, KC_F, KC_L, KC_D, KC_B, KC_MRWD, KC_MFFD, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_MINS, KC_U, KC_O, KC_W, KC_Y, KC_LEFT, KC_RGHT, KC_APP, LT(4,KC_BSPC), LT(6,KC_H), SK_HISTPRV, SK_HISTNXT, KC_C, KC_P0, KC_P0, KC_PDOT, KC_ESC, LT(3,KC_SPC), LT(6,KC_ENT), LT(4,KC_TAB), KC_UP, KC_DOWN),
	[1] = LAYOUT_grid(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, LCTL_T(KC_C), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(6,KC_R), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_grid(KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_DOT, KC_COMM, KC_SLSH, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSFT_T(KC_SPC), KC_TRNS, KC_TRNS, KC_RALT, KC_RCTL),
	[3] = LAYOUT_grid(KC_Q, KC_Z, RALT(KC_5), LALT(KC_7), LSA(KC_7), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LALT(KC_4), KC_DLR, A(S(KC_2)), LALT_T(KC_Y), RALT(KC_3), KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, LSA(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT(KC_1), LSFT_T(KC_PAST), RGUI_T(KC_PEQL), RALT_T(KC_PPLS), RCTL_T(KC_RO), KC_GT, KC_RBRC, KC_RPRN, KC_RCBR, LALT(KC_8), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LSA(KC_8), KC_TRNS, LSA(KC_9), LALT_T(KC_9), KC_TRNS, KC_TRNS),
	[4] = LAYOUT_grid(KC_F9, KC_F10, KC_F11, KC_F12, KC_F13, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_6, KC_7, KC_8, KC_MINS, LCTL_T(KC_F5), LALT_T(KC_F6), LGUI_T(KC_F6), LSFT_T(KC_F8), KC_F14, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, RSFT_T(KC_1), RGUI_T(KC_5), RALT_T(KC_9), RCTL_T(KC_PPLS), KC_F1, KC_F2, KC_F3, KC_F4, KC_F15, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_COMM, KC_2, KC_3, KC_4, KC_EQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_0, KC_DOT, KC_C, KC_TRNS, KC_TRNS),
	[5] = LAYOUT_grid(KC_NLCK, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_TRNS, KC_NLCK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, LALT_T(KC_TAB), KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DLR, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TAB, KC_PCMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_F16, KC_F17, KC_F18, LGUI_T(KC_BSPC), LSFT_T(KC_ENT), KC_SLCK, KC_PAUS, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_C, KC_P0, KC_P0, KC_PDOT, KC_PENT),
	[6] = LAYOUT_grid(SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_PSTM, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_TRNS, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_FAGN, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS, SK_DOCEND, KC_END, KC_DOWN, KC_LALT, SK_PARANXT, SK_HISTPRV, SK_HISTNXT, KC_TRNS, SK_DELWDL, SK_DELWDR, KC_TRNS, KC_TRNS, KC_TRNS, KC_F10, KC_F11, KC_F12, KC_TRNS, SK_HISTPRV, SK_HISTNXT, SK_ZOOMRST, SK_ZOOMOUT, SK_ZOOMIN),
	[7] = LAYOUT_grid(KC_NO, AG_SWAP, CG_SWAP, KC_NO, LCA(KC_DEL), KC_TRNS, KC_NLCK, RGB_TOG, KC_NO, KC_NO, KC_NO, KC_NO, SK_KILL, KC_NO, KC_EJCT, KC_NO, SK_ZOOMRST, KC_NO, HD_L_QWERTY, HD_L_Gold, HD_L_Bronze, KC_NO, KC_TRNS, KC_TRNS, RGB_MOD, RGB_VAI, RGB_SAI, RGB_HUI, KC_NO, KC_BRIU, KC_MPRV, KC_MUTE, KC_MNXT, SK_ZOOMOUT, KC_NO, AG_NORM, CG_NORM, KC_NO, HD_AdaptKeyToggle, KC_BRID, KC_BRIU, RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD, KC_NO, KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, SK_ZOOMIN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS, KC_MPLY, KC_MSTP, KC_VOLU, KC_VOLD)
};
