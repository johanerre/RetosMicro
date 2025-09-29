#include <Wire.h>
#include <CurieIMU.h>

void setup() {
  Serial.begin(115200);
  if (!CurieIMU.begin()(0x77)) { // Dirección I2C del BMP280
    Serial.println("No se encontró la IMU GY-81");
    while (1);
  }
}

void loop() {
  Serial.print("Temperatura = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print("Presión = ");
  Serial.print(bmp.readPressure()/100.0F);
  Serial.println(" hPa");
  
  delay(2000);
}