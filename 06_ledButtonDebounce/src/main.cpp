#include <Arduino.h>

// peripheral definition
static const int LED = 13;
static const int BUTTON = 7;

// global variables
int ledState = HIGH;
int buttonState;
int lastButtonState = HIGH;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup()
{
  // peripheral configuration
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  // set initial led state
  digitalWrite(LED, ledState);
}

void loop()
{
  // read the button state
  int reading = digitalRead(BUTTON);
  // check if we just pressed the button (HIGH to LOW)
  if (reading != lastButtonState)
  {
    // reset the debounce timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      // toggle the LED if new buttonState is LOW
      if (buttonState == LOW)
      {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(LED, ledState);
  lastButtonState = reading;
}