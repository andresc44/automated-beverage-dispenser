#ifndef LCD_H
#define LCD_H

void lcdSetup();                      // Setup LCD display
void lcdPrint(String message);        // Print a given message on LCD, check length of message as well
void lcdChoice(uint8_t choice);       // Print from default messages about the choice of drink
void lcdPouring(uint8_t pump_number); // Print "Currently pouring XX"
void lcdClear();                      // Clears Display

#endif
