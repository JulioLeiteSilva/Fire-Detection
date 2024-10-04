#ifndef UTILS_H
#define UTILS_H

#define SIZE 30
#define INTERVAL 3 // Intervalo de tempo para gerar incêndios

void initialize_forest();
void print_forest();

extern pthread_mutex_t forest_mutex;
extern char forest[SIZE][SIZE];

#endif
