/*
 Combos
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 Tailored for Hands Down Neu-rx a.k.a. Rhodium
 Others have been removed, but I'll try to get everything in here soon enough.
 Finally getting to the last of imagined features that spurred Hands Down design!
  
 */

#include "personalizedmacros.h"

#ifndef At_ComboHeld
#define At_ComboHeld ".com"
#endif
#ifndef LeftComboTapE
#define LeftComboTapE "LeftCombo tapped"
#endif
#ifndef LeftComboHeldE
#define LeftComboHeldE "LeftCombo held"
#endif
#ifndef LeftComboTapJ
#define LeftComboTapJ "hidarikombotappu"
#endif
#ifndef LeftComboHeldJ
#define LeftComboHeldJ "hidarikombochouosi"
#endif
#ifndef RightComboTapE
#define RightComboTapE "RightCombo tapped"
#endif
#ifndef RightComboHeldE
#define RightComboHeldE "RightCombo held"
#endif
#ifndef RightComboTapJ
#define RightComboTapJ "migikombotappu"
#endif
#ifndef RightComboHeldJ
#define RightComboHeldJ "migikombochouosi"
#endif


/*
 For Titanium

 x g m p j  # . / " '
 c s n t k  , a e i h
 w f l d v  - u o y b
    bspc r  spc ret
*/


uint16_t COMBO_LEN = COMBO_LENGTH;

// for 34 key boards
const uint16_t PROGMEM HC_kbd_combo[] = {LT(L_PUNCT,KC_SPC), LT(L_NAV,KC_ENT), COMBO_END}; // keyboard settings/config layer
const uint16_t PROGMEM H_menu_combo[] = {LT(L_FN_NUM, KC_BSPC), LT(L_NAV, KC_H), COMBO_END}; // MENU

/* examples of text entry combos */
const uint16_t PROGMEM H_Left_combo[] = {KC_G, KC_M, KC_P, COMBO_END}; // TYPE LeftComboTapE
const uint16_t PROGMEM H_Right_combo[] = {KC_DOT, KC_SLSH, KC_DQUO, COMBO_END}; // some demonstrator macro placeholder

const uint16_t PROGMEM F_KILL_combo[] = {KC_DQUO, KC_HASH, COMBO_END}; // KILL = Force quit OR CTRL-ALT-DEL
const uint16_t PROGMEM F_SCLP_combo[] = {KC_M, KC_P, KC_J, COMBO_END}; // SCREEN shot SELECTION to clipboard
const uint16_t PROGMEM F_SCAP_combo[] = {KC_G, KC_M, KC_P, KC_J, COMBO_END}; //  SCREEN shot SELECTION to file


const uint16_t PROGMEM F_CAPS_combo[] = {RALT_T(KC_S), RGUI_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), COMBO_END}; // CAPS LOCK (on until hit again)
const uint16_t PROGMEM H_CAPW_combo[] = {RSFT_T(KC_T), RGUI_T(KC_N), RSFT_T(KC_A), RGUI_T(KC_E), COMBO_END}; // CAPS WORD (on until word delimiter)
const uint16_t PROGMEM H_EISUU_combo[] = {RALT_T(KC_S), RGUI_T(KC_N), RSFT_T(KC_T), COMBO_END}; // KC_MHEN
const uint16_t PROGMEM H_KANA_combo[] = {RALT_T(KC_I), RGUI_T(KC_E), RSFT_T(KC_A), COMBO_END}; // KC_HENK


//  (22) keypad combos
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


// Off map and other letter/symbol thingies typically on keyboard

// RIGHT HAND

  // for HANDS DOWN Chromium
const uint16_t PROGMEM F_ESC_combo[] = {RCTL_T(KC_C), RSFT_T(KC_T), COMBO_END}; // ESCape
const uint16_t PROGMEM Hndsh_combo[] = {KC_MINS, KC_U, COMBO_END}; // – n dash
const uint16_t PROGMEM Hmdsh_combo[] = {KC_MINS, KC_O, COMBO_END}; // — m dash
const uint16_t PROGMEM Htild_combo[] = {KC_MINS, KC_B, COMBO_END}; // ~ tilde (not the deadkey for eñye)
const uint16_t PROGMEM Hunds_combo[] = {KC_U, KC_Y, COMBO_END}; // _ underscore
const uint16_t PROGMEM Hequal_combo[] = {KC_O, KC_Y, COMBO_END}; // = equal
const uint16_t PROGMEM Hpercent_combo[] = {KC_Y, KC_B, COMBO_END}; // % percent


// spatially arranged characters and diacritics
const uint16_t PROGMEM Hscln_combo[] = {KC_DOT, KC_DQUO, COMBO_END}; // ; semicolon
const uint16_t PROGMEM Hcoln_combo[] = {KC_DOT, KC_QUOT, COMBO_END}; // : colon
const uint16_t PROGMEM Hexlm_combo[] = {KC_DOT, KC_SLSH, COMBO_END}; // !
const uint16_t PROGMEM Hques_combo[] = {KC_SLSH, KC_DQUO, COMBO_END}; // ?
const uint16_t PROGMEM Hdquo_combo[] = {KC_SLSH, KC_QUOT, COMBO_END}; // " DOUBLE QUOTE  // " hijacked for $
const uint16_t PROGMEM Htic_combo[] = {KC_DQUO, KC_QUOT, COMBO_END}; // ` tic (not dead key grave)

const uint16_t PROGMEM Hhash_combo[] = {KC_HASH, KC_SLSH, COMBO_END}; // # HASH hijacked for §
const uint16_t PROGMEM Hat_combo[] = {KC_HASH, KC_DOT, COMBO_END}; // @

// spatially arranged diacritics
const uint16_t PROGMEM Hdier_combo[] = {KC_U, KC_O, COMBO_END}; // ¨ dieresis (dead key)
const uint16_t PROGMEM Henye_combo[] = {KC_G, KC_J, COMBO_END}; // ˜ enye (dead key) (ñ only?)
const uint16_t PROGMEM Hacut_combo[] = {RSFT_T(KC_A), RGUI_T(KC_E), COMBO_END}; // ´ acute (dead key)é

 // for Neu/Au/Ti/Rh
const uint16_t PROGMEM Hgrv_combo[] = {RGUI_T(KC_E), RALT_T(KC_I), COMBO_END}; // ` grave (dead key)
const uint16_t PROGMEM Hcirc_combo[] = {RSFT_T(KC_A), RALT_T(KC_I), COMBO_END}; // ˆ circumflex (dead key)
const uint16_t PROGMEM Hmacr_combo[] = {RGUI_T(KC_E), RCTL_T(KC_H), COMBO_END}; // - macron (dead key)
const uint16_t PROGMEM Hring_combo[] = {RSFT_T(KC_A), RCTL_T(KC_H), COMBO_END}; // ˚ ring (dead key)
const uint16_t PROGMEM Hcedi_combo[] = {RCTL_T(KC_C), RGUI_T(KC_N), COMBO_END}; // ¸ cedille (dead key)
//const uint16_t PROGMEM Hoslsh_combo[] = {KC_O, KC_W, COMBO_END}; // ø/Ø or Wh

