#include <SPI.h>
#include <WiFi.h>

char ssid[] = "G4_1447";
char pass[] = "richboss";

int keyIndex = 0;
int status = WL_IDLE_STATUS;

WiFiClient client;

void connectToInternet()
{
  status = WiFi.status();
  if (status == WL_NO_SHIELD)
  {
    Serial.println("[ERROR] WiFi Shield not Present");
    while (true);
  }

  while (status != WL_CONNECTED)
  {
    Serial.print("[INFO] Attempting connection - WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
  }
  Serial.print("[INFO] Connection Successful");
  Serial.print("");
  Serial.println("");
  Serial.print("----------------------------------------------");
  Serial.println("");
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}


void setup()
{
  Serial.begin(9600);
  connectToInternet();
}

void loop()
{
  
}

