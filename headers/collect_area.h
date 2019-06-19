#ifndef ZONE_COLLECTE_H
#define ZONE_COLLECTE_H

#include "../headers/container.h"
#include <pthread.h>

pthread_mutex_t collect_area_mutex;
pthread_cond_t collect_area_wait;

typedef struct{

    unsigned int nbContainer;

}collect_area;

collect_area *collect_zone;

#endif //ZONE_COLLECTE_H

