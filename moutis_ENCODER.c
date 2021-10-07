bool encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
  if (!index) { /* First (left) encoder */
      switch(get_highest_layer(layer_state)){
          case L_MEDIA_NAV: // media/nav layer
              /* for audio scrub bk/fwd. */
              if (clockwise) {
                  tap_code16(KC_BRIU); // BRIGHTNESS UP
              } else {
                  tap_code16(KC_BRID);  // BRIGHTNESS DN
              }
              break;
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
          case L_MEDIA_NAV: // media/nav layer
              if (clockwise) {
                  tap_SemKey(SK_HISTPRV); // prev page
              } else {
                  tap_SemKey(SK_HISTNXT); // next page
              }
              break;
          case L_LANG_NUM: // punctuation layer
              if (clockwise) {
                  tap_SemKey(SK_ZOOMIN); // ZOOM IN
              } else {
                  tap_SemKey(SK_ZOOMOUT); // ZOOM OUT
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
