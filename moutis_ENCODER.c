
bool encoder_update_user(uint8_t index, bool clockwise) {
    static  uint8_t  held_mods; // static so we're not reallocating each time.
    
    held_mods = get_mods(); // fetch mods
    //
    // Global behaviors, all encoders, all layers.
    // activated if a mod (Gui/Ctrl) is held.
    //
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

    //
    // all other encoder actions are in this table, most of these defined in the meta keymap file moutis_layers.h
    // Currently using the keyboard's bottom left and rightmost key defs, outside thumb keys,
    // for L/R encoder actions. (I prefer Kyria/Elora's under palm locations, so none of my keyboards
    // that have encoders have these outside thumb row edge keys as well.
    // I still want those functions, so placing them on these outside thumb keys tends
    // to keep them in similar locations on encoderless boards (i.e. Naked 48/60, Planck/Preonic).
    // Any keycode works here: normal QMK and my HD extended keycodes, including SemKeys
    //
    static  uint16_t HD_enc[L_count][2][2][2] = {
        // [layer][L/R encoder][N/Y shift][ccw, cw] * uint16_t = 112 bytes (16 bytes/layer)
        //               Left encoder                              Right encoder
        //      Unshifted            Shifted             Unshifted              Shifted
        //       CCW, CW             CCW, CW              CCW, CW               CCW, CW
        {{{KC_VOLD,KC_VOLU}, {KC_BRID,KC_BRIU}}, {{KC_PGUP, KC_PGDN}, {KC_LEFT,KC_RIGHT}}}, // L_HD,  - Hands Down Alpha layer
        {{{LS_LH5,LS_LH4},   {LS_LH4,LS_LH5}},   {{LS_RH4,LS_RH5},    {LS_RH4,  LS_RH5}}},  // L_SYM, - symbols, punctuation, off-map alphas
        {{{LF_LH5,LF_LH4},   {LF_LH4,LF_LH5}},   {{LF_RH4,LF_RH5},    {LF_RH4,  LF_RH5}}},  // L_FUN, - function & number rows
        {{{LN_LH5,LN_LH4},   {LN_LH4,LN_LH5}},   {{LN_RH4,LN_RH5},    {LN_RH4,  LN_RH5}}},  // L_NUM, - numpad (right); navpad (left)
        {{{LV_LH5,LV_LH4},   {LV_LH4,LV_LH5}},   {{KC_MFFD, KC_MRWD}, {LV_RH4,LV_RH5}}},    // L_NAV, - nav pad (right); meta keys (left)
        {{{LC_LH5,LC_LH4},   {LC_LH4,LC_LH5}},   {{LC_RH5,LC_RH4},    {LC_RH4,  LC_RH5}}}   // L_CFG  - Media/Consumer controls; Keyboard settings
    };
    unregister_mods(MOD_MASK_SHIFT); // lift Shift, but leave all others (preserves capslock..)
        // look up the keycode to send for this layer, encoder, shift state, direction
    tap_HDkey(HD_enc[(int)get_highest_layer(layer_state)][(int)index][(int)((held_mods & MOD_MASK_SHIFT) ? 1 : 0)][(int)clockwise]);
    
exit:
    set_mods(held_mods); // restore mods
    return false;
}

