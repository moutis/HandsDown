/*
 Semantic Keys is as STUB for platform independence. Anything
 that must be interpreted by the host, in order to produce a glyph
 or keystroke(s) that issues a command, can be abstracted to a
 semantic function here, enabling platform specific keystroke(s)
 to be sent as appropriate.

 Phase 1:
    simple 1:1 keystroke mapping
   -- complete.
 
 Phase 2:
 Integrate all combo and keymap processing so they both queue
 SemKeys to be handled in process_record_user, reducing the code
 and simplifying maintenance.
  -- complete
 
 Phase 3:
 Expand to multi-keystrokes, which would enable sending
 different compose sequences based on platform (diacritics),
 and possibly facilitate editor support (vim/emacs)?
  -- complete
 
 Now more than 70 Semantic Keys are enabled. Most populated on the Keymaps either directly,
 or through combos or Adaptive Keys.

 Many extended commands & symbols can be executed or entered with identical keystrokes on the keyboard,
 without needing unicode support enabled on the host.

 Much thanks to Bryson Dodwell (b-dod on github,  u/praedatore)
 for help completing phase 3 for WinCompose entry:
 https://github.com/b-dod/zsa-firmware/b-dod/moutis_semantickeys.c

 Phase 4:
 In use in most Hands Down variations in this repo. Next step would be
 to use it in Hands Down Polyglot for PanEuropean multi-platform layout
  -- research proposal in the works.



 SemKeys_t table below is a uint16 keycode, unless MSB is high, then it
 is BCD of the 4·3·2 digit Windows/DOS character codes for AltGr compose.

  based on the table at:
  https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
  and
  https://www.alt-codes.net
  tested on my own machines, seems to work fine.
 
*/

