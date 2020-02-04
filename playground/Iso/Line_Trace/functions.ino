#include"parameters.h"

void MoveStop(int time) {
  Serial.println("90 LEFT");
  Move(0, 0);
  delay(time);
}
void Move90L() {
  while (true) {
    MoveL();
    if (analogRead(CT) < DCT) {
      break;
    }
  }
  Serial.println("90 LEFT");
  Move(-MSL, MSR);
  delay(1300);
}
void MoveR() {
  Serial.println("RIGHT");
  Serial.println("RIGHT");
  Move(MSL, 0);
  delayMicroseconds(10);

}
void MoveL() {
  Serial.println("LEFT");
  Move(0, MSR);
  delayMicroseconds(10);
}
void MoveS() {
  Serial.println("Straight");
  Move(MSL, MSR);
  delayMicroseconds(10);
}

void Move (int Lp, int Rp) {
  if (Lp >= 0) {
    analogWrite(LF, Lp);
    analogWrite(LB, 0);
  }
  else {
    analogWrite(LF, 0);
    analogWrite(LB, -Lp);
  }
  if (Rp >= 0) {
    analogWrite(RF, Rp);
    analogWrite(RB, 0);
  }
  else {
    analogWrite(RF, 0);
    analogWrite(RB, -Rp);
  }
}