// TEXT ENTRY - off map standard alphas (also on Layer L_PUNCT @ J & G respectively)byby=
const uint16_t PROGMEM H_Z_combo[] = {KC_X, KC_G, COMBO_END}; // TYPE "z"
const uint16_t PROGMEM H_Q_combo[] = {KC_G, KC_P, COMBO_END}; // TYPE "q" (Qu & Linger deletes u)

// H digraphs

const uint16_t PROGMEM H_Th_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), COMBO_END}; // "th"
const uint16_t PROGMEM H_Sh_combo[] = {RALT_T(KC_S), RGUI_T(KC_N), COMBO_END}; // "sh"
const uint16_t PROGMEM H_Ch_combo[] = {RALT_T(KC_S), RSFT_T(KC_T), COMBO_END}; // TYPE "ch"
const uint16_t PROGMEM H_Wh_combo[] = {KC_F, KC_D, COMBO_END}; // TYPE "wh"
const uint16_t PROGMEM H_Ph_combo[] = {KC_M, KC_P, COMBO_END}; // TYPE "ph"
const uint16_t PROGMEM H_Gh_combo[] = {KC_G, KC_M, COMBO_END}; // TYPE "gh"
//const uint16_t PROGMEM H_Sc_combo[] = {RCTL_T(KC_C), RALT_T(KC_S), COMBO_END}; // TYPE "Sc" (SC is 5.6x more common than "CS", so this is the single worst roll on this incarnation. Fix it with a combo, since swapping pinky and ring finger columns creates a bunch of other undesirable things that, individually aren't nearly as severe but add up to close to the same problem. Collectively they are very annoying, and are very hard to solve, because they are so many smaller annoyances. So this one combo, bandaid that it is, actually relieves a lot of other potential problems.) For the time being, I'm trying out an adaptive solution, rolling CS to actually send the inverted. "CS" isn't really all that uncommon, so this may not be a practical solution.
const uint16_t PROGMEM H_Sch_combo[] = {RCTL_T(KC_C), RALT_T(KC_S), RGUI_T(KC_N), COMBO_END}; // TYPE "Sch"
// TEXT ENTRY - (ANY ROW/ MIXED ROWS)


const uint16_t PROGMEM HOE_lig_combo[] = {RGUI_T(KC_E), KC_O, COMBO_END}; // Œ
const uint16_t PROGMEM HAE_lig_combo[] = {RSFT_T(KC_A), KC_U, COMBO_END}; // Æ
/*
const uint16_t PROGMEM HC_1E_combo[] = {LGUI_T(KC_N), RGUI_T(KC_E), COMBO_END}; // É
const uint16_t PROGMEM HC_2E_combo[] = {LSFT_T(KC_T), RGUI_T(KC_E), COMBO_END}; // È
const uint16_t PROGMEM HC_3E_combo[] = {RALT_T(KC_S), LSFT_T(KC_T), RGUI_T(KC_E), COMBO_END}; // Ê
const uint16_t PROGMEM HC_4E_combo[] = {RALT_T(KC_S), RGUI_T(KC_E), COMBO_END}; // Ë
const uint16_t PROGMEM HC_5E_combo[] = {KC_M, RGUI_T(KC_E), COMBO_END}; // Ē
const uint16_t PROGMEM HC_6E_combo[] = {LCTL_T(KC_C), RGUI_T(KC_E), COMBO_END}; // E̊
*/
/*
 // Major diacritic combos will use SemKeys for platform independance
 // revisit this for Polyglot (will cause some conflict w/some
 // data entry combos above. Rethink combo vs adaptive considerations)
const uint16_t PROGMEM HUM_combo[] = {KC_F, KC_U, COMBO_END};  // Ü
const uint16_t PROGMEM HOM_combo[] = {KC_F, KC_O, COMBO_END};  // Ö
const uint16_t PROGMEM HUK_combo[] = {KC_L, KC_U, COMBO_END};  // Ů
const uint16_t PROGMEM HOK_combo[] = {KC_L, KC_O, COMBO_END};  // O̊
const uint16_t PROGMEM HUV_combo[] = {KC_W, KC_U, COMBO_END};  // Û
const uint16_t PROGMEM HOV_combo[] = {KC_W, KC_O, COMBO_END};  // Ô
const uint16_t PROGMEM HUF_combo[] = {KC_V, KC_U, COMBO_END};  // Ú
const uint16_t PROGMEM HOF_combo[] = {KC_V, KC_O, COMBO_END};  // Ó

*/



// Fast 4grams
/*
const uint16_t PROGMEM H_ould_combo[] = {KC_O, KC_D, COMBO_END}; // "ould" #11

#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
const uint16_t PROGMEM H_with_combo[] = {KC_W, RCTL_T(KC), COMBO_END}; // "with" #5 for Gold/Neu
const uint16_t PROGMEM H_ment_combo[] = {KC_M, RSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_ting_combo[] = {RSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_ough_combo[] = {KC_O, RCTL_T(KC_H), COMBO_END}; // "ough" #25 for Gold/Neu
#else  // for HD Neu/Au/Ti
const uint16_t PROGMEM H_with_combo[] = {KC_W, RCTL_T(KC_H), COMBO_END}; // "with" #5 for Gold/Neu
const uint16_t PROGMEM H_ment_combo[] = {KC_M, RSFT_T(KC_T), COMBO_END}; // "ment" #6
const uint16_t PROGMEM H_ting_combo[] = {RSFT_T(KC_T), KC_G, COMBO_END}; // "ting" #12
const uint16_t PROGMEM H_ough_combo[] = {KC_O, RCTL_T(KC_H), COMBO_END}; // "ough" #25 for Gold/Neu
#endif
*/


#ifdef EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

// PRONOUNS Fast 4-7grams

// not excluding the first person pronoun combos for now, because I've become quite accustomed to them.

// enum my_layers for layout layers for HD Neu/Au/Ti/Rh
//    L_HDNUE,      N             RSNT AEIH (same home row as Rhodium)
//    L_HDBRONZE,   B BR (Neu-hx) RSNT AECI (same home row as Platinum)
//    L_HDSILVER,   S Ag (Neu-nx) RSHT AECI
//    L_HDPLATINUM, P Pl (Neu-lx) RSNT AECI (same home row as Bronze)
//    L_HDTITANIUM, T Ti (Neu-rx) CSNT AEIH
//    L_HDRHODIUM,  R Rh (Neu-cx) RSNT AEIH (same home row as Platinum)
//    L_HDCHROMIUM, x Cr (Neu-xx) RSNT AEIH (same home row as Platinum)
//    L_HDGOLD,     G Au (Neu-tx) RSND AEIH

