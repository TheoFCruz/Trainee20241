#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer
{
  public:
    Potentiometer(int pin, int max_value);

    int getNumber(); 
    int getReading();
  private:
    int _pin;
    int _max_value;
};

#endif
