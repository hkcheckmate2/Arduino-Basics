void setup() {
 pinMode(10,OUTPUT);
void loop() {
  for(int i=0; i<1024; i++)
  {
    analogWrite(10,i);
  }
};
