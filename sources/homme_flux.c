#include "../headers/homme_flux.h"
#include "../headers/boite_aux_lettres.h"
#include "../headers/utils.h"
#include "../headers/container.h"
#include <pthread.h>

homme_flux *homme_flux_intialize(void){
    homme_flux *hf = malloc(sizeof(homme_flux));
    hf->cards = NULL;
    hf->is_active = FALSE;

    return hf;
}

void *fonc_homme_flux(void *hf){
    homme_flux *f = hf;
    while(1){
        int i;
        f->is_active = FALSE;
        usleep(1200000); // time elapsed before checking the letters box

        pthread_mutex_lock(&homme_flux_mutex);
        pthread_cond_wait(&wait_boite, &homme_flux_mutex);
        printf("reception du signal\n");
        pthread_mutex_unlock(&homme_flux_mutex);

        printf("La boite contient : %d\n", boite->size);

        if(boite->size > 0 && f->is_active == FALSE){

            f->is_active = TRUE;
            int size = boite->size;
            f->cards = malloc(size * sizeof(card *));

            printf("fin\n");
            f->nbCards = boite->size;

            for(i = 0; i != f->nbCards; i++)
                f->cards[i] = boite->box[i];

            free(boite->box);
            boite->size = 0;

            /* traitements avec l'atelier */
            printf("L'homme flux a pris les cartes de la boite aux lettres\n");
            pthread_cond_signal(&wait_atelier);
        }
        else{
            printf("L'homme flux constate que la boite aux lettres est vide\n");
        }
    }
}
