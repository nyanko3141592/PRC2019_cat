#include "parameters.h"

void setup()
{
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  Serial.begin(9600); //PC (Debug)
}

void loop()
{
  // B???B
  if (analogRead(R1) < DR1 && analogRead(L1) < DL1)
  {
    // 0.5s forward
    Serial.println("B???B");
    Move(MSL, MSR);
    delay(500);
    // B?B?B
    if (analogRead(CT) > DCT)
    { //dead end (U-turn)
      Serial.println("B?B?B");
      Move(MSL, -MSR);
      delay(2500);
    }
  }
  // ????B
  if (analogRead(R1) < DR1)
  { //turn right
    Serial.println("????B");
    Move(MSL, 0);
    delayMicroseconds(10);
  }
  // B???W
  else if (analogRead(L1) < DL1)
  {
    Serial.println("W???B");
    // BB??W
    if (analogRead(L2) < DL2)
    { //left outer sensor detected
      Serial.println("BB??W");
      Move(MSL, MSR);
      delay(200);
      // BB?WW
      if (analogRead(R2) > DR2)
      { //spin left
        Serial.println("BB?WW");
        Move(-MSL, MSR);
        delay(1250);
      }
    }
  }
  // ????W
  else
  { //turn left
    Serial.println("????W");
    Move(MSL, MSR);
    delayMicroseconds(10);
  }
}
