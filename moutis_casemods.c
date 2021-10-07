/* Copyright 2021 Andrew Rae ajrae.nv@gmail.com @andrewjrae
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
 
    currently doesn't handle layer/mod taps properly. why?
 
 */


// bool to keep track of the caps word state
static bool caps_word_on = false;
//static uint16_t caps_word_timer = 0;

// Check whether caps word is on
bool caps_word_enabled(void) {
    return caps_word_on;
}

// Enable caps word
void enable_caps_word(void) {

    caps_word_on = true;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
    state_reset_timer = timer_read(); // (re)start timing hold for keyup below
}

// Disable caps word
void disable_caps_word(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Toggle caps word
void toggle_caps_word(void) {
    if (caps_word_on) {
        disable_caps_word();
    }
    else {
        enable_caps_word();
    }
}

// overrideable function to determine whether the case mode should stop
__attribute__ ((weak))
bool terminate_caps_word(uint16_t keycode, const keyrecord_t *record) {
        switch (keycode) {
            // Keycodes to ignore (don't disable caps word)
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_MINS:
            case KC_UNDS:
            case KC_BSPC:
                state_reset_timer = timer_read(); // (re)start timing hold for auto-off delay
                if (record->event.pressed && (get_mods() != 0)) {
                    return true;
                }
                break;
            default:
                if (record->event.pressed) {
                    return true;
                }
                break;
        }
        return false;
}

bool process_caps_word(uint16_t keycode, const keyrecord_t *record) {

    if (caps_word_on) {
        // Filter out the actual keycode from MT and LT keys.
        // This isn't working right
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
                if (record->tap.count == 0) // if not tapped yet…
                    return false; // do that first
                keycode = keycode & 0xFF; // This may ignore off layer keys?
            default:
                break;
        }

        if (record->event.pressed) {
            // check if the case modes have been terminated
            if ((terminate_caps_word(keycode, record))) {
                disable_caps_word();
            }
        } // end if event.pressed
        return true; // keep processing
    }
    return true;
}
