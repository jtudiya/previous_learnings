#include <avr/io.h>
#define F_CPU 16000000UL
void T0Delay();

int main(void) {
  DDRA |= (1 << PA0);
  int i=1;

  while (1) {
    PORTA ^= 0x01;
    if (i<1001) {
      T0Delay();
      i++;
    }
    else {
    i=1;
    }
  }
  return 0;
}

void T0Delay() {

  TCNT0 = 125;  //1 sec delay
  TCCR0A = 0X00;
  TCCR0B = 0X05;
  while ((TIFR0 & (1 << TOV0)) == 0)
    ;
  TIFR0 = 0X01;
}