
//#include QMK_KEYBOARD_H

#include <stdio.h>

#include "moutis.h"


/*
    My globals
*/
user_config_t user_config;
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user
uint16_t record_keycode = 0; // the keykcode we poke at in process_record
// key_trap is used to intercept keycodes to do KEY_OVERRIDE stuff in userspace.
// since QMK's KEY_OVERRIDE can't integrate Semantic Keys or lingers.
uint16_t key_trap = 0; // the actual keycode registered (need to unregister)

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint32_t appmenu_timer = 0;  // time to leave appmenu active before shutting it down automatically.
bool appmenu_on = false;  // appmenu triggered (after holding key)
bool mods_held = false;  // need to remember how we entered the appmenu state

#ifdef ADAPTIVE_ENABLE
uint16_t preprior_keycode = KC_NO;
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0; // timer of keydown for adaptive threshhold.
#endif

#ifdef JP_MODE_ENABLE
bool IS_ENGLISH_MODE = true;
#endif

#ifdef MYMODMORPH // use the table for modmorph

#define mm_count 5
const modmorph_t ModMorph[mm_count] = {
// linger?, keycode,    shifted,    alt,        altshft
    {true,  KC_DOT,     KC_COLN,    SK_ELPS,    SK_NOTEQ},  // ., SHIFT = :, ALT= …, ALT+SHIFT= ≠
    {true,  KC_QUOT,    KC_GT,      SK_FDQR,    SK_FSQR },  // ', SHIFT = >, ALT= », ALT+SHIFT= ›
    {true,  KC_DQUO,    KC_LT,      SK_FDQL,    SK_FSQL },  // ", SHIFT = <, ALT= «, ALT+SHIFT= ‹
    {false, KC_SCLN,    KC_COLN,    SK_PARA,    SK_SECT },  // ", SHIFT = —, ALT= ¶, ALT+SHIFT= §
    {false, KC_COLN,    SK_ELPS,    KC_PERC,    SK_PERM },  // ", SHIFT = —, ALT= ¶, ALT+SHIFT= §
};
#endif // MYMODMORPH
uint16_t L_quote = KC_DQUO; // default " (「 in Japanese mode)
uint16_t R_quote = KC_QUOT; // default ' (」 in Japanese mode)

#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;
#endif

uint8_t  combo_on = 0;           // for combo actions with hold behaviors
bool  combo_triggered = false;   // for one-shot-combo-actions

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
        case L_HD:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(128, 128, 128);
            break;
#endif
        case L_SYM:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(213, 255, 128);
#endif
            break;
        case L_FUN:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(64, 255, 128);
#endif
            break;
        case L_NUM:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(85, 255, 128);
#endif
            break;
        case L_NAV:
#ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(128, 255, 128);
#endif
            break;
        case L_CFG:
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

//    user_config.raw = 0; // reset
//    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
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

#include "moutis_app_menu.c" // my custom app_menu handler (mac/win)

#include "moutis_semantickeys.c" // anything could send a semantic, so…first

#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
    #include "moutis_ENCODER.c"
#endif

#ifdef COMBO_ENABLE
    #include "moutis_combo.c"  // combo processing code (def in keymap)
#endif

#include "moutis_casemods.c"

#ifdef ADAPTIVE_ENABLE
#include HD_adaptive_code   // this is HD variation dependent
#endif

// #include HD_process_record_code   // this might need to be HD variation dependent?
#include "moutis_process_record.c"

#include "moutis_matrix.c"
