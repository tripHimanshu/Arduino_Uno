#include <Arduino.h>

// peripheral definition
static const int LED = 13;

// global variables
bool ledState = true; // state of LED

void setup()
{
  // peripheral configuration
  pinMode(LED, OUTPUT); // LED pin is output
}

void loop()
{
  // blink the LED
  ledState = !ledState; // toggle LED state
  digitalWrite(LED, ledState);
  delay(1000); // wait for 1 sec
}