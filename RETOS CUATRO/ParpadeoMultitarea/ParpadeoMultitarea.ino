#include <Arduino.h>


#define LED1 2   
#define LED2 4   


void Tarea1(void *pvParameters);
void Tarea2(void *pvParameters);

void setup() {
 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); 


  xTaskCreate(
    Tarea1,           
    "Parpadeo500ms",  
    2048,             
    NULL,             
    1,                
    NULL              
  );

 
  xTaskCreate(
    Tarea2,
    "Parpadeo1000ms",
    2048,
    NULL,
    1,
    NULL
  );
}

void loop() {
  
}
void Tarea1(void *pvParameters) {
  (void) pvParameters;
  for(;;) {
    digitalWrite(LED1, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);  
    digitalWrite(LED1, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Tarea2(void *pvParameters) {
  (void) pvParameters;
  for(;;) {
    digitalWrite(LED2, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS); 
    digitalWrite(LED2, LOW);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

