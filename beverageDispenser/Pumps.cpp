
////Variables

//Pump1
int pump1_in1 = ;
int pump1_in2 = ;

//Pump2
int pump2_in3 = ;
int pump2_in4 = ;  

//Pump3
int pump3_in1 = ;
int pump3_in2 = ;

//Pump4
int pump4_in3 = ;
int pump4_in4 = ;


int pump_pins[4] = {pump1_in1, pump2_in3, pump3_in1, pump4_in3};

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



void pumpDurations(uint8_t choice, int *durations[], uint8_t number_of_pumps){ // Alter pointer of durations depending on choice. Talk to Andres
  
  
  
}





void pumpOn(uint8_t pump_number, int duration); {    //make sure array indexing is correct, do i need globalization forthe pump pins arrray

  int pump_pin = pump_pins[pump_number -1];
  digitalWrite(pump_pin, HIGH); //makes the first 'in' pin of the pump equal to high to allow current flow 
  //timer
  delay(duration*1000); //seconds to miliseconds
  
  digitalWrite(pump_pin, LOW); //turn off pump
 
  
}
  


