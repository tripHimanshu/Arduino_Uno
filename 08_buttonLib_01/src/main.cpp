#include <Arduino.h>
#include <ezButton.h>

// create ezButton object that attach to pin 7
ezButton button(7);
// peripheral definition
static const int LED = 13;
bool ledState = false; // default LED state

void setup()
{
  // configure serial
  Serial.begin(9600);
  // configure peripherals
  pinMode(LED, OUTPUT);
  button.setDebounceTime(50);
  digitalWrite(LED, ledState); // put LED into default state
}

void loop()
{
  // must call the loop function first
  button.loop();
  // perform action on button press event, toggle the LED
  if (button.isPressed())
  {
    Serial.println("button is pressed");
    ledState = !ledState; // toggle LED state
    digitalWrite(LED, ledState);
    Serial.println("LED is toggled");
  }
}
