#include <Arduino.h>

// peripheral definition
static const int LED = 13;
static const int BUTTON = 7;

// global variables

void setup()
{
  // peripheral configuration
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop()
{
  if (digitalRead(BUTTON) == HIGH) // button is not pressed
  {
    digitalWrite(LED, LOW); // turn  off the LED
  }
  else if (digitalRead(BUTTON) == LOW) // button is pressed
  {
    digitalWrite(LED, HIGH); // turn on the LED
  }
}