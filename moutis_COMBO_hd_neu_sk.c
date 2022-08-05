/*
 Combos
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 Tailored for Hands Down Neu-rx a.k.a. Rhodium
 Others have been removed, but I'll try to get everything in here soon enough.
 Finally getting to the last of imagined features that spurred Hands Down design!
  
 */


#define JapanComboTapE "Japan "
#define JapanComboHeldE "Japanese "
#define JapanComboTapJ "arigatou"
#define JapanComboHeldJ "yorosiku"
#define EnglishComboTapE "English "
#define EnglishComboHeldE "End of times in 2020"
#define EnglishComboTapJ "gozaimasu."
#define EnglishComboHeldJ "onegaisimasu."

uint16_t COMBO_LEN = COMBO_LENGTH;

// for 34 key boards
const uint16_t PROGMEM H_menu_combo[] = {LT(4, KC_BSPC), LT(6, KC_R), COMBO_END}; // MENU

/* examples of text entry combos */
const uint16_t PROGMEM H_Japan_combo[] = {KC_G, KC_M, KC_P, COMBO_END}; // TYPE EnglishComboTapE
const uint16_t PROGMEM H_English_combo[] = {KC_DOT, KC_SLSH, KC_DQUO, COMBO_END}; // some demonstrator macro placeholder

const uint16_t PROGMEM F_ESC_combo[] = {KC_X, KC_K, COMBO_END}; // ESCape
const uint16_t PROGMEM F_KILL_combo[] = {KC_X, KC_V, COMBO_END}; // KILL = Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCLP_combo[] = {KC_J, KC_G, KC_P, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_J, KC_G, KC_V, COMBO_END}; //  SCREEN shot SELECTION to file


const uint16_t PROGMEM F_CAPS_combo[] = {KC_D, KC_U, COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_CAPW_combo[] = {LSFT_T(KC_T), RSFT_T(KC_A), COMBO_END}; // CAPS WORD (on until word delimiter)
const uint16_t PROGMEM H_EISUU_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // KC_MHEN
#ifdef HD_BRONZE   // for Bronze/Ag/Pl
const uint16_t PROGMEM H_KANA_combo[] = {RALT_T(KC_C), RGUI_T(KC_E), RSFT_T(KC_A), COMBO_END}; // KC_HENK
#else // for Neu/Au/Ti
const uint16_t PROGMEM H_KANA_combo[] = {RALT_T(KC_I), RGUI_T(KC_E), RSFT_T(KC_A), COMBO_END}; // KC_HENK
#endif

//  (22) keypad combos
const uint16_t PROGMEM PNLCK_combo[] = {KC_P4, KC_P5, KC_P6, COMBO_END}; // toggle numlck from num layer
const uint16_t PROGMEM P0E_combo[] = {KC_P0, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCME_combo[] = {KC_PDOT, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCM1_combo[] = {KC_PDOT, KC_P1, COMBO_END};
const uint16_t PROGMEM PCM2_combo[] = {KC_PDOT, KC_P2, COMBO_END};
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

const uint16_t PROGMEM Hndsh_combo[] = {KC_MINS, KC_U, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {KC_MINS, KC_O, COMBO_END}; // — m dash
#ifdef HD_BRONZE  // for Bronze/Ag/Pl
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_Y, COMBO_END}; // _ underscore
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_Y, COMBO_END}; // ~ tilde (not the dead one)
const uint16_t PROGMEM Hequal_combo[] = {KC_MINS, KC_W, COMBO_END}; // = equal
#else  // for Neu/Au/Ti
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_W, COMBO_END}; // _ underscore
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_W, COMBO_END}; // ~ tilde (not the dead one)
const uint16_t PROGMEM Hequal_combo[] = {KC_MINS, KC_Y, COMBO_END}; // = equal
#endif
const uint16_t PROGMEM Hscln_combo[] = {LT(4, KC_COMM), RSFT_T(KC_A), COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {KC_HASH, KC_DOT, COMBO_END}; // : colon

// spatially arranged characters and diacritics
const uint16_t PROGMEM Hexlm_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // !
#ifdef HD_BRONZE   // for Bronze/Ag/Pl
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_QUOT, COMBO_END}; //
#else // for Neu/Au/Ti
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_DQUO, COMBO_END}; //
#endif
const uint16_t PROGMEM Hat_combo[] = {KC_P, KC_V, COMBO_END}; // @
const uint16_t PROGMEM Helip_combo[] = {KC_HASH, KC_SLSH, COMBO_END}; // … elipses
const uint16_t PROGMEM Htic_combo[] = {KC_DQUO, KC_QUOT, COMBO_END}; // ` tic (not dead key grave)

