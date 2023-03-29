#ifndef LIGHTS_H
#define LIGHTS_H

void lightsSetup();                   // Setup Lights
void ledFinished(bool state);         // Decide whether the finished LED is on or off
void ledPumpOn(uint8_t pump_number);  // Turn on LED to indicate the current pump serving

#endif
