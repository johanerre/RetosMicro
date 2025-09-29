# PASO A PASO EJERCICIO V 

Se plantea el **control del brillo de un LED** utilizando dos pulsadores. Uno de ellos sirve para aumentar el brillo, mientras que el otro lo disminuye. El control se realiza mediante PWM, que permite variar la intensidad del LED de forma gradual.

## Definición de variables  

Se definen tres pines principales:

- Led donde está conectado el LED.
- Pul1 pulsador para aumentar el brillo.
- Pul2 pulsador para disminuir el brillo.

Además, dos variables de control:

- Brillo almacena el nivel actual del brillo (0 a 255).
- paso determina cuánto se incrementa o disminuye el brillo cada vez que se presiona un botón.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20214423.png)

## Void Setup

Se configuran los pines:

- El LED como salida.
- Los pulsadores como entradas con resistencia interna Pull-Up, esto permite que al presionar el botón la lectura cambie de HIGH a LOW.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20214503.png)

## Void loop

Aquí se revisa constantemente el estado de los dos pulsadores:

- Si se presiona Pul1, el valor de Brillo aumenta en cada pulsación.
- Si supera 255, se mantiene en ese máximo.
- Si se presiona Pul2, el valor de Brillo disminuye.
- Si baja de 0, se mantiene en ese mínimo.

Cada vez que se cambia el valor de Brillo, se actualiza con analogWrite(), que es la función encargada del PWM. El delay(200) evita lecturas repetidas cuando se mantiene el botón presionado.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20214638.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%205/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20214703.png)

## Link Tinkercad:

https://www.tinkercad.com/things/kbM0rcKEHyH-punto-5-micro