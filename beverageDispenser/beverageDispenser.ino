// MIE438 Team 29
// Adam Cavallo, Andres Cervera Rozo, Liam Toner, Selin Ertan
// Use the header file functionality to implement other functions into code
// Comment any special libraries required to install locally

#include "Pinout.h"
#include "Keypad.h"
#include "LCD.h"
#include "Lights.h"
#include "Pumps.h"

const int FILLUP_TIME = 12000; //milliseconds of how long it takes to fillup a drink to a desired level
const float DURATION_CONVERSION = FILLUP_TIME/18; //Seconds per oz
const String drink1 = "Coca Cola";
const String drink2 = "Lime Juice";
const String drink3 = "Rum";
const String drink4 = "Vodka";

void setup() {
  Serial.begin(9600);
  lcdSetup();
  pumpsSetup();
  lightsSetup();
  lcd.clear();
}

void loop() {
//  ledFinished(false);
  lcdPrint("Hello, Please make a selection"); //might need delay after print statements 
  int choice_made = 255;    //does int cover everything? Input protection in keySelected stage
  while ((choice_made == 255)||(choice_made <= 0)){ //need to put a statement that woud assing choice made only if keyselected result isn't zero
    choice_made = keySelected();//Add protection from timeout, return the key pressed
  }
  delay(400);
  lcd.clear();
  lcdChoice(choice_made); //Print out the choice made
  delay(1500);

  int pumps_time[4] = {0, 0, 0, 0};
  pumpDurations(choice_made, &pumps_time, 4); //https://stackoverflow.com/questions/13295011/altering-an-array-from-a-function-in-c

  for (uint8_t pump = 0; pump < 4; pump++) {
    int on_time = pumps_time[pump];
    if (on_time) {
      lcd.clear();
//      ledPumpOn(pump);
      lcdPouring(pump);
      Serial.print("Pump and time: ");
      Serial.print(pump);
      Serial.print(" ");
      Serial.println(on_time);
      
      pumpOn(pump, on_time);
      delay(300); // To allow electric load to drop mildly rather than spike
    }
  }
  
  lcd.clear();
  lcdPrint("Your drink is now ready");
//  ledFinished(true);
  delay(5000);
  lcd.clear();
}

// Emergency stop push button interrupt, to be discussed
