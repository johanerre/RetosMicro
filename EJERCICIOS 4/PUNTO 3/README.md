# PASO A PASO EJERCICIO III

En este ejercicio se emplea un **semáforo binario para controlar el acceso a un recurso compartido** (puerto Serial), evitando que dos tareas escriban al mismo tiempo y mezclen sus mensajes.

## Definición de variables: 

- xSemaphore: controla el acceso al recurso compartido.
- Task1 y Task2: tareas que intentan escribir al mismo tiempo. 

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20193014.png) 

## Void setup: 

Ambas tareas tienen la misma prioridad, así que el RTOS alternará entre ellas, pero solo una podrá escribir cuando obtenga el semáforo.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20193057.png)

## Void Task1 y Task2

Cada tarea:

- Espera hasta obtener el semáforo (xSemaphoreTake).
- Escribe su mensaje en el Serial.
- Libera el semáforo (xSemaphoreGive).

Espera un tiempo antes de volver a intentarlo.

![Funciones](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%203/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20193114.png) 
