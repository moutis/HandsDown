/*

 Set keyboard on host to ANSI (not ISO/JIS for now. will eventually invert this.)
 
 */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    bool return_state = true;
    uint8_t  saved_mods;
    

    saved_mods = get_mods(); // preserve mods

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

#ifdef ADAPT_SHIFT  // pseudo-adaptive comma-shift uses 2x ADAPTIVE_TERM, so pre-evaluated
    if (
        (prior_keycode == ADAPT_SHIFT) &&  // is it shift leader?
        !caps_word_timer && // not already doing a caps_word?
        (timer_elapsed(prior_keydown) <= ADAPTIVE_TERM * 4) &&  // use large threshold?
        ((keycode & QK_BASIC_MAX) >= KC_A) &&  // followed by any alpha?
        ((keycode & QK_BASIC_MAX) <= KC_Z)) {
            tap_code(KC_BSPC); // get rid of ADAPT_SHIFT
            tap_code16(S(keycode & QK_BASIC_MAX)); // send cap letter
            preprior_keycode = prior_keydown = linger_key = 0; // reset other states.
            goto AdaptCont; // continue with capped letter as next adaptive leader
        }

#endif

#ifdef ADAPTIVE_ENABLE
    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (record->event.pressed // keyup = not rolling = no adaptive -> return.
        && user_config.AdaptiveKeys // AdaptiveKeys is on
#ifdef JP_MODE_ENABLE
        && IS_ENGLISH_MODE // Adaptives only in primary (Latin) mode
#endif // #ifdef JP_MODE_ENABLE
        ) {

        if (!process_adaptive_key(keycode, record)) {
            preprior_keycode = prior_keycode; // look back 2 keystrokes?
AdaptCont:  // still space constrained on AVR MCUs. This saves 12 bytes.
            prior_keycode = keycode; // this keycode is stripped of mods+taps
            prior_keydown = timer_read(); // (re)start prior_key timing
            return false; // took care of that key
        }
    }
