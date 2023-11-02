#include <Arduino.h>

#include <WifiConexion.h>

const char* ssid = "Galaxy A24 78C5";
const char* pass = "noa12345";

WifiConexion wifi(ssid, pass);


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

  Serial.println(timeClient.getDay + " " + timeClient.getFormattedTime);

  delay(10000);
}

