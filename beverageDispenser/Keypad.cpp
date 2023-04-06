#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {39, 41, 43, 45}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {47, 49, 51, 53}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);  
  
int keySelected(){
  char customKey = customKeypad.getKey();
  if (customKey >= '1' && customKey <= '4'){
    return customKey - '0'; //return integer representation of the character
  } else{
    return 0;
}
