/*
 Adaptive Keys
 Called from early within process_record_user
 
 Tailored for HD Vibranium-f (vf)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 */
//    Base (alpha) Layer  Hands Down Vibranium-vf (HRMs /+ thumb mods)
//      ╭─────────────────────╮                 ╭─────────────────────╮
// esc  │  X   W   M   G   J  │ L_CFG     L_NUM │  #$  .:  /*  "[  '] │ LANG2/henk
// tab  │  S   C   N   T   K  | (             ) |  ,;   A   E   I   H │ LANG1/mhen
//  Z   │  F   P   L   D   V  │ [ copy   pste ] │  -+   U   O   Y   B │ Q
//      ╰───────────╮ bsp  R  │ &             | │ spc  ret ╭──────────╯
//    left rght app ╰─────────╯                 ╰──────────╯ tgLN  up  dn
//
// For small boards, Q (LT3) & Z (LT4) are (also) on the sym layer


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_timer) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    } // may want more granular control than this…

//        switch (((keycode >= SAFE_RANGE) && (keycode <= SemKeys_COUNT)) ? (keycode) : (keycode & QK_BASIC_MAX)) { // only handling normal, SHFT or ALT cases.

    switch (keycode) { // process ignoring multi-function keys & shift state?
/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of key press "H"
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_D: // (for KD=KL; least code, no side effects)
            switch (prior_keycode) { //
                case KC_K:
                case KC_V:
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_L:
                    if (preprior_keycode == KC_P) { // PLD = PWD?
                        tap_code(KC_BSPC);
                        tap_code(KC_W); // replace the L with W
                        break; // process the D normally
                    }
            }
            break;
        case KC_E: // AH is just 10% more common than AE
            switch (prior_keycode) {
                case KC_A: //
                    tap_code(KC_U); // AU is 8.6x more common than AE
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_D: // eliminate DV SFB
                    tap_code(KC_V);
                    return_state = false; // done.
                    break;
                case KC_P: // avoid row step (PS is 36x more common than PF)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_G:
            switch (prior_keycode) {
                case KC_J: // roll JG => jpg free letter!
                    tap_code(KC_P); // insert a P
                    break; // and let current keycode send normally
                case KC_K: // eliminate index-middle stretch with alt fingering
                    tap_code(KC_L);  // pull up "L" (KL is 5x more common than KG)
                    return_state = false; // done.
                    break;
               case KC_M: // eliminate scissor
                    if (preprior_keycode == KC_W) { // to roll WMG -> lml? (no side effects?)
                        tap_code(KC_L); // G kecomes L for "LML"
                        return_state = false; // done.
                        break; // and let current keycode send normally
                    }
                    tap_code(KC_BSPC); // replace M
                    tap_code(KC_L); // "pull up" L to eliminate scissor
                    break; // and let current keycode send normally
                case KC_W:
                    tap_code(KC_D); // pull up D (WD is 35x more common than WG)
                    return_state = false; // done.
                    break;
            }
            break;

#ifndef ADAPT_H // if not using the default
        case KC_H: // H precedes a vowel vastly more often than it follows (thanks, Ancient Greek!) so adaptive H is a sort of Magic Key
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
                case KC_L: // Eliminate NN SFB
                     tap_code(KC_N); // "LH" yields "LN" (4.8x more common)
                    return_state = false; // done.
                    break;
/*
                case KC_M: // Eliminate ML SFB (using MV instead)
                     tap_code(KC_L); // "MH" yields "ML" (7x more common)
                    return_state = false; // done.
                    break;
*/
                case KC_N: // Eliminate NL SFB
                     tap_code(KC_L); // "NH" yields "NL" (2.6x more common)
                    return_state = false; // done.
                    break;
                case KC_U: // Eliminate UA SFB
                     tap_code(KC_A); // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
            }
            break;
 #endif // ADAPT_H


        case KC_J:
            switch (prior_keycode) {
                case KC_G: // 99.7% of GT are followed by H
                    send_string("th"); // as in "length"
                    return_state = false; // done.
                    break;
                case KC_M: // Eliminate ML SFB (ML is 43.43x more common than MJ)
                case KC_W: // Eliminate WL scissor (WL is 468x more common than WJ)
                    tap_code(KC_L); //
                    return_state = false; // done.
                    break;
#ifdef ADAPT_J // if not using the default
                case KC_A: //
                    tap_code(KC_U); // "AJ" yields "AU"
                    return_state = false; // done.
                    break;
                case KC_E: //
                    tap_code(KC_O); // "EJ" yields "EO"
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "OJ" yields "OE"
                    return_state = false; // done.
                    break;
                case KC_U: //
                     tap_code(KC_A); // "UJ" yields "UA"
                    return_state = false; // done.
                    break;
#endif // ADAPT_J

            }
            break;
            // Since the hand is already displaced to reach the inner column,
            // pull the L over with alternate fingering to avoid the lateral stretch.
        case KC_K:
            switch (prior_keycode) {
                case KC_D: // eliminate index-middle stretch with alt fingering
                case KC_G:
                    tap_code(KC_BSPC); // replace D/G
                    tap_code(KC_L); // D/GK = LK (LK ismore common than D/GK)
                    break; // Send K normally
                case KC_T: // eliminate lateral stretch
                    tap_code(KC_BSPC); // replace T
                    tap_code(KC_C); // HK = CK
                    break; // Send K normally
            }
            break;
        case KC_L: // catch this so we can unshift L on these involving pinky/ring rolls.
            switch (prior_keycode) {
                case KC_P:
                case KC_B: //
                case KC_S: //
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_X: // pull up "L" (XL is 1.5x more common than XM)
                case KC_C: // step for upper column pref (CL is 7.6x more common than CM)
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
                    switch (preprior_keycode) {
                        case KC_M: // for lml
                        case KC_X: // for xpl
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        default:
                            tap_code(KC_BSPC);
                            send_string("lm");
                            return_state = false; // done.
                            break;
                    }
                    break;
            }
            break;
            // If not using H-digraph combos, consider this adaptive solution?
#ifndef EN_HDIGRAPH_COMBOS
        case KC_N: // N becomes H (for H-Digraph rolls)
            switch (prior_keycode) {
                case KC_P: // pn = ph (ph 78x more common)
                case KC_G: // gn = gh (gh 2.5x more common)
                case KC_S: // sn = sh (sh 33x more common)
                case KC_W: // wn = wh (wh 3.8x more common)
                case KC_C: // cn = ch (sh 694x more common)
                case KC_T: // tn = th (LM 354x more common)
                    tap_code(KC_H);
                    return_state = false; // done.
            }
            break;
#else
        case KC_N: // N becomes H (for H-Digraph rolls)
            switch (prior_keycode) {
                case KC_T: // "TION" is 58x more common than "TN"
                    send_string("ion");
                    return_state = false; // done.
                    break;
                case KC_X: // xn = ln (LN 101x more common)
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = true; // let the N happen.
                    break;
            }
            break;
#endif
        case KC_P:
            switch (prior_keycode) {
                case KC_D: // DP = DT eliminate SFB (DT is 2.5x more common)
                    tap_code(KC_G);
                    return_state = false; // done.
                    break;
                case KC_F: // Pull S down (SP is 860x more common than FP)
                    tap_code(KC_BSPC);
                    tap_code(KC_S); //(but maybe should be BS? SP/BS are about equal...)
                    break;
            }
            break;
        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_K: // quickly typing "k?" yields "kn" (+48x)
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_V: // remedy inner column split by shifting fingering
            switch (prior_keycode) {

                case KC_T: // TK/DK/GK = LK ()
                case KC_G: //
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
           }
            break;
        case KC_W: // W becomes P (pull up "P" to same row)
            switch (prior_keycode) {
                case KC_G:
                    tap_code(KC_D); // eliminate SFB on index
                    return_state = false; // done.
                    break;
                case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
                    if (preprior_keycode == KC_W) { // except for WMW -> lml?
                        tap_code(KC_L); // replace the W with L
                        return_state = false; // done.
                        break;
                    } // drop through!
                case KC_W: // WW doesn't exist, so to permit PP after M...
                case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
                case KC_N: // avoid SFB (NL is 10x more common than NW)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_X:
            switch (prior_keycode) {
                case KC_D: // eliminate DJ SFB.
                    tap_code(KC_J); // "DJ" is 103x more frequent than "DX"
                    return_state = false; // done.
                    break;
                case KC_G: // eliminate GT SFB.
                    tap_code(KC_T); // "GT" is 778x more frequent than "GX"
                    return_state = false; // done.
                    break;
                case KC_M:  // eliminate MN SFB.
                    tap_code(KC_N); // "MN" is 248x more frequent than "MX"
                    return_state = false; // done.
                    break;
               case KC_W:  // eliminate WS scissor.
                    tap_code(KC_S); //
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_Y:
            switch (prior_keycode) {
                case KC_Y: // "YY" basically never occurs, so double-tap YY = YI instead of row change
                    tap_code(KC_I); // 191x
                    return_state = false; // done.
                    break;
            }
            break;
/*
// right hand adaptives
*/
#include "adapt_h.c" // the common vowel block adaptives (esp. for AU SFB)

#if defined (HD_MAGIC) || defined (HD_MAGIC_A) || defined (HD_MAGIC_B)
#include "adapt_magic.c" // the common adaptive "magic" key
#endif //

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
    }
    return return_state; //
}
