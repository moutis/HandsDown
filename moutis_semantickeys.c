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
  -- IN PROCESS --
 
 Phase 3: expand to multi-keystrokes, which would enable sending
 different compose sequences based on platform (diacritics),
 and possibly facilitate editor support (vim/emacs)?
 
 Phase 4: use in Hands Down Polyglot.
 
 */



/*
unsigned char BCD_TO_ASCII(uint8 src) {
    return (unsigned char)((src - 0x30) * 0x10 + src[1] - 0x30);
*/


//
// SemKey table is a uint16 keycode, unless MSB is high, then it
// is BCD of the 3 digit Windows/DOS character codes
//
/*
void tap_SemKey(uint16_t semkeycode) {

    if (semkeycode && 0x8000 ) { // highest bit set = Windows AltGR code
        clear_keyboard(); // must have clean buffer.
        register_code(KC_RALT);
        if (semkeycode && 0xE000 ) // need to send 4 digits
            tap_code(KC_0); // send 4th to last digit (always 0)
        if (semkeycode && 0xC000 ) // need to send 3 more digits
            tap_code((uint16_t)(((semkeycode>>8) && 0x000F) + KC_0)); // send 3rd to last digit
        if (semkeycode && 0xA000 ) // need to send 2 more digits
            tap_code((uint16_t)(((semkeycode>>4) && 0x000F) + KC_0)); // send 2nd to last digit
        tap_code((uint16_t)((semkeycode && 0x000F) + KC_0)); // send last digit
        unregister_code(KC_RALT);
    } else {
        tap_code16(semkeycode); // Just send the keycode as-is
    }
}
*/
    
    
/*
* based on the table at:
* https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
* tested on my own machines, seems to work fine.
*
*/

