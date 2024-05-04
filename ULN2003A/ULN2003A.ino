#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRB = 0xFF;

  while (1) {

    if (PORTB &= ~(1 << 7)) {
      PORTB = PORTB << 1;
      _delay_ms(10);
    } else {
      PORTB = 1 << 0;
      _delay_ms(10);
    }
  }
}