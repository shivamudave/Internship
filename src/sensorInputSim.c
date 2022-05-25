#include <unistd.h>  
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "../inc/sensorInputSim.h"


extern uint16_t MAX_TANK_DEPTH  ; /* Tank deep */

extern uint16_t EXIT_LEVEL_SAMPLE ; /* Limit of Tank deep */

extern uint16_t tank_level ;

extern uint16_t MAX_VOLTAGE_SAMPLE ; /* It is for full of Tank */

extern bool is_tank_level_below_par ; //A flag used to indicate the tank level is below 15%.


/* DO NOT MODIFY HERE */
uint16_t adc0_register = 0xFFFF;
bool intr_status = false;
uint32_t counter = 0;
uint8_t decrement_sim = 0;

void sensor_sim(void)
{
    //printf("inside sensore c \n"); for debugging

    while (1)
    {
        if(counter == 10)
        {
            decrement_sim = rand() %8 ;
            adc0_register -= decrement_sim;
            intr_status = true;
            counter = 0;
            usleep(7800);
      //  printf("counter 10 \n"); //for debugging
        }

        else
        {
            //printf("counter 0 \n"); //for debugging
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

    //printf("inside sensore d \n");// for debugging
    //printf("intr_status_1:%u \n",intr_status);// for debugging

    while (1)
    {
        if ((intr_status=true) && (counter == 0))
        {
          //  printf("intr_status_inside:%u \n",intr_status);// for debugging

            // printf("inside sensore d1 \n"); //for debugging

        //tank_level indicates the depth of the tank, filled with liquid(MAX filled = 10m)
        tank_level = (adc0_register * MAX_TANK_DEPTH)/(MAX_VOLTAGE_SAMPLE);

        printf("Current tank level of liquid present is:%u \n",tank_level);
        printf("adc regisr:%x \n",adc0_register);


        EXIT_LEVEL_SAMPLE = (MAX_TANK_DEPTH*15)/100;

                   if(tank_level <= EXIT_LEVEL_SAMPLE)
                   {
                	   is_tank_level_below_par = true;

                      printf("Tank liquid less than 15 percent\n");
                      pthread_exit(NULL);
                   }
                   usleep(100000);

    }    

        }

         
}   
    
/* Implement code here end */
