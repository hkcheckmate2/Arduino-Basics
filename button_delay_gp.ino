int led=10, button=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==HIGH)
  {
      for(float j=0.5; j<=2; j*=2)
      {
        digitalWrite(led,HIGH);
        delay(j*1000);
        digitalWrite(led,LOW);
        delay(j*1000);
      }
   }
}
