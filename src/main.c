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
    pthread_create(&level_sensor, NULL, /* ADD FUNC here */, NULL);
    /* DO NOT MODIFY HERE */

    /* Implement code here start */

    /* Implement code here end */

    /* DO NOT MODIFY HERE */
    pthread_join(level_sensor, NULL);
    pthread_join(sim_thread_id, NULL);
    /* DO NOT MODIFY HERE */
   
    return 0;
}