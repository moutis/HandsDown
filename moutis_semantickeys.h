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
    HD_AdaptKeyToggle = SAFE_RANGE, // Adaptive Keys Toggle on/off
    HD_L_QWERTY, // base layer switch
    HD_L_ALPHA,
#ifdef RGBLIGHT_ENABLE  // backlight/underglow
    HD_RGB_sat_up, // Sat +
    HD_RGB_sat_dn, // Sat -
    HD_RGB_hue_up, // Hue +
    HD_RGB_hue_dn, // Hue +
#endif
    SK_Mac,
    SK_Win,
    SK_Lux,
    // Semantic Keys (keystrokes handled by process_semkey() for platform independence)
    SK_KILL, // SK_KILL must be the first of contiguous block of SKs
    SK_HENK,  // kana (others)
    SK_MHEN, // eisuu (others)
    SK_HENT, // Hard-Enter
    SK_UNDO, // undo
    SK_REDO, // redo
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
//    SK_DEL,   // Delete char right of cursor
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
        // Punctuation
    SK_SECT, // § Section symbol
    SK_ENYE, // ñ/Ñ ENYE
    SK_IEXC, // ¡ Inverted exclamation mark
    SK_ELPS, // … Elipsis
    SK_PARA, // ¶ Paragraph symbol
    SK_MDSH, // — M-Dash
    SK_DCRS, // ‡ Double Cross
    SK_SCRS, // † Single Cross
    SK_BBLT, // • Bold Bullet
        // Currency
    SK_CENT, // ¢
    SK_EURO, // €
    SK_BPND, // £
    SK_JPY,  // ¥
        // Quotations
    SK_SQUL, // ’ Left single quote (linger for paired)
    SK_SQUR, // ’ Right single quote
//    SK_SDQU, // " straight double-quote character (custom so we can manipulate it.)
    SK_SDQL, // ’ Left double quote (linger for paired)
    SK_SDQR, // ’ Right double quote
    SK_FDQL, // ’ « Left double French quote (linger for paired)
    SK_FDQR, // ’ » Right double French quote
    SK_FSQL, // ’ ‹ Left single French quote (linger for paired)
    SK_FSQR, // ’ › Right single French quote
    SemKeys_COUNT, // end of SemKeys


/* Eventually…these should be handled as SemKeys with BCD & Alt-gr for Windows?
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

#define first_SemKey SK_KILL
#define last_Semkey SemKeys_COUNT

#define is_SemKey(sk) ((sk > (uint16_t)first_SemKey) && (sk < (uint16_t)last_Semkey))

#define tap_SemKey(sk) tap_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])
#define register_SemKey(sk) register_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])
#define unregister_SemKey(sk) unregister_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex])

#define linger_SemKey(sk) {register_code16(SemKeys_t[sk - SK_KILL][user_config.OSIndex]);linger_key = sk;linger_timer = state_reset_timer = timer_read();}
#define unlinger_SemKey(sk) {unregister_code16(SemKeys_t[linger_key - SK_KILL][user_config.OSIndex]);linger_key = 0;}

