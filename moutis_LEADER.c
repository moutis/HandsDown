/*
this is included in the scan_matrix_user function
*/

  LEADER_DICTIONARY() {
    did_leader_succeed = leading = false;
    leader_end();
 
    // Set current OS indicator to macOs
      SEQ_ONE_KEY(KC_M) {
          user_config.osIsWindows = false;
          eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
          oled_set_cursor(oled_max_chars() - 3, 0);
          oled_write_P(PSTR("MAC"), false);
#endif // OLED_DRIVER_ENABLE
      }

    // Set current OS indicator to Windows
      SEQ_ONE_KEY(KC_W) {
          user_config.osIsWindows = true;
          eeconfig_update_user(user_config.raw);
#ifdef OLED_DRIVER_ENABLE
          oled_set_cursor(oled_max_chars() - 3, 0);
          oled_write_P(PSTR("WIN"), false);
#endif // OLED_DRIVER_ENABLE
}
    // Screenshot
      SEQ_ONE_KEY(KC_S) {
          if (user_config.osIsWindows) {
              tap_code16(S(G(KC_S)));
          } else {
              tap_code16(S(G(KC_4)));
          }
#ifdef OLED_DRIVER_ENABLE
          oled_set_cursor(9, 3);
          oled_write_P(PSTR("Screenshot"), false);
#endif // OLED_DRIVER_ENABLE
      }
      SEQ_ONE_KEY(KC_H) {
          SEND_STRING("however, ");
      }
      SEQ_ONE_KEY(KC_N) {
          SEND_STRING("nevertheless, ");
      }
      SEQ_TWO_KEYS(KC_G, KC_R) {
          SEND_STRING("Gratefully,\n");
      }
      SEQ_TWO_KEYS(KC_A, KC_R) {
          SEND_STRING("Alan Reiser");
      }
      SEQ_THREE_KEYS(KC_A, KC_A, KC_R) {
          SEND_STRING("alan@alanreiser.com");
      }
  } // end LEADER_DICTIONARY

