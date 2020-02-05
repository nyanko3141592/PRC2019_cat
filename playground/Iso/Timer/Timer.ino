unsigned long t_start;
unsigned long t_now;
unsigned long t_dur;
int Serin;
int flag = 0;
void setup() {
  Serial.begin(9600);//PC (Debug)
  //Serial1.begin(9600);//Main Arduino
}

void loop() {
  Serin = Serial.read();
  if(Serin == 1 + 48){// srart countup
    t_start = millis();
    //Serial.println("Timer Started");
  }
  else if(Serin == 2 + 48){//machine arrived at A
    //Serial.println("waiting...");
    while(flag == 0){
      t_now = millis();
      t_dur = (t_now-t_start);
      if(t_dur > 30*1000){//time to go
        Serial.print("1");
        flag = 1;
      }
    }

  }  
}
