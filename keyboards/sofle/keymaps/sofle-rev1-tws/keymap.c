#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _Base,
    _Arrows,
    _Gaming,
};


#ifdef LEADER_ENABLE
    LEADER_EXTERNS();
    void matrix_scan_user(void) {
        LEADER_DICTIONARY() {
            leading = false;
            leader_end();
            // When I press KC_LEAD and then 9, this sends [
            SEQ_ONE_KEY(KC_9) {
                SEND_STRING("[");   
            }
            // When I press KC_LEAD and then 0, this sends ]
            SEQ_ONE_KEY(KC_0) {
                SEND_STRING("]");   
            }
            // When I press KC_LEAD and then double tap 9, this sends {
            SEQ_TWO_KEYS(KC_9, KC_9) {
                SEND_STRING("{");   
            }
            // When I press KC_LEAD and then double tap 0, this sends }
            SEQ_TWO_KEYS(KC_0, KC_0)     {
                SEND_STRING("}");   
            }
            // When I press KC_LEAD and then double tap S, this sends WIN + SHIFT + S to snip a screenshot
            SEQ_TWO_KEYS(KC_S, KC_S) {
                SEND_STRING(SS_LSFT( SS_LGUI("s")));
            }
            // When I press KC_LEAD and then T, this sends CTRL + TAB
            SEQ_ONE_KEY(KC_T) {
                register_code(KC_LCTL);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LCTL);
            }
            // When I press KC_LEAD and then double tap T, this sends CTRL + SHIFT + TAB
            SEQ_TWO_KEYS(KC_T, KC_T) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                register_code(KC_TAB);
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
        }
    }


#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //  Layer 0 - _base
    [_Base] = LAYOUT( \
    // ,-----------------------------------------.                    ,-----------------------------------------.
    // |Escape|   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Game |
        KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                     KC_6,  KC_7,  KC_8,  KC_9,   KC_0,  KC_NO, \
    // |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    // | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |  UP  |   O  |   P  |  ' " |
        KC_TAB, KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,                      KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_QUOT, \
    // |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    // |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ; : | Enter|
        KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                      KC_H,  KC_J, KC_K,  KC_L, KC_SCLN, KC_ENT, \
    // |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    // |LCTR  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | , <  | . >  |  / ? |      |
        KC_LCTL, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_NO,      KC_NO, KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_NO, \
    // `-----------------------------------------/       /     \      \-----------------------------------------'
    //            |      |      | ALT  |  Win | /Space  /       \ Bspc \  |Arrows|Leader| RAlt | RCTR |
    //            |      |      |      |      |/       /         \      \ | mode |      |      |      |
                KC_NO, KC_NO, KC_LALT, KC_RGUI, KC_SPC,           KC_BSPC, OSL(1), KC_LEAD, KC_RALT, KC_RCTL \
    //            `----------------------------------'           '------''---------------------------'
        ),

    // Layer 1 - _Arrows
    [_Arrows] = LAYOUT( \
    // ,-----------------------------------------.                    ,-----------------------------------------.
    // | Game |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
         TG(2), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, \
    // |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    // | Tab  |   Q  | Psc  |   E  |   R  |   T  |                    | Home |      |  UP  |      | F12  | ` ~  |
        KC_TAB, KC_Q, KC_PSCR, KC_E,  KC_R,  KC_T,                    KC_HOME, KC_NO, KC_UP, KC_NO, KC_F12, KC_GRV, \
    // |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    // |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------| End  | LEFT | DOWN | RIGHT|      | Enter|
        KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_TRNS, \
    // |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    // |LCTR  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|  - _ |  = + | [ {  | ] }  |  \ | |      |
        KC_LCTL, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_NO,      KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, \
    // `-----------------------------------------/       /     \      \-----------------------------------------'
    //            |      |      | ALT  |  Win | /Space  /       \Delete\  |Arrows|Leader| RAlt | RCTR |
    //            |      |      |      |      |/       /         \      \ | mode |      |      |      |
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
    //            `----------------------------------'           '------''---------------------------'
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
                    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(2), \
                    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_UP, KC_O, KC_P, KC_NO, \
                    KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_NO, \
                    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, \
                    KC_NO, KC_LALT, KC_LCTL, KC_SPC, KC_SPC, KC_TRNS, KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL \
                    ),

};

