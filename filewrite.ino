#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
#define ledpin 13
File myFile;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
  digitalWrite(ledpin, HIGH);
  Serial.println("Initializing SD Card...");
  if (!SD.begin(4)){  //Note: important that this is pin 4 and not pin 10 as pin 10 resulted in failure
    Serial.println("Initialization failed!!!");
    return;
  }
  Serial.println("Initialization complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile){
    Serial.println("EG4302");
    myFile.println("EG4302");
    myFile.close(); 
  }
  else{
    Serial.println("Error in opening file");
  }
  delay(3000);
}
