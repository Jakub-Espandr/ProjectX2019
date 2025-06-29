#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define pinDHT 11
#define pinDHT2 10

#define typDHT11 DHT11

long randNumber;
long randNumber2;
long randNumber3;
long randNumber4;

long randNumber5;
long randNumber6;
long randNumber7;
long randNumber8;

DHT mojeDHT(pinDHT, typDHT11);
DHT mojeDHT2(pinDHT2, typDHT11);


LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin = 12;
int numPixels = 24;
int pixelFormat = NEO_GRB + NEO_KHZ800;
Adafruit_NeoPixel *pixels;
#define DELAYVAL 40


void counting() {
  randNumber = random(1, 99);
  randNumber2 = random(12345, 99999);
  randNumber3 = random(39, 999);
  randNumber4 = random(90, 999);

  randNumber5 = random(67, 999);
  randNumber6 = random(12345, 99999);
  randNumber7 = random(39, 9999);
  randNumber8 = random(90, 999);

  lcd.setCursor(0, 0);
  lcd.print(randNumber);
  lcd.setCursor(3, 0);
  lcd.print(randNumber2);
  lcd.setCursor(9, 0);
  lcd.print(randNumber3);
  lcd.setCursor(13, 0);
  lcd.print(randNumber4);
  lcd.setCursor(0, 1);
  lcd.print(randNumber5);
  lcd.setCursor(3, 1);
  lcd.print(randNumber6);
  lcd.setCursor(9, 1);
  lcd.print(randNumber7);
  lcd.setCursor(13, 1);
  lcd.print(randNumber8);
}

void stripcounting() {
  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 255, 0));
    pixels->show();

    counting();
  }


  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 0, 0));
    pixels->show();
  }
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(10);

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 0, 255));
    pixels->show();

    counting();
  }


  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 255, 0));
    pixels->show();
  }
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(10);

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 0, 255));
    pixels->show();

    counting();
  }
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(10);
}




void strip() {
  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 255, 0));
    pixels->show();
    delay(DELAYVAL);
  }

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 0, 0));
    pixels->show();
    delay(DELAYVAL);
  }

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(0, 0, 255));
    pixels->show();
    delay(DELAYVAL);
  }

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 255, 0));
    pixels->show();
    delay(DELAYVAL);
  }

  for (int i = 0; i < numPixels; i++) {
    pixels->setPixelColor(i, pixels->Color(255, 0, 255));
    pixels->show();
    delay(DELAYVAL);
  }
}

void temp() {

  float tep = mojeDHT.readTemperature();
  float hum = mojeDHT.readHumidity();
  float tep2 = mojeDHT2.readTemperature();
  float hum2 = mojeDHT2.readHumidity();

  lcd.setCursor(0, 0);
  lcd.print(tep);
  lcd.print(" / ");
  lcd.setCursor(0, 1);
  lcd.print(hum);
  lcd.print(" / ");
  lcd.setCursor(8, 0);
  lcd.print(tep2);
  lcd.print("(C)");
  lcd.setCursor(8, 1);
  lcd.print(hum2);
  lcd.print("(%)");
  strip();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("                ");
}


void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);
  pixels->begin();
  pixels->setBrightness(98);

  lcd.begin();
  lcd.backlight();

  mojeDHT.begin();
  mojeDHT2.begin();
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {



  lcd.setCursor(3, 0);
  lcd.print("Project X");
  lcd.setCursor(1, 1);
  lcd.print("flycamczech.cz");
  strip();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print("                ");

  temp();
  stripcounting();

  lcd.setCursor(1, 0);
  lcd.print("Czech Republic");
  strip();
  lcd.setCursor(0, 0);
  lcd.print("                ");

  temp();
  stripcounting();

  lcd.setCursor(0, 0);
  lcd.print("Jakub Espandr  &");
  lcd.setCursor(1, 1);
  lcd.print("Jakub Brandejs");
  strip();
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");

  temp();
  stripcounting();
}