#endif // #ifdef ADAPTIVE_ENABLE
    
    // Do we turn off CAPS_WORD?
    if (caps_word_timer) {
        if (!process_caps_word(keycode, record)) {
            return false; // took care of that key
        }
    }

    // Do we handle a semantic key? Combos or adaptives could have sent one.
    if (!process_semkey(keycode, record)) {
        return false; // took care of that key
    }

    // APP_MENU gets special treatment (no adaptive handling, separate timers)

    if  (keycode == KC_APP) {  // mimic windows app key behavior (only better?) also in scan_matrix
        process_APP_MENU(record);
        return false; // took care of that key
    }
    
    // only process for SHIFT/ALT & no CTRL or GUI mods
    if (saved_mods & MOD_MASK_CG)  // CTRL or GUI/CMD?
        return true; // do default if CTRL or GUI/CMD are down


    if (record->event.pressed) {
//        switch (((keycode >= SAFE_RANGE) && (keycode <= SemKeys_COUNT)) ? (keycode) : (keycode & QK_BASIC_MAX)) { // only handling normal, SHFT or ALT cases.
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
                if (!(saved_mods & MOD_MASK_SHIFT)) // only SHFT? (ALT ok)
                    break; // N: nothing to do
                // shift down with KC_BSPC? (ALT OK)
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                key_trap = KC_DEL;  // mode monitor on to clear this on keyup
                goto goto_register_key_trap_and_return;
            case KC_MINS:  // SHIFT = +
                if (!(saved_mods & MOD_MASK_SHIFT)) // only SHFT? (ALT ok)
                    break; // N: nothing to do
                key_trap = KC_PLUS;  //  enter override state
                goto goto_register_key_trap_and_return;

            case KC_EQL: // SHIFT = _
                if (!(saved_mods & MOD_MASK_SHIFT)) // only SHFT? (ALT ok)
                    break; // N: nothing to do
                key_trap = KC_UNDS;  // enter override state
goto_register_key_trap_and_return: // ##Warning
                register_code16(key_trap);
                return_state = false; // stop processing this record.
                set_mods(saved_mods);  // not sure if we need this
                break;

            case KC_SLSH:  // SHIFT = *, ALT=\, ALT+SHIFT=⁄
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_code16(S(A(KC_1))); // Y:
                    } else {
                        tap_code16(KC_BSLS); // N: just alt, so
                    }
                    return_state = false; // don't do more with this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT?
                    key_trap = KC_ASTR;  // enter override state
                    goto goto_register_key_trap_and_return;
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
                    goto goto_register_key_trap_and_return;
                }
                break;
                
            case KC_LPRN:  // SHIFT = { (linger=(|))
                if (!saved_mods) {
                    goto goto_linger_and_return; // CAUTION: messing w/stack frame here!!
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
                    goto goto_linger_and_return; // CAUTION: messing w/stack frame here!!
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down? (ALT ok)
                    tap_code16(A(KC_COMM)); // ≤ convert to SemKey
                    return_state = false; // stop processing this record.
                }
                break;
            case KC_GT:  // SHIFT = ≥
                if (saved_mods & MOD_MASK_SHIFT) { // SHFT down? (ALT ok)
                    tap_code16(A(KC_DOT)); // ≥ convert to SemKey
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_LBRC:  // linger=[|]
            case KC_LCBR:   // linger={|}
                if (!saved_mods)
                    goto goto_linger_and_return; // CAUTION: messing w/stack frame here!!
                break;

            case KC_SPC:  //
                linger_key = 0;
                break;
            case KC_COMM:  // SHIFT = ;, ALT=_; linger = ", "
                unregister_mods(MOD_MASK_SA); // get rid of shift & alt
                if (saved_mods & MOD_MASK_ALT) { // ALT down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SFT too?
                        tap_code16(A(KC_BSLS)); // "⁄" (convert to SemKey)
                    } else {
                        tap_code16(KC_UNDS);
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_code16(KC_SCLN); // just semicolon
                    return_state = false; // stop processing this record.
                }
                register_linger_key(KC_COMM); // linger to add space
                return_state = false; // stop processing this record.
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
                    tap_code16(S(A(KC_2))); // this should be semkey for €
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
                        tap_SemKey(SK_PARA); // this should be semkey for ¶
                    }
                    return_state = false; // stop processing this record.
                } else if (saved_mods & MOD_MASK_SHIFT) { // only SHFT down
                    tap_SemKey(SK_MDSH); // this should be semkey for — M-Dash
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
                    tap_SemKey(SK_ELPS); // semkey for …
                    return_state = false; // stop processing this record.
                }
                break;

            case KC_DQUO:  // SHIFT = [ (linger=[|]), ALT=«, ALT+SHIFT=‹
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                        if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                            register_linger_key(SK_FSQL); // linger on semkey for ‹
                        } else { // only alt?
                            register_linger_key(SK_FDQL); // linger on semkey for «
                        }
                        return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
                    register_linger_key(KC_LT); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else //{ // no mods, so linger
                    register_linger_key(L_quote); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                break;
                
            case KC_QUOT: // SHIFT = ], ALT=», ALT+SHIFT=›
                clear_keyboard(); // clean record to tinker with.
                if (saved_mods & MOD_MASK_ALT) { // ALT (only) down?
                    if (saved_mods & MOD_MASK_SHIFT) { // SHFT too?
                        tap_SemKey(SK_FSQR); // semkey for ›
                    } else {
                        tap_SemKey(SK_FDQR); // semkey for »
                    }
                    return_state = false; // don't do more with this record.
#ifndef JP_MODE_ENABLE
                } else if (saved_mods & MOD_MASK_SHIFT) { // SHFT (only)?
#else
                } else if (((saved_mods & MOD_MASK_SHIFT) && IS_ENGLISH_MODE)  // SHFT (only)
                           || (!saved_mods && !IS_ENGLISH_MODE)) { // or no mods & not in english
#endif
                    tap_code16(KC_GT); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                } else { // no mods, so
                    register_linger_key(keycode); // example of simple linger macro
                    return_state = false; // don't do more with this record.
                }
                break;

