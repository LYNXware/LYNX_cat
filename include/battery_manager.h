#ifndef BATTERY_MANAGER_H
#define BATTERY_MANAGER_H

#include <Arduino.h>

#include "esp_adc_cal.h"

#include "wireless_comms.h"
#include "neopixel-LED.h"



#define BATTERY_PIN 14



class BatteryManager {

public:

    void initialize();

    void read_battery();

private:

    int battery_level;
    int readings_sum = 0;
    int number_readings = 0;
    
    // byte max_readings = 1000;
    u16_t max_readings = 10000;

    uint8_t battery_level_converted;

    void check_battery_stats(uint8_t battery_level_converted);
};

// create an instance
extern BatteryManager battery_manager;

#endif