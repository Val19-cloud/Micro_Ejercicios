
volatile unsigned int contadorPulsos = 0; 
unsigned int frecuencia = 0;              


void contarPulsos() {
  contadorPulsos++;
}


ISR(TIMER1_COMPA_vect) {
  frecuencia = contadorPulsos;  
  contadorPulsos = 0;           
}

void setup() {
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(2), contarPulsos, RISING);
  
 
  noInterrupts();           
  TCCR1A = 0;               
  TCCR1B = 0;
  TCNT1 = 0;                
  OCR1A = 15624;            
  TCCR1B |= (1 << WGM12);   
  TCCR1B |= (1 << CS12) | (1 << CS10); 
  TIMSK1 |= (1 << OCIE1A); 
  interrupts();             
}

void loop() {
  
  Serial.print("Frecuencia: ");
  Serial.print(frecuencia);
  Serial.println(" Hz");

  
}
