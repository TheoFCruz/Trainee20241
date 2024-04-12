#ifndef DISPLAY_H
#define DISPLAY_H

#include "Adafruit_ILI9341.h"

enum screen 
{
  NUMBER,
  OPEN
};

class Display
{
public:
  /**
   * Inicializa a instancia do display e a variavel _screen
   */
  Display(int tft_cs, int tft_dc);

  /**
   * Inicializa e configura o display
   */
  void setup();

  /**
  * Atualiza a tela de acordo com o número atualmente lido. Caso _screen = DONE, mostra a tela de conclusão
  */
  void updateScreen(int num, int* input, int length);

  /**
  * Apenas muda o valor de _screen para OPEN, indicando a abertura do cofre
  */
  void setScreenOpen();

  /**
  * Apenas muda o valor de _screen para NUMBER, indicando a abertura do cofre
  */
  void setScreenNumber();

private:
  /**
  * Lógica da tela de número
  */
  void numberScreen(int num, int* input, int length);   

  /**
  * Lógica da tela de conclusão
  */
  void openScreen();   

  screen _screen; 
  Adafruit_ILI9341 _tft_instance;
};

#endif // !DISPLAY_H
