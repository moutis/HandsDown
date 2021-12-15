bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (!index) { /* First (left) encoder */
      switch(get_highest_layer(layer_state)){
          case L_FN: // function layer
              /* for audio scrub bk/fwd. */
              if (clockwise) {
                  tap_code16(KC_BRIU); // Screen BRIGHTNESS UP
              } else {
                  tap_code16(KC_BRID);  // Screen BRIGHTNESS DN
              }
              break;

#ifdef RGBLIGHT_ENABLE
          case L_NAV: // media/nav layer
              saved_mods = get_mods();
              if (saved_mods & MOD_MASK_SHIFT) {
                  if (clockwise) {
                      tap_code16(RGB_SAI); // Sat +
                  } else {
                      tap_code16(RGB_SAD); // Sat -
                  }
              } else {
                  if (clockwise) {
                      tap_code16(RGB_HUI); // Hue +
                  } else {
                      tap_code16(RGB_HUD); // Hue -
                  }
              }
              break;
#endif

          default:
              if (clockwise) {
                tap_code(KC_VOLU); // media vol up
              } else {
                tap_code(KC_VOLD); // media vol dn
              }
              break;
      }
  } else  {  // Second (right) encoder
      switch(get_highest_layer(layer_state)){
          case L_FN: // function layer
              if (clockwise) {
                  tap_SemKey(SK_ZOOMIN); // ZOOM IN
              } else {
                  tap_SemKey(SK_ZOOMOUT); // ZOOM OUT
              }
              break;
          case L_NAV: // media/nav layer
              if (clockwise) {
                  tap_SemKey(SK_HISTNXT); // prev page
              } else {
                  tap_SemKey(SK_HISTPRV); // next page
              }
              break;
          default:
              if (clockwise) {
                tap_code(KC_MNXT); // media next track
              } else {
                tap_code(KC_MPRV); // media prev track
              }
              break;
      }
  }
    return false;
}
