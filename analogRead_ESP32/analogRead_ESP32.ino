//Experiment 3: Reading a Potentiometer using ESP32

//Define the analog pin
const int potPin = 15;
const int ledPin = 18;
//GPI012 is input only

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
  //Start Serial Monitor at 115200 baud rate
}

void loop() {
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 4095, 0, 1023);

  for (int i= 0; i<5; i++){
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(brightness);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(1023 - brightness);
  }
  //Reads analog value (0-4095)

  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);
  Serial.println("Brightness: ");
  Serial.println(brightness);
  //Prints the Value

  //Delay for readability

}
