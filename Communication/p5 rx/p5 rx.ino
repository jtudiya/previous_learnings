#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRL = 0XFF;
  DDRH = 0xFF;
  UCSR1B = 0x10;
  UCSR1C = 0x06;
  UBRR1 = 103;
  UCSR0B = 0x10;
  UCSR0C = 0x06;
  UBRR0 = 103;


  while (1) {
    while (!(UCSR1A & (1 << RXC1)))
      ;
    PORTH = UDR1;

    while (!(UCSR0A & (1 << RXC0)))
      ;
    PORTL = UDR0;
  }
}
