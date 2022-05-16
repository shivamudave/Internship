#include <unistd.h>  
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "sensorInputSim.h"


/* DO NOT MODIFY HERE */
uint16_t adc0_register = 0xFFFF;
bool intr_status = false;
uint32_t counter = 0;
uint8_t decrement_sim = 0;

void sensor_sim(void)
{
    while (1)
    {
        if(counter == 10)
        {
            decrement_sim = rand() % 8;
            adc0_register -= decrement_sim;
            intr_status = true;
            counter = 0;
            usleep(7800);
        }
        else
        {
            intr_status = false;
            counter++;
        }

        if(adc0_register <= 8)
        {
            adc0_register = 0xFFFF;
        }
        usleep(10000);
    }    
}
/* DO NOT MODIFY HERE */

/* Implement code here begin */

/*
    This function calculates that level of liquid present in tank when the interrupt status is triggered.
    It will exit from the thread once the level of liquid present is found to be less than 15%.
    Parameters:
    uint8_t tank_level : indicates the tank depth (Max 10 m).
*/

void level_sensing(void)
{
 uint8_t tank_level = 0x0000;

uint16_t MAX_VOLTAGE_SAMPLE = 0xFFFF; /* It is 15% of level */

    while (intr_status)
    {
        //tank_level indicates the depth of the tank, filled with liquid(MAX filled = 10m)
        tank_level = (adc0_register * MAX_TANK_DEPTH)/(MAX_VOLTAGE_SAMPLE);

        printf("Current tank level of liquid present is:%u m",tank_level);

    }    
}   
    
/* Implement code here end */
