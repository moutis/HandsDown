
//
// The Hands Down Variation dependent defs & files
//
#define HD_adaptive_code "handsdown/au-adaptive.c"
//
//
//       Alpha Layer for a 34 key formfactor
// ╭─────────────────────╮ ╭─────────────────────╮
// │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
// │ LM4 LM3 LM2 LM1 LM0 | | RT0 RM1 RM2 RM3 RM4 │
// │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
// ╰───────────╮ LH2 LH1 │ │ RH1 RH2  ╭──────────╯
//             ╰─────────╯ ╰──────────╯
//              Hands Down Gold
// ╭─────────────────────╮ ╭─────────────────────╮
// │  J   G   M   P   V  │ │  #$  .:  /*  "[  '] │
// │  R   S   N   D   B  | |  ,;   A   E   I   H │
// │  X   F   L   C   W  │ │  -+   U   O   Y   K │
// ╰───────────╮ BSP  T  │ │ SPC  RET ╭──────────╯
//             ╰─────────╯ ╰──────────╯
// Q (LT3) & Z (LT4) are on the punc layer
// and on combos (defined below)
//
// for now...
// This will morph to being entirel properly abstracted
// similar to Miryoku, (maybe someone will make an HD Miryoku someday?)
//
//

//
// We want to be able to define a combo either
// by location for variation independent, spatial referencing, or
// or by letter for mnemonic/phonetic referencing (variation dependent)
//
// BE CAREFUL to not double define a combo!
//
// First, let's add any hold-taps to the keycodes
//
#define HD_A RSFT_T(KC_A)
#define HD_B LT(L_NUMPAD,KC_B)
#define HD_C KC_C
#define HD_D RSFT_T(KC_D)
#define HD_E RGUI_T(KC_E)
#define HD_F KC_F
#define HD_G KC_G
#define HD_H RCTL_T(KC_H)
#define HD_I RALT_T(KC_I)
#define HD_J KC_J
#define HD_K KC_K
#define HD_L KC_L
#define HD_M KC_M
#define HD_N RGUI_T(KC_N)
#define HD_O KC_O
#define HD_P KC_P
#define HD_Q KC_Q
#define HD_R RCTL_T(KC_R)
#define HD_S RALT_T(KC_S)
#define HD_T LT(L_NAV,KC_T)
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y
#define HD_Z KC_Z

#define HD_MINS KC_MINS
#define HD_HASH KC_HASH
#define HD_SPC  LT(L_PUNCT,KC_SPC)
#define HD_BSPC LT(L_FN_NUM,KC_BSPC)
#define HD_ENT  LT(L_NAV,KC_ENT)
#define HD_QUOT KC_QUOT
#define HD_DQUO KC_DQUO
#define HD_SLSH KC_SLSH
#define HD_DOT  KC_DOT
#define HD_COMM LT(L_FN_NUM, KC_COMM)

//
// Now let's also defineo the keycodes on the map for spatial referencing
//
// (is there anyway to combine these 2 steps?)
//
#define HD_LT4 HD_J
#define HD_LT3 HD_G
#define HD_LT2 HD_M
#define HD_LT1 HD_P
#define HD_LT0 HD_V
#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLSH
#define HD_RT3 HD_DQUO
#define HD_RT4 HD_QUOT

#define HD_LM4 HD_R
#define HD_LM3 HD_S
#define HD_LM2 HD_N
#define HD_LM1 HD_D
#define HD_LM0 HD_B
#define HD_RM0 HD_COMM
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_H

#define HD_LB4 HD_X
#define HD_LB3 HD_F
#define HD_LB2 HD_L
#define HD_LB1 HD_C
#define HD_LB0 HD_W
#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_K

//Primary Thumbs (others unique to the board)
#define HD_LH2 HD_BSPC
#define HD_LH1 HD_T
#define HD_RH1 HD_SPC
#define HD_RH2 HD_ENT



#ifdef COMBO_ENABLE
//
// Combo definitions that rely on phonetics/mnemonics for their locations.
//
// Combos that are spacially organized don't need to be redefined
// to match the base alpha layer, so they are not included here.
//
// These few spatial combos may move to accommodate some mnemonic combos,
// notably the H-digraph combos that inhabit close areas.
//
#define HD_tab_keys  HD_LM4, HD_LM3     // tab
#define HD_spc_keys  HD_LM1, HD_LM0     // SPACE
#define HD_ent_keys  HD_LB0, HD_LB1     // ENTER
#define HD_ent2_keys HD_LB0, HD_LB2, HD_LB1 // hard-ENTER/page break

