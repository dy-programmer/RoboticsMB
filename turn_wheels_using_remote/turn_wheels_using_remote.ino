#include <microM.h>

const int upKey=117;
const int downKey=118;
const int leftKey=53;
const int rightKey=52;
const int power=22;
const int forwardSpeedL=163;
const int forwardSpeedR=110;
const int reverseSpeedL=-163;
const int reverseSpeedR=-110;

void setup()
 {
   microM.Setup();    // this must be called to initialize timer 2
  microM.ircommand=0;
  //microM.irpin=4;                              // only required for external IR receivers. Defaults to 4 for onboard IR receiver

  Serial.begin(9600);                            // initialize serial monitor
  Serial.println("Ready to receive IR commands");
 }

 
 
 
 void loop()
 {
  if(microM.ircommand>0)                         // display command from IR receiver
  {
     Serial.print("\tIR command:");
    Serial.println(microM.ircommand,DEC);       // use the DEC option to convert a byte to a decimal number                          // prevents display repeating the same values
  }
 
  if (microM.ircommand == upKey)
   {
     microM.Motors(forwardSpeedL,forwardSpeedR,0,0);
     delay(1000);
   }   
  /*else if (microM.ircommand == downKey)
   {
     microM.Motors(0,0,reverseSpeedL,reverseSpeedR);
     delay(1000);
   }*/
  else if (microM.ircommand == rightKey)
   {
     microM.Motors(forwardSpeedL,0,0,0);
     delay(1000);
   }
  else if (microM.ircommand == leftKey)
   {
     microM.Motors(0,forwardSpeedR,0,0);
     delay(1000);
   }
  else if (microM.ircommand == power);
   {
     microM.Motors(0,0,0,0);
     delay(1000);
   }

 }
