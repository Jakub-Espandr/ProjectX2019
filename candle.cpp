#include "candle.h"
#include <Arduino.h>

//--------------//
int candle = 900;
//--------------//


void display() {
  Serial.print(analogRead(A0));
  Serial.print("   ");
  Serial.print(analogRead(A1));
  Serial.print("   ");
  Serial.print(analogRead(A2));
  Serial.print("   ");
  Serial.print(analogRead(A3));
  Serial.print("   ");
  Serial.print(analogRead(A4));
  Serial.print("   ");
  Serial.print(analogRead(A5));
  //Serial.println();
}

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if ((analogRead(A0) < candle) or (analogRead(A1) < candle) or (analogRead(A2) < candle) or (analogRead(A3) < candle) or (analogRead(A4) < candle) or (analogRead(A5) < candle)) {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  //display();
}
