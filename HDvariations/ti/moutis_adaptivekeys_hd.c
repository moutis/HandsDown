/*
 Adaptive Keys
 Called from within process_record_user
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 Tailored for HD Titanium (ti)

 Finally getting to the last of imagined features that spurred Hands Down design!
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 All the goto shenanigans should be resolved after complete migration to STM/RP controllersr
 (not totally possible, as some of my boards have embedded AVR mcus

 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.

    
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
        case KC_F: //
            switch (prior_keycode) { //
              case KC_D: // hande "DG" SFB with D leading (DF is less than 1/10 as common.
                    tap_code(KC_G);  // pull over "G"
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch");
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_J:
            switch (prior_keycode) { //
                case KC_P:  // quickly typing "PJ" yields "PDF" (rolling shortcut for PDF, awk SFB)
                    send_string("df");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_X: // XM = LM (97x more common)
                    goto ReplacePriorWithL; // short jumps save bytes
                case KC_P: // pull up "L" (PL is 15x more common than PM)
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                    goto PullUpLAndExit;
            }
            break;
        case KC_D: // (for KD=KL; least code, no side effects)
        case KC_P: //
            switch (prior_keycode) { //
                case KC_X:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
                case KC_K:
PullUpLAndExit:
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_G:
                    goto ReplacePriorWithL; // short jumps save bytes
            }
            break;

        case KC_G:
            switch (prior_keycode) {
                case KC_P: // pull up "D" to eliminate SFB (PD is >1.5x more common than PG)
                    tap_code(KC_D);
                    return_state = false; // done.
                    break;
               case KC_M:
ReplacePriorWithL:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break;
                case KC_X:  // eliminate SFB (XC 1374x more common than XG)
                    tap_code(KC_C);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_K:
            switch (prior_keycode) {
                case KC_T: // TK = LK (remedy mid-index split by shift fingering)
                case KC_P: // PK = LK
                    goto ReplacePriorWithL; // short jumps save bytes
            }
            break;
        case KC_S: //
            switch (prior_keycode) { //
                case KC_C: // invert "SC" outward roll (5.6x more common than "CS")
                    tap_code(KC_BSPC);
                    send_string("sc");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_K: // quickly typing "k?" yields "kn"
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_X: //
            switch (prior_keycode) { //
              case KC_G:  // remedy SFB (GS 2590x more common than GX)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
                case KC_P: // remedy SFB (PT 2025x more common than PX)
                    tap_code(KC_T);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_W:
            switch (prior_keycode) {
                case KC_L: // LX = LM (75x more common)
                    tap_code(KC_M); // (reflexive of WM=LM, except leading letter first.)
                    return_state = false; // done.
                    break;
                case KC_D: // DX = DT eliminate SFB, 62x more common, like PT
                    // Index->pinky roll is a whole wrist wave, less individual finger motion, so rather easy.
                    tap_code(KC_T);
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

        case KC_H: // H becomes the SFB vowel
            switch (prior_keycode) {
                case KC_A:
                    tap_code(KC_U); // "AH" yields "AU"
                    return_state = false; // done.
                    break;
                case KC_E:
                    tap_code(KC_O); // "EH" yields "EO"
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "OH" yields "OE"
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A); // "UH" yields "UA"
                    return_state = false; // done.
                    break;

            }
            break;
        
        case KC_Y:
            switch (prior_keycode) {
                case KC_W: //
                    send_string("hy ");  // bc "HY" is pinky->ring on diff rows
                    return_state = false; // done.
                    break;
            }
            break;
                    
        case KC_B:
            switch (prior_keycode) {
                case KC_Y: //
                    tap_code(KC_I); // eliminate SFB on ring finger
                    return_state = false; // done.
                    break;
            }
            break;

#ifdef THUMB_REPEATER
        case KC_BSPC: // Make a repeat key of the secondary thumb key on both sides
        case KC_ENT: // for most common double letters (inherently SFBs)
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
        case KC_MINS: // Using Adaptives for macros (flexible LeaderKey)
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

    }
//    (return_state) ? (set_mods(saved_mods);prior_keycode = keycode = 0) : (prior_keycode = keycode);
    if (return_state) {
        set_mods(saved_mods);
//        prior_prior_keycode = 
        prior_keycode = keycode = 0;
    }
/*    else {
        prior_keycode = keycode;
    }
*/
    return return_state; //
}
