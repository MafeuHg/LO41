/*
 * homme_flux.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definitions of a "homme flux"
 *      its dedicated functions
 */

#ifndef HOMME_FLUX_H
#define HOMME_FLUX_H

#include "card.h"
#include "boite_aux_lettres.h"
#include "container.h"
#include "BOOL.h"

typedef struct{

    card *cards;
    int nbCards;
    BOOL is_active;

}homme_flux;

/*
 * function: homme_flux_initialize
 * description: instanciate and return a "homme flux"
 *
 */
homme_flux *homme_flux_intialize(void);
/*
 * function: fonc_homme_flux
 * description below:
 *      1) cast of the void pointer into a "homme_flux"
 *      2) waiting to check the letter box (aka boite aux lettres)
 *      3) set is_active to FALSE
 *      4) checks the letter box, if its contains card, the is_active state is set to TRUE to avoid other messages to reach him
 *         then he will take the card from the box, reset the box, otherwise he will just wait an other time
 *      5) he send a signal to the factory (aka atelier) to tell it that he got some cards to proceed orders
 *
 */
void *fonc_homme_flux(void *f);

#endif //HOMME_FLUX_H

