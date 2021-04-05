#include <Ultrasonic.h>
#define pwm 8      
#define dir 11 
Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  distance = ultrasonic.read();
  Serial.print("Distance in CM: "); Serial.println(distance);

  if(distance <= 100){
    analogWrite(pwm, HIGH);   //motor will rotate in one direction
    digitalWrite(dir, HIGH);
  }
  else if(distance >= 100){
    analogWrite(pwm, HIGH);   //motor will rotate in secong direction
    digitalWrite(dir, LOW);
  }
  else {
    analogWrite(pwm, LOW);    //motor will stop rotating
  }
}
