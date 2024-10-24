#include "control_center.h"
#include <pthread.h>
#include <unistd.h>
#include "../utils/utils.h"

extern char forest[SIZE][SIZE];
extern pthread_mutex_t forest_mutex;

void *central_control(void *args)
{
    log_message("Central de controle iniciada.");

    while (1)
    {
        pthread_mutex_lock(&forest_mutex);
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (forest[i][j] == 'D')
                { // Célula marcada como "detectada"
                    log_message("Fogo combatido, célula marcada como queimada.");
                    forest[i][j] = '/'; // Apagar o fogo
                    sleep(2);           // Tempo para combater o incêndio
                }
            }
        }
        pthread_mutex_unlock(&forest_mutex);

        sleep(3); // Espera entre as ações de controle
    }

    return NULL;
}
