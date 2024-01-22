// For HX711
#include <HX711-multi.h>

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/////////////////////////////////////////////////////
// LOAD CELL-related defintions
#define NUMLC 6 // number of load cells

// Pins for the HX711 amplifiers
#define CLK 2 // clock pin shared across all the HX711s
#define LC1 3 // data pin for load cell #1
#define LC2 4 // data pin for load cell #2
#define LC3 5 // data pin for load cell #3
#define LC4 6 // data pin for load cell #4
#define LC5 7 // data pin for load cell #5
#define LC6 8 // data pin for load cell #6

# define GAIN 128 // Gain for HX711s

byte DOUTS[NUMLC] = {LC1, LC2, LC3, LC4, LC5, LC6};

HX711MULTI lcs(NUMLC, DOUTS, CLK, GAIN);

long int forces[NUMLC];
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
// IMU-related definitions
Adafruit_BNO055 myIMU = Adafruit_BNO055();

/////////////////////////////////////////////////////

void setup() {
  Serial.begin(57600);
  Serial.flush();

  myIMU.begin();
  myIMU.setExtCrystalUse(true);
}

void loop() {
  imu::Vector<3> acc = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER); //accel
  imu::Vector<3> omega = myIMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE); // angular vel
  imu::Vector<3> orient = myIMU.getVector(Adafruit_BNO055::VECTOR_EULER); // orientation
  Serial.print(acc.x());
  Serial.print(",");
  Serial.print(acc.y());
  Serial.print(",");
  Serial.print(acc.z());
  Serial.print(",");
  Serial.print(omega.x());
  Serial.print(",");
  Serial.print(omega.y());
  Serial.print(",");
  Serial.print(omega.z());
  Serial.print(",");
  Serial.print(orient.x());
  Serial.print(",");
  Serial.print(orient.y());
  Serial.print(",");
  Serial.print(orient.z());
  Serial.print(",");
  
  lcs.readRaw(forces);
  for (int i=0; i<NUMLC; ++i) {;
    Serial.print(forces[i]);  
    Serial.print( (i!=NUMLC-1)?",":"\r\n");
  }
  delay(100);
}
