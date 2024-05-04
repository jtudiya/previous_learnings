#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
int pattern();
int x = 0x01;

int pattern() {
  _delay_ms(100);
  x = x << 1;
  if (x == 0x100) {
    _delay_ms(100);
    x = 0x01;
  }
}
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
  int n = 0, j = 0, x;
  while (1) {
    if ((~PIND & 0x01) && n == 0) {  //on
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = pattern();
      0x00;
      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = 0x00;
      j = 1;
    }
    if ((PIND & 0x01) && j == 1) {  //off
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = pattern();
      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = 0x00;
      n = 1;
    }
    if ((~PIND & 0x01) && n == 1) {  //on
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = 0x00;
      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = pattern();
      j = 2;
    }
    if ((PIND & 0x01) && (j == 2)) {  //off
      while (!(UCSR0A & (1 << UDRE0)))
        ;
      UDR0 = pattern();
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = 0x00;
      n = 0;
    }
  }
}