void setup() {
  // put your setup code here, to run once:
pinMode(53,INPUT_PULLUP);  //10
pinMode(51,INPUT_PULLUP);  //9
pinMode(49,INPUT_PULLUP);  //8
pinMode(47,INPUT_PULLUP);  //7
pinMode(45,INPUT_PULLUP);  //5
pinMode(43,INPUT_PULLUP);  //4
pinMode(41,INPUT_PULLUP);  //3
Serial.begin(9600);
}

void loop() {
 Serial.print(digitalRead(53));
 Serial.print(" " );
 Serial.print(digitalRead(51));
 Serial.print(" " );
 Serial.print(digitalRead(49));
 Serial.print(" " );
 Serial.print(digitalRead(47));
 Serial.print(" " );
 Serial.print(digitalRead(45));
 Serial.print(" " );
 Serial.print(digitalRead(43));
 Serial.print(" " );
 Serial.print(digitalRead(41));
 Serial.println();

}
