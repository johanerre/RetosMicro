# PASO A PASO EJERCICIO IV

En este ejercicio se implementan **tres tareas independientes, que se comunican entre sí mediante una cola de mensajes**, demostrando cómo el sistema operativo en tiempo real (RTOS) permite el intercambio ordenado de información entre tareas.

- Tarea de lectura: mide la temperatura con un sensor DHT11.
- Tarea de procesamiento: recibe los datos de la cola, los muestra por Serial y controla un LED según el valor recibido.
- Tarea de monitoreo: opera en paralelo mostrando el mensaje “Sistema en funcionamiento...”.

## Definición de variables: 

- LedTemp: pin digital donde se conecta el LED indicador del nivel de temperatura.
- Temp: variable tipo float que almacena la lectura del sensor.
- Cola: cola de mensajes creada con xQueueCreate() para enviar los datos de temperatura entre tareas.
- DHTPIN: pin digital donde se conecta el sensor DHT11.
- DHTTYPE: define el tipo de sensor (DHT11).

Además, se declaran las tres tareas principales:

- TaskLectura
- TaskProceso
- TaskMonitoreo

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20194312.png) 

## Void setup: 

Se inicializan los periféricos y la cola de mensajes:

- Se configura el puerto Serial para mostrar información.
- Se inicializa el sensor DHT11 para obtener lecturas de temperatura.
- Se configura el pin del LED como salida digital.
- Se crea la cola, que almacenará los valores de temperatura enviados desde la tarea de lectura.

Posteriormente, se crean las tres tareas mediante xTaskCreate():

- TaskLectura: prioridad 2, mide la temperatura y envía los datos.
- TaskProceso: prioridad 1, recibe los datos y los procesa.
- TaskMonitoreo: prioridad 1, muestra el estado del sistema.

Gracias al RTOS, las tres tareas se ejecutan en paralelo, compartiendo datos mediante la cola sin interferencias.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20194319.png)

## Void TaskLectura, TaskProceso y TaskMonitoreo

Cada tarea utiliza un bucle infinito for(;;) y la función vTaskDelay() para ejecutar sus acciones periódicamente sin bloquear la CPU.

- TaskLectura: lee la temperatura del DHT11 cada 2 segundos y la envía a la cola.
- TaskProceso: recibe el valor desde la cola, lo muestra por Serial y enciende el LED si la temperatura supera los 30°C.
- TaskMonitoreo: imprime en el Serial el mensaje “Sistema en funcionamiento...” cada 3 segundos para indicar que el sistema opera correctamente.

![Funciones](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%204/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20194330.png) 
