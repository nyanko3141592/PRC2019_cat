unsigned long t_start;
unsigned long t_now;
unsigned long t_dur;
int Serin;
int flag = 0;
void setup() {
  Serial.begin(9600);//PC (Debug)
  Serial1.begin(9600);//Timer Arduino
  Serial1.print("1");
}

void loop() {
  Serin = Serial.read();
  if(Serin == 1 + 48){
    Serial1.print("1");
    Serial.println("Timer Started");
  }
  else if(Serin == 2 + 48){
    Serial1.print("2");
    Serial.println("waiting...");
    while (flag == 0) {
      if (Serial1.read() == 1 + 48) {
      Serial.println("Time to go");
      flag = 1;
      }
    }
  }
}
