/*
 Adaptive Keys
 Called from early within process_record_user
 
 Tailored for HD Vibranium-x (vx)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 */


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
        case KC_B:
            switch (prior_keycode) {
                case KC_D: // avoid SFB/step (LB is 1.6x more common than DB)
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = true; // done.
                    break;
//                case KC_P: // avoid scissor (MB is 67x more common than PB)
                case KC_T: // avoid scissor (MB is 34x more common than TB)
                case KC_X: // avoid scissor (MB is 1174x more common than XB)
                    tap_code(KC_BSPC);
                    tap_code(KC_M);
                    return_state = true; // done.
                    break;
           }
            break;
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch (free letter, eliminates H-digraph combo SFB)
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of key press "H"
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_D:
            switch (prior_keycode) { //
                case KC_B:
                    tap_code(KC_L);  // eliminate stretch (bl is 93x more common than BD)
                    return_state = false; // done.
                    break;
                case KC_L:
                    if (preprior_keycode == KC_P) { // roll PLD = PWD? (no side effects?)
                        tap_code(KC_BSPC);
                        tap_code(KC_W); // replace the L with W
                        break; // process the D normally
                    }
            }
            break;
        case KC_G:
            switch (prior_keycode) {
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
                case KC_J: // roll JG => jpg free letter!
                    tap_code(KC_P); // insert a P
                    break; // and let current keycode send normally
                case KC_W:
                    tap_code(KC_D); // pull up D (WD is 35x more common than WG)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // eliminate scissor (GL is 5x more common than GM)
                case KC_V: // eliminate scissor (VL is 2.6x more common than VM)
                case KC_C: // step for upper column pref (CL is 7.6x more common than CM)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
                    switch (preprior_keycode) {
                        case KC_M:
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        default:
                            tap_code(KC_BSPC);
                            send_string("lm");
                            return_state = false; // done.
                            break;
                   }
            }
            break;
        case KC_W: // W becomes P (pull up "P" to same row)
            switch (prior_keycode) {
                case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
                    if (preprior_keycode == KC_W) { // except for WMW -> lml?
                        tap_code(KC_L); // replace the W with L
                        return_state = false; // done.
                        break;
                    } // drop through!
                case KC_W: // WW doesn't exist, so to permit PP after M...
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_D); // eliminate SFB on index
                    return_state = false; // done.
                    break;
                case KC_N: // avoid SFB (NL is 10x more common than NW)
                    tap_code(KC_L);
                    return_state = false; // done.
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
                case KC_V: // eliminate SFB
                    tap_code(KC_BSPC); // delete the V
                    tap_code(KC_L); // vn = ln (LN 37x more common)
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
            }
            break;
        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_K: // eliminate index-middle stretch with alt fingering
                    tap_code(KC_N); // (KN is 48x more common than KT)
                    return_state = false; // not done
                    break;
            }
            break;
            // remedy ring-index split by shifting fingering
            // Since the hand is already displaced to reach the inner column,
            // pull the L over with alternate fingering to avoid the stretch.
        case KC_K:
            switch (prior_keycode) {
                case KC_G: // eliminate index-middle stretch with alt fingering
                    tap_code(KC_BSPC); // replace G
                    tap_code(KC_L); // GK = LK (LK is 75x more common than GK)
                    break; // Send K normally
                case KC_T:
                    tap_code(KC_BSPC); // replace D
                    tap_code(KC_C); // DK = CK (CK is 348x more common than DK)
                    break; // Send K normally
            }
            break;

        case KC_V:
            switch (prior_keycode) {
                case KC_G: // "GT" is 363x more frequent than "GV"
                    tap_code(KC_T); // eliminate GT SFB.
                    return_state = false; // done.
                    break;
                case KC_M: // eliminate LV scissor.
                    tap_code(KC_BSPC); // replace M
                    tap_code(KC_L); // "LV" is 119x more frequent than "MV"
                    break;
            }
            break;
        case KC_X:
            switch (prior_keycode) {
                case KC_L: // eliminate LV scissor.
                    tap_code(KC_V); // "LV" is 113x more frequent than "LX"
                    return_state = false; // done.
                    break;
                case KC_D: // eliminate DT SFB.
                    tap_code(KC_T); // "DT" is 61x more frequent than "DX"
                    return_state = false; // done.
                    break;
                case KC_P: // eliminate awkward ring/pinky step.
                    tap_code(KC_S); // "PS" is 2023x more frequent than "PX"
                    return_state = false; // done.
                    break;
                case KC_B: // eliminate sfb
                    tap_code(KC_J); // "BJ" is 840x more common than "BX"
                    return_state = false; // not done
                    break;
           }
            break;

        case KC_J:
            switch (prior_keycode) {
                case KC_G: // "GTH" is an awkward trigram/skipgram
                    send_string("th"); // for "length"
                    return_state = false; // done.
                    break;
                case KC_M: // Eliminate MN Scissor (still same fingers)
                    tap_code(KC_B); // MJ = mn (MB is 869x more common than MJ)
                    return_state = false; // done.
                    break;
                case KC_W: // Eliminate WL scissor (still same fingers)
                    tap_code(KC_L); // WJ = wl (WL is 468x more common than WJ)
                    return_state = false; // done.
                    break;
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



/*
// right hand adaptives
*/
            
          case KC_QUOT:
              switch (prior_keycode) {
                  case KC_DOT:
                      send_string("org");
                      return_state = false; // done.
                      break;
#ifndef ADAPT_VOWEL_H
                  case KC_A: //
                      tap_code(KC_U); // "A'" yields "AU"
                      return_state = false; // done.
                      break;
                  case KC_U:
                      tap_code(KC_A); // "U'" yields "UA"
                      return_state = false; // done.
                      break;
                  case KC_E:
                      tap_code(KC_O); // "E'" yields "EO"
                      return_state = false; // done.
                      break;
                  case KC_O:
                      tap_code(KC_E); // "O'" yields "OE"
                      return_state = false; // done.
                      break;
/*#else // regain v-H rolls (kludgy? unnecessary?)
                  case KC_A:
                  case KC_U:
                  case KC_E:
                  case KC_O:
                  case KC_I:
                      tap_code(KC_H); // "IH" yields "IF" (96x more common)
                      return_state = false; // done.
*/
#endif
              }
              break;
        case KC_SLSH:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("com");
                    return_state = false; // done.
            }
            break;
        case KC_DQUO:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("edu");
                    return_state = false; // done.
                    break;
                case KC_SLSH: // /" => ?
                    tap_code(KC_BSPC);
                    tap_code16(KC_QUES);
                    return_state = false; // done.
            }
            break;
        case KC_COMM:
            switch (prior_keycode) {
                case KC_COMM: // double comma = CAPS_WORD.
                    tap_code(KC_BSPC);
                    toggle_caps_word();
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_DOT:
            switch (prior_keycode) {
                case KC_SLSH: // /. => !
                    tap_code(KC_BSPC);
                    tap_code16(KC_EXLM);
                    return_state = false; // done.
                    break;
            }
            break;

#ifdef ADAPT_VOWEL_H
#if defined(ADAPT_AE_AU) || defined(DE_ADAPTIVES) // AU is really common in German (and influences EN/FR)
        case KC_E:
            switch (prior_keycode) {
                case KC_A: // "AE" yields "AU" (8x more common)
                    tap_code(KC_U);
                    return_state = false; // done.
            }
            break;
#endif // ADAPT_AE_AU
#endif // ADAPT_VOWEL_H
        case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!) so adaptive H is a sort of Magic Key
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
#ifdef ADAPT_VOWEL_H
#if !defined(ADAPT_AE_AU) && !defined(DE_ADAPTIVES) // AU is really common it German (and influences EN/FR)
                case KC_A: // AE is a fraction less common (8x), but the EAE trill may be harder than EAH.
                    tap_code(KC_U); // "AH" yields "AU" (7x more common)
                    return_state = false; // done.
                    break;
