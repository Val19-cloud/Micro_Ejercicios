//Alternar Leds
int Led1 = 4;
int Led2 = 5;
int Puls1 = 6;
int Puls2 = 7;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Puls1, INPUT_PULLUP);
  pinMode(Puls2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(Puls1) == LOW) {
    while (true) {
      digitalWrite(Led1, HIGH);
      digitalWrite(Led2, LOW);
      delay(150);
      if (digitalRead(Puls2) == LOW) break;

     
      digitalWrite(Led1, LOW);
      digitalWrite(Led2, HIGH);
      delay(150);
       if (digitalRead(Puls2) == LOW) break;
    }
  }
}
