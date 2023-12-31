#include "finger_mod_keys.h"



void Finger_Module::initialize(){

    //initializing outputpins of finger module
    for(byte j=0; j<outPin_f_count; j++){    
        pinMode(outPin_f[j],OUTPUT);
        digitalWrite(outPin_f[j],HIGH);  
    }
    //initializing inputpins of finger module
    for(byte j=0; j<inPin_f_count; j++){     
        pinMode(inPin_f[j],INPUT_PULLUP);
    }
}



void Finger_Module::read_keystate()
{
//looping through Outputpins and setting one at a time to LOW 
for (fo=0; fo<outPin_f_count; fo++)
{               
    digitalWrite(outPin_f[fo],LOW);   
    
    // looping through Inputpins and checking for the LOW state of outputpins
    for (fi=0; fi<inPin_f_count; fi++)
    {          

        f_index = f_map[fi][fo];

        if (digitalRead(inPin_f[fi]) == LOW && f_state[fi][fo] == 0){
            
            // event.actuate(f_index); 
            Serial.print("pressed-");
            Serial.println(f_index);

            f_state[fi][fo] = 1;

            catnow.send_event_index(f_index, true);
            delay(1);
            
        }
        else if (digitalRead(inPin_f[fi]) == HIGH && f_state[fi][fo] == 1){
            
            // event.deactuate(f_index); 
            Serial.print("released-");
            Serial.println(f_index);

            catnow.send_event_index(f_index, false);

            f_state[fi][fo] = 0;

        }
        else {     
            // do nothing   
        }
    }      
        //setting the Outputpin back to HIGH state
    digitalWrite(outPin_f[fo],HIGH);             
}
}




// creating an instance of the Finger_Module class
Finger_Module finger_mod;