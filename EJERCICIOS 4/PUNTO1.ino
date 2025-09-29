int Leds[4] = {7, 8, 9, 10};
int Puls[4] = {3, 4, 5, 6};
int Longitud = 1;
int Indice = 0;
bool Fallo = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(Leds[i], OUTPUT);
    pinMode(Puls[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < Longitud; i++) {
    digitalWrite(Leds[i % 4], HIGH);
    delay(500);
    digitalWrite(Leds[i % 4], LOW);
    delay(300);
  }

  Fallo = false;
  Indice = 0;

  while (Indice < Longitud && !Fallo) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(Puls[i]) == LOW) {
        while (digitalRead(Puls[i]) == LOW);
        if (i == (Indice % 4)) {
          Indice++;
        } else {
          Fallo = true;
        }
      }
    }
  }

  if (Fallo) {
    Longitud = 1;
  } else {
    Longitud++;
  }

  delay(500);
}