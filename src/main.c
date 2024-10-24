#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include "sensors/sensor.h"
#include "fire/fire_generator.h"
#include "control/control_center.h"
#include "utils/utils.h"

#define SIZE 30

int main() {
    pthread_mutex_init(&forest_mutex, NULL);
    initialize_forest();
    
    // Cria as threads para os nós sensores
    pthread_t sensors[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pthread_create(&sensors[i][j], NULL, sensor_node, (void *)(intptr_t)(i * SIZE + j));
        }
    }

    // Cria a thread para gerar incêndios
    pthread_t fire_thread;
    pthread_create(&fire_thread, NULL, fire_generator, NULL);

    // Cria a thread da central de controle
    pthread_t central_thread;
    pthread_create(&central_thread, NULL, central_control, NULL);

    // Junta as threads
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            pthread_join(sensors[i][j], NULL);
        }
    }
    pthread_join(fire_thread, NULL);
    pthread_join(central_thread, NULL);

    pthread_mutex_destroy(&forest_mutex);
    return 0;
}
