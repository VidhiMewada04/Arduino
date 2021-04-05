//LSA will give value between 0 to 70

#define Analog 12    //analog pin of lsa08
#define Junction 13  //junction pin of lsa08

#define pwm1 8       //left wheel 
#define inA1 11 
#define inB1 10

#define pwm2 9       //right wheel
#define inA2 14 
#define inB2 15

void setup() 
{
  pinMode(Analog, INPUT);
  pinMode(Junction, INPUT);

  pinMode(pwm1, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inB1, OUTPUT);
  
  pinMode(pwm2, OUTPUT);
  pinMode(inA2, OUTPUT);
  pinMode(inB2, OUTPUT);
}

void loop() 
{
  if(0 <= Analog <= 15) {                                 //clockwise
    analogWrite(pwm1, HIGH);   analogWrite(pwm2, HIGH);
    digitalWrite(inA1, HIGH);  digitalWrite(inA2, LOW);
    digitalWrite(inB1, LOW);  digitalWrite(inB2, HIGH);    
  }
  if(15 < Analog <= 35) {                                 //right
    analogWrite(pwm1, HIGH);   analogWrite(pwm2, HIGH);
    digitalWrite(inA1, HIGH);  digitalWrite(inA2, LOW);
    digitalWrite(inB1, LOW);  digitalWrite(inB2, LOW);    
  }
  if(35 < Analog < 45) {                                  //forward
    analogWrite(pwm1, HIGH);   analogWrite(pwm2, HIGH);
    digitalWrite(inA1, HIGH);  digitalWrite(inA2, HIGH);
    digitalWrite(inB1, LOW);  digitalWrite(inB2, LOW);    
  }
  if(45 <= Analog < 55) {                                 //left
    analogWrite(pwm1, HIGH);   analogWrite(pwm2, HIGH);
    digitalWrite(inA1, LOW);  digitalWrite(inA2, HIGH);
    digitalWrite(inB1, LOW);  digitalWrite(inB2, LOW);    
  }
  if(55 <= Analog <= 70) {                                //anticlockwise
    analogWrite(pwm1, HIGH);   analogWrite(pwm2, HIGH);
    digitalWrite(inA1, LOW);  digitalWrite(inA2, HIGH);
    digitalWrite(inB1, HIGH);  digitalWrite(inB2, LOW);    
  }
}
