#ifndef TIMESTAMPS_H
#define TIMESTAMPS_H

#include <Arduino.h>

class TimeStamps
{
public: 
  TimeStamps();

public: 
  // Check necessity for esp_timer.h later.
  inline void SetTime() {_time = micros();}
  inline void DeltaTime() {_dTime = micros() - _time;}

public:
  inline unsigned long GetTime() {return _time;}
  inline unsigned long GetDeltaTime() {return _dTime;}
  
private:
  unsigned long _time;
  unsigned long _dTime;

};


#endif