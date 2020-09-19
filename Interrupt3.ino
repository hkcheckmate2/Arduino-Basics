int led=10, button=2;
volatile float j=0.5;
volatile int ct=0;

 void func()
{
  Serial.println("ISR working");
  j=0.5;
  ct=1;
Serial.println("ct=");Serial.print(ct);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  attachInterrupt(0,func,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ct==1)
  {
      while(j<=2)
      {
        digitalWrite(led,HIGH);
        delay(j*1000);
        digitalWrite(led,LOW);
        delay(j*1000);
        j*=2;
        ct=0;
      }
   }
}
