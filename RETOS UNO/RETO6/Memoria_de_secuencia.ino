int leds[4] = {2, 3, 4, 5};       
int botones[4] = {6, 7, 8, 9};    
int secuencia[20];                
int nivel = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botones[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 20; i++) {
    secuencia[i] = i % 4;   
  }
}

void loop() {
  for (int i = 0; i <= nivel; i++) {
    digitalWrite(leds[secuencia[i]], HIGH);
    delay(400);
    digitalWrite(leds[secuencia[i]], LOW);
    delay(200);
  }

  for (int i = 0; i <= nivel; i++) {
    int boton = esperarBoton();
    if (boton != secuencia[i]) {
      nivel = 0; 
      return;
    }
  }

  nivel++;
  delay(800);
}

int esperarBoton() {
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(botones[i]) == LOW) {
        digitalWrite(leds[i], HIGH);
        delay(300);
        digitalWrite(leds[i], LOW);
        delay(200);
        return i;
      }
    }
  }
}
