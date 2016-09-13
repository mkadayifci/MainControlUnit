#include "Arduino.h"
#include "Servo.h"

class Thruster

{
private:
        Servo thrusterReference;
        int outputPort;
        int currentValue;
public:

	Thruster(int outputPort){
          this->outputPort=outputPort;
          thrusterReference.attach(this->outputPort);
        };

	~Thruster(){};

	int readValue(){
            return this->currentValue;
        }

        
        void setValue(int percentage){
          
            int convertedServoValue = map(percentage,-100,100,1100,1900);
            thrusterReference.writeMicroseconds(convertedServoValue);           
            this->currentValue=convertedServoValue;
        }

};





