
bool encoder_update_user(uint8_t index, bool clockwise) {
    static  uint8_t  held_mods; // static so we're not reallocating each time.
    
    held_mods = get_mods(); // fetch mods
    // Mod held Global (All layers) behaviors, all encoders
    if (held_mods & MOD_MASK_GUI) { // App switch // not platform saavy!
        if (held_mods & MOD_MASK_CTRL) { // workspace switch
            unregister_mods(MOD_MASK_SAG); // lift all but ctrl
            if (clockwise) {
                tap_code(KC_RIGHT); // fwd
            } else {
                tap_code(KC_LEFT); // back
            }
        }
        if (clockwise) { // Uses SemKey for Platform flexible app switch
            tap_SemKey(SK_APPNXT); // APP switcher Next (last used)
        } else {
            tap_SemKey(SK_APPPRV); // APP switcher Prev (least recently used)
        }
        goto exit;
    }
    if (held_mods & MOD_MASK_CTRL) { // just ctrl switch
        unregister_mods(MOD_MASK_SAG); // lift all but ctrl
        if (clockwise) { // Uses SemKey for Platform flexible app switch
            //tap_code16(C(KC_TAB)); // fwd
            tap_SemKey(SK_WINNXT); // Window/tab switcher Next
        } else {
            //tap_code16(C(S(KC_TAB))); // fwd
            tap_SemKey(SK_WINPRV); // Window/tab switcher Prev
        }
        goto exit;
    }

#ifndef no_enctbl
    static  uint16_t HD_enc[L_count][2][2][2] = { // [layer][L/R encoder][N/Y shift][ccw, cw] * uint16_t = 112 bytes
        // all other encoder actions in this table, most of these defined in the meta keymap file moutis_layers.h
        // currently using the keyboards bottom left and rightmost key defs for L/R encoder actions, as none
        // of my keyboards have both these edge keys and encoders.
        // ALL QMK keycodes work here, and HD extended keycodes, including SemKeys
        //
        //              Left encoder                         Right encoder
        //      Unshifted            Shifted             Unshifted              Shifted
        //       CCW, CW             CCW, CW              CCW, CW               CCW, CW
        {{{KC_VOLD,KC_VOLU}, {KC_BRID,KC_BRIU}}, {{KC_LEFT,KC_RIGHT}, {KC_UP, KC_DOWN}}},    // L_QWERTY, 0 - QWERTY compatibility layer
        {{{KC_VOLD,KC_VOLU}, {KC_BRID,KC_BRIU}}, {{KC_LEFT,KC_RIGHT}, {KC_UP, KC_DOWN}}},    // L_HD,  1 - Hands Down Alpha layer
        {{{LS_LH5,LS_LH4},   {LS_LH4,LS_LH5}},   {{LS_RH4,LS_RH5},    {LS_RH4,LS_RH5}}},    // L_SYM, 2 - symbols, punctuation, off-map alphas
        {{{LF_LH5,LF_LH4},   {LF_LH4,LF_LH5}},   {{LF_RH4,LF_RH5},    {LF_RH4,LF_RH5}}},    // L_FUN, 3 - function & number rows
        {{{LN_LH5,LN_LH4},   {LN_LH4,LN_LH5}},   {{LN_RH4,LN_RH5},    {LN_RH4,LN_RH5}}},    // L_NUM, 4 - numpad (right); navpad (left)
        {{{LV_LH5,LV_LH4},   {LV_LH4,LV_LH5}},   {{LV_RH4,LV_RH5},    {LV_RH4,LV_RH5}}},    // L_NAV, 5 - nav pad (right); meta keys (left)
        {{{LC_LH5,LC_LH4},   {LC_LH4,LC_LH5}},   {{LC_RH5,LC_RH4},    {LC_RH4,LC_RH5}}}     // L_CFG  6 - Media/Consumer controls; Keyboard settings
    };
    unregister_mods(MOD_MASK_SHIFT); // lift Shift, but leave all others (preserves capslock..)
        // look up the keycode to send for this layer, encoder, shift state, direction
    tap_HDkey(HD_enc[(int)get_highest_layer(layer_state)][(int)index][(int)((held_mods & MOD_MASK_SHIFT) ? 1 : 0)][(int)clockwise]);
    
#else // #ifdef no_enctbl
            
        if (!index) { /* First (left) encoder */
            switch(get_highest_layer(layer_state)){
              case L_SYM: // puncuation layer
              case L_FUN:
    volbright:
                  /* for audio scrub bk/fwd. */
                if ((held_mods & MOD_MASK_SHIFT)) {
                    if (clockwise) {
                        tap_code16(KC_BRIU); // Screen BRIGHTNESS UP
                     } else {
                        tap_code16(KC_BRID);  // Screen BRIGHTNESS DN
                    }
                  } else {
                    if (clockwise) {
                        tap_code(KC_VOLU); // media vol up
                    } else {
                        tap_code(KC_VOLD); // media vol dn
                    }
                  }
                  goto exit;
#ifdef L_NUM_SCAN
              case L_NUM: // numpad layer (for navigating in spreadsheets)
                    if (clockwise) {
                      tap_code16(KC_RGHT); //
                  } else {
                      tap_code16(KC_LEFT);  //
                  }
                  break;
#endif
              case L_NAV: // nav layer
                  if (clockwise) {
                      tap_SemKey(SK_ZOOMIN); // ZOOM IN
                  } else {
                      tap_SemKey(SK_ZOOMOUT); // ZOOM OUT
                  }
                  break;

#ifdef RGBLIGHT_ENABLE
              case L_CFG: // media/kbd settings layer
                  if (clockwise) {
                      rgblight_increase_val(); // val (brightness) +
                  } else {
                      rgblight_decrease_val(); // val (brightness) -
                  }
                  break;
#endif
              default:
                    if (clockwise) {
                        tap_code(KC_VOLU); // media vol up
                    } else {
                        tap_code(KC_VOLD); // media vol dn
                    }
                    
            }
      } else  {  // Second (right) encoder
          switch(get_highest_layer(layer_state)){
              case L_SYM: // puncuation layer
                  goto volbright;
              case L_FUN: // function layer
                  /* for audio scrub bk/fwd. */
                  if (clockwise) {
                      tap_code(KC_MNXT); // media next track
                    } else {
                      tap_code(KC_MPRV); // media prev track
                  }
                  break;
              case L_NUM: // numpad layer (for navigating in spreadsheets)
                  if (clockwise) {
                      tap_code16(KC_DOWN);  //
                            } else {
                      tap_code16(KC_UP); //
                  }
                  break;
              case L_NAV: // nav layer
                  if (clockwise) {
                      tap_SemKey(SK_HISTNXT); // prev page
                  } else {
                      tap_SemKey(SK_HISTPRV); // next page
                  }
                  break;

#ifdef RGBLIGHT_ENABLE
              case L_CFG: // media/kbd settings layer
                  if ((held_mods & MOD_MASK_SHIFT)) {
                      if (clockwise) {
                          rgblight_increase_sat(); // Sat +
                      } else {
                          rgblight_decrease_sat(); // Sat -
                      }
                  } else {
                      if (clockwise) {
                          rgblight_increase_hue(); // Hue +
                      } else {
                          rgblight_decrease_hue(); // Hue -
                      }
                  }
                  break;
#endif
              default:
                  if (clockwise) {
                      tap_code(KC_RIGHT); //
                  } else {
                      tap_code(KC_LEFT); //
                  }
                  break;
          }
      }
#endif // #ifdef no_enctbl
exit:
    set_mods(held_mods); // restore mods
    return false;
}

