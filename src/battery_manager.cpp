#include "battery_manager.h"

BatteryManager battery_manager;


void BatteryManager::initialize(){

    // initialize the battery pin
    // pinMode(BATTERY_PIN, INPUT);
    // pinMode(BATTERY_PIN, INPUT_PULLUP);


    // initialize the battery level
    // battery_level = 0;



    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_8, ADC_ATTEN_DB_11);
}


void BatteryManager::read_battery()
{
    battery_level = adc1_get_raw(ADC1_CHANNEL_8);

    // read the battery level
    // battery_level = analogRead(BATTERY_PIN);

    readings_sum += battery_level;
    number_readings++;

    if (number_readings == max_readings){

        battery_level = readings_sum / number_readings;
        battery_level_converted = map(battery_level, 0, 4095, 0, 255);

        catnow.send_battery_level(battery_level_converted);
        check_battery_stats(battery_level_converted);

        readings_sum = 0;
        number_readings = 0;

        Serial.print("Battery level: ");
        Serial.print(battery_level);

        Serial.print("      Battery level converted: ");
        Serial.println(battery_level_converted);
    }
}


void BatteryManager::check_battery_stats(uint8_t battery_level_converted){

    if (battery_level_converted < 1){

        catnow.turn_off();
        neopixelled.battery_empty();

    }
}




// void BatteryManager::read_battery(){

//     // read the battery level
//     battery_level = analogRead(BATTERY_PIN);


//     readings_sum += battery_level;
//     number_readings++;


//     if (number_readings == max_readings){

//         battery_level = readings_sum / number_readings;
//         battery_level_converted = map(battery_level, 0, 4095, 0, 255);

//         catnow.send_battery_level(battery_level);

//         readings_sum = 0;
//         number_readings = 0;

//         Serial.print("Battery level: ");
//         Serial.print(battery_level);

//         Serial.print("      Battery level converted: ");
//         Serial.println(battery_level_converted);
//     }
// }