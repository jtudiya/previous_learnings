#include <avr/io.h>
#define F_CPU 16000000UL

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
  TCNT1 = 63036;  //1 sec delay
  TCCR1B = 0X05;
  while ((TIFR1 & (1 << TOV1)) == 0)
    ;
  TCCR1B = 0;
  TIFR1 = 0X01;
}