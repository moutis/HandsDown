

void matrix_scan_user(void) {

#ifdef COMBO_ENABLE
    if (combo_on) { // Is a combo_action being held?
        matrix_scan_user_process_combo();
    }
#endif

    if (state_reset_timer) { // is there an active state to check on?

        if (caps_word_on) { // caps_word mode on, (no mods) check if it needs to be cleared
            if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME * 3) {// caps time over?
                disable_caps_word(); // turn off all open states
                state_reset_timer = 0;
            }
        }

        if (appmenu_on) { // App menu up, (no mods) check if it needs to be cleared
            if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME) {// menu up time over?
                if (user_config.OSIndex) { // Y. stop the menu.
                    unregister_code(KC_RALT); // Windows
                } else {
                    unregister_code(KC_RGUI); // Mac
                }
                state_reset_timer = mods_held = 0;  // stop the timer            
                appmenu_on = false;
            }
        }

        
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
                        clear_keyboard(); // QMK doesn't let go of shift properly?
                        tap_SemKey(SK_SDQL);
                        tap_SemKey(SK_SDQR);
                        tap_code(KC_LEFT);
                        break;
/*
#ifdef JP_MODE_ENABLE
                   case KC_A: // long 長母音・ん if held in Japanese mode
                   case KC_I: // KC_I won't work with (home row) mod_taps…
                   case KC_U:
                   case KC_E: // KC_E won't work with (home row) mod_taps…
                   case KC_O:
                       if (IS_ENGLISH_MODE) {
                           unregister_linger_key(); // example of simple linger macro
                           tap_code16(KC_MINS);
                       }
                       break;
                    case KC_N: // KC_N won't work with (home row) mod_taps…
                        if (IS_ENGLISH_MODE) {
                            unregister_linger_key(); // example of simple linger macro
                            tap_code16(KC_N);
                        }
#endif
*/

                    default:
                        break;
                }
                linger_timer = state_reset_timer = 0; // stop lingering
                set_mods(saved_mods); // Restore mods
            }
        }

    }


 }

