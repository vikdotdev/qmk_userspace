#include QMK_KEYBOARD_H

// Layer enum
#define _BASE     0
#define _GAME     1
#define _RAISE    2
#define _LOWER    3

// Custom keys
// Left <Ctrl> when held, <Esc> when tapped.
#define LC_ESC LCTL_T(KC_ESC)

// Right <Ctrl> when held, <Quote> when tapped.
#define RC_QUOT RCTL_T(KC_QUOT)

// Left <Super> when held, <Tab> when tapped.
#define WIN_TAB LWIN_T(KC_TAB)

// Left <Super> when held, <Back-Slash> when tapped.
#define WIN_SLS RWIN_T(KC_BSLS)

// Raise layer when held, <Enter> when tapped.
#define RA_ENT LT(_RAISE, KC_ENT)
#define RA_ENT LT(_RAISE, KC_ENT)

// Raise layer when held, <Space> when tapped.
#define RA_SPC LT(_RAISE, KC_SPC)
#define LOW OSL(_LOWER)

// Hold to enable <Shift>, or tap to enable <Shift> for next key-press.
#define OSM_LS OSM(MOD_LSFT)
#define OSM_RS OSM(MOD_RSFT)

// Hold to enable <Alt>, or tap to enable <Alt> for next key-press.
#define OSM_LA OSM(MOD_LALT)
#define OSM_RA OSM(MOD_RALT)

// Hold to enable <Ctrl>, or tap to enable <Ctrl> for next key-press.
#define OSM_LC OSM(MOD_RCTL)

// Switch to game layer. This is a layer where most key just do what they say, layers disabled.
#define TG_GAME TG(_GAME)
#define NO_BTN KC_NO

// Left <Alt> on hold, pinky keys on press.
#define TLA_A LALT_T(KC_A)
#define TLA_SCL LALT_T(KC_SCLN)

// To better visualise thumb-cluster layout, turn keyboard side outward so that the
// grid is straight instead of diagonal. The buttons will match directly, except the missing button.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6(
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    ,      KC_7    , KC_8    , KC_9    , KC_0    , KC_TILD , KC_GRV  ,
        WIN_TAB , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , WIN_SLS ,
        LC_ESC  , TLA_A   , KC_S    , KC_D    , KC_F    , KC_G    ,      KC_H    , KC_J    , KC_K    , KC_L    , TLA_SCL , RC_QUOT ,
        OSM_LS  , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , OSM_LS  ,
                            KC_LBRC , KC_RBRC ,                                              KC_EQL  , KC_MINS ,
                                                OSM_LA  , NO_BTN  ,      NO_BTN  , OSM_RA   ,
                                                LOW     , RA_SPC  ,      RA_ENT  , LOW      ,
                                                QK_BOOT , KC_UNDS ,      KC_BSPC , QK_BOOT
    ),
    [_RAISE] = LAYOUT_5x6(
        _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ ,
        _______ , _______ , _______ , KC_END  , _______ , _______ ,      _______ , _______ , _______ , _______ , KC_UP   , _______ ,
        _______ , KC_HOME , _______ , KC_DEL  , KC_RGHT , KC_ENT  ,      _______ , _______ , KC_BSPC , _______ , _______ , _______ ,
        _______ , _______ , _______ , _______ , _______ , KC_LEFT ,      KC_DOWN , _______ , _______ , _______ , _______ , _______ ,
                            _______ , _______ ,                                              _______ , _______ ,
                                                _______ , NO_BTN  ,      NO_BTN  , _______ ,
                                                _______ , _______ ,      _______ , _______ ,
                                                _______ , _______ ,      _______ , _______
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,      KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,
        _______ , _______ , _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , KC_PSCR , TG_GAME ,
        KC_MUTE , KC_VOLD , KC_VOLU , _______ , _______ , _______ ,      _______ , _______ , _______ , KC_CAPS , _______ , _______ ,
        KC_MPLY , KC_MPRV , KC_MNXT , _______ , _______ , _______ ,      _______ , _______ , _______ , _______ , _______ , _______ ,
                            _______ , _______ ,                                              QK_RBT  , QK_BOOT ,
                                                _______ , NO_BTN  ,      NO_BTN  , _______ ,
                                                _______ , _______ ,      _______ , _______ ,
                                                _______ , _______ ,      _______ , _______
    ),

    [_GAME] = LAYOUT_5x6(
        KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    ,      KC_7    , KC_8    , KC_9    , KC_0    , KC_TILD , KC_GRV  ,
        KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,      KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSLS ,
        KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    ,      KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , RC_QUOT ,
        KC_LCTL , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,      KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT  ,
                            KC_LBRC , KC_RBRC ,                                              KC_EQL  , KC_MINS ,
                                                KC_LALT , NO_BTN  ,      NO_BTN  , KC_RALT ,
                                                LOW     , KC_SPC  ,      KC_ENT  , LOW     ,
                                                KC_ESC  , KC_UNDS ,      KC_BSPC , KC_NO
    ),
};
