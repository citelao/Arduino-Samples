const int thermistorpin = 2;

const int SAMPLES = 5;

const double kelvin = 273.15;
const double resistor = 1000;
const double b = 4000; // est
const double t0 = 25;
const double thermistorbase = 4700;

void setup() {
  analogReference(EXTERNAL);
  
  Serial.begin(9600);
}

void loop() {
  double sum = 0;
  for(int i = 0; i < SAMPLES; i++) {
    sum += analogRead(thermistorpin);
    delay(10);
  }
  double avg = sum / SAMPLES;
  
  double resistance = resistor / ((1023.0 / avg) - 1.0);
  
  double rinf = thermistorbase * exp(- b / (t0 + kelvin));
  double temp = b / log(resistance / rinf) - kelvin;
  
  Serial.print("ADC: ");
  Serial.print(avg);
  
  Serial.print("; Resistance: ");
  Serial.print(resistance);
  
  Serial.print("; temp: ");
  Serial.println(temp);  
  
}
