#include <avr/io.h>
#define F_CPU 16000000UL

void inint(void) {
  TWSR = 0X00;  //set prescaler bits to zero
  TWBR = 0x48;  // scl frequency is 100k for XTAL=16MHz
  TWCR = 0x04;
}

void start(void) {
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0);
}

void write(unsigned char data) {
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0);
}

unsigned char read(){
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
  while((TWCR & (1<<TWEN))==0);
  return TWDR;
}

void stop() {
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

int main(void) {
  unsigned char i;
  DDRA = 0xFF;
  inint();
  start();      //transmit start condition
  write(0xf0);  //transmit
  write('H');   //transmit data
  i = read();
  PORTA=i;
  stop();       //transmit stop condition
  while (1);
  return 0;
}