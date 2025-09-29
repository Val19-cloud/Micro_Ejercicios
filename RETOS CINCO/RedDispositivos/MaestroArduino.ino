#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!aht.begin()) {
    Serial.println("No se detecta AHT20");
    while (1);
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("UNO -> Temp: ");
  Serial.print(temp.temperature);
  Serial.print(" C, Hum: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  delay(4000); 
}