// for HD Neu/Au/Ti/Rh

const uint16_t PROGMEM H_Icap_combo[] = {RALT_T(KC_I), RCTL_T(KC_H), COMBO_END}; // TYPE "I"
const uint16_t PROGMEM H_Id_combo[] = {KC_D, RALT_T(KC_I), COMBO_END}; // TYPE "I'd"+"'ve "
const uint16_t PROGMEM H_Ill_combo[] = {KC_L, RALT_T(KC_I), COMBO_END}; // TYPE "I'll"+"'ve "
const uint16_t PROGMEM H_Im_combo[] = {KC_M, RALT_T(KC_I), COMBO_END}; // TYPE "I'm "
const uint16_t PROGMEM H_Iv_combo[] = {KC_V, RALT_T(KC_I), COMBO_END}; // TYPE "I've "

#ifdef EN_PRONOUN_COMBOS_ALL

// should these all be Adaptive keys instead? (Maybe less overhead.)

const uint16_t PROGMEM H_there_combo[] = {RSFT_T(KC_T), LT(L_NAV, KC_R), COMBO_END}; // TYPE "there" #7 + 's
const uint16_t PROGMEM H_here_combo[] = {RCTL_T(KC_H), LT(L_NAV, KC_R), COMBO_END}; // TYPE "here" #5 + 's

// THESE "PULL UP"
#ifdef EN_W_PRONOUNS
const uint16_t PROGMEM H_where_combo[] = {KC_W, LT(L_NAV, KC_R), COMBO_END}; // "where" + 's
const uint16_t PROGMEM H_wed_combo[] = {KC_W, KC_P, COMBO_END}; // TYPE "we'd" + 've
const uint16_t PROGMEM H_well_combo[] = {KC_W, KC_M, COMBO_END}; // TYPE "we'll" + 've
const uint16_t PROGMEM H_were_combo[] = {KC_W, LT(L_NAV, KC_R), COMBO_END}; // TYPE "we're"
const uint16_t PROGMEM H_weve_combo[] = {KC_W, KC_J, COMBO_END}; // TYPE "we've"
#endif // EN_W_PRONOUNS

const uint16_t PROGMEM H_youd_combo[] = {KC_Y, KC_D, COMBO_END}; // TYPE "you'd" + 've
const uint16_t PROGMEM H_youll_combo[] = {KC_Y, KC_L, COMBO_END}; // TYPE "you'll" + 've
const uint16_t PROGMEM H_youre_combo[] = {KC_Y, LT(L_NAV, KC_R), COMBO_END}; // TYPE "you're"
const uint16_t PROGMEM H_youve_combo[] = {KC_Y, KC_V, COMBO_END}; // TYPE "you've"
const uint16_t PROGMEM H_your_combo[] = {KC_Y, KC_P, COMBO_END}; // TYPE "your" "P" for "possessive" case
const uint16_t PROGMEM H_their_combo[] = {RSFT_T(KC_T), KC_P, COMBO_END}; // TYPE "their" #6
const uint16_t PROGMEM H_they_combo[] = {RSFT_T(KC_T), KC_Y, COMBO_END}; // "they" #23 + 've
const uint16_t PROGMEM H_theyd_combo[] = {RSFT_T(KC_T), KC_D, COMBO_END}; // "they'd" #23 + 've
const uint16_t PROGMEM H_theyll_combo[] = {RSFT_T(KC_T), KC_L, COMBO_END}; // "they'll" #23 + 've
const uint16_t PROGMEM H_theyre_combo[] = {RSFT_T(KC_T), LT(L_NAV, KC_R), COMBO_END}; // "they're"

#endif // EN_PRONOUN_COMBOS_ALL

#endif // EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

// UPPER ROW

// FUNCTIONS/COMMANDS Spatially arranged


const uint16_t PROGMEM Htab_combo[] = {RCTL_T(KC_C), RALT_T(KC_S), COMBO_END}; // tab
const uint16_t PROGMEM Hspc_combo[] = {RSFT_T(KC_T), LT(L_NUMPAD, KC_K), COMBO_END}; // SPACE
const uint16_t PROGMEM Hent_combo[] = {KC_D, KC_V, COMBO_END}; // ENTER
const uint16_t PROGMEM Hent2_combo[] = {KC_L, KC_D, KC_V,  COMBO_END}; // hard-ENTER/page break

// LOWER ROW

// SEMANTIC FUNCTIONS Spatially arranged  ** uses SemKeys **
const uint16_t PROGMEM Hnew_combo[] = {RCTL_T(KC_C), LT(L_NUMPAD, KC_K), COMBO_END}; // new
const uint16_t PROGMEM Hopen_combo[] = {KC_X, KC_J, COMBO_END}; // open
const uint16_t PROGMEM Hclose_combo[] = {RGUI_T(KC_N), LT(L_NUMPAD, KC_K), COMBO_END}; // close
const uint16_t PROGMEM Hquit_combo[] = {RALT_T(KC_S), LT(L_NUMPAD, KC_K), COMBO_END}; // quit
const uint16_t PROGMEM Hfind_combo[] = {RCTL_T(KC_C), KC_V, COMBO_END}; // find selection
const uint16_t PROGMEM Hsall_combo[] = {KC_W, KC_D, COMBO_END}; // select all
const uint16_t PROGMEM Hswrd_combo[] = {KC_W, KC_V, COMBO_END}; // select word
const uint16_t PROGMEM Hundo_combo[] = {KC_W, KC_F, COMBO_END}; // undo
const uint16_t PROGMEM Hcut_combo[] = {KC_W, KC_L, COMBO_END}; // cut
const uint16_t PROGMEM Hcopy_combo[] = {KC_F, KC_L, COMBO_END}; // copy (hold for cut)
const uint16_t PROGMEM Hpste_combo[] = {KC_L, KC_D, COMBO_END}; // paste (hold for paste-match)
const uint16_t PROGMEM Hpstm_combo[] = {KC_L, KC_V, COMBO_END}; // paste-match


// TWO HANDS

// Japanese contract consonants.
// These will conflict with Polyglot's diacritics (below),
// so some sort of mode-switch will be necessary for both to be used on the same board.
//

