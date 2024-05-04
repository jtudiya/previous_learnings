#include <avr/io.h>
#include <util/delay.h>
int i = 0, d = 0, n = 0, a = 0, s = 3, k = 0;

int main() {
  init();
  DDRB |= 0x0F;
  PORTB = 0x01;

  Serial.begin(9600);

  while (1) {

    if (Serial.available()) {
      n = Serial.parseInt();
    }

    Serial.print(a);
    Serial.print("  ");
    Serial.print(i);
    Serial.print("  ");
    Serial.println(d);
    a = n *5.56 ;
    d = a - i;
    cw();
    ccw();
  }
}

void cw() {
  if (d > 0) {
    PORTB = 1 << k;
    _delay_ms(s);
    k++;
    if (k == 4) {
      _delay_ms(s);
      k = 0;
    }
    i++;
  }
}

void ccw() {
  if (d < 0) {
    PORTB = 8 >> k;
    _delay_ms(s);
    k++;
    if (k == 4) {
      k = 0;
      _delay_ms(s);
    }
    i--;
  }
}