#include "sensor.h"
#include <pthread.h>
#include <unistd.h>
#include "../utils/utils.h"

extern char forest[SIZE][SIZE];
extern pthread_mutex_t forest_mutex;

void *sensor_node(void *args)
{
    int position = (intptr_t)args;
    int x = position / SIZE;
    int y = position % SIZE;

    while (1)
    {
        pthread_mutex_lock(&forest_mutex);
        if (forest[x][y] == '@')
        {
            if (x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1)
            {
                // Lógica de envio para a central
            }
            else
            {
                // Propaga a mensagem para os vizinhos
                if (x > 0 && forest[x - 1][y] == 'T')
                    forest[x - 1][y] = '@';
                if (x < SIZE - 1 && forest[x + 1][y] == 'T')
                    forest[x + 1][y] = '@';
                if (y > 0 && forest[x][y - 1] == 'T')
                    forest[x][y - 1] = '@';
                if (y < SIZE - 1 && forest[x][y + 1] == 'T')
                    forest[x][y + 1] = '@';
            }
        }
        pthread_mutex_unlock(&forest_mutex);

        usleep(100000);
    }
    return NULL;
}
