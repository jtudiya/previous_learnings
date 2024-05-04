#include <avr/io.h>
#define F_CPU 8000000UL

void Delay();

int main(void) {
  DDRB |= (1 << 0x01);

  while (1) {
    PORTB ^= (1 << 0x01);
    Delay();
  }
  return 0;
}

void Delay() {
  TCNT1 = 1;  //1 sec delay
  TCCR1B = 0X05;
  while ((TIFR1 & (1 << TOV1)) == 0)
    ;
  TCCR1B = 0;
  TIFR1 = 0X01;
}