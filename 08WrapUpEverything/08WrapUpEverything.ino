/*
  Created By Kristian Palovic and Radek Strouf
*/

// LEDS
int LED[] = {5, 6};
const int ledLength = sizeof(LED) / sizeof(int);
const int howManyTimesToTestLEDS = 3;

// RELAY
int relay = 2;

// LCD Display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int screenChange = HIGH;

// BUTTON
int button1 = 8;
int buttonState = LOW;           // the current reading from the input pin
int lastButtonState = LOW; // the previous reading from the input pin
int operatingButtonState = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

// Boiler settings - s
int timerSeconds = 10;
unsigned long boilerInitTime = 0;
int boilerState = LOW;

LiquidCrystal_I2C LCD(0x27, 20, 4); // set the LCD address to 0x27 for a 20 chars and 4 line display

void setup()
{
  initializeThingies();
  digitalWrite(LED[1], HIGH);
}

void loop()
{
  // Check the button for clicks
  // if click occurs, change overall state
  checkButtonClick();


  if ((boilerInitTime <= 0 || boilerState == LOW) && operatingButtonState == HIGH) {
    startBoilerTimer();
    operatingButtonState = LOW;
    digitalWrite(relay, HIGH);
    digitalWrite(LED[0], HIGH);
    digitalWrite(LED[1], LOW);
    screenChange = HIGH;
  } else {
    if (boilersTimeUp() && boilerState == HIGH) {
      stopBoilerTimer();
      digitalWrite(relay, LOW);
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], HIGH);
      screenChange = HIGH;
    }
  }

  if (screenChange == HIGH) {
    LCD.clear();
    screenChange = LOW;
  }


  LCD.setCursor(0, 0);
  if (boilerState == HIGH) {
    LCD.print("Secs rest: ");
    LCD.print(checkTimeLeftForBoiler());
  } else {
    LCD.print("Press the button to start boiler.");
  }


}

void initializeThingies()
{
  Serial.begin(9600);

  // Initialize LEDS
  for (int i = 0; i < ledLength; i++)
  {
    pinMode(LED[i], OUTPUT);
  }

  // TEST LEDS
  blinkAllLeds(100);

  // TEST RELAY
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
  delay(500);
  digitalWrite(relay, LOW);

  // TEST LCD
  LCD.init();
  LCD.backlight();
  LCD.setCursor(4, 2);
  LCD.print("SYSTEM SETUP");
  delay(500);
  LCD.print(".");
  delay(500);
  LCD.print(".");
  delay(500);
  LCD.print(".");
  delay(500);
  LCD.clear();
  LCD.setCursor(4, 2);
  LCD.print("System ready");

  // BUTTON INIT
  pinMode(button1, INPUT);
}

void blinkAllLeds(int durationMs)
{
  for (int i = 0; i < howManyTimesToTestLEDS; i++)
  {
    // light every LED UP
    for (int i = 0; i < ledLength; i++)
    {
      digitalWrite(LED[i], HIGH);
    }

    delay(durationMs);

    // light every LED down
    for (int i = 0; i < ledLength; i++)
    {
      digitalWrite(LED[i], LOW);
    }

    delay(durationMs);
  }
}

void checkButtonClick()
{
  // read the state of the switch into a local variable:
  int reading = digitalRead(button1);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState)
  {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState)
    {
      buttonState = reading;
      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH)
      {
        operatingButtonState = !operatingButtonState;
      }
    }
  }

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}

void startBoilerTimer() {
  boilerInitTime = millis();
  boilerState = HIGH;
}

boolean boilersTimeUp() {
  if (boilerInitTime + timerSeconds * 1000 < millis()) {
    return true;
  }

  return false;
}

void stopBoilerTimer() {
  boilerInitTime = 0;
  boilerState = LOW;
}

int checkTimeLeftForBoiler() {
  if (boilerState == HIGH && boilerInitTime > 0) {
    unsigned long timeLeft = ((boilerInitTime + timerSeconds * 1000) - millis()) / 1000;
    return timeLeft >= 0 ? timeLeft : 0;
  }

  return 0;
}
