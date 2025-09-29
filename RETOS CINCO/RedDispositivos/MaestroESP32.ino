#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  if (!aht.begin()) {
    Serial.println("No se detecta AHT20");
    while (1);
  }
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("ESP32 -> Temp: ");
  Serial.print(temp.temperature);
  Serial.print(" C, Hum: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  delay(6000); // pide cada 6s
}
