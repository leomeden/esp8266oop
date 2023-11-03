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

#include "ESP8266TimerInterrupt.h"

volatile bool flag = false;
volatile uint32_t lastMillis = 0;

#define TIMER_INTERVAL_MS       10000

// Init ESP8266 timer 1
ESP8266Timer ITimer;
//=======================================================================
void IRAM_ATTR TimerHandler()
{
  
  flag = true;

#if (TIMER_INTERRUPT_DEBUG > 0)
  Serial.println("Delta ms = " + String(millis() - lastMillis));
  lastMillis = millis();
#endif

}
//=======================================================================

void setup(){
  Serial.begin(115200);
  wifi.conectar();
  timeClient.begin();

  while (!Serial && millis() < 5000);

  delay(500);

  Serial.print(F("\nStarting TimerInterruptTest on "));
  Serial.println(ARDUINO_BOARD);
  Serial.println(ESP8266_TIMER_INTERRUPT_VERSION);
  Serial.print(F("CPU Frequency = "));
  Serial.print(F_CPU / 1000000);
  Serial.println(F(" MHz"));

  // Interval in microsecs
  if (ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, TimerHandler))
  {
    lastMillis = millis();
    Serial.print(F("Starting ITimer OK, millis() = "));
    Serial.println(lastMillis);
  }
  else
    Serial.println(F("Can't set ITimer correctly. Select another freq. or interval"));
}

void loop() {
  timeClient.update();
  
  if (flag == true) {
    Serial.println(timeClient.getFormattedDate() + " " + timeClient.getFormattedTime());
    flag = false;
  }
  
  
}

