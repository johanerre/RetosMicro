# PASO A PASO EJERCICIO VII

En este reto se diseña un **semáforo para vehículos con paso peatonal**, controlado mediante un botón. El sistema inicia con la luz verde encendida. Cuando el peatón presiona el botón, el semáforo cambia de fase:

Se enciende la luz amarilla, luego la luz roja y, finalmente se activa el LED peatonal por unos segundos,
y después todo vuelve al estado inicial con luz verde encendida.

## Definición de variables  

Se declaran cuatro LEDs para representar las luces del semáforo y el cruce peatonal, además de un pulsador: 

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%207/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20223247.png)

## Void Setup

Se configuran todos los pines de los LEDs como salidas y el pulsador como entrada con Pull-Up interna, para poder detectar su pulsación sin usar resistencias externas. El semáforo inicia en verde (paso habilitado para vehículos). Además, se usa un while inicial para esperar a que el botón no esté presionado al comenzar.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%207/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20223359.png)

## Void loop

* ###  1. Paso amarillo (precaución)

Al detectar la pulsación, la luz verde se apaga y la amarilla se enciende por 2 segundos.

* ### 2. Paso rojo + peatonal

Luego se apaga la amarilla, y se enciende la roja y el LED peatonal. Esto representa que los vehículos deben detenerse y los peatones pueden cruzar. El tiempo de cruce es de 5 segundos.

* ### Volver a estado inicial

Después de los 5 segundos:

- Se apaga el LED peatonal y la luz roja,
- Se enciende nuevamente la verde.

Así, el semáforo vuelve a su funcionamiento normal. Para evitar que el botón quede presionado y repita la secuencia, se agrega un (while) hasta que se suelte:

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%207/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20223415.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%207/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20223432.png)

## Link Tinkercad:

https://www.tinkercad.com/things/cKF2bQUNHPv-punto-7-micro