// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

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
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    QK_LEAD,
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
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, QK_LEAD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_PSCR, KC_HOME, KC_PGUP, KC_R,    KC_T,                               KC_HOME,  KC_NO,   KC_UP,  KC_F11,  KC_F12,  KC_GRV,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT , KC_DEL,  KC_END, KC_PGDN,  KC_F,    KC_G,                              KC_END,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_NO,  KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL , KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴   ┬────┘        └───┬    ┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, KC_SPC,                    KC_DEL,  OSL(1),  OSL(1)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

#ifdef LEADER_ENABLE
   // at leader start change lights colour to white
   void leader_start_user(void) {
      // sequence started
      #ifdef RGB_MATRIX_ENABLE
         rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_sethsv(HSV_CYAN);

      #endif
   }

   void leader_end_user(void) {
         // leading = false

         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + S to snip a screenshot
         if (leader_sequence_two_keys(KC_S, KC_S)) {
            SEND_STRING(SS_LSFT( SS_LGUI("S")));
         }
         // When I press KC_LEAD and then double tap S, this sends CMD + SHIFT + 4 to snip a screenshot
         else if (leader_sequence_two_keys(KC_P, KC_P)) {
            SEND_STRING("git push");
         }

         // When I press KC_LEAD and tap X and then double tap U, this sends CMD + OPT + CTRL + Eject / Power to shutdown
         // SEQ_THREE_KEYS(KC_X, KC_U, KC_U) {
         //    register_code(KC_LGUI);
         //    register_code(KC_LCTL);
         //    register_code(KC_LOPT);
         //    register_code(KC_PWR);
         //    unregister_code(KC_PWR);
         //    unregister_code(KC_LCTL);
         //    unregister_code(KC_LOPT);
         //    unregister_code(KC_LGUI);
         // }

         // after leader ends change lights colour to match curren layer state
        #ifdef RGB_MATRIX_ENABLE
            switch (get_highest_layer(layer_state)) {
            case _ARROW:
                    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
                    rgb_matrix_sethsv(HSV_WHITE);

                // rgblight_sethsv(HSV_BLUE);
                break;
            default: // for any other layers, or the default layer
                rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR );
                rgb_matrix_sethsv (85, 255, 200);
                //    rgb_matrix_sethsv (HSV_GREEN);
                break;
            }
        #endif
   }
#endif


#ifdef RGB_MATRIX_ENABLE

   layer_state_t layer_state_set_user(layer_state_t state) {
      switch (get_highest_layer(state)) {
         case _ARROW:
               rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR );
               rgb_matrix_sethsv(HSV_WHITE);
               break;
         default: // for any other layers, or the default layer
               rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR );
               rgb_matrix_sethsv (85, 255, 200);
            //    rgb_matrix_sethsv (HSV_GREEN);
               break;
      }
   return state;
   }
#endif