const uint16_t SemKeys_t[SemKeys_COUNT - SK_KILL][OS_count] = {
// Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
        // System-wide controls
    [SK_KILL - SK_KILL] = {G(A(KC_ESC)),C(A(KC_DEL))},      // Force quit / ctrl-alt-del
    [SK_HENK - SK_KILL] = {KC_LNG1, C(S(KC_1))},            // 変換/かな
    [SK_MHEN - SK_KILL] = {KC_LNG2, C(S(KC_0))},            // 無変換/英数
    [SK_DKT8 - SK_KILL] = {C(S(KC_3)),G(KC_H)},             // Dictate speech to text
    [SK_AIVC - SK_KILL] = {C(S(KC_4)),G(KC_C)},             // AI voice control (mac Siri/Win Cortana)
        // extended characters/ editing commands
    [SK_HENT - SK_KILL] = {G(KC_ENT),C(KC_ENT)},            // Hard ENTER
    [SK_UNDO - SK_KILL] = {G(KC_Z),C(KC_Z)},                // undo
    [SK_REDO - SK_KILL] = {G(S(KC_Z)),C(S(KC_Z))},          // Redo
    [SK_CUT  - SK_KILL] = {G(KC_X),C(KC_X)},                // cut
    [SK_COPY - SK_KILL] = {G(KC_C),C(KC_C)},                // copy
    [SK_PSTE - SK_KILL] = {G(KC_V),C(KC_V)},                // paste
    [SK_PSTM - SK_KILL] = {G(S(A(KC_V))),C(S(A(KC_V)))},    // paste_match
    [SK_SALL - SK_KILL] = {G(KC_A),C(KC_A)},                // select all
    [SK_CLOZ - SK_KILL] = {G(KC_W),C(KC_W)},                // close
    [SK_QUIT - SK_KILL] = {G(KC_Q),C(KC_Q)},                // quit
    [SK_NEW - SK_KILL] = {G(KC_N),C(KC_N)},                 // new
    [SK_OPEN - SK_KILL] = {G(KC_O),C(KC_O)},                // open
    [SK_FIND - SK_KILL] = {G(KC_F),C(KC_F)},                // find
    [SK_FAGN - SK_KILL] = {G(KC_G),C(KC_G)},                // find again
    [SK_SCAP - SK_KILL] = {S(G(KC_4)),KC_PSCR},             // Screen Capture
    [SK_SCLP - SK_KILL] = {C(S(G(KC_4))),A(KC_PSCR)},       // Selection Capture
    [SK_SRCH - SK_KILL] = {G(KC_SPC),G(KC_S)},              // platform search (siri/cortana, etc.)
    [SK_DELWDL - SK_KILL] = {A(KC_BSPC),C(KC_BSPC)},        // DELETE WORD LEFT
    [SK_DELWDR - SK_KILL] = {A(KC_DEL),C(KC_DEL)},          // DELETE WORD RIGHT
    [SK_DELLNL - SK_KILL] = {G(KC_BSPC),C(KC_BSPC)},        // Delete line left of cursor
    [SK_DELLNR - SK_KILL] = {G(KC_DEL),C(KC_DEL)},          // Delete line right of cursor
        // extended navigation
    [SK_WORDPRV - SK_KILL] = {A(KC_LEFT),C(KC_LEFT)},       // WORD LEFT
    [SK_WORDNXT - SK_KILL] = {A(KC_RIGHT),C(KC_RIGHT)},     // WORD RIGHT
    [SK_DOCBEG - SK_KILL] = {G(KC_UP),C(KC_HOME)},          // Go to start of document
    [SK_DOCEND - SK_KILL] = {G(KC_DOWN),C(KC_END)},         // Go to end of document
    [SK_LINEBEG - SK_KILL] = {G(KC_DOWN),C(KC_END)},        // Go to beg of line
    [SK_LINEEND - SK_KILL] = {G(KC_DOWN),C(KC_END)},        // Go to end of line
    [SK_PARAPRV - SK_KILL] = {A(KC_UP),C(KC_UP)},           // Go to previous paragraph
    [SK_PARANXT - SK_KILL] = {A(KC_DOWN),C(KC_DOWN)},       // Go to next paragraph
    [SK_HISTPRV - SK_KILL] = {G(KC_LBRC),A(KC_LEFT)},       // BROWSER BACK
    [SK_HISTNXT - SK_KILL] = {G(KC_RBRC),A(KC_RIGHT)},      // BROWSER FWD
    [SK_ZOOMIN - SK_KILL] = {G(KC_EQL),C(KC_EQL)},          // ZOOM IN
    [SK_ZOOMOUT - SK_KILL] = {G(KC_MINS),C(KC_MINS)},       // ZOOM OUT
    [SK_ZOOMRST - SK_KILL] = {G(KC_0),C(KC_0)},             // ZOOM RESET
    [SK_APPNXT - SK_KILL] = {G(KC_TAB),A(KC_TAB)},          // APP switcher Next (last used)
    [SK_APPPRV - SK_KILL] = {G(RSFT(KC_TAB)),A(S(KC_TAB))}, // APP switcher Prev (least recently used)
    [SK_WINNXT - SK_KILL] = {C(KC_TAB),C(KC_TAB)},          // Window/tab switcher Next
    [SK_WINPRV - SK_KILL] = {C(S(KC_TAB)),C(S(KC_TAB))},    // Window/tab switcher Prev
        // Punctuation & typography
    [SK_NDSH - SK_KILL] = {S(A(KC_MINS)),0x8150},           // — N-Dash ** need Win Compose via BCD?
    [SK_MDSH - SK_KILL] = {S(A(KC_MINS)),0x8151},           // — M-Dash ** need Win Compose via BCD?
    [SK_ELPS - SK_KILL] = {A(KC_SCLN),0x8133},              // … ** need Win Compose via BCD?
    [SK_SCRS - SK_KILL] = {RSA(KC_5),0x8134},               // † Single Cross ** need Win Compose via BCD?
    [SK_DCRS - SK_KILL] = {LSA(KC_7),0x8135},               // ‡ Double Cross ** need Win Compose via BCD?
    [SK_BBLT - SK_KILL] = {A(KC_8),0x8149},                 // • Bold Bullet ** need Win Compose via BCD?
    [SK_SBLT - SK_KILL] = {A(S(KC_9)),0x8183},              // · Small Bullet ** need Win Compose via BCD?
    [SK_PARA - SK_KILL] = {A(KC_7),0x8182},                 // ¶ ** need Win Compose via BCD?
    [SK_SECT - SK_KILL] = {A(KC_5),0x8167},                 // § ** need Win Compose via BCD.
        // Number & Math symbols
    [SK_DEGR - SK_KILL] = {S(A(KC_8)),0x8176},              // ° DEGREE
    [SK_GTEQ - SK_KILL] = {A(KC_DOT),0x4242},               // ≥ Greater Than or Equal to
    [SK_LTEQ - SK_KILL] = {A(KC_COMM),0x4243},              // ≤ Less Than or Equal to
    [SK_PLMN - SK_KILL] = {A(S(KC_EQL)),0x8177},            // ± Plus/Minus
    [SK_NOTEQ - SK_KILL] = {LALT(KC_EQL),ALGR(KC_EQL)},     // ≠ NOT Equal to ** need Win Compose via ?????
    [SK_APXEQ - SK_KILL] = {LALT(KC_X),0x4247},             // ≈ APPROX Equal to
    [SK_OMEGA - SK_KILL] = {LALT(KC_Z),0x4234},             // Ω OMEGA
        // Currency
    [SK_EURO - SK_KILL] = {A(S(KC_2)),0x8128},              // € ** need Win Compose via BCD?
    [SK_CENT - SK_KILL] = {LALT(KC_4),0x8162},              // ¢ ** need Win Compose via BCD?
    [SK_BPND - SK_KILL] = {A(KC_3),0x8163},                 // £ ** need Win Compose via BCD?
    [SK_JPY  - SK_KILL] = {A(KC_Y),0x8165},                 // ¥ ** need Win Compose via BCD?
        // Quotations
    [SK_SQUL - SK_KILL] = {A(KC_RBRC),0x8145},              // ’ ** Left single quote UNICODE?
    [SK_SQUR - SK_KILL] = {S(A(KC_RBRC)),0x8146},           // ’ ** Right single quote UNICODE?
    [SK_SDQL - SK_KILL] = {A(KC_LBRC),0x8147},              // “ ** Left double quote UNICODE?
    [SK_SDQR - SK_KILL] = {A(S(KC_LBRC)),0x8148},           // ” ** Right double quote UNICODE?
    [SK_FDQL - SK_KILL] = {A(KC_BSLS),0x8171},              // « Left double French quote UNICODE?
    [SK_FDQR - SK_KILL] = {S(A(KC_BSLS)),0x8187},           // » Right double French quote UNICODE?
    [SK_FSQL - SK_KILL] = {S(A(KC_3)),0x8139},              // ‹ Left single French quote UNICODE?
    [SK_FSQR - SK_KILL] = {S(A(KC_4)),0x8155},              // › Right single French quote UNICODE?
    [SK_IQUE - SK_KILL] = {S(A(KC_SLASH)),0x8191},          // ¿ Spanish inverted Question Mark
    [SK_IEXC - SK_KILL] = {A(KC_1),0x8161},                 // ¡ Spanish inverted Exclamation Mark
        // Composed letters with diacritics
    [SK_ENYE - SK_KILL] = {A(KC_N),ALGR(KC_N)},             // ñ/Ñ ** need Win Compose via BCD?
/* Eventually… all these should be handled as SemKeys as well?
    HD_aumlt,
    HD_amacr,
    HD_aacut,
    HD_acrcm,
    HD_agrav,

    HD_eumlt,
    HD_emacr,
    HD_eacut,
    HD_ecrcm,
    HD_egrav,

    HD_iumlt,
    HD_imacr,
    HD_iacut,
    HD_icrcm,
    HD_igrav,

    HD_oumlt,
    HD_omacr,
    HD_oacut,
    HD_ocrcm,
    HD_ograv,

    HD_uumlt,
    HD_umacr,
    HD_uacut,
    HD_ucrcm,
    HD_ugrav
*/

};
void send_alt_code(uint16_t semkeycode) {

    if (semkeycode & 0x8000) {
    // Always start with numpad 0 if semkeycode starts with 0x8
    tap_code(KC_P0);
    }

    // Extract & send digits using keypad keys
    tap_code((semkeycode >> 8) & 0x0F ? KC_P0 - ((10 - (semkeycode >> 8)) & 0x0F) : KC_P0);
    tap_code((semkeycode >> 4) & 0x0F ? KC_P0 - ((10 - (semkeycode >> 4)) & 0x0F) : KC_P0);
    tap_code((semkeycode >> 0) & 0x0F ? KC_P0 - ((10 - (semkeycode >> 0)) & 0x0F) : KC_P0);

};

