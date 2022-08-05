#define combo_OLED_row 5

#define EXTRA_SHORT_COMBOS // because I don't believ in big combos-use layers or leader_key

enum my_combos {
    FC_ESC, // ESCape SIMPLE COMBO must be first-used as FALSE for combo_on
    HC_APP,
    HC_CAPW, // CAPS WORD for all others
    FC_CAPS, // CAPS LOCK (others)
    FC_LANG2, // eisuu (others)
    FC_LANG1_1, // kana (others)
    FC_LANG1_2, // kana (others)

    HC_TAB1,
    HC_TAB2,
    HC_EQL, // = equal
    HC_QUES, // ?
    HC_EXLM, // !
    HC_SCLN, // ;
    HC_UNDS, // _ underscore
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_TIC, // ` tic (not a dead key)
    HC_ACUT, // ´ acute
    HC_GRV, // ` grave (dead key)
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_RING, // ˚ ring
    HC_CEDILLE, // ¸ cedille
    HC_ENYE, // ñ/Ñ enye
    HC_AE, // æ/Æ
//    HC_OSLSH, // ø/Ø

//    HC_J, // J is not on the map
    HC_Q, // Q is not on the map
    HC_Z, // Z is not on the map
//    HC_NG, // japanese ん Done in Japanese mode on enye

    
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

    HC_AT, // @
    HC_COLN, // :
    // Fast entry 4grams
    // since combos are a bit slower,
    // needs to be a 4gram+ or more to be worth it
    HC_Ch, // treat as digraph 'CH'
    HC_Ch2, // treat as digraph 'CH'
    HC_Sch1, // treat as digraph 'SCH'
    HC_Sch2, // treat as digraph 'SCH'
//    HC_Tch1, // treat as digraph 'TCH'
//    HC_Tch2, // treat as digraph 'TCH'
    HC_Gh, // treat as digraph 'GH'
    HC_Ph, // treat as φ
    HC_Th, // treat as θ
    HC_Sh, // TYPE "sh"
    HC_Wh2, // treat as digraph 'WH'
    HC_Wh, // treat as digraph 'WH'

#ifdef EN_PRONOUN_COMBOS
// Pronoun combos. KEEP these together!
    HC_I, // Cap I + "'ve " if lingered
    HC_Id, // "I'd " …
    HC_Ill, // "I'll " …
    HC_Im, // "I'm " …
    HC_Iv, // "I've " …

#ifdef EN_PRONOUN_COMBOS_ALL
    HC_wed_4gram, // we'd
    HC_well_5gram, // we'll
    HC_were_5gram, // we're
    HC_weve_5gram, // we've

    HC_youd_5gram,
    HC_youll_6gram,
    HC_youre_6gram,
    HC_youve_6gram,
    HC_your_4gram,

    HC_they_4gram, // TYPE "they" #23
    HC_theyd_6gram, // TYPE "they'd " #23
    HC_theyll_7gram, // TYPE "they'll" #23
    HC_theyre_7gram, // "they're"
    HC_theyve_7gram, // "they've"
    HC_their_5gram, // "their" #6

    HC_there_5gram, // "there" #7
    HC_here_4gram, // TYPE "here" #9
    HC_where_5gram, // TYPE "where"

// END of PRONOUN combos ()
#endif // EN_PRONOUN_COMBOS_ALL
#endif // EN_PRONOUN_COMBOS

//    HC_ing_3gram, // TYPE "ing" // #3 of 3-grams, #62 of all n-grams, 80% of "ng" bigrams
//    HC_thing_5gram, // TYPE "thing" // worth it?
/*
    HC_with_4gram, // TYPE "with" #5
    HC_ment_4gram, // TYPE "ment" #6
    HC_ting_4gram, // TYPE "ting" #12
    HC_ough_4gram, // TYPE "ough" #25

    HC_ould_4gram, // TYPE "ould" #11
*/

// Japanese contract consonants.

#ifdef JP_MODE_ENABLE  // Japanese mode switching
#ifdef JP_YOUON_COMBOS  // Japanese contracted sounds as combos
/*
    jp_ya, // ゃ this is a row "push" so is this easier?
    jp_yu, // ゅ
    jp_yo, // ょ
*/
    jp_kya,  // きゃ
    jp_kyu,  // きゅ
    jp_kyo,  // きょ
    jp_sya,  // しゃ
    jp_syu,  // しゅ
    jp_sye,  // しぇ
    jp_syo,  // しょ
    jp_zya,  // じゃ
    jp_zyu,  // じゅ
    jp_zyo,  // じょ
    jp_tya,  // ちゃ
    jp_tyu,  // ちゅ
    jp_tye,  // ちぇ
    jp_tyo,  // ちょ
    jp_pya,  // ぴゃ
    jp_pyu,  // ぴゅ
    jp_pyo,  // ぴょ
#ifdef JP_YOUON_COMBOS_ALL
    jp_aa,  // アー
    jp_ii,  //　イー
    jp_uu,  //　ウー
    jp_ee,  //　エー
    jp_oo,  //　オー
    jp_nn,  //　ン

    jp_gya,  // ぎゃ
    jp_gyu,  // ぎゅ
    jp_gyo,  // ぎょ
    jp_tha,  // てゃ
    jp_thi,  // てぃ
    jp_thu,  // てょ
    jp_the,  // てぇ
    jp_tho,  // てょ
    jp_dha,  // でゃ
    jp_dhi,  // でぃ
    jp_dhu,  // でょ
    jp_dhe,  // でぇ
    jp_dho,  // でょ
    jp_nya,  // にゃ
    jp_nyu,  // にゅ
    jp_nyo,  // にょ
//    jp_hya,  // ひゃ
    jp_hyu,  // ひゅ
    jp_hyo,  // ひょ
    jp_bya,  // びゃ
    jp_byu,  // びゅ
    jp_byo,  // びょ
    jp_mya,  // みゃ
    jp_myu,  // みゅ
    jp_myo,  // みょ
    jp_rya,  // りゃ
    jp_ryu,  // りゅ
    jp_ryo,  // りょ
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_YOUON_COMBOS
#endif // JP_MODE_ENABLE

// END Japanese contract consonants.

    //
    // DELAYED ACTION COMBOS -- this block must be contiguous
    //
    // no action on press, action (in matrix_scan_user),
    // underlying keys if the hold threshold is not met.
    // may repeat if appropriate. (tap_code vs register_code)
    //
    PC_STAB,  // Shift-<tab>
    PC_TGNM, // TOGGLE NUMLCK on numpad layer
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
    
    HC_TYPE_ENGLISH, // TYPE "English" and hold for "End of times in 2020"
    HC_TYPE_JAPAN, // TYPE "Japan" and hold for "ese"

    //    HC_2DQUO, // "|" insertion point between double quotes

/*
    HC_UM, // Ü
    HC_OM, // Ö
    HC_UK, // Ů
    HC_OK, // O̊
    HC_UV, // Û
    HC_OV, // Ô
    HC_UF, // Ú
    HC_OF, // Ó

    HC_1E, // É
    HC_2E, // Ē
    HC_3E, // Ê
*/
    // THESE ALL USE SemKeys for platform independence
    FC_KILL, // Force quit
    FC_SCAP, // Screen Capture Selection
    FC_SCLP, // Screen Capture Selection to clipboard

    HC_ENT,
    HC_ENT2, // hard enter (cmd/ctrl-enter)
    HC_SPC,
    HC_CLOZ,
    HC_QUIT,
    HC_FIND, // Find the selection
    HC_SALL,

    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
    HC_PSTM,


    COMBO_LENGTH // END OF DELAY BLOCK
};
