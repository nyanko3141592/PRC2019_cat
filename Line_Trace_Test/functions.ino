#include"parameters.h"

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
//↑New code. Not tested yet.

/*void Move (int Lp, int Rp) {
  if (Lp >= 0 && Rp >= 0) {
    analogWrite(LF, Lp);
    analogWrite(LB, 0);
    analogWrite(RF, Rp);
    analogWrite(RB, 0);
  }
  else if (Lp < 0 && Rp > 0) {
    analogWrite(LF, 0);
    analogWrite(LB, -Lp);
    analogWrite(RF, Rp);
    analogWrite(RB, 0);
  }
  else if (Lp > 0 && Rp < 0) {
    analogWrite(LF, Lp);
    analogWrite(LB, 0);
    analogWrite(RF, 0);
    analogWrite(RB, -Rp);
  }
  else {
    analogWrite(LF, 0);
    analogWrite(LB, -Lp);
    analogWrite(RF, 0);
    analogWrite(RB, -Rp);
  }
}*/
//Original code. Use if new one fails.