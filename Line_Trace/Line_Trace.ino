#include"parameters.h"

void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  Serial.begin(9600);//PC (Debug)
}

void loop() {
  if (analogRead(R1) < DR1 && analogRead(L1) < DL1) {
    Move(MSL, MSR);
    delay(500);
    if (analogRead(CT) > DCT) { //dead end (U-turn)
      Move(MSL, -MSR);
      delay(2500);
    }
  }
  if (analogRead(R1) < DR1) { //turn right
    Move(MSL, 0);
    delayMicroseconds(10);
  }
  else if (analogRead(L1) < DL1) { //left sensor detected
    if (analogRead(L2) < DL2) { //left outer sensor detected
      Move(MSL, MSR);
      delay(200);
      if (analogRead(R2) > DR2) { //spin left
        Move(-MSL, MSR);
        delay(1250);
      }
    }
    else { //turn left
      Move(0, MSR);
      delayMicroseconds(10);
    }
  }
  else { //fwdstr
    Move(MSL, MSR);
    delayMicroseconds(50);
  }
}
