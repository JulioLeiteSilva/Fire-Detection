#include "utils.h"
#include <pthread.h>
#include <stdio.h>

char forest[SIZE][SIZE];
pthread_mutex_t forest_mutex;

void initialize_forest()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            forest[i][j] = 'T';
        }
    }
}

void print_forest()
{
    pthread_mutex_lock(&forest_mutex);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", forest[i][j]);
        }
        printf("\n");
    }
    pthread_mutex_unlock(&forest_mutex);
}
