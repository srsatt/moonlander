#include QMK_KEYBOARD_H
#include <quantum/pointing_device.h>
#include "version.h"
#include "layout.h"

#include "arbitrary_keycode/include.h"

#define CUSTOM_SAFE_RANGE ML_SAFE_RANGE
#include "system.h"
#include "lang_shift/include.h"
#include "combo/include.h"
#include "color/include.h"
#include "tt/include.h"
#include "repeat/include.h"

enum custom_keycodes {
    KEYCODES_START = CUSTOM_SAFE_RANGE,

    // Wow, such empty

    NEW_NEW_SAFE_RANGE,
#undef CUSTOM_SAFE_RANGE
#define CUSTOM_SAFE_RANGE NEW_NEW_SAFE_RANGE
};


// Shift keys
#define SH_TAB S(KC_TAB)
#define CT_TAB C(KC_TAB)
#define CS_TAB C(S(KC_TAB))

#define CTL_C C(KC_C)


// Ctrl+Shift keys
#define CS_M LCTL(S(KC_M))
#define CS_P LCTL(S(KC_P))

// Alt keys
#define AL_UP LALT(KC_UP)
#define AL_PSCR LALT(KC_PSCR)


// prog select for Raycast
#define WN_C_1 LGUI(LALT(KC_1))
#define WN_C_2 LGUI(LALT(KC_2))
#define WN_C_3 LGUI(LALT(KC_3))
#define WN_C_4 LGUI(LALT(KC_4))
#define WN_C_5 LGUI(LALT(KC_5))
#define WN_C_6 LGUI(LALT(KC_6))



// Gui keys
#define WN_1 LGUI(KC_1)
#define WN_2 LGUI(KC_2)
#define WN_3 LGUI(KC_3)
#define WN_4 LGUI(KC_4)
#define WN_5 LGUI(KC_5)
#define WN_6 LGUI(KC_6)
#define WN_7 LGUI(KC_7)
#define WN_8 LGUI(KC_8)
#define WN_9 LGUI(KC_9)
#define WN_F1 LGUI(KC_F1)
#define WN_F2 LGUI(KC_F2)
#define WN_F3 LGUI(KC_F3)
#define WN_Q LGUI(KC_Q)

// Ctrl keys
#define CT_1 LCTL(KC_1)
#define CT_2 LCTL(KC_2)
#define CT_J LCTL(KC_J)
#define CT_F5 LCTL(KC_F5)
#define CT_BSLS LCTL(KC_BSLS)



#define RGB_LYR TOGGLE_LAYER_COLOR

enum Combos {
    // Chords

    // thumb cluster edge to middle, U-upper red
    TC_L1 = CMB_000,
    TC_L2,
    TC_L3,
    TC_LU,

    TC_R1,
    TC_R2,
    TC_R3,
    TC_RU,


    //russian combos
    // Х+Ж = Э
    // Б+Ь = Ъ
    RU_CMB_H,
    RU_CMB_ZH,
    RU_CMB_S_H,
    RU_CMB_S_ZH,

    RU_CMB_B,
    RU_CMB_S_B,
    RU_CMB_SF,
    RU_CMB_S_SF,



    // Left number-row left to right
    UR_L1,
    UR_L2,
    UR_L3,
    UR_L4,
    UR_L5,
    UR_L6,

    // Right number-row right to left
    UR_R1,
    UR_R2,
    UR_R3,
    UR_R4,
    UR_R5,
    UR_R6,

    // bottom control row
    BR_R1,
    BR_R2,
    BR_R3,
    BR_R4,
    BR_R5,

    BR_L1,
    BR_L2,
    BR_L3,
    BR_L4,
    BR_L5,


    // middle hotkeys column
    MC_L1,
    MC_L2,
    MC_L3,

    MC_R1,
    MC_R2,
    MC_R3,

    // middle hotkeys columns with SHIFT
    MC_LS1,
    MC_LS2,
    MC_LS3,

    MC_RS1,
    MC_RS2,
    MC_RS3,



    // Edge Controls Line
    EC_L1,
    EC_L2,
    EC_L3,
    EC_S_L1,
    EC_S_L2,
    EC_S_L3,


    EC_R1,
    EC_R2,
    EC_R3,
    EC_S_R1,
    EC_S_R2,
    EC_S_R3,






    // Brackets on red layer, order: 1 - (), 2 - [], 3 - {}, 4 - <>
    CMB_LB1,
    CMB_RB1,
    CMB_LB2,
    CMB_RB2,
    CMB_LB3,
    CMB_RB3,
    CMB_LB4,
    CMB_RB4,

    // Brackets on XCompose layer
    CMB_LTR,
    CMB_RTR,
    CMB_LCR,
    CMB_RCR,

};

#define TT_CTJ TT_000

// Подключаем обработку кастомных кейкодов
#include "xcompose.h"
#include "custom_lang.h"
#include "custom_hotkeys.h"
#include "moonlander_leds.h"
#include "mouse_pixel_move.h"
#include "song_keys.h"

enum Layers {
    L_EN = 0,
    L_EN_S,

