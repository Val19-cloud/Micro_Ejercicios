#include <Arduino.h>

SemaphoreHandle_t xMutex;

void tarea1(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      Serial.println("Tarea 1 escribiendo");
      Serial.println("Tarea 1 terminó de escribir.");
      Serial.println("---------------------------");
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void tarea2(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE) {
      Serial.println("Tarea 2 escribiendo");
      Serial.println("Tarea 2 terminó de escribir.");
      Serial.println("---------------------------");
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("=== Ejemplo de Mutex con ESP32 ===");

  xMutex = xSemaphoreCreateMutex();

  if (xMutex != NULL) {
    xTaskCreate(tarea1, "Tarea1", 4096, NULL, 1, NULL);
    xTaskCreate(tarea2, "Tarea2", 4096, NULL, 1, NULL);
  } else {
    Serial.println("Error al crear el mutex.");
  }
}

void loop() {

}
