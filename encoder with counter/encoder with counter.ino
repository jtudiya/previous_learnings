#include <avr/io.h>
#define F_CPU 16000000UL

int main() {
  PORTD &= ~(1 << 5);
  PORTD |= (1 << 5);
  Serial.begin(9600);
  TCCR1A = 0x00;
  TCCR1B = 0x06;
  TCNT1 = 0;
  int count = 0, number = 0, i = 1;

  while (1) {
    count = TCNT1;
    if (count > (600 * i)) {
      number++;
      i++;
    }
    Serial.print(count);
    Serial.print("  ");
    Serial.println(number);
  }
}
