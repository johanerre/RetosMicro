# PASO A PASO EJERCICIO IV 

En este caso se construye un **contador binario** usando cuatro LEDs para representar valores desde 0 hasta 15.
Cada vez que se presiona un pulsador, el contador aumenta su valor en 1 y lo muestra en binario mediante los LEDs. Cuando llega al número 15, el siguiente pulso hace que el conteo regrese a 0.

## Definición de variables  

Se definen cuatro variables de tipo entero:

- Dos para los pines de los LEDs (Led1, Led2).
- Dos para los pulsadores (Pul1, Pul2).

Además, se declaran dos variables booleanas:

- Strover para controlar el estado general del sistema (encendido o apagado).
- Estled1 para alternar el encendido de los LEDs durante el parpadeo. 

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205438.png)

## Void Setup

Aquí se definen los pines de los LEDs como salidas y los pines de los pulsadores como entradas. De esta forma, el Arduino puede leer los estados de los botones y controlar el encendido y apagado de los LEDs.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205458.png)

## Void loop

Dentro del loop(), se leen los estados de los dos pulsadores:

- Si se presiona el primer pulsador (Pul1), se activa la variable Strover para iniciar el parpadeo.
- Si se presiona el segundo pulsador (Pul2), se desactiva el sistema (Strover = LOW) y se detiene el parpadeo.

Mientras Strover esté activo, se genera un parpadeo alternado entre los dos LEDs:

- Led1 se enciende mientras Led2 se apaga.
- Luego alternan sus estados.

Esto se repite con un pequeño retardo para dar el efecto de intermitencia. Dentro del bucle se mantiene la lectura de Pul2 para permitir detener el parpadeo en cualquier momento.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205516.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20205535.png)

## Link Tinkercad:

https://www.tinkercad.com/things/i6FDCfASRai-punto-4-micro