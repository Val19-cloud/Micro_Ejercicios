#include <Arduino.h>

#define LED1 2 
#define POT1 4 
#define Puls 12
#define LED2 5

void Tarea1(void *pvParameters);
void Tarea2(void *pvParameters);
void Tarea3(void *pvParameters);

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(Puls, INPUT_PULLUP);
  pinMode(LED2, OUTPUT);

  Serial.begin(115200);  // Inicializa el puerto Serial

  // Crear tareas con diferentes prioridades
  xTaskCreate(
    Tarea1,           
    "EncenderLed",  
    2048,             
    NULL,             
    3,                
    NULL              
  );

  xTaskCreate(
    Tarea2,
    "LeerPotenciometro500ms",
    2048,
    NULL,
    2,
    NULL
  );

  xTaskCreate(
    Tarea3,
    "Parpadeo1000ms",
    2048,
    NULL,
    1,
    NULL
  );
}

void loop() {
  // No se usa loop() porque las tareas están corriendo en FreeRTOS
}

void Tarea1(void *pvParameters) {
  (void) pvParameters;
  int BotonPulsado;  // Declaración de la variable
  for(;;) {
    BotonPulsado = digitalRead(Puls);
    if (BotonPulsado == LOW) {
       digitalWrite(LED2, HIGH);
    } else {
       digitalWrite(LED2, LOW);
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);
  }
}

void Tarea2(void *pvParameters) {
  (void) pvParameters;
  int valorPot = 0;

  for(;;) {
    valorPot = analogRead(POT1);    
    Serial.print("[Tarea 2] Valor del potenciómetro: ");
    Serial.println(valorPot);        
    vTaskDelay(500 / portTICK_PERIOD_MS); 
  }
}

void Tarea3(void *pvParameters) {
  (void) pvParameters;
  for(;;) {
    digitalWrite(LED1, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  
    digitalWrite(LED1, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

