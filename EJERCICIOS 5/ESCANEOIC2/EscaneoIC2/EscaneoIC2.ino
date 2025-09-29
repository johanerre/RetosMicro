#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Escaneando dispositivos I2C...");
}

void loop() {
  byte error, address;
  int dispositivos = 0;

  for(address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo I2C encontrado en 0x");
      Serial.println(address, HEX);
      dispositivos++;
    }
  }
  
  if (dispositivos == 0) {
    Serial.println("No se encontraron dispositivos.");
  }
  delay(5000);
}
