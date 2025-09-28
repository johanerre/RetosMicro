const int Pul = 2;   
const int Led = 13;     
bool estadoLED = LOW;     

bool Uestado = HIGH; 

void setup() {
  pinMode(Pul, INPUT); 
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  bool Pulestado = digitalRead(Pul);
  Serial.println(Pulestado);
  

  if (Pulestado == LOW && Uestado == HIGH) {
    estadoLED = !estadoLED;

    digitalWrite(Led, estadoLED);

    //delay(50);
  }

  Uestado = Pulestado;
}