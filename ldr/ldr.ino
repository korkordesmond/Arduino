
#define ldr_pin D2

int ldr_value;

void setup() {
  pinMode(ldr_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  ldr_value = digitalRead(ldr_pin);
  
  Serial.print("LDR: ");
  Serial.println(ldr_value);

  delay(1000);
}
