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
          //Serial.println(random(500)); 
        }
        
        void CheckMessages()
        {
          if(Serial.available())
          {
            String message = Serial.readStringUntil('}');
            Serial.println(message);
          }

        }

};





