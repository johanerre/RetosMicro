const int LedR = 2;
const int LedA = 3;
const int LedV = 4;
const int LedP = 5;
const int Pul = 6;

void setup() {
  pinMode(LedR, OUTPUT);
  pinMode(LedA, OUTPUT);
  pinMode(LedV, OUTPUT);
  pinMode(LedP, OUTPUT);
  pinMode(Pul, INPUT_PULLUP);

  digitalWrite(LedR, LOW);
  digitalWrite(LedA, LOW);
  digitalWrite(LedP, LOW);
  digitalWrite(LedV, HIGH);

  while (digitalRead(Pul) == LOW);  
}

void loop() {
  if (digitalRead(Pul) == LOW) {
    digitalWrite(LedV, LOW);
    digitalWrite(LedA, HIGH);
    delay(2000);

    digitalWrite(LedA, LOW);
    digitalWrite(LedR, HIGH);
    digitalWrite(LedP, HIGH);
    delay(5000);

    digitalWrite(LedP, LOW);
    digitalWrite(LedR, LOW);
    digitalWrite(LedV, HIGH);

    while (digitalRead(Pul) == LOW);  
  }
}