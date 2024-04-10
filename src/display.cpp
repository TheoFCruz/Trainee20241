#include "display.hpp"

Display::Display(int tft_cs, int tft_dc): 
  _screen(NUMBER),
  _tft_instance(tft_cs, tft_dc)
{

}

void Display::setup()
{
  _tft_instance.begin();
  _tft_instance.setTextColor(ILI9341_WHITE);
  _tft_instance.setTextSize(2);
  _tft_instance.setRotation(1);
  _tft_instance.fillScreen(ILI9341_BLACK);
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
