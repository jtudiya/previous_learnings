#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL

int main() {

  DDRH |= (1 << PH5);
  TCCR4A = 0X08;
  TCCR4B = 0X19;
  ICR4=100;
  OCR4C=;
  while (1) {
  }
}