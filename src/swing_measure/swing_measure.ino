#include <HX711-multi.h>

#define NUMLC 2 // number of load cells

// Pins for the HX711 amplifiers
#define CLK 2 // clock pin shared across all the HX711s
#define LC1 3 // data pin for load cell #1
#define LC2 4 // data pin for load cell #2

# define GAIN 128

byte DOUTS[NUMLC] = {LC1, LC2};

HX711MULTI lcs(NUMLC, DOUTS, CLK, GAIN);

long int forces[NUMLC];

void setup() {
  Serial.begin(57600);
  Serial.flush();
}

void loop() {
  lcs.readRaw(forces);
  for (int i=0; i<NUMLC; ++i) {;
    Serial.print(forces[i]);  
    Serial.print( (i!=NUMLC-1)?",":"\r\n");
  }
  delay(100);
}
