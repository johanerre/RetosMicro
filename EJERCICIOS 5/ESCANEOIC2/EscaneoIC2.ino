#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Escaneando dispositivos I2C...");
}

void loop() {
  byte Error, Dir;
  int Contador = 0;

  for (Dir = 1; Dir < 127; Dir++) {
    Wire.beginTransmission(Dir);
    Error = Wire.endTransmission();

    if (Error == 0) {
      Serial.print("Dispositivo I2C encontrado en 0x");
      Serial.println(Dir, HEX);
      Contador++;
    }
  }

  if (Contador == 0) {
    Serial.println("No se encontraron dispositivos I2C.");
  }

  delay(5000);
}
