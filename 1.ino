void setup() {
 pinMode(10,OUTPUT);
 pinMode(2,INPUT);}
void loop() {
  if(digitalRead(2)==HIGH){
  digitalWrite(10,HIGH);
  delay(3000);
  digitalWrite(10,LOW);
}
