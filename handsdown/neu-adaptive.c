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
//              Hands Down Neu
// ╭─────────────────────╮ ╭─────────────────────╮
// │  W   F   M   P   V  │ │  #$  .:  /*  "[  '] │
// │  R   S   N   T   B  | |  ,;   A   E   I   H │
// │  X   C   L   D   G  │ │  -+   U   O   Y   K │
// ╰───────────╮ BSP SPC │ │ SPC  RET ╭──────────╯
//             ╰─────────╯ ╰──────────╯
// Q (LT3) & Z (LT4) are on the punc layer

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
        case KC_B:  // avoid the index-middle split
            switch (prior_keycode) {
                case KC_P: // pull up M over
                    tap_code(KC_M);
                    return_state = false; // done.
                case KC_D: // pull L over
                    goto PullUpLAndExit; // short jumps save bytes
                break;
           }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_P: //
                case KC_F: //
PullUpLAndExit:
                    tap_code(KC_L);  //
                    return_state = false; // done.
                    break;
                case KC_W: // WM = LM (LM 20x more common)
ReplacePriorWithL:
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break;
            }
            break;
        case KC_D: //
            switch (prior_keycode) { //
                case KC_G:
                    goto PullUpLAndExit; // short jumps save bytes
            }
            break;
        case KC_P:
            switch (prior_keycode) {
                case KC_F: // avoid the scissor
                    goto ReplacePriorWithL; // short jumps save bytes
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
                case KC_V: // avoid the index-middle split
                    goto PullUpLAndExit; // short jumps save bytes
            }
            break;
        case KC_G: // avoid the index-middle split
            switch (prior_keycode) {
                case KC_T: // pull N over
                    tap_code(KC_N);
                    return_state = false; // done.
               case KC_D: // pull L over
                    goto ReplacePriorWithL;
            }
            break;

        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_B: //
                    goto PullUpLAndExit; // short jumps save bytes
                    break;
                case KC_G:
                    send_string("ght"); // GHT is much more common
                    return_state = false; // done.
                    break;
            }
            break;


/*
// right hand adaptives
*/

        case KC_E: //
            switch (prior_keycode) { //
                case KC_A:
                    tap_code(KC_U); // "AE" yields "AU" (8x more common)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_H: // How often are we likely to hit BS so quickly after?
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
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

            }
            break;

        case KC_K:
            switch (prior_keycode) {
                case KC_Y:  // eliminate SFB on ring finger
                    tap_code(KC_I);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_U:
            switch (prior_keycode) {
                case KC_K: // make KU send Qu
                    tap_code(KC_BSPC);
                    tap_code(KC_Q);
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
