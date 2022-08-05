#define ADAPTIVE_TERM COMBO_HOLD

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t  saved_mods;
    bool return_state = true;
    
//    static bool shift_held = false;

//
#ifdef LEADER_ENABLE
    extern bool leading;
    if (!leading) {
#endif
        saved_mods = get_mods();
        return_state = true; //
        uint16_t record_keycode = keycode;
        // Filter out the actual keycode from MT and LT keys.
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
            record_keycode &= 0xFF;  // mask off the tap mods
        }

        // invert this to two switches, one for record->event.pressed and one for not
        // It's faster and smaller that way
        
        
        switch (record_keycode) {
            case KC_APP:  // mimic windows app key behavior (only better?)
                if (record->event.pressed) {
                    mods_held = (get_mods() & MOD_MASK_GUI); // were mods held?
                    if (!mods_held) { // gui/alt not down, supply them
                        if (user_config.osIsWindows) {
                            register_code(KC_LALT);
                        } else {
                            register_code(KC_LGUI);
                        }
                    }
                    appmenu_timer = timer_read(); // (re)start timing hold for keyup below
                    register_code(KC_TAB);
                } else { // key up
                    unregister_code(KC_TAB); //
                    if (!mods_held) {// no mods, so see if held for linger menu
                        if (!appmenu_on) {// menu not already up
                            if (timer_elapsed(appmenu_timer) > (TAPPING_TERM * 1.75)) { // held?
                                appmenu_on = true; // turn on menu.
                                appmenu_timer = timer_read(); // reset (matrix_scan_user will release)
                            } else { // no, just a quick tap for app switch.
                                if (!mods_held) { // let them up to perform the tap
                                    if (user_config.osIsWindows) { // let mod keys up now
                                        unregister_code(KC_LALT);
                                    } else {
                                        unregister_code(KC_LGUI);
                                    }
                                }
                                appmenu_timer = 0;  // stop the threshold clock            
                            }
                        }
                    }
                }
                break;
            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_BSPC?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        register_code(KC_DEL);
                        key_trap = true;  // mode monitor on to clear this on keyup
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code(KC_DEL); // make sure KC_DEL isn't held down
                        unregister_code(KC_BSPC);
                        key_trap = false;  // mode monitor off.
                        return_state = false; // don't do more with this record.
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
                
            case CG_SWAP: // SINCE MAC IS MY DEFAULT switch to windows
                user_config.osIsWindows = true;
                OSIndex = 1;
                eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 3, 0);
                oled_write_P(PSTR("WIN"), false);
#endif // OLED_DRIVER_ENABLE
                break;
            case CG_NORM: // Back to mac
                user_config.osIsWindows = false;
                OSIndex = 0;
                eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 3, 0);
                oled_write_P(PSTR("MAC"), false);
#endif // OLED_DRIVER_ENABLE
                break;

            case KC_B: // process adaptive key
                if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
                    switch (prior_keycode) {
                        case KC_P:
                            tap_code(KC_BSPC); // get rid of the KC_M
                            tap_code(KC_L); // quickly typing "mp" yields "lp"
                            tap_code16(record_keycode); //
                            return_state = false; // don't do more with this record.
                            break;
                        }
                    }
                break;
            case KC_D: // process adaptive key ** This will misbehave w/o Sevanteri's early combos
            case KC_F:
                if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K:
                            tap_code(KC_L);
                            return_state = false; // don't do more with this record.
                            break;
