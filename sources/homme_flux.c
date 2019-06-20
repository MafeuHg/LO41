#include "../headers/homme_flux.h"
#include "../headers/boite_aux_lettres.h"
#include "../headers/utils.h"
#include <pthread.h>

homme_flux *homme_flux_intialize(void){
    homme_flux *hf = malloc(sizeof(homme_flux));

    return hf;
}

void *fonc_homme_flux(void *hf){
    homme_flux *f = hf;
    while(1){
        usleep(7200000); // time elapsed before checking the letters box
        printf("TEST");
        if(boite->size > 0){
            f->cards = malloc(boite->size * sizeof(card));
            f->nbCards = boite->size;

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
