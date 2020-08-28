int led=10;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //send data only when you receive data
  if(Serial.available()>0){
    x=Serial.parseInt();
    analogWrite(led,x);
                                                    //Serial.setTimeout(1000);
 }
}
