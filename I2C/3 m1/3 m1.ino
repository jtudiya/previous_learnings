#include <avr/io.h>
#define F_CPU 16000000UL

void write(unsigned char data) {
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0);
}

void start(void) {
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0);
}

void stop() {
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void inint(void) {
  TWSR = 0X00;  //set prescaler bits to zero
  TWBR = 0x48;  // scl frequency is 100k for XTAL=16MHz
  TWCR = 0x04;
}

int main(void) {
  inint();
  start();      //transmit start condition
  write(0xf0);  //transmit
  write('H');   //transmit data
  stop();       //transmit stop condition
  while (1)
    ;
  return 0;
}