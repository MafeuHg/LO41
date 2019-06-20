/*
 * atelier.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definition of a factory (aka "atelier" in the program)
 *      the functions relative to a factory
 */

#ifndef ATELIER_H
#define ATELIER_H

#include "homme_flux.h"
#include "card.h"

typedef struct{

    homme_flux *hF;

}atelier;

/*
 * function: initialize_atelier
 * description: returns an initialized factory
 *
 * it takes an homme_flux in parameter in order to allow him
 * to put the magnetic cards inside the factory to create the
 * orders
 *
 */
atelier *initialize_atelier(homme_flux *hf);

/* function: fonc_atelier
 * description: handle the factory thread
 *
 * the void pointer will be casted as a homme_flux
 * then he will wait that this homme_flux gives him the magnetic cards
 * next, he will instanciate and run a detached thread per command (to avoid the factory_thread to wait
 * that each command is finished to proceed the next orders)
 *
 */
void *fonc_atelier(void *);

/*
 * function: commande
 * description: create and proceed a command of a specific material
 *
 */
void *commande(void *);

#endif //ATELIER_H

