#define LED_PIN 21
#define BUTTON_PIN 5

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("The ESP32 is Active!!!");

}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  Serial.println((state)? "Button Released": "Button Pressed");

  if(state == LOW){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED ON");
  }else{
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED OFF");}
  delay(500);
}
