const byte led = 10;
const byte interruptPin = 2;
volatile float j=0.5;
volatile int ct=0,flag=0;
volatile int i=0,k=0,timenow;

//void ISR_func();
 
void setup() {
   pinMode(led, OUTPUT);
   pinMode(interruptPin, INPUT_PULLUP);
   attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_func, RISING);
   Serial.begin(9600);
}
 
void loop() {
  if(ct){
      for(int i=0; (i<2000)&&(flag==0); i++){
       digitalWrite(led,HIGH);
       delay(1);
       
    }flag=1;
      for(int i=0; (i<2000)&&(flag==1); i++){
       digitalWrite(led,LOW);
       delay(1);
       
    } flag=0;
  } 
 }
 
void ISR_func() {
  Serial.print("ISR implemented    and ct=");Serial.println(ct);
   ct=1;
   flag=0;
}
