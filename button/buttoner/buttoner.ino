const int boardLight = 13;

const int button = 4;
const int output1 = 10;
const int output2 = 11;
const int output3 = 12;

const int outputs[] = {output1, output2, output3};

int pressed = 1;
boolean lit = false;

void setup() {
//  Serial.begin(9600);
  
  pinMode(button, INPUT);
  
  for(int i = 0; i < sizeof(outputs)/sizeof(int); i++) {
    pinMode(outputs[i], OUTPUT);
    digitalWrite(outputs[i], HIGH);
  }
  
  pinMode(boardLight, OUTPUT);
}

void loop() {
  int oldPressed = pressed;
  pressed = digitalRead(button);
  
  if(pressed == 1) {
    lit = !lit;
    for(int i = 0; i < sizeof(outputs)/sizeof(int); i++) {
      pinMode(outputs[i], OUTPUT);
      digitalWrite(outputs[i], lit);
    }
  
  }
  
   delay(1);
}
