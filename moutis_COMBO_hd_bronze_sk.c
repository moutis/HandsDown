
// functions / state keys

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM F_ESC_combo[] = {KC_X, KC_B, COMBO_END}; // ESCape
const uint16_t PROGMEM F_KILL_combo[] = {KC_X, KC_Y, COMBO_END}; // Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCLP_combo[] = {KC_J, KC_P, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_J, KC_V, COMBO_END}; //  SCREEN shot SELECTION to file
const uint16_t PROGMEM F_CAPS_combo[] = {KC_D, KC_U, COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_CAPS_combo[] = {LSFT_T(KC_T), RSFT_T(KC_A), COMBO_END}; // CAPS WORD (on until delimiter)

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
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_W, COMBO_END}; // _ underscore
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_W, COMBO_END}; // ~ tilde (not the dead one)
const uint16_t PROGMEM Hequal_combo[] = {KC_Y, KC_W, COMBO_END}; // = equal
const uint16_t PROGMEM Hscln_combo[] = {KC_COMM, RSFT_T(KC_A), COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {KC_HASH, KC_DOT, COMBO_END}; // : colon

// spatially arranged characters and diacritics
const uint16_t PROGMEM Hexlm_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_QUOT, COMBO_END}; // ?
const uint16_t PROGMEM Hat_combo[] = {KC_J, KC_F, COMBO_END}; // @ at mark
const uint16_t PROGMEM Helip_combo[] = {KC_HASH, KC_SLSH, COMBO_END}; // … elipses
const uint16_t PROGMEM Htic_combo[] = {KC_DQUO, KC_QUOT, COMBO_END}; // ` tic (not dead key grave)
const uint16_t PROGMEM Hacut_combo[] = {KC_SLSH, KC_DQUO, COMBO_END}; // ´ acute (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {KC_EQL, KC_QUOT, COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {KC_DOT, KC_QUOT, COMBO_END}; // - macron (dead key)ā
const uint16_t PROGMEM Hcirc_combo[] = {KC_DOT, KC_DQUO, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hdier_combo[] = {KC_U, KC_O, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Hring_combo[] = {KC_O, KC_Y, COMBO_END}; // ˚ ring (dead key)
const uint16_t PROGMEM Henye_combo[] = {KC_F, KC_P, COMBO_END}; // ˜ enye (dead key) (over N)

// LOWER ROW
// SYMBOLS spatially arranged

// LEFT HAND

// TEXT ENTRY - off map (ANY ROW/ MIXED ROWS) and row jump prevention
const uint16_t PROGMEM H_J_combo[] = {KC_O, KC_W, COMBO_END}; // TYPE "j"
const uint16_t PROGMEM H_Z_combo[] = {KC_M, KC_F, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Q_combo[] = {KC_U, KC_Y, COMBO_END}; // TYPE "q"
const uint16_t PROGMEM H_Ch_combo[] = {RALT_T(KC_C), RGUI_T(KC_E), COMBO_END}; // TYPE "ch" // for HD Gold
const uint16_t PROGMEM H_Wh_combo[] = {KC_O, KC_W, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Ph_combo[] = {KC_M, KC_P, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Th_combo[] = {LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // "th"
const uint16_t PROGMEM H_Sh_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), COMBO_END}; // "sh"
const uint16_t PROGMEM H_Icap_combo[] = {RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I"+"'ve"
const uint16_t PROGMEM H_Id_combo[] = {KC_D, RCTL_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve"
const uint16_t PROGMEM H_Ill_combo[] = {KC_L, RCTL_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve"
const uint16_t PROGMEM H_Im_combo[] = {KC_M, RCTL_T(KC_I), COMBO_END}; // TYPE "I'm"

const uint16_t PROGMEM H_ing_combo[] = {RCTL_T(KC_I), KC_G, COMBO_END}; // TYPE "ing" only a 3gram, let's see it it's worth it

// Fast 4grams
// FOR THUMB SHIFT
/*
const uint16_t PROGMEM H_tion_combo[] = {LGUI_T(KC_N), LT(L_LANG_NUM, KC_T), COMBO_END}; // "tion" #1
const uint16_t PROGMEM H_with_combo[] = {KC_W, LSFT_T(KC_H), COMBO_END}; // "with" #5
const uint16_t PROGMEM H_ment_combo[] = {KC_M, LT(L_LANG_NUM, KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_this_combo[] = {LT(L_LANG_NUM, KC_T), LALT_T(KC_S), COMBO_END}; // "this" #8
const uint16_t PROGMEM H_here_combo[] = {LSFT(KC_H), RCTL_T(KC_R), COMBO_END}; // "here" #9
const uint16_t PROGMEM H_ould_combo[] = {KC_O, KC_D, COMBO_END}; // "ould" #11
const uint16_t PROGMEM H_ting_combo[] = {LT(L_LANG_NUM, KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_sion_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), COMBO_END}; // "sion" #20
const uint16_t PROGMEM H_they_combo[] = {LT(L_LANG_NUM, KC_T), KC_J, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_their_combo[] = {LT(L_LANG_NUM, KC_T), KC_X, COMBO_END}; // "their" #6
const uint16_t PROGMEM H_there_combo[] = {LT(L_LANG_NUM, KC_T), LCTL_T(KC_R), COMBO_END}; // "there" #7
const uint16_t PROGMEM H_ough_combo[] = {KC_O, LSFT_T(KC_H), COMBO_END}; // "ough" #25
 */
// FOR INDEX SHIFT

//const uint16_t PROGMEM H_tion_combo[] = {LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // "tion" #1
const uint16_t PROGMEM H_with_combo[] = {KC_W, LT(L_MEDIA_NAV,KC_H), COMBO_END}; // "with" #5
const uint16_t PROGMEM H_ment_combo[] = {KC_M, LSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_this_combo[] = {LSFT_T(KC_T), LALT_T(KC_S), COMBO_END}; // "this" #8
const uint16_t PROGMEM H_here_combo[] = {LT(L_MEDIA_NAV,KC_H), LCTL_T(KC_R), COMBO_END}; // "here" #9
const uint16_t PROGMEM H_ould_combo[] = {KC_O, KC_D, COMBO_END}; // "ould" #11
const uint16_t PROGMEM H_ting_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_sion_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), COMBO_END}; // "sion" #20
const uint16_t PROGMEM H_they_combo[] = {LSFT_T(KC_T), KC_Y, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_ough_combo[] = {KC_O, LT(L_MEDIA_NAV,KC_H), COMBO_END}; // "ough" #25


// Fast 5-7grams

const uint16_t PROGMEM H_their_combo[] = {LSFT_T(KC_T), KC_X, COMBO_END}; // TYPE "their" #6
const uint16_t PROGMEM H_there_combo[] = {LSFT_T(KC_T), LCTL_T(KC_R), COMBO_END}; // TYPE "there" #7
const uint16_t PROGMEM H_theyre_combo[] = {LSFT_T(KC_T), KC_QUOT, COMBO_END}; // "they're"
const uint16_t PROGMEM H_where_combo[] = {KC_W, LCTL_T(KC_R), COMBO_END}; // "where"


/* other examples or text entry combos */
const uint16_t PROGMEM H_Japan_combo[] = {KC_F, KC_M, KC_P, COMBO_END}; // TYPE "Japan"
const uint16_t PROGMEM Macro_combo[] = {KC_J, KC_B, COMBO_END}; // some demonstrator macro placeholder

// UPPER ROW

// FUNCTIONS Spatially arranged
const uint16_t PROGMEM Qtab_combo[] = {KC_Q, KC_W, COMBO_END}; // tab QWERTY
const uint16_t PROGMEM Htab_combo[] = {LCTL_T(KC_R), LALT_T(KC_S), COMBO_END}; // tab HANDS DOWN
const uint16_t PROGMEM Hent_combo[] = {LSFT_T(KC_T), KC_K, COMBO_END}; // ENTER
const uint16_t PROGMEM Hspc_combo[] = {KC_D, KC_B, COMBO_END}; // SPACE

// LOWER ROW

// SEMANTIC FUNCTIONS Spatially arranged  ** uses SemKeys **
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
const uint16_t PROGMEM Hdquo_combo[] = {KC_HASH, KC_DQUO, COMBO_END};  // "|" insert between double quote

// Major diacritic combos will use SemKeys for platform independance
/*
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
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL), // =
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO(Hcoln_combo, KC_COLN), // :
    [HC_UNDS] = COMBO(Hunds_combo, KC_UNDS), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~
    [HC_TIC] = COMBO(Htic_combo, KC_GRV),  // `
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_AT] = COMBO(Hat_combo, KC_AT), // @
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [QC_TAB] = COMBO(Qtab_combo, KC_TAB),

    [HC_I] = COMBO_ACTION(H_Icap_combo),// TYPE "I"+"'ve "
    [HC_Id] = COMBO_ACTION(H_Id_combo),// TYPE "I'd "
    [HC_Ill] = COMBO_ACTION(H_Ill_combo),// TYPE "I'll "
    [HC_Im] = COMBO_ACTION(H_Im_combo),// TYPE "I'm  "
    [HC_J] = COMBO(H_J_combo, KC_J),
    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
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
    [HC_2DQUO] = COMBO_ACTION(Hdquo_combo),

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
    [FC_KILL] = COMBO(F_KILL_combo, SK_KILL), // Force quit
    [FC_SCAP] = COMBO(F_SCAP_combo, SK_SCAP), // SCREEN CAPTURE SELECTION
    [FC_SCLP] = COMBO(F_SCLP_combo, SK_SCLP), // SCREEN CAPTURE SELECTION to clipboard
    [FC_CAPS] = COMBO(F_CAPS_combo, KC_CAPS), // CAPS LOCK
    [HC_CAPSWORD] = COMBO_ACTION(H_CAPS_combo), // CAPS_WORD

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
/* These will be handled by SemKeys
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
    [HC_ing_3gram] = COMBO_ACTION(H_ing_combo), // TYPE "ing"
//    [HC_tion_4gram] = COMBO_ACTION(H_tion_combo), // TYPE "tion" #1  // handled via adaptive keys?
    [HC_with_4gram] = COMBO_ACTION(H_with_combo), // TYPE "with" #5
    [HC_ment_4gram] = COMBO_ACTION(H_ment_combo), // TYPE "ment" #6
    [HC_this_4gram] = COMBO_ACTION(H_this_combo), // TYPE "this" #8
    [HC_here_4gram] = COMBO_ACTION(H_here_combo), // TYPE "here" #9
    [HC_ould_4gram] = COMBO_ACTION(H_ould_combo), // TYPE "ould" #11
    [HC_ting_4gram] = COMBO_ACTION(H_ting_combo), // TYPE "ting" #12
    [HC_they_4gram] = COMBO_ACTION(H_they_combo), // TYPE "they" #23
    [HC_ough_4gram] = COMBO_ACTION(H_ough_combo), // TYPE "ough" #25
    
    // Fast entry 5-7grams

    [HC_their_5gram] = COMBO_ACTION(H_their_combo), // TYPE "their" #6
    [HC_there_5gram] = COMBO_ACTION(H_there_combo), // TYPE "there" #7
    [HC_where_5gram] = COMBO_ACTION(H_where_combo), // TYPE "where"
    [HC_theyre_7gram] = COMBO_ACTION(H_theyre_combo), // TYPE "they're"

/* Maybe not worth the possible misfire?
    [HC_people_6gram] = COMBO_ACTION(H_people_combo), // TYPE "people" #23
    [HC_present_7gram] = COMBO_ACTION(H_present_combo), // TYPE "present" #1
    [HC_through_7gram] = COMBO_ACTION(H_through_combo), // TYPE "through" #3
    [HC_between_7gram] = COMBO_ACTION(H_between_combo), // TYPE "between" #4
*/

    [HC_TYPE_JAPAN] = COMBO_ACTION(H_Japan_combo), // a personally useful 5-8gram!
    [MYMACRO] = COMBO_ACTION(Macro_combo), // a demonstrator, how long autotypes can be!

//    [HC_APP] = COMBO(Happ_combo, KC_APP), // app menu
    [HC_SPC] = COMBO(Hspc_combo, KC_SPC), // SPACE
    [HC_ENT] = COMBO(Hent_combo, KC_ENT), // ENTER
    /* Uses SemKeys, even as simple combos (handled by process_semkey from process_record_user) */
    [HC_CLOZ] = COMBO(Hclose_combo, SK_CLOZ),
    [HC_QUIT] = COMBO(Hquit_combo, SK_QUIT),
    [HC_FIND] = COMBO(Hfind_combo, SK_FIND),
    [HC_SALL] = COMBO(Hsall_combo, SK_SALL),
    [HC_UNDO] = COMBO(Hundo_combo, SK_UNDO),
    [HC_CUT] = COMBO(Hcut_combo, SK_CUT),
    [HC_COPY] = COMBO(Hcopy_combo, SK_COPY),
    [HC_PSTE] = COMBO(Hpste_combo, SK_PSTE),
    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM),

    
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
            case PC_STAB ... COMBO_LENGTH:  // these have a hold delay before triggering
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;
            case HC_CAPSWORD: // turn on capsword (automatically turns off on delimiter)
                toggle_caps_word();
                break;

            case HC_NDSH:
                register_code16(A(KC_MINS));
                break;
            case HC_MDSH:
                 register_code16(A(S(KC_MINS)));
                break;


            case HC_ing_3gram: // TYPE "ing"
                SEND_STRING("ing");
                combo_on = combo_index; // may add "s " in matrix_scan_user_process_combo
                break;
/*            case HC_tion_4gram: // TYPE "tion" #1
                SEND_STRING("tion");
                break;
*/
            case HC_with_4gram: // TYPE "with" #5
                SEND_STRING("with");
                break;
            case HC_ment_4gram: // TYPE "ment" #6
                SEND_STRING("ment");
                combo_on = combo_index; // may add "s " in matrix_scan_user_process_combo
                break;
            case HC_this_4gram: // TYPE "this" #8
                SEND_STRING("this ");
                break;
            case HC_here_4gram: // TYPE "here" #9
                SEND_STRING("here");
                combo_on = combo_index; // may add "s " in matrix_scan_user_process_combo
                break;
            case HC_ould_4gram: // TYPE "ould" #11
                SEND_STRING("ould");
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_ting_4gram: // TYPE "ting" #12
                SEND_STRING("ting ");
                break;
            case HC_they_4gram: // TYPE "they" #23
                SEND_STRING("they");
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_ough_4gram: // TYPE "ough" #25
                SEND_STRING("ough ");
                break;

            case HC_their_5gram: // TYPE "their" #6
                SEND_STRING("their");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
            case HC_there_5gram: // TYPE "there" #7
                SEND_STRING("there");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
                SEND_STRING("where");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
                
                
            case HC_TYPE_JAPAN:
                SEND_STRING("Japan"); // send "Japan" right away
                combo_on = combo_index; // may add "ese " in matrix_scan_user_process_combo
                break;
            case HC_Id:
                SEND_STRING("I'd"); // send "I'd" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_Ill:
                SEND_STRING("I'll"); // send "I'll" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_Im:
                SEND_STRING("I'm "); // send "I'm " right away
                break;
            case HC_I:
                tap_code16(S(KC_I)); // send "I" CAPITALIZED
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_Ch:
                tap_code(KC_C); // send "C" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                tap_code(KC_H); // send "h" honoring CAPSLK state
                break;
            case HC_Ph:
                tap_code(KC_P); // send "P" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                tap_code(KC_H); // send "h" honoring CAPSLK state
                break;
            case HC_Sh:
                tap_code(KC_S); // send "S" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                tap_code(KC_H); // send "h" honoring CAPSLK state
                break;
            case HC_Th:
                tap_code(KC_T); // send "T" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                tap_code(KC_H); // send "h" honoring CAPSLK state
                break;
            case HC_Wh:
                tap_code(KC_W); // send "G" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                tap_code(KC_H); // send "h" honoring CAPSLK state
                break;
        } // end switch (combo_index)
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
    } else { // end if (pressed) this is the key up switch threshold not met.

#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(0,combo_OLED_row);
        oled_write_P(PSTR("                     "), false);
#endif
/*
 This is the key up event
*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch?
        if (combo_on && !combo_triggered) {// no combo, so send the underlying keys
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
    oled_write_P(PSTR("abort"), true);
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


                case HC_I:
                case HC_Id:
                case HC_Ill:
                case HC_ing_3gram: // TYPE "ing"
                case HC_ment_4gram: // TYPE "ment" #6
                case HC_ting_4gram: // TYPE "ting" #12
                case HC_here_4gram:
                case HC_ould_4gram: // TYPE "ould" #11
                case HC_they_4gram: // TYPE "they" #23
                case HC_their_5gram: //
                case HC_there_5gram: //
                case HC_where_5gram: //
                case HC_TYPE_JAPAN:
                    SEND_STRING(" "); //
                    break;
            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
                case HC_NDSH:
                    unregister_code16(A(KC_MINS));
                    break;
                case HC_MDSH:
                    unregister_code16(A(S(KC_MINS)));
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
//extern uint8_t  saved_mods; // global, so we're not wasting time allocating...

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
        // do simple "on" on first press actions here:
        
        // then turn on combo state for hold acions to be resolved in keyup event above
        // if necessary (like releasing the underlying keys, or other cleanup)
        if (combo_on && (timer_elapsed(linger_timer) > COMBO_HOLD)) {
            saved_mods = get_mods();
            clear_mods();
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
                    tap_code16(A(KC_SCLN)); // this should use semkeys
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


                case HC_2DQUO: // "|"
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

                case MYMACRO:
                    SEND_STRING("End of times in 2020\n"); // some random demonstrator
                    break;
                case HC_ing_3gram: // TYPE "ing"
                case HC_ment_4gram: // TYPE "ment" #6
                case HC_ting_4gram: // TYPE "ting" #12
                    SEND_STRING("s ");
                    break;
                case HC_I: // TYPE "'ve " // should it be I'd? Stats on this?
                case HC_Id: //
                case HC_Ill: //
                case HC_Im: //
                case HC_ould_4gram: // TYPE "ould " #11
                case HC_they_4gram: // TYPE "they " #23
                    SEND_STRING("'ve "); // or should it be "'nt"?
                    break;
                case HC_here_4gram:
                case HC_their_5gram: // TYPE "their" #6
                case HC_there_5gram: // TYPE "there" #7
                case HC_where_5gram: //
                    SEND_STRING("'s ");
                    break;
                case HC_TYPE_JAPAN: // already "Japan" has been sent; if held, add "ese"
                    SEND_STRING("ese ");
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
