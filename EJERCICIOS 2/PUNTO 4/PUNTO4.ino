int contadorPulsos = 0; // Se incrementa en la ISR externa
int frecuencia = 0;

void setup() {
  Serial.begin(9600);

  // Interrupción externa en pin 2 (INT0)
  attachInterrupt(digitalPinToInterrupt(2), contarPulsos, RISING);

  // -------- Configurar Timer1 --------
  noInterrupts();           // Deshabilitar interrupciones globales
  TCCR1A = 0;               // Modo normal
  TCCR1B = 0;

  // (16 MHz / 1024 prescaler) = 15625 ticks por segundo
  OCR1A = 15624;            // Comparación para 1s
  TCCR1B |= (1 << WGM12);   // Modo CTC
  TCCR1B |= (1 << CS12) | (1 << CS10); // Prescaler 1024
  TIMSK1 |= (1 << OCIE1A);  // Habilitar interrupción por comparación
  interrupts();             // Habilitar interrupciones globales
}

void loop() {
}

// ISR externa: cuenta pulsos
void contarPulsos() {
  contadorPulsos++;
}

// ISR Timer1: cada 1 segundo
ISR(TIMER1_COMPA_vect) {
  frecuencia = contadorPulsos;  // Pulsos por segundo
  contadorPulsos = 0;           // Reiniciar contador
  Serial.print("Frecuencia: ");
  Serial.print(frecuencia);
  Serial.println(" Hz");
}

