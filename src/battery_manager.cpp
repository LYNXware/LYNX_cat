#include "battery_manager.h"

BatteryManager battery_manager;


void BatteryManager::initialize(){

    // initialize the battery pin
    // pinMode(BATTERY_PIN, INPUT);
    pinMode(BATTERY_PIN, INPUT_PULLUP);


    pinMode(BATTERY_A, INPUT);
    // pinMode(BATTERY_B, INPUT);

    // initialize the battery level
    battery_level = 0;
}


void BatteryManager::read_battery(){

    // read the battery level
    battery_level = analogRead(BATTERY_PIN);

    a = analogRead(BATTERY_A);
    // b = analogRead(BATTERY_B);

    // battery_level_converted = map(b, 0, 4095, 0, 255);

    battery_level_converted = map(battery_level, 0, 4095, 0, 255);


    Serial.print("A: ");
    Serial.print(a);
    // Serial.print("      B: ");
    // Serial.print(b);

    Serial.print("      Battery level: ");
    Serial.print(battery_level);

    Serial.print("      Battery level converted: ");
    Serial.println(battery_level_converted);


    catnow.send_battery_level(battery_level);
}