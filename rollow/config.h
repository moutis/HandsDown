
#pragma once

// Rollow hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS


#ifdef ENCODER_ENABLE
    #ifdef ENCODER_RESOLUTION
        #undef ENCODER_RESOLUTION
    #endif
    #define ENCODER_DIRECTION_FLIP // old encoders/barrel encoders
    #define ENCODER_RESOLUTION 4 // new encoders
#endif
