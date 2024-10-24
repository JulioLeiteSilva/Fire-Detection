#include "fire_generator.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../utils/utils.h"

extern char forest[SIZE][SIZE];
extern pthread_mutex_t forest_mutex;

void *fire_generator(void *args)
{
    while (1)
    {
        sleep(INTERVAL);

        pthread_mutex_lock(&forest_mutex);
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (forest[x][y] == 'T')
        {
            forest[x][y] = '@';
            printf("Incêndio iniciado em [%d, %d]\n", x, y);
        }
        pthread_mutex_unlock(&forest_mutex);

        print_forest();
    }
    return NULL;
}
