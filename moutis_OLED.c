
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

    oled_set_cursor(0, 6);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCR_LOCK) ? PSTR("SCRL") : PSTR("    "), false);
    return;


}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_clear();
    return OLED_ROTATION_180;  // flips the display 180 degrees
}

