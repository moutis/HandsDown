/*
 Adaptive Keys
 Called from within process_record_user
 
 ** This will misbehave w/o QMK 14.1 or later (Sevanteri's early combos)

 uses globals 
 uint16_t prior_keycode = KC_NO; // for process_adaptive_key
 uint16_t prior_keydown = 0;


 */


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
static uint16_t prior_keycode = KC_NO; // for process_adaptive_key
static uint16_t prior_keydown = 0;
bool return_state = true; // assume we don't do anything.

    if (record->event.pressed) {
        keycode = keycode & 0xFF; // ignore all mods
        if ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
            switch (keycode) {
                case KC_D:
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
                    }
                    break;
                case KC_M:
                    switch (prior_keycode) {
                        case KC_F:
                        case KC_P:
                        case KC_K:
                        case KC_W:
                        case KC_V:
                            tap_code(KC_L);
                            return_state = false; // done.
                    }
                    break;
                case KC_P:
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K:
                        case KC_V:
                            tap_code(KC_L); // quickly typing "kv" yields "lv"
                            return_state = false; // done.
                            break;
                        case KC_F: // "f?" is really uncommon, we prolly want "L?"
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(keycode);
                            return_state = false; // done.
                    }
                    break;
                case KC_B: // take advantage of B & V being phonotacically similar
                case KC_V: // (in same finger/column) to process as adaptive key
                    switch (prior_keycode) {
                        case KC_M:
                        case KC_N:
                            tap_code(KC_B); // "v" is likely a "b"
                            return_state = false; // done.
                            break;
                        case KC_F:
                        case KC_P:
                            tap_code(KC_BSPC); // get rid of the prior
                            tap_code(KC_L); // quickly typing "p?" yields "l?"
                            tap_code16(keycode); //
                            return_state = false; // done.
                    }
                    break;
            }
        }
        prior_keycode = keycode;
        prior_keydown = timer_read(); // (re)start prior timing
    }
    return return_state; //
}
