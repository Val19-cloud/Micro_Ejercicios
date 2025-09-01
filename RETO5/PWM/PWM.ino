//ContolDeBrillo
int Led=9;
int Puls1=3;
int Puls2=5;
int brillo = 0;   
int incremento = 5; 

void setup() {
 pinMode(Led,OUTPUT);
 pinMode(Puls1,INPUT_PULLUP);
 pinMode(Puls2,INPUT_PULLUP);

}

void loop() {
  
  if (digitalRead(Puls1)==LOW) {
  if (brillo<255) {
  brillo= brillo + incremento;
  if (brillo>=255) brillo=255;
  analogWrite (Led,brillo);
  delay (30);
  }

  }
 
   if (digitalRead(Puls2)==LOW) {
  if (brillo>0) {
  brillo= brillo - incremento;
  analogWrite (Led,brillo);
  delay (30);
  }

  }
}