#ifdef JP_MODE_ENABLE // among other things, JP_MODE_ENABLE will swap L & K in process_record_user()
#ifdef JP_YOUON_COMBOS  // Japanese contracted sounds as combos
const uint16_t PROGMEM kya_combo[] = {KC_L, RSFT_T(KC_A), COMBO_END};  // きゃ
const uint16_t PROGMEM kyu_combo[] = {KC_L, KC_U, COMBO_END};  //　きゅ
const uint16_t PROGMEM kyo_combo[] = {KC_L, KC_O, COMBO_END};  //　きょ
const uint16_t PROGMEM sya_combo[] = {RALT_T(KC_S), RSFT_T(KC_A), COMBO_END};  // しゃ
const uint16_t PROGMEM syu_combo[] = {RALT_T(KC_S), KC_U, COMBO_END};  //　しゅ
const uint16_t PROGMEM sye_combo[] = {RALT_T(KC_S), RGUI_T(KC_E), COMBO_END};  //　しぇ
const uint16_t PROGMEM syo_combo[] = {RALT_T(KC_S), KC_O, COMBO_END};  //　しょ
const uint16_t PROGMEM zya_combo[] = {RCTL_T(KC_C), RSFT_T(KC_A), COMBO_END};  // じゃ
const uint16_t PROGMEM zyu_combo[] = {RCTL_T(KC_C), KC_U, COMBO_END};  //　じゅ
const uint16_t PROGMEM zyo_combo[] = {RCTL_T(KC_C), KC_O, COMBO_END};  //　じょ
const uint16_t PROGMEM tya_combo[] = {RSFT_T(KC_T), RSFT_T(KC_A), COMBO_END};  // ちゃ
const uint16_t PROGMEM tyu_combo[] = {RSFT_T(KC_T), KC_U, COMBO_END};  //　ちゅ
const uint16_t PROGMEM tye_combo[] = {RSFT_T(KC_T), RGUI_T(KC_E), COMBO_END};  // ちぇ
const uint16_t PROGMEM tyo_combo[] = {RSFT_T(KC_T), KC_O, COMBO_END};  //　ちょ
const uint16_t PROGMEM pya_combo[] = {KC_P, RSFT_T(KC_A), COMBO_END};  // ぴゃ
const uint16_t PROGMEM pyu_combo[] = {KC_P, KC_U, COMBO_END};  //　ぴゅ
const uint16_t PROGMEM pyo_combo[] = {KC_P, KC_O, COMBO_END};  //　ぴょ

#ifdef JP_YOUON_COMBOS_ALL // JP_YOUON_COMBOS_ALL

const uint16_t PROGMEM naa_combo[] = {KC_X, RSFT_T(KC_A), COMBO_END};  // アー
const uint16_t PROGMEM nii_combo[] = {KC_X, RALT_T(KC_I), COMBO_END};  // イー
//const uint16_t PROGMEM nuu_combo[] = {KC_X, KC_U, COMBO_END};  // ウー
const uint16_t PROGMEM nee_combo[] = {KC_X, RGUI_T(KC_E), COMBO_END};  // エー
const uint16_t PROGMEM noo_combo[] = {KC_X, KC_O, COMBO_END};  // オー
const uint16_t PROGMEM nnn_combo[] = {RCTL_T(KC_C), RSFT_T(KC_T), COMBO_END};  // ん

const uint16_t PROGMEM gya_combo[] = {KC_G, RSFT_T(KC_A), COMBO_END};  // ぎゃ
const uint16_t PROGMEM gyu_combo[] = {KC_G, KC_U, COMBO_END};  //　ぎゅ
const uint16_t PROGMEM gyo_combo[] = {KC_G, KC_O, COMBO_END};  //　ぎょ
const uint16_t PROGMEM tha_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), RSFT_T(KC_A), COMBO_END};  // てゃ
const uint16_t PROGMEM thi_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), RALT_T(KC_I), COMBO_END};  // てぃ
const uint16_t PROGMEM thu_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), KC_U, COMBO_END};  //　てゅ
const uint16_t PROGMEM the_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), RGUI_T(KC_E), COMBO_END};  // てぇ
const uint16_t PROGMEM tho_combo[] = {RGUI_T(KC_N), RSFT_T(KC_T), KC_O, COMBO_END};  //　てょ
const uint16_t PROGMEM dha_combo[] = {KC_L, KC_D, RSFT_T(KC_A), COMBO_END};  // でゃ
const uint16_t PROGMEM dhi_combo[] = {KC_L, KC_D, RALT_T(KC_I), COMBO_END};  // でぃ
const uint16_t PROGMEM dhu_combo[] = {KC_L, KC_D, KC_U, COMBO_END};  //　でゅ
const uint16_t PROGMEM dhe_combo[] = {KC_L, KC_D, RGUI_T(KC_E), COMBO_END};  // でぇ
const uint16_t PROGMEM dho_combo[] = {KC_L, KC_D, KC_O, COMBO_END};  //　でょ
const uint16_t PROGMEM nya_combo[] = {RGUI_T(KC_N), RSFT_T(KC_A), COMBO_END};  // にゃ
const uint16_t PROGMEM nyu_combo[] = {RGUI_T(KC_N), KC_U, COMBO_END};  //　にゅ
const uint16_t PROGMEM nyo_combo[] = {RGUI_T(KC_N), KC_O, COMBO_END};  //　にょ

// hya_combo shares a diacritic combo, so procecessed differently there (for ˚=å)
/*
const uint16_t PROGMEM hya_combo[] = {LT(L_NAV, KC_H), RSFT_T(KC_A), COMBO_END};  // ひゃ
const uint16_t PROGMEM hya2_combo[] = {RCTL_T(KC_H), RSFT_T(KC_A), COMBO_END};  // ひゃ
*/
const uint16_t PROGMEM hyu2_combo[] = {LT(L_NAV, KC_H), KC_U, COMBO_END};  //　ひゅ
const uint16_t PROGMEM hyu_combo[] = {RCTL_T(KC_H), KC_U, COMBO_END};  //　ひゅ
const uint16_t PROGMEM hyo2_combo[] = {LT(L_NAV, KC_H), KC_O, COMBO_END};  //　ひょ
const uint16_t PROGMEM hyo_combo[] = {RCTL_T(KC_H), KC_O, COMBO_END};  //　ひょ

const uint16_t PROGMEM bya_combo[] = {KC_B, RSFT_T(KC_A), COMBO_END};  // びゃ
//const uint16_t PROGMEM byu_combo[] = {KC_B, KC_U, COMBO_END};  //　びゅ  conflicts, so handled in main section
const uint16_t PROGMEM byo_combo[] = {KC_B, KC_O, COMBO_END};  //　びょ
const uint16_t PROGMEM mya_combo[] = {KC_M, RSFT_T(KC_A), COMBO_END};  // みゃ
const uint16_t PROGMEM myu_combo[] = {KC_M, KC_U, COMBO_END};  //　みゅ
const uint16_t PROGMEM myo_combo[] = {KC_M, KC_O, COMBO_END};  //　みょ
const uint16_t PROGMEM rya_combo[] = {LT(L_NAV, KC_R), RSFT_T(KC_A), COMBO_END};  // りゃ
const uint16_t PROGMEM ryu_combo[] = {LT(L_NAV, KC_R), KC_U, COMBO_END};  //　りゅ
const uint16_t PROGMEM ryo_combo[] = {LT(L_NAV, KC_R), KC_O, COMBO_END};  //　りょ
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_YOUON_COMBOS
#endif // JP_MODE_ENABLE


