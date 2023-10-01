/*

 Set keyboard on host to ANSI (not ISO/JIS for now. will eventually invert this.)
 
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool return_state = true;
    uint8_t  saved_mods;
    

    saved_mods = get_mods(); // preserve mods

#ifdef ADAPTIVE_ENABLE
    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (record->event.pressed // keyup = not rolling = no adaptive -> return.
        && user_config.AdaptiveKeys // AdaptiveKeys is on
#ifdef JP_MODE_ENABLE
        && IS_ENGLISH_MODE
#endif // #ifdef JP_MODE_ENABLE
        ) { // Adaptives only in primary (Latin) mode
        if (!process_adaptive_key(&keycode, record)) {
            prior_keydown = timer_read(); // (re)start prior_key timing
            prior_keycode = keycode; // this keycode is stripped of mods+taps
            return false; // took care of that key
        }
    }
#endif // #ifdef ADAPTIVE_ENABLE
    
    // Do we need to filter multi-function keys?
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#ifdef TAP_DANCE_ENABLE
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
#endif
            if (!record->tap.count) // if not tapped yet…
                return true; // let QMK do that first
            keycode &= QK_BASIC_MAX; // mods & taps have been handled.
    }

    // Do we turn off CAPS_WORD?
    if (caps_word_on) {
        if (!process_caps_word(keycode, record)) {
            return false; // took care of that key
        }
    }

    // Do we handle a semantic key? Combos or adaptives could have sent one.
    if (!process_semkey(keycode, record)) {
        return false; // took care of that key
    }

    // APP_MENU gets special treatment (also needs matrix_APP_MENU)

//    if  ((keycode & QK_BASIC_MAX) == KC_APP) {  // mimic windows app key behavior (only better?) also in scan_matrix
    if  (keycode == KC_APP) {  // mimic windows app key behavior (only better?) also in scan_matrix
        process_APP_MENU(record);
        return false; // took care of that key
    }
    
    // only process for SHIFT/ALT & no CTRL or GUI mods
    if (saved_mods & MOD_MASK_CG)  // CTRL or GUI/CMD?
        return true; // do default if CTRL or GUI/CMD are down


    if (record->event.pressed) {
        switch (keycode) { // only handling normal, SHFT or ALT cases.

/*
    Key overrides here. use SemKey wherever possible (del_wd?)
*/
#ifndef KEY_OVERRIDE_ENABLE
/*
    QMK KEY_OVERRIDE can't integrate semkeys or linger keys,
    so for now I roll my own here.
*/

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; ALT = word_del L & R
                if (saved_mods & MOD_MASK_SHIFT) {  // shift down with KC_BSPC? (ALT OK)
                    key_trap = KC_DEL;  // mode monitor on to clear this on keyup
register_key_trap_and_return:
                    register_code16(key_trap);
                    return_state = false; // stop processing this record.
                    set_mods(saved_mods);  // not sure if we need this
                    break;
                }
            case KC_MINS:  // SHIFT = +
                if (!(saved_mods & MOD_MASK_SHIFT)) // only SHFT? (ALT ok)
                    break; // N: nothing to do
                key_trap = KC_PLUS;  //  enter override state
                goto register_key_trap_and_return;

            case KC_EQL: // SHIFT = _
                if (!(saved_mods & MOD_MASK_SHIFT)) // only SHFT? (ALT ok)
                    break; // N: nothing to do
                key_trap = S(KC_MINS);  // enter override state
                goto register_key_trap_and_return;

            case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(A(S(KC_1))); // Y:
                    } else {
                        tap_code16(KC_BSLS); // N: just alt, so
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT?
                    key_trap = KC_ASTR;  // enter override state
                    goto register_key_trap_and_return;
                }
                break;

            case KC_HASH:  // SHIFT = $ ALT=‹ SHIFT_ALT = ›
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                   if (saved_mods & MOD_MASK_SHIFT) { // SFT too?
                        tap_code16(A(KC_4)); // convert to SemKey ¢
                    } else {
                        tap_code16(S(A(KC_SCLN)));
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    key_trap = KC_DLR;  // enter override state
                    goto register_key_trap_and_return;
                }
                break;
                
            case KC_LPRN:  // SHIFT = { (linger=(|))
                if (!saved_mods) {
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // shift down with KC_RPRN?
                    if (saved_mods & MOD_MASK_ALT) { // SHIFT & ALT?
                        register_linger_key(KC_LCBR); // this should be semkey for ‹/«?
                    } else { // just SHIFT
                        unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                        register_linger_key(KC_LBRC); //
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_ALT) { // ALT only?
                    unregister_mods(MOD_MASK_ALT); // get rid of alt
                    register_linger_key(KC_LCBR);
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_RPRN:  // send } FOR Shift )
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down?
                    if (saved_mods & MOD_MASK_ALT) { // ALT also?
                        tap_code16(KC_RCBR); // SHIFT and ALT
                    } else {
                        unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                        tap_code16(KC_RBRC); // only SHIFT
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_ALT) { // only ALT KC_RPRN?
                    unregister_mods(MOD_MASK_ALT); // get rid of alt
                    tap_code16(KC_RCBR);
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_LT:  //  linger=<|>
                if (!saved_mods)
                    goto linger_and_return; // CAUTION: messing w/stack frame here!!
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down? (ALT ok)
                    tap_code16(A(KC_COMM)); // ≤ convert to SemKey
                    return_state = false; // stop processing this record.
                }
                break;
            case KC_GT:  // SHIFT = ≥,
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down? (ALT ok)
                    tap_code16(A(KC_DOT)); // convert to SemKey
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_LBRC:  // linger=[|]
            case KC_LCBR:   // linger={|}
                if (!saved_mods)
                    goto linger_and_return; // CAUTION: messing w/stack frame here!!
                break;

            case KC_COMM:  // SHIFT = ;, ALT=_
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SFT too?
                        tap_code16(A(KC_BSLS)); // convert to SemKey
                    } else {
                        tap_code16(KC_UNDS);
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(KC_SCLN); // just semicolon
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_DOT:  // SHIFT = :, ALT=…, ALT+SHIFT= \ backslash
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(KC_BSLS);
                    } else {
                        tap_code16(A(KC_SCLN));  // convert to SemKey
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down?
                    tap_code16(KC_COLN);
                    return_state = false; // stop processing this record.
                }
                break;


            case KC_EXLM: // SHFT ! = ¡
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(S(KC_4)); // this should be semkey for №
                    } else {
                        tap_code16(A(KC_1)); // ¡
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(A(S(KC_2))); // this should be semkey for €
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_QUES: // ALT ? = ¿ (should be SemKey?)
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(A(KC_Y)); // this should be semkey for ¥
                    } else {
                        tap_code16(S(A(KC_SLSH))); // this should be semkey for ¿
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(A(KC_3)); // this should be semkey for £
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_SCLN:  // SHIFT = , ALT=_,
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_SemKey(SK_SECT); //
                    } else {
                        tap_code16(A(KC_7)); // this should be semkey for ¶
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(S(A(KC_MINS))); // this should be semkey for — M-Dash
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_COLN:  // SHIFT = …
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(S(A(KC_R))); // this should be semkey for ‰
                    } else {
                        tap_code16(KC_PERC); // this should be semkey for %
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(A(KC_SCLN)); // this should be semkey for …
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_QUOT:  // SHIFT = [ (linger=[|]), ALT=«, ALT+SHIFT=‹
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                            tap_code16(SQUO_SA);// this should be semkey for ‹?
                        } else { // alt & shift?
                            tap_code16(SQUO_A);// this should be linger on semkey for «?
                        }
                        return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
