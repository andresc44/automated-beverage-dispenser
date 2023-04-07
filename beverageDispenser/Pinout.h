#ifndef PINOUT_H
#define PINOUT_H

//Pump1
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

// Liam please add the required pins and labels


#endif

int full = 18;
int half = full/2; //9
float full_shot = 3;
float half_shot = full_shot/2; //1.5
float full_mixer = full-full_shot; //15
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

//String drink_names[13] = {
//  "Coke",
//  "Lime Juice",
//  "Rum Shot",
//  "Vodka Shot",
//  "Coke and Lime",
//  "Rum and Coke",
//  "Coke and Vodka",
//  "Rum and Lime",
//  "Vodka and Lime",
//  "Rum and Vodka",
//  "Rum, Coke, Lime",
//  "Vodka, Coke, Lime",
//  "EVERYTHING"  
//};
