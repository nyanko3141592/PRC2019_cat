const int Trig = A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(Trig) == HIGH) {
    Serial.print("Time to go");
    while (true) {}
  }
}
