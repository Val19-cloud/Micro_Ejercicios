#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

#define LED_PIN 2

typedef struct {
  float temperatura;
  float humedad;
} datosSensor_t;

QueueHandle_t colaDatos;

const float UMBRAL = 28.0;

void TareaLectura(void *pvParameters) {
  datosSensor_t datos;
  for (;;) {
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp);

    datos.temperatura = temp.temperature;
    datos.humedad = humidity.relative_humidity;

    Serial.print("Leído del sensor -> Temp: ");
    Serial.print(datos.temperatura);
    Serial.print(" °C, Humedad: ");
    Serial.print(datos.humedad);
    Serial.println(" %");

 
    xQueueSend(colaDatos, &datos, portMAX_DELAY);

    vTaskDelay(2000 / portTICK_PERIOD_MS); 
  }
}


void TareaProcesamiento(void *pvParameters) {
  datosSensor_t datosRecibidos;
  for (;;) {
    if (xQueueReceive(colaDatos, &datosRecibidos, portMAX_DELAY) == pdTRUE) {
      Serial.print("Procesando -> Temp: ");
      Serial.print(datosRecibidos.temperatura);
      Serial.print(" °C, Humedad: ");
      Serial.print(datosRecibidos.humedad);
      Serial.println(" %");

      if (datosRecibidos.temperatura > UMBRAL) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Temperatura alta - LED encendido");
      } else {
        digitalWrite(LED_PIN, LOW);
        Serial.println("Temperatura normal - LED apagado");
      }
    }
  }
}


void TareaMonitoreo(void *pvParameters) {
  for (;;) {
    Serial.println("Sistema funcionando");
    vTaskDelay(3000 / portTICK_PERIOD_MS); 
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); 

  if (!aht.begin()) {
    Serial.println("No se detecta el AHT20");
    while (1) delay(10);
  }
  Serial.println("AHT20 detectado correctamente!");

  pinMode(LED_PIN, OUTPUT);


  colaDatos = xQueueCreate(5, sizeof(datosSensor_t));

  if (colaDatos == NULL) {
    Serial.println("Error creando la cola");
    while (1);
  }


  xTaskCreatePinnedToCore(TareaLectura, "Lectura", 4096, NULL, 1, NULL, 0);        
  xTaskCreatePinnedToCore(TareaProcesamiento, "Procesamiento", 4096, NULL, 2, NULL, 1); 
  xTaskCreatePinnedToCore(TareaMonitoreo, "Monitoreo", 2048, NULL, 1, NULL, 0);   
}

void loop() {
 
}
