#ifndef SENSORINPUTSIM_H_   
#define SENSORINPUTSIM_H_
#include <unistd.h>

/* DO NOT MODIFY HERE */
void sensor_sim(void);  /* simulates 16 Bit ADC register with voltage input */
/* DO NOT MODIFY HERE */

/* Implement code here begin */

void level_sensing(void);  /* Measure Level of liquid in Tank */

uint8_t MAX_TANK_DEPTH = 0x000A; /* Tank deep */

uint8_t EXIT_LEVEL_SAMPLE = 0x0000; /* Limit of Tank deep */

uint8_t tank_level = 0x0000;

uint16_t MAX_VOLTAGE_SAMPLE = 0xFFFF; /* It is for full of Tank */

bool is_tank_level_below_par = false; //A flag used to indicate the tank level is below 15%.

/* Implement code here end */

#endif // SENSORINPUTSIM_H_