    L_RU,
    L_RU_S,

    L_RED,
    L_GREN,
    L_VIOL,
    L_GRAY,
    L_CYAN,
    L_YELW,

    L_GAME,
    L_NUCL,
};


#define TG_RED TG(L_RED)
#define TG_GREN TG(L_GREN)
#define TG_VIOL TG(L_VIOL)
#define TG_GRAY TG(L_GRAY)
#define TG_CYAN TG(L_CYAN)
#define TG_YELW TG(L_YELW)
#define TG_GAME TG(L_GAME)
#define TG_NUCL TG(L_NUCL)

#define MO_RED MO(L_RED)
#define MO_GREN MO(L_GREN)
#define MO_VIOL MO(L_VIOL)
#define MO_GRAY MO(L_GRAY)
#define MO_CYAN MO(L_CYAN)
#define MO_YELW MO(L_YELW)
#define MO_GAME MO(L_GAME)
#define MO_NUCL MO(L_NUCL)

#define TT_RED (TT_000 + L_RED)
#define TT_GREN (TT_000 + L_GREN)
#define TT_VIOL (TT_000 + L_VIOL)
#define TT_GRAY (TT_000 + L_GRAY)
#define TT_CYAN (TT_000 + L_CYAN)
#define TT_YELW (TT_000 + L_YELW)
#define TT_GAME (TT_000 + L_GAME)
#define TT_NUCL (TT_000 + L_NUCL)

