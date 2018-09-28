#include "IOT.h"

uint8_t pin=D4;
String url="http://iwsautomation.com/iot/get_button.php?key=73a2cfdb3b5f172350cf06cd160fc8fbc58d95b4bc934e21f1c00ad13a507b74&no=4";
IOT button(url,pin);
const char *ssid = "xxxxxx";    //your ssid(wifi) name
const char *password = "xxxxx"; //your ssid password(wifi password)

void setup() {
  Serial.begin(115200);
  button.connect(ssid,password);
}

void loop() {
    String output=button.getBtn();
    Serial.println(output);
    delay(500);
}
