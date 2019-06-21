#include "../headers/homme_flux.h"
#include "../headers/utils.h"

homme_flux *homme_flux_intialize(boite_aux_lettres *b){
    homme_flux *hf = malloc(sizeof(homme_flux));
    hf->cards = NULL;
    hf->boite = b;
    hf->is_active = FALSE;

    return hf;
}

void *fonc_homme_flux(void *hf){
    homme_flux *f = hf;
    while(1){
        int i;
        f->is_active = FALSE;
        usleep(1200000);

        pthread_mutex_lock(&homme_flux_mutex);
        pthread_cond_wait(&wait_boite, &homme_flux_mutex);
        pthread_mutex_unlock(&homme_flux_mutex);

        if(f->boite->size > 0 && f->is_active == FALSE){

            f->is_active = TRUE;
            int size = f->boite->size;
            f->cards = malloc(size * sizeof(card *));

            f->nbCards = f->boite->size;

            for(i = 0; i != f->nbCards; i++)
                f->cards[i] = f->boite->box[i];

            free(f->boite->box);
            f->boite->size = 0;

            printf("\n*** L'homme flux a pris les cartes de la boite aux lettres ***\n\n");
            pthread_cond_signal(&wait_atelier);
        }
        else{
            printf("\n*** L'homme flux constate que la boite aux lettres est vide ***\n\n");
        }
    }
}
