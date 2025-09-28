PASO EJERCICIO I 

Se requiere de el **encendido de un led mediante el uso de un pulsador**, en este caso, debe encender cuando se presione y si **se vuelve a presionar debe apagarse**. 

## Definición de variables: 

Se definen dos variables de tipo entero, una para el led y otra para el pulsador. Luego dos de tipo booleano para los estados del pulsador. 

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20205309.png) 

## Void setup: 

En este caso se definen los pines de salida y de entrada del arduino, el led se define como salida y el pulsador como entrada, tener en cuenta que el pulsador debe estar conectado en Pull Up para el correcto funcionamiento de este código. 

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20212901.png) 

## Void loop: 

Para verificar la entrada del pulsador, se define una variable en el loop booleana para que lea el estado actual del pulsador, luego se imprime el valor de esta variable en el monitor serial para evidenciar en tiempo real si cambia su estado al presionarse. El ciclo if se activa con la condición de que el pulsador se encuentre en LOW, es decir cuando se deja de presionar y sí el último estado del mismo se encontraba en HIGH, en pocas palabras el ciclo se activa cuando se presiona una sola vez el pulsador. Se hace una igualación para cambiar el estado del led con la variable estadoLed, dependiendo si se encuentra encendido o apagado lo que hace es cambiar este estado. Finalmente fuera del ciclo lo que se hace es actualizar el último estado del pulsador igualando las variables de Uestado con PulEstado. 

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20212332.png) 

## Montaje
![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-06%20221143.png)

## Link Tinkercad:

https://www.tinkercad.com/things/8Uf0gC4On1T-punto-1-micro