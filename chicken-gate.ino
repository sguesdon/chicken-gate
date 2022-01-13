#include <avr/interrupt.h>

#define regist PCINT0_vect

#define ISW_LIGHT 0
#define ISW_CLOSED 1
#define ISW_OPENED 2

#define OCMD_CLOSE 4
#define OCMD_OPEN 3

ISR (regist) {

  boolean isw_light = digitalRead(ISW_LIGHT) == HIGH;
  boolean isw_closed = digitalRead(ISW_CLOSED) == HIGH;
  boolean isw_opened = digitalRead(ISW_OPENED) == HIGH;

  digitalWrite(OCMD_CLOSE, (!isw_light && !isw_closed) ? HIGH : LOW);
  digitalWrite(OCMD_OPEN, (isw_light && !isw_opened) ? HIGH : LOW);
}

void setup() {

  pinMode(ISW_LIGHT, INPUT);
  pinMode(ISW_CLOSED, INPUT);
  pinMode(ISW_OPENED, INPUT);
  pinMode(OCMD_CLOSE, OUTPUT);
  pinMode(OCMD_OPEN, OUTPUT);

  GIMSK = 0b00100000;
  PCMSK = 0b00000111;
}

void loop() {}
