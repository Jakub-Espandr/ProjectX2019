#include "show_sensors.h"
#include <Arduino.h>

void showline() {

  Serial.print(analogRead(A5));
  Serial.print("  ");
  Serial.print(analogRead(A0));
  Serial.print("    ");
  Serial.print(analogRead(A1));
  Serial.print("  ");
  Serial.print(analogRead(A2));
  Serial.print("    ");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print(analogRead(A3));
  Serial.println();
}

void showcandle() {
  Serial.print(digitalRead(53));
  Serial.print("  ");
  Serial.print(digitalRead(51));
  Serial.print("  ");
  Serial.print(digitalRead(49));
  Serial.print("  ");
  Serial.print(digitalRead(47));
  Serial.print("  ");
  Serial.print(digitalRead(45));
  Serial.print("  ");
  Serial.print(digitalRead(43));
  Serial.print("  ");
  Serial.print(digitalRead(41));
  Serial.println();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(53, INPUT_PULLUP);
  pinMode(51, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  pinMode(47, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);  // CONNECTED PINS FOR CANDLE SENSOR
  pinMode(41, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  showline();
}
