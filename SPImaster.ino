#include<SPI.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(SS,OUTPUT);
  digitalWrite(SS,HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV4);
}

void loop() {
  // put your main code here, to run repeatedly:
  char c;
  digitalWrite(SS,LOW);
   for (const char * p = "Hello, world!\n" ; c = *p; p++)
    SPI.transfer (c);

  digitalWrite(SS,HIGH);
}
