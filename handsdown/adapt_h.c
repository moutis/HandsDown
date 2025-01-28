/*
 *  adapt_h.c
 *  the common vowel block adaptives (esp. for "AU" SFB)
 *
 *  included at the end of process_adaptive_key
 */


#ifdef ADAPT_H
/*
 * H is a "Magic" adaptive key, depending on the preceding alphas
 */
       case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!) so adaptive H is a sort of Magic Key
           switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
#if !defined(ADAPT_AE_AU) && !defined(DE_ADAPTIVES) // AU is really common it German (and influences EN/FR)
               case KC_A: // AE is a fraction less common (8x), but the EAE trill may be harder than EAH.
                   tap_code(KC_U); // "AH" yields "AU" (7x more common)
                   return_state = false; // done.
                   break;
#endif // ADAPT_AE_AU or !DE_ADAPTIVES
               case KC_U: //
                    tap_code(KC_A); // "UH" yields "UA" (126x more common)
                   return_state = false; // done.
                   break;
               case KC_E: // these EO/OE adaptives are of questionable value
                   tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                   return_state = false; // done.
                   break;
               case KC_O:
                   tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB?)
                   return_state = false; // done.
                   break;
               case KC_Y:
                   tap_code(KC_I); // "YH" basically never occurs, so turn this SFB into a step
                   return_state = false; // done.
                   break;

#ifndef FR_ADAPTIVES
// these are possible, but rather uncommon
               case KC_L: // LH->LN (4.43    202207313)
               case KC_M: // MH->MN (15.49   232816441)
                   tap_code(KC_N); //
                   return_state = false; // done.
                   break;
               case KC_N: // NH->NL (4.86   1491607169)
                   tap_code(KC_L);
                   return_state = false; // done.
                   break;
#else // FR_ADAPTIVES // eliminate 'h SFB for French
               case KC_D: // ex. d'habitude
               case KC_J: // ex. j'habite
               case KC_L: // ex. l'hôtel
               case KC_N: // ex. n'habite
#ifdef EN_HDIGRAPH_COMBOS
               case KC_T: // t'habitude can't do this (bc Th) unless Th digraph combo is used…
#endif // EN_HDIGRAPH_COMBOS
                   tap_code(KC_QUOT); // YH => Y' (pull down to reduce ring-pinky T-B scissor)
                   break;
#endif // FR_ADAPTIVES
           }
           break;
#endif // ADAPT_H

#if defined(ADAPT_AE_AU) || defined(DE_ADAPTIVES) // AU is really common in German (and influences EN/FR)
       case KC_E:
           switch (prior_keycode) {
               case KC_A: // "AE" yields "AU" (8x more common) keeping it on home row
                   tap_code(KC_U);
                   return_state = false; // done.
           }
           break;
#endif // ADAPT_AE_AU
