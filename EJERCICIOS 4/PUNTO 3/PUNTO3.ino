#include <Arduino.h>

SemaphoreHandle_t Semaforo;

void TaskUno(void *pvParameters);
void TaskDos(void *pvParameters);

void setup() {
  Serial.begin(9600);

  Semaforo = xSemaphoreCreateBinary();
  xSemaphoreGive(Semaforo);

  xTaskCreate(TaskUno, "Tarea 1", 2048, NULL, 1, NULL);
  xTaskCreate(TaskDos, "Tarea 2", 2048, NULL, 1, NULL);
}

void loop() {}

void TaskUno(void *pvParameters) {
  for (;;) {
    if (xSemaphoreTake(Semaforo, portMAX_DELAY) == pdTRUE) {
      Serial.println("Escribiendo desde la Tarea 1");
      vTaskDelay(pdMS_TO_TICKS(500));
      xSemaphoreGive(Semaforo);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }
}

void TaskDos(void *pvParameters) {
  for (;;) {
    if (xSemaphoreTake(Semaforo, portMAX_DELAY) == pdTRUE) {
      Serial.println("Escribiendo desde la Tarea 2");
      vTaskDelay(pdMS_TO_TICKS(500));
      xSemaphoreGive(Semaforo);
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
  }
}