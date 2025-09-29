# RED DE DISPOSITIVOS

Este código demuestra cómo leer datos de temperatura y humedad relativa del sensor AHT20 utilizando dos plataformas distintas: Arduino UNO y ESP32.

Código para Arduino UNO
Inicializa la comunicación I2C con Wire.begin().
Configura la comunicación serie a 9600 baudios.
Verifica si el sensor AHT20 está conectado.
En el loop():
Lee temperatura y humedad.
Imprime en el monitor serie con la etiqueta "UNO".
Espera 4 segundos antes de la siguiente lectura.

Código para ESP32
Inicializa la comunicación I2C en los pines GPIO 21 (SDA) y GPIO 22 (SCL) con Wire.begin(21, 22).
Configura la comunicación serie a 115200 baudios.
Verifica si el sensor AHT20 está disponible.
En el loop():
Lee los datos de temperatura y humedad.
Los imprime en el monitor serie con la etiqueta "ESP32 ->".
Espera 6 segundos antes de la siguiente lectura.

Sensor utilizado
AHT20: sensor de temperatura y humedad con comunicación I2C.
Librería: Adafruit_AHTX0.
Resumen
Ambos ejemplos cumplen la misma función: leer y mostrar temperatura y humedad desde el AHT20.
La diferencia está en:
Configuración de I2C (automática en Arduino UNO, manual en ESP32).
Velocidad de comunicación serie (9600 vs 115200).
