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

En esta parte se configura el pin del LED como salida y se inicializa el Timer1 en modo CTC. Este modo permite ejecutar una acción automática (una interrupción) cada vez que el temporizador alcanza un valor específico. Con esto, el Timer1 generará una interrupción cada 500 milisegundos.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20005907.png)

## Void loop

No posee ninguna tarea, acá se pueden ingresar otras tareas que se necesiten ejecutar.

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20005923.png)

## Link Tinkercad:

https://www.tinkercad.com/things/0FwQpfd3qt9-punto-3-micro-ii