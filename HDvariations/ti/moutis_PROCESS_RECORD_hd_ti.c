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
            keycode &= QK_BASIC_MAX; // OK, so trim mods & taps
    }


    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (user_config.AdaptiveKeys && IS_ENGLISH_MODE) { // Adaptives only in primary (Latin) mode
        if (!process_adaptive_key(keycode, record)) {  // could do different Adaptives, another day.
            return false; // took care of that key
        }
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
    
    // APP_MENU gets special treatment
    if  (keycode == KC_APP) {  // mimic windows app key behavior (only better?) also in scan_matrix
        if (record->event.pressed) {
            if (saved_mods & (MOD_MASK_CTRL)) {
                unregister_code(KC_RALT);  // ignore these
                unregister_code(KC_RGUI);
                tap_code(KC_TAB);  // switch window w/in app (need semkey for this.)
                return false; // stop processing this record.
            }
            mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
            if (!mods_held) { // gui/alt not down, supply them
                if (user_config.OSIndex) {  // Can't SemKey this bc hold mods & timer...
                    register_code(KC_RALT); // Windows
                } else {
                    register_code(KC_RGUI); // Mac
                }
            }
            tap_code(KC_TAB); // switch app
            state_reset_timer = timer_read(); // (re)start timing hold for keyup below
            return false; // stop processing this record.
        } else {
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
            return false; // stop processing this record.
        }
    }

    // only process for SHIFT/ALT & no CTRL or GUI mods
    if (saved_mods & MOD_MASK_CG)  // CTRL or GUI?
        return true; // do default if CTRL or GUI are down


    if (record->event.pressed) {
        switch (keycode) { // only handling normal, SHFT or ALT cases.

/*
    Key overrides here. use SemKey wherever possible (del_wd?)
*/
#ifndef KEY_OVERRIDE_ENABLE
/*
    QMK KEY_OVERRIDE in 14.1 is much larger than this,
    and can't integrate semkeys or linger keys,
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
                        register_linger_key(KC_LBRC); // this should be semkey for ‹/«?
                    } else { // just SHIFT
                        register_linger_key(KC_LCBR);
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_ALT) { // ALT only?
                    register_linger_key(KC_LBRC);
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_RPRN:  // send } FOR Shift )
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down?
                    if (saved_mods & MOD_MASK_ALT) { // ALT also?
                        tap_code16(KC_RBRC); // SHIFT and ALT
                    } else {
                        tap_code16(KC_RCBR); // only SHIFT
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_ALT) { // only ALT KC_RPRN?
                    tap_code16(KC_RBRC);
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

                // Bronze/Silver/Platinum are reversed
            case KC_QUOT:  // SHIFT = ], ALT=›, ALT+SHIFT=»
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
                            tap_code16(A(S(KC_3)));// this should be semkey for ‹?
#else
                            tap_code16(A(S(KC_4)));// this should be semkey for ›?
#endif
                        } else { // alt & shift?
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
                            tap_code16(A(KC_BSLS));// this should be linger on semkey for «?
#else
                            tap_code16(A(S(KC_BSLS)));// this should be linger on semkey for »?
#endif
                        }
                        return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
                    register_linger_key(RBRC_key); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else //{ // no mods, so linger
                    goto byteshave; // CAUTION: messing w/stack frame here!!
//                    register_linger_key(keycode); // example of simple linger macro
//                    return_state = false; // don't do more with this record.
//                }
                break;
            case KC_DQUO: // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
                        tap_code16(A(S(KC_4)));// this should be semkey for ‹?
#else
                        tap_code16(A(S(KC_3)));// this should be semkey for ›?
#endif
                    } else {
#ifdef HD_BRONZE // for HD_BRONZE/Ag/Si
                        tap_code16(A(S(KC_BSLS)));// this should be linger on semkey for »?
#else
                        tap_code16(A(KC_BSLS));// this should be linger on semkey for «?
#endif
                    }
                    return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
                    register_linger_key(LBRC_key); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else { // no mods, so
byteshave: // CAUTION: messing w/stack frame here!!
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
                break;

#ifdef JP_MODE_ENABLE
            case KC_C: // C if English, z if Japanese mode
            case KC_X: // X if English, - if Japanese mode
            case KC_L: // L if English, K if Japanese mode
            case KC_K: // K if English, L if Japanese mode
                if (!(saved_mods & MOD_MASK_ALT)) {  // allow only SHFT?
                    switch (keycode) {
                        case KC_C: // C if English, z if Japanese mode
                            register_code16(myKC_C);
                            break;
                        case KC_X: // X if English, - if Japanese mode
                            register_code16(myKC_X);
                            break;

                        case KC_L: // L if English, K if Japanese mode
                            register_code16(myKC_L);
                            break;
                        case KC_K: // K if English, L if Japanese mode
                            register_code16(myKC_K);
                            break;


                    }
                    return_state = false; // stop processing this record.
                }
                break;
#endif
            case KC_J:
            case KC_V:
            case KC_Q:  // for linger Qu
            case KC_Z:
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
            case KC_HENK: // Japanese
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = false;
                myKC_L = KC_K;  // keycode for "L"  (could be K if Japanese mode)
                myKC_K = KC_L;  // keycode for "K"  (could be L if Japanese mode)
#ifdef HD_BRONZE
                myKC_C = KC_Z;  // keycode for "C"  ("unused" (used redundantly) in Japanese)
//                myKC_X = KC_DASH;  // keycode for "X"  (could be - if Japanese mode)
#endif
#endif
                tap_SemKey(SK_HENK);
                return_state = false; // stop processing this record.
                break;
            case KC_MHEN: // English
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = true;
                myKC_L = KC_L;  // keycode for "L"  (could be K if Japanese mode)
                myKC_K = KC_K;  // keycode for "K"  (could be L if Japanese mode)
#ifdef HD_BRONZE
                myKC_C = KC_C;  // keycode for "C"  ("unused" (used redundantly) in Japanese)
//                myKC_X = KC_X;  // keycode for "X"  (could be - if Japanese mode)
#endif
#endif
                tap_SemKey(SK_MHEN);
                return_state = false; // stop processing this record.
                break;
            case CG_SWAP: // SINCE MAC IS MY LAYOUT DEFAULT switch to windows
                user_config.OSIndex = 1; // for Windows Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case CG_NORM: // Back to default
                user_config.OSIndex = 0; // for Mac Semkeys
                return_state = true; // let QMK do it's swap thing.
                goto storeSettings;
            case HD_AdaptKeyToggle: // toggle AdaptiveKeys (& LingerKeys, linger combos)
                user_config.AdaptiveKeys = !user_config.AdaptiveKeys;
                return_state = false; // stop processing this record.
                goto storeSettings;
            case HD_L_Bronze: // are we changing default layers?
//            case HD_L_Silver: // are we changing default layers?
//            case HD_L_Platinum: // are we changing default layers?
                user_config.LBRC_key = KC_LBRC;  // swap keycode for "["
                user_config.RBRC_key = KC_RBRC;  // swap keycode for "]"
                user_config.AdaptiveKeys = true;
                goto setLayer;
//            case HD_L_Neu: // are we changing default layers?
//            case HD_L_Titanium: // are we changing default layers?
//            case HD_L_Rhodium: // are we changing default layers?
            case HD_L_Gold: // are we changing default layers?
                user_config.LBRC_key = KC_RBRC;  // swap keycode for "]"
                user_config.RBRC_key = KC_LBRC;  // swap keycode for "["
                user_config.AdaptiveKeys = true;
                goto setLayer;
            case HD_L_QWERTY: // are we changing default layers?
                user_config.AdaptiveKeys = false; // no adaptive keys on QWERTY
setLayer:
                return_state = false; // don't do more with this record.
                set_single_persistent_default_layer(keycode-HD_L_Bronze);// Remember default layer after powerdown
storeSettings:
                eeconfig_update_user(user_config.raw); // Remember platform after powerdown
                break;

#endif // KEY_OVERRIDE_ENABLE
        } // switch (keycode) {

        prior_keydown = timer_read(); // (re)start prior_key timing

    } else { // key up event
        switch (keycode) { // clean up on keyup.

#ifdef JP_MODE_ENABLE
            case KC_C: // C if English, Z if Japanese  (won't sync w/host)
            case KC_X: // X if English, Z if Japanese
            case KC_L: // L if English, K if Japanese mode
            case KC_K: // K if English, L if Japanese mode
                if (!saved_mods || (saved_mods & MOD_MASK_SHIFT)) { // only shift allowed
                    switch (keycode) {
                        case KC_C: // C if English, z if Japanese mode
                            unregister_code16(myKC_C);
                            break;
                        case KC_X: // X if English, - if Japanese mode
                            unregister_code16(myKC_X);
                            break;

                        case KC_L: // L if English, K if Japanese mode
                            unregister_code16(myKC_L);
                            break;
                        case KC_K: // K if English, L if Japanese mode
                            unregister_code16(myKC_K);
                            break;

                    }
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
                if (!saved_mods) {
                    unregister_linger_key(); // stop lingering
                    return_state = false; // stop processing this record.
                }
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
        } // end key up event

    } // end switch (keycode) {
    prior_keycode = keycode; // this keycode is stripped of mods+taps

    return return_state;  // keep processing record
}


