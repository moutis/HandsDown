/*
 Adaptive Keys
 Called from within process_record_user
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 This will NOT work with all Hands Down Neu variants (only, Titanium (as Gold) & Bronze)
 Finally getting to the last of imagined features that spurred Hands Down design!
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).

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
    }
    switch (keycode & QK_BASIC_MAX) { // process ignoring multi-function keys

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_C:
            switch (prior_keycode) {
                case KC_T: // roll for tch
                    tap_code(KC_C);
                    tap_code(KC_H);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_B: // take advantage of B & V being phonotacically similar
        case KC_V: // (and in same finger/column) to process as adaptive key
            switch (prior_keycode) { // reducing the finger spread from middle-index
                case KC_M:
//                case KC_N:
                    tap_code(KC_B); // "v" is likely a "b"?
                    return_state = false; // done.
                    break;
                case KC_T: // "t" is midway between MB (or MV?)
                    tap_code(KC_BSPC); // so use same finger, shifted toward middle
                    tap_code(KC_M); // column, to make it an inward roll.
                    return_state = true; // send the keycode.
                    break;
                case KC_D:
                case KC_P:  // for (Bronze/Neu-hx)
                    goto ReplacePriorWithLthenBreak;
/*
                case KC_H: // (Platinum/Neu-lx)
                    goto TapLthenBreak;
*/            }
            break;
        case KC_G:
            switch (prior_keycode) {
                case KC_M:
                    goto TapLthenBreak;
                case KC_P:
ReplacePriorWithLthenBreak: // each short jump = only 2 bytes!
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    return_state = true; // send the keycode.
                    break;
                case KC_T:
                    send_string("hing");
//                case KC_I:
//                    send_string("ng");
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_K:
            switch (prior_keycode) {
                case KC_T: // DK = CK
                case KC_D: // DK = CK
                    tap_code(KC_BSPC);
                    tap_code(KC_C);
                    tap_code16(keycode);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_M: // M becomes L after DFGJPVW
            switch (prior_keycode) {
                case KC_J:
                    goto ReplacePriorWithLthenBreak;
                case KC_G:
                case KC_P:
                case KC_V:
//                case KC_W: // if on left hand
TapLthenBreak: // each short jump = only 2 bytes, so cases are ordered to keep it short.
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_P:
            switch (prior_keycode) {
//                case KC_F: // if F is on top row (where G & F swap?)
                case KC_G:
                    goto ReplacePriorWithLthenBreak;
                case KC_B:
                case KC_K:
                case KC_V: // quickly typing "?p" yields "?l"
                    goto TapLthenBreak;
/*
            case KC_H: // "hp" is "lp" (Platinum/Neu-tx)
            case KC_F: // "f?" is really uncommon, we prolly want "l?"
                tap_code(KC_BSPC);
                tap_code(KC_L);
                tap_code16(keycode);
                return_state = false; // done.
                break;
*/

            }
            break;
//                case KC_C:  // inner column accommodations
        case KC_D:  // to relieve stretch between
        case KC_T:  // index and middle (index<->others is easier)
            switch (prior_keycode) {
                case KC_B: // quickly typing "k?" yields "kn"
                    goto TapLthenBreak;
                case KC_K: // quickly typing "k?" yields "kn"
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
                case KC_M: // quickly typing "mt" yields "ment"
                    send_string("ent");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_B:
                case KC_K:
                    goto TapLthenBreak;
                case KC_P: // pull S up a row (more helpful for ortho/row staggers)
                    tap_code(KC_S);
                    return_state = false; // done.
                    break;
                case KC_X: // roll into C (only for Rhodium)
                    tap_code(KC_C);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_N: //
            switch (prior_keycode) {
                case KC_P: // Make PT SFDigraph into a roll
                    tap_code(KC_T); //
                    return_state = false; // done.
                    break;
            }
            break;
/*
 
        case KC_R: //
            switch (prior_keycode) {
                case KC_T: // iffy?
                    send_string("hey");
                    goto addRE;
                case KC_Y: // iffy?
                    send_string("ou");
                    goto addRE;
                case KC_W: // is this needed?
                    send_string("e");
addRE:
                    send_string("'re");
                    return_state = false; // done.
                    break;
            }
            break;
*/
/*       case KC_S:
            switch (prior_keycode) {
*/
/*
                case KC_T: // for "tness"
                    tap_code(KC_N);
*/
/*
                case KC_N: // for "ness"
                    send_string("ess");
                    return_state = false; // done.
                    break;
            }
            break;
*/
        //case KC_W: // for Neu?
        case KC_J: // SAME-HAND TOWARD PINKY ISSUES
            if (prior_keycode == KC_M) {
                tap_code16(KC_F);
                return_state = false; // done.
                break;
            } // fall through to catch the rest.
        case KC_X: // adjacent fingers don't do next row as easily,especially on ring to pinky.
            switch (prior_keycode) {
                case KC_B: //
                case KC_C: // RING TO PINKY This softens the burden,
                case KC_D: //and equalizes column-stagger & ortho boards.
                case KC_F: //
                case KC_G: //
                case KC_P: // bc why not?
                case KC_V: //
                    tap_code16(KC_R);
                    return_state = false; // done.
                    break;
                case KC_L: // L repeater (ie. Platinum/Neu-lx)
                    tap_code(prior_keycode); // LW isn't likely, so we'll leave it for the sake of smaller code
                    return_state = false; // done.
                    break;
            }
            break;

/*
// right hand adaptives
*/
        case KC_A:
            switch (prior_keycode) {
                case KC_COMM: //  ",A" yields "UA" eliminating SFB
                case KC_SLSH: //  "/A" yields "UA" eliminating SFB
                    tap_code(KC_BSPC); // get rid of the prior
                    tap_code(KC_U); // first send U
                    return_state = true; // then the keycode.
                    break;
            }
            break;
        case KC_E:
            switch (prior_keycode) {
//                case KC_DOT:
                case KC_COMM: // ",E" or ".E" yields "OE" eliminating SFB
                    tap_code(KC_BSPC); // get rid of the prior
                    tap_code(KC_O); // first send O
                    return_state = true; // then the keycode.
                    break;
                case KC_A: // "AE" yields "AU" eliminating SFB
                    goto tapUbreak;
            }
            break;
//        case KC_DOT:
        case KC_COMM:
            switch (prior_keycode) {
                case KC_A:
tapUbreak:
                    tap_code(KC_U); // ",/.A" yields "UA" eliminating SFB
                    return_state = false; // send the keycode.
                    break;
                case KC_E: // tight roll controls...so this works
                    tap_code(KC_O); // "E." or "E," yields "EO" eliminating SFB
                    return_state = false; // send the keycode.
            }
            break;
        case KC_SLSH:
            switch (prior_keycode) {
                case KC_A:
                    goto tapUbreak; // ",/.A" yields "UA" eliminating SFB
                case KC_DOT:
                    send_string("com");
                    return_state = false; // done.
            }
            break;
        case KC_U:  // "you" adaptive?
            switch (prior_keycode) {
                case KC_Y: // YU = You bc YO (ring-middle) is a tad awk, but yu is easy, and uncommon
                    send_string("ou ");
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_Y:
            switch (prior_keycode) {
                case KC_W: // WY = WH do avoid row jump (Gold)
                    tap_code(KC_H);
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_MINS:
             switch (prior_keycode) {
                 case KC_L:
                     tap_code16(prior_keycode); // repeater (For Platinum's thumb-L)
                     return_state = false; // done.
                     break;
             }
             break;
    }
//    (return_state) ? (set_mods(saved_mods);prior_keycode = keycode = 0) : (prior_keycode = keycode);
    if (return_state) {
        set_mods(saved_mods);
        prior_keycode = keycode = 0;
    }
/*    else {
        prior_keycode = keycode;
    }
*/
    return return_state; //
}
