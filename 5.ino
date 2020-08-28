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
  
  analogWrite(led, j);

  //if(brightness!=255){
  // brightness = brightness + fadeAmount;}
  //if (brightness == 0 || brightness == 255) {
    //fadeAmount = -fadeAmount ;
  //}

  if(i<510)
  { if(i<255)
    {
      j++;
      i++;
    }
    if(i>=255)
    {
      j--;
      i++;
    }
  }
  }
  else
  {analogWrite(led,0); brightness=0; i=0; j=0;}
  delay(10000/255);
}
