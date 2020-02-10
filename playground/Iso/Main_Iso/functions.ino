#include "parameters.h"

void MoveStop(int time)
{
  Serial.println("STOPPING");
  Move(0, 0);
  delay(time);
}
void MoveL_UntillB()
{
  // 白になるまで旋回
  while (analogRead(CT) < DCT)
  {
    MoveL();
  }
  // 黒になるまで旋回
  while (analogRead(CT) > DCT)
  {
    Serial.println("LEFT");
    Move(-SMSL, SMSR);
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
    Serial.println(location_info);
  }
  Serial.println("Line Ditected");
}
// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 右旋回
void MoveSpinR()
{
  Serial.println("RIGHT SPIN");
  Move(MSL, -MSR);
}
void MoveSpinR2()
{
  Serial.println("RIGHT SPIN");
  Move(SMSL, -SMSR);
}
void MoveR()
{
  Serial.println("RIGHT");
  Move(MSL, 0);
}
// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 左旋回
void MoveSpinL()
{
  Serial.println("LEFT SPIN");
  Move(-MSL, MSR);
}
void MoveSpinL2()
{
  Serial.println("LEFT SPIN");
  Move(-SMSL, SMSR);
}
void MoveL()
{
  Serial.println("LEFT");
  Move(0, MSR);
}
// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// 前進
void MoveStraight()
{
  Serial.println("Straight");
  Move(MSL, MSR);
}
// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
// C
void MoveOnC()
{
  // 白になるまで旋回
  while (analogRead(CT) < DCT)
  {
    MoveSpinL();
  }
  // 黒になるまで旋回
  while (analogRead(CT) > DCT)
  {
    MoveSpinL();
  }
  Serial.println("Line Ditected");
}

void Move(int Lp, int Rp)
{
  if (Lp >= 0)
  {
    analogWrite(LF, Lp);
    analogWrite(LB, 0);
  }
  else
  {
    analogWrite(LF, 0);
    analogWrite(LB, -Lp);
  }
  if (Rp >= 0)
  {
    analogWrite(RF, Rp);
    analogWrite(RB, 0);
  }
  else
  {
    analogWrite(RF, 0);
    analogWrite(RB, -Rp);
  }
}

void RemoteControl()
{
  //Not ready yet
  // location_info++;
}

void TimeAdjust()
{
  Serial.println("Waiting...");
  while (true) {
    if (digitalRead(Timer) == LOW) {
      Serial.println("Time to go");
      return;
    }
  }
}

int SWCheck()
{
  for (i = 0; i < 8; i++)
  {
    if (digitalRead(ModeSW[i]) == LOW)
    {
      return i;
    }
  }
}
