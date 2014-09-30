const int boardLight = 13;

const int button = 3;
const int output1 = 8;
const int output2 = 9;
const int output3 = 10;
const int output4 = 11;

const int outputs[] = {output1, output2, output3, output4};
const int outputsLength = sizeof(outputs)/sizeof(int);

const long bounce = 50; // time in milliseconds to wait
const long hold = 300; // time to wait before sending another press
long lastBounceCheck = 0; // time of last bounce check (for bouncing issues)
long lastUpdateCheck = 0; // time of last update check (for press & hold)

int buttonState = HIGH;
unsigned int counter = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(button, INPUT);
  
  for(int i = 0; i < sizeof(outputs)/sizeof(int); i++) {
    pinMode(outputs[i], OUTPUT);
  }
  oneHot(counter);
  
  pinMode(boardLight, OUTPUT);
}

void loop() {  
  // If we last checked longer than our bounce time,
  // check for the state.
  boolean updated = false;
  if(millis() - lastBounceCheck > bounce) {    
    // If state changed, update variables.
    int pressed = digitalRead(button);
    if(buttonState != pressed) {
      buttonState = pressed;
      updated = true;
    }
    
    Serial.println(counter);    
    lastBounceCheck = millis();
  }
  
  // If our new state is high, flip colors.
  if(buttonState == HIGH &&
    (updated || millis() - lastUpdateCheck > hold)) {
    ++counter;
    binary(counter);
    digitalWrite(boardLight, HIGH);
    
    lastUpdateCheck = millis();
  }
  
   delay(1);
}

// Writes the state to each light.
void oneHot(int counter) {
  for(int i = 0; i < sizeof(outputs)/sizeof(int); i++) {
    boolean state = (i == counter % 3) ? HIGH : LOW;
    digitalWrite(outputs[i], state);
  }
}

void binary(int counter) {
  int power = 1;
  for(int i = 0; i < outputsLength; i++) {
    power << 1;
    boolean state = (counter & power) ? HIGH : LOW;
    digitalWrite(outputs[i], state);
  }
}
