
#pragma once

// Kyria hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS
//#define SPLIT_USB_DETECT

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP

    #ifdef RGBLIGHT_ANIMATIONS
        #undef RGBLIGHT_ANIMATIONS
    #endif
    //#define RGBLIGHT_EFFECT_BREATHING
    //#define RGBLIGHT_EFFECT_TWINKLE
    //#define RGBLIGHT_SLEEP
    //#define RGBLIGHT_EFFECT_SNAKE
    //#define RGBLIGHT_MODE_ALTERNATING

    #ifdef RGBLIGHT_HUE_STEP
        #undef RGBLIGHT_HUE_STEP
    #endif
    #define RGBLIGHT_HUE_STEP 4

    #ifdef RGBLIGHT_SAT_STEP
        #undef RGBLIGHT_SAT_STEP
    #endif
    #define RGBLIGHT_SAT_STEP 4

    #ifdef RGBLIGHT_VAL_STEP
        #undef RGBLIGHT_VAL_STEP
    #endif
    #define RGBLIGHT_VAL_STEP 4
#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 9000
#endif

#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTION 2 // old encoders
    #define ENCODER_DIRECTION_FLIP // old encoders
//    #define ENCODER_RESOLUTION 4 // new encoders
#endif

#ifdef PRODUCT
#undef PRODUCT
#define PRODUCT         HD-microdox
#endif
