#include <avr/io.h>
#define F_CPU 4000000UL

int main() {
  DDRB |= (1 << 7);
  OCR0A = 50.2;
  TCCR0A = 0xC3;
  TCCR0B = 0X02;
  while (1)
    ;
  return 0;
}