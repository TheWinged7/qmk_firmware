#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _Base,
    _Symbols,
    _Arrows,
    _Numpad,
};

// enum custom_keycodes {
//     KC_Base = SAFE_RANGE,
//     KC_Symbols,
//     KC_Arrows,
//     KC_Numpad,
//     KC_PRVWD,
//     KC_NXTWD,
//     KC_LSTRT,
//     KC_LEND,
//     KC_DLINE
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *  Layer 0
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |   `  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_Base] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_QUOT, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT, \
  KC_GRV,   KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,  KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL, \
                 MO(3),KC_LALT,KC_LCTRL, MO(2), KC_SPC,      KC_SPC,  MO(1), KC_RGUI, KC_RALT, KC_RCTL \
),
/* Layer 2
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_Symbols] = LAYOUT( \
  KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12, \
  KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, \
  KC_TRNS,  KC_EQL, KC_PIPE, KC_PLUS, KC_SCLN, KC_COLN, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_LBRC, KC_RBRC, KC_TRNS, \
                       KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS,       KC_TRNS, MO(4), KC_TRNS, KC_TRNS, KC_TRNS\
),
/* Layer 3
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_Arrows] = LAYOUT( \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS, \
  LCTL(KC_TAB), KC_PSCR, LCTL(KC_W), KC_NO, KC_APP, LCTL(KC_T),                   KC_HOME, KC_DEL, KC_UP, LCTL(KC_BSPC), KC_PGUP, KC_BSPC, \
  KC_TRNS, LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G),            KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, LCTL(KC_ENT), \
  KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS,    KC_TRNS, KC_NO, LCTL(KC_LEFT), KC_NO, LCTL(KC_RGHT), KC_NO, KC_TRNS, \
             KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
),
/* Layer 4
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |numlck| num/ | num* | num- |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      | num7 | num8 | num9 | num+ |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | num4 | num5 | num6 |nument|      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | num1 | num2 | num3 | num0 |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |       | /      /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_Numpad] = LAYOUT( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_P4,   KC_P5,   KC_P6,   KC_PENT, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO,  KC_NO, KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_NO, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  )
};

#ifdef OLED_ENABLE



static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };
    oled_write_P(qmk_logo, false);
}


static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _Symbols:
            oled_write_P(PSTR("Symb"), false);
            break;
        case _Arrows:
            oled_write_P(PSTR("Arrow"), false);
            break;
        case _Numpad:
            oled_write_P(PSTR("Num"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
       render_logo();
    }
}

#endif

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case KC_Base:
//         //     if (record->event.pressed) {
//         //         set_single_persistent_default_layer(_Base);
//         //     }
//         //     return false;
//         case KC_Symbols:
//             if (record->event.pressed) {
//                 layer_on(_Symbols);
//                 update_tri_layer(_Symbols, _Arrows, _Numpad);
//             } else {
//                 layer_off(_Symbols);
//                 update_tri_layer(_Symbols, _Arrows, _Numpad);
//             }
//             return false;
//         case KC_Arrows:
//             if (record->event.pressed) {
//                 layer_on(_Arrows);
//                 update_tri_layer(_Symbols, _Arrows, _Numpad);
//             } else {
//                 layer_off(_Arrows);
//                 update_tri_layer(_Symbols, _Arrows, _Numpad);
//             }
//             return false;
//         case KC_Numpad:
//             if (record->event.pressed) {
//                 layer_on(_Numpad);
//             } else {
//                 layer_off(_Numpad);
//             }
//             return false;
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             break;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             break;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             break;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             break;
//         case KC_DLINE:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_BSPC);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_BSPC);
//             }
//             break;
//         case KC_COPY:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_C);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_C);
//             }
//             return false;
//         case KC_PASTE:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_V);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_V);
//             }
//             return false;
//         case KC_CUT:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_X);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_X);
//             }
//             return false;
//             break;
//         case KC_UNDO:
//             if (record->event.pressed) {
//                 register_mods(mod_config(MOD_LCTL));
//                 register_code(KC_Z);
//             } else {
//                 unregister_mods(mod_config(MOD_LCTL));
//                 unregister_code(KC_Z);
//             }
//             return false;
//     }
//     return true;
// }
