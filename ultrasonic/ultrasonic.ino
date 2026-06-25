const int echo_pin = D7;
const int trig_pin = D5;
long duration;
float distance;

void setup() {
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Ultra Sonic Sensor
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  duration = pulseIn(echo_pin, HIGH);
  distance = duration * .034/2;


  //Displaying Readings

  // Distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  

  delay(1000);
}