/*
 Combos

 Tailored for Hands Down Neu related variations
 Others have been removed, but I'll try to get everything in here soon enough.
 Finally getting to the last of imagined features that spurred Hands Down design!
  
 */

uint16_t COMBO_LEN = COMBO_LENGTH;

void process_combo_event(uint16_t combo_index, bool pressed) {

#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, combo_OLED_row);
#endif
    if (pressed) {
#ifdef OLED_DRIVER_ENABLE
        oled_write_P(PSTR("Combo: "), false);
#endif
#ifdef JP_MODE_ENABLE
        // Don't process these
        if (IS_ENGLISH_MODE
#ifdef JP_YOUON_COMBOS
            && (combo_index >= jp_kya)
#ifdef JP_YOUON_COMBOS_ALL
            && (combo_index <= jp_ryo)
#else
            && (combo_index <= jp_pyo)
#endif  // JP_YOUON_COMBOS_ALL
#endif  // JP_YOUON_COMBOS
            )
            return;
#endif // JP_MODE_ENABLE

#ifdef ADAPT_SHIFT
        // pseudo-adaptive comma-shift uses 2x ADAPTIVE_TERM, so pre-evaluated
        if (
            (prior_keycode == ADAPT_SHIFT)  // is it shift leader?
//            && ((timer_elapsed(prior_keydown) <= ADAPTIVE_TERM*2))  // within threshold?
//            && ((combo_index >= HC_Q) && (combo_index <= HC_AE)) // followed by alpha combo?
//            && ((combo_index >= HC_Th) && (combo_index <= HC_their_5gram)) // followed by alpha combo?
            )
        {
            tap_code(KC_BSPC);          // get rid of the ADAPT_SHIFT
            register_code16(KC_LSFT);  // This will unregister in matrix_scan_user_process_combo
            prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        }
#endif

        switch(combo_index) {
            case PC_STAB ... COMBO_LENGTH:// these may have a hold delay BEFORE triggering
            case HC_AT ... HC_COLN: //
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

                
//            case HC_CAPG: // turn on capsword for Gold
            case HC_CAPW: // turn on capsword (automatically turns off on delimiter)
                toggle_caps_word();
                break;

            case HC_Q: //
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                tap_code16(KC_Q); //
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code16(KC_U); //
                combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
                break;
                
/*
 * H digraphs here
 */
            case HC_Th: // on first press
                tap_code(KC_T); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Sh:
                tap_code(KC_S); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
           case HC_Wh:
                tap_code(KC_W); // send "W" honoring caps
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // not in English mode?
                    tap_code(KC_O); // send "o" for を (this is more common/convenient?)
                    break;
                }
#endif
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
/* this conflicts with home row tab, so using adaptive CS -> SC
            case HC_Sc: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code(KC_C); // send "C"
                combo_on = combo_index; // if held, addd 'h' for "Sch" in matrix_scan_user_process_combo
                break;
*/
#ifdef EN_HDIGRAPH_COMBOS
            case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
            case HC_Ch: // not held
                tap_code(KC_C); // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Gh: // not held
                tap_code(KC_G); // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Ph:
                tap_code(KC_P); // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
#endif // EN_HDIGRAPH_COMBOS


            case HC_ACUT:
                tap_code16(A(KC_E)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_GRV:
//                tap_code16(A(KC_NUBS)); // this should use semkeys
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_CIRC:
                 tap_code16(A(KC_6)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_MACR:
                tap_code16(A(KC_A)); // this should use semkeys
                combo_on = combo_index; // may add "o" in matrix_scan_user_process_combo
                break;
            case HC_DIER:
                tap_code16(A(KC_U)); // this should use semkeys
                combo_on = combo_index; // may add "u" in matrix_scan_user_process_combo
                break;
            case HC_RING:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) {// in Japanese mode?
                    send_string("hya");// Y: so ひゃ
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(A(KC_K)); // this should use semkeys
                combo_on = combo_index; // may add "a" for å in matrix_scan_user_process_combo
                break;
            case HC_CEDILLE:
                tap_code16(A(KC_C)); // this should use semkeys
                combo_on = combo_index; // may add "c" in matrix_scan_user_process_combo
                break;
            case HC_ENYE:
                tap_code16(A(KC_N)); // this should use semkeys
                combo_on = combo_index; // may add "n" in matrix_scan_user_process_combo
                break;
            case HC_AE: // Æ
                tap_code16(A(KC_QUOT)); // this should use semkeys
                break;
            case HC_OE: // Œ
                tap_code16(A(KC_Q)); // this should use semkeys
                tap_code16(KC_U); // almost always "œu"
                combo_on = combo_index; // but like qu, we'll take it back if we must.
                break;
/*
            case HC_1E: // É
                tap_code16(A(KC_E)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_2E: // È
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_3E: // Ê
                tap_code16(A(KC_6)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_4E: // Ë
                tap_code16(A(KC_U)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_5E: // Ē
                tap_code16(A(KC_A)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_6E: // E̊
                tap_code16(A(KC_K)); // this should use semkeys
                tap_code16(KC_E); //
                break;
*/
/*
            case HC_OSLSH:
                tap_code16(A(KC_O)); // this should use semkeys
                break;
*/
            case HC_NDSH: // delay action until key-up (outside of delay block)
//                register_code16(A(KC_MINS));  // should be a semkey
                combo_on = combo_index; // hold to replace with m-dash
                break;

#ifdef EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

            case HC_I:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // if in Japanese mode
                    send_string("watasi");  //
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(S(KC_I));
                unregister_mods(MOD_MASK_SHIFT);  //
                combo_on = combo_index; // may add "'ve " if held
                break;
            case HC_Id:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // if in Japanese mode
                    send_string("dhi");  // でぃ
                    break;
                }
#endif // JP_MODE_ENABLE

            case HC_Ill:
            case HC_Im:
            case HC_Iv:
#ifdef JP_MODE_ENABLE
                if (!IS_ENGLISH_MODE) { // if in Japanese mode
                    send_string("watasiga");  //
                    break;
                }
#endif // JP_MODE_ENABLE
                tap_code16(S(KC_I)); // send "I" CAPITALIZED
                unregister_mods(MOD_MASK_SHIFT);  //
                goto addonsuffix;

#ifdef EN_PRONOUN_COMBOS_ALL

// This group all share a suffix, with a goto addonsuffix,
// so keep together 'cause we're messing with stack frames at the end!

            case HC_they_4gram: // "they"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_your_4gram:
                tap_code(KC_Y);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("our");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
#ifdef EN_W_PRONOUNS
            case HC_wed_4gram:
            case HC_well_5gram:
            case HC_were_5gram:
            case HC_weve_5gram:
                tap_code(KC_W); // send "W" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("e"); // send "We" right away
                goto addonsuffix;
#endif // EN_W_PRONOUNS
            case HC_youd_5gram:
            case HC_youll_6gram:
            case HC_youre_6gram:
            case HC_youve_6gram:
                tap_code(KC_Y); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ou"); // send "We're" right away
                goto addonsuffix;
            case HC_theyd_6gram: // TYPE "they'd " #23
            case HC_theyll_7gram:
            case HC_theyre_7gram:
            case HC_theyve_7gram: // "they've"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away

#endif // #ifdef EN_PRONOUN_COMBOS_ALL

addonsuffix: // sharing this saves about 100 bytes on AVR (10 bytes per instance)
                tap_code(KC_QUOT);
                switch (combo_index) { //
                    case HC_Im:
                        SEND_STRING("m ");
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_wed_4gram: // we'd
#endif // EN_W_PRONOUNS
                    case HC_youd_5gram:
//                    case HC_youdg_5gram:
                    case HC_theyd_6gram: // TYPE "they'd " #23
//                    case HC_theydg_6gram: // TYPE "they'd " #23
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Id: // "I'd " …
                        send_string("d");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;


#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_well_5gram: // we'll
#endif // EN_W_PRONOUNS
                    case HC_youll_6gram:
                    case HC_theyll_7gram: // TYPE "they'll " #23
//                    case HC_theyllg_7gram: // TYPE "they'll " #23
#endif //#ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Ill: // "I'll "
                        send_string("ll");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_were_5gram: // we're
#endif // EN_W_PRONOUNS
                    case HC_youre_6gram:
                    case HC_theyre_7gram: // "they're"
                        send_string("re ");
                        break;
#ifdef EN_W_PRONOUNS
                    case HC_weve_5gram: // we've
#endif // EN_W_PRONOUNS
                    case HC_youve_6gram:
                    case HC_theyve_7gram: // "they've"
//                    case HC_theyveg_7gram: // "they've"
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Iv: // "I've " …
                        send_string("ve ");
                        break;
                }
                break;
// END of the common Pronoun suffix group with the goto addonsuffix:

#ifdef EN_PRONOUN_COMBOS_ALL
            case HC_their_5gram: // TYPE "their" #6
                tap_code(KC_T);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("heir");
                combo_on = combo_index; // may add "'s " if held
                break;

            case HC_here_4gram: // TYPE "here" #9
                tap_code(KC_H);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ere");
                combo_on = combo_index; // may add "'s " if held
                break;
#ifdef EN_W_PRONOUNS
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
                tap_code(KC_W);
                goto ADD_HERE;
#endif // EN_W_PRONOUNS
            case HC_there_5gram: // TYPE "there" #7
                tap_code(KC_T);
#ifdef EN_W_PRONOUNS
ADD_HERE:
#endif // EN_W_PRONOUNS
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("here");
                combo_on = combo_index; // may add "'ve " if held
                break;

#endif // EN_PRONOUN_COMBOS_ALL
#endif // EN_PRONOUN_COMBOS
                
#ifdef JP_MODE_ENABLE
        // Don't process these
#ifdef JP_YOUON_COMBOS
            case jp_kya:  // きゃ:
                send_string("kya");  //
                break;
            case jp_kyu:  // きゅ
                send_string("kyu");  //
                break;
            case jp_kyo:  // きょ
                send_string("kyo");  //
                break;
            case jp_sya:  // しゃ
                send_string("sya");  //
                break;
            case jp_syu:  // しゅ
                send_string("syu");  //
                break;
            case jp_sye:  // しぇ
                send_string("sye");  //
                break;
            case jp_syo:  // しょ
                send_string("syo");  //
                break;
            case jp_zya:  // じゃ
                send_string("zya");  //
                break;
            case jp_zyu:  // じょ
                send_string("zyu");  //
                break;
            case jp_zyo:  // じょ
                send_string("zyo");  //
                break;
            case jp_tya:  // ちゃ
                send_string("tya");  //
                break;
            case jp_tyu:  // ちゅ
                send_string("tyu");  //
                break;
            case jp_tye:  // ちぇ
                send_string("tye");  //
                break;
            case jp_tyo:  // ちょ
                send_string("tyo");  //
                break;
            case jp_pya:  // ぴゃ:
                send_string("pya");  //
                break;
            case jp_pyu:  // ぴゅ
                send_string("pyu");  //
                break;
            case jp_pyo:  // ぴょ
                send_string("pyo");  //
                break;

#ifdef JP_YOUON_COMBOS_ALL // JP_YOUON_COMBOS_ALL
/* Unnecessary?
            case ch:  // アー
                send_string("a-");  //
                break;
            case jp_ii:  //　イー
                send_string("i-");  //
                break;
            case jp_uu:  //　ウー
                send_string("u-");  //
                break;
            case jp_ee:  //　エー
                send_string("e-");  //
                break;
            case jp_oo:  //　オー
                send_string("o-");  //
                break;
            case jp_nn:  //　ン
                send_string("nn");  //
                break;
*/

            case jp_gya:  // ぎゃ:
                send_string("gya");  //
                break;
            case jp_gyu:  // ぎゅ
                send_string("gyu");  //
                break;
            case jp_gyo:  // ぎょ
                send_string("gyo");  //
                break;
            case jp_tha:  // てゃ
                send_string("tha");  //
                break;
            case jp_thi:  // てぃ
                send_string("thi");  //
                break;
            case jp_thu:  // てゅ
                send_string("thu");  //
                break;
            case jp_the:  // てぇ
                send_string("the");  //
                break;
            case jp_tho:  // てょ
                send_string("tho");  //
                break;
            case jp_dha:  // でゃ
                send_string("dha");  //
                break;
 #ifndef EN_PRONOUN_COMBOS
           case jp_dhi:  // でぃ
                send_string("dhi");  // /onflicts with I'd pronoun combo, so handle it there.

                break;
#endif
            case jp_dhu:  // でょ
                send_string("dhu");  //
                break;
            case jp_dhe:  // でぇ
                send_string("dhe");  //
                break;
            case jp_dho:  // でょ
                send_string("dho");  //
                break;
            case jp_nya:  // にゃ
                send_string("nya");  //
                break;
            case jp_nyu:  // にょ
                send_string("nyu");  //
                break;
            case jp_nyo:  // ひゅ
                send_string("nyo");  //
                break;
/*
            case jp_hya:  // ひゃ
                send_string("hyu");  // handled with diacritic
                break;
*/
            case jp_hyu:  // ひゅ
                send_string("hyu");  //
                break;
            case jp_hyo:  // ひょ
                send_string("hyo");  //
                break;
            case jp_bya:  // びゃ:
                send_string("bya");  //
                break;
            case jp_byu:  // びゅ
                send_string("byu");  // conflicts, handled in the main section
                break;
            case jp_byo:  // びょ
                send_string("byo");  //
                break;
            case jp_mya:  // みゃ:
                send_string("mya");  //
                break;
            case jp_myu:  // みゅ
                send_string("myu");  //
                break;
            case jp_myo:  // みょ
                send_string("myo");  //
                break;
            case jp_rya:  // りゃ:
                send_string("rya");  //
                break;
            case jp_ryu:  // りゅ
                send_string("ryu");  //
                break;
            case jp_ryo:  // りょ
                send_string("ryo");  //
                break;
#endif // JP_YOUON_COMBOS_ALL
#endif // JP_YOUON_COMBOS
#endif // JP_MODE_ENABLE
                
                
                
        } // end switch (combo_index)
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
        // should GUARD this with return instead
    } else { // end if (pressed) so this is the key up switch, hold threshold NOT met.
#ifdef OLED_DRIVER_ENABLE
        oled_set_cursor(0,combo_OLED_row);
        oled_write_P(PSTR("                     "), false);
#endif
/*
 This is the key up event
*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch?
        // wrapup the combo and send the underlying keys if necessary
        //
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
    oled_write_P(PSTR("abort"), true);
#endif
            switch(combo_index) {
// the H digraphs
#ifdef EN_HDIGRAPH_COMBOS
                case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                case HC_Ch:
                case HC_Th:
                case HC_Sh:
                case HC_Wh:
                case HC_Gh:
                case HC_Ph:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;
#endif // EN_HDIGRAPH_COMBOS

                case HC_FIND:  // Simple Find if not held
                    tap_SemKey(SK_FIND);
                    break;
                case HC_NEW:
                    tap_SemKey(SK_NEW);
                    break;
                case HC_COPY: // not held, so simple copy
                    tap_SemKey(SK_COPY);
                    break;
                case HC_PSTE: // not held, so simple paste
                    tap_SemKey(SK_PSTE);
                    break;
    
                case HC_AT:
                    tap_code16(KC_AT); //
                    break;
                case HC_COLN:
                    tap_code16(KC_COLN); //
                    break;
                case HC_NDSH: // Send N-Dash if not held.
                    tap_code16(A(KC_MINS));  // this should use semkeys
                    break;

                case PC_DASH:
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    break;
                case PC_TILD:
                    tap_code(KC_P1);
                    tap_code(KC_P3);
                    break;
                case PC_ELIP:
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    break;
                case PC_LPRN:
                    tap_code(KC_P4);
                    tap_code(KC_P5);
                    break;
                case PC_RPRN:
                    tap_code(KC_P5);
                    tap_code(KC_P6);
                    break;
                case PC_COLN:
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                    break;
                case PC_PERC:
                    tap_code(KC_P6);
                    tap_code(KC_PPLS);
                    break;
                case PC_JYEN:
                    tap_code(KC_SLSH);
                    tap_code(KC_7);
                    break;
                case PC_DOLR:
                    tap_code(KC_7);
                    tap_code(KC_8);
                    break;
                case PC_CENT:
                    tap_code(KC_7);
                    tap_code(KC_9);
                    break;
                case PC_EURO:
                    tap_code(KC_8);
                    tap_code(KC_9);
                    break;
                                        
                case HC_TYPE_LEFTCOMBO:
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(LeftComboTapE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(LeftComboTapJ); //
                    }
#endif
                    break;
                case HC_TYPE_RIGHTCOMBO:
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(RightComboTapE); // send "Japan" right away
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(RightComboTapJ); // send "Japan" right away
                    }
#endif
                    break;

#ifdef EN_PRONOUN_COMBOS
                case HC_I ... HC_Iv:
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_wed_4gram ... HC_their_5gram:
#endif
#endif
                    tap_code(KC_SPC); // add space after a composed pronoun
                    combo_on = 0;  // done w/these shenanigans
                    break;
                case HC_Q: //
                    unregister_code16(KC_Q); //
                    linger_key = 0;
                    break;
                case HC_EQL: //
                    tap_code16(KC_EQL); // Not held, so…
                    break;

            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
            }  // end switch(combo_index) {
        } // else if (threshold met)
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup
#ifdef OLED_DRIVER_ENABLE
//    oled_render();
#endif
    return;
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user if combo_on

    // These combos are to be held for COMBO_HOLD term before triggering
    // to avoid accidental triggers while fast typing these common rolls (or on home row).
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi on qwerty), so maybe best to avoid them as
    // combos.
    // I've successfully added COMBO_HOLD Home Row combos without difficulty.
    // To use multiple home row mods, just put them down one at a time...works great.
    //
    if (!combo_triggered) {
        // do simple "on" on held actions and then turn on combo state in process_combo_event above,
        // then handle hold actions here,
        // before resolving in keyup event above.
        // if necessary (like releasing the underlying keys, or other cleanup)
        if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on) {
            saved_mods = get_mods();
            clear_mods();
            switch(combo_on) {  // combo_on is global, set in process_combo above


                case HC_FIND: // Held, so find selection (should work with most apps/platforms)
                    tap_SemKey(SK_COPY); // copy the selection
                    tap_SemKey(SK_FIND); // start find
                    tap_SemKey(SK_PSTE); // paste the copy. will find the selection
//                    tap_code(KC_ENT); // register current find
//                    tap_SemKey(SK_FAGN); // now find the next...
                    break;

                case HC_COPY: // held, so cut
                    tap_SemKey(SK_CUT);
                    break;
                case HC_PSTE: // held, so pastematch
                    tap_SemKey(SK_PSTM);
                    break;

#ifdef EN_HDIGRAPH_COMBOS
                case HC_Sh: // if these H digragh combos are held, then send T/SION instead
                case HC_Th: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
                    unregister_mods(MOD_MASK_SHIFT);
                    send_string("ion");
                    break;
                case HC_Gh: // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_T); // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case HC_Sch: //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_W); // add "w" // eliminate SFB schw
                    break;
                case HC_Ch: //
                case HC_Wh: //
                case HC_Ph: //
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_I); // add "i"
                    break;
//                case HC_Sc: //
//                    tap_code(KC_H); // add "h" (for "Sch", since were already on these keys.)
//                    break;
#endif // EN_HDIGRAPH_COMBOS

                case HC_AT:
                    send_string(At_ComboHeld);
                    break;
                case HC_COLN: // held, so …
                    tap_code16(A(KC_SCLN)); // (this could use semkeys)
                    break;
                case HC_OE:
                case HC_Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;
                case HC_EQL:
                    tap_code16(KC_PERC); // Held, so send % (instead of =)
                    break;
                case HC_NDSH: // Held, so send M-Dash (instead of N-Dash).
                    tap_code16(A(S(KC_MINS)));  // this should use semkeys
                    break;

                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT));
                    break;
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case PC_DASH:
                    tap_code16(A(KC_MINS)); // this should use semkeys
                    break;
//                case HC_ELIP:
                case PC_ELIP:
                    tap_code16(A(KC_SCLN)); // this should use semkeys
                    break;
                case PC_EURO:
                    tap_code16(A(S(KC_2))); // this should use semkeys
                    break;
                case PC_CENT:
                    tap_code16(A(KC_4)); // this should use semkeys
                    break;
                case PC_JYEN:
                    tap_code16(A(KC_Y)); // this should use semkeys
                    break;
                case PC_BPND:
                    tap_code16(A(KC_3)); // this should use semkeys
                    break;
                case PC_NEQL:
                    tap_code16(A(KC_EQL)); // this should use semkeys
                    break;
                case PC_DIV:
                    tap_code16(A(KC_SLSH)); // this should use semkeys
                    break;
                case PC_PLMN:
                    tap_code16(A(S(KC_EQL))); // this should use semkeys
                    break;
                case PC_DEG:
                    tap_code16(A(KC_0)); // this should use semkeys
                    break;


// PRONOUN shenanigans
#ifdef EN_PRONOUN_COMBOS
#ifdef EN_PRONOUN_COMBOS_ALL

                case HC_here_4gram:
                case HC_there_5gram: // TYPE "there's" #7
                case HC_where_5gram: //

                case HC_your_4gram: // TYPE "your's"
                case HC_their_5gram: // TYPE "their's" #6

                    tap_code(KC_QUOT);
#endif // EN_PRONOUN_COMBOS_ALL
                    SEND_STRING("s ");
                    break;

//                case HC_ould_4gram: // TYPE "ould " #11
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_they_4gram: // TYPE "they " #23
                case HC_theyd_6gram: // TYPE "they'd " #23
                case HC_theyll_7gram: // TYPE "they'll " #23
                case HC_wed_4gram:
                case HC_well_5gram:
                case HC_youd_5gram:
                case HC_youll_6gram:
#endif // EN_PRONOUN_COMBOS_ALL
                case HC_I:
                case HC_Id:
                case HC_Ill:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    send_string("'ve "); // or should it be "'nt"?
                    break;
#endif // EN_PRONOUN_COMBOS

// END PRONOUN shenanigans

    // if lingered, these will followup with the most common composed letter (Latinate language mashup stats)
                case HC_ACUT:
                case HC_GRV:
                case HC_CIRC:
                    tap_code16(KC_E); // this should use semkeys? éêè
                    break;
                case HC_MACR:
                    tap_code16(KC_O); // this should use semkeys? ō
                    break;
                case HC_DIER:
                    tap_code16(KC_U); // this should use semkeys? ü
                    break;
                case HC_RING:
                    tap_code16(KC_A); // this should use semkeys? å
                    break;
                case HC_CEDILLE:
                    tap_code16(KC_C); // this should use semkeys? ç
                    break;
                case HC_ENYE:
                    tap_code16(KC_N); // this should use semkeys? ñ
                    break;

                    
                case HC_TYPE_LEFTCOMBO: // already "LeftComboTap" has been sent; if held, undo and send "LeftComboHeld"
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(LeftComboHeldE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(LeftComboHeldJ); //
                    }
#endif
                    break;
                case HC_TYPE_RIGHTCOMBO: // already "RightComboTap" has been sent; if held, add "RightComboHeld"
#ifdef JP_MODE_ENABLE
                    if (IS_ENGLISH_MODE) {
#endif
                        send_string(RightComboHeldE); //
#ifdef JP_MODE_ENABLE
                    } else {
                        send_string(RightComboHeldJ); //
                    }
#endif
                    break;

            } // switch
            set_mods(saved_mods); // Restore mods
            combo_triggered = true;
            #ifdef OLED_DRIVER_ENABLE
                oled_set_cursor(oled_max_chars() - 5, combo_OLED_row);
                oled_write_P(PSTR(" sent"), false);
            #endif
        } //  if (combo_on) {
    }
}
