# PASO A PASO EJERCICIO IV

Se propone **medir la frecuencia de una señal externa utilizando dos interrupciones**:

- Una interrupción externa para contar los pulsos generados por un sensor o pulsador.
- Una interrupción interna (Timer1) que se activa cada segundo para calcular la frecuencia.

El sistema mostrará en el Monitor Serial cuántos pulsos ocurrieron en un segundo, es decir, la frecuencia en Hz.

## Definición de variables  

- contadorPulsos: aumenta en cada interrupción externa.
- frecuencia: almacena el resultado de cuántos pulsos ocurrieron en un segundo.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20005838.png)

## Void Setup

- El puerto serial para visualizar los datos.
- La interrupción externa en el pin 2.
- El Timer1 en modo CTC para generar una interrupción cada 1 segundo.

Cada segundo el Timer1 genera una interrupción que ejecuta la rutina ISR(TIMER1_COMPA_vect).

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20011227.png)

## Void contarPulsos

Cada vez que el sensor o pulsador genera un pulso en el pin 2, se ejecuta la función contarPulsos(). Allí simplemente se incrementa el contador.
Esta rutina se ejecuta automáticamente cada 1 segundo. Dentro de ella se calcula la frecuencia y se reinicia el contador para comenzar un nuevo conteo.

![Función](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20011333.png) 

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20011348.png)

## Link Tinkercad:

https://www.tinkercad.com/things/cqR6krpB1lI-punto-4-micro-ii