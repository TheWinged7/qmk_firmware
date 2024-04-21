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
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// #undef RGB_MATRIX_DEFAULT_HUE
// #undef RGBLIGHT_DEFAULT_SAT
// #undef RGBLIGHT_DEFAULT_VAL
// #undef RGBLIGHT_MAX_VAL
// #undef RGBLIGHT_DEFAULT_MODE

// #define RGBLIGHT_DEFAULT_HUE 100 // hue
// #define RGBLIGHT_LIMIT_VAL 255 // brightness
#define RGB_MATRIX_STARTUP_MODE  RGB_MATRIX_SOLID_COLOR 
#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turns off lights when PC is suspended
// #define RGBLIGHT_DISABLE_KEYCODES   // disables the ability to control RGB Light from the keycodes. 
#define RGB_DISABLE_WHEN_USB_SUSPENDED    // the RGB lighting will be switched off when the host goes to sleep 
#define RGBLIGHT_SPLIT


// #undef RGB_MATRIX_ALPHAS_MODS,         // Static dual hue, speed is hue for secondary hue
// #undef RGB_MATRIX_GRADIENT_UP_DOWN,    // Static gradient top to bottom, speed controls how much gradient changes
// #undef RGB_MATRIX_BREATHING,           // Single hue brightness cycling animation
// #undef RGB_MATRIX_BAND_SAT,             // Single hue band fading saturation scrolling left to right
// #undef RGB_MATRIX_BAND_VAL,             // Single hue band fading brightness scrolling left to right
// #undef RGB_MATRIX_BAND_PINWHEEL_SAT,   // Single hue 3 blade spinning pinwheel fades saturation
// #undef RGB_MATRIX_BAND_PINWHEEL_VAL,   // Single hue 3 blade spinning pinwheel fades brightness
// #undef RGB_MATRIX_BAND_SPIRAL_SAT,     // Single hue spinning spiral fades saturation
// #undef RGB_MATRIX_BAND_SPIRAL_VAL,     // Single hue spinning spiral fades brightness
// #undef RGB_MATRIX_CYCLE_ALL,           // Full keyboard solid hue cycling through full gradient
// #undef RGB_MATRIX_CYCLE_LEFT_RIGHT,    // Full gradient scrolling left to right
// #undef RGB_MATRIX_CYCLE_UP_DOWN,       // Full gradient scrolling top to bottom
// #undef RGB_MATRIX_CYCLE_OUT_IN,        // Full gradient scrolling out to in
// #undef RGB_MATRIX_CYCLE_OUT_IN_DUAL,   // Full dual gradients scrolling out to in
// #undef RGB_MATRIX_RAINBOW_MOVING_CHEVRON,  // Full gradent Chevron shapped scrolling left to right
// #undef RGB_MATRIX_CYCLE_PINWHEEL,      // Full gradient spinning pinwheel around center of keyboard
// #undef RGB_MATRIX_CYCLE_SPIRAL,        // Full gradient spinning spiral around center of keyboard
// #undef RGB_MATRIX_DUAL_BEACON,         // Full gradient spinning around center of keyboard
// #undef RGB_MATRIX_RAINBOW_BEACON,      // Full tighter gradient spinning around center of keyboard
// #undef RGB_MATRIX_RAINBOW_PINWHEELS,   // Full dual gradients spinning two halfs of keyboard
// #undef RGB_MATRIX_RAINDROPS,           // Randomly changes a single key's hue
// #undef RGB_MATRIX_JELLYBEAN_RAINDROPS, // Randomly changes a single key's hue and saturation
// #undef RGB_MATRIX_FRAMEBUFFER_EFFECTS, // Randomly changes a single key's hue and saturation
// #undef RGB_MATRIX_KEYPRESSES, // Randomly changes a single key's hue and saturation
// #undef RGB_MATRIX_KEYRELEASES, // Randomly changes a single key's hue and saturation