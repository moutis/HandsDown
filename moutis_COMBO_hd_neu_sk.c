/*
 Combos
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 I think this will work with Hands Down Neu variants Gold, Bronze.
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

/* examples of text entry combos */
const uint16_t PROGMEM H_Japan_combo[] = {KC_G, KC_M, KC_P, COMBO_END}; // TYPE EnglishComboTapE
const uint16_t PROGMEM H_English_combo[] = {KC_DOT, KC_SLSH, KC_DQUO, COMBO_END}; // some demonstrator macro placeholder
//const uint16_t PROGMEM H_Japan_combo[] = {KC_J, KC_P, COMBO_END}; // TYPE JapanComboTapE
//const uint16_t PROGMEM H_English_combo[] = {KC_DOT, KC_SLSH, KC_QUOT, COMBO_END}; // some demonstrator macro placeholder


const uint16_t PROGMEM F_ESC_combo[] = {KC_X, KC_K, COMBO_END}; // ESCape
const uint16_t PROGMEM F_KILL_combo[] = {KC_X, KC_V, COMBO_END}; // KILL = Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCLP_combo[] = {KC_J, KC_G, KC_P, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_J, KC_G, KC_V, COMBO_END}; //  SCREEN shot SELECTION to file

const uint16_t PROGMEM F_CAPG_combo[] = {KC_C, KC_U, COMBO_END}; // CAPS LOCK (on until hit again) Gold
const uint16_t PROGMEM F_CAPS_combo[] = {KC_D, KC_U, COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_CAPW_combo[] = {LSFT_T(KC_T), RSFT_T(KC_A), COMBO_END}; // CAPS WORD (on until word delimiter)
//const uint16_t PROGMEM H_CAPG_combo[] = {LSFT_T(KC_D), RSFT_T(KC_A), COMBO_END}; // CAPS WORD for Gold
//const uint16_t PROGMEM H_EISUUg_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_D), COMBO_END}; // KC_LANG2
const uint16_t PROGMEM H_EISUU_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // KC_HENK
const uint16_t PROGMEM H_KANA_combo[] = {RALT_T(KC_C), RGUI_T(KC_E), RSFT_T(KC_A), COMBO_END}; // KC_MHEN
const uint16_t PROGMEM H_KANAg_combo[] = {RSFT_T(KC_A), RGUI_T(KC_E), RALT_T(KC_I), COMBO_END}; // KC_MHEN for neu/Gold/Titanium
const uint16_t PROGMEM H_EISUUq_combo[] = {KC_S,KC_D,KC_F, COMBO_END}; // KC_MHEN for QWERTY
const uint16_t PROGMEM H_KANAq_combo[] = {KC_J,KC_K,KC_L, COMBO_END}; // KC_LANG1 for QWERTY

//  (22) keypad combos
const uint16_t PROGMEM PNLCK_combo[] = {KC_P4, KC_P5, KC_P6, COMBO_END}; // toggle num layer
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
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_W, COMBO_END}; // _ underscore
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_W, COMBO_END}; // ~ tilde (not the dead one)
const uint16_t PROGMEM Hequal_combo[] = {KC_MINS, KC_Y, COMBO_END}; // = equal
const uint16_t PROGMEM Hscln_combo[] = {LT(4, KC_COMM), RSFT_T(KC_A), COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {KC_HASH, KC_DOT, COMBO_END}; // : colon

// spatially arranged characters and diacritics
const uint16_t PROGMEM Hexlm_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_QUOT, COMBO_END}; // ?
const uint16_t PROGMEM Hquesg_combo[] = {KC_SLSH, KC_DQUO, COMBO_END}; //
const uint16_t PROGMEM Hat_combo[] = {KC_P, KC_V, COMBO_END}; // MENU (now shift ! = ?) @ at mark
const uint16_t PROGMEM Helip_combo[] = {KC_HASH, KC_SLSH, COMBO_END}; // … elipses
const uint16_t PROGMEM Htic_combo[] = {KC_DQUO, KC_QUOT, COMBO_END}; // ` tic (not dead key grave)

