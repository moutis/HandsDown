/*
 Adaptive Keys
 Called from early within process_record_user

 Tailored for HD Neu (neu)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).

 */
//    Base (alpha) Layer  Hands Down Neu (HRMs /+ thumb mods)
//      ╭─────────────────────╮                 ╭─────────────────────╮
// esc  │  W   F   M   P   V  │ L_CFG     L_NUM │  #$  .:  '"  /*   J │ LANG2/henk
// tab  │  R   S   N   T   B  | (             ) |  ,;   A   E   I   H │ LANG1/mhen
//  Z   │  X   C   L   D   G  │ [ copy   pste ] │  -+   U   O   Y   K │ Q
//      ╰───────────╮ bsp sft │ &             | │ spc  ret ╭──────────╯
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
        case KC_B:  // avoid the index-middle split
            switch (prior_keycode) {
                case KC_P: // pull up M over
                    tap_code(KC_M);
                    return_state = false; // done.
                case KC_D: // pull L over
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                break;
           }
            break;
        case KC_D: //
            switch (prior_keycode) { //
                case KC_G:
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_G: // avoid the index-middle split
            switch (prior_keycode) {
                case KC_T: // pull N over
                    tap_code(KC_N);
                    return_state = false; // done.
               case KC_D: // pull L over
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_V:
            switch (prior_keycode) { //
                case KC_M: // Eliminate ML SFB
                    tap_code(KC_L); // MV = ML (14.89    121716301)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_P: // pull up "L" (PL is 15x more common than PM)
                case KC_F: // pull up "L" (FL is 93x more common than FM)
                    tap_code(KC_L);  // pull up "L"
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
        case KC_P:
            switch (prior_keycode) {
                case KC_F: // avoid the scissor
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                case KC_W:
                    tap_code(KC_BSPC);
                    send_string("lml"); // for "calmly" but not quite intuitive…
                    return_state = false; // done.
                    break;
                case KC_V: // avoid the index-middle split
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_T:  // alt fingering remedy for middle-index splits
            switch (prior_keycode) {
                case KC_B: //
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                case KC_G:
                    send_string("ght"); // GHT is much more common
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
        prior_keycode = preprior_keycode = keycode = 0;
    }
    return return_state; //
}
