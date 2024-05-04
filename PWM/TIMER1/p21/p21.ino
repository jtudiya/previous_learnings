#include <avr/io.h>
#define F_CPU 16000000UL

int main() {
  DDRB |= (1 << 5);
  OCR1A = 358;
  TCCR1A = 0x82;
  TCCR1B = 0X0A;
  while (1)
    ;
  return 0;
}