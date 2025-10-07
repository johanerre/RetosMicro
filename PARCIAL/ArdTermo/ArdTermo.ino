#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Arduino_FreeRTOS.h>

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Termocupla
#define PIN_DATOS 2

OneWire oneWireObjeto(PIN_DATOS);
DallasTemperature sensor(&oneWireObjeto);

float temperatura = 0.0;

// Prototipos
void TaskLeerSensor(void *pvParameters);
void TaskMostrarLCD(void *pvParameters);

void setup() {
  Serial.begin(115200); // Comunicación con ESP32

  sensor.begin();
  lcd.init();
  lcd.backlight();

  // Crear tareas
  xTaskCreate(TaskLeerSensor, "Sensor", 200, NULL, 2, NULL);
  xTaskCreate(TaskMostrarLCD, "LCD", 200, NULL, 1, NULL);
}

void loop() {
  // Vacío (todo lo maneja FreeRTOS)
}

// 🔹 Tarea 1: Leer sensor y enviar a ESP32
void TaskLeerSensor(void *pvParameters) {
  for (;;) {
    sensor.requestTemperatures();
    temperatura = sensor.getTempCByIndex(0);

    // Mostrar por serial para ESP32
    Serial.println(temperatura, 1);

    vTaskDelay(pdMS_TO_TICKS(2000));
  }
}

// 🔹 Tarea 2: Mostrar en LCD
void TaskMostrarLCD(void *pvParameters) {
  for (;;) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatura, 1);
    lcd.write(223);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Tiempo: ");
    lcd.print(millis() / 1000);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}


