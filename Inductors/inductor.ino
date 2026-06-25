const int emfPin = 35; // Analog pin connected to voltage divider

void setup() {
  Serial.begin(115200);
}

void loop() {
  int emfValue = analogRead(emfPin);
  
  if (emfValue > 100) { // Threshold to avoid noise
    Serial.print("Back EMF detected! Value: ");
    Serial.println(emfValue);
  }

  delay(500); // Delay in milliseconds to control sampling rate
}

