#include <Arduino.h>
#include <ezButton.h>

// create ezButton object that attach with pin 7
ezButton button(7);
// Configure peripherals
static const int LED = 13;
// global variables
unsigned long lastPress = 0;
int count;
bool ledState = false;

void setup()
{
  // configure serial
  Serial.begin(9600);
  // configure button (peripheral)
  button.setDebounceTime(50);
  button.setCountMode(COUNT_FALLING);
  // configure LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, ledState);
}

void loop()
{
  // must call the loop function first
  button.loop();

  if (button.isPressed())
  {
    lastPress = millis();
    count++;
  }
  if (count > 0 && (millis() - lastPress) > 1000)
  {
    switch (count)
    {
    case 1:
      ledState = !ledState;
      digitalWrite(LED, ledState);
      Serial.print("Count = ");
      Serial.println(count);
      count = 0;
      break;
    case 2:
      for (int i = 0; i < 5; i++)
      {
        ledState = !ledState;
        digitalWrite(LED, ledState);
        delay(500);
      }
      Serial.print("count = ");
      Serial.println(count);
      count = 0;
      break;
    default:
      Serial.println("Default case");
      count = 0;
      break;
    }
  }
  // control the LED according to the button press
}