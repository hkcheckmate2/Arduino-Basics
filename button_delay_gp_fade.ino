int led=10, button=2;
float steps=100;

volatile float j=0.5;
volatile int ct=1;


void func();

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{     
  if (digitalRead(button)==HIGH){
  //for(j=0.5; j<=2; j*=2)
  float j=0.5;
  while(j<=2){
      { Serial.println("loop working");
        float i=0,k=0;
        while(i<510){
        analogWrite(led,k); delay(500*(j/steps));  //0<k<255
        if(i<255)
        {
           k++;
           i++;
        }
        if(i>=255)
        {
            k--;
            i++;
        }
        }
      digitalWrite(led,LOW);
      j*=2;
      }
 }}}

 void func()
{
  Serial.println("ISR working");
  j=0.5;
  ct=1;
  Serial.println("ct=");Serial.print(ct);
}
 
