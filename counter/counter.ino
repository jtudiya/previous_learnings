#include <avr/io.h>
#define F_CPU 16000000UL

int main() {

  DDRC = 0xFF;
  DDRD &= ~(1 << 7);
  TCCR0A = 0x00;
  TCCR0B = 0x06;
  TCNT0 = 0;

  while (1) {
    do {
      PORTC = TCNT0;
        if (PORTC==0x0a) {
      TCNT0=0x00;
      }
    }while ((TIFR0 & (1 << TOV0)) == 0);
      TIFR0 = 1 << TOV0;
  }
}