// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
  MCRO_TMUX_LEFT = SAFE_RANGE,  // Macro Tmux Left Pane
  MCRO_TMUX_RIGHT,              // Macro Tmux Right Pane
  MCRO_TMUX_COPY,               // Macro Tmux Copy Mode
  MCRO_TMUX_PANE,               // Macro Tmux New Pane

  MCRO_BACK_c,                  // Vim [c  -- Nav to prev hunk
  MCRO_BACK_e,                  // Vim [e  -- Nav to prev error
  MCRO_BACK_l,                  // Vim [l  -- Nav to prev loclist
  MCRO_BACK_m,                  // Vim [m  -- Nav to prev method start
  MCRO_BACK_M,                  // Vim [M  -- Nav to prev method end
  MCRO_BACK_p,                  // Vim [p  -- Paste to current indent, bef cursorline
  MCRO_BACK_q,                  // Vim [q  -- Nav to prev quickfix
  MCRO_BACK_z,                  // Vim [z  -- Nav to prev fold
  MCRO_BACK_LBRC,               // Vim [[  -- Nav to prev class start
  MCRO_BACK_RBRC,               // Vim []  -- Nav to prev class end

  MCRO_FWD_c,                   // Vim ]c  -- Nav to next hunk
  MCRO_FWD_e,                   // Vim ]e  -- Nav to next error
  MCRO_FWD_l,                   // Vim ]l  -- Nav to next loclist
  MCRO_FWD_m,                   // Vim ]m  -- Nav to next method start
  MCRO_FWD_M,                   // Vim ]M  -- Nav to next method end
  MCRO_FWD_p,                   // Vim ]p  -- Paste to current indent, aft cursorline
  MCRO_FWD_q,                   // Vim ]q  -- Nav to next quickfix
  MCRO_FWD_z,                   // Vim ]z  -- Nav to next fold
  MCRO_FWD_LBRC,                // Vim ][  -- Nav to next class end
  MCRO_FWD_RBRC,                // Vim ]]  -- Nav to next class start
};

enum layers {
    _DVORAK,
    _LSYM,
    _RSYM,
    _NAV,
    _NUM,
    _BVIM,
    _FVIM,
    _QWERTY,
    _MISC
};

// TODO: OLEDs

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | NONE |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | MISC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   C  |   C  |   R  |   L  |  SYM |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | SYM  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  ENT |
 * |------+------+------+------+------+------|  NONE |    | NONE  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |   [  |   ]  |ESCNUM| /Space  /       \ BSPC \  |  NAV |  DEL |QWERTY|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT(
  _______,         KC_1,          KC_2,           KC_3,            KC_4,            KC_5,                       KC_6,             KC_7,            KC_8,            KC_9,           KC_0,           MO(_MISC),
  KC_TAB,          KC_QUOT,       KC_COMM,        KC_DOT,          KC_P,            KC_Y,                       KC_F,             KC_G,            KC_C,            KC_R,           KC_L,           OSL(_LSYM),
  OSL(_RSYM),      LCTL_T(KC_A),  LALT_T(KC_O),   LCMD_T(KC_E),    KC_U,            KC_I,                       KC_D,             KC_H,            RCMD_T(KC_T),    RALT_T(KC_N),   RCTL_T(KC_S),   KC_ENT,
  OSM(MOD_LSFT),   KC_COLON,     KC_Q,           LT(_BVIM, KC_J), LT(_FVIM, KC_K), KC_X, _______,    _______,  LT(_BVIM, KC_B),  LT(_FVIM, KC_M), KC_W,            KC_V,           KC_Z,           OSM(MOD_LSFT),
                                                      KC_LBRC,  KC_RBRC, LT(_NUM, KC_ESC), KC_SPC,          KC_BSPC, OSL(_NAV), KC_DELETE, TG(_QWERTY)
),

