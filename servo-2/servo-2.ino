#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main() {

  DDRB |= (1 << 5);
  TCCR1A = 0x82;
  TCCR1B = 0x1A;
  ICR1 = 39999;
+
  while (1) {
    angle(17.59);
  }
}
float angle(float n) {
  OCR1A = n * 11.1111+ 1999;
}