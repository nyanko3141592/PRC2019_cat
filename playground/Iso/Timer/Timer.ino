unsigned long t_start;
unsigned long t_now;
unsigned long t_dur;
const int Trig = 14;
void setup() {
  Serial.begin(9600);//PC (Debug)
  pinMode(Trig, OUTPUT);
  t_start = millis();
  Serial.begin(9600);
  digitalWrite(Trig,HIGH);
}

void loop() {
  t_now = millis();
  t_dur = (t_now - t_start)/1000;
  Serial.println(t_dur);
  if (t_dur > 120) { //time to go
    digitalWrite(Trig, LOW);
    Serial.println("Time to go");
  }else{
    digitalWrite(Trig, HIGH);
    Serial.println("not go");    
  }
}
