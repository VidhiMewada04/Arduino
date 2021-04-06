#include "base.h"
#include "pneu.h"
#include <Encoder.h>
#include <TFMini.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
float angle = 0;
float oldangle = 0;
float newangle = 0;
int p = 100;
int count = 0;
#define l1 A6
#define l2 A0
#define Reed A7
Encoder E(2, 3);
long oldE  = -999;
long newE = 0;
TFMini tfmini1;
TFMini tfmini2;
MPU6050 mpu(Wire);
void (*resetFunc) (void) = 0;

void setUP() 
{ 
  pinMode(l1, INPUT_PULLUP);
  pinMode(l2, INPUT_PULLUP);
  pinMode(Reed, INPUT_PULLUP);
  while (!Serial2);
  Serial2.begin(TFMINI_BAUDRATE);
  tfmini1.begin(&Serial2);  
  while (!Serial3);
  Serial3.begin(TFMINI_BAUDRATE);
  tfmini2.begin(&Serial3);  
  Wire.begin();
  mpu.begin(); 
  mpu.calcGyroOffsets(true); 
}

void relayoff() 
{
  N1.fre();
  N2.fre(); 
}

void limitoff() 
{
  if(digitalRead(l1) == 0) {
    m.stp(0); 
    m.clk(50);
    delay(70); }    
  else if(digitalRead(l2) == 0) {
    m.stp(0); 
    m.aclk(50);
    delay(70); } 
}

void REED() 
{
  while(count < 2){
    if(digitalRead(Reed) == 0){
      count++; } 
    else{ 
      N1.fre(); } }
  N1.up(); 
  count = 0; 
}

void tfmini() 
{
  uint16_t dist1 = tfmini1.getDistance();
  Serial.print(dist1);
  uint16_t dist2 = tfmini2.getDistance();
  Serial.print(dist2);
}

void mpu6050() 
{
  mpu.update();
  angle = mpu.getAngleZ();
  if (angle != oldangle){
    oldangle = angle; }
}
  
void encoder() 
{
  newE = E.read();   
  if (newE != oldE) {
    oldE = newE; } 
}
    
void mpuL1()  //+
{  
  mpu.update();
  angle = mpu.getAngleZ();
  m1.clk(p);
  m2.clk(p);    
  m3.aclk(p+50);
  m4.aclk(p+50); 
}
  
void mpuR1()  //-
{   
  mpu.update();
  angle = mpu.getAngleZ();
  m1.clk(p+50);
  m2.clk(p+50);
  m3.aclk(p);
  m4.aclk(p); 
}

void mpuL2()  //+
{  
  mpu.update();
  angle = mpu.getAngleZ();
  m1.aclk(p);
  m2.aclk(p);    
  m3.clk(p+50);
  m4.clk(p+50); 
}
  
void mpuR2()  //- 
{  
  mpu.update();
  angle = mpu.getAngleZ();
  m1.aclk(p+50);
  m2.aclk(p+50); 
  m3.clk(p);
  m4.clk(p); 
}
    
void Forward() 
{
  mpu.update();
  if(-40 < oldangle && oldangle < -5) {
    mpuR1(); }
  if(-5 < oldangle && oldangle < 5) {
    bot.forward(); }
  if(5 < oldangle && oldangle < 40) {
    mpuL1();  }
  else {
    bot.stpp(); }
//    Serial.print("angle:");
//    Serial.println(angle);
//    Serial.print("oldangle:");
//    Serial.println(oldangle); 
//    Serial.print("newangle:");
//    Serial.println(newangle); 
}

void Backward() 
{
  mpu.update();
  if(-40 < oldangle && oldangle < -5) {
    mpuR2(); }
  if(-5 < oldangle && oldangle < 5) {
    bot.backward(); }
  if(5 < oldangle && oldangle < 40) {
    mpuL2(); }
  else {
    bot.stpp(); } 
}
