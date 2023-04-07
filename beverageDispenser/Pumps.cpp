
unsigned long previousMillis = 0;  // Store the last time the loop ran

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



void pumpDurations(int choice, int *durations[]){ // Alter pointer of durations depending on choice. Talk to Andres
  *durations = new float[4];
  drink_amounts[choice]*DURATION_CONVERSION
  *durations[0] = drink_amounts[choice][0]*DURATION_CONVERSION;
  *durations[1] = drink_amounts[choice][1]*DURATION_CONVERSION;
  *durations[2] = drink_amounts[choice][2]*DURATION_CONVERSION;
  *durations[3] = drink_amounts[choice][3]*DURATION_CONVERSION;
  return 0;
}





void pumpOn(uint8_t pump_number, int duration) {    //make sure array indexing is correct, do i need globalization forthe pump pins arrray

  int pump_pin = pump_pins[pump_number -1];
  digitalWrite(pump_pin, HIGH); //makes the first 'in' pin of the pump equal to high to allow current flow 
  //timer
  
  while (true) {
     unsigned long currentMillis = millis();  // Get the current time

      if (currentMillis - previousMillis >= duration) {  // Check if the interval has passed
        previousMillis = currentMillis;  // Save the current time as the last time the loop ran
        break;  // Exit the while loop to wait for the next interval
      }
    }
    digitalWrite(pump_pin, LOW); //turn off pump 
}
