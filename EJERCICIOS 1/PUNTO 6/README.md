# PASO A PASO EJERCICIO VI

En este reto se crea un **juego de memoria tipo “Simón Dice”**, donde el Arduino muestra una secuencia de luces con varios LEDs, y el usuario debe repetirla correctamente usando los botones. Cada vez que el jugador acierta la secuencia, esta se hace más larga. Si se equivoca, el juego reinicia desde el inicio.

## Definición de variables  

Se definen dos arreglos principales:

- Leds[]: almacena los pines donde están conectados los cuatro LEDs.
- Pul[]: guarda los pines de los pulsadores.

Otras variables de control:

- longitud: determina cuántos pasos tiene la secuencia actual.
- indice: lleva el control de cuántos pasos ha acertado el jugador.
- fallo: indica si el jugador se equivocó en algún momento.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%206/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20221626.png)

## Void Setup

Se inicializan todos los pines:

- Los LEDs como salidas,
- Los pulsadores como entradas con resistencia Pull-Up interna, lo cual permite detectar cuándo se presiona un botón (lectura LOW).

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%206/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20221639.png)

## Void loop

* ###  1. Mostrar la secuencia

Se encienden los LEDs uno por uno según la longitud actual. Se usa el operador %4 para repetir el orden en caso de que la secuencia sea más larga que 4. Cada LED se enciende y apaga con pequeños retardos para que el jugador pueda verla claramente.

* ### 2. Esperar la respuesta del jugador

Se inicializa fallo en false e indice en 0 para comenzar a evaluar desde el inicio. Luego se entra en un bucle que se mantiene activo mientras el jugador no haya fallado y no haya terminado la secuencia.

Cuando el jugador presiona un botón, el programa verifica si corresponde con el LED encendido en esa posición. Si acierta, el contador indice avanza; si se equivoca, fallo se vuelve TRUE.

* ### 3. Verificar resultado

- Si el jugador falló, el juego reinicia volviendo la longitud a 1.
- Si acertó, se aumenta la longitud de la secuencia para el siguiente nivel.

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%206/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20221712.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%201/PUNTO%206/IMÁGENES/Captura%20de%20pantalla%202025-09-28%20221726.png)

## Link Tinkercad:

https://www.tinkercad.com/things/hxS8i5dlJrW-punto-6-micro