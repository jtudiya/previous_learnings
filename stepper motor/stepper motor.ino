#include <avr/io.h>
#include <util/delay.h>
int i = 0, d = 0, n = 0, a = 0, s = 1;

int main() {
  
  init();
  DDRB |= 0x0F;
  Serial.begin(9600);

  while (1) {

    // if (i < 401) {
    //   PORTB ^= (1 << PB2);  // | (1<<PB0); // pulse
    //   _delay_ms(1);
    //   i++;
    // }

    if (Serial.available()) {
      n = Serial.parseInt();
    }

    Serial.print(a);
    Serial.print("  ");
    Serial.print(i);
    Serial.print("  ");
    Serial.println(d);
    a = n*0.5556;
    d = a - i;
    angle();

    if ((d==0 && i==200) || (d==0 && i==-200)) {
    i=0;
    d=0;
    a=0;
    n=0;
    }
  }
}

void angle() {

  if (d > 0) {
    PORTB |= (1<<PB2);
    _delay_ms(s);
    PORTB &=~ (1<<PB2);
    _delay_ms(s);
    i++;
  }

  if (d < 0) {
    PORTB |= (1<<PB2);
    PORTB |= (1<<PB0);
    _delay_ms(s);
    PORTB &=~ (1<<PB2);
    PORTB &=~ (1<<PB0);
    _delay_ms(s);
    i--;
  }
}