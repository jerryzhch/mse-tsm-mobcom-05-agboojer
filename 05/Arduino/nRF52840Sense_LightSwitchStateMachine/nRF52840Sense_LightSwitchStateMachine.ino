/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/DigitalReadSerial/
*/
#include <Adafruit_TinyUSB.h>  // provides Serial on nRF52840

int pushButton = 7; // onboard button
int ledPin = 4; // onboard, blue LED

int state = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
}

int pressed(int value) {
  return value == LOW; // inverted, active low
}
// the loop routine runs over and over again forever:
void loop() {
  
  int b = digitalRead(pushButton);
  Serial.println(b);
  if (state == 0 && pressed(b)) {
    state = 1;
    digitalWrite(ledPin, HIGH);
  } else if (state == 1 && !pressed(b)) {
    state = 2;
  } else if (state == 2 && pressed(b)) {
    state = 3;
    digitalWrite(ledPin, LOW);
  } else if (state == 3 && !pressed(b)) {
    state = 0;
  }
  delay(1);
}
