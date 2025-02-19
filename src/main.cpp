#include <Arduino.h>

const int ledPin = 6;  // Define pin 6 as the LED pin

void setup() {
  pinMode(ledPin, OUTPUT);  // Set pin 6 as an output
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED on
  delay(1000);                 // Wait for 1 second
  digitalWrite(ledPin, LOW);   // Turn LED off
  delay(1000);                 // Wait for 1 second
}