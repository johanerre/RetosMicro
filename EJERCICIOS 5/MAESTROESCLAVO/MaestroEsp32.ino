#include <Wire.h>

void setup() {
  Wire.begin(); // Inicia como maestro
  Serial.begin(115200);
}

void loop() {
  Wire.beginTransmission(8); // Dirección del esclavo
  Wire.write('7'); // Dato a enviar
  Wire.endTransmission();
  Serial.println("Dato enviado al esclavo");
  delay(1000);
}
