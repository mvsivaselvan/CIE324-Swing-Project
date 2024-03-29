// For HX711
#include <HX711-multi.h>

// For BNO055 IMU
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

/////////////////////////////////////////////////////
// Timing-related definitions
#define BAUDRATE 115200
#define LOOPTIME 100
unsigned long startMillis;
unsigned long loopBeginMillis;
/////////////////////////////////////////////////////


void setup() {
  Serial.begin(BAUDRATE);
  Serial.flush();

  myIMU.begin();
  myIMU.setExtCrystalUse(true);

  startMillis = millis();
}

void loop() {
  loopBeginMillis = millis();

  // Read IMU
  imu::Vector<3> acc = myIMU.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER); //accel
  imu::Vector<3> omega = myIMU.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE); // angular vel
  imu::Vector<3> orient = myIMU.getVector(Adafruit_BNO055::VECTOR_EULER); // orientation
  
  // Read HX711s
  lcs.readRaw(forces);

  // Write time
  Serial.print(millis());
  Serial.print(",");

  // Write IMU data
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
  
  // Write load cell data
  for (int i=0; i<NUMLC; ++i) {;
    Serial.print(forces[i]);  
    Serial.print( (i!=NUMLC-1)?",":"\r\n");
  }

  // Wait until end of looptime
  while(millis()-loopBeginMillis < LOOPTIME);
}
