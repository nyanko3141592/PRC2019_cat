#include<Servo.h>
Servo myServo1;
Servo myServo2;
unsigned long t_start;
unsigned long t_now;
unsigned long t_dur;
const int Trig = 14;
void setup() {
  Serial.begin(9600);//PC (Debug)
  pinMode(Trig, OUTPUT);
  t_start = millis();
  Serial.begin(9600);
  digitalWrite(Trig, HIGH);
  myServo1.attach(7);
  myServo2.attach(8);
}

void loop() {
  t_now = millis();
  t_dur = (t_now - t_start) / 1000;
  Serial.println(t_dur);
  if (t_dur > 130) { //time to go
    digitalWrite(Trig, LOW);
    Serial.println("Time to go");
  } else {
    digitalWrite(Trig, HIGH);
    Serial.println("not go");
  }
  if (t_dur % 4 == 0) {
    myServo1.write(90);
    myServo2.write(90);
    Serial.println("Right Up");
  }
  else if (t_dur % 4 == 2) {
    myServo1.write(0);
    myServo2.write(0);
    Serial.println("Left Up");
  }
}
