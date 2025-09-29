# PASO A PASO EJERCICIO V

En este reto construiremos un **sistema de alarma inteligente** que combina:

- Un sensor o pulsador que activa la alarma (interrupción externa INT0).
- Un pulsador de apagado que detiene la alarma (interrupción externa INT1).
- Un buzzer que emite sonido con frecuencia variable, controlado mediante Timer2 (interrupción interna tipo PWM).

## Definición de variables  

- sensor: detecta movimiento o un evento (por ejemplo, un PIR o un pulsador).
- detener: pulsador para apagar la alarma.
- buzzer: salida PWM controlada por Timer2.
- alarmaActiva: estado de la alarma.
- frecuencia: valor de frecuencia del tono PWM.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20012837.png)

## Void Setup

Se configuran:

- Los pines de entrada y salida.
- Las interrupciones externas para los dos pulsadores.
- El Timer2 para generar la señal PWM que controla el buzzer.

- attachInterrupt(..., RISING) activa la alarma al detectar un flanco ascendente.
- attachInterrupt(..., FALLING) apaga la alarma cuando se pulsa el botón de detener.
- configurarTimer2(frecuencia) prepara el Timer2 para generar PWM a la frecuencia deseada.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20012855.png)

## Void loop

Mientras la alarma está activa, se puede variar la frecuencia del buzzer para crear un efecto de sirena.

- Este bloque incrementa poco a poco la frecuencia, y al llegar a 1000 Hz, vuelve a 100 Hz, generando un tono ascendente-descendente típico de sirena.
- Si la alarma no está activa, el buzzer queda apagado.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20012916.png)

## Void activarAlarma

Se ejecuta automáticamente al detectar una señal de movimiento o pulsación en el pin 2 (INT0).

## Void detenerAlarma

Se ejecuta al presionar el pulsador en el pin 3 (INT1).

## Void configurarTimer2

Esta función calcula y ajusta el valor del registro OCR2A para crear una señal PWM con la frecuencia deseada.

![Funciones](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20012936.png) 

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20012959.png)

## Link Tinkercad:

https://www.tinkercad.com/things/gXOFCvbBNJc-punto-5-micro-ii