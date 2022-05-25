#include <unistd.h>  
#include <stdio.h>
#include <pthread.h>
#include "../inc/sensorInputSim.h"


uint16_t MAX_TANK_DEPTH = 0x000A; /* Tank deep */

uint16_t EXIT_LEVEL_SAMPLE = 0x0000; /* Limit of Tank deep */

uint16_t tank_level = 0x0000;

uint16_t MAX_VOLTAGE_SAMPLE = 0xFFFF; /* It is for full of Tank */

bool is_tank_level_below_par = false; //A flag used to indicate the tank level is below 15%.


int main(void)
{
    /* DO NOT MODIFY HERE */

    //printf("Hello \n"); for debugging

    pthread_t sim_thread_id;
    pthread_create(&sim_thread_id, NULL, sensor_sim, NULL);
    
    pthread_t level_sensor;
    pthread_create(&level_sensor, NULL, level_sensing, NULL);
    /* DO NOT MODIFY HERE */

    /* Implement code here start */


    if(is_tank_level_below_par == true)
    {
        exit(0);
    }

    /* Implement code here end */

    /* DO NOT MODIFY HERE */
    pthread_join(level_sensor, NULL);
    pthread_join(sim_thread_id, NULL);
    /* DO NOT MODIFY HERE */
   
    return 0;
}