// Этот макрос нужен, чтобы задавать одинаковые слои (в том числе и шифтовый слой) для английского и русского языка. В итоге их отличия будут только в буквах.
#define LANG_TWO_LAYERS(\
  L_DEFAULT, L_SHIFT,\
  \
  /* Left hand */ \
       LU1, LU2, LU3, LU4, LU5, \
       LH1, LH2, LH3, LH4, LH5, \
       LD1, LD2, LD3, LD4, LD5, /* Right hand */ \
       RU1, RU2, RU3, RU4, RU5, \
       RH1, RH2, RH3, RH4, RH5, \
       RD1, RD2, RD3, RD4, RD5, \
  \
  /* ---------------------------- Shift layer ---------------------------- */ /* Left hand */ \
        SLU1, SLU2, SLU3, SLU4, SLU5, \
        SLH1, SLH2, SLH3, SLH4, SLH5, \
        SLD1, SLD2, SLD3, SLD4, SLD5, /* Right hand */ \
  SRU1, SRU2, SRU3, SRU4, SRU5, \
  SRH1, SRH2, SRH3, SRH4, SRH5, \
  SRD1, SRD2, SRD3, SRD4, SRD5  \
    ) \
  /*-------------------------------------------------------------------------*/ \
  [L_DEFAULT] = MY_layout(/* LEFT HALF */ \
    UR_L1,   UR_L2,   UR_L3,   UR_L4,   UR_L5,   UR_L6,   MC_L1, \
    EC_L1,   LU1,     LU2,     LU3,     LU4,     LU5,     MC_L2, \
    EC_L2,   LH1,     LH2,     LH3,     LH4,     LH5,     MC_L3, \
    EC_L3,   LD1,     LD2,     LD3,     LD4,     LD5, \
    BR_L1,   BR_L2,   BR_L3,   BR_L4,   BR_L5, \
    TC_LU, /* LEFT RED THUMB KEY */ \
    TC_L1,   TC_L2,   TC_L3, /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    MC_R1,   UR_R6,   UR_R5,   UR_R4,   UR_R3,   UR_R2,   UR_R1, \
    MC_R2,   RU1,     RU2,     RU3,     RU4,     RU5,     EC_R1, \
    MC_R3,   RH1,     RH2,     RH3,     RH4,     RH5,     EC_R2, \
             RD1,     RD2,     RD3,     RD4,     RD5,     EC_R3, \
                      BR_R5,   BR_R4,   BR_R3,   BR_R2,   BR_R1, \
                      TC_RU, /* RIGHT RED THUMB KEY */ \
                      TC_R3, TC_R2, TC_R1 /* RIGHT THUMB KEYS */ \
  ), \
  \
  /*-------------------------------------------------------------------------*/ \
  [L_SHIFT] = MY_layout(                                               /* LEFT HALF */ \
    _______, AG_1,    AG_2,    AG_3,    AG_4,    AG_5,    MC_LS1, /* NUMBERS WITH SHIFT */  \
    EC_S_L1, SLU1,    SLU2,    SLU3,    SLU4,    SLU5,    MC_LS2, \
    EC_S_L2, SLH1,    SLH2,    SLH3,    SLH4,    SLH5,    MC_LS3, \
    EC_S_L3, SLD1,    SLD2,    SLD3,    SLD4,    SLD5, \
    _______, _______, _______, _______, _______, \
    _______, /* LEFT RED THUMB KEY */ \
    _______, _______, _______, /* LEFT THUMB KEYS */ \
    \
    /* RIGHT HALF */ \
    MC_RS1,  AG_6,    AG_7,    AG_8,    AG_9,    AG_0,    _______, \
    MC_RS2,  SRU1,    SRU2,    SRU3,    SRU4,    SRU5,    EC_S_R1, \
    MC_RS3,  SRH1,    SRH2,    SRH3,    SRH4,    SRH5,    EC_S_R2, \
             SRD1,    SRD2,    SRD3,    SRD4,    SRD5,    EC_S_R3, \
                      _______, _______, _______, _______, _______, \
                      _______, /* RIGHT RED THUMB KEY */ \
                      _______, _______, _______ /* RIGHT THUMB KEYS */ \
  ),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //---------------------------------------------------------------------------
    LANG_TWO_LAYERS(
        L_EN, L_EN_S,

        /* Left hand */
        EN_Q,    EN_W,    EN_E,    EN_R,    EN_T,
        EN_A,    EN_S,    EN_D,    EN_F,    EN_G,
        EN_Z,    EN_X,    EN_C,    EN_V,    EN_B,

        /* Right hand */
        EN_Y,    EN_U,    EN_I,    EN_O,    EN_P,
        EN_H,    EN_J,    EN_K,    EN_L,    EN_S,
        EN_N,    EN_M,    EN_W,    EN_V,    EN_Z,

        /* ---------------------------- Shift layer ---------------------------- */
        /* Left hand */
        EN_S_Q,    EN_S_W,    EN_S_E,    EN_S_R,    EN_S_T,
        EN_S_A,    EN_S_S,    EN_S_D,    EN_S_F,    EN_S_G,
        EN_S_Z,    EN_S_X,    EN_S_C,    EN_S_V,    EN_S_B,

        /* Right hand */
        EN_S_Y,    EN_S_U,    EN_S_I,    EN_S_O,    EN_S_P,
        EN_S_H,    EN_S_J,    EN_S_K,    EN_S_L,    EN_S_S,
        EN_S_N,    EN_S_M,    EN_S_W,    EN_S_V,    EN_S_Z
        )

    //---------------------------------------------------------------------------
    LANG_TWO_LAYERS(
        L_RU, L_RU_S,
        /* Left hand */
        RU_J,    RU_TS,   RU_U,    RU_K,    RU_JE,
        RU_F,    RU_Y,    RU_V,    RU_A,    RU_P,
        RU_JA,   RU_CH,   RU_S,    RU_M,    RU_I,

        /* Right hand */
        //  я ч с м и т ь б ю /
        RU_N,    RU_G,    RU_SH,   RU_SC,   RU_Z,
        RU_R,    RU_O,    RU_L,    RU_D,    RU_CMB_H,
        RU_T,    RU_CMB_SF,   RU_CMB_B,    RU_JU,   RU_CMB_ZH,

        /* ---------------------------- Shift layer ---------------------------- */
        /* Left hand */
        RU_S_J,    RU_S_TS,   RU_S_U,    RU_S_K,    RU_S_JE,
        RU_S_F,    RU_S_Y,    RU_S_V,    RU_S_A,    RU_S_P,
        RU_S_JA,   RU_S_CH,   RU_S_S,    RU_S_M,    RU_S_I,
        /* Right hand */
        RU_S_N,    RU_S_G,    RU_S_SH,   RU_S_SC,   RU_S_Z,
        RU_S_R,    RU_S_O,    RU_S_L,    RU_S_D,    RU_CMB_S_H,
        RU_S_T,    RU_CMB_S_SF,   RU_CMB_S_B,    RU_S_JU,   RU_CMB_S_ZH
        )

        //---------------------------------------------------------------------------
        [L_RED] = MY_layout(
            // LEFT HALF
            TG_RED,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
            CT_G,    WN_C_1,  WN_C_2,  WN_C_3,  WN_C_4,  WN_C_5,  WN_C_6,
            _______, _______, _______, _______, _______, _______,  CTL_C,
            _______, _______, _______, CS_G,  CT_G, CT_F,
            _______, _______, _______, _______, _______,
            _______, // LEFT RED THUMB KEY
            _______, _______, _______, // LEFT THUMB KEYS

            // RIGHT HALF
            KC_F7,   KC_F8,    KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______,
            _______, ARR_F_JS, AG_LPRN, AG_RPRN,  EN_LBRC, EN_RBRC, CT_TAB,
            _______, EN_ARR2,  EN_LCBR, EN_RCBR,  EN_LT,   EN_GT,   CS_TAB,
            AG_EQL,  EQ_JS,    NEQ_JS,  EN_GTEQ,  EN_LTEQ, EN_CLTG,
            _______, CT_LEFT,  CT_DOWN, CT_UP,    CT_RGHT,
            _______, // RIGHT RED THUMB KEY
            _______, _______, _______ // RIGHT THUMB KEYS
            ),

    //---------------------------------------------------------------------------
    [L_GREN] = MY_layout(
        // LEFT HALF
        TG_GREN, WN_C_1,  WN_C_2,  WN_C_3,  WN_C_4,  WN_C_5,  WN_C_6,
        KC_MUTE, KC_F5,   CS_T,    CT_T,    CT_W,     F6_CT_C,  _______,
        KC_VOLU, KC_MPRV, KC_MNXT, CT_PGUP, CT_C_F_V,  KC_MPLY,  CTL_C,
        KC_VOLD, KC_MPRV, KC_MNXT,    CT_1,    CT_2,     CS_C,
        _______, _______, _______, _______, _______,
        _______, // LEFT RED THUMB KEY
        _______, _______, _______, // LEFT THUMB KEYS

        // RIGHT HALF
        _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______,
        _______, _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______,
        _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,  _______,
        _______, _______, _______, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUbMB KEYS
        ),

    //---------------------------------------------------------------------------
    [L_VIOL] = MY_layout(
        // LEFT HALF
        TG_VIOL, _______, _______, _______, _______, _______, _______,
        AL_UP,   APP_8,   APP_7,   APP_6,   APP_5,   _______, _______,
        WN_Q,    APP_4,   APP_3,   APP_2,   APP_1,   _______, _______,
        KC_F2,   MY_APPS, _______, APP_0,   APP_9,   _______,
        _______, _______, _______, _______, _______,
        _______, // LEFT RED THUMB KEY
        _______, _______, _______, // LEFT THUMB KEYS

        // RIGHT HALF
        _______, _______, _______, _______, _______, _______, _______,
        _______, AC_SUB,  AG_4,    AG_5,    AG_6,    _______, _______,
        _______, AC_SUP,  AG_0,    AG_1,    AG_2,    AG_3,    _______,
        AC_CRCL, AG_9,    AG_8,    AG_7,    _______, _______,
        _______, _______, _______, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUMB KEYS
        ),

    //---------------------------------------------------------------------------
    [L_GRAY] = MY_layout(
        // LEFT HALF
        TG_GRAY, _______, _______, _______, _______, _______,  _______,
        _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,  _______,
        KC_BTN1, RP_001,  RP_003,  RP_002,  RP_004,  KC_BTN2,  _______,
        KC_LGUI, RP_005,  RP_007,  RP_006,  RP_008,  KC_BTN3,
        _______, _______, _______, _______, _______,
        _______, // LEFT RED THUMB KEY
        _______, _______, _______, // LEFT THUMB KEYS

        // RIGHT HALF
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUMB KEYS
        ),

    //---------------------------------------------------------------------------
    [L_CYAN] = MY_layout(
        // LEFT HALF
        TG_CYAN, _______, _______, _______, _______, _______,  _______,
        XC_NIN,  XC_IN,   XC_SBST, XC_DEGR, XC_PLMN, XC_MU,    _______,
        XC_MUSC, XC_LEFT, XC_DOWN, XC_UP,   XC_RGHT, XC_LMBD,  _______,
        XC_ANGL, XC_IFAI, XC_EXST, XC_ALL,  XC_THEN, XC_PI,
        _______, _______, _______, _______, _______,
        _______, // LEFT RED THUMB KEY
        _______, _______, _______, // LEFT THUMB KEYS

        // RIGHT HALF
        _______, _______, _______, _______, _______, _______, _______,
        _______, XC_CRSS, CMB_LCR, CMB_RCR, XC_APRX, XC_EMPT, XC_TM,
        _______, XC_DONE, CMB_LTR, CMB_RTR, XC_DASH, XC_TIMS, XC_NEQ,
        XC_SPRK, XC_TMBU, XC_TMBD, XC_BULL, XC_INF, XC_COPY,
        _______, _______, _______, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUMB KEYS
        ),

    //---------------------------------------------------------------------------
    [L_YELW] = MY_layout(
        // LEFT HALF
        TG_YELW, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD, RGB_TOG,
        RGB_PRT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, RGB_RMOD,RGB_LYR,
        RGB__0,  RGB__1,  RGB__2,  RGB__25, RGB__28, RGB__36, RGB__27,
        RGB__7,  RGB__13, RGB__15, RGB__16, RGB__17, _______,
        _______, _______, AU_TOG,  MU_TOG,  MU_MOD,
        RGB_PRT, // LEFT RED THUMB KEY
        PIC_0,   PIC_1,   PIC_2, // LEFT THUMB KEYS
        // RIGHT HALF
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, LED_1,   LED_2,   LED_3,   LED_4,   LED_5,   LED_6,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUMB KEYS
        ),


    //---------------------------------------------------------------------------
    [L_GAME] = MY_layout(
        // LEFT HALF
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_7,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_8,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CS_M,
        KC_LGUI, // LEFT RED THUMB KEY
        KC_SPC,  KC_LALT, KC_ENT, // LEFT THUMB KEYS

        // RIGHT HALF
        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TG_GAME,
        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, // RIGHT RED THUMB KEY
        XXXXXXX, XXXXXXX, XXXXXXX // RIGHT THUMB KEYS
        ),

    //---------------------------------------------------------------------------
    [L_NUCL] = MY_layout(
        // LEFT HALF
        TG_NUCL, KC_SLCK, KC_CAPS, KC_INS,  KC_PAUS, KC_PSCR, KC_APP,
        SYS_PRT, SYS_LIN, SYS_WIN, SYS_MAC, _______, _______, _______,
        _______, MU_LAN1, MU_LAN2, MU_LAN3, MU_LAN4, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, KC_RGUI,
        _______, // LEFT RED THUMB KEY
        KC_RCTL, KC_RSFT, _______, // LEFT THUMB KEYS

        // RIGHT HALF
        _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, RESET,
        _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
        _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PENT, _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, _______,
        KC_P0,   KC_PDOT, KC_PCMM, _______, _______,
        _______, // RIGHT RED THUMB KEY
        _______, _______, _______ // RIGHT THUMB KEYS
        ),
};

