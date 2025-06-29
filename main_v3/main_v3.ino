/*...........................................................................................................................
  ............................................................................................................................
  ...........................................................................................................................
  ........@@@@@@@@@@@@@@..................................................................................@@@@@@.......@@@...
  .....@@@@@@@@@@@@@@@@@@@............................................................................@@@@@@@@@@@.....@@@....
  ...@@@@....@@@.......@@@@..................................@@@................................. ..@@@@@@@...@@@@...@@@.....
  ..@@......@@@.........@@@.................................@@@............................@@......@@@@.......@@@@.@@@.......
  .........@@@..........@@@..............................................................@@@@@.....@@@@@.......@@@@@@........
  .......@@@...........@@@...@@...@@@.....@@@@...........@@@@.....@@@@@......@@@@@....@@@@@@@@@................@@@@@@........
  ......@@@.........@@@@....@@@@@@@@@...@@@@@@@@.....@@@@@@@@@..@@@...@@...@@@@@@@@.....@@@....................@@@@@.........
  ...@@@@@.......@@@@@.....@@@@@.@@@...@@@....@@@..@@@@...@@...@@@...@@...@@@...@@@....@@@....................@@@@@@.........
  .@@@@@@@@@@@@@@@........@@....@@....@@@@....@@@........@@...@@@@@@@@...@@@..........@@@....................@@@@.@@@........
  ...@@@.................@@...@@......@@@.....@@@.......@@...@@@@.......@@@..........@@@...@@@..............@@@@...@@@.......
  ..@@@................@@@....@@@@@@..@@@@..@@@@.......@@...@@@@....@@..@@@....@@@..@@@...@@@..............@@@@.....@@@......
  .@@@.................@@......@@@......@@@@@@........@@@.....@@@@@@@....@@@@@@@@...@@@@@@@@..............@@@@......@@@@.....
  @@@@...............................................@.@@................................................@@@@.......@@@@@@...
  @@@..............................................@@.@@.....................................................................
  ................................................@@.@@......................................................................
  ...............................................@@.@@.......................................................................
  ..............................................@@@@@........................................................................
  ..............................................@@@..........................................................................
  ...........................................................................................................................
  ...........................................................................................................................
*/

//  rev. 1.48

// REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW
//    REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW  REVIEW

/*......................................................................................................................
  88 - 150 DEFINITONS, VARIABLES, STATIC
  155 - 726 void
  732 - 774 void setup
  782 - 1374 void loop
  .....................................................................................................................
*/

// UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE  UPDATE
//     NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES   NOTES

/*......................................................h..............................................................
  13.4 new project                                      5
  15.4 definiton, setup                                 4
  29.4 if conditions                                    5
  10.5 servo, if conditions                             6
  12.5 if contitions, bool interactions                 4
  16.5 bool interactions, motor                         6
  18.5 communication slave                              5
  20.5 communication master                             4
  22.5 main program                                     6
  24.5 logic states                                     4
  26.5 logic states, program, bools                     6
  28.5 everything again                                 6
  01.6 reactions                                        5
  03.6 motor stop, motor reactions                      5
  04.6 line, candle, object                             5
  05.6 reactions for obstacle                           4
  07.6 circle around obstacle                           5
  08.6 escape states                                    4
  09.6 candle                                           8
  10.6 stop actions                                     6
  12.6 bugs                                             7
  13.6 communication fixes                              8
  14.6 random states fix                                8
  15.6 fix main seed                                    8
  16.6 debugging ( () {} )                              8
  02.7 debugging                                        7
  03.7 trying to fix problem with candle                8
             04.7 >>>>firstly used walls<<<<            10
  04.7 add optionaly: blow out behind wall              10
  05.7 bug in font of candle fix                        10
  06.7 fixing speed, adding SEEK MODE next to line      10
  06.7 optimalisation                                   10
  07.7 optimalisation and debugging                     9
  15.7 debugging - line + can. , line cross
  16.7 final debugging
  16.7 pre flight robot check and sensor cleaning
  .......................................................................................................
*/



