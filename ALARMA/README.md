# Alarma

Este programa implementa un sistema de alarma con buzzer controlado mediante interrupciones externas y el Timer2 del Arduino.

## ¿Cómo funciona?

El buzzer está conectado al pin 8.
El pin 2 activa la alarma cuando recibe un pulso.
El pin 3 desactiva la alarma cuando recibe un pulso.
El Timer2 está configurado en modo CTC, generando una interrupción periódica.
Si la alarma está activada, dentro de la ISR (TIMER2_COMPA_vect) se cambia rápidamente el estado del buzzer (HIGH ↔ LOW), produciendo un tono intermitente.
Si la alarma está desactivada, el buzzer se apaga.
En el loop(), se imprime por el monitor serial el estado actual de la alarma (ACTIVADA o DESACTIVADA).

Cuando se pulsa el botón del pin 2, la alarma se activa y el buzzer comienza a sonar de manera intermitente.
Al presionar el botón del pin 3, la alarma se desactiva y el buzzer se apaga.

## Simulación del circuito

[Circuito en Tinkercad](https://www.tinkercad.com/things/dPLdTJek9qT-alarma?sharecode=8IRRb1e909Cjvqs64op19nm53ABotOdPE9CVL_suaO0)

## Imagen del circuito

![Circuito](Alarma.png)
