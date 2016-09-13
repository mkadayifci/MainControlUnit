#include "Arduino.h"
#include "Servo.h"
#include "AbraServoBase.cpp"

class Light:public AbraServoBase
{
private:
public:
        static const int INIT_VALUE_IN_MICROSECONDS = 0 ;

	Light(int outputPort):AbraServoBase(outputPort, INIT_VALUE_IN_MICROSECONDS)
        {
        };

	~Light(){};
        
        void SetBrightness(int value)
        {
          int convertedMicrosecondsValue = map(value,0,100,1100,1900);
          this->WriteMicroseconds(convertedMicrosecondsValue);
        }

        int GetBrightness()
        {
          return this->ReadMicroseconds();
        }
};





