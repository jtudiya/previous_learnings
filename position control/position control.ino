#include <avr/io.h>
#include <avr/interrupt.h>
//void pid()
double csa = 0, psa = 0, csb = 0, psb = 0;
float n = 0, s, kp = 0, ki = 0.00000, kd = 0, ct = 0, pt = 0, dt = 0,k;
int a = 0, b, count = 0, e = 0, error, ei, etdt, p, i, d, pe;
//unsigned


int main() {

  init();
  DDRE &= ~(1 << PE4) | (1 << PE5);
  PORTE |= (1 << PE4) | (1 << PE5);
  EICRB |= (1 << ISC40) | (1 << ISC50);
  EIMSK |= (1 << INT4) | (1 << INT5);

  DDRH |= (1 << PH6);
  DDRH |= (1 << PH5);
  TCCR4A = 0xAA;
  TCCR4B = 0x19;
  ICR4 = 1000;

  Serial.begin(9600);


  while (1) {

    if (error==-error) {
    kp=k;
    } else {
    k=k+0.1;
    }


    if (Serial.available()) {
      n = Serial.parseFloat();
    }

    b = ((n * 1300.00) / 360.00);
    a = b;
    pid();

    dir(error);
    if (error == 0) {
      OCR4C = 0;
    } else {
      OCR4C = abs(s);
    }
    Serial.print(b);
    Serial.print("  ");
       Serial.print(kp);
       Serial.print("  ");
    Serial.println(count);
  }
}

void dir(int diff) {
  if (diff > 0) PORTH |= 0x40;
  else PORTH &= ~0x40;
}

void pid() {
  ct = micros();
  dt = (ct - pt) / 1000000.00;
  error = b - count;
  etdt = (error - pe) / dt;
  ei = ei + (error * dt);
  pt = ct;
  pe = error;
  p = kp * error;
  i = ki * ei;
  d = kd * etdt;
  s = 700 + p + i + d;
}

ISR(INT5_vect) {

  csa = ~PINE & 0x10;
  csb = ~PINE & 0x20;

  if (csa != psa) {
    if (csa != csb) {
      count++;
    } else {
      count--;
    }
  } else {
    if (csa == csb) {
      count++;
    } else {
      count--;
    }
  }
  if (csb != psb) {
    if (csb == csa) {
      count++;
    } else {
      count--;
    }
  } else {
    if (csb != csa) {
      count++;
    } else {
      count--;
    }
  }

  psa = csa;
  psb = csb;
}

ISR(INT4_vect) {

  csa = ~PINE & 0x10;
  csb = ~PINE & 0x20;

  if (csa != psa) {
    if (csa != csb) {
      count++;
    } else {
      count--;
    }
  } else {
    if (csa == csb) {
      count++;
    } else {
      count--;
    }
  }
  if (csb != psb) {
    if (csb == csa) {
      count++;
    } else {
      count--;
    }
  } else {
    if (csb != csa) {
      count++;
    } else {
      count--;
    }
  }

  psa = csa;
  psb = csb;
}