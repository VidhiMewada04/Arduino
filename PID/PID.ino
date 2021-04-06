#include <PID_v1.h>
#define PIN_INPUT A0
#define PIN_OUTPUT 3

double Setpoints, Input, Output;
double Kp = 0, Ki = 10, Kd = 0;
PID myPID(&Input, &Output, &Setpoints, Kp, Ki, Kd, DIRECT);

void setup() {
  Serial.begin(115200);
  Input = analogRead(PIN_INPUT);
  Setpoints = 75;
  myPID.SetMode(AUTOMATIC);
  myPID.SetTunings(Kp, Ki, Kd);
}

void loop() {
  Input = map(analogRead(A0), 0, 1024, 0, 255);
  myPID.Compute();
  analogWrite(3, Output);
  Serial.println(Input);
  Serial.println(" ");
  Serial.println(Output);
  Serial.println(" ");
  Serial.println(Setpoints);
//  Serial.print(digitalRead(A0));
//  Serial.print("-");
//  Serial.print(digitalRead(3));
//  Serial.print("-");
//  Serial.println(setpoint);
}
