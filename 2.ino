void setup() {
 pinMode(10,OUTPUT);
 pinMode(2,INPUT);}
void loop() {
  digitalWrite(10,digitalRead(2));
}
