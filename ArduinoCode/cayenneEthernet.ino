#include <BlynkApiArduino.h>
#include <BlynkApiParticle.h>
#include <BlynkParticle.h>
#include <BlynkSimpleCC3000.h>
#include <BlynkSimpleEnergiaWiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <BlynkSimpleEsp8266_SSL.h>
#include <BlynkSimpleEthernet.h>
#include <BlynkSimpleEthernet2.h>
#include <BlynkSimpleEthernetV2_0.h>
#include <BlynkSimpleIntelEdisonWiFi.h>
#include <BlynkSimpleLinkItONE.h>
#include <BlynkSimpleParticle.h>
#include <BlynkSimpleRBL_CC3200.h>
#include <BlynkSimpleRBL_WiFi_Mini.h>
#include <BlynkSimpleRedBear_Duo.h>
#include <BlynkSimpleSerial.h>
#include <BlynkSimpleShieldEsp8266.h>
#include <BlynkSimpleShieldEsp8266_HardSer.h>
#include <BlynkSimpleShieldEsp8266_SoftSer.h>
#include <BlynkSimpleTI_CC3200_LaunchXL.h>
#include <BlynkSimpleTI_TivaC_Connected.h>
#include <BlynkSimpleTinyDuino.h>
#include <BlynkSimpleUIPEthernet.h>
#include <BlynkSimpleUserDefined.h>
#include <BlynkSimpleWifi.h>
#include <BlynkSimpleWiFiShield101.h>
#include <BlynkSimpleWiFiShield101_SSL.h>
#include <BlynkSimpleWiFly.h>
#include <BlynkSimpleWildFire.h>
#include <BlynkSimpleYun.h>
#include <BlynkWidgets.h>
#include <CayenneClient.h>
#include <CayenneDefines.h>
#include <CayenneEthernet.h>
#include <CayenneEthernetClient.h>
#include <CayenneEthernetW5200.h>
#include <CayenneEthernetW5500.h>
#include <CayenneSerial.h>
#include <CayenneTemperature.h>
#include <CayenneTMP102.h>
#include <CayenneTypes.h>
#include <CayenneVCNL4000.h>
#include <CayenneWiFi.h>
#include <CayenneWiFi101.h>
#include <CayenneWiFiClient.h>
#include <CayenneYun.h>
#include <WidgetBridge.h>
#include <WidgetLCD.h>
#include <WidgetLED.h>
#include <WidgetRTC.h>
#include <WidgetSD.h>
#include <WidgetTerminal.h>

/*
Cayenne Ethernet Example

This sketch connects to the Cayenne server using an Arduino Ethernet Shield W5100
and runs the main communication loop.

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. Set the token variable to match the Arduino token from the Dashboard.
2. Compile and upload this sketch.

For Cayenne Dashboard widgets using digital or analog pins this sketch will automatically
send data on those pins to the Cayenne server. If the widgets use Virtual Pins, data
should be sent to those pins using virtualWrites. Examples for sending and receiving
Virtual Pin data are under the Basics folder.
*/

//#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "hiqjexyopj";

void setup()
{
  Serial.begin(9600);
  Cayenne.begin(token);
}

void loop()
{
  Cayenne.run();

  int a = 1;
  
}

