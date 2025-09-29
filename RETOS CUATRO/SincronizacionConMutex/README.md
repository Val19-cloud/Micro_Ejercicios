# Ejemplo de Mutex con FreeRTOS en ESP32

Este proyecto muestra cómo usar un mutex (exclusión mutua) en un ESP32 con FreeRTOS para evitar que dos tareas escriban al mismo tiempo en el puerto serial.

## ¿Cómo funciona?

Crea dos tareas (tarea1 y tarea2).
Ambas intentan escribir mensajes en el monitor serial.
Antes de escribir, cada tarea solicita el mutex:
Si lo obtiene, escribe su bloque de mensajes.
Cuando termina, libera el mutex para que la otra tarea pueda usarlo.
Así se asegura que los mensajes no se mezclen en el monitor serial.

En setup(), se inicializa el puerto serial y se crea un mutex con xSemaphoreCreateMutex().
Si el mutex se creó correctamente, se lanzan las dos tareas.
Cada tarea entra en un bucle infinito (while(1)):
Pide acceso exclusivo con xSemaphoreTake().
Escribe un conjunto de mensajes en el serial.
Devuelve el mutex con xSemaphoreGive().
Espera 1 segundo (vTaskDelay) antes de intentarlo otra vez.
El resultado es que el monitor serial muestra mensajes ordenados y completos de cada tarea, sin interferencias.

[Circuito](https://drive.google.com/file/d/12ilC1em8ZfRL8N_Cr65opnRGAAp1STww/view?usp=sharing)
