
//
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5
//
// These definitions based on Hands Down Neu & variations'
// combo keycodes defined in the variation config
//
// Combo definitions defined spatially
// Other variation dependent combos have predetermined
// positions for 34 key boards

const uint16_t PROGMEM HC_cfg_combo[] = {HD_RH1, HD_RH2, COMBO_END}; // keyboard settings/config layer
#ifdef APPMENU_keys
const uint16_t PROGMEM H_menu_combo[] = {APPMENU_keys, COMBO_END}; // AppMENU
#else
const uint16_t PROGMEM H_menu_combo[] = {HD_LB3, HD_LB1, COMBO_END}; // AppMENU // default Appmenu location
#endif
#ifdef APPMENU_nav_keys
const uint16_t PROGMEM H_menu_nav_combo[] = {APPMENU_nav_keys, COMBO_END}; // AppMENU on Nav layer
#else
const uint16_t PROGMEM H_menu_nav_combo[] = {LV_LT1, LV_LT0, COMBO_END}; // AppMENU on Nav layer
#endif

// Spatially arranged on the QWERTY ZXCV locations
//
const uint16_t PROGMEM Htab_combo[] = {HD_tab_keys, COMBO_END};    // tab
const uint16_t PROGMEM Hstab_combo[] = {HD_stab_keys, COMBO_END};  // shift-tab
const uint16_t PROGMEM Hspc_combo[] = {HD_spc_keys, COMBO_END};    // SPACE
const uint16_t PROGMEM Hent_combo[] = {HD_ent_keys, COMBO_END};    // ENTER
const uint16_t PROGMEM Hent2_combo[] = {HD_ent2_keys, COMBO_END};  // hard-ENTER/page break

// SEMANTIC FUNCTIONS  ** usinp SemKeys **
const uint16_t PROGMEM Hnew_combo[] = {HD_new_keys, COMBO_END}; // new
const uint16_t PROGMEM Hopen_combo[] = {HD_open_keys, COMBO_END}; // open
const uint16_t PROGMEM Hclose_combo[] = {HD_close_keys, COMBO_END}; // close
const uint16_t PROGMEM Hquit_combo[] = {HD_quit_keys, COMBO_END}; // quit
const uint16_t PROGMEM Hfind_combo[] = {HD_find_keys, COMBO_END}; // find selection
const uint16_t PROGMEM Hsall_combo[] = {HD_sall_keys, COMBO_END}; // select all
const uint16_t PROGMEM Hswrd_combo[] = {HD_swrd_keys, COMBO_END}; // select word
const uint16_t PROGMEM Hundo_combo[] = {HD_undo_keys, COMBO_END}; // undo
const uint16_t PROGMEM Hredo_combo[] = {HD_redo_keys, COMBO_END}; // redo
const uint16_t PROGMEM Hcopy_combo[] = {HD_copy_keys, COMBO_END}; // copy (hold for cut)
const uint16_t PROGMEM Hpste_combo[] = {HD_pste_keys, COMBO_END}; // paste (hold for paste-match)




const uint16_t PROGMEM H_Left_combo[] = {HD_LT3, HD_LT2, HD_LT1, COMBO_END}; // TYPE LeftComboTapE
const uint16_t PROGMEM H_Right_combo[] = {HD_RT1, HD_RT2, HD_RT3, COMBO_END}; // some demonstrator macro placeholder

const uint16_t PROGMEM F_KILL_combo[] = {HD_RT3, HD_RT0, COMBO_END}; // KILL = Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCLP_combo[] = {HD_LT2, HD_LT1, HD_LT0, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {HD_LT3, HD_LT2, HD_LT1, HD_LT0, COMBO_END}; //  SCREEN shot SELECTION to file