/* this doesn't play well w/o Sevanteri's early combos
                        case KC_M:
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(record_keycode);
                            return_state = false; // don't do more with this record.
                            break;
*/
                            
                    }
                    }
                break;

            case KC_M: // process adaptive key
                if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
                    switch (prior_keycode) {
                        case KC_F:
                        case KC_P:
                        case KC_K:
                        case KC_W:
                        case KC_V:
                            tap_code(KC_L);
                            return_state = false; // don't do more with this record.
                            break;
                        }
                    }
                break;
            case KC_P: // process adaptive key
                if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
                    switch (prior_keycode) {
                        case KC_B:
                        case KC_K:
                        case KC_V:
                        case KC_W:
                            tap_code(KC_L); // quickly typing "kv" yields "lv"
                            return_state = false; // don't do more with this record.
                            break;
                        case KC_F:
                            tap_code(KC_BSPC);
                            tap_code(KC_L);
                            tap_code16(record_keycode);
                            return_state = false; // don't do more with this record.
                            break;
                        }
                    }
                break;
            case KC_V: // process adaptive key
                if (record->event.pressed && ((timer_elapsed(prior_keydown) < ADAPTIVE_TERM))) {
                    switch (prior_keycode) {
                        case KC_M:
                        case KC_N:
                            tap_code(KC_B); // quickly typing "mv" yields "mb"
                            return_state = false; // don't do more with this record.
                            break;
                        case KC_P:
                            tap_code(KC_BSPC); // get rid of the KC_P
                            tap_code(KC_L); // quickly typing "pv" yields "lv"
                            tap_code16(record_keycode); //
                            return_state = false; // don't do more with this record.
                            break;
                        }
                    }
                break;

            case KC_J:  // send Z FOR Alt-J
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_J?
                        set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                        register_code16(KC_Z);
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    }
                } else {
                    unregister_code16(KC_Z);
                }
                break;


            case KC_X:  // send Q FOR Alt-X
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_X?
                        set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                        register_code16(KC_Q);
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    }
                } else {
                    unregister_code16(KC_Q);
                }
                break;

            case KC_LPRN:  // send { FOR Shift (
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                            tap_code16(KC_LBRC);
                        } else {
                            tap_code16(KC_LCBR);
                        }
                        return_state = false; // don't do more with this record.
                    } else {
                        if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_LPRN?
                            set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                            tap_code16(KC_LBRC);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_RPRN:  // send } FOR Shift )
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key downSS
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                            tap_code16(KC_RBRC);
                        } else {
                            tap_code16(KC_RCBR);
                        }
                        return_state = false; // don't do more with this record.
                    } else {
                        if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_RPRN?
                            set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                            tap_code16(KC_RBRC);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_LT:  // send ≤ FOR Shift (
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_LT?
                        clear_mods(); // turn off shift
                        tap_code16(A(KC_COMM));
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_GT:  // send ≥ FOR Alt )
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key downSS
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_GT?
                        clear_mods(); // turn off ALT
                        tap_code16(A(KC_DOT));
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_COMM:  // send ; FOR SHIFT ,
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(A(KC_BSLS));
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(KC_UNDS);
                            return_state = false; // don't do more with this record.
                        }
                        set_mods(saved_mods); // restore shift state
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_SCLN);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_DOT:  // send : FOR SHIFT .
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(KC_BSLS);
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(KC_SCLN));
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_COLN);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_DQUO:  //
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(A(KC_BSLS));
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(S(KC_3)));
                            return_state = false; // don't do more with this record.
                        }
                        set_mods(saved_mods); // restore shift state
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_LBRC);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_QUOT:  //
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(A(S(KC_BSLS)));
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(S(KC_4)));
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_RBRC);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_QUES:  //
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(KC_AT);
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(KC_HASH);
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_EXLM);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_MINS:  // send + FOR SHIFT - (_)
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_HASH?
                        register_code16(KC_PLUS);
                        key_trap = true;  // mode monitor – enter state
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code16(KC_PLUS); //
                        key_trap = false;  // mode monitor – exit state.
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_SLSH:  // send  FOR ALT /(?)
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            clear_mods(); // turn off ALT
                            tap_code16(A(S(KC_1))); //
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_ASTR); // *
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_HASH:  // send
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        clear_mods(); // turn off ALT
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            tap_code16(S(KC_5)); // %
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(KC_5)); // §
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_AT); // @
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
            case KC_PERC:  // % + shft = ‰
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // ALT down?
                        tap_code16(A(S(KC_R))); // ‰
                        return_state = false; // don't do more with this record.
                    }
                }
                if (!return_state) set_mods(saved_mods); // restore shift state
                break;
    } // switch (record_keycode) {
#ifdef LEADER_ENABLE
        }
#endif
    prior_keycode = record_keycode;
    prior_keydown = timer_read(); // (re)start prior timing
    return return_state;  // keep processing record
}
