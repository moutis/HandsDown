//
//  adaptive_trailer.c
//  
//
//  Created by Alan on 1/22/24.
//
//
// embedded in the switch in adaptive.c
//

// Using Adaptives for macros (like a flexible LeaderKey)
case ADAPTIVE_TRAILER:

    if (preprior_keycode) // allow only 1 deep
    break;
    return_state = false; // presume we do something.
    switch (prior_keycode) {
    #ifdef adaptAHASH
        case KC_A: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptAHASH);  //
            break;
    #endif
    #ifdef adaptBHASH
        case KC_B: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptBHASH);  //
            break;
    #endif
    #ifdef adaptCHASH
        case KC_C: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptCHASH);  //
            break;
    #endif
    #ifdef adaptDHASH
        case KC_D: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptDHASH);  //
            break;
    #endif
    #ifdef adaptEHASH
        case KC_E: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptEHASH);  //
            break;
    #endif
    #ifdef adaptFHASH
        case KC_F: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptFHASH);  //
            break;
    #endif
    #ifdef adaptGHASH
        case KC_G: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptGHASH);  //
            break;
    #endif
    #ifdef adaptHHASH
        case KC_H: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptHHASH);  //
            break;
    #endif
    #ifdef adaptIHASH
        case KC_I: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptIHASH);  //
            break;
    #endif
    #ifdef adaptJHASH
        case KC_J: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptJHASH);  //
            break;
    #endif
    #ifdef adaptKHASH
        case KC_K: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptKHASH);  //
            break;
    #endif
    #ifdef adaptLHASH
        case KC_L: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptLHASH);  //
            break;
    #endif
    #ifdef adaptMHASH
        case KC_M: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptMHASH);  //
            break;
    #endif
    #ifdef adaptNHASH
        case KC_N: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptNHASH);  //
            break;
    #endif
    #ifdef adaptOHASH
        case KC_O: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptOHASH);  //
            break;
    #endif
    #ifdef adaptPHASH
        case KC_P: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptPHASH);  //
            break;
    #endif
    #ifdef adaptRHASH
        case KC_R: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptRHASH);  //
            break;
    #endif
    #ifdef adaptSHASH
        case KC_S: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptSHASH);  //
            break;
    #endif
    #ifdef adaptTHASH
        case KC_T: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptTHASH);  //
            break;
    #endif
    #ifdef adaptUHASH
        case KC_U: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptUHASH);  //
            break;
    #endif
    #ifdef adaptVHASH
        case KC_V: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptVHASH);  //
            break;
    #endif
    #ifdef adaptWHASH
        case KC_W: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptWHASH);  //
            break;
    #endif
    #ifdef adaptXHASH
        case KC_X: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptXHASH);  //
            break;
    #endif
    #ifdef adaptYHASH
        case KC_Y: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptYHASH);  //
            break;
    #endif
    #ifdef adaptZHASH
        case KC_Z: //
            tap_code(KC_BSPC); // and may have been lowercase
            send_string(adaptZHASH);  //
            break;
    #endif
        default: //
            return_state = true; // didn't end up doing anything.
    }
    break;
