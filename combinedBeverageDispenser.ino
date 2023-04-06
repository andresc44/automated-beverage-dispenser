// MIE438 Team 29
// Adam Cavallo, Andres Cervera Rozo, Liam Toner, Selin Ertan
// Use the header file functionality to implement other functions into code
// Comment any special libraries required to install locally

#include <Keypad.h>
#include <LiquidCrystal.h>

const int FILLUP_TIME = 12000; //milliseconds of how long it takes to fillup a drink to a desired level
const float DURATION_CONVERSION = FILLUP_TIME/18; //Seconds per oz

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const String drink1 = "Coca Cola";
const String drink2 = "Lime Juice";
const String drink3 = "Rum";
const String drink4 = "Vodka";
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

float full = 18.0*DURATION_CONVERSION;
float half = full/2; //9
float full_shot = 3*DURATION_CONVERSION;
float half_shot = full_shot/2; //1.5
float full_mixer = (full-full_shot); //15
float half_mixer = full_mixer/2; //7.5

float drink_amounts[13][4] = {
                        //Single Drink
  {full, 0, 0, 0},      //Coke- 18 oz, button 0, return 0
  {0, full, 0, 0},      //Lime Juice -18 oz, button 1, return 1
  {0, 0, full_shot, 0}, //Rum - 3 oz, button 2, return 2
  {0, 0, 0, full_shot}, //Vodka -3 oz, button 3, return 3

                                //Double Drink
  {half, half, 0, 0},           //Coke (9oz) and Lime (9 oz), button 4, return 4
  {full_mixer, 0, full_shot, 0},//Rum (3 oz) and Coke (15 oz), button 5, return 5
  {full_mixer, 0, 0, full_shot},//Coke (15 oz) and Vodka (3 oz), button 6, return 6
  {0, full_mixer, full_shot, 0},//Lime Juice (15 oz) and Rum (3 oz), button 7, return 7
  {0, full_mixer, 0, full_shot},//Lime Juice (15 oz) and Vodka (3 oz), button 8, return 8
  {0, 0, half_shot, half_shot}, //Rum (1.5oz) and Vodka (1.5oz), button 9, return 9

                                                //Triple Drink
  {half_mixer, half_mixer, full_shot, 0},       //Rum (3 oz) and Coke (7.5 oz) and Lime (7.5 oz), button A, return 10
  {half_mixer, half_mixer, 0, full_shot},       //Vodka (3 oz) and Coke (7.5 oz) and Lime (7.5 oz), button B, return 11

                                                //Quadruple Drink
  {half_mixer, half_mixer, half_shot, half_shot}//Rum (1.5 oz) and Vodka (1.5 oz) and Coke (7.5oz) and Lime juice (7.5oz), button C, return 12
};


int pump1_in1 = 1;
int pump1_in2 = 1;

//Pump2
int pump2_in3 = 1;
int pump2_in4 = 1;  

//Pump3
int pump3_in1 = 1;
int pump3_in2 = 1;

//Pump4
int pump4_in3 = 1;
int pump4_in4 = 1;

int pump_pins[4] = {pump1_in1, pump2_in3, pump3_in1, pump4_in3};

// initialize the library with the numbers of the interface pins

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


////////////////////////////////////////////Keypad
  
int keySelected(){
  char customKey = customKeypad.getKey();
  if (customKey == 'A'){
    return 10;
  } else if (customKey == 'B'){
    return 11;
  } else if (customKey == 'C'){
    return 12;
  } else if (customKey == 'D'){
    return -10;
  } else{
    return customKey - '0';
  }
}

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


void lcdSetup(){
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
  lcd.setCursor(0,1);
  if (pump_number == 0){
      lcd.print("Coke");
  } else if (pump_number == 1){
    lcd.print("Lime Juice");
  } else if (pump_number == 2){
    lcd.print("Rum");
  } else if (pump_number == 3){
    lcd.print("Vodka");
  }
}


void pumpsSetup() { // Setup pumps

//Pump1
  pinMode(pump1_in1, OUTPUT);
  pinMode(pump1_in2, OUTPUT);

  //Pump2
  pinMode(pump2_in3, OUTPUT);
  pinMode(pump2_in4, OUTPUT);

  //Pump3
  pinMode(pump3_in1, OUTPUT);
  pinMode(pump3_in2, OUTPUT);

  //Pump4
  pinMode(pump4_in3, OUTPUT);
  pinMode(pump4_in4, OUTPUT);

  
  //Set initial no directionsince enable pin always on (we no longer touch the second 'in', and use the first 'in' pins to control flow
  digitalWrite(pump1_in1, LOW);
  digitalWrite(pump1_in2, LOW);
  digitalWrite(pump2_in3, LOW);
  digitalWrite(pump2_in4, LOW);
  digitalWrite(pump3_in1, LOW);
  digitalWrite(pump3_in2, LOW);
  digitalWrite(pump4_in3, LOW);
  digitalWrite(pump4_in4, LOW);
  
}

void pumpDurations(int choice, float durations[]){ // Alter pointer of durations depending on choice. Talk to Andres
//  *durations = new float[4];
  drink_amounts[choice];
  durations[0] = drink_amounts[choice][0];
  durations[1] = drink_amounts[choice][1];
  durations[2] = drink_amounts[choice][2];
  durations[3] = drink_amounts[choice][3];
}


void pumpOn(uint8_t pump_number, float duration) {    //make sure array indexing is correct, do i need globalization forthe pump pins arrray

  int pump_pin = pump_pins[pump_number];
  digitalWrite(pump_pin, HIGH); //makes the first 'in' pin of the pump equal to high to allow current flow 
  //timer
  unsigned long previousMillis = millis();  // Store the last time the loop ran

  while (true) { 
    Serial.println("Entering while");
    Serial.println(duration);
     unsigned long currentMillis = millis();  // Get the current time

      if (currentMillis - previousMillis >= duration) {  // Check if the interval has passed
        previousMillis = currentMillis;  // Save the current time as the last time the loop ran
        break;  // Exit the while loop to wait for the next interval
      }
    }
    Serial.println("Done while");
    digitalWrite(pump_pin, LOW); //turn off pump 
}


void setup() {
  Serial.begin(9600);
  Serial.println(DURATION_CONVERSION);
  Serial.println(full);
  Serial.println(half);
  Serial.println(full_shot);
  Serial.println(half_shot);
  Serial.println(full_mixer);
  Serial.println(half_mixer);
  
  lcdSetup();
  pumpsSetup();
//  lightsSetup();
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

  float pumps_time[4] = {0, 0, 0, 0};
  Serial.print("Choice: ");
  Serial.print(choice_made);
  
  pumpDurations(choice_made, pumps_time); //https://stackoverflow.com/questions/13295011/altering-an-array-from-a-function-in-c
  
  for (uint8_t pump = 0; pump < 4; pump++) {
    float on_time = pumps_time[pump];
    if (on_time > 0) {
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
