#include <Arduino.h>

#include "config.h"

#include "neopixel-LED.h"

#include "finger_mod_keys.h"
#include "thumb_mod_keys.h"

#include "wireless_comms.h"



// module to control the scroll wheel
#include "scroll-wheel.h"

// module to control the mouse sensor
#include "mouse-sensor.h"




void setup() {

  config.set_variant();

  neopixelled.initialize();

  finger_mod.initialize();
  thumb_mod.initialize();

  catnow.initialize();

  // included according to config.h
#if finger_module == 1  
  scroll_wheel.initialize();
#endif

#if thumb_module == 1  
  joystick.initialize();
#endif
  
#if additional_modules == 1  
  adns5050.initialize();
#endif

}

void loop() {
  
  // checking if key of thumb and fingers are triggered
  finger_mod.read_keystate();
  thumb_mod.read_keystate();

  // included according to config.h 
#if finger_module == 1
  // check if the scroll wheel is triggered
  scroll_wheel.read_encoder();
#endif  

#if thumb_module == 1  
  // check if the joystick is triggered
  joystick.read_joystick();
#endif
  
#if additional_modules == 1  
  // checking if the mouse sensor is triggered
  adns5050.read_mouse_sensor();
#endif

}

