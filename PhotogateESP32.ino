#define USE_INTRANET

// Utilizado para debug do código. Deve ser usado somente dessa maneira.
#define LOCAL_SSID "XXX"
#define LOCAL_PASS "XXX"

// Definição do WebServer.
#define AP_SSID "PhotoGateXX"
#define AP_PASS "ccaufscarxx"

// Definição do pinout dos sensores(photogate). Preferencialmente utilizar variáveis.
const int gate[6] = {36, 37, 38, 39, 32, 33};

#include <WiFi.h>

#include "Photogate.h" // Classe das funções do photogate

#ifdef USE_INTRANET

#endif


#ifdef USE_INTRANET

#endif


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
