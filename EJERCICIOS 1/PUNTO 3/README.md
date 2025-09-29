# PASO A PASO EJERCICIO III  

En este reto se requiere simular una luz de emergencia, haciendo uso de dos LEDs de distinto color y dos pulsadores. Un pulsador se encarga de activar el parpadeo alterno entre los LEDs, mientras que el otro pulsador detiene el parpadeo cuando se desee.

## Definición de variables  

Se definen cuatro variables de tipo entero:

- Dos para los pines de los LEDs (Led1, Led2).
- Dos para los pulsadores (Pul1, Pul2).

Además, se declaran dos variables booleanas:

- Strover para controlar el estado general del sistema (encendido o apagado).
- Estled1 para alternar el encendido de los LEDs durante el parpadeo. 

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20202818.png)

## Void Setup

Aquí se definen los pines de los LEDs como salidas y los pines de los pulsadores como entradas. De esta forma, el Arduino puede leer los estados de los botones y controlar el encendido y apagado de los LEDs.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20203028.png)

## Void loop

Dentro del loop(), se leen los estados de los dos pulsadores:

- Si se presiona el primer pulsador (Pul1), se activa la variable Strover para iniciar el parpadeo.
- Si se presiona el segundo pulsador (Pul2), se desactiva el sistema (Strover = LOW) y se detiene el parpadeo.

Mientras Strover esté activo, se genera un parpadeo alternado entre los dos LEDs:

- Led1 se enciende mientras Led2 se apaga.
- Luego alternan sus estados.

Esto se repite con un pequeño retardo para dar el efecto de intermitencia. Dentro del bucle se mantiene la lectura de Pul2 para permitir detener el parpadeo en cualquier momento.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20203050.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20203108.png)

## Link Tinkercad:

https://www.tinkercad.com/things/ioEgons1RPe-punto-3-micro