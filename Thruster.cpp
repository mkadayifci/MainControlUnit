#include "Arduino.h"
#include "Servo.h"
#include "AbraServoBase.cpp"



class Thruster:public AbraServoBase

{
private:
public:
        static const int FULL_REVERSE_VALUE=-100;
        static const int FULL_FORWARD_VALUE= 100;
        
        static const int INIT_VALUE_IN_MICROSECONDS = 1500 ;

	Thruster(int outputPort):AbraServoBase(outputPort, INIT_VALUE_IN_MICROSECONDS)
        {
        }

	~Thruster()
        {
        }
        
        void SetThrust(int value)
        {
            int convertedMicrosecondsValue = map(
                                                  value,
                                                  FULL_REVERSE_VALUE,
                                                  FULL_FORWARD_VALUE,
                                                  SERVO_MIN_VALUE,
                                                  SERVO_MAX_VALUE
                                                );

            this->WriteMicroseconds(convertedMicrosecondsValue);           
        }
        
        
        int GetThrust()
        {
          int convertedThrustValue = map(
                                          this->ReadMicroseconds(),
                                          SERVO_MIN_VALUE,
                                          SERVO_MAX_VALUE,
                                          FULL_REVERSE_VALUE,
                                          FULL_FORWARD_VALUE
                                        );
          
          return convertedThrustValue;
        }

};





