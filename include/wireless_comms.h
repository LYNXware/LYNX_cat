#ifndef WIRELESS_COMMS_H
#define WIRELESS_COMMS_H

#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>

#include "config.h"


class CatNow {

    public:

        // turn on wifi and CatNow
        void initialize();

        void scan_for_hub();

        void send_event_index(uint8_t event_index);

        void send_mouse_movements(uint8_t x_value, uint8_t y_value);





        // void send_switch_layer(uint8_t layer);

    private:

        // wifi credentials
        #define CHANNEL 1
        String wifi_cat = "LYNX_"; // + cat_variant;
        String wifi_hub = "LYNXhub_";

        // slave mac address
        esp_now_peer_info_t peerInfo;
        // peer is available
        bool peer_available = false;

        // esp-now callbacks
        static void OnDataSent(const uint8_t* mac_addr, esp_now_send_status_t status);
        static void OnDataReceived(const uint8_t* mac_addr, const uint8_t* data, int data_len); 

};

//instance of the class 
extern CatNow catnow;

#endif