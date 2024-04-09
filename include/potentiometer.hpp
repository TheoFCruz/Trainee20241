#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer
{
public:
  Potentiometer(int pin, int max_value);

  /**
  * Retorna a leitura já mapeada para os números reais de 0 a 10
  */
  int getNumber(); 
  
  /**
  * Retorna a leitura crua do sinal analógico
  */
  int getReading();
private:
  int _pin;
  int _max_value;
};

#endif
