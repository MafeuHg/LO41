#ifndef ZONE_COLLECTE_H
#define ZONE_COLLECTE_H

#include "../headers/container.h"
#include <pthread.h>

pthread_t collect_area_thread;
pthread_mutex_t collect_area_mutex;
pthread_cond_t collect_area_wait;

pthread_mutex_t waiting_for_cont_mutex;
pthread_cond_t waiting_for_cont;

typedef struct{

    unsigned int nbContainer;

}collect_area;

void *fonc_collect_area(void *d);
collect_area *initialize_collect_area();

collect_area *collect_zone;

#endif //ZONE_COLLECTE_H

