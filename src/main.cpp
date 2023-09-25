#include <Arduino.h>


#include "finger_mod_keys.h"

#include "wireless_comms.h"








void setup() {

  fingerModule.initialize();

  catnow.initialize();


}

void loop() {
  
  fingerModule.read_keystate();
  // Serial.println("loopppppppppppppppppp ");

  }

