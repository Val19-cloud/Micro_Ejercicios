#include <EEPROM.h>

int direccion = 0; 
unsigned int contador = 0;
void setup() {
 Serial.begin(9600);
 contador = EEPROM.read(direccion);
  contador++;
  EEPROM.write(direccion, contador);
  Serial.print("Numero de encendidos: ");
  Serial.println(contador);

}

void loop() {
  // put your main code here, to run repeatedly:

}
