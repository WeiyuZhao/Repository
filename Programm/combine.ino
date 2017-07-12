#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;
int photocellPin = 2; // Fotowiderstand mit anallog pin 2 verbinden
int photocellVal = 0; // photocell variable
int minLight = 300;   // minimale Grenzwert
int ledPin = 12;
int ledState = 0; 


 
void setup() {
  Serial.begin(9600);
   pinMode(ledPin, OUTPUT); 
   stepper.setSpeed(100);
 }
 

 
 
void loop() {
  // Ablesen der Messwerte und Abgabe zu Serial Port 
  photocellVal = analogRead(photocellPin);
  Serial.println(photocellVal);  
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading


  // remember the previous value of the sensor
  previous = val;
   
  // Wenn die Helligkeit von Draussen zu hoch,schaltet LED ein und wird der Motor Uhrzeigerrichtung entlang getrieben.
  if (photocellVal < minLight && ledState == 0) {
    digitalWrite(ledPin, HIGH); // turn on LED
     stepper.step(400);
 
    ledState = 1;
  }
   
  // Wenn die Helligkeit von Draussen zu niedrig,schaltet LED aus und wird der Motor gegen Uhrzeigerrichtung entlang getrieben
  if (photocellVal > minLight && ledState == 1) {
    digitalWrite(ledPin, LOW);   // turn off LED

    stepper.step(- 400);
    ledState = 0;
  }  
   
  delay(100);       
}
