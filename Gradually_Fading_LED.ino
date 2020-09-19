int led = 10;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int om=11;
int i=0;
int j=0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(om, INPUT);
}
 
void loop() {
  
  if(digitalRead(om)==HIGH){
  
  analogWrite(led, brightness);

  if(brightness!=255){
  brightness = brightness + fadeAmount;}
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }

  else
  {analogWrite(led,0); brightness=0;}
  delay(20000/255); //10000 ms for reaching full brightness and 10000 ms for 0
}
