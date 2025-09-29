#include <Arduino.h>

int LedBajo = 2;
int LedAlto = 4;
int Pot = 34;
int Puls = 15;
int ValorPot = 0;

void TaskBaja(void *pvParameters);
void TaskMedia(void *pvParameters);
void TaskAlta(void *pvParameters);

void setup() {
  pinMode(LedBajo, OUTPUT);
  pinMode(LedAlto, OUTPUT);
  pinMode(Puls, INPUT_PULLUP);
  Serial.begin(9600);

  xTaskCreate(TaskBaja, "Tarea Baja", 2048, NULL, 1, NULL);   // Baja prioridad
  xTaskCreate(TaskMedia, "Tarea Media", 2048, NULL, 2, NULL); // Media prioridad
  xTaskCreate(TaskAlta, "Tarea Alta", 2048, NULL, 3, NULL);   // Alta prioridad
}

void loop() {}

void TaskBaja(void *pvParameters) {
  for (;;) {
    digitalWrite(LedBajo, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(LedBajo, LOW);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void TaskMedia(void *pvParameters) {
  for (;;) {
    ValorPot = analogRead(Pot);
    Serial.print("Valor Potenciometro: ");
    Serial.println(ValorPot);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void TaskAlta(void *pvParameters) {
  for (;;) {
    if (digitalRead(Puls) == LOW) {
      digitalWrite(LedAlto, HIGH);
    } else {
      digitalWrite(LedAlto, LOW);
    }
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}