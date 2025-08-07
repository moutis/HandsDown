/*
 Adaptive Keys
 Called from early within process_record_user
 
 Tailored for HD Promethium (pm)
 
 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).
 
 */
//    Base (alpha) Layer  Hands Down Promethium (HRMs /+ thumb mods)
//      this is canonical Promethium, "inverted" (top-bottom), as
//      I prefer "bottom heavy" layouts.  If you prefer top heavy,
//      be sure to invert all rows, as the rolling/scissoring characteristics
//      that make Promethium what it is depend on the same-row neighbors
//  ※ arguably, the inner column is less sensitive to this.
//            ╭─────────────────────╮                 ╭─────────────────────╮
// LANG1/mhen │  V   W   G   M   J  │ L_CFG     L_NUM │  #$  .:  /*  "[  '] │ LANG2/henk
//    esc     │  S   N   T   H   K  | (             ) |  ,;   A   E   I   C │ Z
//    tab     │  F   P   D   L   X  │ [ copy   pste ] │  -+   U   O   Y   B │ Q(u)
//            ╰───────────╮ bsp  R  │ &             | │ spc  ret ╭──────────╯
//          left rght app ╰─────────╯                 ╰──────────╯ tgLN  up  dn
//
// For small boards, Q (LT3) & Z (LT4) are (also) on the sym layer


bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.
    
    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    if (!caps_word_timer) { // turn off shift, (first-words & Proper nouns)
        unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    } // may want more granular control than this…

//        switch (((keycode >= SAFE_RANGE) && (keycode <= SemKeys_COUNT)) ? (keycode) : (keycode & QK_BASIC_MAX)) { // only handling normal, SHFT or ALT cases.

    switch (keycode) { // process ignoring multi-function keys & shift state?

/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        case KC_D:
            switch (prior_keycode) { //
                case KC_P:  // roll PD = PWD? (no side effects?)
                        tap_code(KC_W);
                        break; // process the D normally
            }
            break;
        case KC_F:
            switch (prior_keycode) {
                case KC_P: // Eliminate PS scissor (worse on less staggered boards)
                    tap_code(KC_S); // PF=PS (PS 36x more common)
                    return_state = false; // done.
            }
            break;
        case KC_G:
            switch (prior_keycode) {
                case KC_K: // eliminate index-middle stretch with alt fingering
                    tap_code(KC_L);  // pull up "L" (KL is 5x more common than KG)
                    return_state = false; // done.
                    break;
               case KC_M: // eliminate scissor
                    if (preprior_keycode == KC_W) { // to roll WMG -> lml? (no side effects?)
                        tap_code(KC_L); // G kecomes L for "LML"
                        return_state = false; // done.
                        break; // and let current keycode send normally
                    }
                    tap_code(KC_BSPC); // replace M
                    tap_code(KC_L); // "pull up" L to eliminate scissor
                    break; // and let current keycode send normally
                case KC_J: // roll JG => jpg free letter!
                    tap_code(KC_P); // insert a P
                    break; // and let current keycode send normally
                case KC_W:
                    tap_code(KC_D); // pull up D (WD is 35x more common than WG)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_H:
            switch (prior_keycode) {
                case KC_K: // to avoid the lat stretch
                    tap_code(KC_N); // KH = KN (KN is 15x more common)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_J:
            switch (prior_keycode) {
                case KC_G: // 99.7% of GT are followed by H
                    send_string("th"); // for "length"
                    return_state = false; // done.
                    break;
                case KC_V: // Eliminate VL Scissor
                case KC_W: // Eliminate WL scissor
                    tap_code(KC_L); // WJ = wl (WL is 468x more common than WJ)
                    return_state = false; // done.
                    break;
            }
            break;

            // remedy ring-index split by shifting fingering
            // Since the hand is already displaced to reach the inner column,
            // pull the L over with alternate fingering to avoid the stretch.
        case KC_K:
            switch (prior_keycode) {
                case KC_M: // eliminate index-middle stretch with alt fingering
                    tap_code(KC_BSPC); // replace M
                    tap_code(KC_L); // MK = LK (LK is 75x more common than GK)
                    break; // Send K normally
                case KC_H: // eliminate lateral stretch
                    tap_code(KC_BSPC); // replace H
                    tap_code(KC_N); // HK = NK (219x more common)
                    break; // Send K normally
            }
            break;

        case KC_L: // catch this so we can unshift L on these involving pinky/ring rolls.
            switch (prior_keycode) {
                case KC_P:
                case KC_B: //
                case KC_S: //
                    tap_code(KC_L);  //
                    return_state = false; // done.
                    break;
            }
            break;

        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // eliminate scissor (GL is 5x more common than GM)
                case KC_V: // eliminate VL scissor ()
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                case KC_W:
                    switch (preprior_keycode) {
                        case KC_M: // eliminate 2r/2c scissor
                            tap_code(KC_L); // WM = LM (LM 20x more common)
                            return_state = false; // done.
                            break;
                        default:
                            tap_code(KC_BSPC);
                            send_string("lm");
                            return_state = false; // done.
                            break;
                   }
            }
            break;
        case KC_P:
            switch (prior_keycode) {
                case KC_F: // eliminate SP scissor
                    tap_code(KC_BSPC); // remove F
                    tap_code(KC_S);  // FP=SP (SP 860x more common)
                    break; // Send P normally
                case KC_P: // eliminate DG sfb
                    tap_code(KC_G);  //
                    return_state = false; // done.
                    break; // 
            }
            break;

        case KC_V:
            switch (prior_keycode) {
                case KC_G: // "GT" is 363x more frequent than "GV"
                    tap_code(KC_T); // eliminate GT SFB.
                    return_state = false; // done.
                    break;
                case KC_M: // eliminate LV scissor.
                    tap_code(KC_BSPC); // replace M
                    tap_code(KC_L); // "LV" is 119x more frequent than "MV"
                    break;
            }
            break;

        case KC_W:
            switch (prior_keycode) {
                case KC_G: // eliminate SFB
                    tap_code(KC_D); // GW = GD (3.8x more common)
                    return_state = false; // done.
                    break;
                case KC_M: // eliminate SFB/scissor
//                    tap_code(KC_N); // MW = MN (14x more common) (if F is on bottom)
                    tap_code(KC_P); // MW = MF (if P is on bottom)
                    return_state = false; // done.
                    break;
            }
            break;



/*
// right hand adaptives
*/
            
        case KC_B:
            switch (prior_keycode) {
                case KC_Y: // avoid ring->pinky scissor
                    tap_code(KC_BSPC);
                    tap_code(KC_I);
                    break; // process the B normally
            }
            break;
// PM doesn't use the common vowel block, so…
//#include "adapt_h.c" // the common vowel block adaptives (esp. for AU SFB)

        case KC_E:
            switch (prior_keycode) {
                case KC_A: // "AE" yields "AU" (8x more common) keeping it on home row
                    tap_code(KC_U);
                    return_state = false; // done.
            }
            break;

#if defined (HD_MAGIC) || defined (HD_MAGIC_A) || defined (HD_MAGIC_B)
#include "adapt_magic.c" // the common adaptive "magic" key
#endif //

    }
    if (return_state)  // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);

    return return_state; //
}
