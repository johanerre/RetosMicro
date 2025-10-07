# PASO ArduinoEsclavo

Se requiere **leer la temperatura de un sensor DS18B20 (termocupla digital)** y mostrarla en un display LCD I2C de 16x2, utilizando tareas concurrentes con FreeRTOS.  

El programa ejecuta dos tareas simultáneamente:  
1. Leer la temperatura del sensor y enviarla por el puerto serial hacia un ESP32.  
2. Mostrar la temperatura y el tiempo de ejecución en el LCD en tiempo real.  

---

## Definición de librerías y variables  

Para el funcionamiento del sistema se incluyen las siguientes librerías:

- OneWire.h y DallasTemperature.h: permiten la comunicación con el sensor DS18B20 mediante el protocolo OneWire.  
- Wire.h y LiquidCrystal_I2C.h: permiten la comunicación con el LCD I2C.  
- Arduino_FreeRTOS.h: permite crear y manejar tareas concurrentes en el microcontrolador.  

Además, se definen las variables y objetos necesarios:  
- PIN_DATOS: pin de conexión del sensor DS18B20.  
- temperatura: variable tipo float para almacenar el valor de temperatura.  
- Objetos sensor y lcd para controlar los periféricos.  

## Void setup  

En la función setup() se inicializan los dispositivos, la comunicación serial y las tareas de FreeRTOS:  

- TaskLeerSensor: se encarga de leer el sensor y enviar los datos al puerto serial.  
- TaskMostrarLCD: se encarga de mostrar la información en el LCD.  

La prioridad de las tareas se define con 2 para la lectura del sensor y 1 para la pantalla LCD.  

## Void loop  

El loop() se deja vacío, ya que FreeRTOS gestiona la ejecución de las tareas de forma automática.  