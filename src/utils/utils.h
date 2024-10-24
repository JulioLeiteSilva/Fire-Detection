#ifndef UTILS_H
#define UTILS_H

#include <pthread.h>

#define SIZE 30
#define INTERVAL 3 // Intervalo de tempo para gerar incêndios

extern pthread_mutex_t forest_mutex;

void initialize_forest();
void print_forest();

extern char forest[SIZE][SIZE];

#endif
