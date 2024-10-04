#include "control_center.h"
#include <pthread.h>
#include <unistd.h>
#include "../utils/utils.h"

extern char forest[SIZE][SIZE];
extern pthread_mutex_t forest_mutex;

void *central_control(void *args)
{
    while (1)
    {
        pthread_mutex_lock(&forest_mutex);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (forest[i][j] == '@')
                {
                    forest[i][j] = '/';
                }
            }
        }
        pthread_mutex_unlock(&forest_mutex);
        sleep(1);
    }
    return NULL;
}