/*
  05.7      2:42 , 1:38 , 2:51 , error stuck obstacle and candle , out of time
  07.7      1:45 , 1;54 , 1:35
  15.7      1:55 , 2:10 , 2:05 , 2:22 , 1:14 , 1:47
  16.7      out of track , error no candle stop / debugging 
  16.7      last time : 2:44 - problem stuck on obstacle 

*/

// ------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------

#include <Servo.h>  // include library
Servo propeller;    // inicializate servo
#define on 102      // activate propeller servo degrees
#define off 180     // deactivate propeller servo degrees

//..................................................................

//SENSORS
#define ten 53         // candle sensor ten
#define nine 51        // candle sensor nine
#define eight 49       // candle sensor eight
#define seven 47       // candle sensor seven
#define five 45        // candle sensor five
#define four 43        // candle sensor four
#define three 41       // candle sensor three
#define button 10      // start button
#define ultrasonic 37  // ultrasonic sensor
#define backup A8      // candle sensor backup (lower)
#define backup2 A10    // candle sensor backup2 (higher)

#define led 36  // indicating led before start

#define mode 12  // mode switch

//..................................................................

//MOTORS
#define steps 4   // left motor step pin
#define dir 5     // left motor dir pin
#define steps2 2  // right motor step pin
#define dir2 3    // right motor dir pin

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define stepTime 800     // stepDELAYVAL
#define turnTime 2400    // turnDELAYVAL
int lineV = 350;         // value for line sensor
int backupLight = 380;   // value for candle backup sensnor
int backupLight2 = 530;  // value for backup2 candle sensor
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#define msg 7     // driver microstepping pin  (HIGH)
#define enable 6  // driver enable pin         (LOW)

//..................................................................

#define line >   // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define lineN <  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//.................................................................

int randNumber;  // random number for turning
int randState;   // random state for turning
int btt;         // value for start button - starting value is 0
int state;       // state value for debugging line and sensors
int slow;
//..................................................................

//  a5      a0
//a1    .     a2
//     / \                  line sensor shcheme
//      I
//a4    I     a3

//--------------------------------------------------------------------------------------------------------------
//VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs  VOIDs
//--------------------------------------------------------------------------------------------------------------

void goFwd() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, HIGH);
  digitalWrite(dir2, LOW);
  digitalWrite(steps, HIGH);  // go FORWARD
  digitalWrite(steps2, HIGH);
  delayMicroseconds(stepTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(stepTime);
}

//........................................................

void goFwdSlow() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, HIGH);
  digitalWrite(dir2, LOW);
  digitalWrite(steps, HIGH);  // go FORWARD SLOWLY
  digitalWrite(steps2, HIGH);
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);
}
//..................................................................
void turnL() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, HIGH);  // turn LEFT
  digitalWrite(dir2, HIGH);
  digitalWrite(steps, HIGH);
  digitalWrite(steps2, HIGH);
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);
}

//..................................................................
void turnR() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(steps, HIGH);
  digitalWrite(steps2, HIGH);  // turn RIGHT
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);
}


//..................................................................
void turnLeft() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, HIGH);  // turn LEFT
  digitalWrite(dir2, HIGH);
  digitalWrite(steps, HIGH);
  digitalWrite(steps2, HIGH);
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);
}

//..................................................................
void turnRight() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, LOW);
  digitalWrite(dir2, LOW);
  digitalWrite(steps, HIGH);
  digitalWrite(steps2, HIGH);  // turn RIGHT
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);
}
//..................................................................
void goBack() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, LOW);
  digitalWrite(dir2, HIGH);  // go BACK
  digitalWrite(steps, HIGH);
  digitalWrite(steps2, HIGH);
  delayMicroseconds(turnTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(turnTime);

  if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A3) line lineV) or (analogRead(A4) line lineV) or (analogRead(A5) line lineV)) {
    motorStop();
    turnR();
  }
}