void tap_SemKey(uint16_t sk) {
    uint16_t semkeycode = SemKeys_t[sk - SK_KILL][user_config.OSIndex];

    if ((semkeycode & 0x8000) || (semkeycode & 0x4000)) {
        clear_keyboard();           // must have clean buffer.
        register_code(KC_LALT);     // hold Left Alt

        send_alt_code(semkeycode); // send 3 or 4-digit alt code

        unregister_code(KC_LALT);    // release Left Alt

    } else {
        tap_code16(semkeycode);      // regular keycode
    }
};

void register_SemKey(uint16_t sk) {
    uint16_t semkeycode = SemKeys_t[sk - SK_KILL][user_config.OSIndex];
    if ((semkeycode & 0x8000) || (semkeycode & 0x4000)) {
        clear_keyboard();           // must have clean buffer.
        register_code(KC_LALT);     // hold Left Alt

        send_alt_code(semkeycode); // send 3 or 4-digit alt code

        // Alt must stay held here

    } else {
        register_code16(semkeycode);
    }
};

void unregister_SemKey(uint16_t sk) {
    uint16_t semkeycode = SemKeys_t[sk - SK_KILL][user_config.OSIndex];
    if ((semkeycode & 0x8000) || (semkeycode & 0x4000)) {
        // Release Alt to finish Unicode input
        unregister_code(KC_LALT);
    } else {
        unregister_code16(semkeycode);
    }
};

