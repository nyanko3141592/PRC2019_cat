#include <Servo.h>
const int servoa = 11;
const int trig = A1;
const int echo = A2;
int a=0;
Servo servoA;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(A3, INPUT);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,OUTPUT);
  servoA.attach(servoa);
  servoA.write(175);
}

void loop() {
  // put your main code here, to run repeatedly;
  int readtime = 0;
  double dis = 0;
  digitalWrite(trig, HIGH);
  delayMicroseconds(50);
  digitalWrite(trig, LOW);
  readtime = pulseIn(echo, HIGH, 30000) / 2.0;
  dis = readtime * 340.29 * 100 / 1000000;
  Serial.print("dis");
  Serial.print(dis);
  Serial.println("cm");
  digitalWrite(4,LOW);
  if(digitalRead(3)==LOW){//３ピンに電流が流れていたら
    if(dis>10){
      a=0;
    }
     if (dis <10) {  // 距離が５センチ以下の時に
        a++;
        if(a<5){
          delay(500);
        }
        if(a==5){
          Serial.print("servo ON");
          digitalWrite(4,HIGH);
          delay(50);//０.０５秒の動作確認
          digitalWrite(4,LOW);
          delay(5000);//５秒待つ
          digitalWrite(4,HIGH);
          delay(5000);//クラッカーを鳴らす    
          servoA.write(80);//ハリボテを倒す
       }
   }
  }
}