//..................................................................
void goBack100() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);
  for (int i = 0; i < 115; i++) {
    digitalWrite(dir, LOW);
    digitalWrite(dir2, HIGH);  // go BACK 100 times
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(turnTime);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, LOW);
    delayMicroseconds(turnTime);

    if ((analogRead(A3) line lineV) or (analogRead(A4) line lineV)) {
      state++;
      motorStop();
      turnR();
      break;

      if (state > 50) {
        motorStop();
        randR();
        state = 0;
      }
    }
  }

  delay(100);
}

//..................................................................
void goBack50() {
  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);
  for (int i = 0; i < 50; i++) {
    digitalWrite(dir, LOW);
    digitalWrite(dir2, HIGH);  // go BACK 50 times
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(turnTime);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, LOW);

    delayMicroseconds(turnTime);
    if ((analogRead(A3) line lineV) or (analogRead(A4) line lineV)) {
      state++;
      motorStop();
      turnR();
      break;

      if (state > 50) {
        motorStop();
        randR();
        state = 0;
      }
    }
  }

  delay(100);
}

//..................................................................
void motorStop() {

  digitalWrite(msg, HIGH);
  digitalWrite(enable, LOW);

  digitalWrite(dir, LOW);
  digitalWrite(dir2, HIGH);
  digitalWrite(steps, HIGH);  // STOP motor
  digitalWrite(steps2, HIGH);
  delayMicroseconds(stepTime);
  digitalWrite(steps, LOW);
  digitalWrite(steps2, LOW);
  delayMicroseconds(stepTime);
}

//..................................................................
void circle() {
  for (int i = 0; i < 850; i++) {
    digitalWrite(msg, HIGH);
    digitalWrite(enable, LOW);

    digitalWrite(dir, HIGH);
    digitalWrite(dir2, LOW);

    digitalWrite(steps, HIGH);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, LOW);  // circle around obstacle
    delayMicroseconds(1000);
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, LOW);
    delayMicroseconds(1000);
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, LOW);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, HIGH);
    delayMicroseconds(1000);
    digitalWrite(steps, HIGH);
    digitalWrite(steps2, LOW);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, LOW);
    delayMicroseconds(1000);
    digitalWrite(steps, LOW);
    digitalWrite(steps2, LOW);
    delayMicroseconds(1000);

    if ((digitalRead(ten) == LOW) or (digitalRead(nine) == LOW) or (digitalRead(eight) == LOW) or (digitalRead(seven) == LOW) or (digitalRead(five) == LOW) or (digitalRead(four) == LOW) or (digitalRead(three) == LOW) or ((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2)) or ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A3) line lineV) or (analogRead(A4) line lineV) or (analogRead(A5) line lineV))) {
      motorStop();
      delay(100);
      break;
    }
  }
}

//..................................................................
void turnL90() {
  for (int i = 0; i < 180; i++) {
    turnL();  // TURN LEFT 90 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnR();
      break;
    }
  }

  delay(100);
}

//..................................................................
void turnR90() {
  for (int i = 0; i < 180; i++) {
    turnR();  // TURN RIGHT 90 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnL();
      break;
    }
  }

  delay(100);
}

//..................................................................
void turnL45() {
  for (int i = 0; i < 120; i++) {
    turnL();  // TURN LEFT 45 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnR();
      break;
    }
  }

  delay(100);
}

//..................................................................
void turnR45() {
  for (int i = 0; i < 120; i++) {
    turnR();  // TURN RIGHT 45 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnL();
      break;
    }
  }

  delay(100);
}

//..................................................................
void turnL135() {
  for (int i = 0; i < 260; i++) {
    turnL();  // TURN LEFT 135 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnR();
      break;
    }
  }

  delay(100);
}

//..................................................................
void turnR135() {
  for (int i = 0; i < 260; i++) {
    turnR();  // TURN RIGHT 135 DEGREES

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      motorStop();
      turnL();
      break;
    }
  }

  delay(100);
}

