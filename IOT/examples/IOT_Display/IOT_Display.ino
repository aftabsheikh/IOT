#include "IOT.h"

String url="http://iwsautomation.com/iot/set_display.php?key=682b336af6a80d4b5452098cfbe2a4c3dca623a0cd2de51ab06dbbe1ad6d4fa1&no=1";

IOT dis(url);
const char *ssid = "xxxxxxx";     //your ssid(wifi) name
const char *password = "xxxxxx";  //your ssid password(wifi password)

void setup() {
  Serial.begin(115200);
  dis.connect(ssid,password);
}

void loop() {
 
  String data="hello from Esp8266";
  String output=dis.setDisplay(data);
  Serial.println(output);
  delay(500);
}
