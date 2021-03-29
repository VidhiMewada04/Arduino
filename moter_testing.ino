#define pwm = 12
#define dir1 = 11
#define dir12 = 10

void setup() {
  pinMode(pwm, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
}

void loop() {
  //wheel will rotate in clockwise direction for 1 sec..
  analogWrite(pwm, 255);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 0);
  delay(1000);            
  
  //wheel will rotate in anticlockwise direction for 2 sec..
  analogWrite(pwm, 255);
  digitalWrite(dir1, 0);
  digitalWrite(dir2, 1);
  delay(2000);
  
  //wheel will rotate freely for 1.5 sec..
  analogWrite(pwm, 255);
  digitalWrite(dir1, 0);
  digitalWrite(dir2, 0);
  delay(1500);
  
  //wheel will stop rotating for 5 sec..
  analogWrite(pwm, 255);
  digitalWrite(dir1, 1);
  digitalWrite(dir2, 1);
  delay(5000);
}
