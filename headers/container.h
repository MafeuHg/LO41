/*
 * conteneurs.h
 * written by GUICHARD Mériadeg
 *
 * Contains the definitions of the line's containers
 * Those containers are of two types: one that contains raw plastic
 * and one that contains raw fibers
 *
 */

#ifndef CONTENEURS_H
#define CONTENEURS_H
typedef int BOOL;
#define TRUE 0
#define FALSE 1

#include "card.h"


typedef struct{

    char type;

    long int originalNbComponents; // the original number of fiber per container. Defined by the user
    long int currentNbComponent; // the number of fiber at a instant t, will decrease until 0

    card *mCard; // the magnetic card that is associated with every container
    BOOL isCardHere; // represent the presence or not of the magnetic card

}container;

container *initialize_container(unsigned char type, long int original, signed short p, signed short wn, int nbC, int ref, int des, int o);
BOOL isContainerEmpty(container c);

#endif //CONTENEURS_H

