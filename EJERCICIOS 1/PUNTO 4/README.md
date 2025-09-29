# PASO A PASO EJERCICIO IV 

En este caso se construye un **contador binario** usando cuatro LEDs para representar valores desde 0 hasta 15.
Cada vez que se presiona un pulsador, el contador aumenta su valor en 1 y lo muestra en binario mediante los LEDs. Cuando llega al número 15, el siguiente pulso hace que el conteo regrese a 0.

## Definición de variables  

Se declara un arreglo de pines para los cuatro LEDs (ledPins), un pin para el pulsador (Pul), y dos variables de control:

- contador almacena el valor actual del conteo (de 0 a 15).
- botonPresionado evita que el conteo se incremente más de una vez por cada pulsación.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205438.png)

## Void Setup

En esta sección se permiten configurar los pines de los LEDs como salidas, asegurando que inicien apagados, y el pin del pulsador como entrada con resistencia pull-up interna, evitando lecturas falsas.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205458.png)

## Void loop

Se lee el estado del pulsador:

- Si se presiona (lectura en LOW), y el botón no estaba presionado antes, se incrementa el contador.
- Si el valor supera 15, se reinicia a 0.
- Cuando el pulsador se suelta, la variable botonPresionado se resetea, permitiendo volver a contar en la siguiente pulsación.

Luego, mediante un bucle for, se encienden los LEDs según los bits activos del número binario.
Esto se logra con una operación de máscara bit a bit (& y desplazamiento <<).

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205516.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205535.png)

## Link Tinkercad:

https://www.tinkercad.com/things/i6FDCfASRai-punto-4-micro