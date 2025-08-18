/*
 Semantic Keys is a keystroke abstraction tool
 for platform independence.
 Simply swapping Gui/Cmd for Ctrl is insufficient.
 Anything that must be interpreted by the host
 in order to produce a glyph or keystroke(s) that issues a command,
 can be abstracted to a semantic function here, enabling
 host specific keystroke(s) to be sent as appropriate.
 
 Now nearly 80 Semantic Keys are enabled. Most populated
 on the keymaps either directly, or through combos or Adaptive Keys.
 These are all commands or symbols that might
 use different keystrokes on different host systems.

 Many extended commands & symbols can be executed or entered
 with identical keystrokes on the keyboard,
 without needing unicode support enabled on the host.

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

 Much thanks to Bryson Dodwell (b-dod on github,  u/praedatore)
 for completing phase 3 for WinCompose entry:
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

const uint16_t SemKeys_t[SK_count][OS_count] = {
// Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
        // System-wide controls

    [SK_ndx(SK_KILL)] = {LAG(KC_ESC),LCA(KC_DEL)},        // Force quit / ctrl-alt-del
    [SK_ndx(SK_HENK)] = {KC_LNG1, C(S(KC_1))},            // 変換/かな
    [SK_ndx(SK_MHEN)] = {KC_LNG2, C(S(KC_0))},            // 無変換/英数
    [SK_ndx(SK_DKT8)] = {C(S(KC_3)),G(KC_H)},             // Dictate speech to text
    [SK_ndx(SK_AIVC)] = {C(S(KC_4)),G(KC_C)},             // AI voice control (mac Siri/Win Cortana)
        // extended characters/ editing commands
    [SK_ndx(SK_HENT)] = {G(KC_ENT),C(KC_ENT)},            // Hard ENTER
    [SK_ndx(SK_UNDO)] = {G(KC_Z),C(KC_Z)},                // undo
    [SK_ndx(SK_REDO)] = {G(S(KC_Z)),C(S(KC_Z))},          // Redo
    [SK_ndx(SK_CUT )] = {G(KC_X),C(KC_X)},                // cut
    [SK_ndx(SK_COPY)] = {G(KC_C),C(KC_C)},                // copy
    [SK_ndx(SK_PSTE)] = {G(KC_V),C(KC_V)},                // paste
    [SK_ndx(SK_PSTM)] = {G(S(A(KC_V))),C(S(A(KC_V)))},    // paste_match
    [SK_ndx(SK_SALL)] = {G(KC_A),C(KC_A)},                // select all
    [SK_ndx(SK_CLOZ)] = {G(KC_W),C(KC_W)},                // close
    [SK_ndx(SK_QUIT)] = {G(KC_Q),C(KC_Q)},                // quit
    [SK_ndx(SK_NEW)]  = {G(KC_N),C(KC_N)},                  // new
    [SK_ndx(SK_OPEN)] = {G(KC_O),C(KC_O)},                // open
    [SK_ndx(SK_FIND)] = {G(KC_F),C(KC_F)},                // find
    [SK_ndx(SK_FAGN)] = {G(KC_G),C(KC_G)},                // find again
    [SK_ndx(SK_SCAP)] = {LSG(KC_4),KC_PSCR},              // Screen Capture
    [SK_ndx(SK_SCLP)] = {C(S(G(KC_4))),A(KC_PSCR)},       // Selection Capture
    [SK_ndx(SK_SRCH)] = {G(KC_SPC),G(KC_S)},              // platform search (siri/cortana, etc.)
    [SK_ndx(SK_DELWDL)] = {A(KC_BSPC),C(KC_BSPC)},        // DELETE WORD LEFT
    [SK_ndx(SK_DELWDR)] = {A(KC_DEL),C(KC_DEL)},          // DELETE WORD RIGHT
    [SK_ndx(SK_DELLNL)] = {G(KC_BSPC),C(KC_BSPC)},        // Delete line left of cursor
    [SK_ndx(SK_DELLNR)] = {G(KC_DEL),C(KC_DEL)},          // Delete line right of cursor
        // extended navigation
    [SK_ndx(SK_WORDPRV)] = {A(KC_LEFT),C(KC_LEFT)},       // WORD LEFT
    [SK_ndx(SK_WORDNXT)] = {A(KC_RIGHT),C(KC_RIGHT)},     // WORD RIGHT
    [SK_ndx(SK_DOCBEG)] = {G(KC_UP),C(KC_HOME)},          // Go to start of document
    [SK_ndx(SK_DOCEND)] = {G(KC_DOWN),C(KC_END)},         // Go to end of document
    [SK_ndx(SK_LINEBEG)] = {G(KC_DOWN),C(KC_END)},        // Go to beg of line
    [SK_ndx(SK_LINEEND)] = {G(KC_DOWN),C(KC_END)},        // Go to end of line
    [SK_ndx(SK_PARAPRV)] = {A(KC_UP),C(KC_UP)},           // Go to previous paragraph
    [SK_ndx(SK_PARANXT)] = {A(KC_DOWN),C(KC_DOWN)},       // Go to next paragraph
    [SK_ndx(SK_HISTPRV)] = {G(KC_LBRC),A(KC_LEFT)},       // BROWSER BACK
    [SK_ndx(SK_HISTNXT)] = {G(KC_RBRC),A(KC_RIGHT)},      // BROWSER FWD
    [SK_ndx(SK_ZOOMIN)] = {G(KC_EQL),C(KC_EQL)},          // ZOOM IN
    [SK_ndx(SK_ZOOMOUT)] = {G(KC_MINS),C(KC_MINS)},       // ZOOM OUT
    [SK_ndx(SK_ZOOMRST)] = {G(KC_0),C(KC_0)},             // ZOOM RESET
    [SK_ndx(SK_APPNXT)] = {G(KC_TAB),A(KC_TAB)},          // APP switcher Next (last used)
    [SK_ndx(SK_APPPRV)] = {RSG(KC_TAB),LSA(KC_TAB)},      // APP switcher Prev (least recently used)
    [SK_ndx(SK_WINNXT)] = {C(KC_TAB),C(KC_TAB)},          // Window/tab switcher Next
    [SK_ndx(SK_WINPRV)] = {C(S(KC_TAB)),C(S(KC_TAB))},    // Window/tab switcher Prev
        // Punctuation & typography
    [SK_ndx(SK_NDSH)] = {A(KC_MINS),0x8150},              // – N-Dash 
    [SK_ndx(SK_MDSH)] = {LSA(KC_MINS),0x8151},            // — M-Dash
    [SK_ndx(SK_ELPS)] = {A(KC_SCLN),0x8133},              // … 
    [SK_ndx(SK_SCRS)] = {LSA(KC_5),0x8134},               // † Single Cross 
    [SK_ndx(SK_DCRS)] = {LSA(KC_7),0x8135},               // ‡ Double Cross 
    [SK_ndx(SK_BBLT)] = {A(KC_8),0x8149},                 // • Bold Bullet 
    [SK_ndx(SK_SBLT)] = {LSA(KC_9),0x8183},               // · Small Bullet 
    [SK_ndx(SK_PARA)] = {A(KC_7),0x8182},                 // ¶ 
    [SK_ndx(SK_SECT)] = {A(KC_5),0x8167},                 // §
        // Number & Math symbols
    [SK_ndx(SK_PERM)] = {LSA(KC_R),0x8137},               // ‰ Per Mille
    [SK_ndx(SK_DEGR)] = {LSA(KC_8),0x8176},               // ° DEGREE
    [SK_ndx(SK_GTEQ)] = {A(KC_DOT),0x4242},               // ≥ Greater Than or Equal to
    [SK_ndx(SK_LTEQ)] = {A(KC_COMM),0x4243},              // ≤ Less Than or Equal to
    [SK_ndx(SK_PLMN)] = {LSA(KC_EQL),0x8177},             // ± Plus/Minus
    [SK_ndx(SK_DIV) ] = {A(KC_SLSH),0x4246},              // ÷ Divide
    [SK_ndx(SK_FRAC)] = {LSA(KC_1),0x4246},               // ⁄ Fraction "Solidus" symbol
    [SK_ndx(SK_NOTEQ)] = {A(KC_EQL),ALGR(KC_EQL)},        // ≠ NOT Equal to
    [SK_ndx(SK_APXEQ)] = {A(KC_X),0x4247},                // ≈ APPROX Equal to
    [SK_ndx(SK_OMEGA)] = {A(KC_Z),0x4234},                // Ω OMEGA
        // Currency
    [SK_ndx(SK_EURO)] = {LSA(KC_2),0x8128},               // € 
    [SK_ndx(SK_CENT)] = {A(KC_4),0x8162},                 // ¢ 
    [SK_ndx(SK_BPND)] = {A(KC_3),0x8163},                 // £ 
    [SK_ndx(SK_JPY )] = {A(KC_Y),0x8165},                 // ¥
    [SK_ndx(SK_No  )] = {LSA(KC_SCLN),0x8470},            // № ordinal number symbol *wrong alt code*
        // Quotations
    [SK_ndx(SK_SQUL)] = {A(KC_RBRC),0x8145},              // ’ ** Left single quote 
    [SK_ndx(SK_SQUR)] = {LSA(KC_RBRC),0x8146},            // ’ ** Right single quote 
    [SK_ndx(SK_SDQL)] = {A(KC_LBRC),0x8147},              // “ ** Left double quote 
    [SK_ndx(SK_SDQR)] = {LSA(KC_LBRC),0x8148},            // ” ** Right double quote 
    [SK_ndx(SK_FDQL)] = {A(KC_BSLS),0x8171},              // « Left double French quote 
    [SK_ndx(SK_FDQR)] = {LSA(KC_BSLS),0x8187},            // » Right double French quote 
    [SK_ndx(SK_FSQL)] = {LSA(KC_3),0x8139},               // ‹ Left single French quote 
    [SK_ndx(SK_FSQR)] = {LSA(KC_4),0x8155},               // › Right single French quote 
    [SK_ndx(SK_IQUE)] = {LSA(KC_SLASH),0x8191},           // ¿ Spanish inverted Question Mark
    [SK_ndx(SK_IEXC)] = {A(KC_1),0x8161},                 // ¡ Spanish inverted Exclamation Mark
        // Composed letters with diacritics
    [SK_ndx(SK_ENYE)] = {A(KC_N),ALGR(KC_N)}             // ñ/Ñ 
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
void send_alt_code(uint16_t sk) {

    if (sk & 0x8000) {
    // Always start with numpad 0 if semkeycode starts with 0x8
    tap_code(KC_P0);
    }

    // Extract & send digits using keypad keys
    tap_code((sk >> 8) & 0x0F ? KC_P0 - ((10 - (sk >> 8)) & 0x0F) : KC_P0);
    tap_code((sk >> 4) & 0x0F ? KC_P0 - ((10 - (sk >> 4)) & 0x0F) : KC_P0);
    tap_code((sk >> 0) & 0x0F ? KC_P0 - ((10 - (sk >> 0)) & 0x0F) : KC_P0);

};

void tap_SemKey(uint16_t sk) {
    uint16_t semkeycode = get_SemKeyCode(sk);

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
    uint16_t semkeycode = get_SemKeyCode(sk);
    
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
    uint16_t semkeycode = get_SemKeyCode(sk);
    
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
    if (!(is_SemKey(keycode)))
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
