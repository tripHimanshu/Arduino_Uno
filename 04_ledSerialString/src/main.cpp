#include <Arduino.h>

// peripheral definitions
static const int LED = 13;

// global variables
bool ledState = true;

void setup()
{
  // peripheral configuration
  pinMode(LED, OUTPUT);
  // serial configuration
  Serial.begin(9600);
}

void loop()
{
  // check if command is available at serial
  if (Serial.available())
  {
    String command = Serial.readString(); // read integer data from serial
    // turn on the LED for command = a or A
    if (command.equalsIgnoreCase("turn on"))
    {
      digitalWrite(LED, true);
      Serial.println("LED ON");
    }
    // turn off the LED for command = z or Z
    else if (command.equalsIgnoreCase("turn off"))
    {
      digitalWrite(LED, false);
      Serial.println("LED OFF");
    }
    // print Invalid command
    else
    {
      Serial.println("Invalid Command, try again");
    }
  }
}