#ifndef HOMME_FLUX_H
#define HOMME_FLUX_H

#include "card.h"
#include "boite_aux_lettres.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
    card *cards;
    int nbCards;
}homme_flux;

void *fonc_homme_flux(void *f);
homme_flux *homme_flux_intialize(void);

#endif //HOMME_FLUX_H

