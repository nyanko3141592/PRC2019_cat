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

int location_info = 0;
bool flag = true ;

void Move (int Lp, int Rp);

void setup() {
    pinMode(RF, OUTPUT);
    pinMode(RB, OUTPUT);
    pinMode(LF, OUTPUT);
    pinMode(LB, OUTPUT);
    Serial.begin(9600); //PC (Debug)    
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
        Serial.print("else=================================");
        Serial.println(flag);
        if (flag)
        {
            Move(0, 0);
            delay(5);
            location_info += 1; 
            flag = false;
        }

    }

}
void MoveR(){
    Serial.println("RIGHT");
    Move(MSL, 0);
    delayMicroseconds(10);

}
void MoveL(){
    Serial.println("LEFT");
    Move(0, MSR);
    delayMicroseconds(10);
}
void MoveS(){
    Serial.println("Straight");
    Move(MSL, MSR);
    delayMicroseconds(10);
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
  }
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
