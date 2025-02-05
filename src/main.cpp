#include <Arduino.h>

#define LED_BUILTIN_PIN 13  // Built-in LED (usually pin 13)
#define LED_PIN_9  9        // External LED on pin 9
#define LED_PIN_10 10       // External LED on pin 10
#define LED_PIN_11 11       // External LED on pin 11

void setup() {
    pinMode(LED_BUILTIN_PIN, OUTPUT);
    pinMode(LED_PIN_9, OUTPUT);
    pinMode(LED_PIN_10, OUTPUT);
    pinMode(LED_PIN_11, OUTPUT);
}

void loop() {
    // Turn all LEDs on
    digitalWrite(LED_BUILTIN_PIN, HIGH);
    digitalWrite(LED_PIN_9, HIGH);
    digitalWrite(LED_PIN_10, HIGH);
    digitalWrite(LED_PIN_11, HIGH);
    delay(1000); // Wait 1 second

    // Turn all LEDs off
    digitalWrite(LED_BUILTIN_PIN, LOW);
    digitalWrite(LED_PIN_9, LOW);
    digitalWrite(LED_PIN_10, LOW);
    digitalWrite(LED_PIN_11, LOW);
    delay(1000); // Wait 1 second
}
