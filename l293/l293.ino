#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRB |= (1 << 7);
  TCCR0A = 0x83;
  TCCR0B = 0x05;
  int b, a = 1;
  OCR0A = b;

  while (1) {
    b = b + a;

    if (a <= 0 || a >= 255) {
      a = -a;
    }
    _delay_ms(10);
  }
}