//                    register_linger_key(user_config.RBRC_key); // example of simple linger macro
                    register_linger_key(SQUO_S); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else //{ // no mods, so linger
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
//                }
                break;
            case KC_DQUO: // SHIFT = ], ALT=», ALT+SHIFT=›
                
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(DQUO_SA);// this should be semkey for ›?
                    } else {
                        tap_code16(DQUO_A);// this should be linger on semkey for »?
                    }
                    return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
//                    register_linger_key(user_config.RBRC_key); // example of simple linger macro
                    register_linger_key(DQUO_S); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else { // no mods, so
byteshave: // CAUTION: messing w/stack frame here!!
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
                break;

#ifdef JP_MODE_ENABLE
            case KC_L: // L if English, ん if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    tap_code(KC_N);
                    tap_code(KC_N);
                    return_state = false; // stop processing this record.
                }
                break;
            case KC_C: // C if English, z if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    register_code(KC_Z);
                    return_state = false; // stop processing this record.
                }
                break;
           case KC_X: // X if English, - if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    register_code(KC_MINS);
                    return_state = false; // stop processing this record.
                }
                break;
#endif
            case KC_J:  // optional linger
            case KC_V:  // optional linger
            case KC_Q:  // Qu, linger deletes U
            case KC_Z:  // optional linger
                if ((saved_mods & MOD_MASK_ALT)
#ifdef JP_MODE_ENABLE
                    || !IS_ENGLISH_MODE
#endif
                    ) // can this linger?
                    break; // N: do default thing
