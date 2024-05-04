#include <avr/io.h>


int main() {
  DDRD = ~(1 << PD2);
  TCCR0A = 0x83;
  TCCR0B = 0x01;

  while (1) {

    if (PIND & (1 << PD2)) {
      OCR0A = 200;
    } else OCR0A = 0;
  }
}