const ComboWithKeycode combos[] PROGMEM = {



    //Russian additional keys
    //Х+Ж = Э
    CHORD(RU_H, /* <- */ RU_CMB_H),
    CHORD(RU_ZH, /* <- */ RU_CMB_ZH),
    CHORD(RU_E, /* <- */ RU_CMB_ZH, RU_CMB_H ),

    CHORD(RU_S_H, /* <- */ RU_CMB_S_H),
    CHORD(RU_S_ZH, /* <- */ RU_CMB_S_ZH),
    CHORD(RU_S_E, /* <- */ RU_CMB_S_H, RU_CMB_S_ZH),

    //Б + Ь = Ъ
    CHORD(RU_B, /* <- */ RU_CMB_B),
    CHORD(RU_SF, /* <- */ RU_CMB_SF),
    CHORD(RU_HD, /* <- */ RU_CMB_B, RU_CMB_SF),

    CHORD(RU_S_B, /* <- */ RU_CMB_S_B),
    CHORD(RU_S_SF, /* <- */ RU_CMB_S_SF),
    CHORD(RU_S_HD, /* <- */ RU_CMB_S_B, RU_CMB_S_SF),


    //temporary arrows
    CHORD(TT_RED, BR_R5),
    CHORD(KC_LEFT, /* <- */ BR_R4),
    CHORD(KC_DOWN, /* <- */ BR_R3),
    CHORD(KC_UP, /* <- */ BR_R2),
    CHORD(KC_RIGHT, /* <- n*/ BR_R1),

    //bottom row left
    CHORD(TT_GREN, BR_L5),
    CHORD(TT_YELW, BR_L4),
    CHORD(KC_LALT, BR_L3),



    // Left Thumb
    IMMEDIATE_CHORD(SFT_N, SFT_N,     /* <-! */ TC_L1 ),
    CHORD(KC_BSPC, /* <- */ TC_L2), //backspace
    CHORD(KC_ENT, /* <- */ TC_L3), //enter
    CHORD(KC_LGUI, /* <- */ TC_LU), //CMD
    CHORD(LGUI(KC_BSPC), /* <- */ TC_L2, TC_LU), // cmd+ backspace
    CHORD(LALT(KC_BSPC), /* <- */ TC_L2, TC_L3), // alt + backspace
    CHORD(MU_SCR, /* <- */ TC_L2, TC_L3, TC_LU), //screenshot
    CHORD(CT_A,    /* <- */ TC_L1, TC_LU), // cmd + A

    //  // Right Thumb
    CHORD(MU_LANG, /* <- */ TC_R3), //language shift
    CHORD(LA_SYNC, /* <- */ TC_R3, TC_R2), // language sync
    CHORD(KC_SPC,  /* <- */ TC_R1), // space
    CHORD(KC_LCTL, TC_RU), // ctrl
    CHORD(AG_DOT, TC_R2), // dot
    CHORD(AG_SDOT, /* <- */ TC_R2, TC_R1), //dot+ space + next shift



    //  // Left Index

    CHORD(CT_T, MC_L1), // key1:cmd+T
    CHORD(CS_T, MC_LS1), // key1+ shift: cmd+shift+T
    CHORD(CT_C,    /* <- */ MC_L2), // key 2: copy
    CHORD(CT_V,    /* <- */ MC_L3), //key 3: paste
    CHORD(CT_X,    /* <- */ MC_L2, MC_L3), //key2 + key3: cut
    CHORD(CT_A_C,  /* <- */ MC_LS2),// key 2 + shift: ctrl+A + copy
    CHORD(CT_A_V,  /* <- */ MC_LS3), // key 3 + shift: ctrl+A + copy,
    CHORD(CT_A_X,  /* <- */ MC_LS2, MC_LS3),// key 3 +key2 + shift: ctrl+A + cut


    //Right Index
    CHORD(CT_W, MC_R1), //cmd+W
    CHORD(CS_W, MC_RS1), //cmd+shift+W
    CHORD(CT_S, MC_R2), //cmd + S
    CHORD(CO_L, MC_RS2), // cmd + Alt + L
    CHORD(AG_CMSP, MC_R3), // ,+ space
    CHORD(AG_COMM, MC_RS2, MC_R3), // ,


    //  // Right Thumb
    CHORD(MU_LANG, /* <- */ TC_R3),
    CHORD(LA_SYNC, /* <- */ TC_R3, TC_R2),
    CHORD(KC_SPC,  /* <- */ TC_R1),


//    CHORD(CT_T, MC_L1), //cmd+T
    //Left top row
    CHORD(KC_ESC, UR_L1), // Escape
    CHORD(AG_EXCL, UR_L2), // !
    CHORD(EN_AT, UR_L3), // @
    CHORD(EN_AMPR, UR_L4), // &
    CHORD(EN_PIPE, UR_L5), // |
    CHORD(EN_PERC, UR_L6), // %

    // Right top row
    CHORD(EN_CIRC, UR_R6), // ^
    CHORD(AG_QUES, UR_R5), // ?
    CHORD(EN_ASTR, UR_R4), // *
    CHORD(EN_QUOT, UR_R3), // '
    CHORD(AG_DQUO, /* <- */ UR_R2),// "
    CHORD(EN_GRV, UR_R3, UR_R2), // ` is " + '


    // total combos upper = 62
    //right outer column
    CHORD(AG_MINS, EC_R1), // -
    CHORD(EN_TILD, EC_S_R1), // ~
    CHORD(AG_SCLN, EC_R2), // ;
    CHORD(AG_COLN, EC_S_R2), // :
    CHORD(EN_SLSH, EC_R3), // /
    CHORD(EN_BSLS, EC_S_R3), // backslash

    //left outer column
    CHORD(AG_UNDS, EC_L1), // _
    CHORD(AG_UNDS, EC_S_L1), // _
    CHORD(KC_TAB, EC_L2), // tab
    CHORD(AG_PLUS, EC_S_L2), // +
    CHORD(AG_EQL, EC_L2, EC_L3), // =
    CHORD(EN_HASH, EC_S_L3), // #
    CHORD(EN_DLR, EC_L3), // $







    //  CHORD(KC_ENT,  /* <- */ CMB_ENT),
    //  IMMEDIATE_CHORD(CTRL_EN, CTRL_EN, /* <-! */ CMB_CTL),
    //  IMMEDIATE_CHORD(TT_GRAY, TT_UNDO, /* <-! */ CMB_SFT, CMB_BSP),
    //  CHORD(KC_DEL,  /* <- */ CMB_BSP, CMB_CTL),
    //  CHORD(CT_BSPC, /* <- */ CMB_BSP, CMB_ENT),
    //  CHORD(CTSH_EN, /* <- */ CMB_SFT, CMB_BSP, CMB_CTL),
    //  CHORD(MU_SCR,  /* <- */ CMB_BSP, CMB_ENT, CMB_CTL),
    //
    //  // Left Left Thumb
    //  IMMEDIATE_CHORD(TT_VIOL, TT_UNDO, /* <-! */ CMB_LYV),
    //  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_RED),
    //  IMMEDIATE_CHORD(TT_GREN, TT_UNDO, /* <-! */ CMB_LYG),
    //  IMMEDIATE_CHORD(TT_RED,  TT_UNDO, /* <-! */ CMB_LYV, CMB_LYG),
    //  IMMEDIATE_CHORD(TT_CYAN, TT_UNDO, /* <-! */ CMB_LYV, CMB_RED),
    //

    //  CHORD(AG_DOT,  /* <- */ CMB_DOT),
    //  CHORD(ALT_EN,  /* <- */ CMB_ALT),
    //  CHORD(AG_SDOT, /* <- */ CMB_DOT, CMB_SPC),
    //  CHORD(CTAL_EN, /* <- */ CMB_SPC, CMB_ALT),
    //  CHORD(SHAL_EN, /* <- */ CMB_DOT, CMB_ALT),
    //  CHORD(WIN_EN,  /* <- */ CMB_SPC, CMB_DOT, CMB_ALT),
    //  CHORD(MU_WNL,  /* <- */ CMB_LAN, CMB_DOT, CMB_ALT),
    //
    //  // -------------------------------------------------------------------------
    //  // Shifted index keys
    //
    //  // Left Index
    //  CHORD(CT_A_C,  /* <- */ CMB_CAC),
    //  CHORD(CT_A_V,  /* <- */ CMB_CAV),
    //  CHORD(CT_A_X,  /* <- */ CMB_CAC, CMB_CAV),
    //
    //  // -------------------------------------------------------------------------
    //  // Russian combos on letters
    //  CHORD(RU_R,    /* <- */ CMS_R),
    //  CHORD(RU_SH,   /* <- */ CMS_SH),
    //  CHORD(RU_HD,   /* <- */ CMS_R, CMS_SH),
    //  CHORD(RU_S_R,  /* <- */ CMS_S_R),
    //  CHORD(RU_S_SH, /* <- */ CMS_SSH),
    //  CHORD(RU_S_HD, /* <- */ CMS_S_R, CMS_SSH),
    //
    //  // -------------------------------------------------------------------------
    //  // Number row
    //
    //  // Left hand
    //  CHORD(AG_PLUS, /* <- */ CMB_PLS),
    //  CHORD(AG_SCLN, /* <- */ CMB_SCL),
    //  CHORD(EN_GRV,  /* <- */ CMB_GRV),
    //  CHORD(AG_EXCL, /* <- */ CMB_EXL),
    //  CHORD(AG_ASTR, /* <- */ CMB_ASR),
    //  CHORD(EN_TILD, /* <- */ CMB_PLS, CMB_EXL),
    //  CHORD(RU_NUME, /* <- */ CMB_PLS, CMB_ASR),
    //  CHORD(EN_QUOT, /* <- */ CMB_GRV, CMB_EXL),
    //  CHORD(AG_DQUO, /* <- */ CMB_SCL, CMB_GRV),
    //  CHORD(AG_PERC, /* <- */ CMB_SCL, CMB_EXL),
    //  CHORD(EN2QUOT, /* <- */ CMB_SCL, CMB_ASR),
    //  CHORD(AG2DQUO, /* <- */ CMB_SCL, CMB_GRV, CMB_EXL),
    //
    //  // Right hand
    //  CHORD(AG_SLSH, /* <- */ CMB_SLS),
    //  CHORD(AG_QUES, /* <- */ CMB_QUE),
    //  CHORD(AG_CMSP, /* <- */ CMB_CMM),
    //  CHORD(AG_COLN, /* <- */ CMB_CLN),
    //  CHORD(AG_EQL,  /* <- */ CMB_EQL),
    //  CHORD(EN_DLR,  /* <- */ CMB_SLS, CMB_CLN),
    //  CHORD(EN_HASH, /* <- */ CMB_SLS, CMB_EQL),
    //  CHORD(EN_PIPE, /* <- */ CMB_CMM, CMB_CLN),
    //  CHORD(EN_AMPR, /* <- */ CMB_QUE, CMB_CMM),
    //  CHORD(AG_BSLS, /* <- */ CMB_QUE, CMB_CLN),
    //  CHORD(EN2PIPE, /* <- */ CMB_QUE, CMB_EQL),
    //  CHORD(EN2AMPR, /* <- */ CMB_QUE, CMB_CMM, CMB_CLN),
    //
    //  // -------------------------------------------------------------------------
    //  // Brackets on red layer
    //  CHORD(AG_LPRN, /* <- */ CMB_LB1),
    //  CHORD(AG_RPRN, /* <- */ CMB_RB1),
    //  CHORD(EN_LBRC, /* <- */ CMB_LB2),
    //  CHORD(EN_RBRC, /* <- */ CMB_RB2),
    //  CHORD(EN_LCBR, /* <- */ CMB_LB3),
    //  CHORD(EN_RCBR, /* <- */ CMB_RB3),
    //  CHORD(EN_LT,   /* <- */ CMB_LB4),
    //  CHORD(EN_GT,   /* <- */ CMB_RB4),
    //  CHORD(AG_2B1,  /* <- */ CMB_LB1, CMB_RB1),
    //  CHORD(EN_2B2,  /* <- */ CMB_LB2, CMB_RB2),
    //  CHORD(EN_2B3,  /* <- */ CMB_LB3, CMB_RB3),
    //  CHORD(EN_2B4,  /* <- */ CMB_LB4, CMB_RB4),
    //
    //  // -------------------------------------------------------------------------
    //  // Brackets on XCompose layer
    //
    //  CHORD(XC_LTRE, /* <- */ CMB_LTR),
    //  CHORD(XC_RTRE, /* <- */ CMB_RTR),
    //  CHORD(XC_BTRE, /* <- */ CMB_LTR, CMB_RTR),
    //
    //  CHORD(XC_LCRN, /* <- */ CMB_LCR),
    //  CHORD(XC_RCRN, /* <- */ CMB_RCR),
    //  CHORD(XC_BCRN, /* <- */ CMB_LCR, CMB_RCR),
};
const uint8_t combos_size = sizeof(combos)/sizeof(ComboWithKeycode);

