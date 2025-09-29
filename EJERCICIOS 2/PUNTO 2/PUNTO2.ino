int Pul = 3;
int Led = 7;

int Brillo = 0;
int Paso = 25;

bool Uestado = HIGH;
bool Dir = HIGH;

void setup()
{
  pinMode(Led, OUTPUT);
  pinMode(Pul, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Pul),Dimmer,FALLING);
}

void loop(){
  analogWrite(Led, Brillo);
  if(Dir){
    Brillo += Paso;
    if(Brillo >= 255){
      Brillo = 255;
      Dir = LOW;
    }
    else{
      Brillo -= Paso;
    }
    if(Brillo <= 0){
      Brillo = 0;
      Dir = HIGH;
    }
  }
}