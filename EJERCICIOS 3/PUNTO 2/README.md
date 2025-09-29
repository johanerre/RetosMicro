# PASO A PASO EJERCICIO II

Diseñar un **sistema de configuración que permita seleccionar un modo de funcionamiento mediante el monitor serial y guardar la selección en la memoria EEPROM**, para que al reiniciar el Arduino se mantenga la misma configuración sin necesidad de volver a elegir.

## Definición de variables  

- led → almacena el número de pin al que está conectado el LED.
- dir → dirección en la EEPROM donde se guardará el valor de configuración.
- config → variable que almacenará la opción seleccionada (1, 2 o 3).

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20020419.png)

## Void Setup

Se configuran:

- Inicia comunicación serial a 9600 bps.
- Configura el pin del LED como salida.
- Lee desde la EEPROM el valor guardado en la dirección dir.
- Si el valor no está entre 1 y 3, muestra un menú de opciones por el monitor serial.
- Espera la entrada del usuario (Serial.parseInt()) y guarda la selección en EEPROM.
- Muestra en pantalla la configuración cargada.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20020435.png)

## Void loop

Según el valor de config, define el tiempo de encendido y apagado del LED:

- 1 -> 1000 ms (lento)
- 2 -> 500 ms (medio)
- 3 -> 100 ms (rápido)

Realiza el parpadeo correspondiente con digitalWrite() y delay().

![Loop](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20020454.png)

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20020526.png)

## Link Tinkercad:

https://www.tinkercad.com/things/fn9EeXIviDp-punto-2-micro-iii