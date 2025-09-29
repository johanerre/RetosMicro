int Leds[4] = {7,8,9,10};
int Pul[4] = {3,4,5,6};
int longitud = 1;
int indice = 0;
bool fallo = false;

void setup() {
  for (int i=0; i<4; i++) {
    pinMode(Leds[i], OUTPUT);
    pinMode(Pul[i], INPUT_PULLUP);  
  }
}

void loop() {
  for (int i=0; i<longitud; i++) {
    digitalWrite(Leds[i%4], HIGH);
    delay(500);
    digitalWrite(Leds[i%4], LOW);
    delay(300);
  }

  fallo = false;
  indice = 0;

  while (indice < longitud && !fallo) {
    for (int i=0; i<4; i++) {
      if (digitalRead(Pul[i]) == LOW) {   
        while (digitalRead(Pul[i]) == LOW);  
        if (i == (indice%4)) {
          indice++;
        } else {
          fallo = true;
        }
      }
    }
  }

  if (fallo) {
    longitud = 1;
  } else {
    longitud++;
  }
  delay(500);
}