// spatially arranged diacritics
const uint16_t PROGMEM Hacut_combo[] = {RSFT_T(KC_A), RGUI_T(KC_E), COMBO_END}; // ´ acute (dead key)
const uint16_t PROGMEM Hdier_combo[] = {KC_U, KC_O, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Henye_combo[] = {KC_G, KC_P, COMBO_END}; // ˜ enye (dead key) (ñ only?)
#ifdef HD_BRONZE  // for Bronze/Ag/Pl
const uint16_t PROGMEM Hmacr_combo[] = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {RSFT_T(KC_A), RCTL_T(KC_H), COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hring_combo[] = {LCTL_T(KC_C), LSFT_T(KC_T), COMBO_END}; // ˚ ring (dead key)
#else // for Neu/Au/Ti
const uint16_t PROGMEM Hmacr_combo[] = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {RGUI_T(KC_E), RALT_T(KC_I), COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {RSFT_T(KC_A), RCTL_T(KC_H), COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hring_combo[] = {RGUI_T(KC_E), RCTL_T(KC_H), COMBO_END}; // ˚ ring (dead key)
#endif

// TEXT ENTRY - off map standard alphas
//const uint16_t PROGMEM H_J_combo[] = {KC_P, KC_V, COMBO_END}; // TYPE "j"
const uint16_t PROGMEM H_Z_combo[] = {KC_J, KC_G, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Q_combo[] = {KC_U, KC_Y, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_NG_combo[] = {KC_W, KC_Y, COMBO_END}; // TYPE "ん"

// H digraphs
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
const uint16_t PROGMEM H_Wh_combo[] = {KC_O, KC_W, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Ch_combo[] = {RALT_T(KC_C), RGUI_T(KC_C), COMBO_END}; // TYPE "ch"
#else  // for HD Neu/Au/Ti
const uint16_t PROGMEM H_Wh_combo[] = {KC_O, KC_Y, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Ch_combo[] = {LALT_T(KC_S), LSFT_T(KC_T), COMBO_END}; // TYPE "ch"
#endif
const uint16_t PROGMEM H_Ph_combo[] = {KC_M, KC_P, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "gh"
const uint16_t PROGMEM H_Sh_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), COMBO_END}; // "sh"
const uint16_t PROGMEM H_Th_combo[] = {LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // "th"

// TEXT ENTRY - (ANY ROW/ MIXED ROWS)

/*
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
const uint16_t PROGMEM H_ing_combo[] = {RCTL_T(KC_I), KC_G, COMBO_END}; // TYPE "ing" only a 3gram, worth it?
#else  // for HD Neu/Au/Ti
const uint16_t PROGMEM H_ing_combo[] = {RALT_T(KC_I), KC_G, COMBO_END}; // TYPE "ing" only a 3gram, worth it?
#endif
*/

// Fast 4grams
/*
const uint16_t PROGMEM H_ould_combo[] = {KC_O, KC_D, COMBO_END}; // "ould" #11

#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
const uint16_t PROGMEM H_with_combo[] = {KC_W, RCTL_T(KC), COMBO_END}; // "with" #5 for Gold/Neu
const uint16_t PROGMEM H_ment_combo[] = {KC_M, LSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_ting_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_ough_combo[] = {KC_O, RCTL_T(KC_H), COMBO_END}; // "ough" #25 for Gold/Neu
#else  // for HD Neu/Au/Ti
const uint16_t PROGMEM H_with_combo[] = {KC_W, RCTL_T(KC_H), COMBO_END}; // "with" #5 for Gold/Neu
const uint16_t PROGMEM H_ment_combo[] = {KC_M, LSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_ting_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_ough_combo[] = {KC_O, RCTL_T(KC_H), COMBO_END}; // "ough" #25 for Gold/Neu
#endif
*/

// PRONOUNS Fast 4-7grams

#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
const uint16_t PROGMEM H_Icap_combo[] = {RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I" for Gold/Neuh
const uint16_t PROGMEM H_Id_combo[] = {KC_D, RCTL_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Ill_combo[] = {KC_L, RCTL_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Im_combo[] = {KC_M, RCTL_T(KC_I), COMBO_END}; // TYPE "I'm " for Gold/Neu
const uint16_t PROGMEM H_Iv_combo[] = {KC_V, RCTL_T(KC_I), COMBO_END}; // TYPE "I've " for Gold/Neu
#else  // for HD Neu/Au/Ti
const uint16_t PROGMEM H_Icap_combo[] = {RALT_T(KC_I), RCTL_T(KC_H), COMBO_END}; // TYPE "I" for Gold/Neuh
const uint16_t PROGMEM H_Id_combo[] = {KC_D, RALT_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Ill_combo[] = {KC_L, RALT_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Im_combo[] = {KC_M, RALT_T(KC_I), COMBO_END}; // TYPE "I'm " for Gold/Neu
const uint16_t PROGMEM H_Iv_combo[] = {KC_V, RALT_T(KC_I), COMBO_END}; // TYPE "I've " for Gold/Neu
#endif

const uint16_t PROGMEM H_there_combo[] = {LSFT_T(KC_T), LT(L_NAV,KC_R), COMBO_END}; // TYPE "there" #7
const uint16_t PROGMEM H_here_combo[] = {RCTL_T(KC_H), LT(L_NAV,KC_R), COMBO_END}; // TYPE "here" #5
const uint16_t PROGMEM H_where_combo[] = {KC_W, LT(L_NAV,KC_R), COMBO_END}; // "where"

const uint16_t PROGMEM H_wed_combo[] = {KC_W, KC_D, COMBO_END}; // TYPE "we'd" we'll
const uint16_t PROGMEM H_well_combo[] = {KC_W, KC_L, COMBO_END}; // TYPE "we'll" we're
const uint16_t PROGMEM H_were_combo[] = {KC_W, KC_J, COMBO_END}; // TYPE "we're"
const uint16_t PROGMEM H_weve_combo[] = {KC_W, KC_V, COMBO_END}; // TYPE "we've"
const uint16_t PROGMEM H_youd_combo[] = {KC_Y, LSFT_T(KC_D), COMBO_END}; // TYPE "you'd"
const uint16_t PROGMEM H_youll_combo[] = {KC_Y, KC_L, COMBO_END}; // TYPE "you'll"
const uint16_t PROGMEM H_youre_combo[] = {KC_Y, KC_J, COMBO_END}; // TYPE "you're"
const uint16_t PROGMEM H_youve_combo[] = {KC_Y, KC_V, COMBO_END}; // TYPE "you've"
const uint16_t PROGMEM H_your_combo[] = {KC_Y, KC_X, COMBO_END}; // TYPE "your"
const uint16_t PROGMEM H_their_combo[] = {LSFT_T(KC_T), KC_X, COMBO_END}; // TYPE "their" #6
const uint16_t PROGMEM H_they_combo[] = {LSFT_T(KC_T), KC_Y, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyd_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyll_combo[] = {LSFT_T(KC_T), KC_L, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyre_combo[] = {LSFT_T(KC_T), KC_J, COMBO_END}; // "they're"

// UPPER ROW

// FUNCTIONS/COMMANDS Spatially arranged

const uint16_t PROGMEM Htab_combo[] = {LCTL_T(KC_C), LALT_T(KC_S), COMBO_END}; // tab 
const uint16_t PROGMEM Hspc_combo[] = {LSFT_T(KC_T), LT(5,KC_B), COMBO_END}; // SPACE
const uint16_t PROGMEM Hent_combo[] = {KC_D, KC_K, COMBO_END}; // ENTER

// LOWER ROW

// SEMANTIC FUNCTIONS Spatially arranged  ** uses SemKeys **
const uint16_t PROGMEM Hclose_combo[] = {KC_L, KC_K, COMBO_END}; // close
const uint16_t PROGMEM Hquit_combo[] = {KC_F, KC_K, COMBO_END}; // quit
const uint16_t PROGMEM Hfind_combo[] = {KC_G, KC_V, COMBO_END}; // find
const uint16_t PROGMEM Hsall_combo[] = {KC_X, KC_D, COMBO_END}; // select all
const uint16_t PROGMEM Hundo_combo[] = {KC_X, KC_F, COMBO_END}; // undo
const uint16_t PROGMEM Hcut_combo[] = {KC_X, KC_L, COMBO_END}; // cut
const uint16_t PROGMEM Hcopy_combo[] = {KC_F, KC_L, COMBO_END}; // copy
const uint16_t PROGMEM Hpste_combo[] = {KC_L, KC_D, COMBO_END}; // paste
const uint16_t PROGMEM Hpstm_combo[] = {KC_F, KC_D, COMBO_END}; // paste-match
// TWO HANDS

/*
 // Major diacritic combos will use SemKeys for platform independance
 // revisit this for Polyglot (will cause some conflict w/some
 // data entry combos above. Rethink combo vs adaptive considerations)
const uint16_t PROGMEM HUM_combo[] = {KC_F, KC_U, COMBO_END};  // Ü
const uint16_t PROGMEM HOM_combo[] = {KC_F, KC_O, COMBO_END};  // Ö
const uint16_t PROGMEM HUK_combo[] = {KC_L, KC_U, COMBO_END};  // Ů
const uint16_t PROGMEM HOK_combo[] = {KC_L, KC_O, COMBO_END};  // O̊
const uint16_t PROGMEM HUV_combo[] = {KC_P, KC_U, COMBO_END};  // Û
const uint16_t PROGMEM HOV_combo[] = {KC_P, KC_O, COMBO_END};  // Ô
const uint16_t PROGMEM HUF_combo[] = {KC_V, KC_U, COMBO_END};  // Ú
const uint16_t PROGMEM HOF_combo[] = {KC_V, KC_O, COMBO_END};  // Ó

const uint16_t PROGMEM HGRAV_E_combo[] = {LT(L_LANG_NUM, KC_T), KC_E, COMBO_END};  // É
const uint16_t PROGMEM HACUT_E_combo[] = {LGUI_T(KC_N), KC_E, COMBO_END};  // Ê
const uint16_t PROGMEM HDIER_E_combo[] = {LCTL_T(KC_S), KC_E, COMBO_END};  // Ë
const uint16_t PROGMEM HRING_E_combo[] = {LALT_T(KC_R), KC_E, COMBO_END};  // E̊
const uint16_t PROGMEM HMACR_E_combo[] = {KC_M, KC_E, COMBO_END};  // Ē
*/


combo_t key_combos[] = {
    // These simple combos trigger on press, repeat.
    [HC_APP] = COMBO(H_menu_combo, KC_APP), // app menu
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL), // =
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO(Hcoln_combo, KC_COLN), // :
    [HC_UNDS] = COMBO(Hunds_combo, KC_UNDS), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~ or SK_TILD?
    [HC_TIC] = COMBO(Htic_combo, KC_GRV),  // `
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_AT] = COMBO(Hat_combo, KC_AT), // @
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),

    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_NG] = COMBO_ACTION(H_NG_combo),
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
    [HC_Gh] = COMBO_ACTION(H_Gh_combo),
    [HC_Ph] = COMBO_ACTION(H_Ph_combo),
    [HC_Th] = COMBO_ACTION(H_Th_combo),
    [HC_Sh] = COMBO_ACTION(H_Sh_combo),
    [HC_Wh] = COMBO_ACTION(H_Wh_combo),

    [PC_PENT] = COMBO(P3E_combo, KC_PENT), // <enter> on num
    [PC_BSPC] = COMBO(P01_combo, KC_BSPC), // <bksp> on num
    [PC_DEL] = COMBO(P02_combo, KC_DEL), // <del> on num
    [PC_TAB] = COMBO(PCM1_combo, KC_TAB), // <tab> on num

    // action combos below
    // This group have custom actions on trigger (no hold-delay), repeat if held

    // this block should be contiguous,
    // Delayed action (COMBO_HOLD threshold). No repeat if held (tap_code)
    // should send the underlying combo keys if COMBO_HOLD is not met.

    // Keypad combos (all need actions or mods, so must be here)
    [PC_STAB] = COMBO_ACTION(PCM2_combo), // shift-<tab> on num
    
    [PC_SENT] = COMBO_ACTION(P2E_combo), // shift-<enter> on num
    [PC_TGNM] = COMBO(PNLCK_combo, KC_NLCK), // toggle num lock
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
    [FC_KILL] = COMBO(F_KILL_combo, SK_KILL), // Force quit
    [FC_SCAP] = COMBO(F_SCAP_combo, SK_SCAP), // SCREEN CAPTURE SELECTION
    [FC_SCLP] = COMBO(F_SCLP_combo, SK_SCLP), // SCREEN CAPTURE SELECTION to clipboard
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    [HC_CAPW] = COMBO_ACTION(H_CAPW_combo), // CAPS_WORD

    [FC_LANG2] = COMBO(H_EISUU_combo, KC_MHEN), // eisuu (others)
    [FC_LANG1] = COMBO(H_KANA_combo, KC_HENK), // kana (others)

    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_GRV] = COMBO_ACTION(Hgrv_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_RING] = COMBO_ACTION(Hring_combo), // ˚ ring
    [HC_ENYE] = COMBO(Henye_combo, SK_ENYE), // ñ/Ñ enye
    [HC_ELIP] = COMBO_ACTION(Helip_combo),  // …

/* These will need to be handled by SemKeys w/unicode support
    [HC_UM] = COMBO_ACTION(HUM_combo), // Ü
    [HC_OM] = COMBO_ACTION(HOM_combo), // Ö
    [HC_UK] = COMBO_ACTION(HUK_combo), // Ů
    [HC_OK] = COMBO_ACTION(HOK_combo), // O̊
    [HC_UV] = COMBO_ACTION(HUM_combo), // Û
    [HC_OV] = COMBO_ACTION(HOM_combo), // Ô
    [HC_UF] = COMBO_ACTION(HUK_combo), // Ú
    [HC_OF] = COMBO_ACTION(HOK_combo), // Ó

    [HC_1E] = COMBO_ACTION(H1E_combo), // É
    [HC_2E] = COMBO_ACTION(H2E_combo), // Ē
    [HC_3E] = COMBO_ACTION(H3E_combo), // Ê
*/

// Fast entry 4grams
/* not sure these are worth it
    [HC_ing_3gram] = COMBO_ACTION(H_ing_combo), // TYPE "ing"
    [HC_with_4gram] = COMBO_ACTION(H_with_combo), // TYPE "with" #5
    [HC_ment_4gram] = COMBO_ACTION(H_ment_combo), // TYPE "ment" #6
    [HC_ting_4gram] = COMBO_ACTION(H_ting_combo), // TYPE "ting" #12
    [HC_ough_4gram] = COMBO_ACTION(H_ough_combo), // TYPE "ough" #25
    [HC_ould_4gram] = COMBO_ACTION(H_ould_combo), // TYPE "ould" #11
*/

// PRONOUNS Fast entry 4-7gram PRONOUNS (an English quirk)
    [HC_I] = COMBO_ACTION(H_Icap_combo),// TYPE "I"+"'ve "
    [HC_Id] = COMBO_ACTION(H_Id_combo),// TYPE "I'd "
    [HC_Ill] = COMBO_ACTION(H_Ill_combo),// TYPE "I'll "
    [HC_Im] = COMBO_ACTION(H_Im_combo),// TYPE "I'm  "
    [HC_Iv] = COMBO_ACTION(H_Iv_combo),// TYPE "I've  "
    [HC_wed_4gram] = COMBO_ACTION(H_wed_combo),// TYPE "we'd"
    [HC_well_5gram] = COMBO_ACTION(H_well_combo),// TYPE "we'll"
    [HC_were_5gram] = COMBO_ACTION(H_were_combo),// TYPE "we're"
    [HC_weve_5gram] = COMBO_ACTION(H_weve_combo),// TYPE "we've"
    [HC_youd_5gram] = COMBO_ACTION(H_youd_combo),// TYPE "you'd"
    [HC_youll_6gram] = COMBO_ACTION(H_youll_combo),// TYPE "you'll"
    [HC_youre_6gram] = COMBO_ACTION(H_youre_combo),// TYPE "you're"
    [HC_youve_6gram] = COMBO_ACTION(H_youve_combo),// TYPE "you've"
    [HC_your_4gram] = COMBO_ACTION(H_your_combo),// TYPE "your"
    [HC_there_5gram] = COMBO_ACTION(H_there_combo), // TYPE "there" #7
    [HC_they_4gram] = COMBO_ACTION(H_they_combo), // TYPE "they" #23
    [HC_their_5gram] = COMBO_ACTION(H_their_combo), // TYPE "their" #6
    [HC_theyre_7gram] = COMBO_ACTION(H_theyre_combo), // TYPE "they're"
    [HC_here_4gram] = COMBO_ACTION(H_here_combo), // TYPE "here" #9
    [HC_where_5gram] = COMBO_ACTION(H_where_combo), // TYPE "where"


/* Maybe not worth the possible misfire (delay combo only)?
    [HC_people_6gram] = COMBO_ACTION(H_people_combo), // TYPE "people" #23
    [HC_present_7gram] = COMBO_ACTION(H_present_combo), // TYPE "present" #1
    [HC_through_7gram] = COMBO_ACTION(H_through_combo), // TYPE "through" #3
    [HC_between_7gram] = COMBO_ACTION(H_between_combo), // TYPE "between" #4
*/

    [HC_TYPE_JAPAN] = COMBO_ACTION(H_Japan_combo), // a personally useful 5-8gram!
    [HC_TYPE_ENGLISH] = COMBO_ACTION(H_English_combo), // a demonstrator, how long autotypes can be!

    [HC_SPC] = COMBO(Hspc_combo, KC_SPC), // SPACE
    [HC_ENT] = COMBO(Hent_combo, KC_ENT), // ENTER

/* These all use SemKeys, even as simple combos (handled by process_semkey from process_record_user) */
    [HC_CLOZ] = COMBO(Hclose_combo, SK_CLOZ),
    [HC_QUIT] = COMBO(Hquit_combo, SK_QUIT),
    [HC_FIND] = COMBO(Hfind_combo, SK_FIND),
    [HC_SALL] = COMBO(Hsall_combo, SK_SALL),
    [HC_UNDO] = COMBO(Hundo_combo, SK_UNDO),
    [HC_CUT] = COMBO(Hcut_combo, SK_CUT),
    [HC_COPY] = COMBO(Hcopy_combo, SK_COPY),
    [HC_PSTE] = COMBO(Hpste_combo, SK_PSTE),
    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM)

    
};

void process_combo_event(uint16_t combo_index, bool pressed) {

#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, combo_OLED_row);
#endif
    if (pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_write_P(PSTR("Combo: "), false);
#endif
        switch(combo_index) {
            case PC_STAB ... COMBO_LENGTH:// these have a hold delay BEFORE triggering
            case HC_Ch ... HC_Wh:   // The H digraphs determined on up event, or may process a hold, so
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

//            case HC_CAPG: // turn on capsword for Gold
            case HC_CAPW: // turn on capsword (automatically turns off on delimiter)
                toggle_caps_word();
                break;

            case HC_NG: //
                if (user_config.AdaptiveKeys && (myKC_C == KC_C)) { // if Adaptives in English mode
                    if ((prior_keycode >= KC_SPC) && (prior_keycode <= KC_TILD)) // ASCII printable? (expand this?)
                    tap_code16(prior_keycode); // repeat last key
                } else { // (if in Japanese mode, send ん)
                    tap_code16(KC_N);  //
                    tap_code16(KC_N);  //
                }
                break;

            case HC_NDSH:
                register_code16(A(KC_MINS));  // should be a semkey
                break;
            case HC_MDSH:
                 register_code16(A(S(KC_MINS))); // should be a semkey
                break;
// the entirely unnecessary pronoun combo shenanigans
/*
            case HC_this_4gram: // TYPE "this" #8
                tap_code(KC_T);
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("his ");
                break;
*/
            case HC_here_4gram: // TYPE "here" #9
                tap_code(KC_H);
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("ere");
                combo_on = combo_index; // may add "'s " if held
                break;
            case HC_their_5gram: // TYPE "their" #6
//            case HC_theirg_5gram: // TYPE "their" #6
                tap_code(KC_T);
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("heir");
                combo_on = combo_index; // may add "'s " if held
                break;
            case HC_there_5gram: // TYPE "there" #7
                tap_code(KC_T);
                goto ADD_HERE;
/*                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("here");
                combo_on = combo_index; // may add "'s " if held
                break;
*/
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
                tap_code(KC_W);
ADD_HERE:
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("here");
                combo_on = combo_index; // may add "'ve " if held
                break;

// This group all share a suffix, with a goto addonsuffix,
// so keep together 'cause we're messing with stack frames at the end!

            case HC_I:
                tap_code16(S(KC_I));
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                combo_on = combo_index; // may add "'ve " if held
                break;
            case HC_they_4gram: // "they"
//            case HC_theyg_4gram: // "they"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("hey"); // send "they" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_your_4gram:
                tap_code(KC_Y);
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("our");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
            case HC_Id:
            case HC_Ill:
            case HC_Im:
            case HC_Iv:
                tap_code16(S(KC_I)); // send "I" CAPITALIZED
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                goto addonsuffix;
            case HC_wed_4gram:
            case HC_well_5gram:
            case HC_were_5gram:
            case HC_weve_5gram:
                tap_code(KC_W); // send "W" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("e"); // send "We" right away
                goto addonsuffix;
            case HC_youd_5gram:
            case HC_youll_6gram:
            case HC_youre_6gram:
            case HC_youve_6gram:
                tap_code(KC_Y); // send "Y" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("ou"); // send "We're" right away
                goto addonsuffix;
            case HC_theyd_6gram: // TYPE "they'd " #23
            case HC_theyll_7gram:
            case HC_theyre_7gram:
            case HC_theyve_7gram: // "they've"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("hey"); // send "they" right away
addonsuffix: // sharing this saves about 100 bytes (10 bytes per instance)
                tap_code(KC_QUOT);
                switch (combo_index) { //
                    case HC_Id: // "I'd " …
                    case HC_wed_4gram: // we'd
                    case HC_youd_5gram:
//                    case HC_youdg_5gram:
                    case HC_theyd_6gram: // TYPE "they'd " #23
//                    case HC_theydg_6gram: // TYPE "they'd " #23
                        send_string("d");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
                    case HC_Im:
                        SEND_STRING("m ");
                        break;
                    case HC_Ill: // "I'll " …
                    case HC_well_5gram: // we'll
                    case HC_youll_6gram:
                    case HC_theyll_7gram: // TYPE "they'll " #23
//                    case HC_theyllg_7gram: // TYPE "they'll " #23
                        send_string("ll");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
                    case HC_were_5gram: // we're
                    case HC_youre_6gram:
                    case HC_theyre_7gram: // "they're"
//                    case HC_theyreg_7gram: // "they're"
                        send_string("re ");
                        break;
                    case HC_Iv: // "I've " …
                    case HC_weve_5gram: // we've
                    case HC_youve_6gram:
                    case HC_theyve_7gram: // "they've"
//                    case HC_theyveg_7gram: // "they've"
                        send_string("ve ");
                        break;
                    case HC_Ch:
                    case HC_Wh:
                        combo_on = combo_index; // may add "i" in matrix_scan_user_process_combo
                        break;
               }
// END of the common suffix group with the goto addonsuffix:
                break;
        } // end switch (combo_index)
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
    } else { // end if (pressed) so this is the key up switch threshold not met.

#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(0,combo_OLED_row);
        oled_write_P(PSTR("                     "), false);
#endif
/*
 This is the key up event
*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch?
        // wrapup the combo and send the underlying keys if necessary
        //
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
    oled_write_P(PSTR("abort"), true);
#endif
            switch(combo_index) {
// the H digraphs

                case HC_Th:
//                case HC_Ths: // for Silver w/ N on thumb, H on middle
//                case HC_Thg:
                    tap_code(KC_T); // send "T" honoring caps
H_DIGRAPH_EXIT:
                    if (myKC_C == KC_C) { // in English mode?
                        unregister_code(KC_LSFT); // remove shift here.
                        unregister_code(KC_RSFT); // remove shift here.
                        tap_code(KC_H); // send "h" honoring CAPSLK state
                    } else {
                        tap_code(KC_Y); // send "Y" for palatalized contracts
                    }
                    break;
               case HC_Ch:
                    tap_code(KC_C); // send "C"
                    goto H_DIGRAPH_EXIT;
                case HC_Sh:
                    tap_code(KC_S); // send "S" honoring caps
                    goto H_DIGRAPH_EXIT;
                case HC_Gh:
                    tap_code(KC_G); // send "P" honoring caps
                    goto H_DIGRAPH_EXIT;
                case HC_Ph:
                    tap_code(KC_P); // send "P" honoring caps
                    goto H_DIGRAPH_EXIT;
                case HC_Wh:
                    tap_code(KC_W); // send "W" honoring caps
                    if (myKC_C == KC_C) // in English mode?
                        goto H_DIGRAPH_EXIT;
                    tap_code(KC_O); // send "o" for を
                    break;

// END the H digraphs
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


                                        
                case HC_TYPE_ENGLISH:
                    if (myKC_C == KC_C) {
                        send_string(EnglishComboTapE); //
                    } else {
                        send_string(EnglishComboTapJ); //
                    }
                    break;
                case HC_TYPE_JAPAN:
                    if (myKC_C == KC_C) {
                        send_string(JapanComboTapE); // send "Japan" right away
                    } else {
                        send_string(JapanComboTapJ); // send "Japan" right away
                    }
                    break;

/*
                case HC_ing_3gram: // TYPE "ing"
                    SEND_STRING("ing");
                    combo_on = combo_index; // may add "s " in matrix_scan_user_process_combo
                    break;
                case HC_with_4gram: // TYPE "with" #5
                    SEND_STRING("with ");
                    break;
                case HC_ment_4gram: // TYPE "ment" #6
                    SEND_STRING("ment");
                    combo_on = combo_index; // may add "s " in matrix_scan_user_process_combo
                    break;
                case HC_ting_4gram: // TYPE "ting" #12
                    SEND_STRING("ting ");
                    break;
                case HC_ough_4gram: // TYPE "ough" #25
                    SEND_STRING("ough ");
                    break;

                case HC_ould_4gram: // TYPE "ould" #11
                    SEND_STRING("ould");
                    combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                    break;
*/
                case HC_I ... HC_where_5gram:
                    tap_code(KC_SPC); // add space after a pronoun
                    combo_on = 0;  // done w/these shenanigans
                    break;
            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
/*                case HC_Z:
                    unregister_linger_key();
                    break;
*/
                case HC_NDSH:
                    unregister_code16(A(KC_MINS));  // this should use semkeys
                    break;
                case HC_MDSH:
                    unregister_code16(A(S(KC_MINS)));  // this should use semkeys
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

void matrix_scan_user_process_combo() {  // called from matrix_scan_user if combo_on

    // These combos are to be held for COMBO_HOLD term before triggering
    // to avoid accidental triggers while fast typing these common rolls (or on home row).
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi), so maybe best to avoid them as
    // combos. On Hands Down, this means no combos on home row, but that's fine,
    // because home already has modifiers, so it all works out.
    //
    // I've since successfully added COMBO_HOLD Home Row combos without difficulty.
    // To use multiple home row mods, just put them down one at a time...works great.
    //
    if (!combo_triggered) {
        // do simple "on" on first press actions here:
        
        // then turn on combo state for hold acions to be resolved in keyup event above
        // if necessary (like releasing the underlying keys, or other cleanup)
        if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on && user_config.AdaptiveKeys) {
            saved_mods = get_mods();
            clear_mods();
            switch(combo_on) {  // combo_on is global, set in process_combo above
                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT)); //
                    break;
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case PC_DASH:
                    tap_code16(A(KC_MINS)); // this should use semkeys
                    break;
                case HC_ELIP:
                case PC_ELIP:
                    tap_code16(A(KC_SCLN)); // this should use semkeys
                    break;
                case PC_EURO:
                    tap_code16(A(S(KC_2))); // this should use semkeys
                    break;
                case PC_CENT:
                    tap_code16(A(KC_4)); // this should use semkeys
                    break;
                case PC_JYEN:
                    tap_code16(A(KC_Y)); // this should use semkeys
                    break;
                case PC_BPND:
                    tap_code16(A(KC_3)); // this should use semkeys
                    break;
                case PC_NEQL:
                    tap_code16(A(KC_EQL)); // this should use semkeys
                    break;
                case PC_DIV:
                    tap_code16(A(KC_SLSH)); // this should use semkeys
                    break;
                case PC_PLMN:
                    tap_code16(A(S(KC_EQL))); // this should use semkeys
                    break;
                case PC_DEG:
                    tap_code16(A(KC_0)); // this should use semkeys
                    break;

                case HC_ACUT:
                     tap_code16(A(KC_E)); // this should use semkeys
                    break;
                case HC_GRV:
                     tap_code16(A(KC_GRV)); // this should use semkeys
                    break;
                case HC_CIRC:
                     tap_code16(A(KC_6)); // this should use semkeys
                    break;
                case HC_MACR:
                    tap_code16(A(KC_A)); // this should use semkeys
                    break;
                case HC_DIER:
                     tap_code16(A(KC_U)); // this should use semkeys
                    break;
                case HC_RING:
                     tap_code16(A(KC_K)); // this should use semkeys
                    break;



                case HC_Sh:
                    tap_code(KC_S); // send "S" honoring caps
                    goto ion;
                case HC_Th: // Works w/ Neu/Bronze/Platinum/Titanium
                    tap_code(KC_T); // send "T" honoring caps
ion: // an phonoLOGICAL extension of the Th&Sh digraph phenomenon
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("ion");
                    break;
                case HC_Ch:
                    tap_code(KC_C); // send "C" honoring caps
                    goto addHI;
                case HC_Wh:
                    tap_code(KC_W); // send "W" honoring caps
addHI:  //  because hi/ci can be awkward on Neu/Au/Ti or Bronze/Ag/Pl
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("hi");
                    break;
                case HC_Gh:
                    send_string("lm"); // no CAPS, never is mixed case.
                    break;
                case HC_Ph:
                    send_string("lp"); // no CAPS, never is mixed case
                    break;
/* these don't seem to be worth it.
                case HC_ing_3gram: // TYPE "ing"
                case HC_ment_4gram: // TYPE "ment" #6
                case HC_ting_4gram: // TYPE "ting" #12
                    SEND_STRING("s ");
                    break;
*/
// PRONOUN shenanigans

                case HC_I:
                case HC_Id:
                case HC_Ill:
//                case HC_ould_4gram: // TYPE "ould " #11
                case HC_they_4gram: // TYPE "they " #23
                case HC_theyd_6gram: // TYPE "they'd " #23
                case HC_theyll_7gram: // TYPE "they'll " #23
                case HC_wed_4gram:
                case HC_well_5gram:
                case HC_youd_5gram:
                case HC_youll_6gram:
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("'ve "); // or should it be "'nt"?
                    break;

                case HC_here_4gram:
                case HC_your_4gram: // TYPE "your's"
                case HC_their_5gram: // TYPE "their's" #6
                case HC_there_5gram: // TYPE "there's" #7
                case HC_where_5gram: //
                    SEND_STRING("'s ");
                    break;

// END PRONOUN shenanigans


                case HC_TYPE_ENGLISH: // already "English" has been sent; if held, undo and send "End of times in 2020"
                    if (myKC_C == KC_C) {
                        send_string(EnglishComboHeldE); //
                    } else {
                        send_string(EnglishComboHeldJ); //
                    }
                    break;
                case HC_TYPE_JAPAN: // already "Japan" has been sent; if held, add "ese"
                    if (myKC_C == KC_C) {
                        send_string(JapanComboHeldE); //
                    } else {
                        send_string(JapanComboHeldJ); //
                    }
                    break;

            } // switch
            set_mods(saved_mods); // Restore mods
            combo_triggered = true;
            #ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
                oled_write_P(PSTR(" sent"), false);
            #endif
        } //  if (combo_on) {
    }
}
