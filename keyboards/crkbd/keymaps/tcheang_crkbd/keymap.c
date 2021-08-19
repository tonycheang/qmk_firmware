/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

#define L_BASE 0
#define L_LSYM 1
#define L_RSYM 2
#define L_NAV 3
#define L_NUM 4
#define L_BVIM 5
#define L_FVIM 6
#define L_MISC 7

enum custom_keycodes {
  ST_MACRO_0 = SAFE_RANGE,  // Tmux Left Pane
  ST_MACRO_1,               // Tmux Right Pane
  ST_MACRO_2,               // Tmux Copy Mode
  ST_MACRO_3,               // Vim [p
  ST_MACRO_4,               // Vim [e
  ST_MACRO_5,               // Vim [q
  ST_MACRO_6,               // Vim [[
  ST_MACRO_7,               // Vim []
  ST_MACRO_8,               // Vim [c
  ST_MACRO_9,               // Vim [l
  ST_MACRO_10,              // Vim [m
  ST_MACRO_11,              // Vim [M
  ST_MACRO_12,              // Vim [[
  ST_MACRO_13,              // Vim []
  ST_MACRO_14,              // Vim [z
  ST_MACRO_15,              // Vim ]p
  ST_MACRO_16,              // Vim ]e
  ST_MACRO_17,              // Vim ]q
  ST_MACRO_18,              // Vim ][
  ST_MACRO_19,              // Vim ]]
  ST_MACRO_20,              // Vim ]c
  ST_MACRO_21,              // Vim ]l
  ST_MACRO_22,              // Vim ]m
  ST_MACRO_23,              // Vim ]M
  ST_MACRO_24,              // Vim ][
  ST_MACRO_25,              // Vim ]]
  ST_MACRO_26,              // Vim ]z
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
             KC_TAB,       KC_QUOT,       KC_COMM,        KC_DOT,           KC_P,          KC_Y,                                  KC_F,           KC_G,          KC_C,          KC_R,          KC_L,   OSL(L_LSYM),
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
        OSL(L_RSYM),  LCTL_T(KC_A),  LALT_T(KC_O),   LCMD_T(KC_E),          KC_U,          KC_I,                                  KC_D,           KC_H,  RCMD_T(KC_T),  RALT_T(KC_N),  RCTL_T(KC_S),        KC_ENT,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
      OSM(MOD_LSFT),     KC_SCOLON,        KC_Q, LT(L_BVIM, KC_J), LT(L_FVIM, KC_K),       KC_X,                                KC_B, LT(L_BVIM, KC_M), LT(L_FVIM, KC_W),       KC_V,          KC_Z, OSM(MOD_LSFT),
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         OSL(L_MISC), LT(L_NUM, KC_ESC), KC_SPC,    KC_BSPC,    OSL(L_NAV),      KC_DELETE
                                                                      //`----------------------------------'   `-------------------------------------'

  ),

  [L_LSYM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_DQUO,       KC_LABK,       KC_RABK,       KC_EQUAL,      KC_GRAVE,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_EXLM,         KC_AT,       KC_HASH,         KC_DLR,       KC_PERC,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_COLN,        KC_TRNS,       KC_LCBR,        KC_RCBR,       KC_TILD,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'

  ),

  [L_RSYM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_PIPE,        KC_LPRN,       KC_RPRN,       KC_PLUS,       KC_QUES,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_CIRC,        KC_AMPR,       KC_ASTR,      KC_MINUS,      KC_SLASH,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_TRNS,    KC_LBRACKET,   KC_RBRACKET,       KC_UNDS,     KC_BSLASH,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  ),

  [L_NAV] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_TRNS,       KC_HOME,        KC_UP,          KC_END,       KC_PGUP,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_LEFT,       KC_DOWN,       KC_RIGHT,     KC_PGDOWN,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,    ST_MACRO_0,       KC_TRNS,     ST_MACRO_1,       KC_TRNS,                               KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  ),

  [L_NUM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_TRNS,    KC_TRNS, LGUI(LSFT(KC_4)), LGUI(LSFT(KC_4)),  ST_MACRO_2,                               KC_TRNS,           KC_7,          KC_8,          KC_9,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_TRNS,           KC_4,          KC_5,          KC_6,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_TRNS,           KC_1,          KC_2,          KC_3,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,          KC_0,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  ),

  [L_BVIM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,     ST_MACRO_3,       KC_TRNS,                               KC_TRNS,        KC_TRNS,    ST_MACRO_8,       KC_TRNS,    ST_MACRO_9,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,    ST_MACRO_4,        KC_TRNS,       KC_TRNS,                               KC_TRNS,    ST_MACRO_10,   ST_MACRO_11,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,    ST_MACRO_5,    ST_MACRO_6,     ST_MACRO_7,       KC_TRNS,                               KC_TRNS,    ST_MACRO_12,   ST_MACRO_13,       KC_TRNS,   ST_MACRO_14,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  ),

  [L_FVIM] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,    ST_MACRO_15,       KC_TRNS,                               KC_TRNS,        KC_TRNS,   ST_MACRO_20,       KC_TRNS,   ST_MACRO_21,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,   ST_MACRO_16,        KC_TRNS,       KC_TRNS,                               KC_TRNS,    ST_MACRO_22,   ST_MACRO_23,       KC_TRNS,       KC_TRNS,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,   ST_MACRO_17,   ST_MACRO_18,    ST_MACRO_19,       KC_TRNS,                               KC_TRNS,    ST_MACRO_24,   ST_MACRO_25,       KC_TRNS,   ST_MACRO_26,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  ),

  [L_MISC] = LAYOUT_split_3x6_3(
  //,------------------------------------------------------------------------------------------.                       ,------------------------------------------------------------------------------------------.
            RGB_TOG,       RGB_HUI,       RGB_SAI,       RGB_VAI,        KC_TRNS,       KC_TRNS,                               KC_TRNS,          KC_F7,         KC_F8,         KC_F9,        KC_F10,         RESET,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,                               KC_TRNS,          KC_F4,         KC_F5,         KC_F6,        KC_F11,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
            RGB_MOD,       RGB_HUD,       RGB_SAD,       RGB_VAD,        KC_TRNS,       KC_TRNS,                               KC_TRNS,          KC_F1,         KC_F2,         KC_F3,        KC_F12,       KC_TRNS,
  //|--------------+--------------+--------------+--------------+---------------+--------------|                       |--------------+---------------+--------------+--------------+--------------+--------------|
                                                                         KC_TRNS,       KC_TRNS, KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS
                                                                      //`----------------------------------'   `-------------------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case L_LSYM:
            oled_write_ln_P(PSTR("Left Symbol"), false);
            break;
        case L_RSYM:
            oled_write_ln_P(PSTR("Right Symbol"), false);
            break;
        case L_NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_BVIM:
            oled_write_ln_P(PSTR("Back Vim"), false);
            break;
        case L_FVIM:
            oled_write_ln_P(PSTR("Forward Vim"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_O));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_I));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LBRACKET));
    }
    break;
    /* case ST_MACRO_3: */
    /* if (record->event.pressed) { */
    /*   SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_P)); */
    /* } */
    /* break; */
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_Q));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_LBRACKET));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_C));
    }
    break;
    /* case ST_MACRO_9: */
    /* if (record->event.pressed) { */
    /*   SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_L)); */
    /* } */
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_M));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_LSFT(SS_TAP(X_M)));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_LBRACKET));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_Z));
    }
    break;
    /* case ST_MACRO_15: */
    /* if (record->event.pressed) { */
    /*   SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_P)); */
    /* } */
    /* break; */
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_E));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_Q));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_LBRACKET));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_C));
    }
    break;
    /* case ST_MACRO_21: */
    /* if (record->event.pressed) { */
    /*   SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_L)); */
    /* } */
    /* break; */
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_LSFT(SS_TAP(X_M)));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_M));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_LBRACKET));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_RBRACKET));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_Z));
    }
    break;
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
