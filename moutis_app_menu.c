//
// called early within process_record_user
// process_APP_MENU handles taps to turn on APP_MENU and cycle.
//
// called early within scan_matrix_user
// matrix_APP_MENU checks/disables the timer.
//
// uses globals:
// uint32_t state_reset_timer = 0; // timer used for app_menu, adaptives, lingers
// uint8_t  saved_mods = 0; //
// bool appmenu_on = false;  // state of windows-like app switcher
// bool mods_held = false;  // nood to remember how we entered the appmenu state
//

void process_APP_MENU(keyrecord_t *record) {
// KC_APP key gets special treatment
  if (record->event.pressed) {
    if (saved_mods & MOD_MASK_CTRL) { // cycle window w/in app (semkey?)
      unregister_code(KC_RALT);  // ignore these if ctrl
      unregister_code(KC_RGUI);
      tap_code(KC_TAB);
      return; // handled this record.
    }
    mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
    if (!mods_held) { // gui/alt not down, supply them
      if (user_config.OSIndex) {  // Can't SemKey this bc hold mods & timer...
        register_code(KC_RALT); // Windows
      } else {
        register_code(KC_RGUI); // Mac
      }
    }
/*
      if (saved_mods & MOD_MASK_SHIFT)
        tap_code16(S(KC_TAB)); // switch app
    else
*/
    tap_code(KC_TAB); // switch app
    state_reset_timer = timer_read(); // (re)start timing hold for keyup below
    return; // handled this record.
  }
  // up event
  // if (mods_held || appmenu_on) // mods down, or already on…
  if (appmenu_on) // mods down, or already on…
    return; // so nothing to do here (matrix_APP_MENU will handle it)
  if (timer_elapsed(state_reset_timer) > LINGER_TIME) { // held long enough?
    appmenu_on = true; // Y:turn on menu (taken down in matrix_scan_user)
    state_reset_timer = timer_read(); // start timer
  } else { // N: just a quick tap for app switch.
    if (user_config.OSIndex) { // let mod keys up now
      unregister_code(KC_RALT); // Win
    } else {
      unregister_code(KC_RGUI); // Mac
    }
    state_reset_timer = 0;  // stop the timer
  }
  return; // handled this record.
}


//
// somewhere in matrix_scan_user (early?)
//
void matrix_APP_MENU(void) {
    if (appmenu_on) { // App menu up, (no mods) check if it needs to be cleared
        if (timer_elapsed(state_reset_timer) > STATE_RESET_TIME) {// menu up time elapsed?
            if (user_config.OSIndex) { // Y. stop the menu by lifting the mods
                unregister_code(KC_RALT); // Win
            } else {
                unregister_code(KC_RGUI); // Mac
            }
            state_reset_timer = mods_held = 0;  // stop the timer
            appmenu_on = false;
        }
    }
}
