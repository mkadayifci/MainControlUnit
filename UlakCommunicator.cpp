#include "Arduino.h"



class UlakCommunicator

{
private:
public:

	UlakCommunicator()
        {
            Serial.begin(9600);

        }

	~UlakCommunicator()
        {
        }
        
        void SendRandomValue()
        {
          Serial.println(random(500)); 
        }

};





