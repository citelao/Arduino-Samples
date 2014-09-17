const int boardLight = 13;

const int button = 4;
const int output1 = 10;
const int output2 = 11;
const int output3 = 12;

const int outputs[] = {output1, output2, output3};

const long bounce = 50; // time in milliseconds to wait
long lastCheck = 0;

int buttonState = HIGH;
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
  // If we last checked longer than our bounce time,
  // check for the state.
  if(millis() - lastCheck > bounce) {
    lastCheck = millis();
    
    // If state changed, update variables.
    int pressed = digitalRead(button);
    if(buttonState != pressed) {
      buttonState = pressed;
      
      // If our new state is high, flip colors.
      if(buttonState == HIGH) {
        lit = !lit;
        updateLights(lit);
      }
    }
  }
  
   delay(1);
}

// Writes the state to each light.
void updateLights(int state) {
  for(int i = 0; i < sizeof(outputs)/sizeof(int); i++) {
    pinMode(outputs[i], OUTPUT);
    digitalWrite(outputs[i], state);
  }
}
