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
        keycode = keycode & 0xFF; // ignore all mods? or just shift?
        if ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
            switch (keycode) {

/*
// Left hand adaptives (most are single-handed, bc speed, dexterity limits)
*/

                case KC_D:
                case KC_F:
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K:
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        case KC_M: // LF
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                        case KC_P:
                            tap_code(KC_S);
                            return_state = false; // done.
                    }
                    break;
                case KC_G:
                    switch (prior_keycode) {
                        case KC_I: // IG =
                            send_string("ng ");
                            return_state = false; // done.
                    }
                    break;
                case KC_L:
                    switch (prior_keycode) {
                        case KC_M: // ML = LL
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                    }
                    break;

                case KC_M:
                    switch (prior_keycode) {
                        case KC_D:
                        case KC_F:
                        case KC_K:
                        case KC_P:
                        case KC_V:
                        case KC_W:
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_L);
                            return_state = false; // done.
                    }
                    break;
                case KC_N: // Do we need to watch for more?
                    switch (prior_keycode) {
                        case KC_P: // is this needed?
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_H); // quickly typing "?n" yields "?h"
                            return_state = false; // done.
                            break;
                        case KC_T: // demonstrator. TN combo is "TH" digraph
                            send_string("ion");
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
                            unregister_code(KC_RSFT); // remove shift here.
                            send_string("apan");
                            return_state = false; // done.
                            break;
                        case KC_H: // "hp" is "lp" on Platinum
                            tap_code(KC_BSPC);
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                            break;
                        case KC_B:
                        case KC_K:
                        case KC_V: // quickly typing "?p" yields "?l"
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_L);
                            return_state = false; // done.
                            break;
                        case KC_M:
                        case KC_F: // "f?" is really uncommon, we prolly want "l?"
                            tap_code(KC_BSPC);
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                    }
                    break;
                case KC_T:
                    switch (prior_keycode) {
                        case KC_K: // ML = LL
                            tap_code(KC_L);
                            return_state = false; // done.
                    }
                    break;
                case KC_U:
                    switch (prior_keycode) {
                        case KC_Y: // YU = You bc YO is a tad awk, but yu is easy, and uncommon
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code(KC_O);
                            tap_code(KC_U);
                            return_state = false; // done.
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
                        case KC_P:  /* this is for bronze */
                            tap_code(KC_BSPC); // get rid of the prior
                            tap_code(KC_L); // quickly typing "p?" yields "l?"
                            tap_code16(keycode); //
                            return_state = false; // done.
                            break;
                        case KC_H: /* mostly for platinum */
                           tap_code(KC_L); // quickly typing "hv" yields "lh"
                    }
                    break;

                case KC_S:
                    switch (prior_keycode) { // demonstrator. SN combo is "SH" digraph
                        case KC_T:
                            tap_code(KC_N);
                        case KC_N:
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
                        case KC_F: // and equalizes column-stagger & ortho boards.
                        case KC_G: //
                        case KC_M: // anything that is statistically much more frequent
                        case KC_P: // bc why not?
                        case KC_V: //
                            unregister_code(KC_LSFT); // remove shift here.
                            unregister_code(KC_RSFT); // remove shift here.
                            tap_code16(KC_R);
                            return_state = false; // done.
                            break;
                        case KC_L: // repeater (For Platinum's thumb-L)
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
        }
        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior_key timing
    }
    return return_state; //
}
