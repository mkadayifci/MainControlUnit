#include "Servo.h"
#include "AbraServoBase.cpp"
#include "Light.cpp"
#include "Thruster.cpp"

Light* light;
Thruster* thruster;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  light=new Light(9);
  thruster=new Thruster(2);
}

bool isStarted = false;

void loop() {

  thruster->SetThrust(100);
  
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


