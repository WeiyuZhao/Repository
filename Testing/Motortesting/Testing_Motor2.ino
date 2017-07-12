 photocellVal =250
 void setup()
{
   pinMode(ledPin, OUTPUT); 
 }

void loop() {
 
 
 
  if (photocellVal < 300) 
  {
    digitalWrite(ledPin, HIGH); // turn on LED
  }
  if (photocellVal >300) 
  {
    digitalWrite(ledPin, LOW);   // turn off LED
  }  
  delay(100);       
}
