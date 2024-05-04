#include <avr/io.h>
#define F_CPU 8000000UL

int main() {
  DDRB |= (1 << 5);
  OCR1A = 204;
  TCCR1A = 0x82;
  TCCR1B = 0X09;
  while (1)
    ;
  return 0;
}