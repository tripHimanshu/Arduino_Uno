#include <Arduino.h>
#include <SoftwareSerial.h>

// Connect SIM900A Tx to Arduino Pin 2
// Connect SIM900A Rx to Arduino Pin 3
SoftwareSerial SIM900A(3, 2); // RX|TX

void sendMessage()
{
  Serial.println("setting SMS number");
  SIM900A.println("AT+CMGS=\""+919873812070"\""); // mobile phone number to send message
  delay(1000);
  Serial.println("Sending message");
  SIM900A.println("AT+CMGF=1\r"); // set the GSM module in text mode
  delay(1000);
  
  Serial.println("Setting SMS content");
  SIM900A.println("Working on project");
  delay(100);
  Serial.println("Finish");
  SIM900A.println((char)26); // ASCII code of CTRL+Z
  delay(1000);
  Serial.println("Message has been sent");
}

void receiveMessage()
{
  Serial.println("SIM900A SMS");
  delay(1000);
  SIM900A.println("AT+CNMI=2,2,0,0,0"); // AT command to receive SMS
  delay(1000);
  Serial.write("unread message done");
}

void setup()
{
  // configure hardware serial for Arduino
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("Arduino with SIM900A is ready");
  // configure software serial for SIM900A
  SIM900A.begin(9600);
  Serial.println("SIM900A started at 9600");
  delay(1000);
  Serial.println("Setup Complete! SIM900A is ready");
}

void loop()
{
  if (Serial.available())
  {
    switch (Serial.read())
    {
    case 's':
      sendMessage();
      break;
    case 'r':
      receiveMessage();
      break;
    }
  }

  if (SIM900A.available())
  {
    Serial.write(SIM900A.read());
  }
}