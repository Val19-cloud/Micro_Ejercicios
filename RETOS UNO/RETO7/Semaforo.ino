int ledVerde = 2;
int ledAmarillo = 3;
int ledRojo = 4;
int ledPeaton = 5;
int boton = 6;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledPeaton, OUTPUT);
  pinMode(boton, INPUT_PULLUP); 
}
void loop() {
 
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledPeaton, LOW);

  if (digitalRead(boton) == LOW) {
    // Cambia a amarillo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    delay(2000);

    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledPeaton, HIGH);
    delay(5000);

    digitalWrite(ledRojo, LOW);
    digitalWrite(ledPeaton, LOW);
    digitalWrite(ledVerde, HIGH);
  }
}

