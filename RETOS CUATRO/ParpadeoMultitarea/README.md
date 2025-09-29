# Parpadeo de LEDs con FreeRTOS en ESP32

Este proyecto muestra cómo usar FreeRTOS en un ESP32 para ejecutar dos tareas en paralelo que hacen parpadear dos LEDs a diferentes intervalos de tiempo.

## ¿Cómo funciona?

Cada LED parpadea de manera independiente:
LED1: enciende y apaga cada 500 ms.
LED2: enciende y apaga cada 1000 ms.
Gracias a FreeRTOS, ambas tareas funcionan al mismo tiempo sin que una interfiera con la otra.

Se crean dos tareas con la función xTaskCreate():
Tarea1 controla el parpadeo rápido (LED1).
Tarea2 controla el parpadeo más lento (LED2).
Cada tarea entra en un bucle infinito (for(;;)), encendiendo y apagando su LED con un retardo (vTaskDelay) que marca el ritmo del parpadeo.
El ESP32 ejecuta ambas tareas de manera concurrente, demostrando la capacidad multitarea de FreeRTOS.

## Video del circuito

[Circuito](https://drive.google.com/file/d/1mHZMzCxu7DJfGRsWKxNLUTlvqcNA2Xw7/view?usp=sharing)
