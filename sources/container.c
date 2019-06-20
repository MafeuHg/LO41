#include "../headers/container.h"
#include "../headers/utils.h"

container *container_initialize(unsigned char type, long int original, signed short p, signed short wn, int nbC, int ref, int des, int o){
    container *c = malloc(sizeof(container));

    c->type = type;
    c->originalNbComponents = original;
    c->currentNbComponent = original;
    c->mCard = create_card(p, wn, nbC, ref, des, o);

    return c;
}
