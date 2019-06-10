#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "../headers/stock.h"

stock *initalize_stock(int nbC, unsigned char type, unsigned long int original){
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

void *fonc_fiberStock(){
    while(1){
        pthread_cond_wait(&fiberStock, &mutex1);
        printf("Envoi de nouveaux stocks de fibres\n");
        usleep(700000);
        pthread_cond_signal(&wait1);
    }
}

void *fonc_plasticStock(){
    while(1){
        pthread_cond_wait(&plasticStock, &mutex2);
        printf("Envoi de nouveaux stocks de plastique\n");
        usleep(700000);
        pthread_cond_signal(&wait2);
    }
}
