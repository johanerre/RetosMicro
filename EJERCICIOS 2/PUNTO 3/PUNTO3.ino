// Ejemplo: Timer1 en modo CTC, interrupción cada 500 ms
int led = 13;   // LED integrado en Arduino UNO

void setup() {
  pinMode(led, OUTPUT);

  noInterrupts();           // Deshabilita interrupciones globales

  TCCR1A = 0;               // Limpia registros de control
  TCCR1B = 0;

  // Modo CTC (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);

  // Prescaler = 256
  TCCR1B |= (1 << CS12);

  // Valor de comparación para 500 ms
  // Fórmula: OCR1A = (F_CPU / (Prescaler * Frecuencia)) - 1
  // F_CPU = 16 MHz, Prescaler = 256, Tiempo = 0.5 s → Frecuencia = 2 Hz
  // OCR1A = (16e6 / (256*2)) - 1 = 31249
  OCR1A = 31249;

  // Habilitar interrupción por comparación A
  TIMSK1 |= (1 << OCIE1A);

  interrupts();             // Habilita interrupciones globales
}

ISR(TIMER1_COMPA_vect) {
  // Se ejecuta cada 500 ms
  digitalWrite(led, !digitalRead(led));  // Invierte el estado del LED
}

void loop() {
}