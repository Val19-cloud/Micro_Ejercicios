# Cola Mensajes  

Utiliza una ESP32 con FreeRTOS para leer, procesar y monitorear datos de temperatura y humedad obtenidos del sensor AHT20 (a través de la librería Adafruit_AHTX0).

## ¿Cómo funciona?

El programa está dividido en tres tareas concurrentes que se comunican mediante una cola de mensajes (xQueue):

TareaLectura

Lee periódicamente los valores de temperatura y humedad relativa desde el sensor AHT20.
Muestra los datos por el monitor serie.
Envía los datos leídos a la cola para que otra tarea los procese.

TareaProcesamiento

Recibe los datos de la cola.
Los muestra en el monitor serie con la etiqueta.
Compara la temperatura con un umbral definido de 28 °C.
Si la temperatura es mayor al umbral, enciende el LED en el pin 2.
Si no, apaga el LED.

TareaMonitoreo

Cada 3 segundos imprime en el monitor serie "Sistema funcionando".
