const byte led = 10;
const byte interruptPin = 2;
const int steps=100;
volatile float j=0.5;
volatile int ct=0,weed=-1;
volatile int i=0,k=0;

//void ISR_func();
 
void setup() {
   pinMode(led, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_func, RISING);
   Serial.begin(9600);
}
 
void loop() {
 // if(weed>0){int timenow=millis();
//  while(millis()<timenow+1000){};};
   if(ct==1)
   {
    
    while(j<=2){
      { Serial.print("loop working for j="); Serial.println(j);
       // i=0;k=0;
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
    Serial.println("loop finished");
   }ct=0;Serial.print("ct= ");Serial.println(ct);
} 
}
 
void ISR_func() {
  Serial.print("ISR implemented    and ct=");Serial.println(ct);
   ct=1;
   j=0.5;
   i=0;
   k=0;
   weed++;
   Serial.println("weed= ");Serial.print(weed);
}
