#include "Photogate.h"

Photogate::Photogate(const int* gate) : _gate(gate), _gateSize(s_gateSize), _isRunning(false)
{

}

Photogate::~Photogate()
{
  delete _gate;
  delete _timeStamps;
  delete _channel;
}


void Photogate::PinGate()
{
  for(int index = 0; index < 6; index++) {pinMode(_gate[index], INPUT_PULLUP);} // Change to INPUT later, check results.
}

void Photogate::InitPhotogate() //Called when init button is pressed.
{
  // Start counting, call timestamps.
  // Change _isRunning status.
  _isRunning = true;
}