#endif // ADAPT_AE_AU or !DE_ADAPTIVES
                case KC_U:
                    tap_code(KC_A); // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
                case KC_E: // these EO/OE adaptives are of questionable value
                    tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB?)
                    return_state = false; // done.
                    break;
#endif // ADAPT_VOWEL_H
                case KC_I: // IF = IY (eliminate SFB on ring finger)
                    tap_code(KC_Y); // (inverted IH->IF = IF->IY)
                    return_state = false; // done.
                    break;
/*
                case KC_I: // avoid row skip on outward pinky roll
                    tap_code(KC_Y); // "IH" yields "IF" (96x more common)
                    return_state = false; // done.
                    break;
*/
                case KC_Y: // (y'all)
                    return_state = false; // done.
#ifdef FR_ADAPTIVES // eliminate 'h SFB for French
                case KC_J: // ex. j'habite
                case KC_L: // ex. l'hôtel
                case KC_N: // ex. n'habite
                case KC_D: // ex. d'habitude
#ifdef EN_HDIGRAPH_COMBOS
                case KC_T: // t'habitude can't do this (bc Th) unless Th digraph combo is used…
#endif // EN_HDIGRAPH_COMBOS
#endif // FR_ADAPTIVES
                    tap_code(KC_QUOT); // YH => Y' (pull down to reduce ring-pinky T-B scissor)
                    break;
                case KC_M: // MH->MN eliminate SFB (15x)
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
                case KC_L: // LH->LL eliminate double tap SFB "ll" (355x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
