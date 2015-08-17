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

const int upKey=117;
const int downKey=118;
const int leftKey=53;
const int rightKey=52;
const int power=22;
const int forwardSpeedL=160;
const int forwardSpeedR=110;
const int reverseSpeedL=-160;
const int reverseSpeedR=-110;
const int t=50;

int sensorInput[3]={0};// sensor inputs

void setup()
{
  microM.Setup(); // set up the library
  pinMode(senseOnOffPin,OUTPUT); // set up sensor on/off pin
  Serial.begin(19200); // set the serial port speed.
  digitalWrite(senseOnOffPin, HIGH);  // Turn on the sensor
  microM.ircommand=0;
}

void sensorData(int index)
{
  if (index == 0)
  {
    sensorInput[index]=analogRead(sensePin[index])-420;//350
    Serial.print(sensorInput[index]);
    Serial.print(" "); 
  } 
  
   
  if (index == 1)
  {
    sensorInput[index]=analogRead(sensePin[index])-450;//270
    Serial.print(sensorInput[index]);
    Serial.print(" "); 
  } 
  
  if (index == 2)
  {
    sensorInput[index]=analogRead(sensePin[index])-560;//360
    Serial.print(sensorInput[index]);
    Serial.print(" "); 
  } 
}

void remoteControl (int ir_signal)
{
if (ir_signal == upKey)
   {
     microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
     microM.ircommand = 0;
     delay (t);
   }

else if (ir_signal == downKey)
   {
     microM.Motors(reverseSpeedL,reverseSpeedR,0,0);
     microM.ircommand = 0;
     delay (t);
   }
   
else if (ir_signal == rightKey)
   {
     microM.Motors(forwardSpeedL,0,0,0);
     microM.ircommand = 0;
     delay (t);
   }
   
else if (ir_signal == leftKey)
   {
     microM.Motors(0,forwardSpeedR,0,0);
     microM.ircommand = 0;
     delay (t);
   }

else if   (ir_signal == power)
   {
     microM.Motors(0,0,0,0);
     microM.ircommand = 0;
     delay (t);
   }
   
else
   {
     microM.Motors(0,0,0,0);
     microM.ircommand = 0;
   }
}

void detectObject (int sensorInfo)
{   
 if ((sensorInfo == 1) && (sensorInput[sensorInfo]>220))
{
  Serial.print("detectStraight");
  Serial.print(" ");
  microM.Motors(0,0,0,0);
  delay(50); // 50 is just so the code will work. I don't know the actual time length the robot should back up.
  do
  {
    microM.Motors(reverseSpeedL,reverseSpeedR,0,0);
    delay(50);
  }
  while ((sensorInput[0]>300) && (sensorInput[2]>100));
  if ((sensorInput[0]<300) || (sensorInput[2]>100))
  {
    microM.Motors(0,0,0,0);
    delay (50);
  }
 /* if ((sensorInput[2]<100))
  {
    Serial.print("Open Right");
    Serial.print(" ");
    microM.Motors(forwardSpeedL,0,0,0);
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(0,forwardSpeedR,0,0);
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
  } 
  if ((sensorInput[0]<300));
  {
    Serial.print("Open Left");
    Serial.print(" ");
    microM.Motors(0,forwardSpeedR,0,0);
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(forwardSpeedL,forwardSpeedR,0,0);   
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(forwardSpeedL,0,0,0);
    delay(50);
    microM.Motors(0,0,0,0);
    delay(50);
    microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
  } */
}

}

void loop()
{
 if(microM.ircommand>0)
  {
    Serial.print("\tIR command:");
    Serial.println(microM.ircommand,DEC);
  }
  for (int i = 0; i < numSensors; i++)
  {
    sensorData(i); // filling array sensor
 
    if (sensorInput[1]<220)
    {
      microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
      delay(50);
      microM.Motors(0,0,0,0);
      delay(50);
    }

 remoteControl(microM.ircommand);
   detectObject(i);
  }
  Serial.println();
}
/*Sensor readings are affected by light. Remember to normalize
in each environment.
In the loop, i=0 is the RIGHT sensor. i=2 is the LEFT sensor.
Maybe I could use while loops to have robot avoid obstacles?
Write*/
