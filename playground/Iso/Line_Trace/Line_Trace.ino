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
  int sum_black = 5;
  const bool R1_black = analogRead(R1) < DR1;
  const bool R2_black = analogRead(R2) < DR2;
  const bool CT_black = analogRead(CT) < DCT;
  const bool L1_black = analogRead(L2) < DL2;
  const bool L2_black = analogRead(L1) < DL1;
  sum_black = R1_black ? sum_black : sum_black - 1;
  sum_black = R2_black ? sum_black : sum_black - 1;
  sum_black = CT_black ? sum_black : sum_black - 1;
  sum_black = L2_black ? sum_black : sum_black - 1;
  sum_black = L1_black ? sum_black : sum_black - 1;
  Serial.print(L1_black);
  Serial.print(L2_black);
  Serial.print(CT_black);
  Serial.print(R2_black);
  Serial.print(R1_black);
  Serial.print(" ");
  Serial.print(sum_black);
  Serial.print(" ");

  if (sum_black <= 2) {
    if (CT_black) {
      MoveS();
    }
    else {
      if ((R1_black || R2_black) && (L1_black || L2_black) ) {
        Move(0, 0);
      }
      else {
        if (R1_black || R2_black) {
          MoveR();
        }
        else if (L1_black || L2_black) {
          MoveL();
        }
        else {
          MoveS();
        }
      }
    }
  }
  /*else{
      if(L1_black && L2_black){
          MoveL();
      }
    }*/
}
