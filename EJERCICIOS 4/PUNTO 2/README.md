# PASO A PASO EJERCICIO II

En este ejercicio se implementan **tres tareas independientes**, cada una con una prioridad distinta, para evidenciar cómo el sistema operativo en tiempo real (RTOS) administra el uso del procesador según la prioridad asignada. Cada tarea realiza una acción específica:

- La de baja prioridad controla el parpadeo de un LED.
- La de prioridad media lee el valor de un potenciómetro y lo envía al puerto serie.
- La de alta prioridad detecta el estado de un pulsador y controla un LED indicador.

Gracias al uso del FreeRTOS, todas las tareas se ejecutan en paralelo, sin interferir entre sí, pero con atención preferente a las de mayor prioridad.

## Definición de variables: 

- LedBajo: pin digital donde se conecta el LED controlado por la tarea de baja prioridad.
- LedAlto: pin digital donde se conecta el LED de alta prioridad (indica estado del pulsador).
- Pot: pin analógico donde se conecta el potenciómetro.
- Puls: pin digital configurado como entrada con resistencia pull-up, para leer el estado del pulsador.
- ValorPot: variable entera que almacena el valor leído desde el potenciómetro.

Además, se declaran las tareas.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20120134.png) 

## Void setup: 

Se configuran los pines de entrada y salida, y se inicializa el puerto serie. Luego, se crean las tres tareas con diferentes prioridades mediante xTaskCreate():

- TaskBaja: prioridad 1.
- TaskMedia: prioridad 2.
- TaskAlta: prioridad 3.

Gracias al RTOS, las tareas se ejecutan en paralelo, priorizando las de mayor nivel.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20120152.png)

## Void TaskAlta, TaskMedia y TaskBaja

Cada tarea usa un bucle infinito for(;;) y vTaskDelay() para realizar sus acciones sin bloquear la CPU.

- TaskBaja: enciende y apaga el LED cada 1000 ms.
- TaskMedia: lee el potenciómetro y muestra su valor cada 500 ms.
- TaskAlta: verifica el estado del pulsador y enciende o apaga el LED cada 50 ms.

![Funciones](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%202/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20120212.png) 
