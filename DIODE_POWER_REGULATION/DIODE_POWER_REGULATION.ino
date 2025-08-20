#define LED_PIN 25

void setup(){
  pinMode(LED_PIN ,OUTPUT);
  Serial.begin(9600);
  Serial.println("ESP32 Active!!");
  delay(1000);
}

void loop(){
  digitalWrite(LED_PIN ,HIGH);
  Serial.println("LED ON");
  delay(5000);
}