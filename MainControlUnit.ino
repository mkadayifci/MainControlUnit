#include "Servo.h"
#include "light.cpp"

Light* light;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  light=new Light(9);
}

void loop() {

  light->setValue(50);
  Serial.println(light->readValue()); 
  delay(1000);
  light->setValue(100);
  Serial.println(light->readValue()); 
  delay(1000);
  light->setValue(0);
  Serial.println(light->readValue()); 
  delay(1000);
  
}


