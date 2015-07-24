#include <microM.h>

int forwardSpeedL=163;
int forwardSpeedR=110;
int reverseSpeedL=-163;
int reverseSpeedR=-110;

void setup()
{
  microM.Setup();
  microM.Motors(forwardSpeedL,forwardSpeedR,0,0); 
}

void loop()
{
}
