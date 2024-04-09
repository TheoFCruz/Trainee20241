#include "display.hpp"

Display::Display(int tft_cs, int tft_dc): 
  _screen(NUMBER),
  _tft_instance(tft_cs, tft_dc)
{

}

void Display::updateScreen(int num)
{
  switch(_screen)
  {
    case NUMBER:
      numberScreen(num);
      break;
    case DONE:
      doneScreen();
      break;
  }
}

void Display::openVault() {_screen = DONE;}

void Display::numberScreen(int num)
{
  // TODO: implementar a tela de número
}

void Display::doneScreen()
{
  // TODO: implementar a tela de conclusão
}
