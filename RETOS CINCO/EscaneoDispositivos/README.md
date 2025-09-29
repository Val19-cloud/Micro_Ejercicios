# Escáner de dispositivos I²C con ESP32

Este código implementa un escáner I²C en el ESP32. Es una herramienta muy útil para identificar qué dispositivos I²C están conectados al bus y cuál es su dirección.

## ¿Cómo funciona?

Escanea todas las direcciones I²C posibles (del 1 al 127).
Intenta comunicarse con cada dirección:
Si hay respuesta, significa que un dispositivo está presente en esa dirección.
Si no hay respuesta, significa que la dirección está vacía.
Muestra en el monitor serial la lista de dispositivos encontrados.
Repite el escaneo cada 2 segundos.

El ESP32 inicia el bus I²C con Wire.begin(), usando los pines por defecto:
SDA → GPIO 21
SCL → GPIO 22
En el loop(), se recorre el rango de direcciones I²C (1 a 126).
Para cada dirección:
Se envía una transmisión vacía con Wire.beginTransmission(address).
Si Wire.endTransmission() devuelve 0, se detectó un dispositivo en esa dirección.
Si devuelve 4, significa que hubo un error desconocido.
Al final del barrido, muestra si se encontraron dispositivos o no.
Espera 2 segundos y repite.
