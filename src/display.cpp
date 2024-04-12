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
    case OPEN:
      openScreen();
      break;
  }
}

void Display::setScreenOpen() {_screen = OPEN;}
void Display::setScreenNumber() {_screen = NUMBER;}

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

void Display::openScreen()
{
  _tft_instance.fillScreen(ILI9341_BLACK);

  _tft_instance.setCursor(10, 10);
  _tft_instance.println("Cofre aberto.");
  _tft_instance.println("Aperte o botao para fechar.");
}
