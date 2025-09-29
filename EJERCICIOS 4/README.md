# PASO A PASO EJERCICIO I

En este caso, se implementan **dos tareas independientes, cada una encargada del parpadeo de un LED con diferentes intervalos de tiempo**, evidenciando que ambas se ejecutan en paralelo sin utilizar funciones de retardo como delay().

## Definición de variables: 

Se declaran dos variables de tipo entero llamadas Led1 y Led2, que almacenan los pines donde están conectados los LEDs utilizados para el parpadeo multitarea.

Además, se declaran las funciones TaskBlink1 y TaskBlink2, que representan las tareas encargadas de encender y apagar los LEDs en intervalos de 500 ms y 1000 ms, respectivamente.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20205309.png) 

## Void setup: 

En este caso se definen los pines de salida y de entrada del arduino, el LED se define como salida y el pulsador como entrada, tener en cuenta que el pulsador debe estar conectado en Pull Up para el correcto funcionamiento de este código. 

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20212901.png) 

## Void loop: 

Para verificar la entrada del pulsador, se define una variable en el loop booleana para que lea el estado actual del pulsador, luego se imprime el valor de esta variable en el monitor serial para evidenciar en tiempo real si cambia su estado al presionarse. El ciclo if se activa con la condición de que el pulsador se encuentre en LOW, es decir cuando se deja de presionar y sí el último estado del mismo se encontraba en HIGH, en pocas palabras el ciclo se activa cuando se presiona una sola vez el pulsador. Se hace una igualación para cambiar el estado del LED con la variable estadoLed, dependiendo si se encuentra encendido o apagado lo que hace es cambiar este estado. Finalmente fuera del ciclo lo que se hace es actualizar el último estado del pulsador igualando las variables de Uestado con PulEstado. 

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20212332.png) 

## Montaje
![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20221143.png)

## Link Tinkercad:

https://www.tinkercad.com/things/8Uf0gC4On1T-punto-1-micro