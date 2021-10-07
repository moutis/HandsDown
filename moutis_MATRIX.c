

void matrix_scan_user(void) {

#ifdef COMBO_ENABLE
    if (combo_on) { // This will be true only if a combo_action is being held.
        matrix_scan_user_process_combo();
    }
#endif

    if (state_reset_timer) { // is there an active state to check on?

        if (caps_word_on) { // caps_word mode on, (no mods) check if it needs to be cleared
            if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME * 4) {// linger time over?
                disable_caps_word(); // turn off all open states
                state_reset_timer = 0;
            }
        }

        if (appmenu_on) { // App menu up, (no mods) check if it needs to be cleared
            if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME) {// menu up time over?
                if (user_config.osIsWindows) { // Y. stop the menu.
                    unregister_code(KC_RALT);
                } else {
                    unregister_code(KC_RGUI);
                }
                state_reset_timer = mods_held = 0;  // stop the timer            
                appmenu_on = false;
            }
        }

        if (linger_key) { // A linger key is being held down
            if (timer_elapsed(linger_timer) > LINGER_TIME) {
                saved_mods = get_mods();
                clear_mods();
                switch(linger_key) { // only one linger_key at a time, obviously
                    case KC_Q: // already "Q" has been sent; if held, add "u"
                        unregister_code(KC_LSFT); // remove shift here.
                        unregister_code(KC_RSFT); // remove shift here.
                        tap_code(KC_U);
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
                    case KC_DQUO: //
                        tap_code16(KC_DQUO);
                        tap_code16(KC_LEFT);
                        break;
                    default:
                        break;
                }
                linger_timer = state_reset_timer = 0; // finished with this state
                set_mods(saved_mods); // Restore mods
            }
        }

    }


 }

