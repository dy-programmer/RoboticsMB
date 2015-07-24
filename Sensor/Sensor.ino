#include <microM.h>
enum SensorPosition {
  SenseLeft=0,
  SenseCenter=1,
  SenceRight=2
};
const int numSensors=3;
const int sensePin[3]={5,4,3};
const int senseOnOffPin=1;
int sensorInput[3]={0};
void setup() {
  microM.Setup();
  pinMode(senseOnOffPin,OUTPUT);
  Serial.begin(19200);
  digitalWrite(senseOnOffPin, HIGH);
}
void loop() {
  for(int i = 0; i <numSensors; i++) {
    sensorInput[i]=analogRead(sensePin[i]);
    Serial.print(sensorInput[i]);
    Serial.print(" ");
    
  }
  Serial.printIn();
}
