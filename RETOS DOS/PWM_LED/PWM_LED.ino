int led = 9;                  
volatile int direccion = 1;  
int brillo = 0;               

unsigned long tiempoAnterior = 0;  
const long intervalo = 50;    

void cambiarDireccion() {
  direccion = -direccion;    
}

void setup() {
  pinMode(led, OUTPUT);
  pinMode(3, INPUT_PULLUP);  

  attachInterrupt(digitalPinToInterrupt(3), cambiarDireccion, FALLING);

  Serial.begin(9600);
}

void loop() {
  unsigned long ahora = millis();

  if (ahora - tiempoAnterior >= intervalo) {
    tiempoAnterior = ahora;

    brillo += direccion * 5;   

    if (brillo > 255) brillo = 255;
    if (brillo < 0)   brillo = 0;

    analogWrite(led, brillo);
    Serial.println(brillo);
  }
}

