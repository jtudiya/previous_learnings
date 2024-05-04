#include <avr/io.h>
#define F_CPU 8000000UL

int main() {
  DDRB |= (1 << 5);
  OCR1A = 48;
  TCCR1A = 0x81;
  TCCR1B = 0X03;
  while (1)
    ;
  return 0;
}