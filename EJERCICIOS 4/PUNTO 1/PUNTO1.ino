#include <Arduino.h>

int Led1 = 2;
int Led2 = 4;

void TaskLed1(void *pvParameters);
void TaskLed2(void *pvParameters);

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

  xTaskCreate(TaskLed1, "Tarea LED1", 1024, NULL, 1, NULL);
  xTaskCreate(TaskLed2, "Tarea LED2", 1024, NULL, 1, NULL);
}

void loop() {}

void TaskLed1(void *pvParameters) {
  for (;;) {
    digitalWrite(Led1, HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(Led1, LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void TaskLed2(void *pvParameters) {
  for (;;) {
    digitalWrite(Led2, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(Led2, LOW);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
