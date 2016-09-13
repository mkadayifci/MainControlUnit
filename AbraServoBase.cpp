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
        static const int SERVO_MIN_VALUE= 1100;
        static const int SERVO_MAX_VALUE= 1900;

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





