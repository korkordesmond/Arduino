int myVoltPin = 15;       // ADC pin
int readVal;              // Raw ADC reading
float V2;                 // Converted voltage
int delayT = 250;         // Delay in milliseconds

void setup() {
  Serial.begin(9600);     // Start serial communication
}

void loop() {
  readVal = analogRead(myVoltPin);             // Read analog value (0–4095)
  V2 = (3.3 / 4095.0) * readVal;               // Convert to voltage

  Serial.print("Read Value   : ");
  Serial.println(readVal);

  Serial.print("Voltage      : ");
  Serial.println(V2, 3);  // Print with 3 decimal places

  Serial.println();       // Blank line for readability
  delay(delayT);          // Wait before next reading
}
