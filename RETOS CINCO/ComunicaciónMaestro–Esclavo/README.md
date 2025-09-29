# Comunicación maestro - esclavo

Este código muestra cómo establecer comunicación I2C entre dos dispositivos.
Se programan dos roles: Maestro y Esclavo, que se comunican enviando y recibiendo mensajes de texto.

Código Maestro
Inicializa la interfaz I2C con Wire.begin().
Cada segundo envía el mensaje al dispositivo esclavo con dirección 8 (Wire.beginTransmission(8)).
Utiliza Wire.write() para transmitir los bytes del mensaje.
Cierra la transmisión con Wire.endTransmission().

 En resumen, el Maestro se encarga de enviar datos.

Código Esclavo
Inicializa la interfaz I2C en la dirección 8 (Wire.begin(8)).
Configura una función de interrupción (Wire.onReceive(recibirEvento)) que se ejecuta cada vez que llegan datos desde el maestro.
En la función recibirEvento():
Lee los bytes entrantes con Wire.read().
Los muestra en el monitor serie.
De esta forma, el esclavo recibe y muestra los mensajes enviados por el maestro.
Funcionamiento
El Maestro envía periódicamente el mensaje  por el bus I2C.
El Esclavo recibe ese mensaje gracias a la dirección asignada (8) y lo imprime por el monitor serie.
La comunicación se repite cada segundo.
