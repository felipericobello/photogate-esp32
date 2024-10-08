#include "Photogate.h"


Photogate::Photogate(const unsigned int* gate) : _gate(gate), _gateSize(s_gateSize), _isRunning(true)
{
  _TimeStamps = new TimeStamps();

  for(int i = 0; i < _gateSize; i++)
  {
    _Channel[i] = new Channel(i, _gate[i]);
  }

}


Photogate::~Photogate()
{
}


void Photogate::PinSetGate()
{
  for(int index = 0; index < 6; index++) {pinMode(_gate[index], INPUT_PULLUP);} // Change INPUT_PULLUP to INPUT later, check results.
  // INPUT_PULLUP: 4096 when no light is detected (must use a resistor connected to VCC, otherwise it might not work if not using devboards)
  // INPUT: 4096 when all light is detected
}


void Photogate::InitPhotogate() //Called when init button is pressed.
{
  // Start counting, call timestamps.
  // Change _isRunning status.
  _isRunning = true;
}

void Photogate::OnUpdate() // If read starts, should use this function to get time and analog data. (if using lm393, should get digital data).
{
  unsigned int t_Read[s_gateSize] = {0};

  _TimeStamps->SetTime();
  while(Serial.available() == 0)
  {
    for(int index = 0; index<s_gateSize; index++)
    {
      t_Read[index] = _Channel[index]->Read();
      //t_Read[index] = analogRead(_gate[index]);
    }

    _TimeStamps->DeltaTime();

    for(int index = 0; index<s_gateSize; index++)
    {
      //Serial.write(t_Read[index]); // Writes analog reads on serial
      Serial.print("Read Analog Port "); Serial.print(index); Serial.print(": ");
      Serial.println(t_Read[index]);
    }

    unsigned long t_dTime = _TimeStamps->GetDeltaTime();
    //Serial.write(t_dTime); // Writes deltaTime on serial
    Serial.println(t_dTime);
    
    delay(1000); // debug purposes.
  }
}

