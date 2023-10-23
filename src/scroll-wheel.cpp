#include "scroll-wheel.h"


void Scroll_Wheel::initialize(){

    pinMode(encoder_GND,OUTPUT);
    digitalWrite(encoder_GND,LOW);

    pinMode (encoder_a,INPUT_PULLUP);
    pinMode (encoder_b,INPUT_PULLUP);
    
    previous_state = digitalRead(encoder_a);   
} 



void Scroll_Wheel::read_encoder(){

    state = digitalRead(encoder_a);

    if (state != previous_state) {
        if (state == HIGH) {
            if (digitalRead(encoder_b) != state){
                // Clockwise
                catnow.send_event_index(forward_scroll);
                catnow.send_event_index(forward_scroll);   
                // delay(1);
            } 
            else {
                // Counterclockwise
                catnow.send_event_index(backward_scroll);
                catnow.send_event_index(backward_scroll);
                // delay(1);    
            }
        }
    } 
    previous_state = state;
} 

Scroll_Wheel scroll_wheel;