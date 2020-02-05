const int R2 = A0;
const int R1 = A1;
const int CT = A2;
const int L1 = A3;
const int L2 = A4;
void setup(){
    Serial.begin(9600);
}

void loop(){
    Serial.print(analogRead(A0));
    Serial.print(",");
    Serial.print(analogRead(A1));
    Serial.print(",");
    Serial.print(analogRead(A2));
    Serial.print(",");
    Serial.print(analogRead(A3));
    Serial.print(",");
    Serial.print(analogRead(A4));
    Serial.println("");
}