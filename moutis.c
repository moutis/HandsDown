
#include QMK_KEYBOARD_H

#include <stdio.h>

#include "moutis.h"

/*
    My globals
*/
user_config_t user_config;
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user
uint16_t record_keycode = 0; // the keykcode we poke at in process_record

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint32_t state_reset_timer = 0;  // time to leave a state active before shutting it down automatically.
bool appmenu_on = false;  // state of windows-like app switcher
bool mods_held = false;  // nood to remember how we entered the appmenu state
bool key_trap = false; // used for shift BS = del (right)

//Kinda klugy, prototyping things.
uint16_t myKC_C = KC_C;  // keycode for "C"  (could be K if Japanese mode)
uint16_t myKC_X = KC_X;  // keycode for "X"  (could be Z if Japanese mode)
uint16_t LBRC_key = KC_LBRC;  // keycode for "["
uint16_t RBRC_key = KC_RBRC;  // keycode for "]"

#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;
#endif


uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM to facilitate
    // appropriate platform support

    /*
    user_config.OSIndex use 0 for Mac; 1 for Win
     */
    user_config.raw = eeconfig_read_user();
    eeconfig_read_default_layer(); // get the default layer from eeprom.
    
#ifdef OLED_DRIVER_ENABLE
    oled_clear();
    switch (user_config.OSIndex) {
        case OS_Mac:
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("WIN"), false);
            break;
        case OS_Win:
            oled_set_cursor(oled_max_chars() - 3, 0);
            oled_write_P(PSTR("MAC"), false);
        }
    oled_render();
    oled_on();
#endif
}

uint32_t layer_state_set_user(uint32_t layer_state) {

/*
 Someday, when OLED is important again, rewrite to
 display Host Keyboard Layer Status using a table of layer names
*/
    
    
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, 0);
    oled_write_P (layer_name[get_highest_layer(layer_state)]);
    }
#endif


#ifdef RGBLIGHT_ENABLE
    switch (biton32(layer_state)) {
        case L_PUNCT:
            rgblight_sethsv_noeeprom(213, 255, 128);
            break;
        case L_FN_NUM:
            rgblight_sethsv_noeeprom(64, 255, 128);
            break;
        case L_NUMPAD:
            rgblight_sethsv_noeeprom(85, 255, 128);
            break;
        case L_NAV:
            rgblight_sethsv_noeeprom(128, 255, 128);
            break;
        case L_MEDIA_KBD:
            rgblight_sethsv_noeeprom(0, 255, 128);
            break;
        default: //  for any other layers, or the default layer
            rgblight_reload_from_eeprom();
/*
            switch (biton32(default_layer_state)) {
              case L_HDBRONZE:
                  rgblight_sethsv_noeeprom(12, 228, 228);
                  break;
              case L_HDGOLD:
                  rgblight_sethsv_noeeprom(36, 240, 240);
                  break;
              case L_QWERTY:
                  rgblight_sethsv_noeeprom(HSV_AZURE);
                  break;
            }
*/
            break;
    }
#endif // RGBLIGHT_ENABLE


    return layer_state;
}


#include "moutis_semantickeys.c" // anything could send a semantic, so…first

#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
    #include "moutis_ENCODER.c"
#endif

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd_neu_sk.c"
#endif

#include "moutis_casemods.c"

#include "moutis_adaptivekeys.c"

#include "moutis_PROCESS_RECORD_hd_neu.c"

#include "moutis_MATRIX.c"

#ifdef KEY_OVERRIDE_ENABLE  // If using QMK's key overrides...
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_LANG_NUM,KC_BSPC), KC_DELETE);
const key_override_t ques_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t hash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_AT);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t slsh_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_ASTR);
const key_override_t bsls_key_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_BSLS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &ques_key_override,
    &hash_key_override,
    &dot_key_override,
    &comm_key_override,
    &slsh_key_override,
    &bsls_key_override,
    NULL // Null terminate the array of overrides!
};
#endif