combo_t key_combos[] = {
    // These simple combos trigger on press, repeat. HC_kbd_combo
    [HC_KBD] = COMBO(HC_kbd_combo, MO(L_MEDIA_KBD)), // keyboard/media settings/config layer
    [HC_APP] = COMBO(H_menu_combo, KC_APP), // app menu
    [HC_EQL] = COMBO(Hequal_combo, KC_EQL), // =
    [HC_PCT] = COMBO(Hpercent_combo, KC_PERC), // %
    [HC_SCLN] = COMBO(Hscln_combo, KC_SCLN), // ;
    [HC_COLN] = COMBO_ACTION(Hcoln_combo), // :  (hold for elipsis)
    [HC_UNDS] = COMBO_ACTION(Hunds_combo), // _ underscore
    [HC_TILD] = COMBO(Htild_combo, KC_TILD),  // ~ or SK_TILD?
    [HC_TIC] = COMBO(Htic_combo, KC_GRAVE),  // ` (not dead)
    [HC_EXLM] = COMBO(Hexlm_combo, KC_EXLM), // !
    [HC_QUES] = COMBO(Hques_combo, KC_QUES), // ?
    [HC_DQUO] = COMBO(Hdquo_combo, KC_DLR), // " hijacked for $
    [HC_HASH] = COMBO(Hhash_combo, SK_SECT), // # hijacked for §
    [HC_AT] = COMBO_ACTION(Hat_combo), // @ & alanreiser.com if held
    [HC_TAB] = COMBO(Htab_combo, KC_TAB),

    [HC_Q] = COMBO_ACTION(H_Q_combo),
    [HC_Z] = COMBO(H_Z_combo, KC_Z),
    [HC_Ch] = COMBO_ACTION(H_Ch_combo),
//    [HC_Sc] = COMBO_ACTION(H_Sc_combo),
    [HC_Sch] = COMBO_ACTION(H_Sch_combo),
    [HC_Gh] = COMBO_ACTION(H_Gh_combo),
    [HC_Ph] = COMBO_ACTION(H_Ph_combo),
    [HC_Th] = COMBO_ACTION(H_Th_combo),
    [HC_Sh] = COMBO_ACTION(H_Sh_combo),
    [HC_Wh] = COMBO_ACTION(H_Wh_combo),

    [HC_OE] = COMBO_ACTION(HOE_lig_combo),  // Œ
    [HC_AE] = COMBO_ACTION(HAE_lig_combo),  // Æ
/*
    [HC_1E] = COMBO_ACTION(HC_1E_combo),  // É
    [HC_2E] = COMBO_ACTION(HC_2E_combo),  // È
    [HC_3E] = COMBO_ACTION(HC_3E_combo),  // Ê
    [HC_4E] = COMBO_ACTION(HC_4E_combo),  // Ë
    [HC_5E] = COMBO_ACTION(HC_5E_combo),  // Ē
    [HC_6E] = COMBO_ACTION(HC_6E_combo),  // E̊
*/
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
//    [jp_pyu] = COMBO_ACTION(pyu_combo),  // ぴゅ
    [jp_pyo] = COMBO_ACTION(pyo_combo),  // ぴょ

#ifdef JP_YOUON_COMBOS_ALL // JP_YOUON_COMBOS_ALL

    [jp_aa] = COMBO_ACTION(naa_combo),  // アー
    [jp_ii] = COMBO_ACTION(nii_combo),  // イー
//    [jp_uu] = COMBO_ACTION(nuu_combo),  // ウー
    [jp_ee] = COMBO_ACTION(nee_combo),  // エー
    [jp_oo] = COMBO_ACTION(noo_combo),  // オー
//    [jp_nn] = COMBO_ACTION(nnn_combo),  // ん
    
    [jp_gya] = COMBO_ACTION(gya_combo),  // ぎゃ
    [jp_gyu] = COMBO_ACTION(gyu_combo),  // ぎゅ
    [jp_gyo] = COMBO_ACTION(gyo_combo),  // ぎょ
    [jp_tha] = COMBO_ACTION(tha_combo),  // てゃ
    [jp_thi] = COMBO_ACTION(thi_combo),  // てぃ
    [jp_thu] = COMBO_ACTION(thu_combo),  // てゅ
    [jp_the] = COMBO_ACTION(the_combo),  // てぇ
    [jp_tho] = COMBO_ACTION(tho_combo),  // てょ
    [jp_dha] = COMBO_ACTION(dha_combo),  // でゃ
    [jp_dhi] = COMBO_ACTION(dhi_combo),  // でぃ
    [jp_dhu] = COMBO_ACTION(dhu_combo),  // でゅ
    [jp_dhe] = COMBO_ACTION(dhe_combo),  // でぇ
    [jp_dho] = COMBO_ACTION(dho_combo),  // でょ
    [jp_nya] = COMBO_ACTION(nya_combo),  // にゃ
    [jp_nyu] = COMBO_ACTION(nyu_combo),  // にゅ
    [jp_nyo] = COMBO_ACTION(nyo_combo),  // にょ
//    [jp_hya] = COMBO_ACTION(hya_combo),  // ひゃ
    [jp_hyu] = COMBO_ACTION(hyu_combo),  // ひゅ
    [jp_hyo] = COMBO_ACTION(hyo_combo),  // ひょ
//    [jp_hya2] = COMBO_ACTION(hya2_combo),  // ひゃ
    [jp_bya] = COMBO_ACTION(bya_combo),  // びゃ
//    [jp_byu] = COMBO_ACTION(byu_combo),  // びゅ // handled in the main section
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

    [FC_LANG2] = COMBO(H_EISUU_combo, KC_LNG2), // eisuu (others)
    [FC_LANG1] = COMBO(H_KANA_combo, KC_LNG1), // kana (others)

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

/* These will need to be handled by SemKeys w/unicode support
    [HC_UM] = COMBO_ACTION(HUM_combo), // Ü
    [HC_OM] = COMBO_ACTION(HOM_combo), // Ö
    [HC_UK] = COMBO_ACTION(HUK_combo), // Ů
    [HC_OK] = COMBO_ACTION(HOK_combo), // O̊
    [HC_UV] = COMBO_ACTION(HUM_combo), // Û
    [HC_OV] = COMBO_ACTION(HOM_combo), // Ô
    [HC_UF] = COMBO_ACTION(HUK_combo), // Ú
    [HC_OF] = COMBO_ACTION(HOK_combo), // Ó

*/

// Fast entry 4grams

/* not sure these are worth it
    [HC_with_4gram] = COMBO_ACTION(H_with_combo), // TYPE "with" #5
    [HC_ment_4gram] = COMBO_ACTION(H_ment_combo), // TYPE "ment" #6
    [HC_ting_4gram] = COMBO_ACTION(H_ting_combo), // TYPE "ting" #12
    [HC_ough_4gram] = COMBO_ACTION(H_ough_combo), // TYPE "ough" #25
    [HC_ould_4gram] = COMBO_ACTION(H_ould_combo), // TYPE "ould" #11
*/
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

/* Maybe not worth the possible misfire (delay combo only)?
    [HC_people_6gram] = COMBO_ACTION(H_people_combo), // TYPE "people" #23
    [HC_present_7gram] = COMBO_ACTION(H_present_combo), // TYPE "present" #1
    [HC_through_7gram] = COMBO_ACTION(H_through_combo), // TYPE "through" #3
    [HC_between_7gram] = COMBO_ACTION(H_between_combo), // TYPE "between" #4
*/

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
    [HC_CUT] = COMBO(Hcut_combo, SK_CUT), // also hold copy
    [HC_COPY] = COMBO_ACTION(Hcopy_combo),
    [HC_PSTM] = COMBO(Hpstm_combo, SK_PSTM),  // also hold paste
    [HC_PSTE] = COMBO_ACTION(Hpste_combo)


    
};

