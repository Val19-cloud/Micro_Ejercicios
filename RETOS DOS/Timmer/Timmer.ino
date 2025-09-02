
int LEDpin = 13; 

void setup() {
  pinMode(LEDpin, OUTPUT);

 
  TCCR1A = 0;                  
  TCCR1B = 0;
  OCR1A = 7812;                
  TCCR1B |= (1 << WGM12);      
  TCCR1B |= (1 << CS12) | (1 << CS10); 
  TIMSK1 |= (1 << OCIE1A);     

  interrupts();                

void loop() {
  
}


ISR(TIMER1_COMPA_vect) {
  digitalWrite(LEDpin, !digitalRead(LEDpin));
}

