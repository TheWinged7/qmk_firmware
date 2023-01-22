#include QMK_KEYBOARD_H

enum iris_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _ARROW,

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   // OSL(1)

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LEAD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENTER,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,            KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_BSPC,  OSL(1),  OSL(1)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_LEAD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_PSCR, KC_HOME, KC_PGUP, KC_R,    KC_T,                               KC_HOME,  KC_NO,   KC_UP,  KC_F11,  KC_F12,  KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_DEL,  KC_END, KC_PGDN,  KC_F,    KC_G,                              KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_BSPC,  OSL(1),  OSL(1)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

#ifdef LEADER_ENABLE
   // at leader start change lights colour to white
   void leader_start(void) {
      // sequence started
      #ifdef RGBLIGHT_ENABLE
         rgblight_sethsv(HSV_WHITE);
      #endif
   }

// after leader ends change lights colour to match curren layer state
   void leader_end(void) {
     switch (get_highest_layer(layer_state)) {
         case _ARROW:
               rgblight_sethsv(HSV_BLUE);
               break;
         default: // for any other layers, or the default layer
               rgblight_sethsv (100, 213, 255);
               break;
      }

   }

   LEADER_EXTERNS();
   void matrix_scan_user(void) {
      LEADER_DICTIONARY() {
         leading = false;
         // When I press KC_LEAD and then L, this sends CMD + CTRL + Q
         SEQ_ONE_KEY(KC_L) {
            SEND_STRING(SS_LCTRL( SS_LGUI("q")));
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
         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + 4 to snip a screenshot
         SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING(SS_LSFT( SS_LGUI("4")));
         }
         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + 4 to snip a screenshot
         SEQ_TWO_KEYS(KC_P, KC_P) {
            SEND_STRING("git push");
         }
         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + 4 to snip a screenshot
         SEQ_TWO_KEYS(KC_P, KC_F) {
            SEND_STRING("git sith");
         }

         // When I press KC_LEAD and tap X and then double tap U, this sends CMD + OPT + CTRL + Eject / Power to shutdown
         SEQ_THREE_KEYS(KC_X, KC_U, KC_U) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LOPT);
            register_code(KC_POWER);
            unregister_code(KC_POWER);
            unregister_code(KC_LCTL);
            unregister_code(KC_LOPT);
            unregister_code(KC_LGUI);
         }
      leader_end();
      }
   }
#endif


#ifdef RGBLIGHT_ENABLE

   layer_state_t layer_state_set_user(layer_state_t state) {
      switch (get_highest_layer(state)) {
         case _ARROW:
               rgblight_sethsv(HSV_BLUE);
               break;
         default: // for any other layers, or the default layer
               rgblight_sethsv (100, 213, 255);
               break;
      }
   return state;
   }
#endif