#include <EEPROM.h>
#include <SPI.h>
#include <Ethernet.h>
#include <Exosite.h>
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte rowPins[ROWS] = { A0, A1, A2, A3 };
byte colPins[COLS] = { A4, A5, 2 }; 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#define ledpin 13

String cikData = "22781660f6fa7fbfe773057dfa4e93cb83e85869"; 
byte macData[] = {0x90, 0xA2, 0xDA, 0x02, 0x00, 0x00};        
// Use these variables to customize what datasources are read and written to.
String readString = "command&uptime";
String writeString = "uptime=";
String returnString;

EthernetClient client;
Exosite exosite(cikData, &client);

void setup(){  
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Boot");
  
  Ethernet.begin(macData);
  
  // wait 10 seconds for connection:
  delay(1000);
}

void loop(){
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '*':
        digitalWrite(ledpin, LOW);  //why doesnt pin 13 work at all?
        break;
      case '#':
        digitalWrite(ledpin, HIGH); //why doesnt pin 13 work at all?
        break;
      default:
        Serial.println(key);
    }
    //Write to "uptime" and read from "uptime" and "command" datasources.
    if ( exosite.writeRead(writeString+String(key), readString, returnString)){
      Serial.println("OK");
      Serial.println(returnString);
    }else{
      Serial.println("Error");
    } 
  }
}