void process_combo_event(uint16_t combo_index, bool pressed) {

#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, combo_OLED_row);
#endif
    if (pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_write_P(PSTR("Combo: "), false);
#endif
#ifdef JP_MODE_ENABLE
        // Don't process these
        if (IS_ENGLISH_MODE
#ifdef JP_YOUON_COMBOS
            && (combo_index >= jp_kya)
#ifdef JP_YOUON_COMBOS_ALL
            && (combo_index <= jp_ryo)
#else
            && (combo_index <= jp_pyo)
#endif  // JP_YOUON_COMBOS_ALL
#endif  // JP_YOUON_COMBOS
            )
            return;
#endif // JP_MODE_ENABLE
        switch(combo_index) {
            case PC_STAB ... COMBO_LENGTH:// these may have a hold delay BEFORE triggering
            case HC_AT ... HC_COLN: //
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

                
//            case HC_CAPG: // turn on capsword for Gold
            case HC_CAPW: // turn on capsword (automatically turns off on delimiter)
                toggle_caps_word();
                break;

            case HC_Q: //
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                tap_code16(KC_Q); //
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code16(KC_U); //
                combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
                break;

                
/*
 * H digraphs here
 */
            case HC_Th: // on first press
                tap_code(KC_T); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Sh:
                tap_code(KC_S); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
           case HC_Wh:
                tap_code(KC_W); // send "W" honoring caps
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // not in English mode?
                    tap_code(KC_O); // send "o" for を (this is more common/convenient?)
                    break;
                }
#endif
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
/* this conflicts with home row tab, so using adaptive CS -> SC
            case HC_Sc: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code(KC_C); // send "C"
                combo_on = combo_index; // if held, addd 'h' for "Sch" in matrix_scan_user_process_combo
                break;
*/
            case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
            case HC_Ch: // not held
                tap_code(KC_C); // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Gh: // not held
                tap_code(KC_G); // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Ph:
                tap_code(KC_P); // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;


            case HC_ACUT:
                tap_code16(A(KC_E)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_GRV:
//                tap_code16(A(KC_NUBS)); // this should use semkeys
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_CIRC:
                 tap_code16(A(KC_6)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_MACR:
                tap_code16(A(KC_A)); // this should use semkeys
                combo_on = combo_index; // may add "o" in matrix_scan_user_process_combo
                break;
            case HC_DIER:
                tap_code16(A(KC_U)); // this should use semkeys
                combo_on = combo_index; // may add "u" in matrix_scan_user_process_combo
                break;
            case HC_RING:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) {// in Japanese mode?
                    send_string("hya");// Y: so ひゃ
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(A(KC_K)); // this should use semkeys
                combo_on = combo_index; // may add "a" for å in matrix_scan_user_process_combo
                break;
            case HC_CEDILLE:
                tap_code16(A(KC_C)); // this should use semkeys
                combo_on = combo_index; // may add "c" in matrix_scan_user_process_combo
                break;
            case HC_ENYE:
                tap_code16(A(KC_N)); // this should use semkeys
                combo_on = combo_index; // may add "n" in matrix_scan_user_process_combo
                break;
            case HC_AE: // Æ
                tap_code16(A(KC_QUOT)); // this should use semkeys
                break;
            case HC_OE: // Œ
                tap_code16(A(KC_Q)); // this should use semkeys
                tap_code16(KC_U); // almost always "œu"
                combo_on = combo_index; // but like qu, we'll take it back if we must.
                break;
/*
            case HC_1E: // É
                tap_code16(A(KC_E)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_2E: // È
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_3E: // Ê
                tap_code16(A(KC_6)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_4E: // Ë
                tap_code16(A(KC_U)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_5E: // Ē
                tap_code16(A(KC_A)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_6E: // E̊
                tap_code16(A(KC_K)); // this should use semkeys
                tap_code16(KC_E); //
                break;
*/
/*
            case HC_OSLSH:
                tap_code16(A(KC_O)); // this should use semkeys
                break;
*/
            case HC_NDSH:
                register_code16(A(KC_MINS));  // should be a semkey
                break;
            case HC_MDSH:
                 register_code16(A(S(KC_MINS))); // should be a semkey
                break;
            case HC_UNDS:
#ifdef JP_MODE_ENABLE
#ifdef JP_YOUON_COMBOS_ALL
                // case jp_byu:  // びゅ
               if (!IS_ENGLISH_MODE) // in Japanese mode?
                   send_string("byu");  // Y: so びゅ
                else
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_MODE_ENABLE
                    tap_code16(S(KC_MINS)); // _ underscore (semkey this?)
                break;

#ifdef EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

            case HC_I:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // if in Japanese mode
                    send_string("watasi");  //
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(S(KC_I));
                unregister_mods(MOD_MASK_SHIFT);  //
                combo_on = combo_index; // may add "'ve " if held
                break;
            case HC_Id:
            case HC_Ill:
            case HC_Im:
            case HC_Iv:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // if in Japanese mode
                    send_string("watasiga");  //
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(S(KC_I)); // send "I" CAPITALIZED
                unregister_mods(MOD_MASK_SHIFT);  //
                goto addonsuffix;

#ifdef EN_PRONOUN_COMBOS_ALL

// This group all share a suffix, with a goto addonsuffix,
// so keep together 'cause we're messing with stack frames at the end!

            case HC_they_4gram: // "they"
//            case HC_theyg_4gram: // "they"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_your_4gram:
                tap_code(KC_Y);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("our");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
#ifdef EN_W_PRONOUNS
            case HC_wed_4gram:
            case HC_well_5gram:
            case HC_were_5gram:
            case HC_weve_5gram:
                tap_code(KC_W); // send "W" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("e"); // send "We" right away
                goto addonsuffix;
#endif // EN_W_PRONOUNS
            case HC_youd_5gram:
            case HC_youll_6gram:
            case HC_youre_6gram:
            case HC_youve_6gram:
                tap_code(KC_Y); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ou"); // send "We're" right away
                goto addonsuffix;
            case HC_theyd_6gram: // TYPE "they'd " #23
            case HC_theyll_7gram:
            case HC_theyre_7gram:
            case HC_theyve_7gram: // "they've"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away

#endif // #ifdef EN_PRONOUN_COMBOS_ALL

addonsuffix: // sharing this saves about 100 bytes (10 bytes per instance)
                tap_code(KC_QUOT);
                switch (combo_index) { //
                    case HC_Im:
                        SEND_STRING("m ");
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_wed_4gram: // we'd
#endif // EN_W_PRONOUNS
                    case HC_youd_5gram:
//                    case HC_youdg_5gram:
                    case HC_theyd_6gram: // TYPE "they'd " #23
//                    case HC_theydg_6gram: // TYPE "they'd " #23
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Id: // "I'd " …
                        send_string("d");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_well_5gram: // we'll
#endif // EN_W_PRONOUNS
                    case HC_youll_6gram:
                    case HC_theyll_7gram: // TYPE "they'll " #23
//                    case HC_theyllg_7gram: // TYPE "they'll " #23
#endif //#ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Ill: // "I'll "
                        send_string("ll");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_were_5gram: // we're
#endif // EN_W_PRONOUNS
                    case HC_youre_6gram:
                    case HC_theyre_7gram: // "they're"
                        send_string("re ");
                        break;
#ifdef EN_W_PRONOUNS
                    case HC_weve_5gram: // we've
#endif // EN_W_PRONOUNS
                    case HC_youve_6gram:
                    case HC_theyve_7gram: // "they've"
//                    case HC_theyveg_7gram: // "they've"
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Iv: // "I've " …
                        send_string("ve ");
                        break;
                }
                break;
// END of the common Pronoun suffix group with the goto addonsuffix:

#ifdef EN_PRONOUN_COMBOS_ALL
            case HC_their_5gram: // TYPE "their" #6
//            case HC_theirg_5gram: // TYPE "their" #6
                tap_code(KC_T);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("heir");
                combo_on = combo_index; // may add "'s " if held
                break;

            case HC_here_4gram: // TYPE "here" #9
                tap_code(KC_H);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ere");
                combo_on = combo_index; // may add "'s " if held
                break;
#ifdef EN_W_PRONOUNS
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
                tap_code(KC_W);
                goto ADD_HERE;
#endif // EN_W_PRONOUNS
            case HC_there_5gram: // TYPE "there" #7
                tap_code(KC_T);
#ifdef EN_W_PRONOUNS
ADD_HERE:
#endif // EN_W_PRONOUNS
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("here");
                combo_on = combo_index; // may add "'ve " if held
                break;

#endif // EN_PRONOUN_COMBOS_ALL
#endif // EN_PRONOUN_COMBOS
                
#ifdef JP_MODE_ENABLE
        // Don't process these
#ifdef JP_YOUON_COMBOS
            case jp_kya:  // きゃ:
                send_string("kya");  //
                break;
            case jp_kyu:  // きゅ
                send_string("kyu");  //
                break;
            case jp_kyo:  // きょ
                send_string("kyo");  //
                break;
            case jp_sya:  // しゃ
                send_string("sya");  //
                break;
            case jp_syu:  // しゅ
                send_string("syu");  //
                break;
            case jp_sye:  // しぇ
                send_string("sye");  //
                break;
            case jp_syo:  // しょ
                send_string("syo");  //
                break;
            case jp_zya:  // じゃ
                send_string("zya");  //
                break;
            case jp_zyu:  // じょ
                send_string("zyu");  //
                break;
            case jp_zyo:  // じょ
                send_string("zyo");  //
                break;
            case jp_tya:  // ちゃ
                send_string("tya");  //
                break;
            case jp_tyu:  // ちゅ
                send_string("tyu");  //
                break;
            case jp_tye:  // ちぇ
                send_string("tye");  //
                break;
            case jp_tyo:  // ちょ
                send_string("tyo");  //
                break;
            case jp_pya:  // ぴゃ:
                send_string("pya");  //
                break;
/*
            case jp_pyu:  // ぴゅ
                send_string("pyu");  //
                break;
 */
            case jp_pyo:  // ぴょ
                send_string("pyo");  //
                break;
#ifdef JP_YOUON_COMBOS_ALL // JP_YOUON_COMBOS_ALL

            case jp_aa:  // アー
                send_string("a-");  //
                break;
            case jp_ii:  //　イー
                send_string("i-");  //
                break;
            case jp_uu:  //　ウー
                send_string("u-");  //
                break;
            case jp_ee:  //　エー
                send_string("e-");  //
                break;
            case jp_oo:  //　オー
                send_string("o-");  //
                break;
            case jp_nn:  //　ン
                send_string("nn");  //
                break;


            case jp_gya:  // ぎゃ:
                send_string("gya");  //
                break;
            case jp_gyu:  // ぎゅ
                send_string("gyu");  //
                break;
            case jp_gyo:  // ぎょ
                send_string("gyo");  //
                break;
            case jp_tha:  // てゃ
                send_string("tha");  //
                break;
            case jp_thi:  // てぃ                send_string("thi");  //
                send_string("thi");  //
                break;
            case jp_thu:  // てゅ
                send_string("thu");  //
                break;
            case jp_the:  // てぇ
                send_string("the");  //
                break;
            case jp_tho:  // てょ
                send_string("tho");  //
                break;
            case jp_dha:  // でゃ
                send_string("dha");  //
                break;
            case jp_dhi:  // でぃ
                send_string("dhi");  //
                break;
            case jp_dhu:  // でょ
                send_string("dhu");  //
                break;
            case jp_dhe:  // でぇ
                send_string("dhe");  //
                break;
            case jp_dho:  // でょ
                send_string("dho");  //
                break;
            case jp_nya:  // にゃ
                send_string("nya");  //
                break;
            case jp_nyu:  // にょ
                send_string("nyu");  //
                break;
            case jp_nyo:  // ひゅ
                send_string("nyo");  //
                break;
/*
            case jp_hya:  // ひゃ
            case jp_hya2:  // ひゃ
                send_string("hyu");  //
                break;
*/
            case jp_hyu:  // ひゅ
                send_string("hyu");  //
                break;
            case jp_hyo:  // ひょ
                send_string("hyo");  //
                break;
            case jp_bya:  // びゃ:
                send_string("bya");  //
                break;
/*
            case jp_byu:  // びゅ
                send_string("byu");  // conflicts, handled in the main section
                break;
*/
            case jp_byo:  // びょ
                send_string("byo");  //
                break;
            case jp_mya:  // みゃ:
                send_string("mya");  //
                break;
            case jp_myu:  // みゅ
                send_string("myu");  //
                break;
            case jp_myo:  // みょ
                send_string("myo");  //
                break;
            case jp_rya:  // りゃ:
                send_string("rya");  //
                break;
            case jp_ryu:  // りゅ
                send_string("ryu");  //
                break;
            case jp_ryo:  // りょ
                send_string("ryo");  //
                break;
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_YOUON_COMBOS
#endif // JP_MODE_ENABLE
                
                
                
        } // end switch (combo_index)
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
        // should GUARD this with return instead
    } else { // end if (pressed) so this is the key up switch, hold threshold not met.
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

                case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                case HC_Ch:
                case HC_Th:
                case HC_Sh:
                case HC_Wh:
                case HC_Gh:
                case HC_Ph:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;

// END the H digraphs

                case HC_FIND:  // Find next of selection. Should work with many editors/platforms, but not all...obviously.
                    tap_SemKey(SK_COPY);
                    tap_SemKey(SK_FIND);
                    tap_SemKey(SK_PSTE);
                    tap_SemKey(KC_ENT); // register current find
                    tap_SemKey(SK_FAGN); // find next
                    break;
                case HC_NEW:
                    tap_SemKey(SK_NEW);
                    break;
                case HC_COPY: // not held, so simple copy
                    tap_SemKey(SK_COPY);
                    break;
                case HC_PSTE: // not held, so simple paste
                    tap_SemKey(SK_PSTE);
                    break;
    
                case HC_AT:
                    tap_code16(KC_AT); //
                    break;
                case HC_COLN:
                    tap_code16(KC_COLN); //
                    break;

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
                                        
                case HC_TYPE_LEFTCOMBO:
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(LeftComboTapE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(LeftComboTapJ); //
                    }
#endif
                    break;
                case HC_TYPE_RIGHTCOMBO:
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(RightComboTapE); // send "Japan" right away
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(RightComboTapJ); // send "Japan" right away
                    }
#endif
                    break;

#ifdef EN_PRONOUN_COMBOS
                case HC_I ... HC_Iv:
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_wed_4gram ... HC_their_5gram:
#endif
                    tap_code(KC_SPC); // add space after a composed pronoun
                    combo_on = 0;  // done w/these shenanigans
                    break;
#endif
                case HC_Q: //
                        unregister_code16(KC_Q); //
                        linger_key = 0;
                    break;

            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
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
        // do simple "on" on held actions and then turn on combo state in process_combo_event above,
        // then handle hold actions here,
        // before resolving in keyup event above.
        // if necessary (like releasing the underlying keys, or other cleanup)
        if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on && user_config.AdaptiveKeys) {
            saved_mods = get_mods();
            clear_mods();
            switch(combo_on) {  // combo_on is global, set in process_combo above

                case HC_FIND: // Held, so find selection (should work with most apps/platforms)
                    tap_SemKey(SK_COPY); // copy the selection
                    tap_SemKey(SK_FIND); // start find
                    tap_SemKey(SK_PSTE); // paste the copy. will find the selection
                    tap_SemKey(SK_FAGN); // now find the next...
                    break;
                case HC_COPY: // held, so cut
                    tap_SemKey(SK_CUT);
                    break;
                case HC_PSTE: // held, so pastematch
                    tap_SemKey(SK_PSTM);
                    break;

                    
                case HC_Sh:
                case HC_Th: // if this H digragh combo is held, then send T/Sion instead
                    unregister_mods(MOD_MASK_SHIFT);  //
                    send_string("ion");
                    break;
                case HC_Gh: // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_T); // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case HC_Sch: //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_O); // add "o" // o is the most common after sch
                    break;
                case HC_Ch: //
                case HC_Wh: //
                case HC_Ph: //
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_I); // add "i"
                    break;
//                case HC_Sc: //
//                    tap_code(KC_H); // add "h" (for "Sch", since were already on these keys.)
//                    break;
                case HC_AT:
                    send_string(At_ComboHeld);
                    break;
                case HC_COLN:
                    tap_code16(A(KC_SCLN)); // held, so … (this could use semkeys)
                    break;
                case HC_OE:
                case HC_Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;

                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT));
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
//                case HC_ELIP:
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


