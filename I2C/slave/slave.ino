#include <Wire.h>
#define LED 13
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Wire.begin(9);   
}
void loop() {
  Serial.println(Wire.read());
  yield();
}
