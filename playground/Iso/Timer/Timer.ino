#include<SoftwareSerial.h>
unsigned long t_start;
unsigned long t_now;
unsigned long t_dur;
const int Trig = 2;
void setup() {
  Serial.begin(9600);//PC (Debug)
  pinMode(Trig, OUTPUT);
  t_start == millis();
}

void loop() {
  t_now = millis();
  t_dur = (t_now - t_start);
  if (t_dur > 120 * 1000) { //time to go
    digitalWrite(Trig, HIGH);
  }
}
