#include <avr/io.h>
#define F_CPU 1000000UL

int main() {
  DDRB |= (1 << 7);
  OCR0A = 24.6;
  TCCR0A = 0x83;
  TCCR0B = 0X04;
  while (1)
    ;
  return 0;
}