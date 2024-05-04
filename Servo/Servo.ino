#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {

  DDRB |= (1 << 5);
  TCCR1A = 0x82;
  TCCR1B = 0x1c;
  ICR1 = 1249;

  while (1) {

    OCR1A = 63;
    _delay_ms(1000);
    OCR1A = 94;
    _delay_ms(1000);
    OCR1A = 125;
    _delay_ms(1000);
    OCR1A = 63;
    _delay_ms(1000);
  }
}