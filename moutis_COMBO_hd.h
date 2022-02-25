#define combo_OLED_row 5

#define EXTRA_SHORT_COMBOS // because I don't believ in big combos-use layers or leader_key

enum my_combos {
    FC_ESC, // ESCape SIMPLE COMBO must be first-used as FALSE for combo_on

    HC_EQL, // = equal
    HC_QUES, // ?
    HC_QUESg, // ?
    HC_EXLM, // !
    HC_AT, // @
    HC_SCLN, // ;
    HC_COLN, // :
    HC_UNDS, // _ underscore
    HC_NDSH, // – N-dash
    HC_MDSH, // — M-dash
    HC_TILD, // ~ tilde
    HC_TIC, // ` tic (not a dead key)
    HC_GRV, // ` grave (dead key)
    HC_TAB,
    HC_TABt, // tab for Titanium

//    HC_J, // J is not on the map
    HC_Q, // Q is not on the map
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

    // Fast entry 4grams
    // since combos are a bit slower,
    // needs to be a 4gram+ or more to be worth it
    HC_Ch, // treat as digraph 'CH'
    HC_Chg, // treat as digraph 'CH' (for Neu-tx/rx a.k.a Gold/Titanium)
    HC_Gh, // treat as digraph 'GH'
    HC_Ph, // treat as φ
    HC_Th, // treat as θ
//    HC_Ths, // treat as θ (for Neu-nx a.k.a Silver)
//    HC_Thg, // treat as θ (for Neu-tx a.k.a Gold)
    HC_Sh, // TYPE "sh"
//    HC_Shs, // TYPE "sh" (for Neu-nx a.k.a Silver)
    HC_Whg, // treat as digraph 'WH'
    HC_Wh, // treat as digraph 'WH'

    // Pronoun combos. KEEP these together!
    

    HC_I, // Cap I + "'ve " if lingered
    HC_Id, // "I'd " …
    HC_Ill, // "I'll " …
    HC_Im, // "I'm " …
    HC_Iv, // "I've " …

    HC_Ig, // Cap I + "'ve " if lingered for Gold/Neu
    HC_Idg, // "I'd " … for Gold/Neu
    HC_Illg, // "I'll " … for Gold/Neu
    HC_Img, // "I'm " … for Gold/Neu
    HC_Ivg, // "I've " … for Gold/Neu

    HC_wed_4gram, // we'd
    HC_well_5gram, // we'll
    HC_were_5gram, // we're
    HC_weve_5gram, // we've
    HC_youd_5gram,
    HC_youdg_5gram,
    HC_youll_6gram,
    HC_youre_6gram,
    HC_youve_6gram,
    HC_your_4gram,
    HC_they_4gram, // TYPE "they" #23
//    HC_theyg_4gram, // TYPE "they" #23
    HC_theyd_6gram, // TYPE "they'd " #23
//    HC_theydg_6gram, // TYPE "they'd " #23
    HC_theyll_7gram, // TYPE "they'll" #23
//    HC_theyllg_7gram, // TYPE "they'll" #23
    HC_theyre_7gram, // "they're"
//    HC_theyreg_7gram, // "they're" for Gold/Neu
    HC_theyve_7gram, // "they've"
//    HC_theyveg_7gram, // "they've"
    HC_there_5gram, // "there" #7
    HC_thereg_5gram, // "there" #7 for Gold/Neu
    HC_their_5gram, // "their" #6
//    HC_theirg_5gram, // "their" #6 for Gold/Neu
//    HC_this_4gram, // TYPE "this" #8
    HC_here_4gram, // TYPE "here" #9
    HC_hereg_4gram, // TYPE "here" #9 for Gold/Neu
    HC_whereg_5gram, // TYPE "where"
    HC_where_5gram, // TYPE "where"

// END of PRONOUN combos ()

    HC_ing_3gram, // TYPE "ing"
//    HC_tion_4gram, // TYPE "tion" #1 // handled via hold combo Th
    HC_with_4gram, // TYPE "with" #5
//    HC_withg_4gram, // TYPE "with" #5
    HC_ment_4gram, // TYPE "ment" #6
    HC_ould_4gram, // TYPE "ould" #11
    HC_ting_4gram, // TYPE "ting" #12
    HC_ough_4gram, // TYPE "ough" #25
    HC_oughg_4gram, // TYPE "ough" #25



    HC_CAPW, // CAPS WORD for all others
    FC_CAPS, // CAPS LOCK (others)
    FC_LANG2, // eisuu (others)
    FC_LANG1, // kana (others)
//    HC_CAPG, // CAPS WORD for Gold
//    FC_CAPG, // CAPS LOCK (Gold)
    FC_LANG1g, // kana (neu/Gold)
//    FC_LANG2g, // eisuu (neu/Gold)
    FC_LANG2q, // eisuu (QWERTY)
    FC_LANG1q, // kana (QWERTY)

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

    HC_ACUT, // ´ acute
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_ENYE, // ñ/Ñ enye
//    HC_RING, // ˚ ring
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
    HC_ENTg,
    HC_SPC,
    HC_SPCg,
    HC_CLOZ,
//    HC_CLOZg,
    HC_QUIT,
//    HC_QUITg,
    HC_FIND, // Find the selection
    HC_SALL,
//    HC_SALLg,

    HC_UNDO,
    HC_CUT,
    HC_COPY,
    HC_PSTE,
//    HC_PSTEg,
//    HC_PSTMg,
    HC_PSTM,

    COMBO_LENGTH // END OF DELAY BLOCK
};
