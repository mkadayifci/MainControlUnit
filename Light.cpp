#include "Arduino.h"
#include "Servo.h"

class Light

{
private:
        Servo lightReference;
        int outputPort;
        int currentValue;
public:

	Light(int outputPort){
          this->outputPort=outputPort;
          lightReference.attach(this->outputPort);
        };

	~Light(){};

	int readValue(){
            return this->currentValue;
        }

        void setValue(int percentage){
          
            int convertedServoValue = map(percentage,0,100,1100,1900);
            lightReference.writeMicroseconds(convertedServoValue);           
            this->currentValue=convertedServoValue;
        }

};





