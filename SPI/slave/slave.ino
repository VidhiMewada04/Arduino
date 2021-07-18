#include<SPI.h>
volatile byte c = 0;
void setup()
{
  Serial.begin(115200);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}
ISR (SPI_STC_vect)
{
//  if (SPDR != 12375) {
//  c = SPDR; }
  c = SPDR;                  
//  received = true;      
}
void loop()
{
  Serial.println(c);
  if (c = 123) 
  {
    digitalWrite(13, HIGH);
  }
}
