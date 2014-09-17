const int pinLight = 3;
const int boardLight = 13;

void setup() {
  pinMode(boardLight, OUTPUT); 
  pinMode(pinLight, OUTPUT); 
}

void loop() {
  digitalWrite(boardLight, HIGH);
  analogWrite(pinLight, 50);
  delay(1000);
  digitalWrite(boardLight, LOW);
  analogWrite(pinLight, 100);
  delay(1000); 
}