//..................................................................
void randR() {
  randNumber = random(53, 180);  // default 63, 180
  for (int i = 0; i < randNumber; i++) {
    turnR();  // RANDOM ROTATE RIGHT

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      state++;
      motorStop();
      turnL();
      break;

      if (state > 50) {
        motorStop();
        goFwd();
        state = 0;
      }
    }
  }

  delay(100);
}

//..................................................................
void randL() {
  randNumber = random(53, 180);  // default 63, 180
  for (int i = 0; i < randNumber; i++) {
    turnL();  // RANDOM ROTATE LEFT

    if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
      motorStop();
      break;
      delay(50);
    }

    if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
      state++;
      motorStop();
      turnL();
      break;

      if (state > 50) {
        motorStop();
        goFwd();
        state = 0;
      }
    }
  }

  delay(100);
}

//..................................................................
void randRotate() {
  randState = random(101);

  if (randState > 50) {
    randNumber = random(63, 180);
    for (int i = 0; i < randNumber; i++) {
      turnR();

      if ((analogRead(backup) < backupLight) or  // RANDOM ROTATE
          (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
        motorStop();
        break;
        delay(50);
      }

      if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
        state++;
        motorStop();
        turnR();
        break;

        if (state > 50) {
          motorStop();
          goFwd();
          state = 0;
        }
      }
    }
  }

  if (randState < 50) {  // RANDOM ROTATE
    randNumber = random(63, 180);
    for (int i = 0; i < randNumber; i++) {
      turnL();

      if ((analogRead(backup) < backupLight) or (digitalRead(seven) == LOW) or (analogRead(backup2) < backupLight2)) {
        motorStop();
        break;
        delay(50);
      }

      if ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) {
        state++;
        motorStop();
        turnL();
        break;

        if (state > 50) {
          motorStop();
          goFwd();
          state = 0;
        }
      }
    }
  }
}

//..................................................................

void fire() {
  motorStop();
  propeller.write(on);
  delay(10);
  propeller.write(on);
  delay(200);

  for (int i = 0; i < 50; i++) {
    turnLeft();
  }
  delay(200);

  for (int i = 0; i < 100; i++) {
    turnRight();
  }
  delay(200);

  for (int i = 0; i < 100; i++) {  // STOP FIRE
    turnLeft();
  }
  delay(200);

  for (int i = 0; i < 50; i++) {
    turnRight();
  }
  delay(100);
  propeller.write(off);
  delay(10);
  propeller.write(off);
  slow = 0;
  delay(100);
}

//----------------------------------------------------------------------------------------------------------
//VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID  VOID
//   SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP    SETUP
//----------------------------------------------------------------------------------------------------------

void setup() {
  pinMode(ten, INPUT_PULLUP);         // candle sensor ten
  pinMode(nine, INPUT_PULLUP);        // candle sensor nine
  pinMode(eight, INPUT_PULLUP);       // candle sensor eight
  pinMode(seven, INPUT_PULLUP);       // candle sensor seven
  pinMode(five, INPUT_PULLUP);        // candle sensor five
  pinMode(four, INPUT_PULLUP);        // candle sensor four
  pinMode(three, INPUT_PULLUP);       // candle sensor three
  pinMode(ultrasonic, INPUT_PULLUP);  // ultrasonic sensor
  pinMode(button, INPUT_PULLUP);      // start butoon
  pinMode(11, OUTPUT);                // GND for switch mode
  pinMode(mode, INPUT_PULLUP);        // mode switch
  pinMode(led, OUTPUT);               // led (turn on == LOW)

  //..................................................................

  // MOTOR
  pinMode(steps, OUTPUT);   // steps
  pinMode(dir, OUTPUT);     // direction
  pinMode(steps2, OUTPUT);  // steps2
  pinMode(dir2, OUTPUT);    // direction2
  pinMode(msg, OUTPUT);     // microstepping
  pinMode(enable, OUTPUT);  // driver enable

  //..................................................................

  Serial.begin(9600);  // baud rate

  //..................................................................

  //PROPELLER
  propeller.attach(8);   // servo for propeller
  propeller.write(off);  // default servo position

  //..................................................................

  randomSeed(analogRead(15));  // read number from pin 15
  btt = 0;                     // default button value
  state = 0;                   // default state value
  slow = 0;
  digitalWrite(11, LOW);  // GND for switch mode
}


