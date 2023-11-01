#include <Arduino.h>

int SALIDA = 2; 

void setup() {
  Serial.begin(115200);
  pinMode(SALIDA, OUTPUT); 
}

void loop() {
  digitalWrite(SALIDA, HIGH);
  Serial.println("APAGADO");
  delay(3000); 
  
  digitalWrite(SALIDA, LOW); 
  Serial.println("ENCENDIDO");
  delay(3000);

}

