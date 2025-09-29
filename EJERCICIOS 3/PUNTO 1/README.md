# PASO A PASO EJERCICIO I

Este reto tiene como propósito **registrar cuántas veces se ha encendido el Arduino**, guardando esa información en una memoria que no se borra al apagar el sistema. Para ello se usa la EEPROM, que permite conservar datos aunque se desconecte la energía.

## Definición de variables  

Se incluye la librería EEPROM.h para acceder a la memoria interna.
Además, se declaran dos variables:

- Dir (dirección donde se guardará el valor),
- Count (contador de encendidos).

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20014822.png)

## Void Setup

Esta sección se ejecuta una sola vez al encender el sistema. Aquí se realiza la lógica principal del conteo persistente:

- Se inicia la comunicación serial.
- Se lee el valor actual desde la EEPROM.
- Se incrementa en 1 cada vez que se energiza.
- Se guarda nuevamente el nuevo valor en la misma dirección.
- Finalmente, se muestra el número total de encendidos.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%203/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20014838.png)

## Void loop

No se necesita para este caso.

## Montaje

No es necesario ninguna conexión más allá de la comunición del Arduino con el computador. Simplemente se abre el monitor serial y se presiona el botón de reinicio del Arduino o se desconecta y se conecta directamente.

## Link Tinkercad:

https://www.tinkercad.com/things/1tW1Q6GZgiB-punto-1-micro-iii