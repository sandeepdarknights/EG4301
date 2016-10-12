#include <Keypad.h>
#include <Ethernet.h>
#include <SPI.h>
#include <SD.h>
/*-----------------------Keypad Variables----------------------------------*/
const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { A0, A1, A2, A3 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { A4, A5, 2 }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#define ledpin 13 //note: sd card takes pin 13 right?
File myFile;
/*-------------------------------------------------------------------------*/
  
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
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile){
  //  Serial.println("We made it till here");                 
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
        myFile.println(key);
      myFile.close(); 
    }
  }
    
  }
  else{
    Serial.println("Error in opening file");
  }
  delay(3000);
}
