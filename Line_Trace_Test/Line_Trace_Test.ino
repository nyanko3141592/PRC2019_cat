const int R2 = A0;
const int R1 = A1;
const int CT = A2;
const int L1 = A3;
const int L2 = A4;
//↑photo sensors
const int LF = 10;
const int LB = 11;
const int RF = 12;
const int RB = 13;
//↑motors
const int DR2 = 400;
const int DR1 = 400;
const int DCT = 400;
const int DL1 = 400;
const int DL2 = 400;
//↑default photo ensor values
//const int SMSL = 100;
//const int SMSR = 100;
const int MSL = 100;
const int MSR = 100;
//↑motor speed

void Move (int Lp, int Rp);

void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
}

void loop() {
  if (analogRead(R1) < DR1) {
    Move(MSL, 0);
    delayMicroseconds(10);
  }
  else if (analogRead(L1) < DL1) {
    Move(0, MSR);
    delayMicroseconds(10);
  }
  else { //fwdstr
    Move(MSL, MSR);
    delayMicroseconds(50);
  }
}

void Move (int Lp, int Rp) {
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
}

/*void Move (int Lp, int Rp) {
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
  }*/
