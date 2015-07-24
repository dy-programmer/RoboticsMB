
#include <microM.h>

void setup()
{
  microM.Setup();
  microM.Motors(0,255,0,0); //to check if left motor is good, type 255 in first slot. For right motor, type 255 in second slot. -255 is to make robot go backward.
}

void loop()
{
  
}
/* left group of plugs: black red. right: black red.battery: black red



