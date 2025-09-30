## Sensor I²C (IMU GY-81) + Pantalla LCD I²C

Este ejercicio combina la **lectura de un sensor I²C (IMU GY-81) con la visualización en una pantalla LCD I²C**, mostrando cómo varios dispositivos pueden coexistir en el mismo bus.

## Funcionamiento

# Definición de Variables

- Wire.h: para la comunicación I²C.
- CurieIMU.h: librería para manejo de la IMU GY-81.
- CurieIMU.begin(0x77): inicializa el sensor en su dirección I²C (0x77).

# Void setup

- Se inicia la comunicación Serial (115200 baudios).
- Se inicializa la IMU y se verifica su detección.
- Si no se encuentra, se muestra un mensaje de error y se detiene el programa.

# Void loop

- Se realiza la lectura de temperatura mediante la función de la librería.
- Se imprimen los valores en el Monitor Serial cada 2 segundos.

![LCD](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%205/LECTURASENSOR/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20210502.png) 
![LCDI"C](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%205/LECTURASENSOR/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20210515.png) 