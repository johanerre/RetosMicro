const int Led1 = 9;
const int Led2 = 11;
const int Pul1 = 2;  
const int Pul2 = 3; 

bool Strover = LOW; 
bool Estled1 = LOW;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Pul1, INPUT); 
  pinMode(Pul2, INPUT);
}

void loop() {
  if (digitalRead(Pul1) == HIGH) { 
    Strover = HIGH;
    delay(200);
  }
  if (digitalRead(Pul2) == HIGH) { 
    Strover = LOW;
    delay(200);
  }

  while (Strover) {
    Estled1 = !Estled1;
    digitalWrite(Led1, Estled1);
    digitalWrite(Led2, !Estled1);
    for (int i = 0; i < 50; i++) {
      if (digitalRead(Pul2) == HIGH) {
        Strover = LOW;
        delay(200);
        break;
      }
      delay(10);
    }
  }
}