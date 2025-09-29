# PASO A PASO EJERCICIO III  

En este reto se requiere simular una luz de emergencia, haciendo uso de dos LEDs de distinto color y dos pulsadores. Un pulsador se encarga de activar el parpadeo alterno entre los LEDs, mientras que el otro pulsador detiene el parpadeo cuando se desee.

## Definición de variables  

Se definen cuatro variables de tipo entero:

- Dos para los pines de los LEDs (Led1, Led2).
- Dos para los pulsadores (Pul1, Pul2).

Además, se declaran dos variables booleanas:

- Strover para controlar el estado general del sistema (encendido o apagado).
- Estled1 para alternar el encendido de los LEDs durante el parpadeo. 

![Variables]()

## Void Setup

En esta sección se inicializa la comunicación serial a 9600 baudios, para poder visualizar el estado del pulsador en el monitor serial. Luego se configura el pin del pulsador como entrada con resistencia Pull-Up interna, lo cual garantiza que por defecto su lectura sea HIGH y cambie a LOW al presionarlo. Cada pin correspondiente a los LEDs se define como salida digital, permitiendo controlar su encendido y apagado desde el programa. Debido a que los leds se definieron como un arreglo de 8 posiciones, se utiliza un ciclo for para poder definirlo.

![Setup]()

## Void loop

 Se realiza la lectura del estado actual del pulsador mediante la variable de tipo booleano Pulestado. El valor leído se envía al monitor serial para verificar en tiempo real si el pulsador se encuentra presionado o no. Posteriormente, se evalúa la condición mediante una estructura if-else:

- Si el pulsador está en HIGH (no presionado), se ejecuta un ciclo for que recorre el arreglo de forma ascendente, encendiendo cada LED uno a uno con una pequeña pausa de 50 ms entre cada encendido.

- Si el pulsador está en LOW (presionado), se ejecuta un ciclo for descendente que apaga cada LED de manera inversa, también con un retardo de 50 ms entre cada acción.

Este comportamiento genera un efecto visual secuencial, encendiendo o apagando los LEDs dependiendo del estado del pulsador.

![Loop]()

## Montaje

![Montaje]()

## Link Tinkercad:

https://www.tinkercad.com/things/ioEgons1RPe-punto-3-micro