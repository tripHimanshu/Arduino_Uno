#include <Arduino.h>

// peripheral definition
static const int LED = 13;
static const int BUTTON = 7;

// global variables (states)
int buttonState = HIGH;
int ledState = -1;

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 500;  // the debounce time, increase the time if LED ficker

void setup()
{
  // peripheral configuration
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  // put LED into default state
  digitalWrite(LED, ledState);
}

void loop()
{
  // sample the state of button (pressed or not)
  buttonState = digitalRead(BUTTON);
  // filter out any noise by setting a time buffer
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    // if button is pressed, toggle the state of LED
    if (buttonState == LOW && ledState < 0)
    {
      digitalWrite(LED, HIGH); // turn on the LED
      ledState = -ledState;
      lastDebounceTime = millis(); // set the current time
    }
    else if (buttonState == LOW && ledState > 0)
    {
      digitalWrite(LED, LOW);
      ledState = -ledState;
      lastDebounceTime = millis(); // set the current time
    }
  }
}