/* LEFT SYMBOL (LSYM)                                             RIGHT SYMBOL (RSYM)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   "  |   <  |   >  |   =  |   `  |                    |   |  |   (  |   )  |   +  |   ?  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   -  |   /  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   :  |      |   {  |   }  |   ~  |-------|    |-------|      |   [  |   ]  |   _  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LSYM] = LAYOUT(
  _______, _______,   _______,  _______,  _______,  _______,                    _______, _______, _______,_______, _______, _______,
  _______, KC_DQUO,   KC_LABK,  KC_RABK,  KC_EQUAL, KC_GRAVE,                   _______, _______, _______, _______, _______, _______,
  _______, KC_EXLM,   KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                    _______, _______, _______, _______, _______, _______,
  _______, KC_COLN,   _______,  KC_LCBR,  KC_RCBR,  KC_TILD, _______,  _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______,            _______, _______, _______, _______
),
[_RSYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______,     _______,     _______,  _______,   _______,
  _______, _______, _______, _______, _______, _______,                   KC_PIPE, KC_LPRN,     KC_RPRN,     KC_PLUS,  KC_QUES,   _______,
  _______, _______, _______, _______, _______, _______,                   KC_CIRC, KC_AMPR,     KC_ASTR,     KC_MINUS, KC_SLASH,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC,     KC_RBRC,     KC_UNDS,  KC_BSLS,   _______,
                         _______, _______, _______, _______,          _______, _______, _______, _______
),

/* _NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | HOME |  UP  |  END | PGUP |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | LEFT | DOWN | RIGHT| PGDN |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | TRIG |      | TLFT |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NAV] = LAYOUT(
  _______, _______, _______,        _______,  _______,          _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______,  KC_HOME,       KC_UP,    KC_END,           KC_PGUP,                   _______, _______, _______, _______, _______, _______,
  _______, _______,  KC_LEFT,       KC_DOWN,  KC_RIGHT,         KC_PGDN,                   _______, _______, _______, _______, _______, _______,
  _______, _______,  MCRO_TMUX_LEFT, _______, MCRO_TMUX_RIGHT,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______, _______,         _______, _______, _______, _______
  ),

/* _NUM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |SSFULL|SSSNIP|TCOPY |                    |      |   7  |   8  |   9  |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |TPANE |-------.    ,-------|      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |   0  |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUM] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,            KC_F4,            KC_F5,                     KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
  _______, _______, _______, LGUI(LSFT(KC_3)), LGUI(LSFT(KC_4)), MCRO_TMUX_COPY,            _______, KC_7,  KC_8,  KC_9, _______, KC_F12,
  _______, _______, _______, _______,          _______,          MCRO_TMUX_PANE,            _______, KC_4,  KC_5,  KC_6, _______, _______,
  _______, _______, _______, _______,          _______,          _______, _______, _______, _______, KC_1,  KC_2,  KC_3, _______, _______,
                                    _______,          _______,        _______, _______,        _______,  KC_0, _______, _______
  ),

/* _BVIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  [p  |      |                    |      |      |  [c  |      |  [l  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  [e  |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  [q  |  [[  |  []  |      |-------|    |-------|      |  [M  |  [m  |      |  [z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_BVIM] = LAYOUT(
  _______, _______, _______,     _______,          _______,          _______,                    _______, _______,     _______,     _______, _______,     _______,
  _______, _______, _______,     _______,          MCRO_BACK_p,      _______,                    _______, _______,     MCRO_BACK_c, _______, MCRO_BACK_l, _______,
  _______, _______, _______,     MCRO_BACK_e,      _______,          _______,                    _______, _______,     _______,     _______, _______,     _______,
  _______, _______, MCRO_BACK_q, MCRO_BACK_LBRC,   MCRO_BACK_RBRC,   _______, _______,  _______, _______, MCRO_BACK_M, MCRO_BACK_m, _______, MCRO_BACK_z, _______,
                                     _______, _______, _______, _______,         _______, _______, _______, _______
  ),

/* _FVIM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |  ]p  |      |                    |      |      |  ]c  |      |  ]l  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  ]e  |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |  [q  |  ]]  |  ]]  |      |-------|    |-------|      |  ]M  |  ]m  |      |  ]z  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FVIM] = LAYOUT(
  _______, _______, _______,    _______,         _______,         _______,                    _______, _______,    _______,    _______, _______,    _______,
  _______, _______, _______,    _______,         MCRO_FWD_p,      _______,                    _______, _______,    MCRO_FWD_c, _______, MCRO_FWD_l, _______,
  _______, _______, _______,    MCRO_FWD_e,      _______,         _______,                    _______, _______,    _______,    _______, _______,    _______,
  _______, _______, MCRO_FWD_q, MCRO_FWD_LBRC,   MCRO_FWD_RBRC,   _______, _______,  _______, _______, MCRO_FWD_M, MCRO_FWD_m, _______, MCRO_FWD_z, _______,
                                     _______, _______, _______, _______,        _______, _______, _______, _______
  ),

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LALT,    KC_LGUI, _______, KC_SPC,         KC_BSPC,  _______,   KC_ENT,   _______
  ),

/* _MISC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |RGBTOG|      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MISC] = LAYOUT(
  _______, _______, _______, _______,  _______,  _______,                   _______, _______, _______, _______, _______, _______,
  _______, RGB_HUI, RGB_SAI, RGB_VAI,  RGB_MOD,  _______,                   _______, _______, DT_UP, _______, _______, _______,
  _______, RGB_HUD, RGB_SAD, RGB_VAD,  RGB_RMOD,  _______,                   _______, _______, DT_DOWN, _______, _______, _______,
  _______, RGB_TOG,  _______, _______, _______,  _______, _______, _______, _______, _______, DT_PRNT, _______, _______, _______,
                            _______, _______, _______, _______,         _______, _______, _______, _______
  )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
          tap_code16(LCTL(KC_R));
        } else {
          tap_code(KC_U);
        }
    }
    else if (index == 1) {
        if (clockwise) {
          tap_code16(LGUI(KC_Y));
        } else {
          tap_code16(LGUI(KC_Z));
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MCRO_TMUX_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "o");
      }
      break;
    case MCRO_TMUX_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "i");
      }
      break;
    case MCRO_TMUX_COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) "[");
      }
      break;
    case MCRO_TMUX_PANE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a") SS_DELAY(50) SS_LCTL("c"));
      }
      break;


    case MCRO_BACK_c:                  // Vim [c  -- Nav to prev hunk
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "c");
      }
      break;
    case MCRO_BACK_e:                  // Vim [e  -- Nav to prev error
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "e");
      }
      break;
    case MCRO_BACK_l:                  // Vim [l  -- Nav to prev loclist
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "l");
      }
      break;
    case MCRO_BACK_m:                  // Vim [m  -- Nav to prev method start
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "m");
      }
      break;
    case MCRO_BACK_M:                  // Vim [M  -- Nav to prev method end
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "M");
      }
      break;
    case MCRO_BACK_p:                  // Vim [p  -- Paste to current indent, bef cursorline
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "p");
      }
      break;
    case MCRO_BACK_q:                  // Vim [q  -- Nav to prev quickfix
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "q");
      }
      break;
    case MCRO_BACK_z:                  // Vim [z  -- Nav to prev fold
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "z");
      }
      break;
    case MCRO_BACK_LBRC:             // Vim [[  -- Nav to prev class start
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "[");
      }
      break;
    case MCRO_BACK_RBRC:             // Vim []  -- Nav to prev class end
      if (record->event.pressed) {
        SEND_STRING("[" SS_DELAY(50) "]");
      }
      break;


    case MCRO_FWD_c:                   // Vim ]c  -- Nav to next hunk
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "c");
      }
      break;
    case MCRO_FWD_e:                   // Vim ]e  -- Nav to next error
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "e");
      }
      break;
    case MCRO_FWD_l:                   // Vim ]l  -- Nav to next loclist
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "l");
      }
      break;
    case MCRO_FWD_m:                   // Vim ]m  -- Nav to next method start
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "m");
      }
      break;
    case MCRO_FWD_M:                   // Vim ]M  -- Nav to next method end
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "M");
      }
      break;
    case MCRO_FWD_p:                   // Vim ]p  -- Paste to current indent, aft cursorline
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "p");
      }
      break;
    case MCRO_FWD_q:                   // Vim ]q  -- Nav to next quickfix
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "q");
      }
      break;
    case MCRO_FWD_z:                   // Vim ]z  -- Nav to next fold
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "z");
      }
      break;
    case MCRO_FWD_LBRC:              // Vim ][  -- Nav to next class end
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "[");
      }
      break;
    case MCRO_FWD_RBRC:              // Vim ]]  -- Nav to next class start
      if (record->event.pressed) {
        SEND_STRING("]" SS_DELAY(50) "]");
      }
      break;
  }
  return true;
}
