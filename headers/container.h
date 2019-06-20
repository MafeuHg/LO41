/*
 * container.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definitions of the line's containers
 *      those containers are of two types: one that contains raw plastic
 *      and one that contains raw fibers
 */

#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "card.h"

typedef struct{

    char type;

    long int originalNbComponents;
    long int currentNbComponent;

    card *mCard;

}container;

/*
 * function: container_initialize
 * description: instanciate an returns a container with the following attributes:
 *  -> Container attributes
 *      -type: the type of the container ('f' for fiber or 'p' for plastic)
 *      -original: the original quantity of raw material in the container
 *
 *  -> Card attributes
 *      -p: the number of the post
 *      -wn: the number of the workshop (aka factory aka ateler)
 *      -nbC: the number of components in the container
 *      -ref: the reference of the raw material -> 3263825 for fiber and 3263827 for plastic
 *      -des: the designation of the material
 *      -o: the order associate to the container
 *
 */
container *container_initialize(unsigned char type, long int original, signed short p, signed short wn, int nbC, int ref, int des, int o);

#endif //CONTAINERS_H

