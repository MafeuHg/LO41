#ifndef ATELIER_H
#define ATELIER_H

#include "homme_flux.h"
#include "card.h"

typedef struct{

    homme_flux *hF;

}atelier;

int order(card **, int nbOrder);
                // on va faire des threads en mode detach pour pouvoir effectuer les livraisons sans problèmes de surcharge
                // avec en paramètre une fonction qui prend un tableau de carte ;)

#endif //ATELIER_H

