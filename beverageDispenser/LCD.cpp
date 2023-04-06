//  The circuit:
// * LCD RS pin to digital pin 7
// * LCD Enable pin to digital pin 8
// * LCD D4 pin to digital pin 9
// * LCD D5 pin to digital pin 10
// * LCD D6 pin to digital pin 11
// * LCD D7 pin to digital pin 12
// * LCD R/W pin to ground
// * LCD VSS pin to ground
// * LCD VCC pin to 5V
// * 10K resistor:
// * ends to +5V and ground
// * wiper to LCD VO pin (pin 3)

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

String drink_names[13] = {
  "Coke",
  "Lime Juice",
  "Rum Shot",
  "Vodka Shot",
  "Coke and Lime",
  "Rum and Coke",
  "Coke and Vodka",
  "Rum and Lime",
  "Vodka and Lime",
  "Rum and Vodka",
  "Rum, Coke, Lime",
  "Vodka, Coke, Lime",
  "EVERYTHING"  
};

void lcdsetup(){
  // set up the LCD's number of columns and rows:);
  lcd.begin(16, 2);
}

void lcdPrint(String message){
  int messageLength = message.length();
  int lineBreakIndex = -1;

  //find the last space before the 16th character
  for (int i = 0; i < messageLength && i < 16; i++){
    if (message.charAt(i) == ' '){
      lineBreakIndex = i;
    }
  }

  //if a space was found, split the message into two lines
  if (lineBreakIndex != -1){
    lcd.setCursor(0,0);
    lcd.print(message.substring(0, lineBreakIndex));
    lcd.setCursor(0,1);
    lcd.print(message.substring(lineBreakIndex + 1));
  } else{
    lcd.setCursor(0,0);
    lcd.print(message);
  }
}

void lcdChoice(int choice){
  String message;
  message = drink_names[choice];
  lcdPrint(message);
}

void lcdPouring(uint8_t pump_number){
  // print "Pouring" on the first row
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pouring");

  //print the pump number on the second row
  lcd.setCursor(9,0);
  lcd.print(pump_number);
}
