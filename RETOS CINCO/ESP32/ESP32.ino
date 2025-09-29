#include <Wire.h>
#include <string.h>  

void setup() {
  Wire.begin(); 
  Serial.begin(115200);
}

void loop() {
  const char mensaje[] = "9";
  Wire.beginTransmission(8); 
  Wire.write((const uint8_t*)mensaje, strlen(mensaje));  
  Wire.endTransmission();
  delay(1000);
}
