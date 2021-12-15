/*
 Adaptive Keys
 Called from within process_record_user
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 I think this will work with all Hands Down Neu variants (Platinum, Gold, Silver, Bronze)
 Finally getting to the last of imagined features that spurred Hands Down design!
 
 uses globals 
 uint16_t prior_keycode = KC_NO; // for process_adaptive_key
 uint16_t prior_keydown = 0; // time since finished processing prior_keycode
 
 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    static uint16_t prior_keycode = KC_NO; // for process_adaptive_key
    static uint16_t prior_keydown = 0;

    if (record->event.pressed) {
        if ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
            saved_mods = get_mods();  // !!! We're using the global !!!
            unregister_code(KC_LSFT); // turn off shift to facilitate
            unregister_code(KC_RSFT); // first-words & Proper nouns.
            keycode = keycode & 0xFF; // ignore all taps&mods? (or just shift?)
            switch (keycode) {

/*
// Left hand adaptives (most are single-handed, bc speed, dexterity limits)
*/

                case KC_D:
                    switch (prior_keycode) {
                        case KC_C: // CD = could unless you are a programmer, then use CU below
                        case RALT_T(KC_C): //
                        case KC_W: // WU = would bc wu is easy, and uncommon
                            send_string("ould");
                            return_state = false; // done.
                            break;
                        case KC_Y: // YU = You bc YO is a tad awk, but yu is easy, and uncommon
                            send_string("ou'd");
                            return_state = false; // done.
                            break;
                    }
                    if (!return_state) break;
                case KC_F:
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K:
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        case KC_M: // LF
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                        case KC_P: // pull S up a row (more helpful for ortho/row staggers)
                            tap_code(KC_S);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_K:
                    switch (prior_keycode) {
                        case KC_D: // DK = CK
                            tap_code(KC_BSPC);
                            tap_code(KC_C);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_L: // L repeater (Platinum/Neu-lx) like "lx"
                    switch (prior_keycode) {
                        case KC_M: // ML = LL (Platinun/Neu-lx)
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                    }
                    break;

                case KC_M: // M becomes L after DFGKPVW
                    switch (prior_keycode) {
                        case KC_D:
                        case LSFT_T(KC_D): // (Gold/Neu-tx)
                        case KC_F:
                        case KC_G:
                        case KC_K:
                        case KC_P:
                        case KC_V:
                        case KC_W:
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_N: // Do we need to watch for more?
                case LGUI_T(KC_N):
                    switch (prior_keycode) {
                        case KC_P: // is this needed?
                            tap_code(KC_H); // quickly typing "?n" yields "?h"
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_P:
                    switch (prior_keycode) {
                        case KC_J: // "jp" is "Japan"…ese? A demonstrator AK
                            tap_code(KC_BSPC);
                            register_code(KC_LSFT); // shift here.
                            tap_code(KC_J); // this should always be cap
                            unregister_code(KC_LSFT); // remove shift here.
                            send_string("apan");
                            return_state = false; // done.
                            break;
                        case KC_H: // "hp" is "lp" (Platinum/Neu-tx)
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                        case KC_B:
                        case KC_K:
                        case KC_V: // quickly typing "?p" yields "?l"
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        case KC_M:
                        case KC_F: // "f?" is really uncommon, we prolly want "l?"
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_T:
                case LSFT_T(KC_D): // Gold (Neu-tx)
                case LSFT_T(KC_T):
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K: // quickly typing "?t" yields "?l"
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_B: // take advantage of B & V being phonotacically similar
                case KC_V: // (and in same finger/column) to process as adaptive key
                    switch (prior_keycode) {
                        case KC_M:
                        case KC_N:
                            tap_code(KC_B); // "v" is likely a "b"
                            return_state = false; // done.
                            break;
                        case KC_F:
                        case KC_P:  /* (Bronze/Neu-hx) */
                            tap_code(KC_BSPC); // get rid of the prior
                            tap_code(KC_L); // quickly typing "p?" yields "l?"
                            tap_code16(keycode); //
                            return_state = false; // done.
                            break;
                        case KC_H: /* (Platinum/Neu-lx) */
                            tap_code(KC_L); // quickly typing "hv" yields "lh"
                            break;
                    }
                    break;
                    break;
                case KC_S:
                case LALT_T(KC_S):
                    switch (prior_keycode) {
                        case KC_T:
                        case LSFT_T(KC_T): // for "tness"
                            tap_code(KC_N);
                        case KC_N:
                        case LGUI_T(KC_N): // for "ness"
                            send_string("ess");
                            return_state = false; // done.
                            break;
                    }
                    break;

                case KC_J: // SAME-HAND TOWARD PINKY ISSUES
                case KC_W: // adjacent fingers don't do next row as easily,
                case KC_X: // especially on ring to pinky.
                    switch (prior_keycode) {
                        case KC_B: //
                        case KC_C: // RING TO PINKY This softens the burden,
                        case KC_D: //
                        case LSFT_T(KC_D): // (Gold/Neu-tx)
                        case KC_F: // and equalizes column-stagger & ortho boards.
                        case KC_G: //
                        case KC_M: // anything that is statistically much more frequent
                        case KC_P: // bc why not?
                        case KC_V: //
                            tap_code16(KC_R);
                            return_state = false; // done.
                            break;
                        case KC_L: // L repeater (Platinum/Neu-lx)
                            tap_code16(KC_L); // LW isn't likely, so we'll leave it for the sake of smaller code
                            return_state = false; // done.
                            break;
                    }
                    break;

/*
// right hand adaptives
*/

               case KC_A:
                    switch (prior_keycode) {
                        case KC_COMM:
                            tap_code(KC_BSPC); // get rid of the prior
                            tap_code(KC_U); // quickly typing ",A" yields "UA"
                            tap_code16(keycode); //
                            return_state = false; // done.
                            break;
                    }
                    break;
                case KC_U:
                    switch (prior_keycode) {
                        case KC_Y: // YU = You bc YO is a tad awk, but yu is easy, and uncommon
                            tap_code(KC_O);
                            tap_code(KC_U);
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
                case KC_COMM:
                    switch (prior_keycode) {
                        case KC_A:
                            tap_code(KC_U); // quickly typing "A," yields "AU"
                            return_state = false; // done.
                            break;
                    }
                    break;

            }
            if (return_state) set_mods(saved_mods); // Restore mods
        }
        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior_key timing
    }
    return return_state; //
}
