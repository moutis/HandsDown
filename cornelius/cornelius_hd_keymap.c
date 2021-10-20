#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(LT(10,KC_MUTE), KC_J, KC_F, KC_M, KC_P, KC_V, HD_HASH, KC_DOT, KC_SLSH, KC_QUOT, KC_DQUO, LT(10,KC_MPLY), KC_UP, LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), KC_K, KC_COMM, RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_C), RCTL_T(KC_I), LT(9,KC_BSPC), KC_DOWN, KC_X, KC_G, KC_L, KC_D, KC_B, KC_MINS, KC_U, KC_O, KC_W, KC_Y, LT(7,KC_EQL), KC_LEFT, KC_RGHT, KC_APP, LT(5,KC_LANG2), LT(8,KC_BSPC), LT(7,KC_H), LT(8,KC_SPC), LT(7,KC_ENT), LT(6,KC_LANG1), TG(8), KC_LBRC, KC_RBRC),
	[1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_H), KC_TRNS, KC_G, KC_TRNS, KC_TRNS, KC_TRNS, RCTL_T(KC_I), RCTL_T(KC_K), KC_TRNS, KC_TRNS, KC_TRNS, KC_C, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DQUO, KC_QUOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_D), KC_B, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RCTL_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_L, KC_C, KC_K, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(7,KC_T), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT(KC_TRNS, KC_W, KC_TRNS, KC_TRNS, KC_TRNS, KC_V, KC_TRNS, KC_TRNS, KC_TRNS, KC_QUOT, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_N), LSFT_T(KC_T), KC_G, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_I), RSFT_T(KC_H), KC_TRNS, KC_TRNS, KC_TRNS, KC_C, KC_L, KC_D, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_Y, KC_K, KC_TRNS, KC_TRNS, LT(7,KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[5] = LAYOUT(S(G(KC_4)), LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), LALT(KC_8), LALT(KC_4), KC_DLR, A(S(KC_2)), LALT(KC_Y), RALT(KC_3), KC_TRNS, C(S(G(KC_4))), KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_7), RALT(KC_1), LSFT_T(KC_PAST), LGUI_T(KC_PEQL), LALT_T(KC_PPLS), LCTL_T(KC_BSLS), KC_TRNS, KC_TRNS, A(S(KC_5)), A(S(KC_7)), KC_LCBR, KC_RCBR, RALT(KC_5), KC_UNDS, KC_PIPE, KC_AMPR, KC_CIRC, KC_PERC, KC_TRNS, KC_TRNS, KC_TRNS, LCA(KC_DEL), KC_TRNS, SK_DELWDL, SK_DELWDR, A(S(KC_9)), LALT(KC_8), A(S(KC_8)), A(S(KC_R)), TO(5), KC_TRNS),
	[6] = LAYOUT(KC_F16, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_SLSH, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_F17, LCTL_T(KC_F6), LALT_T(KC_F7), LGUI_T(KC_F8), LSFT_T(KC_F9), KC_F10, KC_EQL, RSFT_T(KC_4), RGUI_T(KC_N), RALT_T(KC_6), RCTL_T(KC_MINS), KC_TRNS, KC_F18, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_MINS, KC_1, KC_2, KC_3, KC_EQL, KC_TRNS, KC_F19, KC_F20, KC_F21, KC_F21, KC_TRNS, KC_TRNS, KC_INS, KC_LSCR, KC_LNUM, KC_TRNS, KC_TRNS, KC_TRNS),
	[7] = LAYOUT(KC_MUTE, SK_QUIT, SK_CLOZ, SK_SCAP, SK_SCLP, SK_FAGN, SK_DOCBEG, KC_HOME, KC_UP, KC_PGUP, SK_PARAPRV, KC_TRNS, KC_MFFD, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, SK_FIND, SK_WORDPRV, KC_LEFT, KC_DOWN, KC_RGHT, SK_WORDNXT, KC_TRNS, KC_MRWD, SK_UNDO, SK_CUT, SK_COPY, SK_PSTE, SK_PSTM, SK_DOCEND, KC_END, KC_DOWN, KC_PGDN, SK_PARANXT, KC_TRNS, KC_MPRV, KC_MNXT, LCA(KC_DEL), KC_VOLD, KC_VOLU, KC_MPLY, SK_ZOOMRST, SK_HISTPRV, SK_HISTNXT, SK_ZOOMOUT, SK_ZOOMIN, SK_ZOOMRST),
	[8] = LAYOUT(S(G(KC_4)), LALT(KC_RBRC), A(S(KC_RBRC)), LALT(KC_LBRC), A(S(KC_LBRC)), A(S(KC_8)), KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PMNS, KC_NLCK, C(S(G(KC_4))), KC_LT, KC_GT, KC_LPRN, KC_RPRN, LALT(KC_7), KC_PAST, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_TRNS, KC_TRNS, A(S(KC_5)), A(S(KC_7)), KC_LBRC, KC_RBRC, RALT(KC_5), KC_COMM, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_BSPC, KC_DEL, KC_P0, KC_PDOT, KC_C, KC_C, KC_TRNS, KC_TRNS),
	[9] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_SLCK, KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_MRWD, KC_MSTP, KC_MFFD, KC_NO, KC_BRID, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_EJCT, KC_PAUS, KC_MUTE, KC_MPLY, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO),
	[10] = LAYOUT(KC_NO, BL_BRTG, RGB_SPI, RGB_SPD, KC_NO, KC_NO, KC_NO, CG_SWAP, AG_SWAP, KC_NO, KC_NO, KC_TRNS, KC_BRIU, BL_STEP, BL_INC, RGB_HUI, RGB_SAI, RGB_VAI, HD_L_Neu, HD_L_Bronze, HD_L_Silver, HD_L_Platinum, HD_L_Gold, KC_NO, KC_BRID, BL_TOGG, BL_DEC, RGB_HUD, RGB_SAD, RGB_VAD, TO(4), TO(0), TO(1), TO(2), TO(3), KC_NO, KC_NO, KC_NO, RESET, KC_NO, BL_ON, BL_OFF, CG_NORM, AG_NORM, KC_NO, RESET, KC_NO, KC_NO)
};
