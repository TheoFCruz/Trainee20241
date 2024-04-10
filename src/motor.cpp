#include "motor.hpp"

#include <Arduino.h>

Motor::Motor(int step_pin, int dir_pin):
  _step_pin(step_pin),
  _dir_pin(dir_pin)
{
  
}

void Motor::setup()
{
  pinMode(_step_pin, OUTPUT);
  pinMode(_dir_pin, OUTPUT);
}

void Motor::fullSpin()
{
  for (int i = 0; i < SPIN_STEPS; i++)
  {
    digitalWrite(_step_pin, LOW);
    digitalWrite(_step_pin, HIGH);
    delay(MOTOR_DELAY);
  }
}