const uint16_t tt_keys[][3] = {
    { TT_CTJ, CT_J,  CT_BSLS }, // Убийство программы, если нажать три раза, то выдаёт Ctrl+\, что убивает безоговорочно.
    { TT_RED,  MO_RED,  TG_RED },
    { TT_GREN, MO_GREN, TG_GREN },
    { TT_VIOL, MO_VIOL, TG_VIOL },
    { TT_GRAY, MO_GRAY, TG_GRAY },
    { TT_CYAN, MO_CYAN, TG_CYAN },
    { TT_YELW, MO_YELW, TG_YELW },
    { TT_GAME, MO_GAME, TG_GAME },
    { TT_NUCL, MO_NUCL, TG_NUCL },
};
const uint8_t tt_size = sizeof(tt_keys)/(sizeof(uint16_t) * 3);

const uint16_t repeat_keys[][2] = {
    { RP_000, AR_L5 },
    { RP_001, MS_LF_1 },
    { RP_002, MS_UP_1 },
    { RP_003, MS_DN_1 },
    { RP_004, MS_RG_1 },
    { RP_005, MS_LF10 },
    { RP_006, MS_UP10 },
    { RP_007, MS_DN10 },
    { RP_008, MS_RG10 },
};
const uint8_t repeat_size = sizeof(repeat_keys)/(sizeof(uint16_t) * 2);