#ifdef OLED_ENABLE

    // static void render_eevee(void) {
    //     static const char PROGMEM eevee[] = {// 'eevee', 32x31px
            // 0x00, 0x0e, 0x72, 0x8a, 0x74, 0xe4, 0x98, 0x70, 0x80, 0x80, 0xc0, 0x40, 0x40, 0x40, 0x80, 0x80, 
            // 0x00, 0x80, 0x40, 0xa0, 0xd0, 0xc8, 0xe8, 0xe4, 0x74, 0xb4, 0x5a, 0x2a, 0x12, 0x0e, 0x00, 0x00, 
            // 0x00, 0x00, 0x00, 0x01, 0x02, 0xfd, 0x04, 0x38, 0x74, 0x38, 0x00, 0x80, 0x00, 0x38, 0x74, 0x38, 
            // 0x01, 0x01, 0xe0, 0x7d, 0x05, 0x05, 0x02, 0x82, 0xc1, 0x40, 0xf0, 0x1f, 0x02, 0x0c, 0x70, 0x80, 
            // 0x00, 0x00, 0x00, 0x38, 0xc4, 0x82, 0xe3, 0x12, 0x04, 0x04, 0x0d, 0x0d, 0x0d, 0x2e, 0x2e, 0x42, 
            // 0x83, 0x01, 0x03, 0x82, 0x9c, 0x66, 0xc3, 0x01, 0x00, 0x00, 0x01, 0x03, 0x84, 0xc4, 0x76, 0x0f, 
            // 0x00, 0x00, 0x00, 0x07, 0x08, 0x1c, 0x11, 0x0f, 0x06, 0x04, 0x04, 0x04, 0x34, 0x5e, 0x4b, 0x41, 
            // 0x61, 0x1f, 0x04, 0x37, 0x2c, 0x20, 0x33, 0x1c, 0x06, 0x02, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00
    //     };
        
    //     oled_write_raw_P(eevee, sizeof(eevee));
    // };

    #define ANIM_FRAMES 2
    #define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
    #define ANIM_FRAME_DURATION_CAT 1500 // how long each frame lasts in ms
    #define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024
    #define ANIM_SIZE_CAT 128 // number of bytes in array, minimize for adequate firmware size, max is 1024

    uint32_t anim_timer = 0;
    uint32_t anim_sleep = 0;

    // uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
    uint8_t current_anim_frame = 0;

    // Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
    static void render_anim(void) {
        static const char PROGMEM anim[ANIM_FRAMES][ANIM_SIZE] = {
            {
            0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
            0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,  1,  2,  4,  8, 16, 32, 67,135,  7,  1,  0,184,188,190,159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
            0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132, 67,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1, 61,124,252,252,252,252,252, 60, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
            0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 63, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
            32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8
            },
            {
            0,  0,126,126, 24, 60,102, 66,  0, 12, 28,112,112, 28, 12,  0,116,116, 20, 20,124,104,  0,124,124,  0,112,120, 44, 36,124,124,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
            0,  0,  0,  0,192, 96, 48, 24, 12,132,198, 98, 35, 51, 17,145,113,241,113,145, 17, 51, 35, 98,198,132, 12, 24, 48, 96,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
            0,  0,252, 15,  1,  0,248, 14, 31,109,140,148,148,164,166,249,224,255,224,249,166,164,148,148,140,109, 31, 14,248,  0,  1, 15,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
            0,  0, 31,120,192,  0, 15, 56,124,219,152, 20, 20, 18, 50,207,  3,255,  3,207, 50, 18, 20, 20,152,219,124, 56, 15,  0,192,120, 31, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,122,122,121,121,121,121, 57, 49,  2,  2,  4,  4,  8,  8,  8,136,136,135,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,130,135, 31,  7,159,  7, 28,  7,159,  7,159,  7,  2,130,  0,  0,  0,  0,
            32, 16, 16, 16, 17, 11, 14, 12, 24, 16, 49, 35, 98,102, 68, 68, 71, 71, 71, 68, 68,102, 98, 35, 49, 16, 24, 12,  6,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48,120,124,254,255, 63,  7,  0,  0,  0,  0,255,255,127,127, 63, 62, 28, 24,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  8,  8, 23,  0, 15,  1,  2,  1, 15,  0, 15,  2,  5,  8
            },
        };

        //assumes 1 frame prep stage
        void animation_phase(void) {
            current_anim_frame = (current_anim_frame + 1) % ANIM_FRAMES;
            oled_write_raw_P(anim[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE);
        }
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
            anim_sleep = timer_read32();
    }

    static void render_sleeping_cat(void) {
        static const char PROGMEM anim[ANIM_FRAMES][ANIM_SIZE_CAT] = {
            { //Sleeping cat, frame 1, 26x26px
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xa0, 0x60, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x00, 0x00, 0x0c, 0x0a, 0x09, 0x00, 
                0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 
                0xfb, 0xf9, 0xfc, 0xff, 0xfe, 0xfc, 0xfc, 0xfe, 0xff, 0xfd, 0xf8, 0xff, 0xc0, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 
                0x1f, 0x1f, 0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1e, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00
            },
            { //Sleeping cat, frame 2, 26x26px
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x50, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x32, 0x2a, 0x26, 0x00, 0x00, 
                0x80, 0xc0, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xf0, 0xf8, 0xfc, 0xfc, 0xfe, 0xff, 
                0xfd, 0xfc, 0x7e, 0x7f, 0xff, 0xfe, 0xfe, 0xff, 0x7f, 0x7e, 0xfc, 0xff, 0xe0, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 
                0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x07, 0x00, 0x00, 0x00
            },
        };

        //assumes 1 frame prep stage
        void animation_phase(void) {
            current_anim_frame = (current_anim_frame + 1) % ANIM_FRAMES;
            oled_write_raw_P(anim[abs((ANIM_FRAMES-1)-current_anim_frame)], ANIM_SIZE_CAT);
        }
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION_CAT) {
            anim_timer = timer_read32();
            animation_phase();
        }
            anim_sleep = timer_read32();
    }

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

        render_sleeping_cat();
        oled_set_cursor(0,6);
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
            render_anim();
            oled_set_cursor(0,6);
        }
        return false;
    }

    void suspend_power_down_user(void) {
        oled_off();
    }

    void suspend_power_down_kb(void) {
        oled_off();
    }

#endif

