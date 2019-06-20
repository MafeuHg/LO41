#include "../headers/card.h"

card *create_card(signed short postNumber, signed short workshopNumber, int nbComponent, int refference, int designation, int order){
    card *c = malloc(sizeof(card));

    c->postNumber = postNumber;
    c->workshopNumber = workshopNumber;
    c->nbComponent = nbComponent;
    c->reference = refference;
    c->designation = designation;
    c->order = order;

    return c;
}

void card_info(card *c){
    printf("Infos sur la carte:\n");
    printf("Nombre de comosants; %d\nReference: %d\nDesignation: %d\n", c->nbComponent, c->reference, c->designation);
}
