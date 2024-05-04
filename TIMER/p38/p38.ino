#include <avr/io.h>
#define F_CPU 16000000UL

void T0Delay();

int main(void) {
  DDRA |= (1 << PA0);

  while (1) {
    PORTA ^= 0x01;
    T0Delay();
  }
  return 0;
}

void T0Delay() {
  TCNT0 = 209.125;
  TCCR0B = 0X05;
  while ((TIFR0 & (1 << TOV0)) == 0)
    ;
  TCCR0B = 0;
  TIFR0 = 0X01;
}