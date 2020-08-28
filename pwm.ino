void setup() {
  // put your setup code here, to run once:
   pinMode(10,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0; i<5000; i++)
  {
    for(int j=0; j<i; j++)
    {
      if(j==i-1)
      {digitalWrite(10,HIGH); digitalWrite(10,LOW);}}
  }
}
