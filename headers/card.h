/*
 * card.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definition of a magnetic card
 *      the functions relatives to a magnetic card
 *
 */

#ifndef CARD_H
#define CARD_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{

    signed short postNumber; // identifies the number of the post where was located the container associated to this card
    signed short workshopNumber; // identifies the number of the supplier's workshop

    int nbComponent; // define the number of component of the container
    int reference; // the reference ofthe component
    int designation; // the designation of the component
    int order; // the order of the card



}card;

/*
 * function: create_card
 * description: create and retun a card with the paramaters descripted below:
 *      -postNumber: the number of the post
 *      -workshopNumber: the number of the workshop (aka factory aka ateler)
 *      -nbComponent: the number of components in the container
 *      -reference: the reference of the raw material -> 3263825 for fiber and 3263827 for plastic
 *      -designation: the designation of the material
 *      -order: the order associate to the container
 *
 */
card *create_card(signed short postNumber, signed short workshopNumber, int nbComponent, int reference, int designation, int order);

#endif //CARD_H

