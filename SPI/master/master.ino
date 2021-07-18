#include<SPI.h>
void setup()
{
  Serial.begin(115200);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  digitalWrite(SS, HIGH);
}

void loop()
{
  digitalWrite(SS, LOW);
  int a = SPI.transfer(123);
}
