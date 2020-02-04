const int ModeSW[8]{
  14,15,16,17,18,19,20,21
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
