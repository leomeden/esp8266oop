#ifndef _CREDENCIALES_H
#define _CREDENCIALES_H

//Credenciales Wifi
const char* ssid = "Galaxy A24 78C5";
const char* pass = "noa12345";

//Credenciales Interrupciones

// These define's must be placed at the beginning before #include "ESP8266TimerInterrupt.h"
// _TIMERINTERRUPT_LOGLEVEL_ from 0 to 4
// Don't define _TIMERINTERRUPT_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
#define TIMER_INTERRUPT_DEBUG        0 
// 1
#define _TIMERINTERRUPT_LOGLEVEL_    0 
// 1

// Select a Timer Clock
#define USING_TIM_DIV1                false           // for shortest and most accurate timer
#define USING_TIM_DIV16               false           // for medium time and medium accurate timer
#define USING_TIM_DIV256              true            // for longest timer but least accurate. Default

#endif