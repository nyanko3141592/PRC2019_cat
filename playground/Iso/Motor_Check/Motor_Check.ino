const int LF = 10;
const int LB = 11;
const int RF = 12;
const int RB = 13;
const int MS = 100;

void Move (int Lp, int Rp);

void setup() {
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Move(MS,0);
  Serial.println("LF");
  delay(3000);
  Move(0,MS);
  Serial.println("RF");
  delay(3000);
  Move(-MS,0);
  Serial.println("LB");
  delay(3000);
  Move(0,-MS);
  Serial.println("RB");
  delay(3000);
  Move(MS,MS);
  Serial.println("FW");
  delay(3000);
  Move(-MS,-MS);
  Serial.println("BW");
  delay(3000);
  Move(MS,-MS);
  Serial.println("LS");
  delay(3000);
  Move(-MS,MS);
  Serial.println("RS");
  delay(3000);
}

void Move (int Lp, int Rp) {
  if (Lp >= 0) {
    analogWrite(LF, Lp);
    analogWrite(LB, 0);
  }
  else {
    analogWrite(LF, 0);
    analogWrite(LB, -Lp);
  }
  if (Rp >= 0) {
    analogWrite(RF, Rp);
    analogWrite(RB, 0);
  }
  else {
    analogWrite(RF, 0);
    analogWrite(RB, -Rp);
  }
}
