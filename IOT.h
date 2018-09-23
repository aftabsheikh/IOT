//******************************************************************************
// IOT services
// Version 1.0 Sep, 2018
// Copyright 2018 aftab sheikh
// For details, see http://iwsautomation.com
// Released into the public domain
//******************************************************************************
#ifndef IOT_h
#define IOT_h

#include "Arduino.h"
#include "ESP8266WiFi.h"
#include "ESP8266HTTPClient.h"
class IOT
{
  public:
    IOT(String url,uint8_t pin);
    void connect(const char*,const char*);
    String initBtn();
  private:
    String _url;
    uint8_t _pin;
};

#endif