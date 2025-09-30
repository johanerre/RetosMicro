#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

QueueHandle_t Cola;

int LedTemp = 2;
float Temp = 0.0;

void TaskLectura(void *pvParameters);
void TaskProceso(void *pvParameters);
void TaskMonitoreo(void *pvParameters);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LedTemp, OUTPUT);

  Cola = xQueueCreate(5, sizeof(float));

  xTaskCreate(TaskLectura, "Lectura", 2048, NULL, 2, NULL);
  xTaskCreate(TaskProceso, "Proceso", 2048, NULL, 1, NULL);
  xTaskCreate(TaskMonitoreo, "Monitoreo", 2048, NULL, 1, NULL);
}

void loop() {}

void TaskLectura(void *pvParameters) {
  for (;;) {
    Temp = dht.readTemperature();
    xQueueSend(Cola, &Temp, portMAX_DELAY);
    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

void TaskProceso(void *pvParameters) {
  float ValorTemp;
  for (;;) {
    if (xQueueReceive(Cola, &ValorTemp, portMAX_DELAY) == pdTRUE) {
      Serial.print("Temperatura: ");
      Serial.println(ValorTemp);
      if (ValorTemp > 30.0) {
        digitalWrite(LedTemp, HIGH);
      } else {
        digitalWrite(LedTemp, LOW);
      }
    }
  }
}

void TaskMonitoreo(void *pvParameters) {
  for (;;) {
    Serial.println("Sistema en funcionamiento...");
    vTaskDelay(pdMS_TO_TICKS(3000));
  }
}