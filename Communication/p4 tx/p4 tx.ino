#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRD &= ~(1 << PD0);
  PORTD = (1 << PD0);
  PORTE = (1 << PD0);
  UCSR1B = 0x08;
  UCSR1C = 0x06;
  UBRR1 = 103;
  UCSR0B = 0x08;
  UCSR0C = 0x06;
  UBRR0 = 103;


  while (1) {

    if (~PIND & 0X01) {
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = 0x01;

      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = 0x01;
    } else {
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = 0x00;

      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = 0x00;
      
    }
  }
}