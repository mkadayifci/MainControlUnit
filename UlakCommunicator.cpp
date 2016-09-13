#include "Arduino.h"
#include "ArduinoJson.h"


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
            ProcessMessage(message);
          }

        }
        
        void ProcessMessage(String message)
        {
          StaticJsonBuffer<200> jsonBuffer;

          JsonObject& root = jsonBuffer.parseObject(message);

          if (!root.success())
          {
            Serial.println("parseObject() failed");
            return;
          }
          else
        {
           String value = root["Value"];
           Serial.println(value);
        }
        }

};





