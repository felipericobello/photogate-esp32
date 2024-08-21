#include "Photogate.h"

Photogate::Photogate(const int* gate) : _gate(gate)
{
  for(int index = 0; index < 6; index++) {pinMode(gate[index], INPUT_PULLUP);} //INPUT_PULLUP mudará o resultado da leitura de INPUT, então, ver qual é mais vantajoso depois.
}