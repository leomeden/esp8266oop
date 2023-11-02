#ifndef _WIFICONEXION_H
#define _WIFICONEXION_H

#include <Arduino.h>
#include <ESP8266WiFi.h>

class WifiConexion
{
    private:
        char _ssid;
        char _pass;
    public:
        WifiConexion(const char* ssid, const char* pass);

        bool conectar();
        
};

#endif