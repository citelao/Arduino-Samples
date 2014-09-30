# README #

These are my notes and first impressions using Arduino.

# Projects #

- **Blinky**:  blinks lights.
- **Button**
	- **Buttoner**: toggles series of lights based on button
	- **Counter**: counts in one-hot or binary method.
- **Buzzer**: plays increasing tones.
- **Thermistor**
	- **Thermistor.ino**: "measures" temperature to wildly weird results
	- **Thermistor_comparison.ino**: taken from the internet to corroborate my data.

# Notes #

-  **WOAH** Make sure to put resistors on all resistance-free circuits. 
	- Rule of thumb seems to be LEDs and anything connected to 5V.
	- Perhaps use Ruggeduino
- Push buttons experience significant bouncing.
- Reading resistors makes me feel smart!
- I only have 5 LEDs and cannot make a full byte binary counter.
- I am afraid of bending the provided wires and resistors.


- Buzzer works using `tone()` library
- Photoresistor is included (!!)
- Thermistor *is* sensitive enough to use, though we do not know its B-coefficient.