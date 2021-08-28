#define combo_OLED_row 5

// functions / state keys

const uint16_t PROGMEM F_ESC_combo[] = {KC_X, KC_B, COMBO_END}; // ESCape
const uint16_t PROGMEM F_KILL_combo[] = {KC_X, KC_W, COMBO_END}; // Force quit
const uint16_t PROGMEM F_MAC_combo[] = {KC_HASH, KC_M, COMBO_END}; // Set MAC OS env var
const uint16_t PROGMEM F_WIN_combo[] = {KC_HASH, KC_W, COMBO_END}; // Set WIN OS env var
const uint16_t PROGMEM F_SCLP_combo[] = {KC_J, KC_V, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_J, KC_K, COMBO_END}; //  SCREEN shot SELECTION to file
const uint16_t PROGMEM F_CAPS_combo[] = {KC_D, KC_U, COMBO_END}; // CAPS LOCK other shift lock
const uint16_t PROGMEM H_CAPS_combo[] = {KC_H, KC_A, COMBO_END}; // CAPS LOCK for when I get home row combos working after merging Sevanteri's fork.  (Karabiner does L+R shift now)

//  (22) keypad combos
const uint16_t PROGMEM PSLMN_combo[] = {KC_PSLS, KC_PMNS, COMBO_END}; // toggle num layer
const uint16_t PROGMEM P0E_combo[] = {KC_P0, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCME_combo[] = {KC_DOT, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCM1_combo[] = {KC_DOT, KC_P1, COMBO_END};
const uint16_t PROGMEM PCM2_combo[] = {KC_DOT, KC_P2, COMBO_END};
const uint16_t PROGMEM P01_combo[] = {KC_P0, KC_P1, COMBO_END};
const uint16_t PROGMEM P02_combo[] = {KC_P0, KC_P2, COMBO_END};
const uint16_t PROGMEM P04_combo[] = {KC_P0, KC_P4, COMBO_END};
const uint16_t PROGMEM P05_combo[] = {KC_P0, KC_P5, COMBO_END};
const uint16_t PROGMEM P12_combo[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM P23_combo[] = {KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM P13_combo[] = {KC_P1, KC_P3, COMBO_END};
const uint16_t PROGMEM P1E_combo[] = {KC_P1, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P2E_combo[] = {KC_P2, KC_PEQL, COMBO_END};
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
const uint16_t PROGMEM PSLT_combo[] = {KC_P7, KC_PMNS, COMBO_END};
const uint16_t PROGMEM PPLMN_combo[] = {KC_P4, KC_PPLS, COMBO_END};


// Off map and other letter/symbol thingies typically on keyboard


// RIGHT HAND
// LOWER ROW

const uint16_t PROGMEM Hndsh_combo[] = {KC_MINS, KC_U, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {KC_MINS, KC_O, COMBO_END}; // — m dash
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_Y, COMBO_END}; // _ underscore
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_Y, COMBO_END}; // ~ tilde (not the dead one)
const uint16_t PROGMEM Hequal_combo[] = {KC_Y, KC_W, COMBO_END}; // = equal

// spatially arranged characters and diacritics
const uint16_t PROGMEM Hexlm_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_DQUO, COMBO_END}; // ?
const uint16_t PROGMEM Hat_combo[] = {KC_HASH, KC_DOT, COMBO_END}; // @ at mark
const uint16_t PROGMEM Helip_combo[] = {KC_HASH, KC_SLSH, COMBO_END}; // … elipses
const uint16_t PROGMEM Htic_combo[] = {KC_QUOT, KC_DQUO, COMBO_END}; // ` tic (not dead key grave)
const uint16_t PROGMEM Hacut_combo[] = {KC_QUOT, KC_SLSH, COMBO_END}; // ´ acute (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {KC_HASH, KC_DQUO, COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {KC_DOT, KC_DQUO, COMBO_END}; // - macron (dead key)ā
const uint16_t PROGMEM Hcirc_combo[] = {KC_QUOT, KC_DOT, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hdier_combo[] = {KC_U, KC_O, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Hring_combo[] = {KC_O, KC_Y, COMBO_END}; // ˚ ring (dead key)

// LOWER ROW
// SYMBOLS spatially arranged

// LEFT HAND

// TEXT ENTRY (ANY ROW/ MIXED ROWS
const uint16_t PROGMEM H_Z_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Q_combo[] = {KC_J, KC_M, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_Q2_combo[] = {KC_Y, KC_U, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_LM_combo[] = {KC_M, KC_P, COMBO_END}; // TYPE "lp"
const uint16_t PROGMEM H_tion_combo[] = {KC_P, KC_SLSH, COMBO_END}; // TYPE "tion"
const uint16_t PROGMEM H_Japan_combo[] = {KC_J, KC_P, COMBO_END}; // TYPE "Japan"

// UPPER ROW

// FUNCTIONS Spatially arranged
const uint16_t PROGMEM Qtab_combo[] = {KC_Q, KC_W, COMBO_END}; // tab QWERTY
const uint16_t PROGMEM Htab_combo[] = {KC_J, KC_F, COMBO_END}; // tab HANDS DOWN
const uint16_t PROGMEM Henye_combo[] = {KC_F, KC_P, COMBO_END}; // ˜ enye (dead key)

// LOWER ROW

// FUNCTIONS Spatially arranged
const uint16_t PROGMEM Hent_combo[] = {KC_D, KC_B, COMBO_END}; // ENTER
const uint16_t PROGMEM Hclose_combo[] = {KC_L, KC_B, COMBO_END}; // close
const uint16_t PROGMEM Hquit_combo[] = {KC_G, KC_B, COMBO_END}; // quit
const uint16_t PROGMEM Hfind_combo[] = {KC_F, KC_V, COMBO_END}; // find
const uint16_t PROGMEM Hsall_combo[] = {KC_X, KC_D, COMBO_END}; // select all
const uint16_t PROGMEM Hundo_combo[] = {KC_X, KC_G, COMBO_END}; // undo
const uint16_t PROGMEM Hcut_combo[] = {KC_X, KC_L, COMBO_END}; // cut
const uint16_t PROGMEM Hcopy_combo[] = {KC_G, KC_L, COMBO_END}; // copy
const uint16_t PROGMEM Hpste_combo[] = {KC_L, KC_D, COMBO_END}; // paste
const uint16_t PROGMEM Hpstm_combo[] = {KC_G, KC_D, COMBO_END}; // paste-match

// TWO HANDS
const uint16_t PROGMEM Hdquo_combo[] = {KC_HASH, KC_QUOT, COMBO_END};  // "|" insert between double quote
const uint16_t PROGMEM Hdbrc_combo[] = {KC_MINS, KC_W, COMBO_END};  // [|] insert between double BRACKET

// Major diacritic combos
const uint16_t PROGMEM HUM_combo[] = {KC_F, KC_U, COMBO_END};  // Ü
const uint16_t PROGMEM HOM_combo[] = {KC_F, KC_O, COMBO_END};  // Ö
const uint16_t PROGMEM HUK_combo[] = {KC_L, KC_U, COMBO_END};  // Ů
const uint16_t PROGMEM HOK_combo[] = {KC_L, KC_O, COMBO_END};  // O̊
const uint16_t PROGMEM HUV_combo[] = {KC_P, KC_U, COMBO_END};  // Û
const uint16_t PROGMEM HOV_combo[] = {KC_P, KC_O, COMBO_END};  // Ô
const uint16_t PROGMEM HUF_combo[] = {KC_V, KC_U, COMBO_END};  // Ú
const uint16_t PROGMEM HOF_combo[] = {KC_V, KC_O, COMBO_END};  // Ó



enum my_combos {
    FC_ESC, // ESCape SIMPLE COMBO must be first-used as FALSE for combo_on

    HC_EQL, // = equal
    HC_QUES, // ?
    HC_EXLM, // !
    HC_AT, // @
    HC_UNDS, // _ underscore
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_TIC, // ` tic (not a dead key)
    HC_GRV, // ` grave (dead key)
    HC_TAB,
    QC_TAB,

    HC_Q, // Q is not on the map
    HC_Q2, // Q is not on the map
    HC_Z, // Z is not on the map

    //
    // ACTION COMBOS (ie, not simple combos as above)
    //
    // This group all have actions on press (no hold-delay),
    // may be repeated if held (register_code) or not (tap_code)
    // to be handled in process_combo_event and/or matrix_scan_user_process_combo
    //
    PC_PENT, // <enter> on num
    PC_BSPC, // <bksp> on num
    PC_DEL, // <del> on num
    PC_TAB, // <tab> on num
    HC_TYPE_TION,
    HC_TYPE_JAPAN,

    //
    // DELAYED ACTION COMBOS -- this block must be contiguous
    //
    // no action on press, action (in matrix_scan_user),
    // underlying keys if the hold threshold is not met.
    // may repeat if appropriate. (tap_code vs register_code)
    //
    PC_STAB,  // Shift-<tab>
    PC_TGNM, // TOGGLE NUM LAYER
    PC_DASH, // – on number layer (keypad)
    PC_TILD, // ˜
    PC_ELIP, // …
    HC_ELIP, // …
    PC_COLN, // :
    PC_DEG, //
    PC_NEQL, // ≠
    PC_ENTR, // <enter> on num layer
    PC_SENT,  // Shift-<enter>
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
    PC_CLR,
    PC_AC,
    
    FC_MAC, // Set MAC OS env var
    FC_WIN, // Set WIN OS env var
    FC_KILL, // Force quit
    FC_SCAP, // Screen Capture Selection
    FC_SCLP, // Screen Capture Selection to clipboard
    FC_CAPS, // CAPS LOCK
    HC_CAPS, // CAPS LOCK

    HC_2DQUO, // "|" insertion point between double quotes
    HC_2DBRC, // [|] insertion point between double BRACKETS (japanese quote)

    HC_ENYE, // ~ enye
    HC_ACUT, // ´ acute
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_RING, // ˚ ring

    HC_UM, // Ü
    HC_OM, // Ö
    HC_UK, // Ů
    HC_OK, // O̊
    HC_UV, // Û
    HC_OV, // Ô
    HC_UF, // Ú
    HC_OF, // Ó

    HC_TYPE_LM,

    
    HC_ENT,
    HC_CLOSE,
    HC_QUIT,
    HC_FIND, // Find the selection
    HC_SALL,
    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
    HC_PSTM  // END OF DELAY BLOCK
};


combo_t key_combos[COMBO_COUNT] = {
    // These simple combos trigger on press, repeat.
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL), // =
    [HC_UNDS] = COMBO(Hunds_combo, KC_UNDS), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~
    [HC_TIC] = COMBO(Htic_combo, KC_GRV),  // `
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_AT] = COMBO(Hat_combo, KC_AT), // @
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [QC_TAB] = COMBO(Qtab_combo, KC_TAB),

    [HC_Q] = COMBO_ACTION(H_Q_combo),
    [HC_Q2] = COMBO_ACTION(H_Q2_combo),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),


    [PC_PENT] = COMBO(P3E_combo, KC_PENT), // <enter> on num
    [PC_BSPC] = COMBO(P01_combo, KC_BSPC), // <bksp> on num
    [PC_DEL] = COMBO(P02_combo, KC_DEL), // <del> on num
    [PC_TAB] = COMBO(PCM1_combo, KC_TAB), // <tab> on num

    // action combos below
    // This group have custom actions on trigger (no hold-delay), repeat if held
    [HC_2DQUO] = COMBO_ACTION(Hdquo_combo),
    [HC_2DBRC] = COMBO_ACTION(Hdbrc_combo),

    // this block should be contiguous,
    // Delayed action (COMBO_HOLD threshold). No repeat if held (tap_code)
    // should send the underlying combo keys if COMBO_HOLD is not met.

    // Keypad combos (all need actions or mods, so must be here)
    [PC_STAB] = COMBO_ACTION(PCM2_combo), // shift-<tab> on num
    [PC_TGNM] = COMBO_ACTION(PSLMN_combo), // toggle num layer
    
    [PC_SENT] = COMBO_ACTION(P2E_combo), // shift-<enter> on num
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
    [PC_CLR] = COMBO(P0E_combo, KC_C), // C for "CLEAR"
    [PC_AC] = COMBO(PCME_combo, KC_ESC), // ESC for "ALL CLEAR"
    [PC_PLMN] = COMBO_ACTION(PPLMN_combo), // ±

    [FC_ESC] = COMBO(F_ESC_combo, KC_ESC),  // ESCape
    [FC_MAC] = COMBO_ACTION(F_MAC_combo), // Set MAC OS env var
    [FC_WIN] = COMBO_ACTION(F_WIN_combo), // Set WIN OS env var
    [FC_KILL] = COMBO_ACTION(F_KILL_combo), // Force quit
    [FC_SCAP] = COMBO_ACTION(F_SCAP_combo), // SCREEN CAPTURE SELECTION
    [FC_SCLP] = COMBO_ACTION(F_SCLP_combo), // SCREEN CAPTURE SELECTION to clipboard
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    [HC_CAPS] = COMBO(H_CAPS_combo, KC_CAPS), // CAPS LOCK

// HANDSDOWN
    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_GRV] = COMBO_ACTION(Hgrv_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_RING] = COMBO_ACTION(Hring_combo), // ˚ ring
    [HC_ENYE] = COMBO_ACTION(Henye_combo), // ˜ enye
    [HC_ELIP] = COMBO_ACTION(Helip_combo),  // …
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL),  // =

    [HC_UM] = COMBO_ACTION(HUM_combo), // Ü
    [HC_OM] = COMBO_ACTION(HOM_combo), // Ö
    [HC_UK] = COMBO_ACTION(HUK_combo), // Ů
    [HC_OK] = COMBO_ACTION(HOK_combo), // O̊
    [HC_UV] = COMBO_ACTION(HUM_combo), // Û
    [HC_OV] = COMBO_ACTION(HOM_combo), // Ô
    [HC_UF] = COMBO_ACTION(HUK_combo), // Ú
    [HC_OF] = COMBO_ACTION(HOK_combo), // Ó


    [HC_TYPE_LM] = COMBO_ACTION(H_LM_combo),
    [HC_TYPE_TION] = COMBO_ACTION(H_tion_combo),
    [HC_TYPE_JAPAN] = COMBO_ACTION(H_Japan_combo),

//    [HC_APP] = COMBO(Happ_combo, KC_APP), // app menu
    [HC_ENT] = COMBO_ACTION(Hent_combo), // ENTER
    [HC_CLOSE] = COMBO_ACTION(Hclose_combo),
    [HC_QUIT] = COMBO_ACTION(Hquit_combo),
    [HC_FIND] = COMBO_ACTION(Hfind_combo), // Find the selection (COPY, FIND, PASTE)
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
            case HC_TYPE_TION:
                SEND_STRING("tion");
                break;
            case HC_TYPE_JAPAN:
                SEND_STRING("Japan"); // send "Japan" right away
                combo_on = combo_index; // may add "ese" in matrix_scan_user_process_combo
                break;
            case HC_Q:
            case HC_Q2:
                SEND_STRING("q"); // send "q" right away
                combo_on = combo_index; // may add "u" in matrix_scan_user_process_combo
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

                case HC_UM: // Ü
                    SEND_STRING("mu");
                    break;
                case HC_OM: // Ö
                    SEND_STRING("mo");
                    break;
                case HC_UK: // Ů
                    SEND_STRING("ku");
                    break;
                case HC_OK: // O̊
                    SEND_STRING("ko");
                    break;
                case HC_UV: // Û
                    SEND_STRING("vu");
                    break;
                case HC_OV: // Ô
                    SEND_STRING("vo");
                    break;
                case HC_UF: // Ú
                    SEND_STRING("fu");
                    break;
                case HC_OF: // Ó
                    SEND_STRING("fo");
                    break;

                case HC_TYPE_LM:
                    SEND_STRING("gm");
                    break;

                case HC_ENT:
                    SEND_STRING("bd");
                    break;
                case HC_SALL:
                    SEND_STRING("xd");
                    break;
                case HC_UNDO:
                    SEND_STRING("xg");
                    break;
                case HC_CUT:
                    SEND_STRING("xl");
                    break;
                case HC_COPY:
                    SEND_STRING("gl");
                    break;
                case HC_PSTE:
                    SEND_STRING("ld");
                    break;
                case HC_PSTM:
                    SEND_STRING("gd");
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
                    
                case HC_CLOSE:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        unregister_code16(C(KC_W));
                    } else {
                        unregister_code16(G(KC_W));
                    }
                    break;
                case HC_QUIT:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        unregister_code16(C(KC_Q));
                    } else {
                        unregister_code16(G(KC_Q));
                    }
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
extern uint8_t  saved_mods; // global, so we're not wasting time allocating...

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
        // if necessary (like releasing the underlying keys, or other cleanup)


        if (combo_on && (timer_elapsed(keyhold_timer) > COMBO_HOLD)) {
            switch(combo_on) {  // combo_on is global, set in process_combo above
                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_TGNM:
                    layer_on(L_LANG_NUM); // toggle num layer
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT));
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

                case HC_2DQUO: // "|"
                    tap_code16(A(KC_LBRC));
                    tap_code16(A(S(KC_LBRC)));
                    tap_code(KC_LEFT);
                    break;
                case HC_2DBRC: // [|]
                    tap_code16(KC_LBRC);
                    tap_code16(KC_RBRC);
                    tap_code(KC_LEFT);
                    break;

                case HC_ENYE:
                    tap_code16(A(KC_N));
                    break;
                case HC_ACUT:
                     tap_code16(A(KC_E));
                    break;
                case HC_GRV:
                     tap_code16(A(KC_GRV));
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
                case HC_RING:
                     tap_code16(A(KC_K));
                    break;

                case HC_UM: // Ü
                    tap_code16(A(KC_U));
                    tap_code16(KC_U);
                   break;
                case HC_OM: // Ö
                    tap_code16(A(KC_U));
                    tap_code16(KC_O);
                    break;
                case HC_UK: // Ů
                    tap_code16(A(KC_K));
                    tap_code16(KC_U);
                    break;
                case HC_OK: //
                    tap_code16(A(KC_K));
                    tap_code16(KC_O);
                    break;
                case HC_UV: // Û
                    tap_code16(A(KC_6));
                    tap_code16(KC_U);
                   break;
                case HC_OV: // Ô
                    tap_code16(A(KC_6));
                    tap_code16(KC_O);
                    break;
                case HC_UF: // Ú
                    tap_code16(A(KC_E));
                    tap_code16(KC_U);
                    break;
                case HC_OF: // Ó
                    tap_code16(A(KC_E));
                    tap_code16(KC_O);
                    break;

                case HC_TYPE_LM:
                    SEND_STRING("lm");
                    break;

                case HC_Q: // already "Q" has been sent; if held, add "u"
                case HC_Q2: // already "Q" has been sent; if held, add "u"
                    saved_mods = get_mods();
                    clear_mods(); //
                    SEND_STRING("u");
                    set_mods(saved_mods); //
                    break;
                case HC_TYPE_JAPAN: // already "Japan" has been sent; if held, add "ese"
                    SEND_STRING("ese ");
                    break;

                case HC_CLOSE:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        register_code16(C(KC_W));
                    } else {
                        register_code16(G(KC_W));
                    }
                    break;
                case HC_QUIT:
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        register_code16(C(KC_Q));
                    } else {
                        register_code16(G(KC_Q));
                    }
                    break;
                case HC_FIND: // Find the selection
                    if (user_config.osIsWindows) { // eventually this will be replaced with smart table lookup by platform (mac/ios, win, linux, vim, etc.)
                        tap_code16(C(KC_C));
                        tap_code16(C(KC_F));
                        tap_code16(C(KC_V));
                        tap_code16(C(KC_G));
                    } else {
                        tap_code16(G(KC_C));
                        tap_code16(G(KC_F));
                        tap_code16(G(KC_V));
                        tap_code16(G(KC_G));
                    }
                    break;
                case HC_ENT:
                    tap_code(KC_ENT);
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
        } //  if (combo_on) {
    }
}