const uint16_t PROGMEM H_CAPW_combo[] = {HD_RB3, HD_RB4, COMBO_END}; // CAPS WORD (on until word delimiter)
const uint16_t PROGMEM F_CAPS_combo[] = {HD_RB2, HD_RB3, HD_RB4, COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_EISUU_combo[] = {HD_LM3, HD_LM2, HD_LM1, COMBO_END}; // KC_MHEN
const uint16_t PROGMEM H_KANA_combo[] = {HD_RM3, HD_RM2, HD_RM1, COMBO_END}; // KC_HENK



// Off map and other letter/symbol thingies typically on keyboard

// RIGHT HAND
// should work for most Neu variations (Gold/Titanium/Rhodium/Vibranium)
// Bronze/Silver/Platinum (C on right hand, H on left/thumb) may need changes...
//
const uint16_t PROGMEM F_ESC_combo[] = {HD_LM4, HD_LM1, COMBO_END}; // ESCape
const uint16_t PROGMEM Hndsh_combo[] = {HD_RB0, HD_RB1, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {HD_RB0, HD_RB2, COMBO_END}; // — m dash
const uint16_t PROGMEM Htild_combo[] = {HD_RB1, HD_RB4, COMBO_END}; // ~ tilde (not the deadkey for eñye)
const uint16_t PROGMEM Hunds_combo[] = {HD_RB1, HD_RB3, COMBO_END}; // _ underscore
const uint16_t PROGMEM Hequal_combo[] = {HD_RB2, HD_RB3, COMBO_END}; // = equal (hold for %)
//const uint16_t PROGMEM Hpercent_combo[] = {HD_RB3, HD_RB4, COMBO_END}; // % percent


// spatially arranged characters and diacritics
const uint16_t PROGMEM Hscln_combo[] = {HD_RM0, HD_RM1, COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {HD_RT1, HD_RT3, COMBO_END}; // : colon
const uint16_t PROGMEM Hexlm_combo[] = {HD_RT1, HD_RT2, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {HD_RT2, HD_RT3, COMBO_END}; // ?
const uint16_t PROGMEM Hdolr_combo[] = {HD_RT2, HD_RT4, COMBO_END}; // " DOUBLE QUOTE  // " hijacked for $
const uint16_t PROGMEM Htic_combo[] = {HD_RT3, HD_RT4, COMBO_END}; // ` tic (not dead key grave)

const uint16_t PROGMEM Hhash_combo[] = {HD_RT0, HD_RT2, COMBO_END}; // # HASH hijacked for §
const uint16_t PROGMEM Hat_combo[] = {HD_RT0, HD_RT1, COMBO_END}; // @

// spatially arranged diacritics
const uint16_t PROGMEM Hdier_combo[] = {HD_RB1, HD_RB2, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Henye_combo[] = {HD_LT4, HD_LT0, COMBO_END}; // ˜ enye (dead key) (ñ only?)
const uint16_t PROGMEM Hacut_combo[] = {HD_RM1, HD_RM2, COMBO_END}; // ´ acute (dead key)é
const uint16_t PROGMEM Hgrv_combo[] = {HD_RM2, HD_RM3, COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {HD_RM1, HD_RM3, COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {HD_RM2, HD_RM4, COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hring_combo[] = {HD_RM1, HD_RM4, COMBO_END}; // ˚ ring (dead key)
const uint16_t PROGMEM Hcedi_combo[] = {HD_LM4, HD_LM2, COMBO_END}; // ¸ cedille (dead key)
//const uint16_t PROGMEM Hoslsh_combo[] = {HD_RB2, HD_LB0, COMBO_END}; // ø/Ø or Wh

// Precomposed letters with diacritics (uses expanded Semantic Keys)
// This could be a very large numper of comboos, as many as 35 for vowels
// áàâåäā éèêe̊ëē íìîīï óòôo̊ōü úùûůūü 
// two handed combos with home-row [p, r, m, i, l] + vowel
// and many more for frequently used consonants
// two handed combos top/bottom row vowel hand?


// TEXT ENTRY - off map standard alphas (also on Layer L_SYM @ J & G respectively)byby=
const uint16_t PROGMEM H_Q_combo[] = {HD_Qu_keys, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)
const uint16_t PROGMEM H_L1_combo[] = {HD_L1_keys, COMBO_END}; // ex. TYPE "z"
//const uint16_t PROGMEM H_L2_combo[] = {HD_L2_keys, COMBO_END}; // ex. TYPE "x"
//const uint16_t PROGMEM H_L3_combo[] = {HD_L3_keys, COMBO_END}; // ex. TYPE "j"

// H digraph combos (ideally, these are phonetically/mnemonically arranged

const uint16_t PROGMEM H_Th_combo[] = {HD_Th_keys, COMBO_END}; // TYPE "th"
const uint16_t PROGMEM H_Ch_combo[] = {HD_Ch_keys, COMBO_END}; // TYPE "ch"
const uint16_t PROGMEM H_Wh_combo[] = {HD_Wh_keys, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Sh_combo[] = {HD_Sh_keys, COMBO_END}; // TYPE "sh"
const uint16_t PROGMEM H_Ph_combo[] = {HD_Ph_keys, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[] = {HD_Gh_keys, COMBO_END}; // TYPE "gh"
const uint16_t PROGMEM H_Sch_combo[] = {HD_Sch_keys, COMBO_END}; // TYPE "Sch"

// TEXT ENTRY - (ANY ROW/ MIXED ROWS)

const uint16_t PROGMEM HOE_lig_combo[] = {HD_OE_lig_keys, COMBO_END}; // Œ
const uint16_t PROGMEM HAE_lig_combo[] = {HD_AE_lig_keys, COMBO_END}; // Æ


// Fast 4grams

#ifdef EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

// PRONOUNS Fast 4-7grams
const uint16_t PROGMEM H_Icap_combo[] = {HD_Icap_keys, COMBO_END}; // TYPE "I"
const uint16_t PROGMEM H_Id_combo[] = {HD_Id_keys, COMBO_END}; // TYPE "I'd"+"'ve "
const uint16_t PROGMEM H_Ill_combo[] = {HD_Ill_keys, COMBO_END}; // TYPE "I'll"+"'ve "
const uint16_t PROGMEM H_Im_combo[] = {HD_Im_keys, COMBO_END}; // TYPE "I'm "
const uint16_t PROGMEM H_Iv_combo[] = {HD_Iv_keys, COMBO_END}; // TYPE "I've "

#ifdef EN_PRONOUN_COMBOS_ALL
const uint16_t PROGMEM H_youd_combo[] = {HD_youd_keys, COMBO_END}; // TYPE "you'd" + 've
const uint16_t PROGMEM H_youll_combo[] = {HD_youll_keys, COMBO_END}; // TYPE "you'll" + 've
const uint16_t PROGMEM H_youre_combo[] = {HD_youre_keys, COMBO_END}; // TYPE "you're"
const uint16_t PROGMEM H_youve_combo[] = {HD_youve_keys, COMBO_END}; // TYPE "you've"
const uint16_t PROGMEM H_your_combo[] = {HD_your_keys, COMBO_END}; // TYPE "your" "P" for "possessive" case
const uint16_t PROGMEM H_their_combo[] = {HD_their_keys, COMBO_END}; // TYPE "their" #6
const uint16_t PROGMEM H_they_combo[] = {HD_they_keys, COMBO_END}; // "they" #23 + 've
const uint16_t PROGMEM H_theyd_combo[] = {HD_theyd_keys, COMBO_END}; // "they'd" #23 + 've
const uint16_t PROGMEM H_theyll_combo[] = {HD_theyll_keys, COMBO_END}; // "they'll" #23 + 've
const uint16_t PROGMEM H_theyre_combo[] = {HD_theyre_keys, COMBO_END}; // "they're"

const uint16_t PROGMEM H_there_combo[] = {HD_there_keys, COMBO_END}; // TYPE "there" #7 + 's
const uint16_t PROGMEM H_here_combo[] = {HD_here_keys, COMBO_END}; // TYPE "here" #5 + 's

#ifdef EN_W_PRONOUNS
const uint16_t PROGMEM H_where_combo[] = {HD_where_keys, COMBO_END}; // "where" + 's
const uint16_t PROGMEM H_were_combo[] = {HD_were_keys, COMBO_END}; // TYPE "we're"
const uint16_t PROGMEM H_wed_combo[] = {HD_wed_keys, COMBO_END}; // TYPE "we'd" + 've
const uint16_t PROGMEM H_well_combo[] = {HD_well_keys, COMBO_END}; // TYPE "we'll" + 've
const uint16_t PROGMEM H_weve_combo[] = {HD_weve_keys, COMBO_END}; // TYPE "we've"
#endif // EN_W_PRONOUNS

#endif // EN_PRONOUN_COMBOS_ALL

#endif // EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

// TWO HANDS

// 53 Japanese contract consonant combos.
// Some of these will conflict with diacritics (noted below),
// so some sort of mode-switch is necessary for both to be used on the same board.
//
// Also, these should be coded phonetically, not spatially, but there is risk of
// conflict with spatial and phonetically/mnemonically coded combos.
// already, some conflicts with diacritic or pronoun combos
// that are also phonetically/mnemonically (noted here).
//

#ifdef JP_MODE_ENABLE
#ifdef JP_YOUON_COMBOS  // Major Japanese contracted sounds as combos
const uint16_t PROGMEM kya_combo[] = {JP_kya_keys, COMBO_END};  // きゃ
const uint16_t PROGMEM kyu_combo[] = {JP_kyu_keys, COMBO_END};  //　きゅ
const uint16_t PROGMEM kyo_combo[] = {JP_kyo_keys, COMBO_END};  //　きょ
const uint16_t PROGMEM sya_combo[] = {JP_sya_keys, COMBO_END};  // しゃ
const uint16_t PROGMEM syu_combo[] = {JP_syu_keys, COMBO_END};  //　しゅ
const uint16_t PROGMEM sye_combo[] = {JP_sye_keys, COMBO_END};  //　しぇ
const uint16_t PROGMEM syo_combo[] = {JP_syo_keys, COMBO_END};  //　しょ
const uint16_t PROGMEM zya_combo[] = {JP_zya_keys, COMBO_END};  // じゃ
const uint16_t PROGMEM zyu_combo[] = {JP_zyu_keys, COMBO_END};  //　じゅ
const uint16_t PROGMEM zyo_combo[] = {JP_zyo_keys, COMBO_END};  //　じょ
const uint16_t PROGMEM tya_combo[] = {JP_tya_keys, COMBO_END};  // ちゃ
const uint16_t PROGMEM tyu_combo[] = {JP_tyu_keys, COMBO_END};  //　ちゅ
const uint16_t PROGMEM tye_combo[] = {JP_tye_keys, COMBO_END};  // ちぇ
const uint16_t PROGMEM tyo_combo[] = {JP_tyo_keys, COMBO_END};  //　ちょ
const uint16_t PROGMEM pya_combo[] = {JP_pya_keys, COMBO_END};  // ぴゃ
const uint16_t PROGMEM pyu_combo[] = {JP_pyu_keys, COMBO_END};  //　ぴゅ
const uint16_t PROGMEM pyo_combo[] = {JP_pyo_keys, COMBO_END};  //　ぴょ

#ifdef JP_YOUON_COMBOS_ALL // All Japanese contracted sounds

const uint16_t PROGMEM gya_combo[] = {JP_gya_keys, COMBO_END};  // ぎゃ
const uint16_t PROGMEM gyu_combo[] = {JP_gyu_keys, COMBO_END};  //　ぎゅ
const uint16_t PROGMEM gyo_combo[] = {JP_gyo_keys, COMBO_END};  //　ぎょ
const uint16_t PROGMEM tha_combo[] = {JP_tha_keys, COMBO_END};  // てゃ
const uint16_t PROGMEM thi_combo[] = {JP_thi_keys, COMBO_END};  // てぃ
const uint16_t PROGMEM thu_combo[] = {JP_thu_keys, COMBO_END};  //　てゅ
const uint16_t PROGMEM the_combo[] = {JP_the_keys, COMBO_END};  // てぇ
const uint16_t PROGMEM tho_combo[] = {JP_tho_keys, COMBO_END};  //　てょ
const uint16_t PROGMEM dha_combo[] = {JP_dha_keys, COMBO_END};  // でゃ
#ifndef EN_PRONOUN_COMBOS
const uint16_t PROGMEM dhi_combo[] = {JP_dhi_keys, COMBO_END};  // でぃ conflicts with I'd
#endif
const uint16_t PROGMEM dhu_combo[] = {JP_dhu_keys, COMBO_END};  //　でゅ
const uint16_t PROGMEM dhe_combo[] = {JP_dhe_keys, COMBO_END};  // でぇ
const uint16_t PROGMEM dho_combo[] = {JP_dho_keys, COMBO_END};  //　でょ
const uint16_t PROGMEM nya_combo[] = {JP_nya_keys, COMBO_END};  // にゃ
const uint16_t PROGMEM nyu_combo[] = {JP_nyu_keys, COMBO_END};  //　にゅ
const uint16_t PROGMEM nyo_combo[] = {JP_nyo_keys, COMBO_END};  //　にょ

//fconst uint16_t PROGMEM hya_combo[] = {JP_hya_keys, COMBO_END};  // ひゃ　conflicts with diacritic?
const uint16_t PROGMEM hyu_combo[] = {JP_hyu_keys, COMBO_END};  //　ひゅ
const uint16_t PROGMEM hyo_combo[] = {JP_hyo_keys, COMBO_END};  //　ひょ

const uint16_t PROGMEM bya_combo[] = {JP_bya_keys, COMBO_END};  // びゃ
const uint16_t PROGMEM byu_combo[] = {JP_byu_keys, COMBO_END};  //　びゅ  potential conflict?
const uint16_t PROGMEM byo_combo[] = {JP_byo_keys, COMBO_END};  //　びょ
const uint16_t PROGMEM mya_combo[] = {JP_mya_keys, COMBO_END};  // みゃ
const uint16_t PROGMEM myu_combo[] = {JP_myu_keys, COMBO_END};  //　みゅ
const uint16_t PROGMEM myo_combo[] = {JP_myo_keys, COMBO_END};  //　みょ
const uint16_t PROGMEM rya_combo[] = {JP_rya_keys, COMBO_END};  // りゃ
const uint16_t PROGMEM ryu_combo[] = {JP_ryu_keys, COMBO_END};  //　りゅ
const uint16_t PROGMEM ryo_combo[] = {JP_ryo_keys, COMBO_END};  //　りょ
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_YOUON_COMBOS
#endif // JP_MODE_ENABLE


//
//  (22) keypad combos
// These are not abstracted to location, as they are not on an HD alpha layer
//
const uint16_t PROGMEM PNLCK_combo[] = {RSFT_T(KC_P4), RGUI_T(KC_P5), RALT_T(KC_P6), COMBO_END}; // toggle numlck from num layer
const uint16_t PROGMEM P0E_combo[] = {KC_P0, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCME_combo[] = {KC_PDOT, KC_PEQL, COMBO_END};
const uint16_t PROGMEM PCM1_combo[] = {KC_PDOT, KC_P1, COMBO_END};
const uint16_t PROGMEM PCM2_combo[] = {KC_PDOT, KC_P2, COMBO_END};
const uint16_t PROGMEM P01_combo[] = {KC_P0, KC_P1, COMBO_END};
const uint16_t PROGMEM P02_combo[] = {KC_P0, KC_P2, COMBO_END};
const uint16_t PROGMEM P04_combo[] = {KC_P0, RSFT_T(KC_P4), COMBO_END};
const uint16_t PROGMEM P05_combo[] = {KC_P0, RGUI_T(KC_P5), COMBO_END};
const uint16_t PROGMEM P12_combo[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM P23_combo[] = {KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM P13_combo[] = {KC_P1, KC_P3, COMBO_END};
const uint16_t PROGMEM P1E_combo[] = {KC_P1, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P2E_combo[] = {KC_P2, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P3E_combo[] = {KC_P3, KC_PEQL, COMBO_END};
const uint16_t PROGMEM P45_combo[] = {RSFT_T(KC_P4), RGUI_T(KC_P5), COMBO_END};
const uint16_t PROGMEM P56_combo[] = {RGUI_T(KC_P5), RALT_T(KC_P6), COMBO_END};
const uint16_t PROGMEM P46_combo[] = {RSFT_T(KC_P4), RALT_T(KC_P6), COMBO_END};
const uint16_t PROGMEM P5PLS_combo[] = {RGUI_T(KC_P5), RCTL_T(KC_PPLS), COMBO_END};
const uint16_t PROGMEM P6PLS_combo[] = {RALT_T(KC_P6), RCTL_T(KC_PPLS), COMBO_END};
const uint16_t PROGMEM PS7_combo[] = {KC_PSLS, KC_P7, COMBO_END};
const uint16_t PROGMEM P78_combo[] = {KC_P7, KC_P8, COMBO_END};
const uint16_t PROGMEM P79_combo[] = {KC_P7, KC_P9, COMBO_END};
const uint16_t PROGMEM P89_combo[] = {KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM P9M_combo[] = {KC_P9, KC_PMNS, COMBO_END};
const uint16_t PROGMEM PSLT_combo[] = {KC_P7, KC_PMNS, COMBO_END};
const uint16_t PROGMEM PPLMN_combo[] = {RSFT_T(KC_P4), RCTL_T(KC_PPLS), COMBO_END};


combo_t key_combos[] = {
    // These simple combos trigger on press, repeat. HC_cfg_combo
    [HC_CFG] = COMBO(HC_cfg_combo, MO(L_CFG)), // keyboard/media settings/config layer
    [HC_APP] = COMBO(H_menu_combo, KC_APP), // app menu
    [HC_APPNAV] = COMBO(H_menu_nav_combo, KC_APP), // app menu
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO_ACTION(Hcoln_combo), // :  (hold for elipsis)
    [HC_UNDS] = COMBO_ACTION(Hunds_combo), // _ underscore
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~ or SK_TILD?
    [HC_TIC] = COMBO(Htic_combo, KC_GRAVE),  // ` (not dead)
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_DOLR] = COMBO(Hdolr_combo, KC_DLR), // $
    [HC_HASH] = COMBO(Hhash_combo, SK_SECT), // # hijacked for §
    [HC_AT] = COMBO_ACTION(Hat_combo), // @ (hold for alanreiser.com)
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),
    [HC_STAB] = COMBO(Hstab_combo, S(KC_TAB)),

    [HC_Q] = COMBO_ACTION(H_Q_combo),
    [HC_L1] = COMBO(H_L1_combo, HD_L1),
//    [HC_L2] = COMBO(H_L2_combo, HD_L2),
//    [HC_L3] = COMBO(H_L3_combo, HD_L3),
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
    [HC_Sch] = COMBO_ACTION(H_Sch_combo),
    [HC_Gh] = COMBO_ACTION(H_Gh_combo),
    [HC_Ph] = COMBO_ACTION(H_Ph_combo),
    [HC_Th] = COMBO_ACTION(H_Th_combo),
    [HC_Sh] = COMBO_ACTION(H_Sh_combo),
    [HC_Wh] = COMBO_ACTION(H_Wh_combo),

    [HC_OE] = COMBO_ACTION(HOE_lig_combo),  // Œ
    [HC_AE] = COMBO_ACTION(HAE_lig_combo),  // Æ

// Japanese contract consonants
#ifdef JP_MODE_ENABLE  // Japanese contracted sounds as combos
#ifdef JP_YOUON_COMBOS  // Japanese contracted sounds as combos
    [jp_kya] = COMBO_ACTION(kya_combo),  // きゃ
    [jp_kyu] = COMBO_ACTION(kyu_combo),  // きゅ
    [jp_kyo] = COMBO_ACTION(kyo_combo),  // きょ
    [jp_sya] = COMBO_ACTION(sya_combo),  // しゃ
    [jp_syu] = COMBO_ACTION(syu_combo),  // しゅ
    [jp_sye] = COMBO_ACTION(sye_combo),  // しぇ
    [jp_syo] = COMBO_ACTION(syo_combo),  // しょ
    [jp_zya] = COMBO_ACTION(zya_combo),  // じゃ
    [jp_zyu] = COMBO_ACTION(zyu_combo),  // じゅ
    [jp_zyo] = COMBO_ACTION(zyo_combo),  // じょ
    [jp_tya] = COMBO_ACTION(tya_combo),  // ちゃ
    [jp_tyu] = COMBO_ACTION(tyu_combo),  // ちゅ
    [jp_tye] = COMBO_ACTION(tye_combo),  // ちぇ
    [jp_tyo] = COMBO_ACTION(tyo_combo),  // ちょ
    [jp_pya] = COMBO_ACTION(pya_combo),  // ぴゃ
    [jp_pyu] = COMBO_ACTION(pyu_combo),  // ぴゅ
    [jp_pyo] = COMBO_ACTION(pyo_combo),  // ぴょ

#ifdef JP_YOUON_COMBOS_ALL // JP_YOUON_COMBOS_ALL
    [jp_gya] = COMBO_ACTION(gya_combo),  // ぎゃ
    [jp_gyu] = COMBO_ACTION(gyu_combo),  // ぎゅ
    [jp_gyo] = COMBO_ACTION(gyo_combo),  // ぎょ
    [jp_tha] = COMBO_ACTION(tha_combo),  // てゃ
    [jp_thi] = COMBO_ACTION(thi_combo),  // てぃ
    [jp_thu] = COMBO_ACTION(thu_combo),  // てゅ
    [jp_the] = COMBO_ACTION(the_combo),  // てぇ
    [jp_tho] = COMBO_ACTION(tho_combo),  // てょ
    [jp_dha] = COMBO_ACTION(dha_combo),  // でゃ
#ifndef EN_PRONOUN_COMBOS
    [jp_dhi] = COMBO_ACTION(dhi_combo),  // でぃ conflicts with I'd
#endif
    [jp_dhu] = COMBO_ACTION(dhu_combo),  // でゅ
    [jp_dhe] = COMBO_ACTION(dhe_combo),  // でぇ
    [jp_dho] = COMBO_ACTION(dho_combo),  // でょ
    [jp_nya] = COMBO_ACTION(nya_combo),  // にゃ
    [jp_nyu] = COMBO_ACTION(nyu_combo),  // にゅ
    [jp_nyo] = COMBO_ACTION(nyo_combo),  // にょ
//    [jp_hya] = COMBO_ACTION(hya_combo),  // ひゃ conflicts with diactric combos
    [jp_hyu] = COMBO_ACTION(hyu_combo),  // ひゅ
    [jp_hyo] = COMBO_ACTION(hyo_combo),  // ひょ
    [jp_bya] = COMBO_ACTION(bya_combo),  // びゃ
    [jp_byu] = COMBO_ACTION(byu_combo),  // びゅ potential conflict with diactric combos
    [jp_byo] = COMBO_ACTION(byo_combo),  // びょ
    [jp_mya] = COMBO_ACTION(mya_combo),  // みゃ
    [jp_myu] = COMBO_ACTION(myu_combo),  // みゅ
    [jp_myo] = COMBO_ACTION(myo_combo),  // みょ
    [jp_rya] = COMBO_ACTION(rya_combo),  // りゃ
    [jp_ryu] = COMBO_ACTION(ryu_combo),  // りゅ
    [jp_ryo] = COMBO_ACTION(ryo_combo),  // りょ

#endif // JP_YOUON_COMBOS_ALL  // All Japanese contracted sounds
#endif // JP_YOUON_COMBOS  // Japanese contracted sounds as combos
#endif // JP_MODE_ENABLE

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
    
    [HC_EQL] = COMBO_ACTION(Hequal_combo), // =  (hold for %)
    [PC_SENT] = COMBO_ACTION(P2E_combo), // shift-<enter> on num
    [PC_TGNM] = COMBO(PNLCK_combo, KC_NUM), // toggle num lock
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

    [FC_LANG2] = COMBO(H_EISUU_combo, SK_MHEN), // eisuu (others)
    [FC_LANG1] = COMBO(H_KANA_combo, SK_HENK), // kana (others)

    [HC_NDSH] = COMBO_ACTION(Hndsh_combo), // – N-DASH
    [HC_MDSH] = COMBO_ACTION(Hmdsh_combo), // — M-DASH
    
// Dead keys (Mac only, for now)
    [HC_ACUT] = COMBO_ACTION(Hacut_combo), // ´ acute
    [HC_GRV] = COMBO_ACTION(Hgrv_combo), // ` grave
    [HC_CIRC] = COMBO_ACTION(Hcirc_combo), // ˆ circumflex
    [HC_MACR] = COMBO_ACTION(Hmacr_combo), // - macron
    [HC_DIER] = COMBO_ACTION(Hdier_combo), // ¨ dieresis
    [HC_RING] = COMBO_ACTION(Hring_combo), // ˚ ring
    [HC_CEDILLE] = COMBO_ACTION(Hcedi_combo), // ¸ cedille
    [HC_ENYE] = COMBO_ACTION(Henye_combo), // ˜ tilde (dead)
//    [HC_OSLSH] = COMBO_ACTION(Hoslsh_combo), // ø/Ø or Wh

//    [HC_ENYE] = COMBO(Henye_combo, SK_ENYE), // ñ/Ñ enye
//    [HC_ELIP] = COMBO_ACTION(Helip_combo),  // …


// Fast entry 4grams

#ifdef EN_PRONOUN_COMBOS
// PRONOUNS Fast entry 4-7gram PRONOUNS (an English quirk)
    [HC_I] = COMBO_ACTION(H_Icap_combo),// TYPE "I"+"'ve "
    [HC_Id] = COMBO_ACTION(H_Id_combo),// TYPE "I'd "
    [HC_Ill] = COMBO_ACTION(H_Ill_combo),// TYPE "I'll "
    [HC_Im] = COMBO_ACTION(H_Im_combo),// TYPE "I'm  "
    [HC_Iv] = COMBO_ACTION(H_Iv_combo),// TYPE "I've  "

#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
    [HC_wed_4gram] = COMBO_ACTION(H_wed_combo),// TYPE "we'd"
    [HC_well_5gram] = COMBO_ACTION(H_well_combo),// TYPE "we'll"
    [HC_were_5gram] = COMBO_ACTION(H_were_combo),// TYPE "we're"
    [HC_weve_5gram] = COMBO_ACTION(H_weve_combo),// TYPE "we've"
    [HC_where_5gram] = COMBO_ACTION(H_where_combo), // TYPE "where"
#endif // EN_W_PRONOUNS
    [HC_youd_5gram] = COMBO_ACTION(H_youd_combo),// TYPE "you'd"
    [HC_youll_6gram] = COMBO_ACTION(H_youll_combo),// TYPE "you'll"
    [HC_youre_6gram] = COMBO_ACTION(H_youre_combo),// TYPE "you're"
    [HC_youve_6gram] = COMBO_ACTION(H_youve_combo),// TYPE "you've"
    [HC_your_4gram] = COMBO_ACTION(H_your_combo),// TYPE "your"
    [HC_they_4gram] = COMBO_ACTION(H_they_combo), // TYPE "they" #23
    [HC_their_5gram] = COMBO_ACTION(H_their_combo), // TYPE "their" #6
    [HC_theyre_7gram] = COMBO_ACTION(H_theyre_combo), // TYPE "they're"

    [HC_there_5gram] = COMBO_ACTION(H_there_combo), // TYPE "there" #7
    [HC_here_4gram] = COMBO_ACTION(H_here_combo), // TYPE "here" #9

#endif // EN_PRONOUN_COMBOS_ALL
#endif // EN_PRONOUN_COMBOS

    [HC_TYPE_LEFTCOMBO] = COMBO_ACTION(H_Left_combo), // a personally useful 5-8gram!
    [HC_TYPE_RIGHTCOMBO] = COMBO_ACTION(H_Right_combo), // a demonstrator, how long autotypes can be!
    
    [HC_SPC] = COMBO(Hspc_combo, KC_SPC), // SPACE
    [HC_ENT] = COMBO(Hent_combo, KC_ENT), // ENTER
    [HC_ENT2] = COMBO(Hent2_combo, SK_HENT), // hard-ENTER

/* These all use SemKeys, even as simple combos (handled by process_semkey from process_record_user) */
    [HC_NEW] = COMBO(Hnew_combo, SK_NEW),
    [HC_OPEN] = COMBO(Hopen_combo, SK_OPEN),
    [HC_CLOZ] = COMBO(Hclose_combo, SK_CLOZ),
    [HC_QUIT] = COMBO(Hquit_combo, SK_QUIT),
    [HC_FIND] = COMBO_ACTION(Hfind_combo),
    [HC_SALL] = COMBO(Hsall_combo, SK_SALL),
    [HC_SWRD] = COMBO(Hswrd_combo, SK_SWRD),
    [HC_UNDO] = COMBO(Hundo_combo, SK_UNDO),
    [HC_REDO] = COMBO(Hredo_combo, SK_REDO),
//    [HC_CUT] = COMBO(Hcut_combo, SK_CUT), // also hold copy (no longer used?)
    [HC_COPY] = COMBO_ACTION(Hcopy_combo), // using hold for cut
//    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM),  // also hold paste (no longer used?)
    [HC_PSTE] = COMBO_ACTION(Hpste_combo) // using hold for paste-match
    
};
