#include <Arduino.h>


#include "finger_mod_keys.h"


void setup() {

  fingerModule.initialize();

}

void loop() {
  
  fingerModule.read_keystate();
  Serial.println("loopppppppppppppppppp ");

  }

