#define combo_OLED_row 5

// functions / state keys

const uint16_t PROGMEM F_MAC_combo[] = {KC_MINS, KC_M, COMBO_END}; // Set MAC OS env var
const uint16_t PROGMEM F_WIN_combo[] = {KC_MINS, KC_W, COMBO_END}; // Set WIN OS env var
const uint16_t PROGMEM F_KILL_combo[] = {KC_MINS, KC_DOT, COMBO_END}; // Force quit
const uint16_t PROGMEM F_SCLP_combo[] = {KC_MINS, KC_C, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_MINS, KC_O, COMBO_END}; //  SCREEN shot SELECTION to file
const uint16_t PROGMEM F_CAPS_combo[] = {KC_D, KC_P, COMBO_END}; // CAPS LOCK
const uint16_t PROGMEM F_LANG1_combo[] = {KC_L, KC_O, COMBO_END}; // LANG1/KANA
const uint16_t PROGMEM F_LANG2_combo[] = {KC_L, KC_P, COMBO_END}; // LANG2/EISUU
const uint16_t PROGMEM F_BACK_combo[] = {KC_M, KC_L, COMBO_END}; // CMD [
const uint16_t PROGMEM F_FWD_combo[] = {KC_M, KC_B, COMBO_END}; // CMD ]

