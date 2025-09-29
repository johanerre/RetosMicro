int Pul = 2;
int Count = 0;

void setup()
{
  pinMode(Pul, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Pul), ContadorPul, RISING);
}

void loop(){
}

void ContadorPul(){
  Count++;
  Serial.println(Count);
}