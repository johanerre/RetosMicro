const int Led = 9;
const int Pul1 = 2;
const int Pul2 = 3;

int Brillo = 0;
int paso = 25;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(Pul1, INPUT_PULLUP);
  pinMode(Pul2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(Pul1) == LOW) {
    Brillo = Brillo + paso;
    if (Brillo > 255) Brillo = 255;
    delay(200);
  }

  if (digitalRead(Pul2) == LOW) {
    Brillo = Brillo - paso;
    if (Brillo < 0) Brillo = 0;
    delay(200);
  }

  analogWrite(Led, Brillo);
}