#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>


// CONFIG - here you can define your cat variant

#define DEVICE_SIDE         0   // 0-(left) || 1-(right)
#define THUMB_MODULE        0   // 0-(only keys) || 1-(keys+joystick) || 2-(trackball) 
#define FINGER_MODULE       0   // 0-(only keys) || 1-(keys+wheel) 
#define ADDITIONAL_MODULES  0   // 0-(none) || 1-(mouse moudule)



class Config {

    public:

        char cat_side;

        //the variant variable is used to communicate with the LYNXapp
        String variant = "C0-000-000-000_v0.3.0";

        // the setup function is used to set the variant variable
        void set_variant();
};

// create an instance
extern Config config;

#endif