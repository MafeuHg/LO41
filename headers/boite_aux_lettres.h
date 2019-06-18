#ifndef CLASS_H
#define CLASS_H

#include "card.h"

typedef struct{

    card *box; // will be dynamically allocated at the execution of the program
    unsigned int  size;

}boite_aux_lettres;

boite_aux_lettres *initialize_boite_aux_lettres();
void add_card(boite_aux_lettres *b, card *c);

boite_aux_lettres *boite;

#endif //CLASS_H

