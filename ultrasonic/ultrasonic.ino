//    7 oo oo oo 6
//   2 oo   3  oo 4
//1 oo             oo 5


long duration1, duration2, duration3, duration4, duration5, duration6, duration7;
long distance1, distance2, distance3, distance4, distance5, distance6, distance7;



//---------------//
int range = 13;
int rangeSide = 10;
//---------------//


int trigPin1 = 11;
int echoPin1 = 12;

int trigPin2 = 10;
int echoPin2 = 9;

int trigPin3 = 7;
int echoPin3 = 8;

int trigPin4 = 5;
int echoPin4 = 6;

int trigPin5 = 4;
int echoPin5 = 3;

int trigPin6 = 14;
int echoPin6 = 15;

int trigPin7 = 16;
int echoPin7 = 17;


void setup() {
  //Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);

  pinMode(trigPin6, OUTPUT);
  pinMode(echoPin6, INPUT);

  pinMode(trigPin7, OUTPUT);
  pinMode(echoPin7, INPUT);

  pinMode(13, OUTPUT);
}

void loop() {

  long duration1, distance1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  long duration2, distance2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  long duration3, distance3;
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  long duration4, distance4;
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = (duration4 / 2) / 29.1;

  long duration5, distance5;
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5 = (duration5 / 2) / 29.1;

  long duration6, distance6;
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = (duration6 / 2) / 29.1;

  long duration7, distance7;
  digitalWrite(trigPin7, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin7, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin7, LOW);
  duration7 = pulseIn(echoPin7, HIGH);
  distance7 = (duration7 / 2) / 29.1;



  if ((distance1 < rangeSide) or
      (distance2 < range) or
      (distance3 < range) or
      (distance4 < range) or
      (distance6 < range) or
      (distance7 < range) or
      (distance5 < rangeSide)) {
    digitalWrite(13, LOW);
  }

  else {
    digitalWrite(13, HIGH);
  }

/*
  Serial.print(distance1);
  Serial.print("  ");
  Serial.print(distance2);
  Serial.print("  ");
  Serial.print(distance3);
  Serial.print("  ");
  Serial.print(distance4);
  Serial.print("  ");
  Serial.print(distance5);
  Serial.print(" // ");
  Serial.print(distance6);
  Serial.print("  ");
  Serial.print(distance7);
  Serial.println();
*/

}
