# PASO BROKER

Se requiere **mostrar la temperatura obtenida de un sensor DS18B20** en un **display LCD I2C de 16x2**, empleando **tareas concurrentes con FreeRTOS**.  
El sistema debe realizar dos procesos principales:  
1. **Leer la temperatura del sensor** y enviarla por puerto serial hacia el ESP32.  
2. **Mostrar la temperatura y el tiempo de ejecución** en el LCD, de manera continua e independiente.

---

## Definición de librerías y variables  

Para este proyecto se incluyen las siguientes librerías:

- OneWire.h y DallasTemperature.h: permiten la comunicación con el sensor DS18B20 mediante el protocolo OneWire.  
- Wire.h y LiquidCrystal_I2C.h: necesarias para manejar la comunicación I2C con el LCD.  
- Arduino_FreeRTOS.h: permite crear y administrar tareas concurrentes dentro del microcontrolador.  

Además, se definen las variables:  
- PIN_DATOS: pin digital donde se conecta el sensor DS18B20.  
- temperatura: variable de tipo float que almacena la lectura actual de temperatura.  
- Objetos sensor y lcd para gestionar los periféricos.  

## Void setup  

En el bloque setup(), se inicializa la comunicación serial a 115200 baudios, se configuran los dispositivos y se crean las tareas que ejecutará FreeRTOS:  

- TaskLeerSensor: lee periódicamente el sensor y envía el valor por el puerto serial.  
- TaskMostrarLCD: actualiza el contenido del LCD mostrando la temperatura y el tiempo de ejecución.  

Estas tareas se ejecutan en paralelo, con diferente prioridad (la lectura del sensor tiene prioridad 2 y el LCD prioridad 1).  

## Void loop  

En este caso el loop() queda vacío, ya que FreeRTOS toma el control del flujo del programa y ejecuta las tareas definidas en el setup().  


## Tarea 1: Lectura del sensor  

La tarea TaskLeerSensor solicita una nueva lectura al sensor cada 2 segundos, obtiene la temperatura en °C y la envía por el puerto serial al ESP32.  

## Montaje

![Montaje](https://github.com/johanerre/RetosMicro/blob/main/PARCIAL/IMÁGENES/Captura%20de%20pantalla%202025-10-06%20200019.png)