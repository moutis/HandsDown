
#pragma once

// FauFox hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
//#define EE_HANDS
//#define SPLIT_USB_DETECT

//#ifdef PRODUCT
//#undef PRODUCT
//#define PRODUCT         HD-FauxFox
//#endif

#ifdef OLED_DRIVER_ENABLE
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 9000
#endif

#ifdef ENCODER_ENABLE
    #ifdef ENCODER_RESOLUTION
        #undef ENCODER_RESOLUTION
    #endif
//    #define ENCODER_DIRECTION_FLIP // old encoders
    #define ENCODER_RESOLUTION 4 // new encoders
#endif
