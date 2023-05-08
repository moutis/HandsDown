//
// somewhere early in process_record_user
//
// uses globals:
// uint32_t state_reset_timer = 0;
// uint8_t  saved_mods = 0; //
// bool appmenu_on = false;  // state of windows-like app switcher
// bool mods_held = false;  // nood to remember how we entered the appmenu state
//

bool process_KC_APP()
{
// KC_APP key gets special treatment
  if (record->event.pressed) {
    if (saved_mods & (MOD_MASK_CTRL)) {
      unregister_code(KC_RALT);  // ignore these if ctrl
      unregister_code(KC_RGUI);
      tap_code(KC_TAB);  // switch window w/in app (need semkey for this.)
      return false; // handled this record.
    }
    mods_held = (saved_mods & (MOD_MASK_GUI | MOD_MASK_ALT)); // were mods held?
    if (!mods_held) { // gui/alt not down, supply them
      if (user_config.OSIndex) {  // Can't SemKey this bc hold mods & timer...
        register_code(KC_RALT); // Windows
      } else {
        register_code(KC_RGUI); // Mac
      }
    }
    tap_code(KC_TAB); // switch app
    state_reset_timer = timer_read(); // (re)start timing hold for keyup below
    return false; // handled this record.
  }
  // up event
  if (mods_held || appmenu_on) // mods down, or already on…
    return false; // so nothing to do here (scan_matrix_user will handle it)
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
  return false; // handled this record.
}
//
// somewhere in matrix_scan_user
//
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
