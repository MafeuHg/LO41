#include "../headers/homme_flux.h"
#include "../headers/boite_aux_lettres.h"

void *fonc_homme_flux(void *hf){
    homme_flux *f = hf;
    while(1){
        usleep(1200000); // time elapsed before checking the letters box
        if(boite->size > 0){
            f->cards = malloc(boite->size * sizeof(card));
            f->nbCards = boite->size;

            free(boite->box);
            boite->size = 0;

            /* traitements avec l'atelier */
            printf("L'homme flux a pris les cartes de la boite aux lettres\n");
        }
        else{
            printf("L'homme flux constate que la boite aux lettres est vide\n");
        }
    }
}
