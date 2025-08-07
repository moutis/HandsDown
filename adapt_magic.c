//
//  adaptive_magic.c
//
//
//  Created by Alan on 1/22/24.
//
//
// embedded in the switch in ive.c
//
//
// first the common non-alpha adaptives for macros (Basically a "Magic" key, like a reverse LeaderKey)
//

case KC_SLSH: // the "MAGIC_SLSH" keys
    if (preprior_keycode == KC_DOT)
        break;
    if (prior_keycode == KC_DOT) { // ./ but not ../
        send_string("com");
        return_state = false; // done.
    }
    break;
case KC_COMM:
    switch (prior_keycode) { // a tap-dance of sorts
        case KC_COMM: // double comma = CAPS_WORD.
            tap_code(KC_BSPC);
            toggle_caps_word();
            return_state = false; // done.
            break;
    }
    break;
case KC_DOT:
    if (preprior_keycode == KC_DOT)
        break;
    switch (prior_keycode) {
        case KC_SLSH: // /. => !
            tap_code(KC_BSPC);
            tap_code16(KC_EXLM);
            return_state = false; // done.
            break;
    }
    break;
case KC_DQUO:
    switch (prior_keycode) {
        case KC_DOT:
            send_string("edu");
            return_state = false; // done.
            break;
        case KC_SLSH: // /" => ?
            tap_code(KC_BSPC);
            tap_code16(KC_QUES);
            return_state = false; // done.
    }
    break;
case KC_QUOT:
     switch (prior_keycode) {
         case KC_DOT:
             send_string("org");
             return_state = false; // done.
             break;
         case KC_SLSH: // roll for ¿
             tap_code(KC_BSPC);
             tap_SemKey(SK_IQUE); //
             return_state = false; // done.
             break;
#ifndef ADAPT_H // alternate way to handle the AU/EO SFBs
         case KC_A: //
             tap_code(KC_U); // "A'" yields "AU"
             return_state = false; // done.
             break;
         case KC_U:
             tap_code(KC_A); // "U'" yields "UA"
             return_state = false; // done.
             break;
         case KC_E:
             tap_code(KC_O); // "E'" yields "EO"
             return_state = false; // done.
             break;
         case KC_O:
             tap_code(KC_E); // "O'" yields "OE"
             return_state = false; // done.
             break;
#endif
     }
     break;

#ifdef HD_MAGIC
case HD_MAGIC:  // default is KC_HASH "#"

    if (preprior_keycode) // allow only 1 deep
    break;
    return_state = false; // presume we do something.
    switch (prior_keycode) {
        case KC_SLSH: // roll for ¡
            tap_code(KC_BSPC);
            tap_SemKey(SK_IEXC); //
            return_state = false; // done.
            break;
    #ifdef A_MAGIC
        case KC_A: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(A_MAGIC);  //
            break;
    #endif
    #ifdef B_MAGIC
        case KC_B: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(B_MAGIC);  //
            break;
    #endif
    #ifdef C_MAGIC
        case KC_C: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(C_MAGIC);  //
            break;
    #endif
    #ifdef D_MAGIC
        case KC_D: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(D_MAGIC);  //
            break;
    #endif
    #ifdef E_MAGIC
        case KC_E: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(E_MAGIC);  //
            break;
    #endif
    #ifdef F_MAGIC
        case KC_F: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(F_MAGIC);  //
            break;
    #endif
    #ifdef G_MAGIC
        case KC_G: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(G_MAGIC);  //
            break;
    #endif
    #ifdef H_MAGIC
        case KC_H: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(H_MAGIC);  //
            break;
    #endif
    #ifdef I_MAGIC
        case KC_I: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(I_MAGIC);  //
            break;
    #endif
    #ifdef J_MAGIC
        case KC_J: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(J_MAGIC);  //
            break;
    #endif
    #ifdef K_MAGIC
        case KC_K: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(K_MAGIC);  //
            break;
    #endif
    #ifdef L_MAGIC
        case KC_L: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(L_MAGIC);  //
            break;
    #endif
    #ifdef M_MAGIC
        case KC_M: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(M_MAGIC);  //
            break;
    #endif
    #ifdef N_MAGIC
        case KC_N: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(N_MAGIC);  //
            break;
    #endif
    #ifdef O_MAGIC
        case KC_O: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(O_MAGIC);  //
            break;
    #endif
    #ifdef P_MAGIC
        case KC_P: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(P_MAGIC);  //
            break;
    #endif
    #ifdef R_MAGIC
        case KC_R: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(R_MAGIC);  //
            break;
    #endif
    #ifdef S_MAGIC
        case KC_S: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(S_MAGIC);  //
            break;
    #endif
    #ifdef T_MAGIC
        case KC_T: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(T_MAGIC);  //
            break;
    #endif
    #ifdef U_MAGIC
        case KC_U: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(U_MAGIC);  //
            break;
    #endif
    #ifdef V_MAGIC
        case KC_V: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(V_MAGIC);  //
            break;
    #endif
    #ifdef W_MAGIC
        case KC_W: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(W_MAGIC);  //
            break;
    #endif
    #ifdef X_MAGIC
        case KC_X: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(X_MAGIC);  //
            break;
    #endif
    #ifdef Y_MAGIC
        case KC_Y: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(Y_MAGIC);  //
            break;
    #endif
    #ifdef Z_MAGIC
        case KC_Z: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(Z_MAGIC);  //
            break;
    #endif
        default: //
            return_state = true; // didn't end up doing anything.
    }
    break;
