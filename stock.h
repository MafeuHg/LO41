/*
 * stock.h
 * written by GUICHARD Mériadeg
 *
 * contains the definiton of the stocks
 *
 */

#include "utils.h"
#include "container.h"

#ifndef STOCK_H
#define STOCK_H

typedef struct{

    int nbContainers; // the number of container per stock
    int currentNbContainer // the number of container  at a time t, decreasing number

    container *containers; // "dynamic" array containing the number of container by stock, defined in the main programm

}stock;

*stock initalize_stock(int nbC, char type, int original);
BOOL isStockEmpty(stock s);

#endif //STOCK_H


