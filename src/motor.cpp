#include "motor.hpp"

#include <Arduino.h>

StepperMotor::StepperMotor(int step_pin, int dir_pin):
  _step_pin(step_pin),
  _dir_pin(dir_pin)
{
  
}

void StepperMotor::setup()
{
  pinMode(_step_pin, OUTPUT);
  pinMode(_dir_pin, OUTPUT);

  digitalWrite(_dir_pin, HIGH);
}

void StepperMotor::open()
{
  for (int i = 0; i < STEPPER_STEPS; i++)
  {
    digitalWrite(_step_pin, LOW);
    digitalWrite(_step_pin, HIGH);
    delay(STEPPER_DELAY);
  }
}

void StepperMotor::close()
{
  digitalWrite(_dir_pin, LOW);
  for (int i = 0; i < STEPPER_STEPS; i++)
  {
    digitalWrite(_step_pin, LOW);
    digitalWrite(_step_pin, HIGH);
    delay(STEPPER_DELAY);
  }
  digitalWrite(_dir_pin, HIGH);
}


ServoMotor::ServoMotor(int pwm_pin)
{
  _servo.attach(pwm_pin);
}

void ServoMotor::setup()
{
  _servo.write(0); 
}

void ServoMotor::open()
{
  _servo.write(180); 
}

void ServoMotor::close()
{
  _servo.write(0); 
}
