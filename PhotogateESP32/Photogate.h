#ifndef PHOTOGATE_H
#define PHOTOGATE_H

#include <Arduino.h>
#include "Timestamps.h"
#include "Channel.h"

class Photogate
{
public:
  Photogate(const int* gate);
  ~Photogate();
  void PinGate();
  void InitPhotogate();

public:
  inline int GetGateSize() {return _gateSize;}
  inline bool IsRunning() {return _isRunning;}
public:

private:
  const int* _gate; 
  const int _gateSize;

  bool _isRunning;

private: //static allocations
  static const int s_gateSize = 6; // "As a result, the declaration of a static data member is not considered a definition. The data member is declared in class scope, but definition is performed at file scope."

private: // features
  TimeStamps* _timeStamps;
  Channel* _channel[s_gateSize]; // Ideally, I would like to use std::vector<> here, but that could cause some memory issues in microcontrollers, as stack overflow.
};


#endif