#include"parameters.h"

/*
  location_info
  0:before start line
  1: Start→A
  2: A→B(RemoteControl)
  3: B→C
  4: C(Before U-turn)
  5: C(After U-turn)
  6: C→A
  7: A→Goal
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
  Serial2.write("1");
}

void loop() {
    int sum_black = 5; 
    const bool R1_black = analogRead(R1) < DR1;
    const bool R2_black = analogRead(R2) < DR2;
    const bool CT_black = analogRead(CT) < DCT;
    const bool L1_black = analogRead(L2) < DL2;
    const bool L2_black = analogRead(L1) < DL1;
    sum_black = R1_black ? sum_black : sum_black-1;
    sum_black = R2_black ? sum_black : sum_black-1;
    sum_black = CT_black ? sum_black : sum_black-1;
    sum_black = L2_black ? sum_black : sum_black-1;
    sum_black = L1_black ? sum_black : sum_black-1;
    Serial.print(L1_black);
    Serial.print(L2_black);
    Serial.print(CT_black);
    Serial.print(R2_black);
    Serial.print(R1_black);
    Serial.print(" ");
    Serial.print(sum_black);
    Serial.print(" ");
    Serial.println(location_info);

    if (sum_black <= 2){
        if (CT_black){
            MoveS();
        }
        else
        {
            if ((R1_black || R2_black) && (L1_black || L2_black) ){
                Move(0, 0);
            }
            else
            {
                if (R1_black || R2_black)
                {
                    MoveR();
                }
                else if (L1_black || L2_black) 
                {
                    MoveL();
                }
                else 
                {
                    MoveS();
                }
            }
        }
        flag = true;
    }
    else
    {
        Serial.print("==================================================================");
        Serial.println(flag);
        switch (location_info) {
            // start line
            case 0:

            // point A
            case 1:
                MoveStop(5000);
                break;
            //  point B
            case 2:
            // すこし前進して一回転
                MoveS():
                delay(1000)
                Move90L();
                Move90L();
                break;
            // point C path
            case 3:
                Move90L();
                break;
            // point C
            case 4:
                Move90L();
                break;
            // point C path again
            case 5:
                Move90L();
                break;
            // point A again
            case 6:
                MoveStop(5000);
                break;
            default:
                MoveStop(5000);
        }
        if (flag)
        {
            location_info += 1; 
            flag = false;
        }

    }

}
