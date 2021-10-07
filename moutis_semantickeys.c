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
enum SemKeys {
    SK_KILL,
    SK_UNDO,
    SK_CUT,
    SK_COPY,
    SK_PSTE,
    SK_PSTM,
    SK_SALL,
    SK_CLOZ,
    SK_QUIT,
    SK_FIND,
    SK_FAGN,
    SK_SCAP,
    SK_SCLP,
    SK_SECT,

    SK_GRAV_E,
    SK_ACUT_E,
    SK_DIER_E,
    SK_RING_E,
    SK_MACR_E,

    SemKeys_COUNT
};
*/

enum SemKeys_OS {
    SKP_Mac,
    SKP_Min,
    SemKeys_OS_COUNT
};
/*
* based on the table at:
* https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
* tested on my own machines, seems to work fine.
*
*/

const uint16_t SemKeys_t[SemKeys_COUNT - SK_KILL][SemKeys_OS_COUNT] = {
    // Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
    [SK_KILL - SK_KILL] = {G(A(KC_ESC)),C(A(KC_DEL))}, // "KILL" OR Force quit / ctrl-alt-del
    [SK_UNDO - SK_KILL] = {G(KC_Z),C(KC_Z)}, // undo
    [SK_CUT  - SK_KILL] = {G(KC_X),C(KC_X)}, // cut
    [SK_COPY - SK_KILL] = {G(KC_C),C(KC_C)}, // copy
    [SK_PSTE - SK_KILL] = {G(KC_V),C(KC_V)}, // paste
    [SK_PSTM - SK_KILL] = {G(S(A(KC_V))),C(S(A(KC_V)))}, // paste_match
    [SK_SALL - SK_KILL] = {G(KC_A),C(KC_A)}, // select all
    [SK_CLOZ - SK_KILL] = {G(KC_W),C(KC_W)}, // close
    [SK_QUIT - SK_KILL] = {G(KC_Q),C(KC_Q)}, // quit
    [SK_FIND - SK_KILL] = {G(KC_F),C(KC_F)}, // find
    [SK_FAGN - SK_KILL] = {G(KC_G),KC_F3}, // find again
    [SK_SCAP - SK_KILL] = {S(G(KC_4)),KC_PSCR}, // Screen Capture
    [SK_SCLP - SK_KILL] = {C(S(G(KC_4))),A(KC_PSCR)}, // Selection Capture))
    [SK_DELWDL - SK_KILL] = {A(KC_BSPC),C(KC_BSPC)}, // DELETE WORD LEFT
    [SK_DELWDR - SK_KILL] = {A(KC_DEL),C(KC_DEL)}, // DELETE WORD RIGHT
    [SK_WORDPRV - SK_KILL] = {A(KC_LEFT),C(KC_LEFT)}, // WORD LEFT
    [SK_WORDNXT - SK_KILL] = {A(KC_RIGHT),C(KC_RIGHT)}, // WORD RIGHT
    [SK_DOCBEG - SK_KILL] = {G(KC_UP),C(KC_HOME)}, // Go to start of document
    [SK_DOCEND - SK_KILL] = {G(KC_DOWN),C(KC_END)}, // Go to end of document
    [SK_LINEBEG - SK_KILL] = {G(KC_DOWN),C(KC_END)}, // Go to beg of line
    [SK_LINEEND - SK_KILL] = {G(KC_DOWN),C(KC_END)}, // Go to end of line
    [SK_PARAPRV - SK_KILL] = {A(KC_UP),C(KC_UP)}, // Go to previous paragraph
    [SK_PARANXT - SK_KILL] = {A(KC_DOWN),C(KC_DOWN)}, // Go to next paragraph
    [SK_HISTPRV - SK_KILL] = {G(KC_LBRC),A(KC_LEFT)}, // BROWSER BACK
    [SK_HISTNXT - SK_KILL] = {G(KC_RBRC),A(KC_RIGHT)}, // BROWSER FWD
    [SK_ZOOMIN - SK_KILL] = {G(S(KC_EQL)),C(KC_EQL)}, // ZOOM IN
    [SK_ZOOMOUT - SK_KILL] = {G(KC_MINS),C(KC_MINS)}, // ZOOM OUT
    [SK_ZOOMRST - SK_KILL] = {G(KC_0),C(KC_0)}, // ZOOM RESET
    [SK_SECT - SK_KILL] = {A(KC_5),A(KC_5)}, // § ** SAMPLE OF GLYPH. REALLY NEED UNICODE.

};

bool process_semkey(uint16_t keycode, const keyrecord_t *record) {
    // custom processing could hapen here
    if (keycode >= SK_KILL && keycode < SemKeys_COUNT) {
        if (record->event.pressed) {
            switch (keycode) {
/*
 //
 // demonstrator. can handle multi-keystrokes here
 //
                case SK_umluatU: // Ü
                    tap_code16(A(KC_U));
                    tap_code16(KC_U);
                   break;
                case SK_umluatO: // Ö
                    tap_code16(A(KC_U));
                    tap_code16(KC_O);
                    break;
                case SK_ringU: // Ů
                    tap_code16(A(KC_K));
                    tap_code16(KC_U);
                    break;
                case SK_ringO: //
                    tap_code16(A(KC_K));
                    tap_code16(KC_O);
                    break;
                case SK_caretU: // Û
                    tap_code16(A(KC_6));
                    tap_code16(KC_U);
                   break;
                case SK_caretO: // Ô
                    tap_code16(A(KC_6));
                    tap_code16(KC_O);
                    break;
                case SK_acuteU: // Ú
                    tap_code16(A(KC_E));
                    tap_code16(KC_U);
                    break;
                case SK_acuteO: // Ó
                    tap_code16(A(KC_E));
                    tap_code16(KC_O);
                    break;

                case SK_acuteE: // É
                    tap_code16(A(KC_E));
                    tap_code16(KC_E);
                    break;
                case SK_macronE: // Ē
                    tap_code16(A(KC_A));
                    tap_code16(KC_O);
                    break;
                case SK_caretE: // Ê
                    tap_code16(A(KC_6));
                    tap_code16(KC_E);
                    break;
*/
/*
    Example of custom behaviors.
 */
                case SK_SCAP:
                    tap_SemKey(SK_SCAP);
                    break;
                case SK_SCLP:
                    tap_SemKey(SK_SCLP);
                    break;
                case SK_CUT:
                    tap_SemKey(SK_CUT);
                    break;
                case SK_COPY:
                    tap_SemKey(SK_COPY);
                    break;
                default: // default keydown event
                    register_SemKey(keycode);
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
