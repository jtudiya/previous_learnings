#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRB |= (1 << PB2);

  while (1) {
    PORTB ^= (1 << PB2);
    _delay_ms(10);
    PORTB &= ~(1 << PB2);
    _delay_ms(10);
  }
}