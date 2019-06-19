#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "../headers/atelier.h"
#include "../headers/stock.h"
#include "../headers/utils.h"
#include "../headers/homme_flux.h"
#include "../headers/collect_area.h"

atelier *initialize_atelier(homme_flux *hf){
    atelier *a = malloc(sizeof(atelier));

    a->hF = hf;
    return a;
}

void *commande(void *d){
    card *c = d;
    usleep(20000000); // the time during the livraison of a container

    pthread_mutex_lock(&collect_area_mutex);
    pthread_cond_wait(&collect_area_wait, &collect_area_mutex);

    collect_zone->nbContainer--;
    if(c->reference == 3263825){
        printf("La livraison de fibres est arrivee\n");
        pthread_cond_signal(&fiberStock);
    }
    else if(c->reference == 3263827){
        printf("La livraison de plastique est arrivee\n");
        pthread_cond_signal(&plasticStock);
    }

    pthread_mutex_unlock(&collect_area_mutex);
}

void *fonc_atelier(void *d){
    homme_flux *hf = d;
    card* cards = hf->cards;

    while(1){
        pthread_mutex_lock(&mutex_atelier);
        pthread_cond_wait(&wait_atelier, &mutex_atelier);
        pthread_mutex_unlock(&mutex_atelier);

        int i;
        pthread_t order;
        pthread_attr_t attr;

        if(pthread_attr_init(&attr) != 0){
            perror("Echec d'initialisation du thread de commande");
            exit(EXIT_FAILURE);
        }
        if(pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) != 0){
            perror("Echec d'initialisation de l'attribut detache du thread de commande");
            exit(EXIT_FAILURE);
        }

        for(i = 0; i != hf->nbCards; i++){
            pthread_create(&order, &attr, commande, (void *)&cards[i]);
        }
    }
}
