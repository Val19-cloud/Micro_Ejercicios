# Proyecto: Multitarea con FreeRTOS en ESP32

Este proyecto muestra cómo usar FreeRTOS en un ESP32 para manejar varias tareas de manera concurrente y con diferentes prioridades.


## ¿Cómo funciona?
Ejecuta tres tareas en paralelo:
Tarea 1 (Prioridad 3): Lee un botón y enciende o apaga un LED según su estado.
Tarea 2 (Prioridad 2): Lee el valor de un potenciómetro y lo muestra en el monitor serial cada 500 ms.
Tarea 3 (Prioridad 1): Hace parpadear otro LED cada 1 segundo.

De esta manera, el ESP32 realiza varias funciones al mismo tiempo sin necesidad de usar el loop().

En setup(), se configuran los pines de entrada/salida y se crean las tres tareas con xTaskCreate().
FreeRTOS asigna a cada tarea una prioridad:
Cuanto mayor sea el número, mayor la prioridad de ejecución.
En este caso, la lectura del botón (Tarea 1) tiene la mayor prioridad para responder rápido a las pulsaciones.
Cada tarea corre en un bucle infinito (for(;;)) con retardos controlados por vTaskDelay().
Gracias a FreeRTOS, el ESP32 administra el tiempo de CPU y mantiene todas las tareas funcionando sin interferirse.

[Circuito](https://drive.google.com/file/d/1HnexQYSwWuHm3eofcrYXMbs0K7aOI1q-/view?usp=sharing)
