
#include QMK_KEYBOARD_H

#include <stdio.h>
#include "process_combo.h"
#include "moutis.h"


user_config_t user_config;

uint32_t keyhold_timer = 0;
uint32_t appmenu_timer = 0;
bool appmenu_on = false;
bool mods_held = false;
bool key_trap = false; // used for shift BS = del (right)
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user

bool is_keyboard_left(void) {
    #if defined(MASTER_LEFT)
        return is_keyboard_master();
    #elif defined(MASTER_RIGHT)
        return !is_keyboard_master();
    #elif defined(SPLIT_HAND_PIN)
        // Test pin SPLIT_HAND_PIN for High/Low, if low it's right hand
        setPinInputHigh(SPLIT_HAND_PIN);
        bool x = !readPin(SPLIT_HAND_PIN);
        setPinInput(SPLIT_HAND_PIN);
        return x;
    #elif defined(EE_HANDS)
        return eeprom_read_byte(EECONFIG_HANDEDNESS);
    #endif

    return is_keyboard_master();
}

/*
 Semantic Keys is as STUB for platform independence. Anything
 that must be interpreted by the host, in order to produce a glyph
 or keystroke(s) that issues a command, can be abstracted to a
 semantic function here, enabling platform specific keystroke(s)
 to be sent as appropriate.

 Phase 1: simple 1:1 keystroke mapping
   complete.
 
 Phase 2: Requires w/Sevanteri's early combos.
 Integrate all combo and keymap processing so they both queue
 SemKeys to be handled in process_record_user, reducing the code
 and simplifying maintenance.
 
 Phase 3: expand to multi-keystrokes, which would enable sending
 different compose sequences based on platform (diacritics),
 and possibly facilitate editor support (vim/emacs)?
 
 Phase 4: use in Hands Down Polyglot.
 
 */

const uint16_t SemKeys_t[SemKeys_COUNT][SemKeys_OS_COUNT] = {
    // Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
    [SK_KILL] = {G(A(KC_ESC)),C(A(KC_DEL))}, // "KILL" OR Force quit / ctrl-alt-del
    [SK_UNDO] = {G(KC_Z),C(KC_Z)}, // undo
    [SK_CUT ] = {G(KC_X),C(KC_X)}, // cut
    [SK_COPY] = {G(KC_C),C(KC_C)}, // copy
    [SK_PSTE] = {G(KC_V),C(KC_V)}, // paste
    [SK_PSTM] = {G(S(A(KC_V))),C(S(A(KC_V)))}, // paste_match
    [SK_SALL] = {G(KC_A),C(KC_C)}, // select all
    [SK_CLOZ] = {G(KC_W),C(KC_W)}, // close
    [SK_QUIT] = {G(KC_Q),C(KC_Q)}, // quit
    [SK_FIND] = {G(KC_F),C(KC_F)}, // find
    [SK_FAGN] = {G(KC_G),C(KC_G)}, // find again
    [SK_SCAP] = {S(G(KC_4)),KC_PSCR}, // Screen Capture
    [SK_SCLP] = {C(S(G(KC_4))),A(KC_PSCR)}, // Selection Capture
};

#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
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

#endif

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd_bronze.c"
#endif

#include "moutis_PROCESS_RECORD_hd_bronze.c"

#include "moutis_MATRIX.c"

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM to facilitate
    // appropriate for platform support

    /*
    user_config.osIsWindows is true, so use 0 for Mac
     */
    user_config.raw = eeconfig_read_user();
    if (user_config.osIsWindows) { // kludge, 'cause I'm stupid and can't typecast a bool
        OSIndex = 1; // USED BY SemKeys
    } else {
        OSIndex = 0;
    }


#ifdef OLED_DRIVER_ENABLE
    oled_clear();
        if (user_config.osIsWindows) {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("WIN"), false);
        } else {
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("MAC"), false);
        }
    oled_render();
    oled_on();
#endif
}
