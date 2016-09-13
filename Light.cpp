#include "Arduino.h"
#include "Servo.h"
#include "AbraServoBase.cpp"

class Light:public AbraServoBase
{
private:
public:

        static const int MIN_BRIGHTNESS_VALUE=0;
        static const int MAX_BRIGHTNESS_VALUE=100;

        static const int INIT_VALUE_IN_MICROSECONDS = 0 ;

	Light(int outputPort):AbraServoBase(outputPort, INIT_VALUE_IN_MICROSECONDS)
        {
        };

	~Light(){};
        
        void SetBrightness(int value)
        {
          
          int convertedMicrosecondsValue = map(
                                                value,
                                                MIN_BRIGHTNESS_VALUE,
                                                MAX_BRIGHTNESS_VALUE,
                                                SERVO_MIN_VALUE,
                                                SERVO_MAX_VALUE
                                              );

          this->WriteMicroseconds(convertedMicrosecondsValue);
        }

        int GetBrightness()
        {
           int convertedBrightnessValue = map(
                                  this->ReadMicroseconds(),
                                  SERVO_MIN_VALUE,
                                  SERVO_MAX_VALUE,
                                  MIN_BRIGHTNESS_VALUE,
                                  MAX_BRIGHTNESS_VALUE
                                );

          return convertedBrightnessValue;
        }
};