// TEXT ENTRY - off map standard alphas (also on Layer L_PUNCT @ Z=LT4 & Q=LT3)
//
#define HD_Z_keys HD_LT1, HD_LT0 // TYPE "z"
#define HD_Qu_keys HD_LT3, HD_LT1 // TYPE "q" (Qu & Linger deletes u)

//
// H digraph combos
// try to make these use the lead letter and a neighbor.
//
#define HD_Th_keys HD_LM2, HD_LM1 // TYPE "th"
#define HD_Ch_keys HD_LM3, HD_LM1 // TYPE "ch"
#define HD_Wh_keys HD_LT4, HD_LT3 // TYPE "wh"
#define HD_Sh_keys HD_LM3, HD_LM2 // TYPE "sh"
#define HD_Ph_keys HD_LT1, HD_LT2 // TYPE "ph"
#define HD_Gh_keys HD_LT3, HD_LT2 // TYPE "gh"
#define HD_Sch_keys HD_LM4, HD_LM3, HD_LM2 // TYPE "Sch"

#define HD_OE_lig_keys HD_RM2, HD_RB2 // Œ
#define HD_AE_lig_keys HD_RM1, HD_RB1 // Æ


#ifdef EN_PRONOUN_COMBOS
// the entirely unnecessary pronoun combo shenanigans

// PRONOUNS Fast 4-7grams
#define HD_Icap_keys  HD_I, HD_H  // TYPE "I"
#define HD_Id_keys    HD_I, HD_D  // TYPE "I'd"+"'ve "
#define HD_Ill_keys   HD_I, HD_L  // TYPE "I'll"+"'ve "
#define HD_Im_keys    HD_I, HD_M  // TYPE "I'm "
#define HD_Iv_keys    HD_I, HD_V  // TYPE "I've "

#ifdef EN_PRONOUN_COMBOS_ALL // Admittedly of questionable value
#define HD_youd_keys  HD_Y, HD_D  // TYPE "you'd" + 've
#define HD_youll_keys HD_Y, HD_L  // TYPE "you'll" + 've
#define HD_youre_keys HD_Y, HD_R  // TYPE "you're"
#define HD_youve_keys HD_Y, HD_V  // TYPE "you've"
#define HD_your_keys  HD_Y, HD_P  // TYPE "your" "P" for "possessive" case
#define HD_their_keys HD_T, HD_W  // TYPE "their" #6
#define HD_they_keys  HD_T, HD_Y  // "they" #23 + 've
#define HD_theyd_keys HD_T, HD_X  // "they'd" #23 + 've
#define HD_theyll_keys HD_T, HD_L // "they'll" #23 + 've
#define HD_theyre_keys HD_T, HD_QUOT // "they're"

#define HD_there_keys HD_T, HD_F  // TYPE "there" #7 + 's
#define HD_here_keys  HD_H, HD_R  // TYPE "here" #5 + 's


#ifdef EN_W_PRONOUNS
#define HD_where_keys HD_X, HD_R  // "where" + 's
#define HD_wed_keys   HD_X, HD_G  // TYPE "we'd" + 've
#define HD_well_keys  HD_X, HD_M  // TYPE "we'll" + 've
#define HD_were_keys  HD_X, HD_QUOT  // TYPE "we're"
#define HD_weve_keys  HD_X, HD_J  // TYPE "we've"
#endif // EN_W_PRONOUNS

#endif // EN_PRONOUN_keysS_ALL
#endif // EN_PRONOUN_keysS // the entirely unnecessary pronoun combo shenanigans



// SEMANTIC FUNCTIONS  ** uses SemKeys **
// Spatially arranged on the QWERTY ZXCV locations
//
#define HD_new_keys   HD_LM2, HD_LB2   // new
#define HD_open_keys  HD_LM1, HD_LB1   // open
#define HD_close_keys HD_LM3, HD_LB3   // close
#define HD_quit_keys  HD_LB0, HD_LM0   // quit
#define HD_find_keys  HD_RM4, HD_RB0   // find selection
#define HD_sall_keys  HD_LB4, HD_LB1   // select all
#define HD_swrd_keys  HD_LB4, HD_LB0   // select word
#define HD_undo_keys  HD_LB4, HD_LB3   // undo
#define HD_redo_keys  HD_LB4, HD_LB3, HD_LB2   // redo
//#define HD_cut_keys   HD_LB4, HD_LB2   // cut
#define HD_copy_keys  HD_LB3, HD_LB2   // copy (hold for cut)
#define HD_pste_keys  HD_LB2, HD_LB1   // paste (hold for paste-match)



