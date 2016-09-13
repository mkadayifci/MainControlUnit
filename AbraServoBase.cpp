#include "Arduino.h"
#include "Servo.h"

#pragma once

class AbraServoBase

{
private:
        Servo* servoPointer = new Servo();
        int outputPort;
        int lastMicrosecondValue=0;
public:

        int GetOutputPortNumber()
        {
          return outputPort;
        }
        
	AbraServoBase(int outputPort,int initMicrosecond)
        {
          this->outputPort=outputPort;
          servoPointer->attach(this->outputPort);
          this->WriteMicroseconds(initMicrosecond);
        }

	~AbraServoBase()
        {
          servoPointer->detach();
        }

        void WriteMicroseconds(int microSeconds)
        {

            servoPointer->writeMicroseconds(microSeconds);           
            this->lastMicrosecondValue=microSeconds;
        }
        
        
        int ReadMicroseconds()
        {
          return this->lastMicrosecondValue;
        }
};





