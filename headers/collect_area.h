/*
 * collect_area.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definition of a collect area
 *      the functions relative to a collect area
 */

#ifndef ZONE_COLLECTE_H
#define ZONE_COLLECTE_H

#include "../headers/container.h"

typedef struct{

    unsigned int nbContainer;

}collect_area;

/*
 * function: initialize_collect_area
 * description: instanciate an return a collect area with a number of container
 * inside of it to zero
 *
 */
collect_area *initialize_collect_area();

/*
 * function: fonc_collect_area
 * description: the function that is running by the thread of the collect area
 *
 * send a signal when a container is stored inside of it in order to avoir a negative
 * number of container inside the collect area
 */
void *fonc_collect_area(void *d);

#endif //ZONE_COLLECTE_H

