#include <avr/io.h>
#define F_CPU 16000000UL

int main() {
  DDRB |= (1 << 7);
  OCR0A = 153;
  TCCR0A = 0x83;
  TCCR0B = 0X01;
  while (1)
    ;
  return 0;
}