#ifndef KEY_OVERRIDE_ENABLE
linger_and_return:
#endif
                register_linger_key(keycode); // example of simple linger macro
                return_state = false; // stop processing this record.
                break;
/*
            case KC_LNG1: // Japanese
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = false;
#endif
                tap_SemKey(SK_HENK); // Mac/Win/iOS all different?
                return_state = false; // stop processing this record.
                break;
            case KC_LNG2: // English
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = true;
#endif
                tap_SemKey(SK_MHEN); // Mac/Win/iOS all different?
                return_state = false; // stop processing this record.
                break;
*/
            case CG_SWAP: // SINCE MAC IS MY LAYOUT DEFAULT switch to windows
                user_config.OSIndex = 1; // for Windows Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case CG_NORM: // Back to default
                user_config.OSIndex = 0; // for Mac Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case HD_AdaptKeyToggle: // toggle AdaptiveKeys (& LingerKeys, linger combos)
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = !user_config.AdaptiveKeys;
#endif
                return_state = false; // stop processing this record.
                goto storeSettings;
            case HD_L_QWERTY: // are we changing default layers?
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = false; // no adaptive keys on QWERTY
#endif
                goto setLayer;
            case HD_L_ALPHA:
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = true; // assume adaptive keys on Hands Down
#endif
setLayer:
                return_state = false; // don't do more with this record.
                set_single_persistent_default_layer(keycode-L_BASELAYER);// Remember default layer after powerdown
storeSettings:
                eeconfig_update_user(user_config.raw); // Remember platform variables after powerdown
                break;

#endif // KEY_OVERRIDE_ENABLE
        } // switch (keycode) {

#ifdef ADAPTIVE_ENABLE
        prior_keydown = timer_read(); // (re)start prior_key timing
        prior_keycode = keycode; // this keycode is now stripped of mods+taps
#endif
        
    } else { // key up event
//  when I can get this to work with HRMs properly, this will strictly enforce rolling.
//        if (keycode == prior_keycode) // releasing adaptive?
//            prior_keycode = prior_keydown = 0; // exit Adaptive state
        switch (keycode) { // clean up on keyup.

#ifdef JP_MODE_ENABLE
            case KC_C: // C if English, z if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    unregister_code(KC_Z);
                    return_state = false; // stop processing this record.
                }
                break;
           case KC_X: // X if English, - if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    unregister_code(KC_MINS);
                    return_state = false; // stop processing this record.
                }
                break;
#endif
            case KC_J:  //
            case KC_V:  //
            case KC_Z:  //
            case KC_Q:  // for linger Qu (ironically, need to handle this direclty w/o the macros.)
                unregister_code16(keycode);
                linger_key = 0; // make sure nothing lingers
//                unregister_linger_key();
                return_state = false; // stop processing this record.
                break;

#ifndef KEY_OVERRIDE_ENABLE
/*
    QMK KEY_OVERRIDE in 14.1 is much larger,
    and can't integrate semkeys or linger keys,
    so for now I roll my own here.
*/

            case KC_LT:    //  < (linger=<|>)
            case KC_LPRN:  //  ( (linger=(|))
            case KC_LBRC:  //  [ (linger=[|])
            case KC_LCBR:  //  { (linger={|})
                //if (!saved_mods) { //
                    unregister_linger_key(); // stop lingering
                    return_state = false; // stop processing this record.
                //
                break;

            case KC_DQUO:  // SHIFT = ], ALT=›, ALT+SHIFT=»
            case KC_QUOT:  // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
                unregister_linger_key(); // stop lingering
                unregister_code16(keycode); // may still need to handle this
                return_state = false; // stop processing this record.
                break;

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
            case KC_MINS:  // SHIFT = +, ALT=–(n-dash), ALT+SHIFT=±
            case KC_EQL:   // ALT _
            case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
            case KC_HASH:  // SHIFT = @, ALT= , ALT+SHIFT=
                if (!key_trap) // did we override this earlier?
                    break; // N: do normal thing
                unregister_code16(key_trap); //
                key_trap = 0;  // exit override state.
                return_state = false; // stop processing this record.
                break;

#endif // KEY_OVERRIDE_ENABLE
        } // end switch (keycode) {
    } // end key up event

    return return_state;  // keep processing record
}


