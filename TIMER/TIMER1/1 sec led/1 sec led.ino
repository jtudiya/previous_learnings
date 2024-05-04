#include <avr/io.h>

void Delay();

int main(void) {

  DDRA |= (1 << PA0);

  while (1) {
    PORTA ^= 0x01;
    Delay();
  }
  return 0;
}

void Delay() {
  TCNT1 = 49911;
  TCCR1A = 0x00;
  TCCR1B = 0X05;

  while ((TIFR1 & (1 << TOV1)) == 0)
    ;
  TCCR1B = 0;
   TIFR1 = 0x01;
}