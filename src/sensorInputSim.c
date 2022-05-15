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

    
    
/* Implement code here end */