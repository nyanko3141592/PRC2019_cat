#pragma once

const int R2 = A0;
const int R1 = A1;
const int CT = A2;
const int L1 = A3;
const int L2 = A4;
//↑photo sensors
const int Timer = 53;

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

const int SMSL = 100;
const int SMSR = 100;
const int MSL = 200;
const int MSR = 200;
//↑motor speed

const int ModeSW[8] {
  52, 50, 48, 46, 44, 42, 40, 38
};
//↑mode select switches(14~21)

int location_info = 0;
//↑mode selection

bool flag = true;
int i;