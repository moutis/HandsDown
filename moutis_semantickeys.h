#pragma once

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
    complete.
 
 Phase 3: expand to multi-keystrokes, which would enable sending
 different compose sequences based on platform (diacritics),
 and possibly facilitate support for other editors (vim/emacs)?
 
 Phase 4: use in Hands Down Polyglot for all non-ascii glyphs
 
 */

#define tap_SemKey(sk) tap_code16(SemKeys_t[sk - SK_KILL][OSIndex])
#define register_SemKey(sk) register_code16(SemKeys_t[sk - SK_KILL][OSIndex])
#define unregister_SemKey(sk) unregister_code16(SemKeys_t[sk - SK_KILL][OSIndex])

