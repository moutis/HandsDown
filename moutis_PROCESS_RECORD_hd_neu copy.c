/*
 
 This is compatible with Hands Down Platinum (neu-lx), Silver (neu-nx), Bronze (neu-hx)
 May not play nice with Hands Down Neu & Gold (neu-tx) (shift '&" for [&] are backwards)
 
 Set keyboard on host to ANSI (not ISO/JIS for now. will eventually invert this.)
 
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool return_state = true;
    uint8_t  saved_mods;

    saved_mods = get_mods(); // preserve mods
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#ifdef TAP_DANCE_ENABLE
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
#endif
            if (record->tap.count == 0) // if not tapped yet…
                return true; // let QMK do that first
            keycode &= QK_BASIC_MAX; // trim mods & taps
    }

    // Do we turn off CAPS_WORD?
    if (caps_word_on) {
        if (!process_caps_word((keycode & QK_BASIC_MAX), record)) {
            return false; // took care of that key
        }
    }

    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (user_config.AdaptiveKeys) {
        if (!process_adaptive_key(keycode, record)) {
            return false; // took care of that key
        }
    }
 
    // Do we handle a semantic key? Combos or adaptives could have sent one.
    if (!process_semkey(keycode, record)) {
        return false; // took care of that key
    }

    if (record->event.pressed) {
        switch (keycode) {
            case KC_APP:  // mimic windows app key behavior (only better?) also in scan_matrix
                mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
                if (!mods_held) { // gui/alt not down, supply them
                    if (user_config.OSIndex) {  // Can't SemKey this bc hold mods & timer...
                        register_code(KC_RALT); // Windows
                    } else {
                        register_code(KC_RGUI); // Mac
                    }
                }
                tap_code(KC_TAB);
                state_reset_timer = timer_read(); // (re)start timing hold for keyup below
                return_state = false; // don't do more with this record.
                break;

            case KC_C: // C if English, K if Japanese mode
                if (!saved_mods || (saved_mods & MOD_MASK_SHIFT)) { // only shift allowed
                    register_code16(myKC_C);
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_L: // L if English, R if Japanese mode
                if (!saved_mods || (saved_mods & MOD_MASK_SHIFT)) { // only shift allowed
                    register_code16(myKC_L);
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_Q:  // for linger Qu (ironically, need to handle this direclty w/o the macros.)
                if ((!saved_mods) || (saved_mods & MOD_MASK_SHIFT)) { // can this linger?
                    linger_key =  keycode; // may add "u" in matrix_scan_user
                    linger_timer = state_reset_timer = timer_read(); // start timers threshold
                } // can only linger on no mods or shift
                register_code16(keycode);
                return_state = false; // don't do more with this record.
                break;

            case KC_J:
                if ((saved_mods & MOD_MASK_SHIFT)) { // can this linger?
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
                }
                break;
                /*
                 Key overrides here. use SemKey wherever possible (del_wd?)
                */
