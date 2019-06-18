#include <stdio.h>
#include <stdlib.h>
#include "../headers/boite_aux_lettres.h"

boite_aux_lettres *initialize_boite_aux_lettres(){

    boite_aux_lettres *b = malloc(sizeof(boite_aux_lettres));

    b->box = malloc(2 * sizeof(boite_aux_lettres)); // to begin with an array, is handle in add_card;
    b->size = 0;

    return b;
}

void add_card(boite_aux_lettres *b, card *c){

    if(b->size == 0){
        b->box[0] = *c;
    }
    else if(b->size == 1){
        b->box[1] = *c;
    }
    else{
        b->box = (card *)realloc(b->box, ((b->size + 1) * sizeof(card)));
        b->box[b->size] = *c;
    }

    b->size++;
}
