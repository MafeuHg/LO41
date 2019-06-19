#ifndef ATELIER_H
#define ATELIER_H

#include "homme_flux.h"
#include "card.h"

typedef struct{

    homme_flux *hF;

}atelier;

atelier *initialize_atelier(homme_flux *hf);
void *fonc_atelier(void *);
void *commande(void *);
                // on va faire des threads en mode detach pour pouvoir effectuer les livraisons sans problèmes de surcharge
                // avec en paramètre une fonction qui prend un tableau de carte ;)

#endif //ATELIER_H

