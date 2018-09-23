/*
  IOT.cpp - Library for IOT button and Virtual display code.
  Created by Aftab R. Sheikh, Sep-2018.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
#include "IOT.h"

IOT::IOT(String url,uint8_t pin)
{
  _url = url;
  _pin=pin;
  pinMode(_pin, OUTPUT);
}

String IOT::initBtn()
{
    String payload="0";
    if(WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;    //Declare object of class HTTPClient
        http.addHeader("Content-Type", "text/plain");
        http.begin(_url);
        int httpCode = http.GET();            //Send the request
        if(httpCode==200)
        {
            payload = http.getString();
            int result=0,len,i;
            len = payload.length();

            for(i=0; i<len; i++)
            {
              result = result * 10 + ( payload[i] - '0' );
            }
            if(result==0)
            {
                digitalWrite(_pin, LOW);
                payload="LOW";
            }
            if(result==1)
            {
                digitalWrite(_pin, HIGH);
                payload="HIGH";
            }
            delay(2000);
        }
        else
        {
            payload="network error.auto retry after 1 sec";
            delay(500);
        }
        http.end();  //Close connection
        
        
    }
    else
    {
        payload="-1";
    }
    return payload;
}

void IOT::connect(const char *ssid,const char *password)
{
        Serial.println("");
        Serial.print("Waiting for connection");
        WiFi.begin(ssid, password); //WiFi connection
        int i = 0;
        while (WiFi.status() != WL_CONNECTED) { //Wait for the WiFI connection completion
            delay(1000);
            i++;
            Serial.print(".");
            if (i == 10)break;
        }
        
        if(WiFi.status() != WL_CONNECTED)
        {
        Serial.println("connection was fail");
        }
}