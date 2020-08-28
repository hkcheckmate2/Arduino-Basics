

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(10,INPUT);
  pinMode(9,INPUT);
}

void loop() {
 
  digitalWrite(10,LOW );
  digitalWrite(9,LOW);
  Serial.println(digitalRead(8));
}