const uint16_t SemKeys_t[SemKeys_COUNT - SK_KILL][OS_count] = {
    // Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
    [SK_KILL - SK_KILL] = {G(A(KC_ESC)),C(A(KC_DEL))}, // Force quit / ctrl-alt-del
    [SK_HENK - SK_KILL] = {KC_LNG1, C(S(KC_1)), C(S(KC_1))}, // 変換/かな
    [SK_MHEN - SK_KILL] = {KC_LNG2, C(S(KC_0)), C(S(KC_0))}, // 無変換/英数
    [SK_HENT - SK_KILL] = {G(KC_ENT),C(KC_ENT),C(KC_ENT)}, // Hard ENTER
    [SK_UNDO - SK_KILL] = {G(KC_Z),C(KC_Z),C(KC_Z)}, // undo
    [SK_REDO - SK_KILL] = {G(S(KC_Z)),C(S(KC_Z)),C(S(KC_Z))}, // Redo
    [SK_CUT  - SK_KILL] = {G(KC_X),C(KC_X),C(KC_X)}, // cut
    [SK_COPY - SK_KILL] = {G(KC_C),C(KC_C),C(KC_C)}, // copy
    [SK_PSTE - SK_KILL] = {G(KC_V),C(KC_V),C(KC_V)}, // paste
    [SK_PSTM - SK_KILL] = {G(S(A(KC_V))),C(S(A(KC_V))),C(S(A(KC_V)))}, // paste_match
    [SK_SALL - SK_KILL] = {G(KC_A),C(KC_A),C(KC_A)}, // select all
    [SK_CLOZ - SK_KILL] = {G(KC_W),C(KC_W),C(KC_W)}, // close
    [SK_QUIT - SK_KILL] = {G(KC_Q),C(KC_Q),C(KC_Q)}, // quit
    [SK_NEW - SK_KILL] = {G(KC_N),C(KC_N),C(KC_N)}, // new
    [SK_OPEN - SK_KILL] = {G(KC_O),C(KC_O),C(KC_O)}, // open
    [SK_FIND - SK_KILL] = {G(KC_F),C(KC_F),C(KC_F)}, // find
    [SK_FAGN - SK_KILL] = {G(KC_G),KC_F3,KC_F3}, // find again
    [SK_SCAP - SK_KILL] = {S(G(KC_4)),KC_PSCR,KC_PSCR}, // Screen Capture
    [SK_SCLP - SK_KILL] = {C(S(G(KC_4))),A(KC_PSCR),A(KC_PSCR)}, // Selection Capture))
//    [SK_DEL  - SK_KILL] = {KC_DEL,KC_DEL,KC_DEL}, // DELETE CHAR RIGHT
    [SK_DELWDL - SK_KILL] = {A(KC_BSPC),C(KC_BSPC),C(KC_BSPC)}, // DELETE WORD LEFT
    [SK_DELWDR - SK_KILL] = {A(KC_DEL),C(KC_DEL),C(KC_DEL)}, // DELETE WORD RIGHT
    [SK_WORDPRV - SK_KILL] = {A(KC_LEFT),C(KC_LEFT),C(KC_LEFT)}, // WORD LEFT
    [SK_WORDNXT - SK_KILL] = {A(KC_RIGHT),C(KC_RIGHT),C(KC_RIGHT)}, // WORD RIGHT
    [SK_DOCBEG - SK_KILL] = {G(KC_UP),C(KC_HOME),C(KC_HOME)}, // Go to start of document
    [SK_DOCEND - SK_KILL] = {G(KC_DOWN),C(KC_END),C(KC_END)}, // Go to end of document
    [SK_LINEBEG - SK_KILL] = {G(KC_DOWN),C(KC_END),C(KC_END)}, // Go to beg of line
    [SK_LINEEND - SK_KILL] = {G(KC_DOWN),C(KC_END),C(KC_END)}, // Go to end of line
    [SK_PARAPRV - SK_KILL] = {A(KC_UP),C(KC_UP),C(KC_UP)}, // Go to previous paragraph
    [SK_PARANXT - SK_KILL] = {A(KC_DOWN),C(KC_DOWN),C(KC_DOWN)}, // Go to next paragraph
    [SK_HISTPRV - SK_KILL] = {G(KC_LBRC),A(KC_LEFT),A(KC_LEFT)}, // BROWSER BACK
    [SK_HISTNXT - SK_KILL] = {G(KC_RBRC),A(KC_RIGHT),A(KC_RIGHT)}, // BROWSER FWD
    [SK_ZOOMIN - SK_KILL] = {G(KC_EQL),C(KC_EQL),C(KC_EQL)}, // ZOOM IN
    [SK_ZOOMOUT - SK_KILL] = {G(KC_MINS),C(KC_MINS),C(KC_MINS)}, // ZOOM OUT
    [SK_ZOOMRST - SK_KILL] = {G(KC_0),C(KC_0),C(KC_0)}, // ZOOM RESET
    [SK_APPNXT - SK_KILL] = {RGUI(KC_TAB),A(KC_TAB),A(KC_TAB)}, // APP switcher Next (last used)
    [SK_APPPRV - SK_KILL] = {RGUI(RSFT(KC_TAB)),A(S(KC_TAB)),A(S(KC_TAB))}, // APP switcher Prev (least recently used)
    [SK_WINNXT - SK_KILL] = {RCTL(KC_TAB),C(KC_TAB),C(KC_TAB)}, // Window/tab switcher Next
    [SK_WINPRV - SK_KILL] = {RCTL(RSFT(KC_TAB)),C(S(KC_TAB)),C(S(KC_TAB))}, // Window/tab switcher Prev
        // Punctuation
    [SK_SECT - SK_KILL] = {A(KC_5),0xE167,0xE167}, // § ** need Win Compose via BCD.
    [SK_ENYE - SK_KILL] = {A(KC_N),A(KC_N),A(KC_N)}, // ñ/Ñ ** need Win Compose via BCD?
    [SK_IEXC - SK_KILL] = {RALT(KC_1),RALT(KC_1),RALT(KC_1)}, // ¡ Inverted exclamation mark ** need Win Compose via BCD?
    [SK_ELPS - SK_KILL] = {A(KC_SCLN),A(KC_SCLN),A(KC_SCLN)}, // … ** need Win Compose via BCD?
    [SK_PARA - SK_KILL] = {A(KC_7),A(KC_7),A(KC_7)}, // ¶ ** need Win Compose via BCD?
    [SK_MDSH - SK_KILL] = {S(A(KC_MINS)),S(A(KC_MINS)),S(A(KC_MINS))}, // — ** need Win Compose via BCD?
    [SK_DCRS - SK_KILL] = {LSA(KC_7),LSA(KC_7),LSA(KC_7)}, // ‡ Double Cross ** need Win Compose via BCD?
    [SK_SCRS - SK_KILL] = {RSA(KC_5),RSA(KC_5),RSA(KC_5)}, // † Single Cross ** need Win Compose via BCD?
    [SK_BBLT - SK_KILL] = {LALT(KC_8),LALT(KC_8),LALT(KC_8)}, // • Bold Bullet ** need Win Compose via BCD?
        // Currency
    [SK_CENT - SK_KILL] = {LALT(KC_4),LALT(KC_4),LALT(KC_4)}, // ¢ ** need Win Compose via BCD?
    [SK_EURO - SK_KILL] = {A(S(KC_2)),A(S(KC_2)),A(S(KC_2))}, // € ** need Win Compose via BCD?
    [SK_BPND - SK_KILL] = {RALT(KC_3),RALT(KC_3),RALT(KC_3)}, // £ ** need Win Compose via BCD?
    [SK_JPY  - SK_KILL] = {LALT(KC_Y),LALT(KC_Y),LALT(KC_Y)},  // ¥ ** need Win Compose via BCD?
        // Quotations
    [SK_SQUL - SK_KILL] = {A(KC_RBRC),A(KC_RBRC),A(KC_RBRC)}, // ’ ** Left single quote UNICODE?
    [SK_SQUR - SK_KILL] = {S(A(KC_RBRC)),S(A(KC_RBRC)),S(A(KC_RBRC))}, // ’ ** Right single quote UNICODE?
//    [SK_SDQU - SK_KILL] = {KC_DQUO,KC_DQUO,KC_DQUO}, // " straight double-quote character
    [SK_SDQL - SK_KILL] = {A(KC_LBRC),A(KC_LBRC),A(KC_LBRC)}, // “ ** Left double quote UNICODE?
    [SK_SDQR - SK_KILL] = {A(S(KC_LBRC)),A(S(KC_LBRC)),A(S(KC_LBRC))}, // ” ** Right double quote UNICODE?
    [SK_FDQL - SK_KILL] = {A(KC_BSLS),A(KC_BSLS),A(KC_BSLS)}, //  « Left double French quote UNICODE?
    [SK_FDQR - SK_KILL] = {S(A(KC_BSLS)),S(A(KC_BSLS)),S(A(KC_BSLS))}, //  » Right double French quote UNICODE?
    [SK_FSQL - SK_KILL] = {S(A(KC_3)),A(KC_LBRC),A(KC_LBRC)}, //  ‹ Left single French quote UNICODE?
    [SK_FSQR - SK_KILL] = {S(A(KC_4)),A(S(KC_LBRC)),A(S(KC_LBRC))}, //  › Right single French quote UNICODE?

};

