# PASO A PASO EJERCICIO II

Se busca **manejar el brillo de un LED usando una señal PWM** y un pulsador conectado al pin 3 (INT1). Cada vez que se presione el pulsador, se cambia la dirección del ajuste del brillo. Si el LED estaba aumentando su intensidad, ahora comenzará a disminuir, y viceversa.

## Definición de variables  

Se definen las variables necesarias para el control del LED y del pulsador, así como el brillo y la dirección del cambio:

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20004348.png)

## Void Setup

En esta sección se configuran los pines del LED y del pulsador, y se habilita la interrupción externa sobre el pin donde está el pulsador. La línea attachInterrupt() activa una interrupción que ejecutará la función Dimmer cada vez que el pulsador detecte una señal descendente (FALLING).

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20004411.png)

## Void loop

En el bucle principal se realiza el cambio progresivo del brillo del LED. Si la dirección es HIGH, el brillo aumenta, y si es LOW, disminuye. Además, se controla que el brillo no sobrepase los límites (0 y 255).

## Void Dimmer

La función Dimmer() se activa automáticamente cada vez que se presiona el pulsador. Su función es cambiar la dirección del cambio del brillo, permitiendo que pase de aumentar a disminuir o viceversa.

![Función](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20004430.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20004451.png)

## Link Tinkercad:

https://www.tinkercad.com/things/fyb2YFmxVIZ-punto-2-micro-ii