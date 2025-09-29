#include <EEPROM.h>

int led = 12;
int dir = 0;
int config;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  EEPROM.get(dir, config);

  if (config < 1 || config > 3) {
    Serial.println("MENU DE CONFIGURACION");
    Serial.println("1. Parpadeo lento");
    Serial.println("2. Parpadeo medio");
    Serial.println("3. Parpadeo rapido");
    Serial.println("Ingrese una opcion:");
    while (Serial.available() == 0);
    config = Serial.parseInt();
    if (config >= 1 && config <= 3) EEPROM.put(dir, config);
  }

  Serial.print("Configuracion cargada: ");
  Serial.println(config);
}

void loop() {
  int tiempo;
  switch (config) {
    case 1: tiempo = 1000; break;
    case 2: tiempo = 500; break;
    case 3: tiempo = 100; break;
    default: tiempo = 500; break;
  }
  digitalWrite(led, HIGH);
  delay(tiempo);
  digitalWrite(led, LOW);
  delay(tiempo);
}
