#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _Base,
    _Numpad,
    _Arrows,
    _Gaming,
};


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
                        TG(3),KC_LALT,KC_LCTRL, MO(2), KC_SPC,      KC_SPC,  MO(1), KC_RGUI, KC_RALT, KC_RCTL \
    ),
    /* Layer 1
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |numlck| num/ | num* | num- |      |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      | num7 | num8 | num9 | num+ |      |                    |   6  |   7  |   8  |   9  |   0  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | num4 | num5 | num6 |nument|      |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * | Shift| num1 | num2 | num3 | num0 |      _-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_Numpad] = LAYOUT( \
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO, \
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_TRNS, \
        KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                 KC_NO, KC_P4,   KC_P5,   KC_P6,   KC_PENT, KC_TRNS, \
        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_TRNS, \
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    ),
    /* Layer 2
    * ,----------------------------------------.                     ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Esc  | Ins  | Pscr | Menu |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      |      |      |      |      |      |
    * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
    * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|  - _ |  = + |  [ { | ] }  |  \ | |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |/       /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */

    [_Arrows] = LAYOUT( \
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
        LCTL(KC_TAB), KC_PSCR, LCTL(KC_W), KC_NO, KC_F12, LCTL(KC_T),                   KC_HOME, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), KC_PGUP, LCTL(KC_BSPC), \
        KC_LSFT, LCTL(KC_A), LCTL(KC_S), LCTL(KC_D), LCTL(KC_F), LCTL(KC_G),      KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, LCTL(KC_ENT), \
        KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_NO,   KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, LCTL(KC_DEL), \
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    ),

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
    [_Gaming] = LAYOUT( \
        KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_QUOT, \
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, \
        KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT, \
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,  KC_M,     KC_COMM, KC_DOT,  KC_SLSH,  KC_DEL, \
                        TG(3),KC_LALT,KC_LCTRL, KC_SPC, KC_SPC,      KC_SPC,  MO(1), KC_RGUI, KC_RALT, KC_RCTL \
    ),


};

#ifdef OLED_ENABLE


static void render_eevee(void){
	static const char PROGMEM eevee[] = {// 'eevee', 32x31px
		0x00, 0x0e, 0x72, 0x8a, 0x74, 0xe4, 0x98, 0x70, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x80, 0x80, 
		0x00, 0x80, 0x40, 0xa0, 0xd0, 0xc8, 0xe8, 0xe4, 0x74, 0xb4, 0x5a, 0x2a, 0x12, 0x0e, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x01, 0x02, 0xfd, 0x04, 0x38, 0x74, 0x38, 0x00, 0x80, 0x00, 0x38, 0x74, 0x38, 
		0x01, 0x01, 0xe0, 0x7d, 0x05, 0x05, 0x02, 0x82, 0xc1, 0x40, 0xf0, 0x1f, 0x02, 0x0c, 0x70, 0x80, 
		0x00, 0x00, 0x00, 0x38, 0xc4, 0x82, 0xe3, 0x12, 0x04, 0x04, 0x0d, 0x0d, 0x0d, 0x2e, 0x2e, 0x42, 
		0x83, 0x01, 0x03, 0x82, 0x9c, 0x66, 0xc3, 0x01, 0x00, 0x00, 0x01, 0x03, 0x84, 0xc4, 0x76, 0x0f, 
		0x00, 0x00, 0x00, 0x07, 0x08, 0x1c, 0x11, 0x0f, 0x06, 0x04, 0x04, 0x04, 0x34, 0x5e, 0x4b, 0x41, 
		0x61, 0x1f, 0x04, 0x37, 0x2c, 0x20, 0x33, 0x1c, 0x06, 0x02, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00
	};

	oled_write_raw_P(eevee, sizeof(eevee));

};


static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _Arrows:
            oled_write_P(PSTR("Arrow"), false);
            break;
        case _Numpad:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _Gaming:
            oled_write_P(PSTR("Game\n"), false);
            break;
        default:
            oled_write_P(PSTR("???\n"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
    
    render_eevee();

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

    }

}

void suspend_power_down_user(void) {
    oled_off();
}

#endif
