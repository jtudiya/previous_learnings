#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {
  //DDRD = (1 << PD3);
  PORTD = (1 << PD0);
  DDRE = 0xFF;
  UCSR1B = 0x18;
  UCSR1C = 0x06;
  UBRR1 = 103;
  char a = 'A';


  while (1) {

    if (~PIND & 0X01) {


      while (!(UCSR1A & (1 << UDRE1)))
        ;
      UDR1 = a;
      a++;
      if (a == '[') {
        a = 'A';
      }
      while (!(UCSR1A & (1 << RXC1)));
      PORTE = UDR1;
      _delay_ms(100);
    } else {
      PORTE = 0x00;
      PORTD=0X00;
      a='A';
    }
  }
}