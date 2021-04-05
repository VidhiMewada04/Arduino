#include "motor.h"
#define p 100         //pwm
void setup()
{
}
void loop()
{
  //forward
  m1.clk(p);
  m2.clk(p);
  m3.aclk(p);
  m4.aclk(p);
  delay(1000);
  //backward
  m1.aclk(p);
  m2.aclk(p);
  m3.clk(p);
  m4.clk(p);
  delay(1000);
  //left
  m1.clk(p);
  m2.aclk(p);
  m3.aclk(p);
  m4.clk(p);
  delay(1000);
  //right
  m1.aclk(p);
  m2.clk(p);
  m3.clk(p);
  m4.aclk(p);
  delay(1000);
}
