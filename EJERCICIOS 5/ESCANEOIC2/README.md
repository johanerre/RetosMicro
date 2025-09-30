## Escaneo de Dispositivos I²C

En este ejercicio se implementa un **programa que detecta automáticamente los dispositivos conectados al bus I²C**. El microcontrolador realiza una transmisión a todas las direcciones posibles (de 1 a 127) y muestra por Serial aquellas que responden correctamente.

# Funcionamiento

- Se utiliza la librería Wire.h para la comunicación I²C.
- El programa recorre todas las direcciones con Wire.beginTransmission() y Wire.endTransmission().
- Imprime las direcciones encontradas en formato hexadecimal.
- Permite identificar sensores o pantallas conectados al bus I²C antes de su uso.

![Escaneo](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%205/ESCANEOIC2/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20210017.png) 