# PASO A PASO EJERCICIO II  

Se requiere el **encendido secuencial de 8 LEDs** mediante el uso de un pulsador. En este caso, los LEDs deben encenderse uno a uno en orden ascendente cuando el pulsador **no** está presionado (estado HIGH), y deben apagarse en orden descendente cuando el pulsador **se presione** (estado LOW).  

## Definición de variables  

Se define una variable entera para el pulsador, ubicada en el pin 2 del Arduino. Adicionalmente, se define un arreglo de 8 posiciones donde se almacenan los pines correspondientes a cada LED, desde el pin 3 hasta el 10.  

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20154021.png)

## Void Setup

En esta sección se inicializa la comunicación serial a 9600 baudios, para poder visualizar el estado del pulsador en el monitor serial. Luego se configura el pin del pulsador como entrada con resistencia Pull-Up interna, lo cual garantiza que por defecto su lectura sea HIGH y cambie a LOW al presionarlo. Cada pin correspondiente a los LEDs se define como salida digital, permitiendo controlar su encendido y apagado desde el programa. Debido a que los leds se definieron como un arreglo de 8 posiciones, se utiliza un ciclo for para poder definirlo.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20154105.png)

## Void loop

 Se realiza la lectura del estado actual del pulsador mediante la variable de tipo booleano Pulestado. El valor leído se envía al monitor serial para verificar en tiempo real si el pulsador se encuentra presionado o no. Posteriormente, se evalúa la condición mediante una estructura if-else:

- Si el pulsador está en HIGH (no presionado), se ejecuta un ciclo for que recorre el arreglo de forma ascendente, encendiendo cada LED uno a uno con una pequeña pausa de 50 ms entre cada encendido.
- Si el pulsador está en LOW (presionado), se ejecuta un ciclo for descendente que apaga cada LED de manera inversa, también con un retardo de 50 ms entre cada acción.

Este comportamiento genera un efecto visual secuencial, encendiendo o apagando los LEDs dependiendo del estado del pulsador.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20154141.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20161051.png)

## Link Tinkercad:

https://www.tinkercad.com/things/72RvbExvPTk-punto-2-micro