#ifdef JP_MODE_ENABLE
            case KC_C: // C if English, z if Japanese mode
                if (!IS_ENGLISH_MODE) {
                    register_code(KC_Z);
                    return_state = false; // stop processing this record.
                }
                break;
#endif
            case KC_L: // L if English, ん if Japanese mode
            case KC_X: // X if English, - if Japanese mode
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) {
                    switch (keycode) {
                        case KC_L: // L if English, ん if Japanese mode
                            tap_code(KC_N);
                            tap_code(KC_N);
                            return_state = false; // stop processing this record.
                            break;
                        case KC_X: // X if English, - if Japanese mode
                            register_code(KC_MINS);
                            return_state = false; // stop processing this record.
                            break;
                    }
                }
#endif
            case KC_Q:  // Qu, linger deletes U
                if ((saved_mods & MOD_MASK_ALT)
#ifdef JP_MODE_ENABLE
                    || !IS_ENGLISH_MODE
#endif
                    ) // can this linger?
                    break; // N: do default thing
#ifndef KEY_OVERRIDE_ENABLE
goto_linger_and_return: // ##Warning
#endif
                register_linger_key(keycode); // example of simple linger macro
                return_state = false; // stop processing this record.
                break;
                
            case SK_Lux: // switch to linux (or Win if not defined)
#ifdef INCLUDE_HD_Lux
                user_config.OSIndex = OS_Lux; // for Linux Semkeys
//                process_magic(QK_MAGIC_SWAP_CTL_GUI); // tell QMK to swap ctrl/gui
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                return_state = false; // stop processing this record.
                goto storeSettings;
#endif
           case SK_Win: // SINCE MAC IS MY LAYOUT DEFAULT switch to windows
                user_config.OSIndex = OS_Win; // for Windows Semkeys
//                process_magic(QK_MAGIC_SWAP_CTL_GUI); // tell QMK to swap ctrl/gui
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                return_state = false; // stop processing this record.
                goto storeSettings;
            case SK_Mac: // Back to default
                user_config.OSIndex = OS_Mac; // for Mac Semkeys
//                process_magic(QK_MAGIC_UNSWAP_CTL_GUI); // tell QMK to restore ctrl/gui
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
                return_state = false; // stop processing this record.
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


#ifdef RGBLIGHT_ENABLE
            case HD_RGB_sat_up: // Sat +
                rgblight_increase_sat(); // Sat +
                break;
            case HD_RGB_sat_dn: // Sat -
                rgblight_decrease_sat(); // Sat -
                break;
            case HD_RGB_hue_up: // Hue +
                rgblight_increase_hue(); // Hue +
                break;
            case HD_RGB_hue_dn: // Hue +
                rgblight_decrease_hue(); // Hue -
                break;
#endif

        } // switch (keycode) {

#ifdef ADAPTIVE_ENABLE
        prior_keydown = timer_read(); // (re)start prior_key timing
        preprior_keycode = prior_keycode; // look back 2 keystrokes?
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

            case KC_COMM:  //  Comma
            case KC_LT:    //  < (linger=<|>)
            case KC_LPRN:  //  ( (linger=(|))
            case KC_LBRC:  //  [ (linger=[|])
            case KC_LCBR:  //  { (linger={|})
                //if (!saved_mods) { //
//                    unregister_linger_key(); // stop lingering
//                    return_state = false; // stop processing this record.
                //
//                break;

            case SK_FDQL:  // «
            case SK_FSQL:  // ‹
            case KC_BSLS:  // actual keycode for « & »
            case KC_QUOT: // SHIFT = ], ALT=›, ALT+SHIFT=»
            case KC_DQUO: // SHIFT = [ (linger=[|]), ALT=‹, ALT+SHIFT=«
                unregister_linger_key(); // stop any lingering
                //unregister_code16(keycode); // may still need to handle this
                return_state = false; // stop processing this record.
                break;

            case KC_BSPC:  // make S(KC_BSPC) = KC_DEL; plus word_del L & R
/*
                if (!key_trap) // did we override this earlier?
                    break; // N: do normal thing
                unregister_SemKey(key_trap); //
                key_trap = 0;  // exit override state.
                return_state = false; // stop processing this record.
                break;
*/
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


