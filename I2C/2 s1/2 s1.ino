#include <avr/io.h>
#define F_CPU 16000000UL

void init(unsigned char SA) {
  TWCR = 0x04;                                      //enable TWImodule
  TWAR = SA;                                        //set slave address
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);  //init TWI module
}

void send(unsigned char data) {
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0);
}

unsigned char receive() {
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
  while ((TWCR & (1 << TWINT)) == 0);
  return (TWDR);
}

void listen() {
  while ((TWCR & (1 << TWINT)) == 0);
}


int main(void) {
  int i;
  DDRA = 0xFF;
  init(0xf0);
  listen();
  i= 32+ receive();
  PORTA=i-32;
  send(i);
  while (1)
    ;
  return 0;
}