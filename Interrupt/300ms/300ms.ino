#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL

int main() {
  DDRB |= (1 << PB5);
  TCNT0 = -32;
  TCCR0A = 0x00;
  TCCR0B = 0x01;
  TIMSK0 = (1 << TOIE0);
  sei();

  while (1){
    // PORTB ^= (1 << PB5);
  }
  return 0;
}

ISR(TIMER0_OVF_vect) {
  PORTB ^= (1 << PB5);
}