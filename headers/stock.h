/*
 * stock.h
 * written by GUICHARD Mériadeg
 *
 * contains the definiton of the stocks
 *
 */
#ifndef STOCK_H
#define STOCK_H

#include "container.h"

typedef struct{

    unsigned  char type; // the type of raw material contained in the stock
    int nbContainers; // the number of container per stock
    int currentNbContainer; // the number of container  at a time t, decreasing number
    long int nbProducts;

}stock;

stock *initalize_stock(int nbC, unsigned char type, long int original);
void *fonc_fiberStock();
void *fonc_plasticStock();

#endif //STOCK_H


