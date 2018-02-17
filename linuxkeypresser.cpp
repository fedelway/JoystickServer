#include "linuxkeypresser.h"

#ifdef Q_OS_LINUX

LinuxKeyPresser::LinuxKeyPresser()
{
    initializeMap();
}

void LinuxKeyPresser::sendKeyPress(Qt::Key key, bool press)
{
    // Obtain the X11 display.
    Display *display = XOpenDisplay(0);
    if(display == NULL)
        return;

    // Get the root window for the current display.
    Window winRoot = XDefaultRootWindow(display);

    // Find the window which has the current keyboard focus.
    Window winFocus;
    int    revert;
    XGetInputFocus(display, &winFocus, &revert);

    //Create Key Event
    XKeyEvent event;
    KeySym keysym = qtKeyToKeysym.value(key,Qt::Key_unknown);

    event.display     = display;
    event.window      = winFocus;
    event.root        = winRoot;
    event.subwindow   = None;
    event.time        = CurrentTime;
    event.x           = 1;
    event.y           = 1;
    event.x_root      = 1;
    event.y_root      = 1;
    event.same_screen = True;
    event.keycode     = XKeysymToKeycode(display, keysym);
    event.state       = 0;

    if(press)
        event.type = KeyPress;
    else
        event.type = KeyRelease;

    // Send a fake key press event to the window.
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);

    // Done.
    XCloseDisplay(display);
}

