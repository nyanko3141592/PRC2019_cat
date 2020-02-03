//
// Created by 加藤英祐 on 2020/02/01.
//

#ifndef PRCTRACE_SUB_H
#define PRCTRACE_SUB_H

#include <Arduino.h>

extern const int photo[5];
extern const int motorL[2];
extern const int motorR[2];

extern int move(int speedL, int speedR);
extern int moveL(int speed);
extern int moveR(int speed);

#endif //PRCTRACE_SUB_H
