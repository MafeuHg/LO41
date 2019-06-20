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
    usleep(2000000); // the time during the livraison of a container

    if(c->reference == 3263825){
        printf("La livraison de fibres est en cours\n");
        pthread_cond_signal(&waitFiber);
    }
    else if(c->reference == 3263827){
        printf("La livraison de plastique est en cours\n");
        pthread_cond_signal(&waitPlastic);
    }


    pthread_exit(NULL);
}

void *fonc_atelier(void *d){
    homme_flux *hf = d;

    while(1){
        pthread_mutex_lock(&mutex_atelier);
        pthread_cond_wait(&wait_atelier, &mutex_atelier);
        pthread_mutex_unlock(&mutex_atelier);

        printf("L'homme flux a depose les cartes a l'atelier\n");
        card* cards = hf->cards;

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
            if(pthread_create(&order, &attr, commande, (void *)&cards[i]) != 0)
                printf("Dommage\n");
        }
        free(cards);
        free(hf->cards);
        hf->nbCards = 0;
    }
}
