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
  while (analogRead(L2) < DL2)
  {
    MoveL();
  }
  // 黒になるまで旋回
  while (analogRead(L2) > DL2)
  {
    MoveL();
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
void MoveL()
{
  Serial.println("LEFT");
  Move(0, MSR);
<<<<<<< HEAD
  delayMicroseconds(10);
  //Move(-MSL,MSR);
=======
>>>>>>> 890a12c4843f6aeb0894b9bbf5ba5f5d3806bdea
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

int RemoteControl()
{
  //Not ready yet
  // location_info++;
}

<<<<<<< HEAD
void TimeAdjust() {
  Serial.print("2");
  while (true) {
    if (digitalRead(Trig) == HIGH) {
      return;
=======
int TimeAdjust()
{
  Serial.print("2");
  while (true)
  {
    if (Serial2.read() == 1)
    {
      break;
>>>>>>> 890a12c4843f6aeb0894b9bbf5ba5f5d3806bdea
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