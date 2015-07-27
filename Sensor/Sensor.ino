#include <microM.h>   // Use the microM library for motor control, IR command

enum SensorPosition {
  SenseLeft=0, 
  SenseCenter=1,
  SenseRight=2,
}; 
const int numSensors=3;
//
// Sensing pins
//
const int sensePin[3]={5,4,3};  // array containing the pin numbers
// for right,center, and left

const int senseOnOffPin=1;

int sensorInput[3]={0}; // sensor inputs

void setup()
{
  microM.Setup(); // set up the library
  pinMode(senseOnOffPin,OUTPUT); // set up sensor on/off pin
  Serial.begin(19200); // set the serial port speed.
  digitalWrite(senseOnOffPin, HIGH);  // Turn on the sensor
}

void loop()
{
  for (int i = 0; i < numSensors; i++)
{  
  if (i == 0)
  {
    sensorInput[i]=analogRead(sensePin[i])-350;
    Serial.print(sensorInput[i]);
    Serial.print(" ");
  } 

  
  if (i == 1)
  {
    sensorInput[i]=analogRead(sensePin[i])-270;
    Serial.print(sensorInput[i]);
    Serial.print(" ");
  } 
  
  if (i == 2)
    {
    sensorInput[i]=analogRead(sensePin[i])-360;
    Serial.print(sensorInput[i]);
    Serial.print(" ");
  } 
 
}
Serial.println();
}
/*To normalize sensor readings so reading is about 0 
when nothing is in front of it, write a function subtracting
value of reading when nothing's in front.*/
