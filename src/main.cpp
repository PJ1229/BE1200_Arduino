#include <Arduino.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT); // Set built-in LED as output
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH); // Turn LED on
    delay(2000);                      // Wait 2000 milliseconds
    digitalWrite(LED_BUILTIN, LOW);  // Turn LED off
    delay(750);                      // Wait 750 milliseconds
}
