const int led=10, button=2;
volatile byte state=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==HIGH)
    {state=!(state);
    }
    digitalWrite(led,state);
}
