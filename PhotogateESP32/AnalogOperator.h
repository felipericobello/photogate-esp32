#ifndef ANALOGOPERATOR_H
#define ANALOGOPERATOR_H

#include <Arduino.h>

class AnalogOperator
{
public:
  AnalogOperator() {}

public:
  inline unsigned int Read(unsigned int index) {return analogRead(index);}
};

#endif