//   LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP
//...........................................................................................................
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//...........................................................................................................
//   LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP  LOOP


void loop() {

  if ((btt < 1) and ((digitalRead(three) == LOW) or (digitalRead(four) == LOW) or (digitalRead(five) == LOW) or (digitalRead(seven) == LOW) or (digitalRead(eight) == LOW) or (digitalRead(nine) == LOW) or  // candle test
                     (digitalRead(ten) == LOW) or (analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2))) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }

  //....................................................................

  // start button
  if (digitalRead(button) == LOW) {  // increasing btt value
    btt++;
    delay(400);
  }

  if (btt >= 1) {  // if button pressed, START
    goFwd();

    //..................................................................
    // obstacle
    // swithed to "FCC MODE"
    if ((digitalRead(mode) == LOW) and (digitalRead(ultrasonic) == LOW)) {
      for (int i = 0; i < 150; i++) {
        goFwdSlow();

        if ((analogRead(A5) line lineV) or  // switch to "FCC MODE"
            (analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV)) {
          motorStop();
          break;
        }
      }

      delay(50);

      for (int i = 0; i < 130; i++) {
        turnL();

        if ((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(100);

      for (int i = 0; i < 240; i++) {
        turnR();

        if ((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(100);

      for (int i = 0; i < 120; i++) {
        turnL();

        if ((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(100);
      goBack100();

      delay(100);
      randRotate();
    }

    //..................................................................

    // obstacle
    // "NORMAL MODE"
    if ((digitalRead(ultrasonic) == LOW) and (digitalRead(mode) == HIGH) and ((digitalRead(five) == HIGH) and (digitalRead(seven) == HIGH) and (digitalRead(eight) == HIGH) and (digitalRead(three) == HIGH) and  // switched to normal mode
                                                                              (digitalRead(four) == HIGH) and (digitalRead(nine) == HIGH) and (digitalRead(ten) == HIGH))) {
      motorStop();
      delay(100);
      goBack100();

      for (int i = 0; i < 130; i++) {
        turnR();

        if (((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) and (digitalRead(seven) == HIGH) and (analogRead(backup) > backupLight)) {
          motorStop();
          delay(50);
          turnR();
          break;
        }
      }

      delay(100);
      circle();
    }

    //..................................................................


    // candle three
    if (
      /*((analogRead(A0) lineN lineV) or
        (analogRead(A1) lineN lineV) or
        (analogRead(A2) lineN lineV) or
        (analogRead(A3) lineN lineV) or
        (analogRead(A4) lineN lineV) or
        (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(three) == LOW) and  // candle three
      (digitalRead(seven) == HIGH) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2)) {
      motorStop();
      delay(100);
      turnL135();
      slow = 1;
      delay(10);
    }

    //..................................................................

    // candle four
    if (
      /*((analogRead(A0) lineN lineV) or
         (analogRead(A1) lineN lineV) or
         (analogRead(A2) lineN lineV) or
         (analogRead(A3) lineN lineV) or
         (analogRead(A4) lineN lineV) or
         (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(four) == LOW) and (digitalRead(seven) == HIGH) and  // cadnle four
      (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2)) {
      motorStop();
      delay(100);
      turnL90();
      slow = 1;
      delay(10);
    }

    //..................................................................

    // candle five
    if (
      /*((analogRead(A0) lineN lineV) or
         (analogRead(A1) lineN lineV) or
         (analogRead(A2) lineN lineV) or
         (analogRead(A3) lineN lineV) or
         (analogRead(A4) lineN lineV) or
         (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(five) == LOW)) {  // candle five
      motorStop();
      delay(100);
      turnL45();
      slow = 1;
      delay(10);
    }

    //..................................................................

    // candle seven (or seven and five and eight)
    if (((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or  // candle seven
         (analogRead(A5) line lineV))
        and ((digitalRead(seven) == LOW) or (analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2))) {
      motorStop();
      delay(100);
      fire();
      delay(100);
      goBack50();
      delay(10);
      randRotate();
      slow = 0;
      delay(10);
    }

    //..................................................................

    // candle eight
    if (
      /*((analogRead(A0) lineN lineV) or
        (analogRead(A1) lineN lineV) or
        (analogRead(A2) lineN lineV) or
        (analogRead(A3) lineN lineV) or
        (analogRead(A4) lineN lineV) or
        (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(eight) == LOW)) {  // candle eight
      motorStop();
      delay(100);
      turnR45();
      slow = 1;
      delay(10);
    }

    //..................................................................

    // candle nine
    if (
      /*((analogRead(A0) lineN lineV) or
        (analogRead(A1) lineN lineV) or
        (analogRead(A2) lineN lineV) or
        (analogRead(A3) lineN lineV) or
        (analogRead(A4) lineN lineV) or
        (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(nine) == LOW) and (digitalRead(seven) == HIGH) and (analogRead(backup) > backupLight) and  // candle nine
      (analogRead(backup2) > backupLight2)) {
      motorStop();
      delay(100);
      turnR90();
      slow = 1;
      delay(10);
    }

    //..................................................................

    // candle ten
    if (
      /*((analogRead(A0) lineN lineV) or
        (analogRead(A1) lineN lineV) or
        (analogRead(A2) lineN lineV) or
        (analogRead(A3) lineN lineV) or
        (analogRead(A4) lineN lineV) or
        (analogRead(A5) lineN lineV)) and
      */
      (digitalRead(ten) == LOW) and (digitalRead(seven) == HIGH) and  // candle ten
      (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2)) {
      motorStop();
      delay(100);
      turnR135();
      slow = 1;
      delay(10);
    }


    //..................................................................
    // line Left no candle
    if (((analogRead(A1) line lineV) or (analogRead(A5) line lineV)) and (analogRead(backup) > backupLight) and  // left line
        (analogRead(backup2) > backupLight2) and (digitalRead(seven) == HIGH) and (slow == 0)) {
      motorStop();
      delay(50);

      goBack100();
      delay(10);
      randR();
      delay(100);
    }

    //.................................................................
    // line left + candle
    if (((analogRead(A1) line lineV) or (analogRead(A5) line lineV)) and (analogRead(backup) > backupLight) and  // left line
        (analogRead(backup2) > backupLight2) and (digitalRead(seven) == HIGH) and (slow == 1)) {
      motorStop();
      delay(100);

      for (int i = 0; i < 9; i++) {
        goBack();
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 200; i++) {
        turnR();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }


      goBack100();
      delay(10);
      randR();
      slow = 0;
      delay(100);
    }


    //..................................................................

    // line Right no candle
    if (((analogRead(A0) line lineV) or (analogRead(A2) line lineV)) and  // right line
        (digitalRead(seven) == HIGH) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2) and (slow == 0)) {
      motorStop();
      delay(50);

      goBack100();
      delay(10);
      randL();
      delay(100);
    }

    //...................................................................

    // line Right + candle
    if (((analogRead(A0) line lineV) or (analogRead(A2) line lineV)) and  // right line
        (digitalRead(seven) == HIGH) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2) and (slow == 1)) {
      motorStop();
      delay(100);

      for (int i = 0; i < 9; i++) {
        goBack();
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 200; i++) {
        turnR();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }


      goBack100();
      delay(10);
      randL();
      slow = 0;
      delay(100);
    }


    //..................................................................

    // line Right and Left no candle
    if ((((analogRead(A5) line lineV) and (analogRead(A0) line lineV)) or ((analogRead(A1) line lineV) and (analogRead(A2) line lineV))) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2) and  // right and left line
        (digitalRead(seven) == HIGH) and (slow == 0)) {
      motorStop();
      delay(50);

      goBack100();
      delay(10);
      randRotate();
      delay(100);
    }

    //..................................................................

    // line Right and Left + candle
    if ((((analogRead(A5) line lineV) and (analogRead(A0) line lineV)) or ((analogRead(A1) line lineV) and (analogRead(A2) line lineV))) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2) and  // right and left line
        (digitalRead(seven) == HIGH) and (slow == 1)) {
      motorStop();
      delay(50);

      for (int i = 0; i < 9; i++) {
        goBack();
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 200; i++) {
        turnR();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      delay(10);
      motorStop();
      delay(10);

      for (int i = 0; i < 90; i++) {
        turnL();

        if (((analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2) or (digitalRead(seven) == LOW)) and ((analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV) or (analogRead(A5) line lineV))) {
          motorStop();
          delay(100);
          fire();
          break;
        }
      }

      goBack100();
      delay(10);
      randRotate();
      delay(100);
    }

    //..................................................................

    // line back
    if (((analogRead(A4) line lineV) or (analogRead(A3) line lineV)) and (analogRead(backup) > backupLight) and (analogRead(backup2) > backupLight2) and  //back line
        (digitalRead(seven) == HIGH)) {
      motorStop();

      for (int i = 0; i < 15; i++) {
        goFwd();

        if (((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A5) line lineV)) and ((digitalRead(seven) == HIGH) or (analogRead(backup) < backupLight) or (analogRead(backup2) < backupLight2))) {
          motorStop();
          turnL();
          break;
        }
      }
    }

    //..................................................................

    // line cross front left and rear right
    if (((analogRead(A5) line lineV) or (analogRead(A1) line lineV)) and ((analogRead(A4) line lineV))) {
      for (int i = 0; i < 20; i++) {
        goFwd();
      }
      for (int i = 0; i < 20; i++) {
        turnR();
      }
      for (int i = 0; i < 20; i++) {
        goFwd();
      }
    }

    //..................................................................

    // line cross front right and rear left
    if (((analogRead(A0) line lineV) or (analogRead(A2) line lineV)) and (analogRead(A3) line lineV)) {
      for (int i = 0; i < 20; i++) {
        goFwd();
      }
      for (int i = 0; i < 20; i++) {
        turnR();
      }
      for (int i = 0; i < 20; i++) {
        goFwd();
      }
    }

    //...................................................................
    //  DEBUGGING  DEBUGGING  DEBIGGING  DEBUGGING  DEBUGGING  DEBUGGING
    //...................................................................

    if ((digitalRead(ultrasonic) == LOW) and ((analogRead(A0) line lineV) or (analogRead(A1) line lineV) or (analogRead(A2) line lineV) or (analogRead(A3) line lineV) or (analogRead(A4) line lineV) or (analogRead(A5) line lineV))) {
      for (int i = 0; i < 2; i++) {
        goFwd();
      }
    }

    if (((analogRead(A0) line lineV) or (analogRead(A2) line lineV)) and (analogRead(A4) line lineV)) {
      for (int i = 0; i < 54; i++) {
        goBack();
      }
      for (int i = 0; i < 4; i++) {
        turnR();
      }
    }

    if (((analogRead(A5) line lineV) or (analogRead(A1) line lineV)) and (analogRead(A3) line lineV)) {
      for (int i = 0; i < 54; i++) {
        goBack();
      }
      for (int i = 0; i < 4; i++) {
        turnL();
      }
    }

    //..............................................................................................
    //stop button
    if (digitalRead(button) == LOW) {  // STOP button
      motorStop();
      btt = 0;
      delay(1000);
    }
    //..............................................................................................


    //,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
  }  // end (if) start button
}
