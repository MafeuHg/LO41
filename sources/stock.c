#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../headers/stock.h"
#include "../headers/collect_area.h"

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

        printf("La livraison de fibres est arrive\n");

        pthread_mutex_lock(&fiberStock);
        pthread_cond_wait(&waiting_for_cont, &fiberStock);
        pthread_mutex_unlock(&fiberStock);

        collect_zone->nbContainer--;
        st->currentNbContainer++;
        printf("Un container de fibres a ete remplis et remis dans le stock\n");

        pthread_cond_signal(&wait1);
    }
}

void *fonc_plasticStock(void *s){
    stock *st = s;

    while(1){
        pthread_mutex_lock(&plasticStock);
        pthread_cond_wait(&waitPlastic, &plasticStock);
        pthread_mutex_unlock(&plasticStock);

        printf("La livraison de plastique est arrive\n");

        pthread_mutex_lock(&plasticStock);
        pthread_cond_wait(&waiting_for_cont, &plasticStock);
        pthread_mutex_unlock(&plasticStock);

        collect_zone->nbContainer--;
        st->currentNbContainer++;
        printf("Un container de plastique a ete remplis et remis dans le stock\n");

        pthread_cond_signal(&wait2);
    }
}
