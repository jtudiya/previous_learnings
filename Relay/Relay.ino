#include <avr/io.h>
#include <util/delay.h>

int main() {

  DDRB |= (1 << PIN3);
  while (1) {
    PORTB |= (1 << PIN3);
  }
  return 0;
}