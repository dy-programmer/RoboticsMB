int ledPin=13;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void shortBlinks()
{
  for (int i = 0; i < 3; i++)
{digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level) S
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
}
}

void longBlinks()
{
  for (int i = 0; i < 3; i++)
  {digitalWrite(ledPin, HIGH); // O
  delay(1000); 
  digitalWrite(ledPin, LOW); 
  delay(1000);
  }
}


void combinedBlinks()
{
  for (int i = 0; i < 3; i++)
  {  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level) S
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  digitalWrite(ledPin, HIGH); // O
  delay(1000); 
  digitalWrite(ledPin, LOW); 
  delay(1000); 
  digitalWrite(ledPin, HIGH);
  delay(1000); 
  digitalWrite(ledPin, LOW); 
  delay(1000); 
  digitalWrite(ledPin, HIGH);
  delay(1000); 
  digitalWrite(ledPin, LOW); 
  delay(1000);
   digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level) S
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(100);                     // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
      
  }
}


  

void loop()
{ 
   combinedBlinks();
   delay(3000);
}
