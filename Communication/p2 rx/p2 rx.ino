#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRD &= ~(1 << PD2);
  DDRE = 0xFF;
  UCSR1B = 0x18;
  UCSR1C = 0x06;
  UBRR1 = 103;
  unsigned char ch;

  while (1) {
    while (!(UCSR1A & (1 << RXC1)))
      ;
    PORTE = UDR1;
    while (!(UCSR1A & (1 << UDRE1)))
      ;
    UDR1 = 'H';
  }
}