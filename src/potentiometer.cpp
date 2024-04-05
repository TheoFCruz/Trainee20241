#include <Arduino.h>

#include "potentiometer.hpp"

Potentiometer::Potentiometer(int pin, int max_value)
{

}

int Potentiometer::getNumber()
{

}

int Potentiometer::getReading()
{
  return analogRead(this->_pin);
}
