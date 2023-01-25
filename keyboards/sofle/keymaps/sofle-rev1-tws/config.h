#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define ONESHOT_TAP_TOGGLE 2
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_OLED_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250


// RGB SETTINGS

/* ws2812 RGB LED */
#define RGB_DI_PIN D3



/* RGB LIGHT SETTINGS */

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #undef RGBLIGHT_DEFAULT_HUE
    #undef RGBLIGHT_DEFAULT_SAT
    #undef RGBLIGHT_DEFAULT_VAL
    #undef RGBLIGHT_LIMIT_VAL

    #define RGBLED_NUM 72
	
	#ifndef RGB_SPLIT
        #define RGB_SPLIT { 36, 36 } // haven't figured out how to use this yet
    #endif
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_DEFAULT_HUE 200 // hue
    #define RGBLIGHT_DEFAULT_SAT 120 // Sets the default saturation value, if none has been set
    #define RGBLIGHT_DEFAULT_VAL 120 // Sets the default saturation value, if none has been set

    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turns off lights when PC is suspended
    #define RGBLIGHT_DISABLE_KEYCODES   // disables the ability to control RGB Light from the keycodes. 
    #define RGBLIGHT_SLEEP   // the RGB lighting will be switched off when the host goes to sleep 
    #define RGBLIGHT_SPLIT
#endif




/* RGB MATRIX SETTINGS */
#ifdef RGB_MATRIX_ENABLE
    #define RGBLIGHT_SPLIT
    #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
    #define RGBLED_NUM 72
    #ifndef RGB_MATRIX_SPLIT 
        #define RGB_MATRIX_SPLIT { 36, 36 } // changed from RGBLED_SPLIT
    #endif
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM
    #define DRIVER_LED_TOTAL RGBLED_NUM
    

    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10
    
    #define RGB_MATRIX_DEFAULT_HUE 220 // Sets the default hue value, if none has been set
    #define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
    #define RGB_MATRIX_DEFAULT_SPD 50 // Sets the default animation speed, if none has been set
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set

    #define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
    #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turns off lights when PC is suspended
    #define RGB_MATRIX_DISABLE_KEYCODES    // disables the ability to control RGB Light from the keycodes. 
    #define RGBLED_SLEEP   // the RGB lighting will be switched off when the host goes to sleep 
    // #define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    // #define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)

#endif

 /* Disable the animations you don't want/need.  You will need to disable a good number of these    *
    * because they take up a lot of space.  Disable until you can successfully compile your firmware. */

// RGBLIGHT
#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
    #undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_RGB_TEST
    #undef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_TWINKLE


    #ifdef RGBLIGHT_DEFAULT_MODE
        #undef RGBLIGHT_DEFAULT_MODE
        #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
    #endif
#endif

// MATRIX
#ifdef RGB_MATRIX_ENABLE
    #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
    #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #undef ENABLE_RGB_MATRIX_BREATHING
    #undef ENABLE_RGB_MATRIX_CYCLE_ALL
    #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #undef ENABLE_RGB_MATRIX_DUAL_BEACON
    #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #undef ENABLE_RGB_MATRIX_RAINDROPS
    #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #undef ENABLE_RGB_MATRIX_SPLASH
    #undef ENABLE_RGB_MATRIX_MULTISPLASH
    #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
    #undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH


    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #undef RGB_MATRIX_DEFAULT_MODE
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE 
#endif