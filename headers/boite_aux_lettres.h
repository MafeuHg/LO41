/*
 * boite_aux_lettres.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definition of a letter box (aka boite aux lettres in the program)
 *      the functions relative to the letter box
 */

#ifndef CLASS_H
#define CLASS_H

#include "card.h"

typedef struct{

    card *box; // will be dynamically allocated at the execution of the program
    unsigned int  size;

}boite_aux_lettres;

/*
 * function: boite_aux_lettres_initialize
 * description: will instanciate and return a letter box
 *
 */
boite_aux_lettres *initialize_boite_aux_lettres();

/*
 * function: add_card
 * description: will add a card to the letter box
 *
 * this function is called every time an operator take a new container to work with
 */
void add_card(card *c);

boite_aux_lettres *boite;

#endif //CLASS_H

