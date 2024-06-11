//
// called early within process_record_user
// process_APP_MENU handles taps to turn on APP_MENU and cycle.
//
// called early within scan_matrix_user
// matrix_APP_MENU checks/disables the timer.
//
// uses globals:
// uint32_t appmenu_timer = 0; // timer used for app_menu (0 = off)
// uint8_t  saved_mods = 0; //
// bool mods_held = false;  // nood to remember how we entered the appmenu state
//

void process_APP_MENU(keyrecord_t *record) {
// KC_APP key gets special treatment
    uint8_t  saved_mods = get_mods(); // preserve mods

    disable_caps_word(); // turn off CAPS_WORD
    prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
    if (record->event.pressed) {
        if (saved_mods & MOD_MASK_CTRL) { // cycle window w/in app
            unregister_code(KC_RALT);  // ignore these if ctrl
            unregister_code(KC_RGUI);
            tap_code(KC_TAB);
            return; // handled this record.
        }
        mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
        if (!mods_held) { // gui/alt not down, supply them
            if (user_config.OSIndex) {  // Can't SemKey this bc hold mods & timer...
                register_code(KC_RALT); // Win/Lux
            } else {
                register_code(KC_RGUI); // Mac
            }
        }

        if (saved_mods & MOD_MASK_SHIFT)
            tap_code16(RSFT(KC_TAB)); // switch app
        else
            tap_code(KC_TAB); // switch app
        layer_on(L_NAV);
        appmenu_timer = timer_read(); // (re)start timing hold for keyup below
        return; // handled this record.
    }
  // up event
    if (appmenu_on) // mods down, or already on…
        return; // so nothing to do here (matrix_APP_MENU will handle it)
    if (timer_elapsed(appmenu_timer) > LINGER_TIME) { // held long enough?
        appmenu_timer = timer_read(); // Y:start timer (take down in matrix_scan_user)
        appmenu_on = true;
    } else { // N: just a quick tap for app switch.
        if (user_config.OSIndex) { // let mod keys up now
            unregister_code(KC_RALT); // Win/Lux
        } else {
            unregister_code(KC_RGUI); // Mac
        }
        layer_off(L_NAV);
        appmenu_on = false;
        appmenu_timer = 0;  // stop the timer
    }
    return; // handled this record.
}