#ifndef KEY_OVERRIDE_ENABLE
                /*
                 QMK KEY_OVERRIDE in 14.1 doesn't release mods on time,
                 it is also much larger, and can't integrate semkeys or linger keys,
                 so for now I roll my own here.
                */

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
                // This logic feels kludgey (but it works).  fix it.
                if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_BSPC?
                    clear_keyboard(); // clean record to tinker with.
                    register_code16(KC_DEL);
                    key_trap = true;  // mode monitor on to clear this on keyup
                    return_state = false; // don't do more with this record.
                    set_mods(saved_mods);
                }
                break;

            case KC_LPRN:  // SHIFT = { (linger=(|))
                if (!saved_mods) {
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_ALT)) { // shft & alt?
                        register_linger_key(KC_LBRC); // this should be semkey for ‹/«?
                    } else { // just shft
                        register_linger_key(KC_LCBR);
                    }
                    return_state = false; // don't do more with this record.
                } else if ((saved_mods & MOD_MASK_ALT)) { // alt no shft?
                    clear_keyboard(); // clean record to tinker with.
                    register_linger_key(KC_LBRC);
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_RPRN:  // send } FOR Shift )
                if ((saved_mods & MOD_MASK_SHIFT)) { // shift down with KC_RPRN?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_ALT)) { // alt also?
                        tap_code16(KC_RBRC);
                    } else {
                        tap_code16(KC_RCBR);
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if ((saved_mods & MOD_MASK_ALT)) { // alt down with KC_RPRN?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_RBRC);
                        return_state = false; // don't do more with this record.
                    }
                }
                break;

            case KC_LT:  //  linger=<|>
                if (!saved_mods) {
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
                } else  {// SHIFT = ≤,
                    if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_LT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(A(KC_COMM)); // convert to SemKey
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_GT:  // SHIFT = ≥,
                if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_GT?
                    clear_keyboard(); // clean record to tinker with.
                    tap_code16(A(KC_DOT)); // convert to SemKey
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_LBRC:  // linger=(|)
            case KC_LCBR:   // linger={|}
                if (!saved_mods) //{
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
//                }
                break;

            case KC_COMM:  // SHIFT = ;, ALT=_,
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SFT too?
                        tap_code16(A(KC_BSLS)); // convert to SemKey
                    } else {
                        tap_code16(KC_UNDS);
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_SCLN); // just semicolon
                        return_state = false; // don't do more with this record.
                    }
                }
                break;
            case KC_DOT:  // SHIFT = :, ALT=…, ALT+SHIFT= \ backslash
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    clear_keyboard(); // clean record to tinker with.
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                        tap_code16(KC_BSLS);
                    } else {
                        tap_code16(A(KC_SCLN));  // convert to SemKey
                    }
                    return_state = false; // don't do more with this record.
                } else {
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_COLN);
                        return_state = false; // don't do more with this record.
                    }
                }
                break;

            case KC_QUOT:  // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
                if (saved_mods) { // any mods?
                    if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        clear_keyboard(); // clean record to tinker with.
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                            tap_code16(A(KC_BSLS));// this should be linger on semkey for ‹?
                        } else { // alt & shift?
                            tap_code16(A(S(KC_3)));// this should be linger on semkey for «?
                        }
                        return_state = false; // don't do more with this record.
                    } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only) down?
                        clear_keyboard(); // clean record to tinker with.
                        register_linger_key((uint16_t)user_config.LBRC_key); // example of simple linger macro
                        return_state = false; // don't do more with this record.
                    }
                } else //{ // no mods, so linger
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
//                }
                break;
            case KC_DQUO:  // SHIFT = ], ALT=›, ALT+SHIFT=»
                if (saved_mods) { // any mods?
                    if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        clear_keyboard(); // clean record to tinker with.
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                            tap_code16(A(S(KC_BSLS)));// this should be semkey for ›?
                        } else {
                            tap_code16(A(S(KC_4)));// this should be semkey for »?
                        }
                        return_state = false; // don't do more with this record.
                    } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT?
                        clear_keyboard(); // clean record to tinker with.
                        register_linger_key((uint16_t)user_config.RBRC_key); // example of simple linger macro
                        return_state = false; // don't do more with this record.
                    }
                } else { // no mods, so
byteshave: // CAUTION: messing w/stack frame here!!
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_EXLM: // SHFT ! = @
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT ! = ?
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1?)
                    tap_code16(KC_DLR);
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_QUES: // ALT ? = ¿ (should be SemKey?)
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT ? = ~
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1?)
                    tap_code16(KC_TILD);
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_ALT) { // ALT ? = ¿ (should be SemKey)
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1?)
                    tap_code16(S(A(KC_SLSH)));
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_MINS:  // SHIFT = +, ALT=–(n-dash), ALT+SHIFT=±
                if (saved_mods & MOD_MASK_SHIFT) { // shift down?
                    del_mods(MOD_MASK_CG); // turn off unused mods (timing off in 14.1)
                    register_code16(KC_PLUS);
                    key_trap = true;  // mode monitor – enter state
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_EQL: // SHIFT = _
                if (saved_mods & MOD_MASK_SHIFT) { // only SHFT?
                    del_mods(MOD_MASK_CAG); // turn off unused mods.
                    register_code16(S(KC_MINS)); // Y: so _
                    key_trap = true;  // mode monitor – enter state
                   return_state = false; // don't do more with this record.
                }
                break;
            case KC_SCLN:  // SHIFT = ;, ALT=_,
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if ((saved_mods & MOD_MASK_SHIFT)) { // SHFT too?
                        del_mods(MOD_MASK_CAG); // turn off unused mods.
                        tap_code16(KC_PERC); // %
                    } else {
                        tap_SemKey(SK_SECT); // §
                    }
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_COLN:  // SHIFT = %
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down?
                    del_mods(MOD_MASK_CAG); // turn off unused mods.
                    tap_code16(KC_PERC); // %
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(A(S(KC_1))); // Y:
                    } else {
                        clear_keyboard(); // clean record to tinker with.
                        tap_code16(KC_BSLS); // N: just alt, so
                    }
                    return_state = false; // don't do more with this record.
               } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT?
                    register_code16(KC_ASTR); // *
                    key_trap = true;  // mode monitor – enter state
                    return_state = false; // don't do more with this record.
               }

                break;
            case KC_HASH:  // SHIFT = @, ALT= , ALT+SHIFT=
                if (saved_mods & MOD_MASK_SHIFT) { // shift down?
                    register_code16(KC_AT); // this is already shifted…
                    key_trap = true;  // mode monitor – enter state
                } else {
                    register_code16(KC_HASH); // this is shifted too…
                }
                return_state = false; // don't do more with this record.
                break;
            case KC_HENK: // Japanese
                myKC_C = KC_Z;
                myKC_L = KC_K;
                tap_SemKey(SK_HENK);
                return_state = false; // don't do more with this record.
                break;
            case KC_MHEN: // English
                myKC_C = KC_C;
                myKC_L = KC_L;
                tap_SemKey(SK_MHEN);
                return_state = false; // don't do more with this record.
                break;
            case CG_SWAP: // SINCE MAC IS MY LAYOUT DEFAULT switch to windows
                user_config.OSIndex = 1; // for Windows Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case CG_NORM: // Back to default
                user_config.OSIndex = 0; // for Mac Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case HD_AdaptKeyToggle: // toggle AdaptiveKeys (and LingerKeys)
                user_config.AdaptiveKeys = !user_config.AdaptiveKeys;
                return_state = false; // don't do more with this record.
                goto storeSettings;
            case HD_L_Bronze: // are we changing default layers?
                user_config.LBRC_key = KC_LBRC;  // swap keycode for "["
                user_config.RBRC_key = KC_RBRC;  // swap keycode for "]"
                user_config.AdaptiveKeys = true;
                goto setLayer;
            case HD_L_Gold: // are we changing default layers?
                user_config.LBRC_key = KC_RBRC;  // swap keycode for "["
                user_config.RBRC_key = KC_LBRC;  // swap keycode for "]"
                user_config.AdaptiveKeys = true;
                goto setLayer;
            case HD_L_QWERTY: // are we changing default layers?
                user_config.AdaptiveKeys = false; // no adaptive keys on QWERTY
