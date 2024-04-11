#include <Arduino.h>

#include "potentiometer.hpp"
#include "motor.hpp"
#include "display.hpp"

#define POT 34 // Pino do potenciometro
#define POT_MAX 4095 // Valor maximo da leitura do potenciometro

#define TFT_CS 5
#define TFT_DC 21

#define MOTOR_STEP 32
#define MOTOR_DIR 33

#define BUTTON 35

Potentiometer potentiometer(POT, POT_MAX);
Motor motor(MOTOR_STEP, MOTOR_DIR);
Display display(TFT_CS, TFT_DC);

// Senha definida e input atual
#define PASSWORD_LEN 3
#define PASSWORD {0,0,0};
int input[3] = {-1, -1, -1};
int current_index = 0;

// Variaveis para só atualizar a tela quando o número lido mudar
int last_number = 0;
int current_number = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  pinMode(BUTTON, INPUT_PULLUP);

  motor.setup();
  display.setup();
}

void loop() {
  // Atualiza a tela caso o número mude
  last_number = current_number;
  current_number = potentiometer.getNumber();
  if (current_number != last_number) display.updateScreen(current_number, input, PASSWORD_LEN);

  // Adiciona o número atual ao input e aumenta o índice
  if (!digitalRead(BUTTON) && current_index < 3)
  {
    input[current_index] = current_number; 
    current_index++;

    display.updateScreen(current_number, input, PASSWORD_LEN);

    delay(100);
  }

  // TODO: lógica de conferir a senha
}
