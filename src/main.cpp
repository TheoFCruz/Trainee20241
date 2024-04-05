#include <Arduino.h>

#include "potentiometer.hpp"

#define POT 34 // Pino do potenciometro
#define POT_MAX 4095 // Valor maximo da leitura do potenciometro

Potentiometer potentiometer(POT, POT_MAX);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
 
  pinMode(POT, INPUT);
}

void loop() {
  Serial.println(analogRead(POT));
  delay(10); // this speeds up the simulation
}
