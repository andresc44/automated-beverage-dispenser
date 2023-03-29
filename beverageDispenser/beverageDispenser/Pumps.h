#ifndef PUMPS_H
#define PUMPS_H

void pumpsSetup();                                                              // Setup pumps
void pumpDurations(uint8_t choice, int *durations[], uint8_t number_of_pumps);  // Alter pointer of durations depending on choice. Talk to Andres
void pumpOn(uint8_t pump_number, int duration);                                 // Turn on a given pump for a specific period of time

#endif
