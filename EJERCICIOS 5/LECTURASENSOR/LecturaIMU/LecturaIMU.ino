#include <Wire.h>
#include <CurieIMU.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C Pant(0x27, 16, 2); // Dirección I2C del LCD

float AccX, AccY, AccZ;
float TempIMU;

void setup() {
  Serial.begin(115200);
  Pant.init();
  Pant.backlight();

  if (!CurieIMU.begin()) {
    Serial.println("No se encontró la IMU GY-81");
    Pant.setCursor(0, 0);
    Pant.print("IMU no hallada");
    while (1);
  }

  CurieIMU.setAccelerometerRange(2);
  Serial.println("IMU inicializada correctamente");
}

void loop() {
  int ax = CurieIMU.readAccelerometer(X_AXIS);
  int ay = CurieIMU.readAccelerometer(Y_AXIS);
  int az = CurieIMU.readAccelerometer(Z_AXIS);

  AccX = (float)ax / 100.0;
  AccY = (float)ay / 100.0;
  AccZ = (float)az / 100.0;

  TempIMU = 25.0 + (AccX / 10.0); // Simulada

  Serial.print("AccX: "); Serial.print(AccX);
  Serial.print("  AccY: "); Serial.print(AccY);
  Serial.print("  AccZ: "); Serial.print(AccZ);
  Serial.print("  Temp: "); Serial.print(TempIMU);
  Serial.println(" C");

  Pant.setCursor(0, 0);
  Pant.print("X:");
  Pant.print(AccX, 1);
  Pant.print(" Y:");
  Pant.print(AccY, 1);

  Pant.setCursor(0, 1);
  Pant.print("Z:");
  Pant.print(AccZ, 1);
  Pant.print(" T:");
  Pant.print(TempIMU, 1);

  delay(1500);
}
