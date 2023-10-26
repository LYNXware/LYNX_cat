#include "joystick.h"

// creating an instance of the Joystick class
Joystick joystick;



void Joystick::initialize(){

    // pin to read the joystick values
    pinMode(pin_jx, INPUT_PULLUP);     
    pinMode(pin_jy, INPUT_PULLUP);  
    
    // power supply for the joystick
    pinMode(pin_v,OUTPUT);
    digitalWrite(pin_v,HIGH); 
} 




void Joystick::read_joystick(){

  // read the analog joystick values
  joystickValues[0] = analogRead(pin_jy); 
  joystickValues[1] = analogRead(pin_jx);

  // Serial.print(joystickValues[0]);
  // Serial.print(" ");
  // Serial.println(joystickValues[1]);
  // byte a = map(joystickValues[0], 0, 4095, 0, 255);
  // byte b = map(joystickValues[1], 0, 4095, 0, 255);
  // catnow.send_mouse_movements(a, b);


  two_step();

  // check how many steps the joystick has
  // if (){
  //     one_step();
  // }
  // else{
  //     two_step();
  // }
}






void Joystick::one_step() {

  for (byte a = 0; a < 2; a++) {

    if (joystickValues[a] < threshold_low_1) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,0);
    }
    else{
      deactuate_event(a,0);
    }

    if (joystickValues[a] > threshold_high_1) {
      // Serial.println(joystickValues[a]);
      actuate_event(a,2);
    }
    else{
      deactuate_event(a,2);
    }
  }
}



void Joystick::two_step() {

  for (byte a = 0; a < 2; a++) {
        // 1600                                                 
    if (threshold_low_1 > joystickValues[a] && joystickValues[a] > threshold_low_2) {
      // Serial.println(joystickValues[a]);
      //f1
      actuate_event(a,0);
      deactuate_event(a,1);
      // delay(debounce_delay);
      Serial.println("L1");
    }
    else if (joystickValues[a] == threshold_low_3) {
      //f2
      deactuate_event(a,0);
      actuate_event(a,1);
      // delay(debounce_delay);
      Serial.println("L3");
    }
    else if (threshold_high_1 < joystickValues[a] && joystickValues[a] < threshold_high_2) {
      //b1
      actuate_event(a,2);
      deactuate_event(a,3);
      // delay(debounce_delay);
      Serial.println("H1");
    }
    else if (joystickValues[a] == threshold_high_3) {
      //b2
      deactuate_event(a,2);
      actuate_event(a,3);
      // delay(debounce_delay);

      // Serial.print(joystickValues[a]);
      // Serial.print("   ");  

      // Serial.print(threshold_high_3);
      Serial.println("H3");
    }
    else{
      deactuate_event(a,0);
      deactuate_event(a,1);
      deactuate_event(a,2);
      deactuate_event(a,3);
      Serial.println("N");
    }
  }
}





void Joystick::actuate_event(byte axis, byte axis_event){

  if (!joystick_state[axis][axis_event]) {

    catnow.send_event_index(joystick_event_map[axis][axis_event], true);

    joystick_state[axis][axis_event] = true;

    // event.actuate(joystick_event_map[axis][axis_event]);

    // Serial.print("press--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);

  }
}



void Joystick::deactuate_event(byte axis, byte axis_event){

  if (joystick_state[axis][axis_event]) {

    catnow.send_event_index(joystick_event_map[axis][axis_event],false);

    joystick_state[axis][axis_event] = false;

    // event.deactuate(joystick_event_map[axis][axis_event]);

    // Serial.print("rr--");
    // Serial.print(axis);
    // Serial.print("-");
    // Serial.println(axis_event);
  }
}



// void Joystick::read_joystick(){

//     // read the analog joystick values
//     joystickValues[0] = analogRead(pin_jy); 
//     joystickValues[1] = analogRead(pin_jx);

//     // check how many steps the joystick has
//     if (layouts_manager.events_array[layer_control.active_layer][32][0] == '0'){
//         one_step();
//     }
//     else{
//         two_step();
//     }
// }



// void Joystick::two_step() {

//   for (byte a = 0; a < 2; a++) {

//     if (threshold_l1 > joystickValues[a] && joystickValues[a] > threshold_l2) {
//       // Serial.println(joystickValues[a]);

//       actuate_event(a,0);
//     }
//     else{
//       deactuate_event(a,0);
//     }

//     if (joystickValues[a] < threshold_l2) {
//       // Serial.println(joystickValues[a]);
//       actuate_event(a,1);
//     }
//     else{
//       deactuate_event(a,1);
//     }

//     if (threshold_h1 < joystickValues[a] && joystickValues[a] < threshold_h2) {
//       // Serial.println(joystickValues[a]);
//       actuate_event(a,2);
//     }
//     else{
//       deactuate_event(a,2);
//     }

//     if (joystickValues[a] > threshold_h2) {
//       // Serial.println(joystickValues[a]);
//       actuate_event(a,3);
//     }
//     else{
//       deactuate_event(a,3);
//     }
//   }
// }