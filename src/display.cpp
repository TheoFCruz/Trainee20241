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

void Display::updateScreen(int num, int* input, int length)
{
  switch(_screen)
  {
    case NUMBER:
      numberScreen(num, input, length);
      break;
    case DONE:
      doneScreen();
      break;
  }
}

void Display::openVault() {_screen = DONE;}

void Display::numberScreen(int num, int* input, int length)
{
  _tft_instance.fillScreen(ILI9341_BLACK);

  _tft_instance.setCursor(5, 10);
  _tft_instance.print("Senha Inserida: ");
  for (int i = 0; i < length; i++)
  {
    if (input[i] == -1) _tft_instance.print('_');
    else _tft_instance.print(input[i]);
  }

  int width = _tft_instance.width();
  int height = _tft_instance.height();
  _tft_instance.setTextSize(4);
  _tft_instance.setCursor(width/2 - 20, height/2 - 10);

  _tft_instance.print(num);
  _tft_instance.setTextSize(2);
}

void Display::doneScreen()
{
  // TODO: implementar a tela de conclusão
}