// PRONOUN shenanigans
#ifdef EN_PRONOUN_COMBOS_ALL

                case HC_here_4gram:
                case HC_there_5gram: // TYPE "there's" #7
                case HC_where_5gram: //

                case HC_your_4gram: // TYPE "your's"
                case HC_their_5gram: // TYPE "their's" #6

                    tap_code(KC_QUOT);
#endif
                    SEND_STRING("s ");
                    break;

//                case HC_ould_4gram: // TYPE "ould " #11
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_they_4gram: // TYPE "they " #23
                case HC_theyd_6gram: // TYPE "they'd " #23
                case HC_theyll_7gram: // TYPE "they'll " #23
                case HC_wed_4gram:
                case HC_well_5gram:
                case HC_youd_5gram:
                case HC_youll_6gram:
#endif // I've become accustomed to using the pronoun combos so I don't disable them
                case HC_I:
                case HC_Id:
                case HC_Ill:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    send_string("'ve "); // or should it be "'nt"?
                    break;

// END PRONOUN shenanigans

    // if lingered, these will followup with the most common composed letter (Latinate language mashup stats)
                case HC_ACUT:
                case HC_GRV:
                case HC_CIRC:
                    tap_code16(KC_E); // this should use semkeys? éêè
                    break;
                case HC_MACR:
                    tap_code16(KC_O); // this should use semkeys? ō
                    break;
                case HC_DIER:
                    tap_code16(KC_U); // this should use semkeys? ü
                    break;
                case HC_RING:
                    tap_code16(KC_A); // this should use semkeys? å
                    break;
                case HC_CEDILLE:
                    tap_code16(KC_C); // this should use semkeys? ç
                    break;
                case HC_ENYE:
                    tap_code16(KC_N); // this should use semkeys? ñ
                    break;

                    
                case HC_TYPE_LEFTCOMBO: // already "LeftComboTap" has been sent; if held, undo and send "LeftComboHeld"
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(LeftComboHeldE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(LeftComboHeldJ); //
                    }
#endif
                    break;
                case HC_TYPE_RIGHTCOMBO: // already "RightComboTap" has been sent; if held, add "RightComboHeld"
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(RightComboHeldE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(RightComboHeldJ); //
                    }
#endif
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
