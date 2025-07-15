int VoltPin = 15;
int readVal;
int delayTime = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(VoltPin);
  Serial.println(readVal);

  delay(delayTime);

}