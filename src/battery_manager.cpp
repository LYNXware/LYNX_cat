#include "battery_manager.h"

BatteryManager battery_manager;


void BatteryManager::initialize(){

    // initialize the battery pin
    // pinMode(BATTERY_PIN, INPUT);
    pinMode(BATTERY_PIN, INPUT);


    // initialize the battery level
    battery_level = 0;
}


void BatteryManager::read_battery(){

    // read the battery level
    battery_level = analogRead(BATTERY_PIN);


    readings_sum += battery_level;
    number_readings++;


    if (number_readings == max_readings){

        battery_level = readings_sum / number_readings;
        battery_level_converted = map(battery_level, 0, 4095, 0, 255);

        catnow.send_battery_level(battery_level);

        readings_sum = 0;
        number_readings = 0;

        Serial.print("Battery level: ");
        Serial.print(battery_level);

        Serial.print("      Battery level converted: ");
        Serial.println(battery_level_converted);
    }
}