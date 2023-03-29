// MIE438 Team 29
// Adam Cavallo, Andres Cervera Rozo, Liam Toner, Selin Ertan
// Use the header file functionality to implement other functions into code
// Comment any special libraries required to install locally

#include "Pinout.h"
#include "Keypad.h"
#include "LCD.h"
#include "Lights.h"
#include "Pumps.h"

const int FILLUP_TIME = 4000; //milliseconds of how long it takes to fillup a drink to a desired level
const String drink1 = "DRINK 1";
const String drink2 = "DRINK 2";
const String drink3 = "DRINK 3";
const String drink4 = "DRINK 4";

void setup() {
  Serial.begin(9600);
  lcdSetup();
  pumpsSetup();
  keypadSetup();
  lightsSetup();
  lcdClear();
  

}

void loop() {
  ledFinished(false);
  lcdPrint("Hello, Please make a selection");
  uint8_t choice_made = 255;    //does int cover everything? Input protection in keySelected stage
  while (choice_made != 255){
    choice_made = keySelected();//Add protection from timeout, return the key pressed
  }
  delay(400);
  lcdClear();
  lcdChoice(choice_made); //Print out the choice made
  delay(1500);

  int pumps_time[4] = {0, 0, 0, 0};
  pumpDurations(choice_made, &pumps_time, 4); //https://stackoverflow.com/questions/13295011/altering-an-array-from-a-function-in-c

  for (uint8_t pump = 0; pump < 4; pump++) {
    int on_time = pumps_time[pump];
    if (on_time) {
      lcdClear();
      ledPumpOn(pump);
      lcdPouring(pump);
      pumpOn(pump, on_time);
      delay(300); // To allow electric load to drop mildly rather than spike
    }
  }
  
  lcdClear();
  lcdPrint("Your drink is now ready, please enjoy!");
  ledFinished(true);
  delay(5000);
  lcdClear();
}

// Emergency stop push button interrupt, to be discussed
