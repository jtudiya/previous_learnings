#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  DDRE = 0XFF;
  DDRH = 0xFF;
  UCSR1B = 0x10;
  UCSR1C = 0x06;
  UBRR1 = 103;
  UCSR1B = 0x18;
  UCSR1C = 0x06;
  UBRR1 = 103;



  while (1) {

    while (!(UCSR1A & (1 << RXC1)))
      ;
    PORTE = UDR1;

    if (1 << PORTD2 == 0x00) {
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = 0x00;
    } else {
      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = UDR1;
    }
  }
}
