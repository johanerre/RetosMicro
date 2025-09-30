## Comunicación Maestro – Esclavo I²C

Se desarrollan **dos programas independientes, uno actuando como maestro y otro como esclavo**, para demostrar cómo un dispositivo puede enviar y recibir información a través del protocolo I²C.

# Funcionamiento

- El maestro inicia la comunicación con Wire.beginTransmission() y envía un dato (en este caso '7').

![Maestro](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%205/MAESTROESCLAVO/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20210228.png) 

- El esclavo, configurado con la dirección 8, utiliza Wire.onReceive() para recibir el dato y mostrarlo en el Monitor Serial.
- Ejemplo práctico de comunicación bidireccional entre dos microcontroladores mediante I²C.

![Esclavo](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%205/MAESTROESCLAVO/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20210323.png) 