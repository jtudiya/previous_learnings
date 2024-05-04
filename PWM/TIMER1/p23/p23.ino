#include <avr/io.h>
#define F_CPU 4000000UL

int main() {
  DDRB |= (1 << 5);
  OCR1A = 89;
  TCCR1A = 0xC1;
  TCCR1B = 0X02;
  while (1)
    ;
  return 0;
}