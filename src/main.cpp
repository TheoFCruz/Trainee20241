#include <Arduino.h>

#include "potentiometer.hpp"
#include "motor.hpp"
#include "display.hpp"

#define POT 34 // Pino do potenciometro
#define POT_MAX 4095 // Valor maximo da leitura do potenciometro

#define TFT_CS 0
#define TFT_DC 0

#define MOTOR_STEP 32
#define MOTOR_DIR 33

Potentiometer potentiometer(POT, POT_MAX);
Motor motor(MOTOR_STEP, MOTOR_DIR);
// Display display(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  motor.setup();
  // display.setup();

  pinMode(POT, INPUT);
}

void loop() {
  Serial.println(analogRead(POT));
  delay(10); // this speeds up the simulation
}
