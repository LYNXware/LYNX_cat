#include <Arduino.h>

#include "config.h"

#include "finger_mod_keys.h"

#include "wireless_comms.h"








void setup() {

  config.set_variant();



  fingerModule.initialize();

  catnow.initialize();


}

void loop() {
  
  fingerModule.read_keystate();
  // Serial.println("loopppppppppppppppppp ");

  }

