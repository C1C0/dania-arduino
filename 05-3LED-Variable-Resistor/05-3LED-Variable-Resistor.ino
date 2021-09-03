/*
  Created By: Kristian Palovic
*/

/*
   const int POT1 pin for one potentiometer
*/
const int POT1 = A0;

/*
   @variable int[] LEDS specifies pins that are LEDs attached to
   IN THIS CASE ONLY PWM PINS
*/
const int LEDS [] = {3, 5, 6};

/*
   @variable int NumberOfLeds
*/
const int NumberOfLeds = sizeof(LEDS) / sizeof(int);

/*
  @variable float MaximumAnalogInput input for default Ax PIN should
  range from 0 - 1023
*/
const float MaximumAnalogInput = 1023;

/*
   @variable float[] LEDsBreakPoints specifies breakpoint (when should LED light up) for each LED
   Paired by index position
   LEDsBreakPoints[0] is breakpoint for LEDS[0], etc ...
*/
float LEDsBreakPoints [NumberOfLeds];

void setup() {
  // initialize serial communication:
  Serial.begin(9600);

  // Tell the arduino what to do on certain pins
  for (int i = 0; i < NumberOfLeds; i++) {
    pinMode(LEDS[i], INPUT);
  }

  initializeLEDs(100, 5);
}

void loop() {
  // Decides which LED to light up
  lightingBasedOnPot(NumberOfLeds, analogRead(POT1));
}

/*
   Decides, which LED should / shouln't be switched on

   @param int numberOfLeds number of LEDs
   @param int analogInput value of analog input
*/
void lightingBasedOnPot(int numberOfLeds, float analogInput) {

// TODO:
  for (int i = 0; i < numberOfLeds; i++) {
    if (analogInput >= LEDsBreakPoints[i]) {
      digitalWrite(LEDS[i], HIGH);
    } else if (analogInput > LEDsBreakPoints[i - 1]) {

      int mapped = map(analogInput, 0, 1024, 0, 200);
      analogWrite(LEDS[i], mapped);
    } else {
      digitalWrite(LEDS[i], LOW);
    }
  }

}

/**
   Initializes LED - lights them up and turns them off

   @param int delay the delay between blink
   @param int repeat how many times should LEDs blink
*/
void initializeLEDs(int delayTime, int repeat) {
  const float breakPointMaxValue = MaximumAnalogInput / NumberOfLeds;

  // initialize to see, if all light up
  for (int i = 0; i < repeat; i++) {
    Serial.println(i);
    for (int j = 0; j < NumberOfLeds; j++) {
      digitalWrite(LEDS[j], HIGH);
    }

    delay(delayTime);

    for (int j = 0; j < NumberOfLeds; j++) {
      digitalWrite(LEDS[j], LOW);
    }

    delay(delayTime);
  }

  // min break point to light up another LED
  Serial.print("Number of LEDS: ");
  Serial.println(NumberOfLeds);

  for (int i = 0; i < NumberOfLeds; i++) {
    LEDsBreakPoints[i] = breakPointMaxValue * (i + 1);

    Serial.println(LEDsBreakPoints[i]);
  }
}