// spatially arranged diacritics
const uint16_t PROGMEM Hacut_combo[] = {RSFT_T(KC_A), RGUI_T(KC_E), COMBO_END}; // ´ acute (dead key)
const uint16_t PROGMEM Hgrv_combo[] = {RGUI_T(KC_E), RCTL_T(KC_H), COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {KC_DOT, KC_DQUO, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hdier_combo[] = {KC_U, KC_O, COMBO_END}; // ¨ dieresis (dead key)
//const uint16_t PROGMEM Hring_combo[] = {KC_O, KC_Y, COMBO_END}; // ˚ ring (dead key)
const uint16_t PROGMEM Henye_combo[] = {LALT_T(KC_S), LSFT_T(KC_D), COMBO_END}; // ˜ enye (dead key) (ñ only?)


// LEFT HAND

// TEXT ENTRY - off map standard alphas
//const uint16_t PROGMEM H_J_combo[] = {KC_P, KC_V, COMBO_END}; // TYPE "j"
const uint16_t PROGMEM H_Z_combo[] = {KC_J, KC_G, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Q_combo[] = {KC_U, KC_Y, COMBO_END}; // TYPE "q"

// H digraphs
const uint16_t PROGMEM H_Ch_combo[] = {RALT_T(KC_C), RGUI_T(KC_E), COMBO_END}; // TYPE "ch" for Bronze/Silver/Platinum
const uint16_t PROGMEM H_Chg_combo[] = {LALT_T(KC_S), LSFT_T(KC_T), COMBO_END}; // TYPE "ch" // for Titanium
const uint16_t PROGMEM H_Wh_combo[] = {KC_O, KC_W, COMBO_END}; // TYPE "wh"  // TYPE "wh" // for HD Bronze/Silver/Platinum
const uint16_t PROGMEM H_Whg_combo[] = {KC_O, KC_Y, COMBO_END}; // TYPE "wh" // for HD Gold/neu/Ti
const uint16_t PROGMEM H_Ph_combo[] = {KC_M, KC_P, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "gh"
const uint16_t PROGMEM H_Sh_combo[] = {LALT_T(KC_S), LGUI_T(KC_N), COMBO_END}; // "sh"
const uint16_t PROGMEM H_Th_combo[] = {LGUI_T(KC_N), LSFT_T(KC_T), COMBO_END}; // "th"
//const uint16_t PROGMEM H_Shs_combo[] = {LALT_T(KC_S), LGUI_T(KC_H), COMBO_END}; // "sh" // (for Neu-nx a.k.a Silver)
//const uint16_t PROGMEM H_Ths_combo[] = {LGUI_T(KC_H), LSFT_T(KC_T), COMBO_END}; // "th" // (for Neu-nx a.k.a Silver)
//const uint16_t PROGMEM H_Thg_combo[] = {LGUI_T(KC_N), LSFT_T(KC_D), COMBO_END}; // "th" // for HD Gold

// TEXT ENTRY - (ANY ROW/ MIXED ROWS)

const uint16_t PROGMEM H_ing_combo[] = {RCTL_T(KC_I), KC_G, COMBO_END}; // TYPE "ing" only a 3gram, let's see it it's worth it

// Fast 4grams

const uint16_t PROGMEM H_withg_combo[] = {KC_W, RCTL_T(KC_H), COMBO_END}; // "with" #5 for Gold/Neu
const uint16_t PROGMEM H_oughg_combo[] = {KC_O, RCTL_T(KC_H), COMBO_END}; // "ough" #25 for Gold/Neu

const uint16_t PROGMEM H_with_combo[] = {KC_W, LT(L_NAV,KC_H), COMBO_END}; // "with" #5
const uint16_t PROGMEM H_ment_combo[] = {KC_M, LSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_there_combo[] = {LSFT_T(KC_T), LCTL_T(KC_R), COMBO_END}; // TYPE "there" #7
const uint16_t PROGMEM H_here_combo[] = {LT(L_NAV,KC_H), LCTL_T(KC_R), COMBO_END}; // "here" #9
const uint16_t PROGMEM H_ould_combo[] = {KC_O, KC_D, COMBO_END}; // "ould" #11
const uint16_t PROGMEM H_ting_combo[] = {LSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_ough_combo[] = {KC_O, LT(L_NAV,KC_H), COMBO_END}; // "ough" #25


// PRONOUNS Fast 4-7grams

const uint16_t PROGMEM H_Icapg_combo[] = {RALT_T(KC_I), RGUI_T(KC_E), COMBO_END}; // TYPE "I"+"'m" for Gold/Neuh
const uint16_t PROGMEM H_Idg_combo[] = {KC_D, RALT_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Illg_combo[] = {KC_L, RALT_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve " for Gold/Neu
const uint16_t PROGMEM H_Img_combo[] = {KC_M, RALT_T(KC_I), COMBO_END}; // TYPE "I'm " for Gold/Neu
const uint16_t PROGMEM H_Ivg_combo[] = {KC_V, RALT_T(KC_I), COMBO_END}; // TYPE "I've " for Gold/Neu
const uint16_t PROGMEM H_youdg_combo[] = {KC_Y, LSFT_T(KC_D), COMBO_END}; // TYPE "you'd"
/*
const uint16_t PROGMEM H_theyg_combo[] = {LSFT_T(KC_T), KC_Y, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theydg_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END}; // TYPE "they'd " #23
const uint16_t PROGMEM H_theyllg_combo[] = {LSFT_T(KC_T), KC_L, COMBO_END}; // "they'll"
const uint16_t PROGMEM H_theyveg_combo[] = {LSFT_T(KC_T), KC_V, COMBO_END}; // "they've"
const uint16_t PROGMEM H_theyreg_combo[] = {LSFT_T(KC_T), KC_J, COMBO_END}; // "they're"
const uint16_t PROGMEM H_theirg_combo[] = {LSFT_T(KC_T), KC_X, COMBO_END}; // TYPE "their" #6
 */
const uint16_t PROGMEM H_thereg_combo[] = {LSFT_T(KC_T), LT(L_NAV,KC_R), COMBO_END}; // TYPE "there" #7
const uint16_t PROGMEM H_hereg_combo[] = {RCTL_T(KC_H), LT(L_NAV,KC_R), COMBO_END}; // TYPE "here" #5
const uint16_t PROGMEM H_whereg_combo[] = {KC_W, LT(L_NAV,KC_R), COMBO_END}; // "where"

const uint16_t PROGMEM H_Icap_combo[] = {RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I"+"'m" for Bronze/Silver/Platinum
const uint16_t PROGMEM H_Id_combo[] = {KC_D, RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve " for Bronze/Silver/Platinum
const uint16_t PROGMEM H_Ill_combo[] = {KC_L, RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve " for Bronze/Silver/Platinum
const uint16_t PROGMEM H_Im_combo[] = {KC_M, RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I'm " for Bronze/Silver/Platinum
const uint16_t PROGMEM H_Iv_combo[] = {KC_V, RALT_T(KC_C), RCTL_T(KC_I), COMBO_END}; // TYPE "I've " for Bronze/Silver/Platinum

const uint16_t PROGMEM H_wed_combo[] = {KC_W, KC_D, COMBO_END}; // TYPE "we'd" we'll
const uint16_t PROGMEM H_well_combo[] = {KC_W, KC_L, COMBO_END}; // TYPE "we'll" we're
const uint16_t PROGMEM H_were_combo[] = {KC_W, KC_J, COMBO_END}; // TYPE "we're"
const uint16_t PROGMEM H_weve_combo[] = {KC_W, KC_V, COMBO_END}; // TYPE "we've"
const uint16_t PROGMEM H_youd_combo[] = {KC_Y, KC_D, COMBO_END}; // TYPE "you'd"
const uint16_t PROGMEM H_youll_combo[] = {KC_Y, KC_L, COMBO_END}; // TYPE "you'll"
const uint16_t PROGMEM H_youre_combo[] = {KC_Y, KC_J, COMBO_END}; // TYPE "you're"
const uint16_t PROGMEM H_youve_combo[] = {KC_Y, KC_V, COMBO_END}; // TYPE "you've"
const uint16_t PROGMEM H_your_combo[] = {KC_Y, KC_X, COMBO_END}; // TYPE "your"
const uint16_t PROGMEM H_their_combo[] = {LSFT_T(KC_T), KC_X, COMBO_END}; // TYPE "their" #6
const uint16_t PROGMEM H_they_combo[] = {LSFT_T(KC_T), KC_Y, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyd_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyll_combo[] = {LSFT_T(KC_T), KC_L, COMBO_END}; // "they" #23
const uint16_t PROGMEM H_theyre_combo[] = {LSFT_T(KC_T), KC_J, COMBO_END}; // "they're"
const uint16_t PROGMEM H_where_combo[] = {KC_W, LCTL_T(KC_R), COMBO_END}; // "where"


// UPPER ROW

// FUNCTIONS/COMMANDS Spatially arranged

const uint16_t PROGMEM Htab_combo[] = {LCTL_T(KC_R), LALT_T(KC_S), COMBO_END}; // tab
const uint16_t PROGMEM Htabt_combo[] = {LCTL_T(KC_C), LALT_T(KC_S), COMBO_END}; // tab for Titanium
const uint16_t PROGMEM Hspc_combo[] = {LSFT_T(KC_T), LT(5,KC_B), COMBO_END}; // SPACE
const uint16_t PROGMEM Hspcg_combo[] = {LSFT_T(KC_T), LT(5,KC_K), COMBO_END}; // SPACE for Gold
const uint16_t PROGMEM Hent_combo[] = {KC_D, KC_K, COMBO_END}; // ENTER
const uint16_t PROGMEM Hentg_combo[] = {KC_D, KC_B, COMBO_END}; // ENTER for gold (should be CH?)

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
/*
const uint16_t PROGMEM Hcloseg_combo[] = {KC_L, KC_K, COMBO_END}; // close FOR GOLD
const uint16_t PROGMEM Hquitg_combo[] = {KC_G, KC_K, COMBO_END}; // quit FOR GOLD
const uint16_t PROGMEM Hsallg_combo[] = {KC_X, KC_C, COMBO_END}; // select all FOR GOLD
const uint16_t PROGMEM Hpsteg_combo[] = {KC_L, KC_C, COMBO_END}; // paste FOR GOLD
const uint16_t PROGMEM Hpstmg_combo[] = {KC_F, KC_C, COMBO_END}; // paste-match FOR GOLD
*/
// TWO HANDS
//const uint16_t PROGMEM Hdquo_combo[] = {HD_HASH, HD_DQUO, COMBO_END};  // "|" insert between double quote

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
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL), // =
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO(Hcoln_combo, KC_COLN), // :
    [HC_UNDS] = COMBO(Hunds_combo, KC_UNDS), // _
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~ or SK_TILD?
    [HC_TIC] = COMBO(Htic_combo, KC_GRV),  // `
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_QUESg] = COMBO(Hquesg_combo, KC_QUES), // ?
    [HC_AT] = COMBO(Hat_combo, KC_APP), // APP SWITCHER MENU
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [HC_TABt] = COMBO(Htabt_combo, KC_TAB), // tab for Titanium

    [HC_Q] = COMBO(H_Q_combo, KC_Q),
    [HC_Z] = COMBO_ACTION(H_Z_combo),
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
    [HC_Chg] = COMBO_ACTION(H_Chg_combo), // for Gold/Neu
    [HC_Gh] = COMBO_ACTION(H_Gh_combo),
    [HC_Ph] = COMBO_ACTION(H_Ph_combo),
    [HC_Th] = COMBO_ACTION(H_Th_combo),
    [HC_Sh] = COMBO_ACTION(H_Sh_combo),
    [HC_Whg] = COMBO_ACTION(H_Whg_combo),
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
//    [FC_LANG2g] = COMBO(H_EISUUg_combo, KC_LANG2), // eisuu (neu/Gold)
    [FC_LANG1g] = COMBO(H_KANAg_combo, KC_HENK), // kana (neu/Gold)
    [FC_LANG2q] = COMBO(H_EISUUq_combo, KC_MHEN), // eisuu (QWERTY)
    [FC_LANG1q] = COMBO(H_KANAq_combo, KC_HENK), // kana (QWERTY)

// HANDSDOWN
    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_GRV] = COMBO_ACTION(Hgrv_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
//    [HC_RING] = COMBO_ACTION(Hring_combo), // ˚ ring
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
    [HC_ing_3gram] = COMBO_ACTION(H_ing_combo), // TYPE "ing"
//    [HC_tion_4gram] = COMBO_ACTION(H_tion_combo), // TYPE "tion" #1  // handled via adaptive keys?
    [HC_with_4gram] = COMBO_ACTION(H_with_combo), // TYPE "with" #5
//    [HC_withg_4gram] = COMBO_ACTION(H_withg_combo), // TYPE "with" #5
    [HC_ment_4gram] = COMBO_ACTION(H_ment_combo), // TYPE "ment" #6
    [HC_ould_4gram] = COMBO_ACTION(H_ould_combo), // TYPE "ould" #11
    [HC_ting_4gram] = COMBO_ACTION(H_ting_combo), // TYPE "ting" #12
    [HC_ough_4gram] = COMBO_ACTION(H_ough_combo), // TYPE "ough" #25
    [HC_oughg_4gram] = COMBO_ACTION(H_oughg_combo), // TYPE "ough" #25

    // PRONOUNS Fast entry 4-7gram PRONOUNS (an English quirk)

//    [HC_this_4gram] = COMBO_ACTION(H_this_combo), // TYPE "this" #8
    [HC_they_4gram] = COMBO_ACTION(H_they_combo), // TYPE "they" #23
//    [HC_theyg_4gram] = COMBO_ACTION(H_theyg_combo), // TYPE "they" #23

    [HC_Ig] = COMBO_ACTION(H_Icapg_combo),// TYPE "I"+"'ve " for Gold/Neu
    [HC_Idg] = COMBO_ACTION(H_Idg_combo),// TYPE "I'd " for Gold/Neu
    [HC_Illg] = COMBO_ACTION(H_Illg_combo),// TYPE "I'll " for Gold/Neu
    [HC_Img] = COMBO_ACTION(H_Img_combo),// TYPE "I'm  " for Gold/Neu
    [HC_Ivg] = COMBO_ACTION(H_Ivg_combo),// TYPE "I've  " for Gold/Neu
//    [HC_youdg_5gram] = COMBO_ACTION(H_youdg_combo),// TYPE "you'd"
//    [HC_theydg_6gram] = COMBO_ACTION(H_theydg_combo), // TYPE "they'd" for Gold/Neu
//    [HC_theyllg_7gram] = COMBO_ACTION(H_theyllg_combo), // TYPE "they'll" for Gold/Neu
//    [HC_theyreg_7gram] = COMBO_ACTION(H_theyreg_combo), // TYPE "they're" for Gold/Neut
//    [HC_theyveg_7gram] = COMBO_ACTION(H_theyveg_combo), // TYPE "they've" for Gold/Neu
    [HC_thereg_5gram] = COMBO_ACTION(H_thereg_combo), // TYPE "there" #7 for Gold/Neu
//    [HC_theirg_5gram] = COMBO_ACTION(H_theirg_combo), // TYPE "their" #6
    [HC_hereg_4gram] = COMBO_ACTION(H_hereg_combo), // TYPE "here" #9
    [HC_whereg_5gram] = COMBO_ACTION(H_whereg_combo), // TYPE "where"

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
    [HC_their_5gram] = COMBO_ACTION(H_their_combo), // TYPE "their" #6
    [HC_theyre_7gram] = COMBO_ACTION(H_theyre_combo), // TYPE "they're"
    [HC_here_4gram] = COMBO_ACTION(H_here_combo), // TYPE "here" #9
    [HC_where_5gram] = COMBO_ACTION(H_where_combo), // TYPE "where"


/* Maybe not worth the possible misfire?
    [HC_people_6gram] = COMBO_ACTION(H_people_combo), // TYPE "people" #23
    [HC_present_7gram] = COMBO_ACTION(H_present_combo), // TYPE "present" #1
    [HC_through_7gram] = COMBO_ACTION(H_through_combo), // TYPE "through" #3
    [HC_between_7gram] = COMBO_ACTION(H_between_combo), // TYPE "between" #4
*/

    [HC_TYPE_JAPAN] = COMBO_ACTION(H_Japan_combo), // a personally useful 5-8gram!
    [HC_TYPE_ENGLISH] = COMBO_ACTION(H_English_combo), // a demonstrator, how long autotypes can be!

//    [HC_APP] = COMBO(Happ_combo, KC_APP), // app menu


    [HC_SPC] = COMBO(Hspc_combo, KC_SPC), // SPACE
    [HC_ENT] = COMBO(Hent_combo, KC_ENT), // ENTER
    [HC_SPCg] = COMBO(Hspcg_combo, KC_SPC), // SPACE for Gold
    [HC_ENTg] = COMBO(Hentg_combo, KC_ENT), // ENTER for Gold
    /* Uses SemKeys, even as simple combos (handled by process_semkey from process_record_user) */
    [HC_CLOZ] = COMBO(Hclose_combo, SK_CLOZ),
    [HC_QUIT] = COMBO(Hquit_combo, SK_QUIT),
    [HC_FIND] = COMBO(Hfind_combo, SK_FIND),
    [HC_SALL] = COMBO(Hsall_combo, SK_SALL),
//    [HC_CLOZg] = COMBO(Hcloseg_combo, SK_CLOZ), // for Gold
//    [HC_QUITg] = COMBO(Hquitg_combo, SK_QUIT), //  for Gold
//    [HC_SALLg] = COMBO(Hsallg_combo, SK_SALL), // for Gold

    [HC_UNDO] = COMBO(Hundo_combo, SK_UNDO),
    [HC_CUT] = COMBO(Hcut_combo, SK_CUT),
    [HC_COPY] = COMBO(Hcopy_combo, SK_COPY),
    [HC_PSTE] = COMBO(Hpste_combo, SK_PSTE),
    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM),
//    [HC_PSTEg] = COMBO(Hpsteg_combo, SK_PSTE), // for Gold
//    [HC_PSTMg] = COMBO(Hpstmg_combo, SK_PSTM), // for Gold

    
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

            case HC_Z: // (Q gets special treatment)
                register_linger_key(KC_Z); // example of simple linger macro: name "Zoe"
                break;

            case HC_NDSH:
                register_code16(A(KC_MINS));
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
            case HC_hereg_4gram: // TYPE "here" #9
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
            case HC_thereg_5gram: // TYPE "there" #7
                tap_code(KC_T);
                goto here;
/*                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("here");
                combo_on = combo_index; // may add "'s " if held
                break;
*/
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
            case HC_whereg_5gram: // TYPE "where" // this should be a linger add text?
                tap_code(KC_W);
here:
                unregister_code(KC_LSFT); // turn off shift to facilitate
                unregister_code(KC_RSFT); // first-words & Proper nouns.
                send_string("here");
                combo_on = combo_index; // may add "'ve " if held
                break;

// This group all share a suffix, with a goto addonsuffix,
// so keep together 'cause we're messing with stack frames at the end!

            case HC_I:
            case HC_Ig:
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
            case HC_Idg:
            case HC_Ill:
            case HC_Illg:
            case HC_Im:
            case HC_Img:
            case HC_Iv:
            case HC_Ivg:
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
            case HC_youdg_5gram:
            case HC_youll_6gram:
            case HC_youre_6gram:
            case HC_youve_6gram:
                tap_code(KC_Y); // send "Y" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("ou"); // send "We're" right away
                goto addonsuffix;
            case HC_theyd_6gram: // TYPE "they'd " #23
//            case HC_theydg_6gram: // TYPE "they'd " #23
            case HC_theyll_7gram:
//            case HC_theyllg_7gram:
            case HC_theyre_7gram:
//            case HC_theyreg_7gram:
            case HC_theyve_7gram: // "they've"
//            case HC_theyveg_7gram: // "they've"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_code(KC_LSFT); // remove shift here.
                unregister_code(KC_RSFT); // remove shift here.
                send_string("hey"); // send "they" right away
addonsuffix: // sharing this saves about 100 bytes (10 bytes per instance)
                tap_code(KC_QUOT);
                switch (combo_index) { //
                    case HC_Id: // "I'd " …
                    case HC_Idg: // "I'd " …
                    case HC_wed_4gram: // we'd
                    case HC_youd_5gram:
//                    case HC_youdg_5gram:
                    case HC_theyd_6gram: // TYPE "they'd " #23
//                    case HC_theydg_6gram: // TYPE "they'd " #23
                        send_string("d");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
                    case HC_Im:
                    case HC_Img:
                        SEND_STRING("m ");
                        break;
                    case HC_Ill: // "I'll " …
                    case HC_Illg: // "I'll " …
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
                    case HC_Ivg: // "I've " …
                    case HC_weve_5gram: // we've
                    case HC_youve_6gram:
                    case HC_theyve_7gram: // "they've"
//                    case HC_theyveg_7gram: // "they've"
                        send_string("ve ");
                        break;
                    case HC_Chg:
                    case HC_Ch:
                    case HC_Whg:
                    case HC_Wh:
/*
                        tap_code(KC_W); // send "W" honoring caps
                        unregister_code(KC_LSFT); // remove shift here.
                        unregister_code(KC_RSFT); // remove shift here.
                        tap_code(KC_H); // send "h" honoring CAPSLK state
*/
                        combo_on = combo_index; // may add "i" in matrix_scan_user_process_combo
                        break;
               }

// END of the common suffix group with the goto addonsuffix:

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

                case HC_Ch:
                case HC_Chg:
                    tap_code(KC_C); // send "C" honoring caps
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;
                case HC_Gh:
                    tap_code(KC_G); // send "P" honoring caps
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
//                case HC_Shs: // for Silver w/ N on thumb, H on middle
                    if (myKC_C == KC_K) { // in Japanese mode?
                        tap_code(KC_Z); // send "Z"
                    } else {
                        tap_code(KC_S); // send "S" honoring caps
                        unregister_code(KC_LSFT); // remove shift here.
                        unregister_code(KC_RSFT); // remove shift here.
                        tap_code(KC_H); // send "h" honoring CAPSLK state
                    }
                    break;
                case HC_Th:
//                case HC_Ths: // for Silver w/ N on thumb, H on middle
//                case HC_Thg:
                    tap_code(KC_T); // send "T" honoring caps
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;

                case HC_Whg:
                case HC_Wh:
                    tap_code(KC_W); // send "W" honoring caps
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    tap_code(KC_H); // send "h" honoring CAPSLK state
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
                case HC_ould_4gram: // TYPE "ould" #11
                    SEND_STRING("ould");
                    combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                    break;
                case HC_ting_4gram: // TYPE "ting" #12
                    SEND_STRING("ting ");
                    break;
                case HC_ough_4gram: // TYPE "ough" #25
                case HC_oughg_4gram: // TYPE "ough" #25
                    SEND_STRING("ough ");
                    break;

                case HC_I ... HC_where_5gram:
                    tap_code(KC_SPC); // add space after a pronoun
                    combo_on = 0;  // done w/these shenanigans
                    break;
            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
                case HC_Z:
                    unregister_linger_key();
                    break;
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
/*
                case PC_TGNM:
                    layer_on(L_LANG_NUM); // toggle num layer
                    break;
*/
                case PC_SENT:
                    tap_code16(S(KC_ENT)); // this should use semkeys
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
                    tap_code16(A(S(KC_2))); // this should use semkeys
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
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
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
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
/*                case HC_RING:
                     tap_code16(A(KC_K)); // this should use semkeys
                    break;
*/


                case HC_Sh:
//                case HC_Shs: // for Silver
                    tap_code(KC_S); // send "S" honoring caps
                    goto ion;
                case HC_Th: // Works w/ Neu/Bronze/Platinum/Titanium
//                case HC_Ths: // for Silver
//                case HC_Thg: // for Gold
                    tap_code(KC_T); // send "T" honoring caps
ion: // an phonoLOGICAL extension of the Th&Sh digraph phenomenon
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("ion");
                    break;
                case HC_Ch:
                case HC_Chg:
                    tap_code(KC_C); // send "C" honoring caps
                    goto addHI;
                case HC_Whg:
                case HC_Wh:
                    tap_code(KC_W); // send "W" honoring caps
addHI:
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("hi");
                    break;
                case HC_Gh:
                    send_string("lm"); // no need do worry about CAPS on this consonant bigram.

                    break;



                case HC_ing_3gram: // TYPE "ing"
                case HC_ment_4gram: // TYPE "ment" #6
                case HC_ting_4gram: // TYPE "ting" #12
                    SEND_STRING("s ");
                    break;

// PRONOUN shenanigans

                case HC_I:
                case HC_Ig:
                    //tap_code16(S(KC_I)); // send "I" honoring caps
                case HC_Id:
                case HC_Idg:
                case HC_Ill:
                case HC_Illg:
                case HC_ould_4gram: // TYPE "ould " #11
                case HC_they_4gram: // TYPE "they " #23
//                case HC_theyg_4gram: // TYPE "they " #23
                case HC_theyd_6gram: // TYPE "they'd " #23
//                case HC_theydg_6gram: // TYPE "they'd " #23
                case HC_theyll_7gram: // TYPE "they'll " #23
//                case HC_theyllg_7gram: // TYPE "they'll " #23
                case HC_wed_4gram:
                case HC_well_5gram:
                case HC_youd_5gram:
//                case HC_youdg_5gram:https://www.amazon.com/gp/product/B07Z97C45D/ref=ewc_pr_img_3?smid=ATZS6TEUCJJVO&psc=1
                case HC_youll_6gram:
                    unregister_code(KC_LSFT); // remove shift here.
                    unregister_code(KC_RSFT); // remove shift here.
                    send_string("'ve "); // or should it be "'nt"?
                    break;

                case HC_here_4gram:
                case HC_hereg_4gram:
                case HC_your_4gram: // TYPE "your's"
                case HC_their_5gram: // TYPE "their's" #6
                case HC_there_5gram: // TYPE "there's" #7
//                case HC_theirg_5gram: // TYPE "their's" #6
                case HC_thereg_5gram: // TYPE "there's" #7
                case HC_whereg_5gram: //
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