#ifdef JP_MODE_ENABLE
#ifdef JP_YOUON_COMBOS
// Major Japanese contracted consonants as combos
//
// These will conflict with some diacritics (noted below),
// so some sort of mode-switch in process_keys_event is necessary
// for both to be used on the same board.
//
// There is also risk of conflict with spatial any phonetically/mnemonically coded combos.
//
// Major (high frequency) Japanese contracted sounds
#define JP_kya_keys HD_LM0, HD_RM1 // きゃ
#define JP_kyu_keys HD_LM0, HD_RB1 //　きゅ
#define JP_kyo_keys HD_LM0, HD_RB2 //　きょ
#define JP_sya_keys HD_LM4, HD_RM1 // しゃ
#define JP_syu_keys HD_LM4, HD_RB1 //　しゅ
#define JP_sye_keys HD_LM4, HD_RM2 //　しぇ
#define JP_syo_keys HD_LM4, HD_RB2 //　しょ
#define JP_zya_keys HD_LM3, HD_RM1 // じゃ
#define JP_zyu_keys HD_LM3, HD_RB1 //　じゅ
#define JP_zyo_keys HD_LM3, HD_RB2 //　じょ
#define JP_tya_keys HD_LM1, HD_RM1 // ちゃ
#define JP_tyu_keys HD_LM1, HD_RB1 //　ちゅ
#define JP_tye_keys HD_LM1, HD_RM2 // ちぇ
#define JP_tyo_keys HD_LM1, HD_RB2 //　ちょ
#define JP_pya_keys HD_LB3, HD_RM1 // ぴゃ
#define JP_pyu_keys HD_LB3, HD_RB1 //　ぴゅ
#define JP_pyo_keys HD_LB3, HD_RB2 //　ぴょ

#ifdef JP_YOUON_COMBOS_ALL // All Japanese contracted sounds

#define JP_gya_keys HD_LT1, HD_RM1 // ぎゃ
#define JP_gyu_keys HD_LT1, HD_RB1 //　ぎゅ
#define JP_gyo_keys HD_LT1, HD_RB2 //　ぎょ
#define JP_tha_keys HD_LM2, HD_LM1, HD_RM1 // てゃ
#define JP_thi_keys HD_LM2, HD_LM1, HD_RM3 // てぃ
#define JP_thu_keys HD_LM2, HD_LM1, HD_RB1 //　てゅ
#define JP_the_keys HD_LM2, HD_LM1, HD_RM2 // てぇ
#define JP_tho_keys HD_LM2, HD_LM1, HD_RB2 //　てょ
#define JP_dha_keys HD_LB1, HD_RM1 // でゃ
#define JP_dhi_keys HD_LB1, HD_RM3 // でぃ
#define JP_dhu_keys HD_LB1, HD_RB1 //　でゅ
#define JP_dhe_keys HD_LB1, HD_RM2 // でぇ
#define JP_dho_keys HD_LB1, HD_RB2 //　でょ
#define JP_nya_keys HD_LM2, HD_RM1 // にゃ
#define JP_nyu_keys HD_LM2, HD_RB1 //　にゅ
#define JP_nyo_keys HD_LM2, HD_RB2 //　にょ

//#define JP_hya_keys HD_RM4, HD_RM1 // ひゃ conflicts with diacritic
#define JP_hyu_keys HD_RM4, HD_RB1 //　ひゅ
#define JP_hyo_keys HD_RM4, HD_RB2 //　ひょ
//#define JP_fya_keys HD_RM4, HD_RM1 // ふぁ unnecessary?
//#define JP_fyu_keys HD_RM4, HD_RB1 //　ふぃ
//#define JP_fye_keys HD_RM4, HD_RB1 //　ふぇ
//#define JP_fyo_keys HD_RM4, HD_RB2 //　ふぉ

#define JP_bya_keys HD_LB4, HD_RM1 // びゃ
#define JP_byu_keys HD_LB4, HD_RB1 //　びゅ  conflicts with diacritic?
#define JP_byo_keys HD_LB4, HD_RB2 //　びょ
#define JP_mya_keys HD_LT2, HD_RM1 // みゃ
#define JP_myu_keys HD_LT2, HD_RB1 //　みゅ
#define JP_myo_keys HD_LT2, HD_RB2 //　みょ
#define JP_rya_keys HD_LH1, HD_RM1 // りゃ
#define JP_ryu_keys HD_LH1, HD_RB1 //　りゅ
#define JP_ryo_keys HD_LH1, HD_RB2 //　りょ

#endif // JP_YOUON_COMBOS_ALL // All Japanese contracted sounds
#endif // JP_YOUON_COMBOS  // Major Japanese contracted sounds as combos
#endif // JP_MODE_ENABLE // All Japanese mode features


#endif // COMBO_ENABLE