void LinuxKeyPresser::initializeMap()
{
    qtKeyToKeysym.insert( Qt::Key_Escape, XK_Escape );
    qtKeyToKeysym.insert( Qt::Key_Tab,  XK_Tab );
    qtKeyToKeysym.insert( Qt::Key_Backtab,  XK_ISO_Left_Tab );
    qtKeyToKeysym.insert( Qt::Key_Backspace,  XK_BackSpace );
    qtKeyToKeysym.insert( Qt::Key_Return,  XK_Return );
    qtKeyToKeysym.insert( Qt::Key_Enter,  XK_KP_Enter );
    qtKeyToKeysym.insert( Qt::Key_Insert,  XK_KP_Insert );
    qtKeyToKeysym.insert( Qt::Key_Delete,  XK_KP_Delete );
    qtKeyToKeysym.insert( Qt::Key_Pause,  XK_Pause );
    qtKeyToKeysym.insert( Qt::Key_Print,  XK_Print );
    qtKeyToKeysym.insert( Qt::Key_SysReq,  0x1005FF60 );
    qtKeyToKeysym.insert( Qt::Key_Clear,  XK_KP_Begin );
    qtKeyToKeysym.insert( Qt::Key_Home,  XK_Home );
    qtKeyToKeysym.insert( Qt::Key_End,  XK_End );
    qtKeyToKeysym.insert( Qt::Key_Left,  XK_Left );
    qtKeyToKeysym.insert( Qt::Key_Up,  XK_Up );
    qtKeyToKeysym.insert( Qt::Key_Right,  XK_Right );
    qtKeyToKeysym.insert( Qt::Key_Down,  XK_Down );
    qtKeyToKeysym.insert( Qt::Key_PageUp,  XK_Prior );
    qtKeyToKeysym.insert( Qt::Key_PageDown,  XK_Next );
    qtKeyToKeysym.insert( Qt::Key_Shift,  XK_Shift_L );
    qtKeyToKeysym.insert( Qt::Key_Control,  XK_Control_L );
    qtKeyToKeysym.insert( Qt::Key_Meta,  XK_Meta_L );
    qtKeyToKeysym.insert( Qt::Key_Alt,  XK_Alt_L );
    qtKeyToKeysym.insert( Qt::Key_CapsLock,  XK_Caps_Lock );
    qtKeyToKeysym.insert( Qt::Key_NumLock, XK_Num_Lock );
    qtKeyToKeysym.insert( Qt::Key_ScrollLock, XK_Scroll_Lock );
    qtKeyToKeysym.insert( Qt::Key_F1, XK_F1 );
    qtKeyToKeysym.insert( Qt::Key_F2, XK_F2 );
    qtKeyToKeysym.insert( Qt::Key_F3, XK_F3 );
    qtKeyToKeysym.insert( Qt::Key_F4, XK_F4 );
    qtKeyToKeysym.insert( Qt::Key_F5, XK_F5 );
    qtKeyToKeysym.insert( Qt::Key_F6, XK_F6 );
    qtKeyToKeysym.insert( Qt::Key_F7, XK_F7 );
    qtKeyToKeysym.insert( Qt::Key_F8, XK_F8 );
    qtKeyToKeysym.insert( Qt::Key_F9, XK_F9 );
    qtKeyToKeysym.insert( Qt::Key_F10, XK_F10 );
    qtKeyToKeysym.insert( Qt::Key_F11, XK_F11 );
    qtKeyToKeysym.insert( Qt::Key_F12, XK_F12 );
    qtKeyToKeysym.insert( Qt::Key_F13, XK_F13 );
    qtKeyToKeysym.insert( Qt::Key_F14, XK_F14 );
    qtKeyToKeysym.insert( Qt::Key_F15, XK_F15 );
    qtKeyToKeysym.insert( Qt::Key_F16, XK_F16 );
    qtKeyToKeysym.insert( Qt::Key_F17, XK_F17 );
    qtKeyToKeysym.insert( Qt::Key_F18, XK_F18 );
    qtKeyToKeysym.insert( Qt::Key_F19, XK_F19 );
    qtKeyToKeysym.insert( Qt::Key_F20, XK_F20 );
    qtKeyToKeysym.insert( Qt::Key_F21, XK_F21 );
    qtKeyToKeysym.insert( Qt::Key_F22, XK_F22 );
    qtKeyToKeysym.insert( Qt::Key_F23, XK_F23 );
    qtKeyToKeysym.insert( Qt::Key_F24, XK_F24 );
    qtKeyToKeysym.insert( Qt::Key_F25, XK_F25 );
    qtKeyToKeysym.insert( Qt::Key_F26, XK_F26 );
    qtKeyToKeysym.insert( Qt::Key_F27, XK_F27 );
    qtKeyToKeysym.insert( Qt::Key_F28, XK_F28 );
    qtKeyToKeysym.insert( Qt::Key_F29, XK_F29 );
    qtKeyToKeysym.insert( Qt::Key_F30, XK_F30 );
    qtKeyToKeysym.insert( Qt::Key_F31, XK_F31 );
    qtKeyToKeysym.insert( Qt::Key_F32, XK_F32 );
    qtKeyToKeysym.insert( Qt::Key_F33, XK_F33 );
    qtKeyToKeysym.insert( Qt::Key_F34, XK_F34 );
    qtKeyToKeysym.insert( Qt::Key_F35, XK_F35 );
    qtKeyToKeysym.insert( Qt::Key_Super_L, XK_Super_L );
    qtKeyToKeysym.insert( Qt::Key_Super_R, XK_Super_R );
    qtKeyToKeysym.insert( Qt::Key_Menu, XK_Menu );
    qtKeyToKeysym.insert( Qt::Key_Hyper_L, XK_Hyper_L );
    qtKeyToKeysym.insert( Qt::Key_Hyper_R, XK_Hyper_R );
    qtKeyToKeysym.insert( Qt::Key_Help, XK_Help );
    qtKeyToKeysym.insert( Qt::Key_Direction_L, NoSymbol ); // ???
    qtKeyToKeysym.insert( Qt::Key_Direction_R, NoSymbol ); // ???
    qtKeyToKeysym.insert( Qt::Key_Space, XK_space );
    qtKeyToKeysym.insert( Qt::Key_Exclam, XK_exclam );
    qtKeyToKeysym.insert( Qt::Key_QuoteDbl, XK_quotedbl );
    qtKeyToKeysym.insert( Qt::Key_NumberSign, XK_numbersign );
    qtKeyToKeysym.insert( Qt::Key_Dollar, XK_dollar );
    qtKeyToKeysym.insert( Qt::Key_Percent, XK_percent );
    qtKeyToKeysym.insert( Qt::Key_Ampersand, XK_ampersand );
    qtKeyToKeysym.insert( Qt::Key_Apostrophe, XK_apostrophe );
    qtKeyToKeysym.insert( Qt::Key_ParenLeft, XK_parenleft );
    qtKeyToKeysym.insert( Qt::Key_ParenRight, XK_parenright );
    qtKeyToKeysym.insert( Qt::Key_Asterisk, XK_asterisk );
    qtKeyToKeysym.insert( Qt::Key_Plus, XK_plus );
    qtKeyToKeysym.insert( Qt::Key_Comma, XK_comma );
    qtKeyToKeysym.insert( Qt::Key_Minus, XK_minus );
    qtKeyToKeysym.insert( Qt::Key_Period, XK_period );
    qtKeyToKeysym.insert( Qt::Key_Slash, XK_slash );
    qtKeyToKeysym.insert( Qt::Key_0, XK_0 );
    qtKeyToKeysym.insert( Qt::Key_1, XK_1 );
    qtKeyToKeysym.insert( Qt::Key_2, XK_2 );
    qtKeyToKeysym.insert( Qt::Key_3, XK_3 );
    qtKeyToKeysym.insert( Qt::Key_4, XK_4 );
    qtKeyToKeysym.insert( Qt::Key_5, XK_5 );
    qtKeyToKeysym.insert( Qt::Key_6, XK_6 );
    qtKeyToKeysym.insert( Qt::Key_7, XK_7 );
    qtKeyToKeysym.insert( Qt::Key_8, XK_8 );
    qtKeyToKeysym.insert( Qt::Key_9, XK_9 );
    qtKeyToKeysym.insert( Qt::Key_Colon, XK_colon );
    qtKeyToKeysym.insert( Qt::Key_Semicolon, XK_semicolon );
    qtKeyToKeysym.insert( Qt::Key_Less, XK_less );
    qtKeyToKeysym.insert( Qt::Key_Equal, XK_equal );
    qtKeyToKeysym.insert( Qt::Key_Greater, XK_greater );
    qtKeyToKeysym.insert( Qt::Key_Question, XK_question );
    qtKeyToKeysym.insert( Qt::Key_At, XK_at );
    qtKeyToKeysym.insert( Qt::Key_A, XK_a ); // Must be lower qtKeyToKeysym.insert( keysyms
    qtKeyToKeysym.insert( Qt::Key_B, XK_b ); // for correct shift handling.
    qtKeyToKeysym.insert( Qt::Key_C, XK_c );
    qtKeyToKeysym.insert( Qt::Key_D, XK_d );
    qtKeyToKeysym.insert( Qt::Key_E, XK_e );
    qtKeyToKeysym.insert( Qt::Key_F, XK_f );
    qtKeyToKeysym.insert( Qt::Key_G, XK_g );
    qtKeyToKeysym.insert( Qt::Key_H, XK_h );
    qtKeyToKeysym.insert( Qt::Key_I, XK_i );
    qtKeyToKeysym.insert( Qt::Key_J, XK_j );
    qtKeyToKeysym.insert( Qt::Key_K, XK_k );
    qtKeyToKeysym.insert( Qt::Key_L, XK_l );
    qtKeyToKeysym.insert( Qt::Key_M, XK_m );
    qtKeyToKeysym.insert( Qt::Key_N, XK_n );
    qtKeyToKeysym.insert( Qt::Key_O, XK_o );
    qtKeyToKeysym.insert( Qt::Key_P, XK_p );
    qtKeyToKeysym.insert( Qt::Key_Q, XK_q );
    qtKeyToKeysym.insert( Qt::Key_R, XK_r );
    qtKeyToKeysym.insert( Qt::Key_S, XK_s );
    qtKeyToKeysym.insert( Qt::Key_T, XK_t );
    qtKeyToKeysym.insert( Qt::Key_U, XK_u );
    qtKeyToKeysym.insert( Qt::Key_V, XK_v );
    qtKeyToKeysym.insert( Qt::Key_W, XK_w );
    qtKeyToKeysym.insert( Qt::Key_X, XK_x );
    qtKeyToKeysym.insert( Qt::Key_Y, XK_y );
    qtKeyToKeysym.insert( Qt::Key_Z, XK_z );
    qtKeyToKeysym.insert( Qt::Key_BracketLeft, XK_bracketleft );
    qtKeyToKeysym.insert( Qt::Key_Backslash, XK_backslash );
    qtKeyToKeysym.insert( Qt::Key_BracketRight, XK_bracketright );
    qtKeyToKeysym.insert( Qt::Key_AsciiCircum, XK_asciicircum );
    qtKeyToKeysym.insert( Qt::Key_Underscore, XK_underscore );
    qtKeyToKeysym.insert( Qt::Key_QuoteLeft, XK_quoteleft );
    qtKeyToKeysym.insert( Qt::Key_BraceLeft, XK_braceleft );
    qtKeyToKeysym.insert( Qt::Key_Bar, XK_bar );
    qtKeyToKeysym.insert( Qt::Key_BraceRight, XK_braceright );
    qtKeyToKeysym.insert( Qt::Key_AsciiTilde, XK_asciitilde );

    qtKeyToKeysym.insert( Qt::Key_nobreakspace, XK_nobreakspace );
    qtKeyToKeysym.insert( Qt::Key_exclamdown, XK_exclamdown );
    qtKeyToKeysym.insert( Qt::Key_cent, XK_cent );
    qtKeyToKeysym.insert( Qt::Key_sterling, XK_sterling );
    qtKeyToKeysym.insert( Qt::Key_currency, XK_currency );
    qtKeyToKeysym.insert( Qt::Key_yen, XK_yen );
    qtKeyToKeysym.insert( Qt::Key_brokenbar, XK_brokenbar );
    qtKeyToKeysym.insert( Qt::Key_section, XK_section );
    qtKeyToKeysym.insert( Qt::Key_diaeresis, XK_diaeresis );
    qtKeyToKeysym.insert( Qt::Key_copyright, XK_copyright );
    qtKeyToKeysym.insert( Qt::Key_ordfeminine, XK_ordfeminine );
    qtKeyToKeysym.insert( Qt::Key_guillemotleft, XK_guillemotleft );
    qtKeyToKeysym.insert( Qt::Key_notsign, XK_notsign );
    qtKeyToKeysym.insert( Qt::Key_hyphen, XK_hyphen );
    qtKeyToKeysym.insert( Qt::Key_registered, XK_registered );
    qtKeyToKeysym.insert( Qt::Key_macron, XK_macron );
    qtKeyToKeysym.insert( Qt::Key_degree, XK_degree );
    qtKeyToKeysym.insert( Qt::Key_plusminus, XK_plusminus );
    qtKeyToKeysym.insert( Qt::Key_twosuperior, XK_twosuperior );
    qtKeyToKeysym.insert( Qt::Key_threesuperior, XK_threesuperior );
    qtKeyToKeysym.insert( Qt::Key_acute, XK_acute );
    qtKeyToKeysym.insert( Qt::Key_mu, XK_mu );
    qtKeyToKeysym.insert( Qt::Key_paragraph, XK_paragraph );
    qtKeyToKeysym.insert( Qt::Key_periodcentered, XK_periodcentered );
    qtKeyToKeysym.insert( Qt::Key_cedilla, XK_cedilla );
    qtKeyToKeysym.insert( Qt::Key_onesuperior, XK_onesuperior );
    qtKeyToKeysym.insert( Qt::Key_masculine, XK_masculine );
    qtKeyToKeysym.insert( Qt::Key_guillemotright, XK_guillemotright );
    qtKeyToKeysym.insert( Qt::Key_onequarter, XK_onequarter );
    qtKeyToKeysym.insert( Qt::Key_onehalf, XK_onehalf );
    qtKeyToKeysym.insert( Qt::Key_threequarters, XK_threequarters );
    qtKeyToKeysym.insert( Qt::Key_questiondown, XK_questiondown );
    qtKeyToKeysym.insert( Qt::Key_Agrave, XK_agrave );	// Lower qtKeyToKeysym.insert( keysyms
    qtKeyToKeysym.insert( Qt::Key_Aacute, XK_aacute ); // for shift handling.
    qtKeyToKeysym.insert( Qt::Key_Acircumflex, XK_acircumflex );
    qtKeyToKeysym.insert( Qt::Key_Atilde, XK_atilde );
    qtKeyToKeysym.insert( Qt::Key_Adiaeresis, XK_adiaeresis );
    qtKeyToKeysym.insert( Qt::Key_Aring, XK_aring );
    qtKeyToKeysym.insert( Qt::Key_AE, XK_ae );
    qtKeyToKeysym.insert( Qt::Key_Ccedilla, XK_ccedilla );
    qtKeyToKeysym.insert( Qt::Key_Egrave, XK_egrave );
    qtKeyToKeysym.insert( Qt::Key_Eacute, XK_eacute );
    qtKeyToKeysym.insert( Qt::Key_Ecircumflex, XK_ecircumflex );
    qtKeyToKeysym.insert( Qt::Key_Ediaeresis, XK_ediaeresis );
    qtKeyToKeysym.insert( Qt::Key_Igrave, XK_igrave );
    qtKeyToKeysym.insert( Qt::Key_Iacute, XK_iacute );
    qtKeyToKeysym.insert( Qt::Key_Icircumflex, XK_icircumflex );
    qtKeyToKeysym.insert( Qt::Key_Idiaeresis, XK_idiaeresis );
    qtKeyToKeysym.insert( Qt::Key_ETH, XK_eth );
    qtKeyToKeysym.insert( Qt::Key_Ntilde, XK_ntilde );
    qtKeyToKeysym.insert( Qt::Key_Ograve, XK_ograve );
    qtKeyToKeysym.insert( Qt::Key_Oacute, XK_oacute );
    qtKeyToKeysym.insert( Qt::Key_Ocircumflex, XK_ocircumflex );
    qtKeyToKeysym.insert( Qt::Key_Otilde, XK_otilde );
    qtKeyToKeysym.insert( Qt::Key_Odiaeresis, XK_odiaeresis );
    qtKeyToKeysym.insert( Qt::Key_multiply, XK_multiply );
    qtKeyToKeysym.insert( Qt::Key_Ooblique, XK_ooblique );
    qtKeyToKeysym.insert( Qt::Key_Ugrave, XK_ugrave );
    qtKeyToKeysym.insert( Qt::Key_Uacute, XK_uacute );
    qtKeyToKeysym.insert( Qt::Key_Ucircumflex, XK_ucircumflex );
    qtKeyToKeysym.insert( Qt::Key_Udiaeresis, XK_udiaeresis );
    qtKeyToKeysym.insert( Qt::Key_Yacute, XK_yacute );
    qtKeyToKeysym.insert( Qt::Key_THORN, XK_thorn );
    qtKeyToKeysym.insert( Qt::Key_ssharp, XK_ssharp );
    qtKeyToKeysym.insert( Qt::Key_division, XK_division );
    qtKeyToKeysym.insert( Qt::Key_ydiaeresis, XK_ydiaeresis );

    qtKeyToKeysym.insert( Qt::Key_AltGr, XK_ISO_Level3_Shift );
    qtKeyToKeysym.insert( Qt::Key_Multi_key, XK_Multi_key );
    qtKeyToKeysym.insert( Qt::Key_Codeinput, XK_Codeinput );
    qtKeyToKeysym.insert( Qt::Key_SingleCandidate, XK_SingleCandidate );
    qtKeyToKeysym.insert( Qt::Key_MultipleCandidate, XK_MultipleCandidate );
    qtKeyToKeysym.insert( Qt::Key_PreviousCandidate, XK_PreviousCandidate );

    qtKeyToKeysym.insert( Qt::Key_Mode_switch, XK_Mode_switch );

    qtKeyToKeysym.insert( Qt::Key_Kanji, XK_Kanji );
    qtKeyToKeysym.insert( Qt::Key_Muhenkan, XK_Muhenkan );
    qtKeyToKeysym.insert( Qt::Key_Henkan, XK_Henkan );
    qtKeyToKeysym.insert( Qt::Key_Romaji, XK_Romaji );
    qtKeyToKeysym.insert( Qt::Key_Hiragana, XK_Hiragana );
    qtKeyToKeysym.insert( Qt::Key_Katakana, XK_Katakana );
    qtKeyToKeysym.insert( Qt::Key_Hiragana_Katakana, XK_Hiragana_Katakana );
    qtKeyToKeysym.insert( Qt::Key_Zenkaku, XK_Zenkaku );
    qtKeyToKeysym.insert( Qt::Key_Hankaku, XK_Hankaku );
    qtKeyToKeysym.insert( Qt::Key_Zenkaku_Hankaku, XK_Zenkaku_Hankaku );
    qtKeyToKeysym.insert( Qt::Key_Touroku, XK_Touroku );
    qtKeyToKeysym.insert( Qt::Key_Massyo, XK_Massyo );
    qtKeyToKeysym.insert( Qt::Key_Kana_Lock, XK_Kana_Lock );
    qtKeyToKeysym.insert( Qt::Key_Kana_Shift, XK_Kana_Shift );
    qtKeyToKeysym.insert( Qt::Key_Eisu_Shift, XK_Eisu_Shift );
    qtKeyToKeysym.insert( Qt::Key_Eisu_toggle, XK_Eisu_toggle );

    qtKeyToKeysym.insert( Qt::Key_Hangul, XK_Hangul );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Start, XK_Hangul_Start );
    qtKeyToKeysym.insert( Qt::Key_Hangul_End, XK_Hangul_End );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Hanja, XK_Hangul_Hanja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Jamo, XK_Hangul_Jamo );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Romaja, XK_Hangul_Romaja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Jeonja, XK_Hangul_Jeonja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Banja, XK_Hangul_Banja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_PreHanja, XK_Hangul_PreHanja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_PostHanja, XK_Hangul_PostHanja );
    qtKeyToKeysym.insert( Qt::Key_Hangul_Special, XK_Hangul_Special );

    qtKeyToKeysym.insert( Qt::Key_Dead_Grave, XK_dead_grave );
    qtKeyToKeysym.insert( Qt::Key_Dead_Acute, XK_dead_acute );
    qtKeyToKeysym.insert( Qt::Key_Dead_Circumflex, XK_dead_circumflex );
    qtKeyToKeysym.insert( Qt::Key_Dead_Tilde, XK_dead_tilde );
    qtKeyToKeysym.insert( Qt::Key_Dead_Macron, XK_dead_macron );
    qtKeyToKeysym.insert( Qt::Key_Dead_Breve, XK_dead_breve );
    qtKeyToKeysym.insert( Qt::Key_Dead_Abovedot, XK_dead_abovedot );
    qtKeyToKeysym.insert( Qt::Key_Dead_Diaeresis, XK_dead_diaeresis );
    qtKeyToKeysym.insert( Qt::Key_Dead_Abovering, XK_dead_abovering );
    qtKeyToKeysym.insert( Qt::Key_Dead_Doubleacute, XK_dead_doubleacute );
    qtKeyToKeysym.insert( Qt::Key_Dead_Caron, XK_dead_caron );
    qtKeyToKeysym.insert( Qt::Key_Dead_Cedilla, XK_dead_cedilla );
    qtKeyToKeysym.insert( Qt::Key_Dead_Ogonek, XK_dead_ogonek );
    qtKeyToKeysym.insert( Qt::Key_Dead_Iota, XK_dead_iota );
    qtKeyToKeysym.insert( Qt::Key_Dead_Voiced_Sound, XK_dead_voiced_sound );
    qtKeyToKeysym.insert( Qt::Key_Dead_Semivoiced_Sound, XK_dead_semivoiced_sound );
    qtKeyToKeysym.insert( Qt::Key_Dead_Belowdot, XK_dead_belowdot );
    qtKeyToKeysym.insert( Qt::Key_Dead_Hook, XK_dead_hook );
    qtKeyToKeysym.insert( Qt::Key_Dead_Horn, XK_dead_horn );

    /*qtKeyToKeysym.insert( Qt::Key_Back, XF86XK_Back );
    qtKeyToKeysym.insert( Qt::Key_Forward, XF86XK_Forward );
    qtKeyToKeysym.insert( Qt::Key_Stop, XF86XK_Stop );
    qtKeyToKeysym.insert( Qt::Key_Refresh, XF86XK_Refresh );

    qtKeyToKeysym.insert( Qt::Key_VolumeDown, XF86XK_AudioLowerVolume );
    qtKeyToKeysym.insert( Qt::Key_VolumeMute, XF86XK_AudioMute );
    qtKeyToKeysym.insert( Qt::Key_VolumeUp, XF86XK_AudioRaiseVolume );
    qtKeyToKeysym.insert( Qt::Key_BassBoost, NoSymbol );	// ???
    qtKeyToKeysym.insert( Qt::Key_BassUp, NoSymbol );		// ???
    qtKeyToKeysym.insert( Qt::Key_BassDown, NoSymbol );	// ???
    qtKeyToKeysym.insert( Qt::Key_TrebleUp, NoSymbol );	// ???
    qtKeyToKeysym.insert( Qt::Key_TrebleDown, NoSymbol );	// ???

    qtKeyToKeysym.insert( Qt::Key_MediaPlay, XF86XK_AudioPlay );
    qtKeyToKeysym.insert( Qt::Key_MediaStop, XF86XK_AudioStop );
    qtKeyToKeysym.insert( Qt::Key_MediaPrevious, XF86XK_AudioPrev );
    qtKeyToKeysym.insert( Qt::Key_MediaNext, XF86XK_AudioNext );
    qtKeyToKeysym.insert( Qt::Key_MediaRecord, XF86XK_AudioRecord );

    qtKeyToKeysym.insert( Qt::Key_HomePage, XF86XK_HomePage );
    qtKeyToKeysym.insert( Qt::Key_Favorites, XF86XK_Favorites );
    qtKeyToKeysym.insert( Qt::Key_Search, XF86XK_Search );
    qtKeyToKeysym.insert( Qt::Key_Standby, XF86XK_Standby );
    qtKeyToKeysym.insert( Qt::Key_OpenUrl, XF86XK_OpenURL );

    qtKeyToKeysym.insert( Qt::Key_LaunchMail, XF86XK_Mail );
    qtKeyToKeysym.insert( Qt::Key_LaunchMedia, XF86XK_AudioMedia );
    qtKeyToKeysym.insert( Qt::Key_Launch0, XF86XK_Launch0 );
    qtKeyToKeysym.insert( Qt::Key_Launch1, XF86XK_Launch1 );
    qtKeyToKeysym.insert( Qt::Key_Launch2, XF86XK_Launch2 );
    qtKeyToKeysym.insert( Qt::Key_Launch3, XF86XK_Launch3 );
    qtKeyToKeysym.insert( Qt::Key_Launch4, XF86XK_Launch4 );
    qtKeyToKeysym.insert( Qt::Key_Launch5, XF86XK_Launch5 );
    qtKeyToKeysym.insert( Qt::Key_Launch6, XF86XK_Launch6 );
    qtKeyToKeysym.insert( Qt::Key_Launch7, XF86XK_Launch7 );
    qtKeyToKeysym.insert( Qt::Key_Launch8, XF86XK_Launch8 );
    qtKeyToKeysym.insert( Qt::Key_Launch9, XF86XK_Launch9 );
    qtKeyToKeysym.insert( Qt::Key_LaunchA, XF86XK_LaunchA );
    qtKeyToKeysym.insert( Qt::Key_LaunchB, XF86XK_LaunchB );
    qtKeyToKeysym.insert( Qt::Key_LaunchC, XF86XK_LaunchC );
    qtKeyToKeysym.insert( Qt::Key_LaunchD, XF86XK_LaunchD );
    qtKeyToKeysym.insert( Qt::Key_LaunchE, XF86XK_LaunchE );
    qtKeyToKeysym.insert( Qt::Key_LaunchF, XF86XK_LaunchF );

    qtKeyToKeysym.insert( Qt::Key_MediaLast, NoSymbol );   // ???

    qtKeyToKeysym.insert( Qt::Key_Select, QTOPIAXK_Select );
    qtKeyToKeysym.insert( Qt::Key_Yes, QTOPIAXK_Yes );
    qtKeyToKeysym.insert( Qt::Key_No, QTOPIAXK_No );

    qtKeyToKeysym.insert( Qt::Key_Cancel, QTOPIAXK_Cancel );
    qtKeyToKeysym.insert( Qt::Key_Printer, QTOPIAXK_Printer );
    qtKeyToKeysym.insert( Qt::Key_Execute, QTOPIAXK_Execute );
    qtKeyToKeysym.insert( Qt::Key_Sleep, QTOPIAXK_Sleep );
    qtKeyToKeysym.insert( Qt::Key_Play, QTOPIAXK_Play );
    qtKeyToKeysym.insert( Qt::Key_Zoom, QTOPIAXK_Zoom );

    qtKeyToKeysym.insert( Qt::Key_Context1, QTOPIAXK_Context1 );
    qtKeyToKeysym.insert( Qt::Key_Context2, QTOPIAXK_Context2 );
    qtKeyToKeysym.insert( Qt::Key_Context3, QTOPIAXK_Context3 );
    qtKeyToKeysym.insert( Qt::Key_Context4, QTOPIAXK_Context4 );
    qtKeyToKeysym.insert( Qt::Key_Call, QTOPIAXK_Call );
    qtKeyToKeysym.insert( Qt::Key_Hangup, QTOPIAXK_Hangup );
    qtKeyToKeysym.insert( Qt::Key_Flip, QTOPIAXK_Flip );*/

    qtKeyToKeysym.insert( Qt::Key_unknown, NoSymbol );
}

#endif
