# PASO A PASO EJERCICIO I

En este reto se realiza un **contador controlado por un pulsador**, usando una interrupción externa.
Cada vez que se presiona el pulsador, se aumenta el valor del contador y se muestra en el monitor serial.
Este método evita tener que preguntar constantemente si el pulsador fue presionado, ya que la interrupción se encarga de detectar el evento automáticamente.

## Definición de variables  

Se usa una variable para el botón y otra para llevar el conteo:

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20230850.png)

## Void Setup

Se configura el pin del pulsador como entrada y se inicia la comunicación serial para mostrar los valores del contador.

Luego se usa la función attachInterrupt() para vincular la interrupción con el pin del pulsador:

- digitalPinToInterrupt(Pul) indica que se usará el pin 2.
- ContadorPul es la función que se ejecutará cuando ocurra la interrupción.
- RISING significa que la interrupción se activa cuando la señal pasa de LOW a HIGH (cuando se presiona el botón).

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20230910.png)

## Void loop

En este caso está vacío, porque no se necesita revisar constantemente el botón. Todo se controla desde la interrupción.

## Void contadorPul

Cada vez que el botón es presionado, se ejecuta la función ContadorPul(). Dentro de esta función se incrementa el contador y se muestra el valor por el monitor serial:

![Función](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20230937.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%202/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20231001.png)

## Link Tinkercad:

https://www.tinkercad.com/things/dlR7Pc0wcBZ-punto-1-mircro-ii