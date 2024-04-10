#ifndef MOTOR_H
#define MOTOR_H

#define MOTOR_DELAY 10
#define SPIN_STEPS 200

class Motor
{
public:
  Motor(int step_pin, int dir_pin);

  /**
   * Inicializa e configura o motor
   */
  void setup();

  /**
  * Da um giro completo no motor
  */
  void fullSpin();

private:
  int _step_pin;
  int _dir_pin;
};

#endif // !MOTOR_H
