#include "Servo.h"
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

  if(!isStarted){
    //thruster->setValue(-100);
  isStarted = true;
  
  }
delay(2000);
thruster->setValue(0);

///  light->setValue(50);
//  Serial.println(light->readValue()); 
//  delay(1000);
//  light->setValue(100);
//  Serial.println(light->readValue()); 
//  delay(1000);
//  light->setValue(0);
//  Serial.println(light->readValue()); 
//  delay(1000);
  
}


