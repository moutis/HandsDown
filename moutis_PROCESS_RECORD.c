#define ADAPTIVE_TERM COMBO_HOLD

uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    extern uint8_t  saved_mods; // global, so we're not wasting time allocating...
    bool return_state = true;
    
//    static bool shift_held = false;

//
#ifdef LEADER_ENABLE
    extern bool leading;
    if (!leading) {
#endif
        uint16_t record_keycode = keycode;
        // Filter out the actual keycode from MT and LT keys.
        if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
            record_keycode &= 0xFF;  // mask off the tap mods
        }

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
                                appmenu_timer = 0;  // stop the threshold clock			
                            }
                        }
                    }
                }
                break;

            case KC_M: // IF KC_F or KC_G precedes within ADAPTIVE_TERM, then send L to avoid row jump.
                if (record->event.pressed) {
                        if (((prior_keycode == KC_F)||(prior_keycode == KC_G)) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_L); // quickly typing "fm" yields "fl"
                            return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_F: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
            case KC_V: // IF KC_M precedes within ADAPTIVE_TERM, then send B to avoid row jump.
                if (record->event.pressed) {
                        if ((prior_keycode == KC_M) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_B); // quickly typing "fm" yields "fl"
                            return_state = false; // don't do more with this record.
                        }
                }
                break;
            case KC_D: // IF KC_B precedes, then send L bc hand moved out of home block.
                if (record->event.pressed) {
                        if ((prior_keycode == KC_B) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_L); // quickly typing "bd" yields "bl"
                            return_state = false; // don't do more with this record.
                        }
                }
                break;
            case KC_B: // IF KC_C precedes, then send K bc hand moved out of home block.
                if (record->event.pressed) {
                        if ((prior_keycode == KC_C) && (timer_elapsed(prior_keydown) < ADAPTIVE_TERM)) {
                            tap_code(KC_K); // quickly typing "ck" yields "ck"
                            return_state = false; // don't do more with this record.
                        }
                }
                break;

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_BSPC?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        register_code(KC_DEL);
                        set_mods(saved_mods); // restore shift state
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
                break;
            case KC_LPRN:  // send { FOR Shift (
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                            tap_code16(KC_LBRC);
                        } else {
                            tap_code16(KC_LCBR);
                        }
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    } else {
                        if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_LPRN?
                            set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                            tap_code16(KC_LBRC);
                            set_mods(saved_mods); // restore mod state
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                break;
            case KC_RPRN:  // send } FOR Shift )
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key downSS
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                            tap_code16(KC_RBRC);
                        } else {
                            tap_code16(KC_RCBR);
                        }
                        set_mods(saved_mods); // restore mod state
                        return_state = false; // don't do more with this record.
                    } else {
                        if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_RPRN?
                            set_mods(saved_mods & ~MOD_MASK_ALT); // turn off alt
                            tap_code16(KC_RBRC);
                            set_mods(saved_mods); // restore mod state
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                break;
            case KC_LT:  // send ≤ FOR Shift (
                saved_mods = get_mods();
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
                saved_mods = get_mods();
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
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_COMM?
                        set_mods(saved_mods & ~MOD_MASK_SHIFT); // turn off shift
                        register_code16(KC_SCLN);
                        set_mods(saved_mods); // restore shift state
                        key_trap = true;  // mode monitor – enter state
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code(KC_SCLN); // make sure KC_DEL isn't held down
                        key_trap = false;  // mode monitor – exit state.
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_DOT:  // send : FOR SHIFT .
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_DOT?
                        register_code16(KC_COLN);
                        key_trap = true;  // mode monitor – enter state
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code16(KC_COLN); //
                        key_trap = false;  // mode monitor – exit state.
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_QUOT:  //
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            clear_mods(); // turn off ALT
                            tap_code16(A(KC_BSLS));
                            set_mods(saved_mods); // restore shift state
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(S(KC_3)));
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_LBRC);
                            set_mods(saved_mods);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                break;
            case KC_DQUO:  //
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // ALT down?
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                            clear_mods(); // turn off ALT
                            tap_code16(A(S(KC_BSLS)));
                            set_mods(saved_mods); // restore shift state
                            return_state = false; // don't do more with this record.
                        } else {
                            tap_code16(A(S(KC_4)));
                            return_state = false; // don't do more with this record.
                        }
                    } else {
                        if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                            clear_mods();
                            tap_code16(KC_RBRC);
                            set_mods(saved_mods);
                            return_state = false; // don't do more with this record.
                        }
                    }
                }
                break;
            case KC_HASH:  // send @ FOR SHIFT #
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_HASH?
                        register_code16(KC_AT);
                        key_trap = true;  // mode monitor – enter state
                        return_state = false; // don't do more with this record.
                    }
                } else { // key up
                    if (key_trap) { // did we snag this earlier?
                        unregister_code16(KC_AT); //
                        key_trap = false;  // mode monitor – exit state.
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_MINS:  // send + FOR SHIFT - (_)
                saved_mods = get_mods();
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
            case KC_SLSH:  // send ! FOR ALT /(?)
                saved_mods = get_mods();
                // This logic feels kludgey.  fix it.
                if (record->event.pressed) { // key down
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down?
                        clear_mods();
                        tap_code16(S(KC_1));
                        set_mods(saved_mods); // restore shift state
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
/*
            case KC_Q:  // send "qu" if held
                if (record->event.pressed) {
                    keyhold_timer = 0;
                    register_code(KC_Q);
                    if (!(saved_mods & (MOD_MASK_GUI + MOD_MASK_ALT + MOD_MASK_CTRL))) { // Only allow shift or caps
                        keyhold_timer = timer_read(); // time held, or since last pressed alone
                        clear_mods();
                        tap_code(KC_U);
                        set_mods(saved_mods);
                    }
                    return false; // handled it
                } else {
                    unregister_code(KC_Q);
                    if (keyhold_timer && ((record_timer - keyhold_timer) > TAPPING_TERM)) {
                        tap_code(KC_BSPC);
                    }
                    keyhold_timer = 0;
                    return false; // handled it
                }
                return true;  // Didn't handle this
                break;
*/
                
    } // switch (record_keycode) {
#ifdef LEADER_ENABLE
        }
#endif
    prior_keycode = record_keycode;
    prior_keydown = timer_read(); // (re)start prior timing
    return return_state;  // keep processing record
}
