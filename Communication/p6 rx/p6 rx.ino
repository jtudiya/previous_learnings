#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRK = 0XFF;
  UCSR1B = 0x10;
  UCSR1C = 0x06;
  UBRR1 = 103;


  while (1) {
    while (!(UCSR1A & (1 << RXC1)))
      ;
    PORTK = UDR1;
  } 
}
