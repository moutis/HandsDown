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

    // assume already stripped of mods…otherwise…
    keycode = keycode & 0xFF; // now filter out the base keycode

    if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
        switch (keycode) {
            case KC_D: // process adaptive key
            case KC_F:
                switch (prior_keycode) {
                    case KC_B:
                    case KC_K:
                       tap_code(KC_L);
                        return_state = false; // don't do more with this record.
                        break;
                    case KC_M: //
                        tap_code(KC_BSPC);
                        tap_code(KC_L);
                        tap_code16(record_keycode);
                        return_state = false; // don't do more with this record.
                        break;
                }
                break;
            case KC_M: // process adaptive key
                switch (prior_keycode) {
                    case KC_F:
                    case KC_P:
                    case KC_K:
                    case KC_W:
                    case KC_V:
                        tap_code(KC_L);
                        return_state = false; // don't do more with this record.
                }
                break;
            case KC_P: // process adaptive key
                switch (prior_keycode) {
                    case KC_B:
                    case KC_K:
                    case KC_V:
                    case KC_W: // if W is in the left-middle column (Gold, some others)
                        tap_code(KC_L); // quickly typing "kv" yields "lv"
                        return_state = false; // don't do more with this record.
                    case KC_F: // "f?" is really uncommon, we prolly want "L?"
                        tap_code(KC_BSPC);
                        tap_code(KC_L);
                        tap_code16(record_keycode);
                        return_state = false; // don't do more with this record.
                }
                break;
            case KC_B: // take advantage of B & V being phonotacically similar
            case KC_V: // to process as adaptive key
                switch (prior_keycode) {
                    case KC_M:
                    case KC_N:
                        tap_code(KC_B); // "v" is likely a "b"
                        return_state = false; // don't do more with this record.
                        break;
                    case KC_P:
                        tap_code(KC_BSPC); // get rid of the KC_P
                        tap_code(KC_L); // quickly typing "p?" yields "l?"
                        tap_code16(record_keycode); //
                        return_state = false; // don't do more with this record.
                        break;
                }
                break;
        }
    }
    prior_keycode = keycode;
    prior_keydown = timer_read(); // (re)start prior timing
    return return_state; //
}
