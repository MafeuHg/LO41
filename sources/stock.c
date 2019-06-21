#include "../headers/utils.h"
#include "../headers/stock.h"
#include "../headers/collect_area.h"

stock *initalize_stock(int nbC, unsigned char type, long int original, collect_area *ca){
    int i;
    stock *s = malloc(sizeof(stock));

    s->type = type;
    s->nbContainers = nbC;
    s->currentNbContainer = nbC;
    s->nbProducts = original;
    s->collect_zone = ca;

    return s;
}

void *fonc_fiberStock(void *s){
    stock *st = s;

    while(1){
        pthread_mutex_lock(&fiberStock);
        pthread_cond_wait(&waitFiber, &fiberStock);
        pthread_mutex_unlock(&fiberStock);

        usleep(4000000);
        printf("\n*** La livraison de fibres est arrive ***\n\n");

        pthread_mutex_lock(&fiberStock);
        pthread_cond_wait(&waiting_for_cont, &fiberStock);
        pthread_mutex_unlock(&fiberStock);

        st->collect_zone->nbContainer--;
        st->currentNbContainer++;
        printf("\n*** Un container de fibres a ete remplis et remis dans le stock ***\n\n");

        pthread_cond_signal(&wait1);
    }
}

void *fonc_plasticStock(void *s){
    stock *st = s;

    while(1){
        pthread_mutex_lock(&plasticStock);
        pthread_cond_wait(&waitPlastic, &plasticStock);
        pthread_mutex_unlock(&plasticStock);

        usleep(4000000);
        printf("\n*** La livraison de plastique est arrive ***\n\n");

        pthread_mutex_lock(&plasticStock);
        pthread_cond_wait(&waiting_for_cont, &plasticStock);
        pthread_mutex_unlock(&plasticStock);

        st->collect_zone->nbContainer--;
        st->currentNbContainer++;
        printf("\n*** Un container de plastique a ete remplis et remis dans le stock ***\n\n");

        pthread_cond_signal(&wait2);
    }
}