enum ledmap_colors {
    COLOR_BLACK = COLOR_SAFE_RANGE, // Чёрный цвет
    COLOR_ANYFN, // Цвет для кнопки, нажимаемой любым пальцем
    COLOR_PINKY, // Для кнопки нажимаемой мизинцем
    COLOR_ANNUL, // Безымянным
    COLOR_MIDDL, // Средним
    COLOR_INDEX, // Указательным
    COLOR_THUMB, // Большим пальцем
};

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL] = {
    [0] = {
        COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
        COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
        COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
        COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX,
        COLOR_THUMB,
        COLOR_THUMB, COLOR_THUMB, COLOR_THUMB,

        COLOR_ANYFN, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
        COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_PINKY, COLOR_ANYFN,
        COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANNUL, COLOR_ANYFN,
        COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_MIDDL, COLOR_THUMB,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_THUMB,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX, COLOR_INDEX,
        COLOR_INDEX, COLOR_INDEX, COLOR_INDEX,
        COLOR_THUMB,
        COLOR_THUMB, COLOR_THUMB, COLOR_THUMB
    },

    [1] = {
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________,
        ___________, ___________, ___________,
        COLOR_LAYER,
        COLOR_LAYER, COLOR_LAYER, COLOR_LAYER,

        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________, ___________,
        ___________, ___________, ___________, ___________,
        ___________, ___________, ___________,
        COLOR_LAYER,
        COLOR_LAYER, COLOR_LAYER, COLOR_LAYER
    },
};
const uint8_t ledmap_size = sizeof(ledmap)/(sizeof(uint8_t) * DRIVER_LED_TOTAL);

