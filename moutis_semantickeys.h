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


enum my_keycodes {
    SK_KILL = SAFE_RANGE, // SK_KILL must be the first of contiguous block of SKs
    SK_HENK,
    SK_MHEN,
    SK_HENT, // Hard-Enter
    SK_UNDO, // undo
    SK_CUT, // cut
    SK_COPY, // copy
    SK_PSTE, // paste
    SK_PSTM, // paste_match
    SK_SALL, // select all
    SK_SWRD, // select current word
    SK_CLOZ, // close
    SK_QUIT, // quit
    SK_FIND, // find
    SK_NEW, // new
    SK_OPEN, // open
    SK_FAGN, // find again
    SK_SCAP, // screen capture to clipboard
    SK_SCLP, // selection capture to clipboard
    SK_DELWDL, // Delete word left of cursor
    SK_DELWDR, // Delete word right of cursor
    
    SK_WORDPRV, // WORD LEFT
    SK_WORDNXT, // WORD RIGHT
    SK_DOCBEG, // Go to start of document
    SK_DOCEND, // Go to end of document
    SK_LINEBEG, // Go to beg of line
    SK_LINEEND, // Go to end of line
    SK_PARAPRV, // Go to previous paragraph
    SK_PARANXT, // Go to next paragraph
    SK_HISTPRV, // BROWSER BACK
    SK_HISTNXT, // BROWSER FWD
    SK_ZOOMIN, // ZOOM IN
    SK_ZOOMOUT, // ZOOM OUT
    SK_ZOOMRST, // ZOOM RESET
    SK_APPNXT, // APP switcher Next (last used)
    SK_APPPRV, // APP switcher Prev (least recently used)
    SK_WINNXT, // Window/tab switcher Next
    SK_WINPRV, // Window/tab switcher Prev
    SK_SECT, // §
    SK_ENYE, // ñ/Ñ ENYE
    SK_SQUL, // ’ ** Left single quote UNICODE?
    SK_SQUR, // ’ ** Right single quote UNICODE?
    SK_SDQL, // ’ ** Left double quote UNICODE?
    SK_SDQR, // ’ ** Right double quote UNICODE?
    SemKeys_COUNT, // end of non-glyph SemKeys
    HD_AdaptKeyToggle,
//#ifdef L_QWERTY
     HD_L_QWERTY,
//#endif
#ifdef L_HDNUE
     HD_L_Neu,
#endif
#ifdef L_HDBRONZE
    HD_L_Bronze,  // KC to switch default layout
#endif
#ifdef L_HDSILVER
     HD_L_Silver,
#endif
#ifdef L_HDPLATINUM
     HD_L_Platinum,
#endif
#ifdef L_HDGOLD
     HD_L_Gold,
#endif
//#ifdef L_HDTITANIUM
    HD_L_Titanium,
//#endif
#ifdef L_HDRHODIUM
    HD_L_Rhodium,
#endif


/* Eventually…these should be handled as SemKeys?
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

#define L_BASELAYER HD_L_QWERTY

#define tap_SemKey(sk) tap_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])
#define register_SemKey(sk) register_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])
#define unregister_SemKey(sk) unregister_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])

