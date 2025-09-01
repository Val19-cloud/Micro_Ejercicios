//Numeros Binarios 
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int puls = 6;

int num = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(puls, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(puls) == LOW) {
    num++;
    if (num > 15) num = 0;
    NumBinario(num);
    delay(200);
  }
}

void NumBinario(int num) {
  digitalWrite(led1, num & 1);
  digitalWrite(led2, num & 2);
  digitalWrite(led3, num & 4);
  digitalWrite(led4, num & 8);
}