# PASO A PASO EJERCICIO I

En este caso, se implementan **dos tareas independientes, cada una encargada del parpadeo de un LED con diferentes intervalos de tiempo**, evidenciando que ambas se ejecutan en paralelo sin utilizar funciones de retardo como delay(). (Código para ESP32).

## Definición de variables: 

Se declaran dos variables de tipo entero llamadas Led1 y Led2, que almacenan los pines donde están conectados los LEDs utilizados para el parpadeo multitarea.

Además, se declaran las funciones TaskBlink1 y TaskBlink2, que representan las tareas encargadas de encender y apagar los LEDs en intervalos de 500 ms y 1000 ms, respectivamente.

![Variables](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20114710.png) 

## Void setup: 

Se realiza la configuración inicial del sistema. Primero se establecen los pines Led1 y Led2 como salidas mediante la instrucción pinMode(). Posteriormente, se crean las dos tareas principales utilizando la función xTaskCreate().

Cada tarea contiene la siguiente estructura de parámetros:

- El primer parámetro indica la función asociada a la tarea.
- El segundo es el nombre de la tarea.
- El tercero es el tamaño asignado a la pila (en bytes).
- El cuarto representa los parámetros que recibe la tarea (en este caso, ninguno).
- El quinto es la prioridad de ejecución.
- El último es un puntero al manejador de la tarea (aquí no se utiliza, por eso es NULL).

Gracias al uso del RTOS, ambas tareas se ejecutan de forma paralela, sin bloquear la ejecución del programa principal.

![Setup](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20114730.png) 
timo estado del pulsador igualando las variables de Uestado con PulEstado. 

## Void TaskLed1 y TaskLed2
Cada tarea es una función que se ejecuta de forma cíclica e infinita gracias al bucle for(;;).
Estas funciones utilizan vTaskDelay() para establecer los tiempos de espera entre el encendido y apagado del LED sin bloquear la CPU.

- TaskLed1: controla el parpadeo del Led1 cada 500 ms.
- TaskLed2: controla el parpadeo del Led2 cada 1000 ms.

La función vTaskDelay(pdMS_TO_TICKS(x)) convierte el valor en milisegundos a “ticks” del sistema operativo, garantizando una temporización precisa.

![Funciones](https://github.com/johanerre/RetosMicro/blob/main/EJERCICIOS%204/PUNTO%201/IMÁGENES/Captura%20de%20pantalla%202025-09-29%20114748.png) 