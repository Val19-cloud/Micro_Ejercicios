#include <Wire.h>
#include <Adafruit_AHTX0.h>
#include <LiquidCrystal_I2C.h>

Adafruit_AHTX0 aht;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  aht.begin();
  lcd.init();
  lcd.backlight();
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  float t = temp.temperature;
  float h = humidity.relative_humidity;

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" C, Hum: ");
  Serial.print(h);
  Serial.println(" %");

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(h, 1);
  lcd.print(" %");

  delay(2000);
}

