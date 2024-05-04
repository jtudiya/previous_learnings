#include <avr/io.h>
#define ADDRESS 0x68
#define GYRO_Z_H 0x47
#define GYRO_Z_L 0x48



void ini() {
  TWSR = 0x00;  //set prescaler bits to zero
  TWBR = 0x0C;  //SCL Frequency 100k
  TWCR = 0x04;  //enable TWI module
}

void start() {
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0)
    ;
}

void write(unsigned int data) {
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0)
    ;
}

void stop() {
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

unsigned int read() {
  TWCR = (1 << TWINT) | (1 << TWEA) | (1 << TWEN);
  while ((TWCR & (1 << TWINT)) == 0)
    ;
  return TWDR;
}


void GYRO_Config() {
  start();
  write(0b11010000);
  write(0x1B);
  write(0x00);
  stop();

  start();
  write(0b11010000);
  write(0x6B);
  write(0x00);
  stop();
}


int16_t GYRO_Z = 0, a = 0, b = 0;
void setup() {
  
  ini();
  GYRO_Config();
  Serial.begin(9600);
}
void loop() {
  start();
  write(0b11010000);
  write(0x47);
  start();
  write(0b11010001);
  a = (read());
  stop();

  start();
  write(0b11010000);
  write(0x48);
  start();
  write(0b11010001);
  b = read();
  stop();

  GYRO_Z = (a<<8) +  b;
  Serial.println(GYRO_Z);
}
