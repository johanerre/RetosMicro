# PASO A PASO EJERCICIO III

Se busca realizar el **parpadeo de un LED usando un temporizador interno (Timer1) en lugar de usar delay()**. El objetivo es que el LED cambie su estado cada 500 milisegundos, pero sin detener el programa, aprovechando las interrupciones del temporizador para un control más preciso del tiempo.

## Definición de variables  

Se define una sola variable para el LED que se utilizará en el ejemplo, en este caso se añade una conexión pero también se trabaja con el LED integrado que contiene el Arduino:

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