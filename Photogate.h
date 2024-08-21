#ifndef PHOTOGATE_H
#define PHOTOGATE_H

#include <Arduino.h>


class Photogate
{
public:
  Photogate(const int* gate);
  inline int GetGateSize() {return gateSize;}

public:
  const int* _gate; 

private:
  const int gateSize = 6;
};


#endif