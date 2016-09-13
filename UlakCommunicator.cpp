#include "Arduino.h"
#include "ArduinoJson.h"


class UlakCommunicator

{
private:
        const static int BAUD_RATE = 9600;
        const static int COM_PORT_TIMEOUT_IN_MS = 50;
        
        int lightBrightness=0;
public:

	UlakCommunicator()
        {
            Serial.begin(BAUD_RATE);
            Serial.setTimeout(COM_PORT_TIMEOUT_IN_MS);
        }

	~UlakCommunicator()
        {
        }
        
        void SendRandomValue()
        {
          //Serial.println(random(500)); 
        }
        int GetBrightness()
        {
          return lightBrightness;
        }
        void CheckMessages()
        {
          if(Serial.available())
          {
            String message = Serial.readStringUntil('}');
            ProcessMessage(message + "}");
          }

        }
        
        void ProcessMessage(String message)
        {
          StaticJsonBuffer<200> jsonBuffer;

          JsonObject& root = jsonBuffer.parseObject(message);

          if (!root.success())
          {
            Serial.println(message);
            return;
          }
          else
        {
           String value = root["Value"];
           lightBrightness =value.toInt();
           Serial.println(value);
        }
        }

};





