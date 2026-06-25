#include "DHT.h"

#define dht_type DHT22
#define dht_pin D4

DHT dht(dht_pin, dht_type);
 float temperature, humidity;
void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
   
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000);
}
