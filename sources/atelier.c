#include "../headers/atelier.h"
#include "../headers/stock.h"
#include "../headers/utils.h"
#include "../headers/collect_area.h"
#include "../headers/productions.h"

atelier *initialize_atelier(homme_flux *hf){
    atelier *a = malloc(sizeof(atelier));

    a->hF = hf;
    return a;
}

void *fonc_atelier(void *d){
    homme_flux *hf = d;

    while(1){
        int i;
        pthread_t order;
        pthread_attr_t attr;

        pthread_mutex_lock(&mutex_atelier);
        pthread_cond_wait(&wait_atelier, &mutex_atelier);
        pthread_mutex_unlock(&mutex_atelier);

        printf("\n*** L'homme flux a depose les cartes a l'atelier ***\n\n");
        card* cards = malloc(100 * sizeof(cards));

        for(i = 0; i != hf->nbCards; i++)
            cards[i] = hf->cards[i];

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

void *commande(void *d){
    card *c = d;
    usleep(2000000);

    if(c->reference == 3263825){
        printf("\n*** La livraison de fibres est en cours ****\n\n");
        pthread_cond_signal(&waitFiber);
    }
    else if(c->reference == 3263827){
        printf("\n*** La livraison de plastique est en cours ***\n\n");
        pthread_cond_signal(&waitPlastic);
    }


    pthread_exit(NULL);
}

