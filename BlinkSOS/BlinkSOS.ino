/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin ledPin. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  
  THIS HAS BEEN MODIFIED TO BLINK SOS IN MORSE CODE
 */
int ledPin=13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin ledPin as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level) S
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
  delay(1000);}
 
