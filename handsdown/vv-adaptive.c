/*
 Adaptive Keys
 Called from within process_record_user
 
 Tailored for HD Vibranium-v (vv)
 
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
        case KC_G:
            switch (prior_keycode) {
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
                case KC_J:
                    tap_code(KC_P);
                    break;
                case KC_K:
                    goto PullUpLAndExit; // short jumps save bytes
                case KC_M:
                    goto ReplacePriorWithL;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                case KC_C: // rolling "xwm" is captured here, resulting in "xcl" (taking a trigram that would step down a row at each letter, and making it a simple inward roll, replacing a trigram that does not appear in Mayzner's corpus = infinite win)
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
                    goto PullUpLAndExit; // short jumps save bytes
            }
            break;

        case KC_L: // catch this so we can unshift L on these rolls.
            switch (prior_keycode) {
                case KC_S: //
                    goto PullUpLAndExit; // no change except shift is now off
            }
            break;
        case KC_W:
            switch (prior_keycode) {
                case KC_M: // eliminate SFB (modest 7x gain)
                case KC_L: // tricksy - trilling "wmw" results in "lml" trigram instead of SFB
                    goto PullUpLAndExit; // short jumps save bytes
                case KC_G:
                    tap_code(KC_D); // eliminate SFB.
                    return_state = false; // done.
                    break;
                case KC_X: // XC is 117x more common than XW (also set up "xc"+l)
                    *calling_keycode = KC_C; // tricksy - pretend the last was C, for "xcl"
                    tap_code(KC_C); // eliminate row step.
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_D: //
                    tap_code(KC_G); // eliminate SFB (DG is 10x more common than DF)
                    return_state = false; // done.
                    break;
                case KC_V: //
                    tap_code(KC_BSPC);
                    tap_code(KC_S); // avoid row step (311x more common than VF)
                    break;
            }
            break;
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    send_string("ch"); // 85% of tc is tch, so this saves a lot of "H" key presses
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_V:
            switch (prior_keycode) {
                case KC_F: // avoid row step (91x more frequent)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_K: // remedy ring-index split by shifting fingering
            switch (prior_keycode) {
                case KC_T: // TK/DK/GK = CK (252x more frequent)
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    break;
                case KC_D: // DK = LK (11x more frequent)
                case KC_G: // GK = LK (74x more frequent)
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
                case KC_W: // eliminate scissor (2818x gain)
                    goto PullUpLAndExit;
                case KC_M: // eliminate scissor (107x gain)
                    tap_code(KC_F); // pull up F from bottom row.
                    return_state = false; // done.
                    break;
                case KC_G:
                    tap_code(KC_T); // eliminate SFB (778x gain)
                    return_state = false; // done.
                    break;
            }
            break;


/*
// right hand adaptives
*/
            
        case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!)
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
                case KC_A: // AE is a fraction less common, but I find the EAE trill harder than EAH.
                    tap_code(KC_U); // "AH" yields "AU" (8x more common, eliminates SFB)
                    return_state = false; // done.
                    break;
                case KC_E:
                    tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                    return_state = false; // done.
                    break;
                case KC_O:
                    tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB)
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A); // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
                case KC_I: // avoid row skip on outward pinky roll
                    tap_code(KC_P); // "IH" yields "IP" (41x more common)
                    return_state = false; // done.
                    break;

            }
            break;

        case KC_P:
            switch (prior_keycode) {
                case KC_Y: //
                    tap_code(KC_I); // YP = YI (eliminate SFB on ring finger YI is 37x YF)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_J:
            switch (prior_keycode) {
                case KC_QUOT:
                case KC_B: //
                    tap_code(KC_Y); // BJ = BY (eliminate scissor on ring finger BY is 6x BJ)
                    return_state = false; // done.
                    break;
                case KC_DOT:
                    send_string("edu");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_QUOT:
            switch (prior_keycode) {
                case KC_DOT:
                    send_string("com");
                    return_state = false; // done.
                    break;
                case KC_QUOT: //
                case KC_J: //
                case KC_B: //
                    tap_code(KC_O); // (eliminate scissor)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_DOT:
            switch (prior_keycode) {
                case KC_QUOT: // This could be smarter (only after O rolled up)
                case KC_J: //
                case KC_B: //
                    tap_code(KC_U); // (eliminate scissor)
                    return_state = false; // done.
                    break;
            }
            break;
      case KC_B:
          switch (prior_keycode) {
              case KC_DOT:
                  tap_code(KC_BSPC);
                  send_string(".org");
                  return_state = false; // done.
                  break;
              case KC_J:
                  tap_code(KC_I); // (eliminate SFB)
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
