
//#include QMK_KEYBOARD_H

#include <stdio.h>

#include "moutis.h"


/*
    My globals
*/
user_config_t user_config;
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user
uint16_t record_keycode = 0; // the keykcode we poke at in process_record
uint16_t key_trap = 0; // the actual keycode registered (need to unregister)
#ifdef ADAPTIVE_ENABLED
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0; // timer of keydown for adaptive threshhold.
#endif

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint32_t state_reset_timer = 0;  // time to leave a state active before shutting it down automatically.
bool appmenu_on = false;  // state of windows-like app switcher
bool mods_held = false;  // nood to remember how we entered the appmenu state

#ifdef JP_MODE_ENABLE
bool IS_ENGLISH_MODE = true;
uint16_t myKC_C = KC_C;  // keycode for "C"  (could be Z if Japanese mode)
uint16_t myKC_X = KC_X;  // keycode for "X"  (could be - if Japanese mode)
//uint16_t myKC_L = KC_L;  // keycode for "L"  (could be K if Japanese mode)
//uint16_t myKC_K = KC_K;  // keycode for "K"  (could be L if Japanese mode)
#endif
//uint16_t LBRC_key = KC_LBRC;  // keycode for "[" // Bronze/Ag/Pl are swapped
//uint16_t RBRC_key = KC_RBRC;  // keycode for "]" // unneeded if only one map onboard.

#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;
#endif


uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions


#ifdef AUTO_SHIFT_ENABLE
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
        case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
        case KC_1 ... KC_0:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        case KC_TAB:
        case KC_MINUS ... KC_SLASH:
        case KC_NONUS_BSLASH:
#    endif
        case LCTL_T(KC_C): // #ifdef Rh
        case LT(6,KC_H):  // #ifdef Bronze
        case LT(6,KC_R):  // #elseif Ti
        case RALT_T(KC_I):
        case RCTL_T(KC_H):
        case LCTL_T(KC_R):
        case LALT_T(KC_S):
        case LGUI_T(KC_N):
        case LSFT_T(KC_T):
        case RSFT_T(KC_A):
        case RGUI_T(KC_E):
        case RALT_T(KC_C):
        case RCTL_T(KC_I):
        case LT(4,KC_COMM):
        case LT(5,KC_B): // #std B
        case LT(5,KC_K): // #alt K
            return true;
        default:
            return false;
    }
}
#endif // AUTO_SHIFT_ENABLE



layer_state_t layer_state_set_user(layer_state_t layer_state) {

/*
 Someday, when OLED is important again, rewrite to
 display Host Keyboard Layer Status using a table of layer names
*/
    
    
#ifdef OLED_DRIVER_ENABLE
    oled_set_cursor(0, 0);
    oled_write_P (layer_name[get_highest_layer(layer_state)]);
    }
#endif


    switch (biton32(layer_state)) {
#ifdef L_HDNEU
        case L_HDNEU:
#ifdef RGBLIGHT_ENABLE
#endif
#endif
#ifdef L_HDGOLD
        case L_HDGOLD:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(36, 240, 240);
            break;
#endif
#endif
//#ifdef L_HDTITANIUM
        case L_HDTITANIUM:
//#endif
#ifdef L_HDRHODIUM
        case L_HDRHODIUM:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(128, 128, 128);
            break;
#endif
#endif
#if defined(L_HDNEU) || defined(L_HDGOLD) || defined(L_HDTITANIUM) || defined(L_HDRHODIUM)
           LBRC_key = KC_LBRC;  // keycode for "["
           RBRC_key = KC_RBRC;  // keycode for "]"
           break;
#endif
#ifdef L_HDBRONZE
        case L_HDBRONZE:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(12, 228, 228);
            break;
#endif
#endif
#ifdef L_HDSILVER
        case L_HDSILVER,
#ifdef RGBLIGHT_ENABLE
#endif
#endif
#ifdef L_HDPLATINUM
        case L_HDPLATINUM,
#ifdef RGBLIGHT_ENABLE
#endif
#endif
#if defined(L_HDBRONZE) || defined(L_HDSILVER) || defined(L_HDPLATINUM) || defined(L_HDRHODIUM)
//        LBRC_key = KC_RBRC;  // keycode for "]"
//        RBRC_key = KC_LBRC;  // keycode for "["
//        break;
#endif
        case L_PUNCT:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(213, 255, 128);
#endif
            break;
        case L_FN_NUM:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(64, 255, 128);
#endif
            break;
        case L_NUMPAD:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(85, 255, 128);
#endif
            break;
        case L_NAV:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(128, 255, 128);
#endif
            break;
        case L_MEDIA_KBD:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(0, 255, 128);
#endif
            break;
    }

    return layer_state;
}

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


#include "moutis_semantickeys.c" // anything could send a semantic, so…first

#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
    #include "moutis_ENCODER.c"
#endif

#ifdef COMBO_ENABLE
    #include HD_combo_code
#endif

#include "moutis_casemods.c"

#ifdef ADAPTIVE_ENABLED
#include HD_adaptive_code
#endif

#include HD_process_record_code


#include "moutis_MATRIX.c"
// This

#ifdef KEY_OVERRIDE_ENABLE  // If using QMK's key overrides...
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, LT(L_NUMPAD,KC_BSPC), KC_DELETE);
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
