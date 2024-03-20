

void matrix_scan_user(void) {

#ifdef COMBO_ENABLE
// Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }
#endif

    if (caps_word_timer) { // caps_word mode on?, check if it needs to be cleared
        if (timer_elapsed(caps_word_timer) > STATE_RESET_TIME * 3) {// caps time over?
            disable_caps_word(); // turn off all active states
            return;
        }
    }

//
// quick check in with the APP_MENU process
//
    if (appmenu_on) { // App menu up, (no mods) check if it needs to be cleared
        if (timer_elapsed(appmenu_timer) > STATE_RESET_TIME) {// menu up time elapsed?
            if (user_config.OSIndex) { // Y. stop the menu by lifting the mods
                unregister_code(KC_RALT); // Win
            } else {
                unregister_code(KC_RGUI); // Mac
            }
            layer_off(L_NAV);
            appmenu_on = false;
            appmenu_timer = mods_held = 0; // stop the timer
            return;
        }
    }
        
//
// prior register_linger_key(kc) needs to be handled here
//
    if (linger_key && user_config.AdaptiveKeys) { // A linger key is being held down
        if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
            saved_mods = get_mods();
            clear_mods();
            unregister_mods(MOD_MASK_SHIFT);  // second char isn't shifted. CAPSLOCK UNAFFECTED.
            switch(linger_key) {
                case KC_Q: // already "Q" has been sent; if lingered, add "u"
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
                case KC_LT: //
                    tap_code16(KC_GT);
                    tap_code16(KC_LEFT);
                    break;

                case KC_QUOT: // ‘|’ single paired quotes
                    tap_code16(KC_BSPC);
                    tap_SemKey(SK_SQUL);
                    tap_SemKey(SK_SQUR);
                    tap_code16(KC_LEFT);
                    break;
//                    case SK_SDQU: // make “|” double paired quotes
                case KC_DQUO: //
                    tap_code16(KC_BSPC); // get rid of prior straight dbl quote
                    clear_keyboard();  // QMK doesn't let go of shift here?
                    tap_SemKey(SK_SDQL); // “
                    tap_SemKey(SK_SDQR); // ”
                    tap_code(KC_LEFT);
                    break;
                case SK_FDQL: //  « | » double French quote
                    tap_SemKey(SK_FDQR);
                    goto pushspaceshere;
                case SK_FSQL: //  ‹ | › single French quote
                    tap_SemKey(SK_FSQR);
pushspaceshere:
                    tap_code(KC_LEFT); // break up 2 dble spc
                    tap_code16(KC_SPACE); // to thwart "smart" EOS.
                    tap_code(KC_LEFT);
                    tap_code16(KC_SPACE);
                    //unregister_SemKey(linger_key);
                    break;

                default:
                    break;
            }
            linger_timer = linger_key = 0; // done lingering
            set_mods(saved_mods); // Restore mods
        }
    }
}
