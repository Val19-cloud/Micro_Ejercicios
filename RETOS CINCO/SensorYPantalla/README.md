# Sensor y Pantalla

Este código muestra cómo leer datos de temperatura y humedad relativa usando el sensor AHT20 y mostrarlos tanto en el monitor serie como en una pantalla LCD I2C (16x2) conectada a un ESP32.

## ¿Cómo funciona?

Comunicación I2C en los pines del ESP32 GPIO 21 (SDA) y GPIO 22 (SCL).
Se configura el sensor AHT20 mediante la librería Adafruit_AHTX0.
Se inicializa la pantalla LCD I2C con dirección 0x27 y tamaño 16x2.

En cada ciclo del loop(), se obtienen los valores de:
Temperatura (°C).
Humedad relativa (%).

Los datos se envían al monitor serie para depuración.
Los mismos datos se muestran en la pantalla LCD:
Línea 1: "Temp: XX.X°C".
Línea 2: "Hum: XX.X %".
