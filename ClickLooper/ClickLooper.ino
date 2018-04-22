// https://digistump.com/board/index.php?topic=2540.0

#include "DigiMouse.h"

const int moveOffset = 67;
const int duration = 30000; // msec 180000:3min
const int ledPin = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //LED on Model A  
  DigiMouse.begin(); //start or reenumerate USB
}

void loop() {
  DigiMouse.update(); // DigiMouse.update() at least every 50ms

  DigiMouse.delay(500);  
  DigiMouse.setButtons(1); //left click
  digitalWrite(ledPin, true);  

  DigiMouse.delay(500);
  DigiMouse.setButtons(0); //unclick all
  digitalWrite(ledPin, false);    

  DigiMouse.delay(500);
  DigiMouse.moveX(moveOffset); 

  DigiMouse.delay(500);  
  DigiMouse.setButtons(1); //left click
  digitalWrite(ledPin, true);  
  
  DigiMouse.delay(500);
  DigiMouse.setButtons(0); //unclick all
  digitalWrite(ledPin, false);    

  DigiMouse.delay(duration); 
  DigiMouse.moveX(-moveOffset); 
}
