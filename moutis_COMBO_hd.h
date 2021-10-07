#define combo_OLED_row 5

#define EXTRA_SHORT_COMBOS // because I don't believ in big combos-use layers or leader_key

enum my_combos {
    FC_ESC, // ESCape SIMPLE COMBO must be first-used as FALSE for combo_on

    HC_EQL, // = equal
    HC_QUES, // ?
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
    QC_TAB,

    HC_J, // J is not on the map
    HC_Q, // Q is not on the map
    HC_Z, // Z is not on the map
    HC_Ch, // treat as digraph 'CH'
    HC_Ph, // treat as φ
    HC_Th, // treat as θ
    HC_Sh, // TYPE "sh"
    HC_Wh, // treat as digraph 'WH'
    HC_I, // Cap I + "'ve " if lingered
    HC_Id, // "I'd " …
    HC_Ill, // "I'll " …
    HC_Im, // "I'm " …

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
    HC_ing_3gram, // TYPE "ing"
//    HC_tion_4gram, // TYPE "tion" #1 // handled via adaptive keys
    HC_with_4gram, // TYPE "with" #5
    HC_ment_4gram, // TYPE "ment" #6
    HC_this_4gram, // TYPE "this" #8
    HC_here_4gram, // TYPE "here" #9
    HC_ould_4gram, // TYPE "ould" #11
    HC_ting_4gram, // TYPE "ting" #12
    HC_they_4gram, // TYPE "they" #23
    HC_ough_4gram, // TYPE "ough" #25


    HC_their_5gram, // TYPE "their" #6
    HC_there_5gram, // TYPE "there" #7
    HC_where_5gram, // TYPE "where"
    HC_theyre_7gram, // TYPE "they're"
    
    HC_TYPE_JAPAN, // TYPE "Japan" and hold for "ese"
    HC_CAPSWORD, // CAPS WORD
    FC_CAPS, // CAPS LOCK

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
    
    MYMACRO,

    HC_2DQUO, // "|" insertion point between double quotes

    HC_ENYE, // ~ enye
    HC_ACUT, // ´ acute
    HC_CIRC, // ˆ circumflex
    HC_MACR, // - macron
    HC_DIER, // ¨ dieresis
    HC_RING, // ˚ ring
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
