const int ModeSW[8]{
  52, 50, 48, 46, 44, 42, 40, 38
};
//↑mode switch
int i = 0 , h = 1;

void setup() {
  for (i = 0; i < 8; i++) {
    pinMode(ModeSW[i], INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  for (i = 0; i < 8; i++) {
    if (digitalRead(ModeSW[i]) == LOW && i != h) {
      Serial.println(i);
      h = i;
    }
  }
}
