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
/* Implement code here end */

#endif // SENSORINPUTSIM_H_
