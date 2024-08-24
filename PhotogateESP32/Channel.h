#ifndef CHANNEL_H
#define CHANNEL_H

#define REF_LEVEL 2048

#include <Arduino.h>

class Channel
{
public: 
  Channel(int index, int pin);

public:
  inline bool GetUP() {return _up;}
  inline bool GetDown() {return _down;}
  inline int  GetPin() {return _pin;}

public:
  inline void SetReferenceLevel(int referenceLevel) { _refLevel = referenceLevel; }
  inline void SetMarkUP() {_up = !_up;}
  inline void SetMarkDown() {_down = !_down;}

public:
  unsigned int Read();

  // function: flag(). eIf read() > _refLevel, then send flag and mark as _rise. (on rise or on fall)
private:
  /*
    Channel properties:
      Channel Index.
      Reference level: 12bits ADC on ESP32, so 0->4095.
      UP and Down check boxes.
  */

  int _channelIndex;
  int _pin;
  int _refLevel;
  bool _rise, _fall; // 
  bool _up, _down; // Timestamp mark checkboxes

};

#endif