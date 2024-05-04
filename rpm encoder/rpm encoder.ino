#include <avr/io.h>
void delay();
int rpm;
int count = 0, number = 0, i = 1;

int main() {
  PORTD &= ~(1 << 4);
  PORTD |= (1 << 4);
  // PORTB &= ~(1 << 0);
  // PORTB |= (1 << 0);
  PORTD |= (1 << 3);

  PCICR = 0x01;
  PCMSK0 = 0x03;
  init();
  sei();
  Serial.begin(9600);
  TCCR1A = 0x00;
  TCCR1B = 0x06;
  TCNT1 = 0;
  // int count = 0, number = 0, i = 1;

  while (1) {

    PORTD ^= 0x04;
    Delay();
    if (PORTD == 0x04) {
    rpm = count;
    }
    // count = TCNT1;
    // if (count > (600 * i)) {
    //   number++;
    //   i++;
    // }
    Serial.print(count);
    Serial.print("  ");
    Serial.print("RPM =");
    Serial.println(rpm);
  }
}

ISR(PCINT0_vect) {
  count = TCNT1;
  if (count > (600 * i)) {
    number++;
    i++;
  }
}


void T0Delay() {
  TCNT0 = ;
  TCCR0A =0x00;
  TCCR0B = 0X05;
  while ((TIFR0 & (1 << TOV0)) == 0)
    ;
  TIFR0 = 0X01;
}