#include <Arduino.h>

#include "potentiometer.hpp"

Potentiometer::Potentiometer(int pin, int max_value):
  _pin(pin),
  _max_value(max_value)
{
  pinMode(_pin, INPUT);
}

int Potentiometer::getNumber()
{
  float interval = (float)_max_value / 10;

  return analogRead(_pin)/interval;
}

int Potentiometer::getReading()
{
  return analogRead(_pin);
}
