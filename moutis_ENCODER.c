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
//              if (clockwise) {
//                  tap_code16(G(KC_RBRC)); // prev page
//              } else {
//                  tap_code16(G(KC_LBRC)); // next page
//              }
//              break;
          case L_LANG_NUM: // punctuation layer
              if (clockwise) {
                  tap_code16(G(S(KC_EQL))); // ZOOM IN
              } else {
                  tap_code16(G(KC_MINS)); // ZOOM OUT
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
    return true;
}
