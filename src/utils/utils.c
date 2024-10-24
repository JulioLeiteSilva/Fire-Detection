#include "utils.h"
#include <time.h>
#include <pthread.h>
#include <stdio.h>   // Para a função printf

// Definição correta do mutex
pthread_mutex_t forest_mutex;

char forest[SIZE][SIZE];


void initialize_forest() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            // Definir 20% da floresta como área livre (sem sensores)
            if (rand() % 5 == 0) {
                forest[i][j] = '-';  // Área livre (20% de chance)
            } else {
                forest[i][j] = 'T';  // Sensor ativo
            }
        }
    }
}


void print_forest() {
    pthread_mutex_lock(&forest_mutex);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", forest[i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&forest_mutex);
}

void log_message(const char *message) {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    // Pega o horário atual
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Formata o horário para "HH:MM:SS"
    strftime(buffer, 80, "%H:%M:%S", timeinfo);

    // Pega o ID da thread atual
    pthread_t thread_id = pthread_self();

    // Imprime a mensagem com o horário e o ID da thread
    printf("[%s] Thread %lu: %s\n", buffer, (unsigned long)thread_id, message);
}
