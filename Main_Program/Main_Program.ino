#include"parameters.h"

/*
Mode and zones
mode 1: Start→A
mode 2: A→B(RemoteControl)
mode 3: B→C
mode 4: C(Before U-turn)
mode 5: C(After U-turn)
mode 6: C→A
mode 7: A→Goal
*/
void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(ModeSW_11, INPUT_PULLUP);
  pinMode(ModeSW_12, INPUT_PULLUP);
  pinMode(ModeSW_21, INPUT_PULLUP);
  pinMode(ModeSW_22, INPUT_PULLUP);
  Serial.begin(9600);//PC (Debug)
  Serial1.begin(9600);//ESP (Wireless)
  Serial2.begin(9600);//sub Arduino (Timer)
  mode = SWCheck();
  Serial2.write("1")
}

void loop() {
  switch(mode){
    case 2:
      RemoteControl();
      break;
    case 7:
      TimeAdjust();
      break;
    default:
      break;
  }
  if (analogRead(R1) < DR1 && analogRead(L1) < DL1 && mode == 4){
    Move(MSL,-MSR);
    delay(2500);
    mode++;
  }
  if (analogRead(R1) < DR1) { //right sensor detected
    if (analogRead(R2) < DR2) { //right outer sensor deteced
      mode++;
    }
    else { //fwdlft1
      Move(MSL, 0);
      delayMicroseconds(10);
    }
  }
  else if (analogRead(L1) < DL1) { //left sensor detected
    if (analogRead(L2) < DL2) { //left outer sensor detected
      if(mode==3){
        Move(-MSL, MSR);
        delay(1250);
        mode++;
      }
    }
    else { //fwdrgt1
      Move(0, MSR);
      delayMicroseconds(10);
    }
  }
  else { //fwdstr
    Move(MSL, MSR);    
    delayMicroseconds(50);
  }
}