//8 LEDS
int Leds[] = {2, 3, 4, 5, 6, 7, 8, 9};
int numLeds = 8;
int Puls = 10;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(Leds[i], OUTPUT);
  }
  pinMode(Puls, INPUT_PULLUP);
}

void loop() {
  int i = 0;
  while (digitalRead(Puls) == LOW) {
    digitalWrite(Leds[i], HIGH);
    delay(500);
    i++;
    if (i >= numLeds) {
      i = numLeds; 
      break;
    }
  }
  if (i == numLeds) {
    while (digitalRead(Puls) == LOW) {
     
    }
  }

  for (int j = i - 1; j >= 0; j--) {
    digitalWrite(Leds[j], LOW);
    delay(500);
  }
}
