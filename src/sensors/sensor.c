#include "sensor.h"
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include "../utils/utils.h"

extern char forest[SIZE][SIZE];
extern pthread_mutex_t forest_mutex;

void *sensor_node(void *args) {
    int position = (intptr_t)args;
    int x = position / SIZE;
    int y = position % SIZE;

    log_message("Sensor iniciado.");

    while (1) {
        pthread_mutex_lock(&forest_mutex);
        if (forest[x][y] == '@') {
            log_message("Fogo detectado!");
            forest[x][y] = 'D';

            if (x == 0 || x == SIZE - 1 || y == 0 || y == SIZE - 1) {
                log_message("Enviando mensagem para a central de controle.");
            } else {
                log_message("Propagando incêndio para os vizinhos.");
            }
        }
        pthread_mutex_unlock(&forest_mutex);

        usleep(100000);
    }

    return NULL;
}

