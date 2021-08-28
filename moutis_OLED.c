
void oled_task_user(void) {
    uint8_t modifiers = get_mods();
//    uint8_t led_usb_state = host_keyboard_leds();

/* // using modifiers in the home row if left, on thumb if right.
    if (is_keyboard_left()) {
        oled_set_cursor(0, 7);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("     "), false);
    } else {
        oled_set_cursor(0, 7);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT ") : PSTR("      "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL") : PSTR("    "), false);
    }
//*/
    if (is_keyboard_left()) {
        oled_set_cursor(0, 7);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("     "), false);
    } else {
        oled_set_cursor(0, 7);
        oled_write_P((modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT ") : PSTR("      "), false);
        oled_write_P((modifiers & MOD_MASK_GUI) ? PSTR("CMD ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
        oled_write_P((modifiers & MOD_MASK_CTRL) ? PSTR("CTRL") : PSTR("    "), false);
    }
//*/

/*    oled_set_cursor(0, 6);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCR_LOCK) ? PSTR("SCRL") : PSTR("    "), false);
    return;
*/

}

uint32_t layer_state_set_user(uint32_t layer_state) {
    // display Host Keyboard Layer Status
    oled_set_cursor(0, 0);
    switch (get_highest_layer(layer_state)) {
        case L_QWERTY:
            oled_write_P(PSTR("QWERTY           "), false);
            break;
        case L_HANDSDOWN:
            oled_write_P(PSTR("HD Bronze      "), false);
            break;
        case L_PUNCT:
            oled_write_P(PSTR("Brackets/Punct.  "), false);
            break;
        case L_FN:
            oled_write_P(PSTR("fn               "), false);
            break;
        case L_MEDIA_NAV:
            oled_write_P(PSTR("Media/Navi       "), false);
            break;
        case L_LANG_NUM:
            oled_write_P(PSTR("Symbols/10 Key   "), false);
            break;
        case L_DIACR:
            oled_write_P(PSTR("Diacritics       "), false);
            break;
    }
    return layer_state;
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_clear();
    return OLED_ROTATION_180;  // flips the display 180 degrees
}

