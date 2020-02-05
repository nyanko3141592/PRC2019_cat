#include"parameters.h"

void MoveStop(int time) {
  Serial.println("90 LEFT");
  Move(0, 0);
  delay(time);
}
void Move90L() {
  while (true) {
    MoveLS();
    if (analogRead(CT) < DCT) {
      break;
    }
    Serial.println("Line Ditected");
  }
}
void MoveRS() {
  Serial.println("RIGHT SPIN");
  Move(MSL, -MSR);
  delayMicroseconds(10);
}
void MoveR() {
  Serial.println("RIGHT");
  Move(MSL, 0);
  delayMicroseconds(10);
  //Move(MSL,-MSR);
}
void MoveLS() {
  Serial.println("LEFT SPIN");
  Move(-MSL, MSR);
  delayMicroseconds(10);
}
void MoveL() {
  Serial.println("LEFT");
  Move(0, MSR);
  delayMicroseconds(10);
  //Move(-MSL,MSR);  
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

int SWCheck() {
  for (i = 0; i < 8; i++) {
    if (digitalRead(ModeSW[i]) == LOW) {
      return i;
    }
  }
}

int RemoteControl() {
  //Not ready yet
  location_info++;
}

int TimeAdjust() {
  Serial.print("2");
  while (true) {
    if (Serial2.read() == 1) {
      break;
    }
  }
}
