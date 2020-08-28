void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,INPUT);
 
}
volatile int val;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  
  val=digitalRead(10);
  Serial.println(val);
}