//  (22) keypad combos
const uint16_t PROGMEM PCM1_combo[] = {KC_COMM, KC_P1, COMBO_END};
const uint16_t PROGMEM P01_combo[] = {KC_P0, KC_P1, COMBO_END};
const uint16_t PROGMEM P02_combo[] = {KC_P0, KC_P2, COMBO_END};
const uint16_t PROGMEM P04_combo[] = {KC_P0, KC_P4, COMBO_END};
const uint16_t PROGMEM P05_combo[] = {KC_P0, KC_P5, COMBO_END};
const uint16_t PROGMEM P12_combo[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM P23_combo[] = {KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM P13_combo[] = {KC_P1, KC_P3, COMBO_END};
const uint16_t PROGMEM P1E_combo[] = {KC_P1, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P3E_combo[] = {KC_P3, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P45_combo[] = {KC_P4, KC_P5, COMBO_END};
const uint16_t PROGMEM P56_combo[] = {KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM P46_combo[] = {KC_P4, KC_P6, COMBO_END};
const uint16_t PROGMEM P5PLS_combo[] = {KC_P5, KC_PPLS, COMBO_END};
const uint16_t PROGMEM P6PLS_combo[] = {KC_P6, KC_PPLS, COMBO_END};
const uint16_t PROGMEM PS7_combo[] = {KC_PSLS, KC_P7, COMBO_END};
const uint16_t PROGMEM P78_combo[] = {KC_P7, KC_P8, COMBO_END};
const uint16_t PROGMEM P79_combo[] = {KC_P7, KC_P9, COMBO_END};
const uint16_t PROGMEM P89_combo[] = {KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM P9M_combo[] = {KC_P9, KC_PMNS, COMBO_END};
const uint16_t PROGMEM PSLT_combo[] = {KC_PSLS, KC_PAST, COMBO_END};
const uint16_t PROGMEM PPLMN_combo[] = {KC_PPLS, KC_PMNS, COMBO_END};

// spatially arranged characters and diacritics

const uint16_t PROGMEM Hacut_combo[] = {KC_QUOT, KC_SLSH, COMBO_END}; // ´ acute (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {KC_QUOT, KC_O, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {KC_QUOT, KC_X, COMBO_END}; // ` grave

const uint16_t PROGMEM Hmacr_combo[] = {KC_C, KC_X, COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hdier_combo[] = {KC_O, KC_X, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Hstrk_combo[] = {KC_C, KC_SLSH, COMBO_END}; // — strikethrough (dead key)
const uint16_t PROGMEM Hodot_combo[] = {KC_O, KC_SLSH, COMBO_END}; // ˚ hi o dot over char (dead key)

const uint16_t PROGMEM Hbsls_combo[] = {KC_X, KC_SLSH, COMBO_END}; // \ backslash
const uint16_t PROGMEM H_Q_combo[] = {KC_P, KC_O, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_Z_combo[] = {KC_O, KC_COMM, COMBO_END}; // TYPE "z"

const uint16_t PROGMEM Hndsh_combo[] = {KC_MINS, KC_G, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {KC_MINS, KC_H, COMBO_END}; // — m dash
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_K, COMBO_END}; // ~ tilde
const uint16_t PROGMEM Henye_combo[] = {KC_G, KC_K, COMBO_END}; // ˜ enye (dead key)

const uint16_t PROGMEM Hquot_combo[] = {KC_QUOT, KC_C, COMBO_END}; // " DOUBLE QUOTE

const uint16_t PROGMEM Hhash_combo[] = {KC_W, KC_P, COMBO_END}; // #
const uint16_t PROGMEM Hat_combo[] = {KC_W, KC_O, COMBO_END}; // @

const uint16_t PROGMEM Hunds_combo[] = {KC_P, KC_COMM, COMBO_END}; // _ underscore
const uint16_t PROGMEM Hcoln_combo[] = {KC_O, KC_DOT, COMBO_END}; // : colon
const uint16_t PROGMEM Helip_combo[] = {KC_P, KC_DOT, COMBO_END}; // … colon

// Bigram and other multi-output thingies
const uint16_t PROGMEM H_QU_combo[] = {KC_C, KC_O, COMBO_END}; // TYPE "qu"
const uint16_t PROGMEM H_GL_combo[] = {KC_G, KC_H, COMBO_END}; // TYPE "gl"
const uint16_t PROGMEM H_LK_combo[] = {KC_H, KC_K, COMBO_END}; // TYPE "lk"

const uint16_t PROGMEM Hldaq_combo[] = {KC_M, KC_COMM, COMBO_END}; // «
const uint16_t PROGMEM Hrdaq_combo[] = {KC_M, KC_DOT, COMBO_END}; // »
const uint16_t PROGMEM Hlsaq_combo[] = {KC_W, KC_COMM, COMBO_END}; // ‹
const uint16_t PROGMEM Hrsaq_combo[] = {KC_W, KC_DOT, COMBO_END}; // ›

// Spatially arranged typical functions
const uint16_t PROGMEM Qtab_combo[] = {KC_Q, KC_W, COMBO_END}; // tab QWERTY

const uint16_t PROGMEM Hent_combo[] = {KC_M, KC_D, COMBO_END}; // enter
const uint16_t PROGMEM Hsall_combo[] = {KC_J, KC_D, COMBO_END}; // select all
const uint16_t PROGMEM Hundo_combo[] = {KC_J, KC_B, COMBO_END}; // undo
const uint16_t PROGMEM Hcut_combo[] = {KC_J, KC_L, COMBO_END}; // cut
const uint16_t PROGMEM Hcopy_combo[] = {KC_L, KC_B, COMBO_END}; // copy
const uint16_t PROGMEM Hpste_combo[] = {KC_L, KC_D, COMBO_END}; // paste
const uint16_t PROGMEM Hpstm_combo[] = {KC_B, KC_D, COMBO_END}; // paste-match


// (3) functional spatially arranged, but still same on both layouts (shared to conserve memory)
const uint16_t PROGMEM quotq_combo[] = {KC_QUOT, KC_V, COMBO_END};  // "|" insert between double quote
//const uint16_t PROGMEM Hdbrak_combo[] = {KC_V, KC_B, COMBO_END}; // [|] insert between brackets
//const uint16_t PROGMEM Hdbrce_combo[] = {KC_Z, KC_J, COMBO_END}; // {|} insert between braces
//const uint16_t PROGMEM Hdparn_combo[] = {KC_P, KC_W, COMBO_END}; // (|) insert between parens
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END}; // ; semicolon
const uint16_t PROGMEM dotslsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // \ backslash
const uint16_t PROGMEM commslsh_combo[] = {KC_COMM, KC_SLSH, COMBO_END}; // _ underscore

enum my_combos {
    CC_SCLN, // ; SIMPLE COMBO must be first-used as FALSE for combo_on
    HC_COLN, // :
    HC_BSLS, // \ backslash
    HC_UNDS, // _ underscore
    HC_QUOT, // "
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_GRV, // ` grave
    HC_HASH, // #
    HC_AT, // @
    QC_TAB,

    HC_Q, // Q is not on the map
    HC_Z, // Z is not on the map

    //
    // ACTION COMBOS (ie, not simple combos above)
    //
    // This group all have actions on press (no hold-delay),
    // may be repeated if held (register_code) or not (tap_code)
    //
    PC_PENT, // <enter> on num
    PC_BSPC, // <bksp> on num
    PC_DEL, // <del> on num
    PC_TAB, // <tab> on num

    //
    // DELAYED ACTION COMBOS -- this block must be contiguous
    //
    // no action on press, action (in matrix_scan_user),
    // underlying keys if the hold threshold is not met.
    // may repeat if appropriate. (tap_code vs register_code)
    //
    PC_STAB,  // Shift-<tab>
    PC_DASH, // – on number layer (keypad)
    PC_TILD, // ˜
    PC_ELIP, // …
    HC_ELIP, // …
    PC_COLN, // :
    PC_DEG, //
    PC_NEQL, // ≠
    PC_ENTR, // <enter> on num layer
    PC_DIV, // ÷
    PC_PLMN, // ±
    PC_PERC, // %
    PC_EURO, // €
    PC_DOLR, // $
    PC_CENT, // ¢
    PC_JYEN, // ¥
    PC_BPND, // £
    PC_LPRN,
    PC_RPRN,
    
    FC_MAC, // Set MAC OS env var
    FC_WIN, // Set WIN OS env var
    FC_KILL, // Force quit
    FC_SCAP, // Screen Capture Selection
    FC_SCLP, // Screen Capture Selection to clipboard
    FC_CAPS, // CAPS LOCK
    FC_LANG1, // LANG1/KANA
    FC_LANG2, // LANG2/EISUU
    FC_BACK, // CMD [
    FC_FWD, // CMD ]

    CC_2DQUO, // "|" insertion point between double quotes
//    HC_LPRN,
//    HC_RPRN,
//    HC_2BRAC,
//    HC_2PARN,
    HC_LDAQ, // «
    HC_RDAQ, // »
    HC_RSAQ, // ‹
    HC_LSAQ, // ›
//    HC_2BRAK,
    HC_ENYE, // ~ enye
    HC_ACUT, // ´ acute
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_STRK, // — strikethrough
    HC_ODOT, // ˚ hi o dot over char

    HC_TYPE_QU,
    HC_TYPE_GL,
    HC_TYPE_LK,

    HC_ENT,
    HC_SALL,
    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
    HC_PSTM  // END OF DELAY BLOCK
};


combo_t key_combos[COMBO_COUNT] = {
    // These simple combos trigger on press, repeat.
    [CC_SCLN] = COMBO(commdot_combo, KC_SCLN),  // must be first, used as FALSE for combo_on
    [HC_COLN] = COMBO(Hcoln_combo, KC_COLN),  // :
    [HC_BSLS] = COMBO(Hbsls_combo, KC_BSLS), // \ backslash
    [HC_UNDS] = COMBO(Hunds_combo, KC_UNDS), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~
    [HC_GRV] = COMBO(Hgrv_combo, KC_GRV),  // `
    [HC_QUOT] = COMBO(Hquot_combo, KC_DQUO), // " QUOTE (STRAIGHT)
    [HC_HASH] = COMBO(Hhash_combo, KC_HASH), // #
    [HC_AT] = COMBO(Hat_combo, KC_AT), // @
    [QC_TAB] = COMBO(Qtab_combo, KC_TAB),

    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),


    [PC_PENT] = COMBO(P3E_combo, KC_PENT), // <enter> on num
    [PC_BSPC] = COMBO(P01_combo, KC_BSPC), // <bksp> on num
    [PC_DEL] = COMBO(P02_combo, KC_DEL), // <del> on num
    [PC_TAB] = COMBO(P05_combo, KC_TAB), // <tab> on num

    // action combos below
    // This group have custom actions on trigger (no hold-delay), repeat if held
    [CC_2DQUO] = COMBO_ACTION(quotq_combo),

    // this block should be contiguous,
    // Delayed action (COMBO_HOLD threshold). No repeat if held (tap_code)
    // should send the underlying combo keys if COMBO_HOLD is not met.

    // Keypad combos (all need actions or mods, so must be here)
    [PC_STAB] = COMBO_ACTION(P04_combo), // shift-<tab> on num
    [PC_DASH] = COMBO_ACTION(P12_combo), // – for time span on number layer
    [PC_TILD] = COMBO_ACTION(P13_combo), // ~ for time span on number layer
    [PC_ELIP] = COMBO_ACTION(P23_combo), // … for time span on number layer
    [PC_LPRN] = COMBO_ACTION(P45_combo), // ( on number layer
    [PC_RPRN] = COMBO_ACTION(P56_combo), // ) on number layer
    [PC_COLN] = COMBO_ACTION(P46_combo), // : on number layer for time 12:30xx
    [PC_PERC] = COMBO_ACTION(P6PLS_combo), // % on numbers
    [PC_DEG] = COMBO_ACTION(P5PLS_combo), // degree symbol on number layer
    [PC_JYEN] = COMBO_ACTION(PS7_combo), // €
    [PC_DOLR] = COMBO_ACTION(P78_combo), // $
    [PC_CENT] = COMBO_ACTION(P79_combo), // ¢
    [PC_EURO] = COMBO_ACTION(P89_combo), // ¥
    [PC_BPND] = COMBO_ACTION(P9M_combo), // £
    [PC_DIV] = COMBO_ACTION(PSLT_combo), // ÷
    [PC_PLMN] = COMBO_ACTION(PPLMN_combo), // ±
    [PC_NEQL] = COMBO_ACTION(P1E_combo), // ≠

    [FC_MAC] = COMBO_ACTION(F_MAC_combo), // Set MAC OS env var
    [FC_WIN] = COMBO_ACTION(F_WIN_combo), // Set WIN OS env var
    [FC_KILL] = COMBO_ACTION(F_KILL_combo), // Force quit
    [FC_SCAP] = COMBO_ACTION(F_SCAP_combo), // SCREEN CAPTURE SELECTION
    [FC_SCLP] = COMBO_ACTION(F_SCLP_combo), // SCREEN CAPTURE SELECTION to clipboard
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    [FC_LANG1] = COMBO(F_LANG1_combo, KC_LANG1), // LANG1/KANA
    [FC_LANG2] = COMBO(F_LANG2_combo, KC_LANG2), // LANG2/EISUU
    [FC_BACK] = COMBO_ACTION(F_BACK_combo),  // CMD [
    [FC_FWD] = COMBO_ACTION(F_FWD_combo),  // CMD ]

// HANDSDOWN
//    [HC_LPRN] = COMBO_ACTION(Hlprn_combo),
//    [HC_RPRN] = COMBO_ACTION(Hrprn_combo),
//    [HC_2BRAC] = COMBO_ACTION(Hdbrce_combo),
//    [HC_2PARN] = COMBO_ACTION(Hdparn_combo),
    [HC_LDAQ] = COMBO_ACTION(Hldaq_combo), // «
    [HC_RDAQ] = COMBO_ACTION(Hrdaq_combo), // »
    [HC_LSAQ] = COMBO_ACTION(Hlsaq_combo), // ‹
    [HC_RSAQ] = COMBO_ACTION(Hrsaq_combo), // ›
//    [HC_2BRAK] = COMBO_ACTION(Hdbrak_combo), // left+right bracket, insertion in the middle
    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_STRK] = COMBO_ACTION(Hstrk_combo), // - strikethrough
    [HC_ENYE] = COMBO_ACTION(Henye_combo), // ˜ enye
    [HC_ODOT] = COMBO_ACTION(Hodot_combo), // ˚ hi o dot over char
    [HC_ELIP] = COMBO_ACTION(Helip_combo),  // …


    [HC_TYPE_QU] = COMBO_ACTION(H_QU_combo),
    [HC_TYPE_GL] = COMBO_ACTION(H_GL_combo),
    [HC_TYPE_LK] = COMBO_ACTION(H_LK_combo),

    [HC_ENT] = COMBO(Hent_combo, KC_ENT),
    [HC_SALL] = COMBO_ACTION(Hsall_combo),
    [HC_UNDO] = COMBO_ACTION(Hundo_combo),
    [HC_CUT] = COMBO_ACTION(Hcut_combo),
    [HC_COPY] = COMBO_ACTION(Hcopy_combo),
    [HC_PSTE] = COMBO_ACTION(Hpste_combo),
    [HC_PSTM] = COMBO_ACTION(Hpstm_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, combo_OLED_row);
#endif
    if (pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_write_P(PSTR("Combo: "), false);
#endif
        keyhold_timer = timer_read(); // timer for combo hold threshold
        switch(combo_index) {
            case PC_STAB ... HC_PSTM:  // these have a hold delay before triggering
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
            case HC_NDSH:
                register_code16(A(KC_MINS));
                break;
            case HC_MDSH:
                 register_code16(A(S(KC_MINS)));
                break;
        } // end switch (combo_index)
    } else { // end if (pressed)

#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(0,combo_OLED_row);
        oled_write_P(PSTR("                     "), false);
#endif
/*/
 This is the NOT pressed switch (ie. it is the key up event)
/*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch
        if (combo_on && !combo_triggered) {// no combo, so send the underlying keys
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
    oled_write_P(PSTR("abort"), false);
#endif
            switch(combo_index) {
                case PC_DASH:
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    break;
                case PC_TILD:
                    tap_code(KC_P1);
                    tap_code(KC_P3);
                    break;
                case PC_ELIP:
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    break;
                case PC_LPRN:
                    tap_code(KC_P4);
                    tap_code(KC_P5);
                    break;
                case PC_RPRN:
                    tap_code(KC_P5);
                    tap_code(KC_P6);
                    break;
                case PC_COLN:
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                    break;
                case PC_PERC:
                    tap_code(KC_P6);
                    tap_code(KC_PPLS);
                    break;
                case PC_JYEN:
                    tap_code(KC_SLSH);
                    tap_code(KC_7);
                    break;
                case PC_DOLR:
                    tap_code(KC_7);
                    tap_code(KC_8);
                    break;
                case PC_CENT:
                    tap_code(KC_7);
                    tap_code(KC_9);
                    break;
                case PC_EURO:
                    tap_code(KC_8);
                    tap_code(KC_9);
                    break;

                case HC_TYPE_QU:
                    tap_code(KC_C);
                    tap_code(KC_O);
                    break;
                case HC_TYPE_GL:
                    tap_code(KC_G);
                    tap_code(KC_H);
                    break;
                case HC_TYPE_LK:
                    tap_code(KC_H);
                    tap_code(KC_K);
                    break;

                case HC_SALL:
                    tap_code(KC_J);
                    tap_code(KC_D);
                    break;
                case HC_UNDO:
                    tap_code(KC_J);
                    tap_code(KC_B);
                    break;
                case HC_CUT:
                    tap_code(KC_J);
                    tap_code(KC_L);
                    break;
                case HC_COPY:
                    tap_code(KC_B);
                    tap_code(KC_L);
                    break;
                case HC_PSTE:
                    tap_code(KC_L);
                    tap_code(KC_D);
                    break;
                case HC_PSTM:
                    tap_code(KC_B);
                    tap_code(KC_D);
                    break;
            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll resolve the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
                case HC_NDSH:
                    unregister_code16(A(KC_MINS));
                    break;
                case HC_MDSH:
                    unregister_code16(A(S(KC_MINS)));
                    break;
                    
                case HC_UNDO:
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_Z));
                    } else {
                        unregister_code16(G(KC_Z));
                    }
                    break;
                case HC_PSTE:
                    if (user_config.osIsWindows) {
                        unregister_code16(C(KC_V));
                    } else {
                        unregister_code16(G(KC_V));
                    }
                    break;
                case HC_PSTM:
                    if (user_config.osIsWindows) {
                        unregister_code16(C(S(A(KC_V))));
                    } else {
                        unregister_code16(G(S(A(KC_V))));
                    }
                    break;
            }  // end switch(combo_index) {
        } // else if (threshold met)
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup
#ifdef OLED_DRIVER_ENABLE
//    oled_render();
#endif
    return;
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user

    // These combos are to be held for TAPPING_TERM before triggering
    // to avoid accidental triggers while fast typing these common rolls.
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi), so maybe best to avoid them as
    // combos. On Hands Down, this means no combos on home row, but that's fine,
    // because home already has modifiers, so it all works out.
    if (!combo_triggered) {
        // do simple "on" on first press actions here,
        // then turn on combo state for hold acions to be resolved in keyup event above
        if (combo_on && (timer_elapsed(keyhold_timer) > COMBO_HOLD)) {
            switch(combo_on) {  // combo_on is global, set in process_combo above
                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_DASH:
                    tap_code16(A(KC_MINS));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case HC_ELIP:
                case PC_ELIP:
                    tap_code16(A(KC_SCLN));
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_EURO:
                    tap_code16(A(S(KC_2)));
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_CENT:
                    tap_code16(A(KC_4));
                    break;
                case PC_JYEN:
                    tap_code16(A(KC_Y));
                    break;
                case PC_BPND:
                    tap_code16(A(KC_3));
                    break;
                case PC_NEQL:
                    tap_code16(A(KC_EQL));
                    break;
                case PC_DIV:
                    tap_code16(A(KC_SLSH));
                    break;
                case PC_PLMN:
                    tap_code16(A(S(KC_EQL)));
                    break;
                case PC_DEG:
                    tap_code16(A(KC_0));
                    break;
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
/*                case NC_2BRAC:
                    tap_code16(KC_LCBR);
                    tap_code16(KC_RCBR);
                    tap_code(KC_LEFT);
                    break;
                case NC_2PARN:
                    tap_code16(KC_LPRN);
                    tap_code16(KC_RPRN);
                    tap_code(KC_LEFT);
                    break;
 */
                case HC_LDAQ:
                    tap_code16(A(KC_BSLS));
                    break;
                case HC_RDAQ:
                    tap_code16(A(S(KC_BSLS)));
                    break;
                case HC_LSAQ:
                    tap_code16(S(A(KC_3)));
                    break;
                case HC_RSAQ:
                    tap_code16(S(A(KC_4)));
                    break;
/*                case HC_2BRAK:
                    tap_code16(KC_LBRC);
                    tap_code16(KC_RBRC);
                    tap_code(KC_LEFT);
                    break;
*/
                case FC_MAC: // Set current OS indicator to macOs
                    user_config.osIsWindows = false;
                    eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
                    oled_set_cursor(oled_max_chars() - 3, 0);
                    oled_write_P(PSTR("MAC"), false);
#endif // OLED_DRIVER_ENABLE
                    break;
                case FC_WIN: // Set current OS indicator to Windows
                    user_config.osIsWindows = true;
                    eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
                    oled_set_cursor(oled_max_chars() - 3, 0);
                    oled_write_P(PSTR("WIN"), false);
#endif // OLED_DRIVER_ENABLE
                    break;
                case FC_KILL:
                    if (user_config.osIsWindows) {
                        tap_code16(C(A(KC_DEL)));
                    } else {
                        tap_code16(G(A(KC_ESC)));
                    }
                    break;
                case FC_BACK:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_LBRC));
                    } else {
                        tap_code16(G(KC_LBRC));
                    }
                    break;
                case FC_FWD:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_RBRC));
                    } else {
                        tap_code16(G(KC_RBRC));
                    }
                    break;

                case FC_SCAP:
                    if (user_config.osIsWindows) {
                        tap_code16(KC_PSCR);
                    } else {
                        tap_code16(S(G(KC_4)));
                    }
                    break;
                case FC_SCLP:
                    if (user_config.osIsWindows) {
                        tap_code16(A(KC_PSCR));
                    } else {
                        tap_code16(C(S(G(KC_4))));
                    }
                    break;
                case CC_2DQUO:
                    tap_code16(A(KC_LBRC));
                    tap_code16(A(S(KC_LBRC)));
                    tap_code(KC_LEFT);
                    break;

                case HC_ENYE:
                    tap_code16(A(KC_N));
                    break;
                case HC_ACUT:
                     tap_code16(A(KC_E));
                    break;
                case HC_CIRC:
                     tap_code16(A(KC_6));
                    break;
                case HC_MACR:
                    tap_code16(A(KC_A));
                    break;
                case HC_DIER:
                     tap_code16(A(KC_U));
                    break;
                case HC_STRK:
                    tap_code16(A(KC_L));
                    break;
                case HC_ODOT:
                    tap_code16(A(KC_K));
                    break;

                case HC_TYPE_QU:
                    SEND_STRING("qu");
                    break;
                case HC_TYPE_GL:
                    SEND_STRING("gl");
                    break;
                case HC_TYPE_LK:
                    SEND_STRING("lk");
                    break;

                case HC_SALL:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        tap_code16(C(KC_A));
                    } else {
                        tap_code16(G(KC_A));
                    }
                    break;
                case HC_UNDO:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        register_code16(C(KC_Z));
                    } else {
                        register_code16(G(KC_Z));
                    }
                    break;
                case HC_CUT:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_X));
                    } else {
                        tap_code16(G(KC_X));
                    }
                    break;
                case HC_COPY:
                    if (user_config.osIsWindows) {
                        tap_code16(C(KC_C));
                    } else {
                        tap_code16(G(KC_C));
                    }
                    break;
                case HC_PSTE:
                    if (user_config.osIsWindows) {
                        register_code16(C(KC_V));
                    } else {
                        register_code16(G(KC_V));
                    }
                    break;
                case HC_PSTM:
                    if (user_config.osIsWindows) {
                        register_code16(C(S(A(KC_V))));
                    } else {
                        register_code16(G(S(A(KC_V))));
                    }
                    break;
            } // switch
            combo_triggered = true;
            #ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
                oled_write_P(PSTR(" sent"), false);
            #endif
        }
    }
}
