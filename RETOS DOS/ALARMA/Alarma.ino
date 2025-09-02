
volatile bool alarmaActiva = false;  
volatile bool buzzerEstado = false;  

void activarAlarma() {
  alarmaActiva = true;
}


void desactivarAlarma() {
  alarmaActiva = false;
  digitalWrite(8, LOW);   
}
ISR(TIMER2_COMPA_vect) {
  if (alarmaActiva) {
    buzzerEstado = !buzzerEstado;        
    digitalWrite(8, buzzerEstado);       
  } else {
    digitalWrite(8, LOW);                
}
}

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);   


  attachInterrupt(digitalPinToInterrupt(2), activarAlarma, RISING);    
  attachInterrupt(digitalPinToInterrupt(3), desactivarAlarma, RISING); 


  noInterrupts();
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;

  OCR2A = 124;                   
  TCCR2A |= (1 << WGM21);        
  TCCR2B |= (1 << CS22);         
  TIMSK2 |= (1 << OCIE2A);       
  interrupts();
}

void loop() {
 
  if (alarmaActiva) {
    Serial.println("Alarma ACTIVADA");
  } else {
    Serial.println("Alarma DESACTIVADA");
  }
}


