#ifndef ZONE_COLLECTE_H
#define ZONE_COLLECTE_H

#include "../headers/container.h"
#include <pthread.h>


typedef struct{

    unsigned int nbContainer;

}collect_area;

void *fonc_collect_area(void *d);
collect_area *initialize_collect_area();

collect_area *collect_zone;

#endif //ZONE_COLLECTE_H

