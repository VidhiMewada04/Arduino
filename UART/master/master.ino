#include <Wire.h>
void setup() {
  Serial.begin(9600);
  Wire.begin();
}
void loop() {
  Wire.beginTransmission(9);
  Wire.write(123);
  Wire.endTransmission();
}