bool process_semkey(uint16_t keycode, const keyrecord_t *record) {
    // custom processing could hapen here
    uint8_t  held_mods;
    if (keycode < SK_KILL || keycode >= SemKeys_COUNT)
        return true; // nothing to do. continue processing this record
    
    held_mods = get_mods();
    if (record->event.pressed) {
        switch (keycode) {
#ifdef SK_DELLINE
            case SK_WORDPRV: //
                if (!(held_mods && MOD_MASK_GUI))
                    register_SemKey(SK_WORDPRV);
                else
                    register_SemKey(SK_LINEBEG);
                break;
            case SK_WORDNXT: //
                if (!(held_mods && MOD_MASK_GUI))
                    register_SemKey(SK_WORDNXT);
                else
                    register_SemKey(SK_LINEEND);
                break;
            case SK_DELWDL: //
                if (!(held_mods && MOD_MASK_GUI))
                    register_SemKey(SK_DELLNL);
                else
                    register_SemKey(SK_DELLNL);
                break;
            case SK_DELWDR: //
                if (!(held_mods && MOD_MASK_GUI))
                    register_SemKey(SK_DELLNR);
                else
                    register_SemKey(SK_DELLNR);
                break;
#endif // SK_DELLINE
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
                    set_mods(held_mods & MOD_MASK_SHIFT); // Preserve shift state
                    tap_code16(KC_N);
                    // set_mods(held_mods); // restore mods just in case? (not necessary?)
#ifdef JP_MODE_ENABLE
                } else { // (if in Japanese mode, send ん)
                    tap_code16(KC_N);  //
                    tap_code16(KC_N);  //
#endif // JP_MODE_ENABLE
                }
                break;
            case SK_HENK: // Japanese
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = false;
                L_quote = JLQU; // 「 in Japanese mode
                R_quote = JRQU; // 」in Japanese mode
#endif
                tap_SemKey(SK_HENK); // Mac/Win/iOS all different?
//                    return_state = false; // stop processing this record.
                break;
            case SK_MHEN: // English
#ifdef JP_MODE_ENABLE
                IS_ENGLISH_MODE = true;
                L_quote = KC_DQUO; // " in English mode
                R_quote = KC_LBRC; // ' in English mode
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
#ifdef SK_DELLINE
            case SK_WORDPRV: //
                if (!(held_mods && MOD_MASK_GUI))
                    unregister_SemKey(SK_WORDPRV);
                else
                    unregister_SemKey(SK_LINEBEG);
                break;
            case SK_WORDNXT: //
                if (!(held_mods && MOD_MASK_GUI))
                    unregister_SemKey(SK_WORDNXT);
                else
                    unregister_SemKey(SK_LINEEND);
                break;
            case SK_DELWDL: //
                if (!(held_mods && MOD_MASK_GUI))
                    unregister_SemKey(SK_DELLNL);
                else
                    unregister_SemKey(SK_DELLNL);
                break;
            case SK_DELWDR: //
                if (!(held_mods && MOD_MASK_GUI))
                    unregister_SemKey(SK_DELLNR);
                else
                    unregister_SemKey(SK_DELLNR);
                break;
#endif // SK_DELLINE
            default:
                unregister_SemKey(keycode);
                break;
        }

    }
    return false; // don't do more with this record.
};
