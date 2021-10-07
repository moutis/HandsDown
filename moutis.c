
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

#ifdef RGBLIGHT_ENABLE
int RGB_current_mode;
#endif


uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions
uint8_t  OSIndex = (uint8_t) 0;  // kludge, 'cause I'm stupid

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



#include "moutis_semantickeys.c" // anything could send a semantic, so…first

#ifdef OLED_DRIVER_ENABLE
    #include "moutis_OLED.c"
#endif

#ifdef ENCODER_ENABLE
    #include "moutis_ENCODER.c"
#endif

#ifdef COMBO_ENABLE
    #include "moutis_COMBO_hd_bronze_sk.c"
#endif

#include "moutis_casemods.c"

#include "moutis_adaptivekeys.c"

#include "moutis_PROCESS_RECORD_hd_neu.c"

#include "moutis_MATRIX.c"

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);
const key_override_t ques_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &ques_key_override,
    NULL // Null terminate the array of overrides!
};
#endif

