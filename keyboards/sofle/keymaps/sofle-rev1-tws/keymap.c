#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _Base,
    _Arrows,
    _Gaming,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *  Layer 0
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ` ~  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  ; : | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  | Bspc |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  | , <  | . >  |  / ? |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Game | LAlt | LCTR |Arrows| /Space  /       \RShift\  |Enter | Win  | RAlt | RCTR |
     *            | mode |      |      | mode |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_Base] = LAYOUT( \
                KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, \
                KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_DEL, \
                KC_LSFT, KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_BSPC, \
                KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_NO, KC_NO,KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_NO, \
                TG(2), KC_LALT, KC_LCTL, OSL(1), KC_SPC, KC_RSFT, KC_ENT, KC_RGUI, KC_RALT, KC_RCTL \
                ),
    /* Layer 1
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | Pscr | Ins  | PG Up|      |      |                    | Home |      |  UP  |      |      | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift| Del  | End  |PG DWN|      |      |-------.    ,-------| End  | LEFT | DOWN | RIGHT|  ' " |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      _-------|    |-------|  - _ |  = + | [ {  | ] }  |  \ | |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Game | LAlt | LCTR |Arrows| /Space  /       \RShift\  |Enter | Win  | RAlt | RCTR |
     *            | mode |      |      | mode |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_Arrows] = LAYOUT( \
                    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
                    KC_TRNS, KC_NO, KC_PSCR, KC_HOME, KC_PGUP, KC_NO, KC_HOME, KC_NO, KC_UP, KC_NO, KC_NO, KC_F12, \
                    KC_TRNS, KC_NO, KC_DEL, KC_END, KC_PGDN, KC_NO, KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, KC_NO, \
                    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, \
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
                    ),
    /* Layer 2
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |  UP  |   O  |   P  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  | LEFT | DOWN | RIGHT|  ; : | Bspc |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | , <  | . >  |  / ? |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | Game | LAlt | LCTR |Space | /Space  /       \RShift\  |Enter | Win  | RAlt | RCTR |
     *            | mode |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_Gaming] = LAYOUT( \
                    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, \
                    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_UP, KC_O, KC_P, KC_DEL, \
                    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_BSPC, \
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, \
                    TG(2), KC_LALT, KC_LCTL, KC_SPC, KC_SPC, KC_TRNS, KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL \
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
    }
    return false;
}

void suspend_power_down_user(void) {
    oled_off();
}

#endif
