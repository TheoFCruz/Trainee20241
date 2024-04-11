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
  return 1;
}

int Potentiometer::getReading()
{
  return analogRead(_pin);
}
