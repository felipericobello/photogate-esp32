#define USE_INTRANET
// #define USE_INTERNET

// Debug only
#define LOCAL_SSID "XXX"
#define LOCAL_PASS "XXX"


#define AP_SSID "PhotoGateXX"
#define AP_PASS "ccaufscarxx"

#include <WiFi.h>
#include "Photogate.h"

// Photogate pinout.
const int gate[6] = {36, 37, 38, 39, 32, 33}; // Follows the order of ADC Channels
Photogate Gate(gate);


#ifdef USE_INTRANET

#endif


#ifdef USE_INTERNET

#endif


void setup() 
{
  Gate.PinGate();
}

void loop() 
{
  // If start button pressed, calls Gate.InitPhotogate();
  // then,
  // Photogate time loop: 
  if(Gate.IsRunning())
  {

  }
}
