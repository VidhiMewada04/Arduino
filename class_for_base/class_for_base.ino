#include "base.h"

void setup() 
{
}

void loop() 
{
  bot.forward();
  delay(1000);
  bot.backward();
  delay(1000);
  bot.left();
  delay(1000);
  bot.right();
  delay(1000);
}
