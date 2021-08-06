#include <Keypad.h>
#include <HID-Project.h>
#include <HID-Settings.h>

const byte ROWS = 1; // one rows
const byte COLS = 3; // Three columns

// Define the Keymap

char keys[ROWS][COLS] = {
  {'1','2','3'}
};

byte rowPins[ROWS] = {14};
byte colPins[COLS] = {5, 6, 7}; 

void setup() {
  Serial.begin(9600);
  Serial.println(" as input-pullup");
  pinMode(colPins[0], INPUT_PULLUP);
  pinMode(colPins[1], INPUT_PULLUP);
  pinMode(colPins[2], INPUT_PULLUP);
}

void pressKey(char key){
  switch(key){
    case '1':
      Keyboard.write(KEY_F22);
      delay(100);
      break;
    case '2':
      Keyboard.write(KEY_F23);
      delay(100);
      break;
    case '3':
      Keyboard.write(KEY_F24);
      delay(100);
      break;
    default:
      Serial.print(key);
  }
}

void loop() {
  for(int j=0; j<COLS;j++){ 
    byte currentCol = colPins[j];
    for(int i=0; i<ROWS;i++){
      byte currentRow = rowPins[i];
      pinMode(currentRow, OUTPUT);
      digitalWrite(currentRow, LOW);
      if(digitalRead(currentRow)== LOW and digitalRead(currentCol)==LOW){
        char key = keys[i][j];
        pressKey(key);
        Serial.print("Has pressed: ");
        Serial.println(key);
        delay(150);
      }
      pinMode(currentRow, INPUT);
    }
    pinMode(currentCol, INPUT_PULLUP);
  }

}
