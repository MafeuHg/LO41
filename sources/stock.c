#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../headers/stock.h"

stock *initalize_stock(int nbC, unsigned char type, long int original){
    int i;
    stock *s = malloc(sizeof(stock));

    s->type = type;
    s->nbContainers = nbC;
    s->currentNbContainer = nbC;
    s->nbProducts = original;

    return s;
}

BOOL isStockEmpty(stock s){
    if(s.currentNbContainer == 0)
        return TRUE;
    else
        return FALSE;
}

void *fonc_fiberStock(void *s){
    stock *st = s;

    while(1){
        pthread_mutex_lock(&fiberStock);
        pthread_cond_wait(&waitFiber, &fiberStock);
        pthread_mutex_unlock(&fiberStock);

        printf("Un nouveau container de fibres est arrive\n");
        st->currentNbContainer++;

        pthread_cond_signal(&wait1);
    }
}

void *fonc_plasticStock(void *s){
    stock *st = s;

    while(1){
        pthread_mutex_lock(&plasticStock);
        pthread_cond_wait(&waitPlastic, &plasticStock);
        pthread_mutex_unlock(&plasticStock);

        printf("Un nouveau container de plastique est arrive\n");
        st->currentNbContainer++;

        pthread_cond_signal(&wait2);
    }
}
