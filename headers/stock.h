/*
 * stock.h
 * written by GUICHARD Mériadeg
 *
 * contains:
 *      the definiton of the stocks
 *      the dedicated functions
 *
 */
#ifndef STOCK_H
#define STOCK_H

#include "container.h"

typedef struct{

    unsigned  char type; // the type of raw material contained in the stock
    int nbContainers; // the number of container per stock
    int currentNbContainer; // the number of container  at a time t, decreasing number
    long int nbProducts; // the number of product per container in each stock

}stock;

/*
 * function: initalize_stock
 * description: instanciate and return a stock with the attributes below:
 *      -nbC: the number of containers
 *      -type: the type of the stock ('f' for fibers, 'p' for plastic)
 *      -original: the original number of product per stock;
 *
 */
stock *initalize_stock(int nbC, unsigned char type, long int original);

/*
 * function: fonc_fiber_stock
 * description below:
 *      1) cast the void pointer to a stock
 *      2) wait for a "waitFiber" signal send by the factory's (aka atelier) order
 *      3) wait a "wait_for_cont" signal send by the collect area in order to get a container to put the order
 *
 */
void *fonc_fiberStock(void *s);

/*
 * function: fonc_plastic_stock
 * description: basically the same as fiber_stock, but for a plastic stock
 *
 */
void *fonc_plasticStock(void *s);

#endif //STOCK_H


