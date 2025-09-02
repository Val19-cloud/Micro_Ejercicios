# SEMÁFORO

Este código simula un semáforo para autos y peatones usando LEDs y un botón:

## ¿Cómo funciona?

LEDs de autos: verde (pin 2), amarillo (pin 3) y rojo (pin 4).
LED peatonal: verde para peatones (pin 5).
Botón peatonal: conectado al pin 6.

Por defecto, el semáforo mantiene luz verde para autos.
Cuando alguien presiona el botón peatonal:
El semáforo pasa a amarillo por 2 segundos.
Luego cambia a rojo para autos y enciende el verde peatonal durante 5 segundos.
Finalmente, vuelve a verde para autos y el ciclo se repite.

## Simulación circuito

[Circuito en Tinkercad](https://www.tinkercad.com/things/ikIBXlJxkWc-secuencia?sharecode=sxwbo-oGbUQR_Kbi41kxEydu0S5Roo7pJCxgKK3dLVo)

## Imagen del circuito

![Circuito](MemoriaDeSecuencia.png)
