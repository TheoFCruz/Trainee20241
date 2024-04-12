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
const int password[PASSWORD_LEN] {0,0,0};
int input[PASSWORD_LEN] = {-1, -1, -1};
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
  
  display.updateScreen(0, input, PASSWORD_LEN);
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

  // Checagem se a senha está correta quando o indice chega a 3
  if (current_index == PASSWORD_LEN)
  {
    bool correct_pswd = true; 
    for (int i = 0; i < PASSWORD_LEN; i++)
    {
      if (password[i] != input[i])
      {
        correct_pswd = false;
        break;
      }
    }

    if (correct_pswd)
    {
      motor.fullSpin();

      // TODO: Mais lógica de abertura do cofre
    }

    for (int j = 0; j < PASSWORD_LEN; j++) input[j] = -1;
    current_index = 0;

    display.updateScreen(current_number, input, PASSWORD_LEN);
  }
}
