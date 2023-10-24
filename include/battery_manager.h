#ifndef BATTERY_MANAGER_H
#define BATTERY_MANAGER_H

#include <Arduino.h>

#include "wireless_comms.h"

#define BATTERY_PIN 14

#define BATTERY_A 13
// #define BATTERY_B 19

class BatteryManager {

public:

    void initialize();

    void read_battery();

    int battery_level;

    uint8_t battery_level_converted;

    int a;
    int b;


};

// create an instance
extern BatteryManager battery_manager;

#endif