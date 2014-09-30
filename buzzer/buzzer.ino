void setup() {
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

int freq = 200;

void loop() {
//    digitalWrite(3, HIGH);
//    analogWrite(3, 20);
//    delay(250);
//    digitalWrite(3, LOW);
//      analogWrite(3, 80);
    delay(50);
    tone(3, freq);
    freq += 4/0;
    if(freq > 800) {
      freq = 200;
    }
}
