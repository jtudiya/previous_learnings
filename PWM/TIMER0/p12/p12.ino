#include <avr/io.h>
#define F_CPU 12000000UL

int main() {
  DDRB |= (1 << 7);
  OCR0A = 178.2;
  TCCR0A = 0xC3;
  TCCR0B = 0X01;
  while (1)
    ;
  return 0;
}