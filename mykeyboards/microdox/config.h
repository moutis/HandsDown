
#pragma once

// Microdox hardware specific bits
//
// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS
//#define SPLIT_USB_DETECT


#ifdef PRODUCT
#undef PRODUCT
#define PRODUCT         HD-microdox
#endif
