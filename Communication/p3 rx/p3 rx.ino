#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  //DDRD |= (1 << PD3);
  DDRE = 0xFF;
  UCSR1B = 0x18;
  UCSR1C = 0x06;
  UBRR1 = 103;
  char a = 'a';

  while (1) {
    while (!(UCSR1A & (1 << RXC1)))
      ;
    _delay_ms(100);
    while (!(UCSR1A & (1 << UDRE1)))
      ;
    UDR1 = PORTE + 32;
    if (TXC1 == 0) {
      PORTE = 0;
    } else PORTE = UDR1;
  }
}