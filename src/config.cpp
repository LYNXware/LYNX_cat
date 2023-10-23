#include "config.h"

/*
    Variant Legend:
    C  0  -  0  0  0  -  0  0  0  -  0  0  0 - v  0 . 0 . 0
    0  1  2  3  4  5  6  7  8  9  10 11 12 13
    C(side)-(thumb modules)-(finger modules)-(additional modules) - v(version)
*/


void Config::set_variant() {      

    #if DEVICE_SIDE == 0
        variant.setCharAt(1,'L');
        cat_side = 'L';
    #elif side == 1
        variant.setCharAt(1,'R');
        cat_side = 'R';
    #endif


    #if THUMB_MODULE == 0
        variant.setCharAt(3,'B');
    #elif THUMB_MODULE == 1
        variant.setCharAt(3,'J');
        variant.setCharAt(4,'B');
    #elif THUMB_MODULE == 2
        variant.setCharAt(3,'T');
    #endif


    #if FINGER_MODULE == 0
        variant.setCharAt(7,'B');     
    #elif finger_module == 1
        variant.setCharAt(7,'B');
        variant.setCharAt(8,'W');
    #endif

    
    #if ADDITIONAL_MODULES == 0
           variant.setCharAt(11,'0');
    #elif ADDITIONAL_MODULES == 1
        variant.setCharAt(11,'M');
    #endif    
        
}

Config config;
