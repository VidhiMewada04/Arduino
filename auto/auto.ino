#include "ash.h"
void setup()
{
  Serial.begin (9600);
  Serial.println("setup started");
  setUP();
  relayoff();
}

void loop()
{
  tfmini();
  mpu.update();
  limitoff();
  mpu6050();
  encoder();

  //  while(newE < 10000) {
  //    bot.left(); }
  //  bot.stpp();
  //  delay(100);
  //  bot.backward();
  //  delay(500);

  while (newE < 3500) {
    bot.left(50);
  }
  bot.stpp();
  while (digitalRead(l1) == 1 && dist1 <= 100) {
    bot.left(pwm);
  }
  bot.stpp();
  delay(500);
  while (digitalRead(l1) == 0) {
    bot.stpp();
    delay(500);
    backward(pwm);
  }

  bot.stpp();
  delay(500);
  
  while (digitalRead(l1) == 0 || dist2 >= 50 ) { //&& dist1 <= 30) {
    bot.downLeft(100);
    v = 1;
  }
  bot.stpp();
  delay(500);

  if (digitalRead(l1) == 0)
  {
    bot.stpp();
  }
  while (dist2 >= 50)
  {
    bot.downLeft(100);
  }

  while (digitalRead(l1) == 1 && v == 1 && dist2 >= 50) {
    bot.downLeft(100);
  }

  bot.stpp();
  while(1);
}
