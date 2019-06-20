#ifndef HOMME_FLUX_H
#define HOMME_FLUX_H

#include "card.h"
#include "boite_aux_lettres.h"
#include "container.h"
typedef int BOOL;
#define TRUE 0
#define FALSE 1

typedef struct{
    card *cards;
    int nbCards;
    BOOL is_active;
}homme_flux;

void *fonc_homme_flux(void *f);
homme_flux *homme_flux_intialize(void);

#endif //HOMME_FLUX_H