const uint8_t PROGMEM colormap[][3] = {
    [COLOR_BLACK] = { 0, 0, 0 },
    [COLOR_ANYFN] = { 0, 0, 255 },
    [COLOR_PINKY] = { 31, 255, 255 },
    [COLOR_ANNUL] = { 164, 255, 255 },
    [COLOR_MIDDL] = { 76, 255, 255 },
    [COLOR_INDEX] = { 224, 255, 255 },
    [COLOR_THUMB] = { 8, 255, 255 },
};
const uint8_t colormap_size = sizeof(colormap)/(sizeof(uint8_t) * 3);

const uint8_t PROGMEM layermap[][3] = {
    [L_EN] = { 0, 0, 255 },
    [L_EN_S] = { 0, 0, 192 },

    [L_RU] = { 164, 255, 255 },
    [L_RU_S] = { 164, 255, 192 },

    [L_RED] = { 0, 255, 210 },
    [L_GREN] = { 76, 255, 255 },
    [L_VIOL] = { 188, 255, 255 },
    [L_GRAY] = { 0, 0, 128 },
    [L_CYAN] = { 128, 255, 255 },

    [L_YELW] = { 35, 255, 255 },
    [L_GAME] = { 228, 255, 255 },

    [L_NUCL] = { 8, 255, 255 },
};
const uint8_t layermap_size = sizeof(layermap)/(sizeof(uint8_t) * 3);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_my_music_keys(keycode, record)) {
        return false;
    }

    if (!combo_process_record(keycode, record)) {
        return false;
    }

    if (!tt_process_record(keycode, record)) {
        return false;
    }

    if (!rp_process_record(keycode, record)) {
        return false;
    }

    if (!process_my_lang_keys(keycode, record)) {
        return false;
    }

    if (!process_my_xcompose(keycode, record)) {
        return false;
    }

    if (!lang_shift_process_record(keycode, record)) {
        return false;
    }

    if (!color_process_record(keycode, record)) {
        return false;
    }

    if (!process_my_hotkeys(keycode, record)) {
        return false;
    }

    if (!process_system_keys(keycode, record)) {
        return false;
    }

    if (!process_moonlander_leds(keycode, record)) {
        return false;
    }

    if (!process_mouse_pixel_move(keycode, record)) {
        return false;
    }

    return true;
}

float error_song1[][2] = SONG(MUSIC_OFF_SOUND);
void combo_max_count_error(void) {
    PLAY_SONG(error_song1);
    uprintf("COMBO ERROR: MAX COMBOS COUNT HAS REACHED\n");
}

float error_song2[][2] = SONG(VOICE_CHANGE_SOUND);
void combo_max_size_error(void) {
    PLAY_SONG(error_song2);
    uprintf("COMBO ERROR: MAX COMBO SIZE HAS REACHED\n");
}

void repeated_key_error(void) {
    PLAY_SONG(error_song2);
    uprintf("REPEATED KEY ERROR\n");
}

void user_timer(void) {
    combo_user_timer();
    lang_shift_user_timer();
    rp_timer();
}

void matrix_scan_user(void) {
    user_timer();
}

// Нужно для color.h
void rgb_matrix_indicators_user(void) {
    color_rgb_matrix_indicators();
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}
