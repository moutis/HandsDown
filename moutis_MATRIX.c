
#ifdef LEADER_ENABLE
bool did_leader_succeed;
LEADER_EXTERNS();
#endif

void matrix_scan_user(void) {
extern uint8_t  saved_mods;

#ifdef LEADER_ENABLE
    #include "moutis_LEADER.c"
#endif

#ifdef COMBO_ENABLE
        matrix_scan_user_process_combo();
#endif

    if (appmenu_on) { // linger menu on, (no mods) check if it needs to be cleared
        if (timer_elapsed(appmenu_timer) > TAPPING_TERM * 5) {// linger time elapsed?
            if (user_config.osIsWindows) { // Y. stop the menu.
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
            }
            appmenu_timer = 0;
            appmenu_on = false;
        }
    }


}

#ifdef LEADER_ENABLE

void leader_start(void) {
  // Add your code to run when pressing the leader key here
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("Leader: "), false);
#endif
    
}
void leader_end(void) {
// Add your code to run when a leader key sequence ends here

#ifdef OLED_DRIVER_ENABLE
    if (!leading) {
        oled_set_cursor(0, 3);
        oled_write_P(PSTR("                   "), false);
//        oled_render();
    }
#endif

}

#endif
