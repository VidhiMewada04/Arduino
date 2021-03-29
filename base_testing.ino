#define pwm1  12
#define dirA1  11
#define dirB1  10
#define pwm2  12
#define dirA2  11
#define dirB2 10
#define pwm3  12
#define dirA3  11
#define dirB3  10
#define pwm4  12
#define dirA4  11
#define dirB4  10

void setup() {
  pinMode(pwm1, OUTPUT);
  pinMode(dirA1, OUTPUT);
  pinMode(dirB1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(dirA2, OUTPUT);
  pinMode(dirB2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(dirA3, OUTPUT);
  pinMode(dirB3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(dirA4, OUTPUT);
  pinMode(dirB4, OUTPUT);
}

void loop() {
  //base will run in forward direction in full speed for 1 sec..
  analogWrite(pwm1, 255);  analogWrite(pwm2, 255);  analogWrite(pwm3, 255);  analogWrite(pwm4, 255); 
  digitalWrite(dirA1, 1);   digitalWrite(dirA2, 1);   digitalWrite(dirA3, 1);   digitalWrite(dirA4, 1); 
  digitalWrite(dirB1, 0);   digitalWrite(dirB2, 0);   digitalWrite(dirB3, 0);   digitalWrite(dirB4, 0);
  delay(1000);            
  
  //base will run in backward direction in full speed for 1 sec..
  analogWrite(pwm1, 255);  analogWrite(pwm2, 255);  analogWrite(pwm3, 255);  analogWrite(pwm4, 255); 
  digitalWrite(dirA1, 0);   digitalWrite(dirA2, 0);   digitalWrite(dirA3, 0);   digitalWrite(dirA4, 0); 
  digitalWrite(dirB1, 1);   digitalWrite(dirB2, 1);   digitalWrite(dirB3, 1);   digitalWrite(dirB4, 1);
  delay(1000);
  
  //base will be free for 1 sec..
  analogWrite(pwm1, 255);  analogWrite(pwm2, 255);  analogWrite(pwm3, 255);  analogWrite(pwm4, 255); 
  digitalWrite(dirA1, 0);   digitalWrite(dirA2, 0);   digitalWrite(dirA3, 0);   digitalWrite(dirA4, 0); 
  digitalWrite(dirB1, 0);   digitalWrite(dirB2, 0);   digitalWrite(dirB3, 0);   digitalWrite(dirB4, 0);
  delay(1000);
  
  //base will stop for 1 sec..
  analogWrite(pwm1, 255);  analogWrite(pwm2, 255);  analogWrite(pwm3, 255);  analogWrite(pwm4, 255); 
  digitalWrite(dirA1, 1);   digitalWrite(dirA2, 1);   digitalWrite(dirA3, 1);   digitalWrite(dirA4, 1); 
  digitalWrite(dirB1, 1);   digitalWrite(dirB2, 1);   digitalWrite(dirB3, 1);   digitalWrite(dirB4, 1);
  delay(1000);
}
