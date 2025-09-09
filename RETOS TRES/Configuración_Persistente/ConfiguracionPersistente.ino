#include <EEPROM.h>

int led = 8;
int opcion;         
int addr = 0;       

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  EEPROM.get(addr, opcion);

  
  if (opcion < 1 || opcion > 3) {
    opcion = 1;
    EEPROM.put(addr, opcion);
  }

  Serial.println("MENU CONFIGURACION:");
  Serial.println("1 = Lento (1s)");
  Serial.println("2 = Medio (0.5s)");
  Serial.println("3 = Rapido (0.2s)");
  Serial.print("Configuracion actual: ");
  Serial.println(opcion);
}

void loop() {

  if (Serial.available() > 0) {
    char dato = Serial.read();
    if (dato >= '1' && dato <= '3') {
      opcion = dato - '0';   
      EEPROM.put(addr, opcion);
      Serial.print("Guardado: ");
      Serial.println(opcion);
    }
  }


  if (opcion == 1) {
    digitalWrite(led, HIGH); delay(1000);
    digitalWrite(led, LOW);  delay(1000);
  }
  else if (opcion == 2) {
    digitalWrite(led, HIGH); delay(500);
    digitalWrite(led, LOW);  delay(500);
  }
  else if (opcion == 3) {
    digitalWrite(led, HIGH); delay(200);
    digitalWrite(led, LOW);  delay(200);
  }
}
