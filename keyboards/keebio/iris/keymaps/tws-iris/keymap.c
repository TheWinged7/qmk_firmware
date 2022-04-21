#include QMK_KEYBOARD_H


// #define _QWERTY 0
// #define _ARROW 1
enum iris_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _ARROW,

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // OSL(1)

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENTER,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,            KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_LEAD,  OSL(1),  KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_PSCR, KC_HOME, KC_PGUP, KC_R,    KC_T,                               KC_HOME,  KC_NO,   KC_UP,  KC_F11,  KC_F12,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_DEL,  KC_END, KC_PGDN,  KC_F,    KC_G,                              KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_LEAD,  OSL(1),  KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

LEADER_EXTERNS();
void matrix_scan_user(void) {
   LEADER_DICTIONARY() {
      leading = false;
      leader_end();
      SEQ_ONE_KEY(KC_L) {
         // When I press KC_LEAD and then L, this sends CMD + CTRL + Q
         SEND_STRING(SS_LCTRL( SS_LGUI("q")));   
      }
      SEQ_ONE_KEY(KC_L) {
         // When I press KC_LEAD and then L, this sends CMD + CTRL + Q
         SEND_STRING(SS_LCTRL( SS_LGUI("q")));   
      }
      // Note: This is not an array, you don't need to put any commas
      // or semicolons between sequences.
      SEQ_TWO_KEYS(KC_S, KC_S) {
         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + 4 to snip a screenshot
         SEND_STRING(SS_LCTRL( SS_LGUI("4")));
      }

      SEQ_THREE_KEYS(KC_X, KC_U, KC_U) {
         // When I press KC_LEAD and tap X and then double tap S, this sends CMD + OPT + CTRL + Eject / Power to shutdown
         register_code(KC_LGUI);  
         register_code(KC_LCTL);
         register_code(KC_LOPT);
         register_code(KC_POWER);
         unregister_code(KC_POWER);
         unregister_code(KC_LCTL);
         unregister_code(KC_LOPT);
         unregister_code(KC_LGUI);
      }

   }
}

