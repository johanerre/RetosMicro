const int ledPins[4] = {8, 9, 10, 11};
const int Pul = 2;
int contador = 0;
bool botonPresionado = LOW;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  pinMode(Pul, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(Pul) == LOW && !botonPresionado) {
    botonPresionado = HIGH;
    contador++;
    if (contador > 15) {
      contador = 0;
    }
  }

  if (digitalRead(Pul) == HIGH && botonPresionado) {
    botonPresionado = LOW;
  }

  for (int i = 0; i < 4; i++) {
    if (contador & (1 << i)) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}