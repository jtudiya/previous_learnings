#include <avr/io.h>
#define F_CPU 16000000UL
void delay();

int main(void) {
  DDRA |= 0X01;
  DDRB=0XFF;
  while (1) {
    PORTA ^= 0X01;
    PORTB=0XFF;
    delay();
  }
  return 0;
}

void delay() {
  TCNT0 = 0;
  OCR0A = 156.25;  //10 ms 312.5
  TCCR0A = 0X02;
  TCCR0B = 0x05;

  while ((TIFR0 & (1 << OCF0A)) == 0);
  TIFR0 = 0x02;
}