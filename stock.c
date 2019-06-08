#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "stock.h"

*stock initalize_stock(int nbC, char type, int original){
    int i;
    stock *s = malloc(sizeof(stock));

    s->nbContainers = nbC;
    s->currentNbContainer = nbC;
    s->containers = malloc(sizeof(nbC * sizeof(container)));

    for(i = 0; i != nbC; i++){
        s->containers[i] = initialize_container(type, original);
    }

    return s;
}

BOOL isStockEmpty(stock s){
    if(s.currentNbContainer == 0)
        return TRUE;
    else
        return FALSE;
}
