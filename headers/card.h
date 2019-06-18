/*
 * card.h
 * written by GUICHARD Mériadeg
 *
 * contains the definition of a magnetic card
 *
 */

#ifndef CARD_H
#define CARD_H

#include <stdlib.h>

typedef struct{

    signed short postNumber; // identifies the number of the post where was located the container associated to this card
    signed short workshopNumber; // identifies the number of the supplier's workshop

    int nbComponent; // define the number of component of the container
    int reference; // the reference ofthe component
    int designation; // the designation of the component
    int order; // the order of the card



}card;

card *create_card(signed short postNumber, signed short workshopNumber, int nbComponent, int refference, int designation, int order);

#endif //CARD_H

