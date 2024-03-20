/*
 Adaptive Keys
 Called from within process_record_user
 
 Tailored for HD Vibranium-b (vb)
 
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

    switch (keycode & QK_BASIC_MAX) { // process ignoring multi-function keys

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of key press "H"
                    return_state = false; // done.
                    break;
                case KC_B: // eliminate BS SFB (BS is 23x more common than BC)
                    tap_code(KC_S);  //
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_B:
            switch (prior_keycode) {
                case KC_P: // avoid row step (PS is 40x more common than PB)
                    tap_code(KC_S);
                    return_state = false; // done.
                case KC_C: // eliminate SB SFB (CB is 11x more common than SB)
                    tap_code(KC_BSPC);
                    tap_code(KC_S);
                    break;
           }
            break;

        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_X: // pull up "L" (XL is 1.5x more common than XM)
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
                    if (!preprior_keycode) {
                        tap_code(KC_BSPC);
                        tap_code(KC_L);
                        break;
                    }
                    switch (preprior_keycode) {
                        case KC_M:
                        case KC_X:
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                    };
            }
            break;

        case KC_D: // (for KD=KL; least code, no side effects)
            switch (prior_keycode) { //
                case KC_K:
                case KC_V:
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_B: // to avoid the scissor on BM
                    tap_code(KC_M);
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

        case KC_L: // catch this so we can unshift L on these rolls.
            switch (prior_keycode) {
                case KC_P:
                case KC_B: //
                case KC_S: //
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_W: // W becomes P (pull up "P" to same row)
            switch (prior_keycode) {
                case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
                case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_D); // eliminate SFB on index
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_G:
            switch (prior_keycode) {
                case KC_K:
                    tap_code(KC_L);  // pull up "L" (KL is 5x more common than KG)
                    return_state = false; // done.
                    break;
               case KC_M:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
                case KC_J: // JG = jpg
                    tap_code(KC_P); // insert a P
                    break; // and let current keycode send normally
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" though not quite intuitive…
                    return_state = false; // done.
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

        case KC_K: // remedy ring-index split by shifting fingering
            switch (prior_keycode) {
                case KC_T: // TK = CK (>282x)
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    break;
            }
            // falling through here intentionally here. V&K are treated same.
        case KC_V: // remedy inner column split by shifting fingering
            switch (prior_keycode) {
                case KC_D: // DV/TV/GV = LV ()
                case KC_T: // TK/DK/GK = LK ()
                case KC_G: //
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
           }
            break;

        case KC_R:  // LL is the highest consonant repeat, and it's off home, so eliminate this SFB
            switch (prior_keycode) {
                case KC_L: // quickly typing "lr" yields "ll" (+56x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_X:
            switch (prior_keycode) {
                case KC_M: // "MB" is 2558x more frequent than "MX"
                    tap_code(KC_B); // pull up B from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G: // "GX" is 778x more frequent than "GT"
                    tap_code(KC_T); // eliminate GT SFB.
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_P:
            switch (prior_keycode) {
                case KC_D: // DP = DT eliminate SFB (DT is 2.5x more common)
                    tap_code(KC_G);
                    return_state = false; // done.
                    break;
                case KC_B: // Pull S down (SP is 83x more common than BP)
                    tap_code(KC_BSPC);
                    tap_code(KC_S); //(but maybe should be BS? SP/BS are about equal...)
                    return_state = true; // not done (process this key normally)
                    break;
            }
            break;


/*
// right hand adaptives
*/
            
          case KC_QUOT:
              switch (prior_keycode) {
                  case KC_DOT:
                      send_string("edu");
                      return_state = false; // done.
                      break;
                  case KC_SLSH:
                      tap_code(KC_BSPC);
                      send_string(".org");
                      return_state = false; // done.
                      break;
              }
              break;
            case KC_SLSH:
                switch (prior_keycode) {
                    case KC_DOT:
                        send_string("com");
                        return_state = false; // done.
                        break;
      
                }
                break;

        case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!)
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
                case KC_A: // AE is a fraction less common, but I find the EAE trill harder than EAH.
                    tap_code(KC_U); // "AH" yields "AU" (8x more common)
                    return_state = false; // done.
                    break;
                case KC_E:
                    tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB?)
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A); // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
                case KC_I: // avoid row skip on outward pinky roll
                    tap_code(KC_F); // "IH" yields "IF" (96x more common)
                    return_state = false; // done.
                    break;
                case KC_J: // j'habite
                case KC_L: // l'hôtel
                case KC_M: // m'homme
                case KC_N: // n'habite
                case KC_D: // d'habitude
                    tap_code(KC_QUOT);// eliminate 'h SFB for French
                    break;// (can't do it for T bc Th, unless Th digraph combo is mandatory…)
                case KC_Y: //
                    tap_code(KC_QUOT); // YH = Y' (pull down to avoid ring-pinky scissor)
                    return_state = false; // done.
                    break;

            }
            break;

        case KC_F:
            switch (prior_keycode) {
                case KC_Y: //
                    tap_code(KC_I); // YF = YI (eliminate SFB on ring finger YI is 37x YF)
                    return_state = false; // done.
                    break;
            }
            break;
            

#ifdef THUMB_REPEATER
        case HD_REPEATER_A: // Make a repeat key of the secondary thumb key on both sides
        case HD_REPEATER_B: // for most common double letters (inherently SFBs)
            switch (prior_keycode) {
                case KC_A ... KC_SLASH: // Any alpha can be repeated?
/* double-letter frequencies from Peter Norvig's data <https://norvig.com/mayzner.html>
                case KC_L: // 0.577%
                case KC_S: // 0.405%
                case KC_E: // 0.378%
                case KC_O: // 0.210%
                case KC_T: // 0.171%
                case KC_F: // 0.146%
                case KC_P: // 0.137%
                case KC_R: // 0.121%
                case KC_M: // 0.096%
                case KC_C: // 0.083%
                case KC_N: // 0.073%
                case KC_D: // 0.043%
                case KC_G: // 0.025%
                case KC_I: // 0.023%
                case KC_B: // 0.011%
                case KC_A: // 0.003%
                case KC_Z: // 0.003%
                case KC_X: // 0.003%
                case KC_U: // 0.001%
                case KC_H: // 0.001%
*/
                    tap_code(prior_keycode); // eliminate SFB on double
                    return_state = false; // done.
            }
            break;
#endif
#ifdef ADAPTIVE_TRAILER
#include "adaptive_trailer.c"
#endif // ADAPTIVE_TRAILER

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = preprior_keycode = keycode = 0;
    }
    return return_state; //
}
