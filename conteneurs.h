/*
 * conteneurs.h
 * written by GUICHARD Mériadeg
 *
 * Contains the definitions of the line's containers
 * Those containers are of two types: one that contains raw plastic
 * and one that contains raw fibers
 *
 */

#include "utils.h";

#ifndef CONTENEURS_H
#define CONTENEURS_H

typedef struct{
    int originalNbFibers; // the original number of fiber per container. Defined by the user
    int currentNbFibers; // the number of fiber at a instant t, will decrease until 0

    card mCard; // the magnetic card that is associated with every container
    BOOL isCardHere; // represent the presence or not of the magnetic card

}fiberContainer;

typedef struct{
    int originalNbPlastic;
    int currentNbPlastic;

    card mCard;
    BOOL iscardHere;

}plasticContainer;

#endif //CONTENEURS_H

