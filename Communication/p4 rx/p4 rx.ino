#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRB |= (1 << PB5);
  DDRC |= (1 << PC2);
  UCSR1B = 0x10;
  UCSR1C = 0x06;
  UBRR1 = 103;
  UCSR0B = 0x10;
  UCSR0C = 0x06;
  UBRR0 = 103;


  while (1) {
    while (!(UCSR1A & (1 << RXC1)))
      ;
    PORTC = (UDR1 << 2);

    while (!(UCSR0A & (1 << RXC0)))
      ;
    PORTB = (UDR0 << 5);
  }
}