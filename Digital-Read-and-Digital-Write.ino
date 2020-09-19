/*
Reading Port 2 and Writing the same signal to Port 10
*/
void setup() {
 pinMode(10,OUTPUT);
 pinMode(2,INPUT);}
void loop() {
  digitalWrite(10,digitalRead(2));
}
