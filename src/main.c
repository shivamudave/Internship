#include <unistd.h>  
#include <stdio.h>
#include <pthread.h>

#include "sensorInputSim.h"

int main(void)
{
    /* DO NOT MODIFY HERE */
    pthread_t sim_thread_id;
    pthread_create(&sim_thread_id, NULL, sensor_sim, NULL);
    
    pthread_t level_sensor;
    pthread_create(&level_sensor, NULL, level_sensing, NULL);
    /* DO NOT MODIFY HERE */

    /* Implement code here start */

    EXIT_LEVEL_SAMPLE = (MAX_TANK_DEPTH*15)/100;

           if(tank_level <= EXIT_LEVEL_SAMPLE)
           {

              printf("Tank liquid less than 15 percent\n");
              pthread_exit(NULL);
           }
    /* Implement code here end */

    /* DO NOT MODIFY HERE */
    pthread_join(level_sensor, NULL);
    pthread_join(sim_thread_id, NULL);
    /* DO NOT MODIFY HERE */
   
    return 0;
}