bool process_semkey(uint16_t keycode, const keyrecord_t *record) {
    // custom processing could hapen here
    uint8_t  saved_mods;
    if (keycode >= SK_KILL && keycode < SemKeys_COUNT) {
        saved_mods = get_mods();
        if (record->event.pressed) {
            switch (keycode) {
 //
 // handle multi-keystroke semkeys here
 //
                case SK_SWRD: // Select current word
                    tap_SemKey(SK_WORDPRV);
                    register_code(KC_LSFT); // shift for select is close to universal?
                    tap_SemKey(SK_WORDNXT); // of course, not for VIM and the like,
                    unregister_code(KC_LSFT); // but we're talking OS platforms?
                    break;
                case SK_ENYE: // ñ/Ñ ENYE
                    // Doing it this way until proper multi-keystroke table is implemented
                    if (user_config.AdaptiveKeys
#ifdef JP_MODE_ENABLE
                        && IS_ENGLISH_MODE
#endif
                        ) { // if  in English mode
                        clear_keyboard(); // clean record to tinker with.
                        tap_SemKey(SK_ENYE);
                        set_mods(saved_mods & MOD_MASK_SHIFT); // Preserve shift state
                        tap_code16(KC_N);
                        // set_mods(saved_mods); // restore mods just in case? (not necessary?)
#ifdef JP_MODE_ENABLE
                    } else { // (if in Japanese mode, send ん)
                        tap_code16(KC_N);  //
                        tap_code16(KC_N);  //
#endif
                    }
                    break;
                case SK_HENK: // Japanese
#ifdef JP_MODE_ENABLE
                    IS_ENGLISH_MODE = false;
#endif
                    tap_SemKey(SK_HENK); // Mac/Win/iOS all different?
//                    return_state = false; // stop processing this record.
                    break;
                case SK_MHEN: // English
#ifdef JP_MODE_ENABLE
                    IS_ENGLISH_MODE = true;
#endif
                    tap_SemKey(SK_MHEN); // Mac/Win/iOS/Lux all different?
//                    return_state = false; // stop processing this record.
                    break;
                default: // default keydown event (from the semkey table)
                    register_SemKey(keycode);
/* Add the BCD decode for Win compose key stuff here
 
*/
                    break;
            }
        } else { // The keyup event
            switch (keycode) {
                default:
                    unregister_SemKey(keycode);
                    break;
            }

        }
        return false; // don't do more with this record.
    }
    return true;
};
