const byte led = 10;
const byte interruptPin = 2;
//const int steps=100;
volatile float j=0.5;
volatile int ct=0,flag=-1;
volatile int i=0,k=0;
volatile long int times=0;
//void ISR_func();
 
void setup() {
   pinMode(led, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_func, RISING);
   Serial.begin(9600);
}
 
void loop() {
   if(ct==1)
   {
    
    while(j<=2){
      { Serial.print("loop working for j="); Serial.println(j);
        i=0;k=0;
        if((flag)&&(j==0.5)){
          times=millis();
          while(millis()<times+1000){};
        }
        while(i<510){
        analogWrite(led,k); delay(3.921*j);  //0<k<255
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
    Serial.println("loop finished");
   }ct=0;Serial.print("ct= ");Serial.println(ct);
}}
 
void ISR_func() {
  Serial.print("ISR implemented    and ct=");Serial.println(ct);
   ct=1;
   j=0.5;
   i=0;
   k=0;
   flag++;
}
