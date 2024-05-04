#include <avr/io.h>
#include <avr/interrupt.h>
int d = 0, n = 0, a = 0, s = 1;
int16_t i = 0;

void setup() {

  init();
  Serial.begin(115200);
  DDRB |= 0x0F;
  TCCR2A = 0x82;
  TCCR2B = 0x04;
  TIMSK2 = (1 << OCIE2A);
  TCNT2 = 0;
  OCR2A = 250;
}

void loop() {

  if (Serial.available()) {
    n = Serial.parseInt();
  }
  a = n * 1.1112;
  d = a - i;

  Serial.print(a);
  Serial.print("  ");
  Serial.print(i);
  Serial.print("  ");
  Serial.println(d);
  reset();

  if (d == 0) {
    TCCR2B&=~0x04;
  } else {
    TCCR2B|=0x04;
  }
}

ISR(TIMER2_COMPA_vect) {
  if (d > 0) {
    PORTB ^= (1 << PB2);
    i++;
  }

  if (d < 0) {
    PORTB ^= (1 << PB0);
    PORTB ^= (1 << PB2);
    i--;
  }
}


void reset() {
  if ((d == 0 && i == 200) || (d == 0 && i == -200)) {
    i = 0;
    d = 0;
    a = 0;
    n = 0;
  }
}