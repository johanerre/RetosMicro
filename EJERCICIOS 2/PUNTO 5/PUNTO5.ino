const int sensor = 2;      
const int detener = 3;     
const int buzzer = 9;      

bool alarmaActiva = false; 
int frecuencia = 100;      

void setup() {
  pinMode(sensor, INPUT);
  pinMode(detener, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(sensor), activarAlarma, RISING);
  attachInterrupt(digitalPinToInterrupt(detener), detenerAlarma, FALLING);

  configurarTimer2(frecuencia);
}

void loop() {
  if (alarmaActiva) {
    frecuencia += 10;
    if (frecuencia > 1000) frecuencia = 100;
    configurarTimer2(frecuencia);
    delay(50);
  }
}

void activarAlarma() {
  alarmaActiva = true;
  Serial.println("¡Alarma activada!");
}

void detenerAlarma() {
  alarmaActiva = false;
  Serial.println("Alarma detenida");
  digitalWrite(buzzer, LOW);
}

void configurarTimer2(int freq) {
  if(freq <= 0) return;

  noInterrupts();
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2  = 0;

  int prescaler = 64;
  long ocr = (16000000L / (prescaler * freq)) - 1;
  if (ocr > 255) ocr = 255;

  OCR2A = ocr;
  TCCR2A |= (1 << COM2A0) | (1 << WGM21) | (1 << WGM20);
  TCCR2B |= (1 << CS22);
  interrupts();
}