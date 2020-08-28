#include<SPI.h>

char buffer[5];
volatile byte pos; //position of array
volatile boolean process_it=false; //data to be processed when process_it is true

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("SPI test");
  pinMode(MISO,OUTPUT);
  digitalWrite(MISO,LOW);
  SPCR |=_BV(SPE); //spi enable spcr=spi control resistor
  SPCR |= _BV(SPIE); // IE here means interrupt enable
  //SPI.attachInterrupt()   to attach interrupt
}

ISR(SPI_STC_vect)
{
  byte c= SPDR; //SPI Data Register
  if(pos<sizeof(buffer))
  {
    buffer[pos++]=c;
    if(c=='\n')
    {
      process_it=true;
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:

  if(process_it)
  {
    Serial.println(buffer);
    pos=0;
    process_it=false;
  }
}
