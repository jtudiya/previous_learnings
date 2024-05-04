#include <avr/io.h>
#define F_CPU 16000000UL
void delay();

int main(void) {
  DDRA |= 0X01;
  DDRB = 0XFF;
  while (1) {
    PORTA ^= 0X01;
    PORTB = 0XFF;
    delay();
  }
  return 0;
}

void delay() {
  TCNT1 = 0;
  OCR1A = 125;  //500 us
  TCCR1A = 0X02;
  TCCR1B = 0x03;

  while ((TIFR1 & (1 << OCF1A)) == 0)
    ;
  TIFR1 = 0x02;
}