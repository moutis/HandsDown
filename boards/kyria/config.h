
#pragma once

// Kyria hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#ifdef CONVERT_TO // using an RP2040 (ie SeaPicro, SparkFun)
#define USB_DETECT
#else
#define EE_HANDS
#endif

//#ifdef PRODUCT
//#undef PRODUCT
//#define PRODUCT         HD-Kyria
//#endif

//#define OLED_DRIVER_ENABLE

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
    #ifdef OLED_TIMEOUT
        #undef OLED_TIMEOUT
    #endif
    #define OLED_TIMEOUT 9000
#endif

#ifdef ENCODER_ENABLE
    #define ENCODER_RESOLUTION 2 // old encoders =2, new encoders=4
    #define ENCODER_DIRECTION_FLIP // old encoders
//    #define ENCODER_RESOLUTION 4 // new encoders
#endif
