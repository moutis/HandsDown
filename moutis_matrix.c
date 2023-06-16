

void matrix_scan_user(void) {

#ifdef COMBO_ENABLE
// Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }
#endif

    if (state_reset_timer) { // is there an active state to check on (caps_word)?

        if (caps_word_on) { // caps_word mode on, (no mods) check if it needs to be cleared
            if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME * 3) {// caps time over?
                disable_caps_word(); // turn off all open states
                state_reset_timer = 0;
            }
        }

//
// quick check in with the APP_MENU process
// This was inline, to avoid the call/return before the test in matrix,
// but doesn't seem to be an issue, even on AVR.
//
        matrix_APP_MENU();

//
// prior register_linger_key(kc) needs to be handled here
//
        if (linger_key && user_config.AdaptiveKeys) { // A linger key is being held down
            if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
                saved_mods = get_mods();
                clear_mods();
                unregister_mods(MOD_MASK_SHIFT);  // second char isn't shifted. CAPSLOCK UNAFFECTED.
                switch(linger_key) { // only one linger_key at a time, obviously
                    case KC_Q: // already "Q" has been sent; if lingered, add "u"
                        tap_code(KC_U);
                        break;

                    case KC_V: // already "V" has been sent; if lingered, add "ivi "
                        if ((saved_mods & MOD_MASK_SHIFT)) {
                            SEND_STRING("ivi");
                        }
                        break;
                    case KC_Z: // already "Z" has been sent; if lingered, add "oe "
                        if ((saved_mods & MOD_MASK_SHIFT)) {
                            SEND_STRING("oe");
                        }
                        break;
                    case KC_J: // already "Z" has been sent; if lingered, add "oe "
                        if ((saved_mods & MOD_MASK_SHIFT)) {
                            SEND_STRING("acob");
                        }
                        break;

                    case KC_LPRN: //
                        tap_code16(KC_RPRN);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LBRC: //
                        tap_code16(KC_RBRC);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LCBR: //
                        tap_code16(KC_RCBR);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_LT: //
                        tap_code16(KC_GT);
                        tap_code16(KC_LEFT);
                        break;

                    case KC_QUOT: //
                        tap_code16(KC_BSPC);
                        tap_SemKey(SK_SQUL);
                        tap_SemKey(SK_SQUR);
                        tap_code16(KC_LEFT);
                        break;
                    case KC_DQUO: //
                        tap_code16(KC_BSPC);
                        clear_keyboard();       // QMK doesn't let go of shift here?
                        tap_SemKey(SK_SDQL);
                        tap_SemKey(SK_SDQR);
                        tap_code(KC_LEFT);
                        break;

                    default:
                        break;
                }
                linger_timer = state_reset_timer = 0; // stop lingering
                set_mods(saved_mods); // Restore mods
            }
        }

    }


 }

