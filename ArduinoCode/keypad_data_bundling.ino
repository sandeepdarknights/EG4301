#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'.','0','#'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {A4, A5, 2}; //connect to the column pinouts of the kpd

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char entryStr[4]; 
int i=0;

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
 if (key){ 
    if (key != '#'){
     entryStr[i]= key;
     i++;
     Serial.print(key);
     }
   else {
   Serial.println(""); 
   i=0;
   key=0;
   Serial.println("Temperature recorded: " + String(entryStr));
    
 }

 }
}