#ifdef DE_ADAPTIVES // AU is really common it German (and influences EN/FR)
        case KC_I:
            switch (prior_keycode) {
                case KC_A: // "AI" yields "AU" (8x more common)
                    tap_code(KC_U);
                    return_state = false; // done.
                    break;
            }
            break;
#endif // DE_ADAPTIVES
        case KC_F:
            switch (prior_keycode) { // IF is much more common than IY, so optimizing
                case KC_Y: // YF = YI (eliminate SFB on ring finger)
                    tap_code(KC_I); // (YI is 37x more common)
                    return_state = false; // done.
                    break;
            }
            break;


#ifdef THUMB_REPEATER
        case HD_REPEATER_A: // Make a repeat key of the secondary thumb key on both sides
        case HD_REPEATER_B: // for most common double letters (inherently SFBs)
            switch (prior_keycode) {
                case KC_A ... KC_SLASH: // should any alpha be repeated?
/* double-letter frequencies from Peter Norvig's data <https://norvig.com/mayzner.html>
                case KC_L: // 0.577% // Hands Down Platinum – not exactly recommended
                case KC_S: // 0.405%
                case KC_E: // 0.378%
                case KC_O: // 0.210%
                case KC_T: // 0.171% // Hands Down Gold
                case KC_F: // 0.146%
                case KC_P: // 0.137%
                case KC_R: // 0.121% // Hands Down Titanium/Rhodium/Vibranium
                case KC_M: // 0.096%
                case KC_C: // 0.083%
                case KC_N: // 0.073% // Hands Down Silver
                case KC_D: // 0.043%
                case KC_G: // 0.025%
                case KC_I: // 0.023%
                case KC_B: // 0.011%
                case KC_A: // 0.003%
                case KC_Z: // 0.003%
                case KC_X: // 0.003%
                case KC_U: // 0.001%
                case KC_H: // 0.001%  // Hands Down Bronze
*/
                    tap_code(prior_keycode); // eliminate SFB on double
                    return_state = false; // done.
            }
            break;
#endif // THUMB_REPEATER
#ifdef ADAPTIVE_TRAILER
#include "adaptive_trailer.c"
#endif // ADAPTIVE_TRAILER

    }
    if (return_state)  // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);

    return return_state; //
}
