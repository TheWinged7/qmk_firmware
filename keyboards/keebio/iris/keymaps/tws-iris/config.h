/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

#pragma once

// #define USE_I2C
#define EE_HANDS
#define ONESHOT_TAP_TOGGLE 2
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250
#define SPLIT_LAYER_STATE_ENABLE

#undef RGBLIGHT_DEFAULT_HUE
#undef RGBLIGHT_DEFAULT_SAT
#undef RGBLIGHT_DEFAULT_VAL
#undef RGBLIGHT_MAX_VAL
#undef RGBLIGHT_DEFAULT_MODE

#define RGBLIGHT_DEFAULT_HUE 100 // hue
#define RGBLIGHT_LIMIT_VAL 255 // brightness
#define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_STATIC_LIGHT)
#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turns off lights when PC is suspended
#define RGBLIGHT_DISABLE_KEYCODES   // disables the ability to control RGB Light from the keycodes. 
#define RGBLIGHT_SLEEP   // the RGB lighting will be switched off when the host goes to sleep 
#define RGBLIGHT_SPLIT





// disable the non-static RGB effects
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE