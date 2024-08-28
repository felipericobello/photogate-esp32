#ifndef CHANNEL_H
#define CHANNEL_H

#define REF_LEVEL 2048 // If channel read surpasses the reference level, then triggers timer as up or down.

#include <Arduino.h>

class Channel
{
public: 
  Channel(int index, int pin);

public:
  inline bool GetUP() {return _up;}
  inline bool GetDown() {return _down;}
  inline bool IsRising() {return _rise;}
  inline bool IsFalling() {return _fall;}
  inline int  GetPin() {return _pin;}

public:
  inline void SetReferenceLevel(int referenceLevel) { _refLevel = referenceLevel; }
  inline void SetMarkUP() {_up = !_up;} // Called via webserver. Must not work on OnUpdate().
  inline void SetMarkDown() {_down = !_down;} // Called via webserver. Must not work on OnUpdate().
  inline void SetRiseTimer(unsigned long riseTimer) {_riseTimer = riseTimer;}
  inline void SetFallTimer(unsigned long fallTimer) {_fallTimer = fallTimer;}

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
  bool _rise, _fall; // needed for rise and fall timestamps.
  unsigned long _riseTimer;
  unsigned long _fallTimer;
  bool _up, _down; // Timestamp mark checkboxes

};

#endif