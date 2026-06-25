#include "DHT.h"

#define dht_type DHT22
#define dht_pin D4
#define echo_pin D7
#define trig_pin D5
#define ldr_pin D2

DHT dht(dht_pin, dht_type);

long duration;
float distance;
float temperature, humidity;
int ldr_state;

void setup() {
  pinMode(ldr_pin, INPUT);
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  
  Serial.println("System Started. Waiting for readings...");
}

void loop() {
  ldr_state = digitalRead(ldr_pin);
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  
  duration = pulseIn(echo_pin, HIGH, 100000); 
  distance = duration * 0.034 / 2;

  
  // Distance Output
  if (duration == 0) {
    Serial.print("Distance: --- cm");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm");
  }

  Serial.print(", ");

  // Temperature & Humidity Output
  if (isnan(temperature) || isnan(humidity)) {
    Serial.print("Temp/Hum: Error (Check DHT)");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" C, Humidity: ");
    Serial.print(humidity);
    Serial.print(" %");
  }

  Serial.print(", ");

  // LDR Output
  // Since digitalRead is never NaN, we just check the state
  Serial.print("Brightness: ");
  if (ldr_state == 0) {
    Serial.println("Bright");
  } else {
    Serial.println("Dark");
  }

  delay(1000);
}