#include <Arduino.h>
//Credenciales y constantes
#include <Credenciales.h>
//Clases propias
#include <WifiConexion.h>


#include <NTPClient.h>
#include <WiFiUdp.h>

WifiConexion wifi(ssid, pass);

//Hora por NTP
WiFiUDP ntpUDP;
// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionally you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", -10800, 3600);

void setup(){
  Serial.begin(115200);
  wifi.conectar();
  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedDate() + " " + timeClient.getFormattedTime());
  delay(10000);
}

