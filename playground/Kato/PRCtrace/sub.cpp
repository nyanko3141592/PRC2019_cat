//
// Created by 加藤英祐 on 2020/02/01.
//

#include "sub.h"

extern const int photo[5] = {0,1,2,3,4};
extern const int motorL[2] = {10,11};
extern const int motorR[2] = {12,13};

extern int move(int speedL, int speedR){
    moveL(speedL);
    moveR(speedR);
}

extern int moveL(int speed){
    if(speed > 0) {
        analogWrite(motorL[0], speed);
        analogWrite(motorL[1], 0);
    } else if(speed == 0) {
        analogWrite(motorL[0], 0);
        analogWrite(motorL[1], 0);
    } else if (speed < 0){
        analogWrite(motorL[0], 0);
        analogWrite(motorL[1], -speed);
    }
}

extern int moveR(int speed){
    if(speed > 0) {
        analogWrite(motorR[0], speed);
        analogWrite(motorR[1], 0);
    } else if(speed == 0) {
        analogWrite(motorR[0], 0);
        analogWrite(motorR[1], 0);
    } else if (speed < 0){
        analogWrite(motorR[0], );
        analogWrite(motorR[1], -speed);
    }
}