setLayer:
                return_state = false; // don't do more with this record.
                //layer_on(keycode-HD_L_Bronze);
                set_single_persistent_default_layer(keycode-HD_L_Bronze);// Remember default layer after powerdown
storeSettings:
                eeconfig_update_user(user_config.raw); // Remember platform after powerdown
                break;

#endif // KEY_OVERRIDE_ENABLE
        } // switch (keycode) {
/*
 
 */
    } else { // key up event
        switch (keycode) { // should switch off record_keycode?

            case KC_C: // C if English, K if Japanese
                if (!saved_mods || (saved_mods & MOD_MASK_SHIFT)) { // only shift allowed
                    unregister_code16(myKC_C);
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_L: // L if English, R if Japanese (may have probs syncing w/OS)
                if (!saved_mods || (saved_mods & MOD_MASK_SHIFT)) { // only shift allowed
                    unregister_code16(myKC_L);
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_APP:  // mimic windows app key behavior (only better?)
                if (!mods_held) {// just app key, so see if held for menu
                    if (!appmenu_on) {// menu not already up
                        if (timer_elapsed(state_reset_timer) > LINGER_TIME) { // held for menu?
                            appmenu_on = true; // turn on menu (taken down in matrix_scan_user)
                            state_reset_timer = timer_read(); // start timer
                        } else { // no, just a quick tap for app switch.
                            if (user_config.OSIndex) { // let mod keys up now
                                unregister_code(KC_RALT);
                            } else {
                                unregister_code(KC_RGUI);
                            }
                            state_reset_timer = 0;  // stop the timer            
                        }
                    }
                }
                return_state = false; // don't do more with this record.
                break;
            case KC_J:  // SHIFT = ( (linger=(|))
            case KC_Q:  // for linger Qu (ironically, need to handle this direclty w/o the macros.)
                unregister_code16(keycode);
                linger_key = 0; // make sure nothing lingers
                return_state = false; // don't do more with this record.
                break;

#ifndef KEY_OVERRIDE_ENABLE
/*
     QMK KEY_OVERRIDE in 14.1 doesn't release mods on time,
     it is also much larger, and can't integrate semkeys or linger keys,
     so for now I roll my own here.
*/

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_DEL); // make sure KC_DEL isn't held down
                    key_trap = false;  // mode monitor off.
                    return_state = false; // don't do more with this record.
                }
                break;
            case KC_LT:  //  { (linger=<|>)
            case KC_LPRN:  //  { (linger=(|))
            case KC_LBRC:  //  ( (linger=[|])
            case KC_LCBR:  //  { (linger={|})
                if (!saved_mods) {
                    unregister_linger_key(); // stop lingering
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_DQUO:  // SHIFT = ], ALT=›, ALT+SHIFT=»
            case KC_QUOT:  // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
                unregister_linger_key(); // stop lingering
                unregister_code16(keycode); // may still need to handle this
                return_state = false; // don't do more with this record.
                break;

            case KC_MINS:  // SHIFT = +, ALT=–(n-dash), ALT+SHIFT=±
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_PLUS); //
                    key_trap = false;  // mode monitor – exit state.
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_EQL:  // ALT _
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(S(KC_MINS)); //
                    key_trap = false;  // mode monitor – exit state.
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_ASTR); // *
                    key_trap = false;  // mode monitor – exit state.
                    return_state = false; // don't do more with this record.
                }
                break;

            case KC_HASH:  // SHIFT = @, ALT= , ALT+SHIFT=
                if (key_trap) { // did we snag this earlier?
                    unregister_code16(KC_AT); //
                    key_trap = false;  // mode monitor – exit state.
                } else {
                    unregister_code16(KC_HASH);
                }
                return_state = false; // don't do more with this record.
                break;

#endif // KEY_OVERRIDE_ENABLE
        } // end key up event

    } // end switch (keycode) {
//    if (!return_state) set_mods(saved_mods); // unnecessary? (false will dump state anyway)?
    return return_state;  // keep processing record
}


