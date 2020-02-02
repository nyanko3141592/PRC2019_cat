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

int SWCheck(){
  if(digitalRead(ModeSW_11)==HIGH){
    if(digitalRead(ModeSW_21)==HIGH){
      return 1;
    }
    else if(digitalRead(ModeSW_22)==HIGH){
      return 2;
    }
    else{
      return 3;
    }
  }
  else if(digitalRead(ModeSW_12)==HIGH){
    if(digitalRead(ModeSW_21)==HIGH){
      return 4;
    }
    if(digitalRead(ModeSW_22)==HIGH){
      return 5;
    }
    else{
      return 6;
    }
  }
  else{
    return 7;
  }
}

int RemoteControl(){
  //Not ready yet
  mode++;
}

int TimeAdjust(){
  Serial.print("2");
  while(true){
    if(Serial2.read()==1){
      break;
    }
  }
}