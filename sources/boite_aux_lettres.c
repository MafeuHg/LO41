#include "../headers/boite_aux_lettres.h"
#include "../headers/utils.h"

boite_aux_lettres *initialize_boite_aux_lettres(){
    boite_aux_lettres *b = malloc(sizeof(boite_aux_lettres));
    b->size = 0;

    return b;
}

void add_card(card *c){

    if(boite->size == 0){
        boite->box = malloc(1 * sizeof(boite_aux_lettres)); // to begin with an array, is handle in add_card;
        boite->box[0] = *c;
        boite->size = 1;
    }
    else{
        boite->box = (card *)realloc(boite->box, ((boite->size + 1) * sizeof(card)));
        boite->box[boite->size] = *c;
        boite->size++;
    }
    pthread_cond_signal(&wait_boite);
}
