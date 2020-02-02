#include "parameters.h"

void setup()
{
    pinMode(RF, OUTPUT);
    pinMode(RB, OUTPUT);
    pinMode(LF, OUTPUT);
    pinMode(LB, OUTPUT);
    Serial.begin(9600); //PC (Debug)
}

void loop()
{
    // When B???B
    if (analogRead(R1) < DR1 && analogRead(L1) < DL1)
    {
        // When B?B?B
        if (analogRead(CT) > DCT)
        { //dead end (U-turn)
            Serial.println("B?B?B");
            Move(MSL, -MSR);
            delay(2500);
        }
        else
        {
            Serial.println("B???B");
            Move(MSL, MSR);
            delay(500);
        }
    }
    if (analogRead(R1) < DR1)
    { //turn right
        Serial.println("????B");
        Move(MSL, 0);
        delayMicroseconds(10);
    }
    else if (analogRead(L1) < DL1)
    { //left sensor detected
        Serial.println("B???W");
        if (analogRead(L2) < DL2)
        {
            if (analogRead(R2) > DR2)
            { //spin left
                Serial.println("B??WW");
                Move(-MSL, MSR);
                delay(1250);
            }
            else
            {
                //left outer sensor detected
                Serial.println("BB??W");
                Move(MSL, MSR);
                delay(200);
            }
        }
        else
        { //turn left

            Move(0, MSR);
            delayMicroseconds(10);
        }
    }
    else
    { //fwdstr
        Serial.println("B???B");
        Move(MSL, MSR);
        delayMicroseconds(50);
    }
}
