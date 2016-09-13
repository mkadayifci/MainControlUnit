#include "ArduinoJson.h"
#include "Servo.h"
#include "AbraServoBase.cpp"
#include "Light.cpp"
#include "Thruster.cpp"
#include "UlakCommunicator.cpp"



Light* light;
Thruster* thruster;
UlakCommunicator* communicator;

void setup() {
  // initialize serial:

  light=new Light(9);
  thruster=new Thruster(2);
  communicator = new UlakCommunicator();
}

bool isStarted = false;

void loop() {


  communicator->CheckMessages();
//  delay(100);
//  thruster->SetThrust(5);
  
//
//  light->SetBrightness(50);
//  Serial.println(light->GetBrightness()); 
//  delay(1000);
//  light->SetBrightness(100);
//  Serial.println(light->GetBrightness()); 
//  delay(1000);
//  light->SetBrightness(0);
//  Serial.println(light->GetBrightness()); 
//  delay(1000);
  
}


