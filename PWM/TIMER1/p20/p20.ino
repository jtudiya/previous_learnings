#include <avr/io.h>
#define F_CPU 4000000UL

int main() {
  DDRB |= (1 << 5);
  OCR1A = 460;
  TCCR1A = 0xC3;
  TCCR1B = 0X09;
  while (1)
    ;
  return 0;
}