#ifndef MOTOR_H
#define MOTOR_H

#include "ESP32Servo.h"

#define STEPPER_DELAY 10
#define STEPPER_STEPS 200

class Motor
{
public:

  virtual ~Motor() {}

  /**
   * Inicializa e configura o motor
   */
  virtual void setup() = 0;

  /**
  * Da um giro completo no motor
  */
  virtual void open() = 0;

  /**
  * Da um giro completo no motor no sentido contrário
  */
  virtual void close() = 0;
};

/**
* @brief Implementação de Motor para um motor de passos
*/
class StepperMotor: public Motor
{
public:
  /**
  * @brief Construtor do motor de passos
  *
  * @param step_pin O pino em que esta o step do driver
  * @param dir_pin O pino em que esta o dir do driver
  */
  StepperMotor(int step_pin, int dir_pin);

  void setup() override;

  void open() override;

  void close() override;

private:
  int _step_pin;
  int _dir_pin;
};

/**
* @brief Implementação de Motor para um motor servo
*/
class ServoMotor: public Motor
{
public:
  /**
  * @brief Construtor do motor servo
  *
  * @param pwm_pin O pino em que está conectado o pwm do motor servo
  */
  ServoMotor(int pwm_pin);

  void setup() override;

  void open() override;

  void close() override;
private:
  Servo _servo;
};


#endif // !MOTOR_H

