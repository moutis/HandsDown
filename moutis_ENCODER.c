
bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
    uint8_t  held_mods;

    held_mods = get_mods(); // fetch mods
  if (!index) { /* First (left) encoder */
      switch(get_highest_layer(layer_state)){
          case L_FN_NUM: // function layer
              /* for audio scrub bk/fwd. */
              if (clockwise) {
                  tap_code16(KC_BRIU); // Screen BRIGHTNESS UP
              } else {
                  tap_code16(KC_BRID);  // Screen BRIGHTNESS DN
              }
              break;
          case L_NUMPAD: // numpad layer (for navigating in spreadsheets)
              if (clockwise) {
                  tap_code16(KC_RGHT); //
              } else {
                  tap_code16(KC_LEFT);  //
              }
              break;
          case L_NAV: // nav layer
              if (clockwise) {
                  tap_SemKey(SK_ZOOMIN); // ZOOM IN
              } else {
                  tap_SemKey(SK_ZOOMOUT); // ZOOM OUT
              }
              break;

#ifdef RGBLIGHT_ENABLE
          case L_MEDIA_KBD: // media/kbd settings layer
              if (clockwise) {
                  rgblight_increase_val(); // val (brightness) +
              } else {
                  rgblight_decrease_val(); // val (brightness) -
              }
              break;
#endif
          default:
              if (held_mods & MOD_MASK_GUI) {
                  if (clockwise) { // Use SemKey for Platform flexible app switch
                      tap_SemKey(SK_APPNXT); // app right
                  } else {
                      tap_SemKey(SK_APPPRV); // app left
                  }
              } else {
                  if (clockwise) {
                    tap_code(KC_VOLU); // media vol up
                  } else {
                    tap_code(KC_VOLD); // media vol dn
                  }
              }
              break;
      }
  } else  {  // Second (right) encoder
      switch(get_highest_layer(layer_state)){
          case L_NUMPAD: // numpad layer (for navigating in spreadsheets)
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
          case L_MEDIA_KBD: // media/kbd settings layer
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
              if (held_mods & MOD_MASK_GUI) {
                  if (clockwise) { // Use SemKey for Platform flexible app switch
                      tap_SemKey(SK_APPNXT); // app right
                  } else {
                      tap_SemKey(SK_APPPRV); // app left
                  }
              } else {
                  if (clockwise) {
                    tap_code(KC_MNXT); // media next track
                  } else {
                    tap_code(KC_MPRV); // media prev track
                  }
              }
              break;
      }
  }
    return false;
}
