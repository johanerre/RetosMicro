const int Pul = 2;
const int Led[8] = {3,4,5,6,7,8,9,10};

void setup() {
  Serial.begin(9600);
  pinMode(Pul, INPUT_PULLUP);
  pinMode(Led[8], OUTPUT);
  
}

void loop() {
  bool Pulestado = digitalRead(Pul); 
  Serial.println(Pulestado);

  if (Pulestado == HIGH) { 
    for (int i = 0; i < 8; i++) {
      digitalWrite(Led[i], HIGH);
      delay(50);
    }
  } else { 
    for (int i = 7; i >= 0; i--) {
      digitalWrite(Led[i], LOW);
      delay(50);
    }
  }
}