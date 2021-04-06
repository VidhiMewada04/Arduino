#include "cytron.h"
#include <Encoder.h>
//#include "base.h"
Encoder E(2, 3);

void setup() 
{
  Serial.begin(9600);
}

long oldPosition  = -999;

void loop() {
  long newPosition = E.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);}

  if(newPosition < 300){
    m.clk(50);
  }
}
