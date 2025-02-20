#include <Arduino.h>

int   a = 5635;
int   b;
float c;

void setup() {
  //initialize serial communication
  Serial.begin(9600);

}

void loop() {
  b = a/4;  
  c = a/4;  

  Serial.print("b = ");
  Serial.println(b);
  Serial.print("c = ");
  Serial.println(c);
  delay(5000);
}
