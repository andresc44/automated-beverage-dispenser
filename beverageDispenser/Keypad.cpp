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
  if (customKey == 'A'){
    return 10;
  } else if (customKey == 'B'){
    return 11;
  } else if (customKey == 'C'){
    return 12;
  } else if (customKey == 'D'){
    return 13;
  } else{
    return customKey - '0';
  }
}
