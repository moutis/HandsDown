/* Based on Andrew Rae's implementation
 * Copyright 2021 Andrew Rae ajrae.nv@gmail.com @andrewjrae
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* The caps word concept started with @iaap on splitkb.com discord.
 * However it has been implemented and extended by many splitkb.com users:
 * - @theol0403 made many improvements to initial implementation
 * - @precondition used caps lock rather than shifting
 * - @dnaq his own implementation which also used caps lock
 * - @sevanteri added underscores on spaces
 * - @metheon extended on @sevanteri's work and added specific modes for
 *   snake_case and SCREAMING_SNAKE_CASE
 * - @baffalop came up with the idea for xcase, which he implements in his own
 *   repo, however this is implemented by @iaap with support also for one-shot-shift.
 * - @sevanteri
 *     - fixed xcase waiting mode to allow more modified keys and keys from other layers.
 *     - Added @baffalop's separator defaulting on first keypress, with a
 *       configurable default separator and overrideable function to determine
 *       if the default should be used.
 */


// bools to keep track of the caps word state
static uint32_t caps_word_timer = 0;
static bool last_press_was_space = false;

/*
bool caps_word_on (void) {
    if (caps_word_timer)
        return true;
    return false;
}
*/
// Enable caps word
void enable_caps_word(void) {

    last_press_was_space = false;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
    caps_word_timer = timer_read(); // (re)start timing hold for keyup below
}

// Disable caps word
void disable_caps_word(void) {
    caps_word_timer = 0;
    if (last_press_was_space) {
        tap_code(KC_BSPC);
        tap_code16(KC_SPC);
    }
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Toggle caps word
void toggle_caps_word(void) {
    if (caps_word_timer) {
        disable_caps_word();
    }
    else {
        enable_caps_word();
    }
}

// Called from process_record_user. assumes caps_word is on
bool process_caps_word(uint16_t keycode, const keyrecord_t *record) {

    // Filter out the actual keycode from MT and LT keys.
    // This isn't working right. need to allow a layer to happen.
/*    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
 #ifdef TAP_DANCE_ENABLE
         case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
 #endif
            if (record->tap.count == 0) // if not tapped yet…
                return true; // do that first
            keycode = keycode & 0xFF; // process the base key
        default:
            break;
    }
*/
    if (record->event.pressed) {
        keycode = keycode & QK_BASIC_MAX; // process just the base key
        // check if the case modes have been terminated
        if ((get_mods() != 0)) { // hitting any mod...go handle it
            disable_caps_word();
            return true; // let QMK handle it.
        }
        caps_word_timer = timer_read(); // (re)start timing hold for auto-off delay
        switch (keycode) {
            case KC_1 ... KC_0: // let these pass through
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
            case KC_RIGHT ... KC_LEFT:
                last_press_was_space = false;
                return true; // let QMK handle it.
            case KC_SPC:
                if (last_press_was_space) {
                    disable_caps_word();
                    return true; // let QMK handle space normally
                } else {
                    tap_code16(KC_UNDS);
                    last_press_was_space = true;
                    return false; // We handled it
                }
            case KC_A ... KC_Z: // only works for ASCII. fix this.
                register_code(KC_LSFT); // for platforms that do CAPSLK differently
                tap_code(keycode); // like iOS, etc.
                unregister_code(KC_LSFT);
                last_press_was_space = false;
               return false; // We handled it
            }
        disable_caps_word(); // didn't encounter a legit caps char, so off.
        return true;
    } 
/*
    else {
        switch (keycode) {
            case KC_SPC:
                if (last_press_was_space) {
                    //unregister_code16(KC_UNDS);
                    return false; // We handled it
                }
        }
    } // end if event.pressed
*/
    return true; // keep processing
}
