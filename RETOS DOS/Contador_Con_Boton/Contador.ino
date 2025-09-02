volatile int contador = 0;  
int boton = 0;

void incrementar() {
  contador++; 
}

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);  
  attachInterrupt(digitalPinToInterrupt(2), incrementar, FALLING);  
 
}

void loop() {
  boton = contador;   
  Serial.println(boton);
  
}

