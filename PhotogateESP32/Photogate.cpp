#include "Photogate.h"


Photogate::Photogate(const int* gate) : _gate(gate), _gateSize(s_gateSize), _isRunning(false)
{
  _TimeStamps = new TimeStamps();

  for(int i = 0; i < _gateSize; i++)
  {
    _Channel[i] = new Channel(i, _gate[i]);
  }

}


Photogate::~Photogate()
{
  delete _gate;
  delete _TimeStamps;
  delete _Channel;
}


void Photogate::PinSetGate()
{
  for(int index = 0; index < 6; index++) {pinMode(_gate[index], INPUT_PULLUP);} // Change to INPUT later, check results.
}


void Photogate::InitPhotogate() //Called when init button is pressed.
{
  // Start counting, call timestamps.
  // Change _isRunning status.
  _isRunning = true;
}


void Photogate::OnUpdate()
{
  unsigned int t_Read[s_gateSize] = {0};

  _TimeStamps->SetTime();
  while(Serial.available() == 0)
  {
    for(int index = 0; index<s_gateSize; index++)
    {
      t_Read[index] = _Channel[index]->Read();
    }

    _TimeStamps->DeltaTime();

    for(int index = 0; index<s_gateSize; index++)
    {
      Serial.write(t_Read[index]); // Writes analog reads on serial
    }

    unsigned long t_dTime = _TimeStamps->GetDeltaTime();
    Serial.write(t_dTime); // Writes deltaTime on serial
  }
}

