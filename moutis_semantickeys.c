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
/*
    SK_GRAV_E,
    SK_ACUT_E,
    SK_DIER_E,
    SK_RING_E,
    SK_MACR_E,
*/
    SemKeys_COUNT
};

enum SemKeys_OS {
    SKP_Mac,
    SKP_Min,
    SemKeys_OS_COUNT
};

const uint16_t SemKeys_t[SemKeys_COUNT][SemKeys_OS_COUNT] = {
    // Mac, Win, (Phase 3, add others if necessary, expand to multi-key?)
    [SK_KILL] = {G(A(KC_ESC)),C(A(KC_DEL))}, // "KILL" OR Force quit / ctrl-alt-del
    [SK_UNDO] = {G(KC_Z),C(KC_Z)}, // undo
    [SK_CUT ] = {G(KC_X),C(KC_X)}, // cut
    [SK_COPY] = {G(KC_C),C(KC_C)}, // copy
    [SK_PSTE] = {G(KC_V),C(KC_V)}, // paste
    [SK_PSTM] = {G(S(A(KC_V))),C(S(A(KC_V)))}, // paste_match
    [SK_SALL] = {G(KC_A),C(KC_C)}, // select all
    [SK_CLOZ] = {G(KC_W),C(KC_W)}, // close
    [SK_QUIT] = {G(KC_Q),C(KC_Q)}, // quit
    [SK_FIND] = {G(KC_F),C(KC_F)}, // find
    [SK_FAGN] = {G(KC_G),C(KC_G)}, // find again
    [SK_SCAP] = {S(G(KC_4)),KC_PSCR}, // Screen Capture
    [SK_SCLP] = {C(S(G(KC_4))),A(KC_PSCR)}, // Selection Capture
    [SK_SECT] = {A(KC_5),A(KC_5)}, // §


};