#endif // HD_MAGIC

#ifdef HD_MAGIC_A
        case HD_MAGIC_A: //
            switch (prior_keycode) {
                case KC_E: //
                    tap_code(KC_O); //
                    return_state = false; // done.
                    break;
                case KC_O: //
                    tap_code(KC_E); //
                    return_state = false; // done.
                    break;
                case KC_A: //
                    tap_code(KC_U);
                    return_state = false; // done.
                    break;
                case KC_U: //
                    tap_code(KC_A); //
                    return_state = false; // done.
                    break;
            }
           break;
#endif // HD_MAGIC_A

#ifdef HD_MAGIC_B
        case HD_MAGIC_B: // for most common double letters (inherently SFBs)
            switch (prior_keycode) {
                case KC_L: // LN eliminate SFB
                case KC_M: // MN eliminate SFB
                    tap_code(KC_N);
                    return_state = false; // done.
                    break;
#ifndef HD_MAGIC_A
                case KC_E: //
                    tap_code(KC_O); //
                    return_state = false; // done.
                    break;
                case KC_O: //
                    tap_code(KC_E); //
                    return_state = false; // done.
                    break;
                case KC_A: //
                    tap_code(KC_U);
                    return_state = false; // done.
                    break;
                case KC_U: //
                    if (preprior_keycode == KC_O) // oux (french)
                        tap_code(KC_X); //
                    else
                        tap_code(KC_A); //
                    return_state = false; // done.
                    break;
#endif
/* double-letter frequencies from Peter Norvig's data <https://norvig.com/mayzner.html>
 * nearly all double consonants are followed by a vowel, and double vowels by a consonant
 * which limits candidates to basically consonant thumb to avoid possible scissoring/SFBs.
 * Each case needs to be vetted.
 */
/*
                case KC_L: // (0.577%) // Hands Down Platinum – not exactly recommended
                case KC_S: // (0.405%)
                case KC_E: // (0.378%) // with cons on thumb, these are problematic
                case KC_O: // (0.210%)
                case KC_T: // (0.171%) // Hands Down Gold
                case KC_F: // (0.146%)
                case KC_P: // (0.137%)
                case KC_R: // (0.121%) // Hands Down Titanium/Rhodium/Vibranium/Promethium
// These aren't frequent enough to bother?
                case KC_M: // (0.096%)
                case KC_C: // (0.083%)
                case KC_N: // (0.073%) // Hands Down Silver
                case KC_D: // (0.043%)
                case KC_G: // (0.025%)
// These are def not frequent enough to bother?
                case KC_I: // (0.023%)
                case KC_B: // (0.011%)
                case KC_A: // (0.003%)
                case KC_Z: // (0.003%)
                case KC_X: // (0.003%)
                case KC_U: // (0.001%)
                case KC_H: // (0.001%)  // Hands Down Bronze
*/
                default: // make it a dumb repeater
                    tap_code(prior_keycode); // eliminate SFB on double
                    return_state = false; // done.
            }
        break;
#endif // HD_MAGIC_B
