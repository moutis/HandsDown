/*
 Adaptive Keys
 Called from within process_record_user
 
 Tailored for HD Vibranium-b (vb)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 All the goto shenanigans should be resolved after complete migration to STM/RP controllersr
 (not totally possible, as many of my boards have embedded AVR mcus)

 */


bool process_adaptive_key(uint16_t *calling_keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    uint16_t keycode = *calling_keycode;
    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_on) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    } // may want more granular control than this…

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
//                case KC_B: // tricksy - trilling "mxm" results in "mbl" trigram instead of scissor
                    // but this makes norman BM = BL...so not great. proper adaptive method is needed
                    // that recognizes N-gram sequences. Maybe at the migrate to RP2040 or the like?
                case KC_P: // tricksy - trilling "mwm" results in "mpl" trigram instead of scissor
                           // rolling "xwm" is also captured here, resulting in "xpl"
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_X: // pull up "L" (XL is 1.5x more common than XM)
PullUpLAndExit:
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
                    *calling_keycode = KC_L; // tricksy - pretend the last was L, for "lml"
ReplacePriorWithL:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break;
            }
            break;
        case KC_D: // (for KD=KL; least code, no side effects)
            switch (prior_keycode) { //
                case KC_K:
                case KC_V:
                    goto PullUpLAndExit; // short jumps save bytes
            }
            break;

        case KC_L: // catch this so we can unshift L on these rolls.
            switch (prior_keycode) {
                case KC_B: //
                case KC_P: //
                case KC_S: //
                    goto PullUpLAndExit; // no change except shift is now off
            }
            break;
        case KC_W:
            switch (prior_keycode) {
                case KC_B: // tricksy - trilling "mxw" results in "mbl" trigram scissoring
                case KC_L: // tricksy - trilling "wmw" results in "lml" trigram instead of2 SFB
                    goto PullUpLAndExit; // short jumps save bytes
                case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
                case KC_M: // pull up P (W becomes P abter M to set up "mp"+l)
                    *calling_keycode = KC_P; // tricksy - pretend the last was P, for "mpl" or "xpl" trigram
                case KC_J: //
                    tap_code(KC_P); // pull up P from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_D); // eliminate SFB.
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_G:
            switch (prior_keycode) {
                case KC_K:
                    goto PullUpLAndExit; // short jumps save bytes
               case KC_M:
                    goto ReplacePriorWithL;
                case KC_J:
                    tap_code(KC_P); // yields jpg
                    break;
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_K: // remedy ring-index split by shifting fingering
            if (prior_keycode == KC_T) {// TK = CK (+282x)
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    break;
            }
            // fall through to check for these pairs
        case KC_V: // remedy mid-index split by shifting fingering
            switch (prior_keycode) {
                case KC_D: // DV/TV/GV = LV ()
                case KC_T: // TK/DK/GK = LK ()
                case KC_G: //
                    goto ReplacePriorWithL; // short jumps save bytes
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
                case KC_P: // MW->MP, so MPL rolling out
                case KC_W:
                    goto PullUpLAndExit;
                case KC_M: // "MB" is 2558x more frequent than "MX"
                    *calling_keycode = KC_B; // tricksy - pretend the last was B, for "mbl" trigram
                    tap_code(KC_B); // pull up B from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_T); // eliminate SFB.
                    return_state = false; // done.
                    break;
            }
        case KC_P:
            switch (prior_keycode) {
                case KC_D: // DP = DT eliminate SFB (DT is 2.5x more common)
                    tap_code(KC_G);
                    return_state = false; // done.
                    break;
                case KC_B: // Pull S down [SP is 83x more common than BP]
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
// Using Adaptives for macros (like a flexible LeaderKey)
        case ADAPTIVE_TRAILER:
            switch (prior_keycode) {
#ifdef adaptAMINS
                case KC_A: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptAMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptBMINS
                case KC_B: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptBMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptCMINS
                case KC_C: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptCMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptDMINS
                case KC_D: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptDMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptEMINS
                case KC_E: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptEMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptFMINS
                case KC_F: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptFMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptGMINS
                case KC_G: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptGMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptHMINS
                case KC_H: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptHMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptIMINS
                case KC_I: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptIMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptJMINS
                case KC_J: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptJMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptKMINS
                case KC_K: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptKMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptLMINS
                case KC_L: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptLMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptMMINS
                case KC_M: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptMMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptNMINS
                case KC_N: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptNMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptOMINS
                case KC_O: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptOMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptPMINS
                case KC_P: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptPMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptRMINS
                case KC_R: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptRMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptSMINS
                case KC_S: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptSMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptTMINS
                case KC_T: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptTMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptUMINS
                case KC_U: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptUMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptVMINS
                case KC_V: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptVMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptWMINS
                case KC_W: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptWMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptYMINS
                case KC_Y: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptYMINS);  //
                    return_state = false; // done.
                    break;
#endif
#ifdef adaptYMINS
                case KC_Y: //
                    tap_code(KC_BSPC); // may have been lowercase
                    send_string(adaptYMINS);  //
                    return_state = false; // done.
                    break;
#endif
            }
            break;
#endif // ADAPTIVE_TRAILER

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = keycode = 0;
    }
    return return_state; //
}
